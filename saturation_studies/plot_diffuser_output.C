
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <fstream>
#include <utility>
#include <string>

// ROOT Includes
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TEllipse.h"
// Defines
#define PI 3.141592654

#include "myStyle.C"

/*
 * To run this script just type:  root -l -x llib.C 'ODAnalysis.C("wcsim.root", "ODHits.root", false)' 
 * or replace wcsim.root and ODHits.root for your input and output filenames respectively
 * The final true can be changed to true to turn on verbosity.
 * The default: root -l -x llib.C ODAnalysis.C will run with the variables mentioned above
 */

int laser = 10;

// A function to convert radians to degress
float RadToDeg(float x){
  return x*180/PI;
}
// A function to convert degress to radians
float DegToRad(float x){
  return x*PI/180;
}

// A function to check if a PMT has reached saturation
// (100 pe in 16 ns)
float max_charge_in_window(TH1D *h,float window){
  float total_charge = h->Integral();
  float max_charge=0.0;
  int minbin=0;
  int maxbin=0;
  int nbins = h->FindBin(100.);
  int start_bin = h->FindBin(0.);
  for (int ibin=start_bin; ibin<nbins; ibin++){
    int start_window = h->GetBinCenter(ibin);
    int stop_window = start_window+window;
    if (stop_window>200) stop_window=200-1;
    float charge_tmp = h->Integral(h->FindBin(start_window),h->FindBin(stop_window));
    if (charge_tmp>max_charge){
      max_charge = charge_tmp;
      minbin=start_window;
      maxbin=stop_window;
    }
  }
  return max_charge;
}

void plot_diffuser_output( const char *inFileName1 = "/data2/kneale/hk-software/diffuser_sims/diffuser_93/reduced_diffuser_93_365.0_nm_10.0_ns_10000000_ppp_all.root", bool verbosity = 0){ 

  string filename_tmp = std::string(inFileName1).substr(0,std::string(inFileName1).find(".root"));
  string filename = filename_tmp.substr(filename_tmp.find_last_of("/")+1);
  std::cout << "filename " << filename << std::endl;

  // Some nicely formatted text options
  std::cout << std::scientific; // This causes all numbers to be displayed in scientific notation.
//  std::cout << std::setprecision(4); // Sets the decimal precision (no more than two decimal places)
  std::cout << std::left; // Sets the text justification to left
  const int txtW = 20; // Width of "box" holding text
  const int numW = 10; // Width of "box" holding numbers

  // Set plot style
  TStyle *myStyle = GetmyStyle();
  gROOT->SetStyle("myStyle");
  gROOT->ForceStyle();


  // Open the WCSim file
  TFile *inFile1 = new TFile(inFileName1, "READ"); 
  if ( !inFile1->IsOpen() ){
    std::cout << "Error: could not open input file \"" << inFileName1 << "\"." <<std::endl; 
	
  } else if (verbosity) {
    std::cout << "Input file: " << inFileName1 << std::endl;
  }

  TTree *inTree = (TTree*)inFile1->Get("simulation");
  Int_t event;
  Float_t digiHitsOD=99999.;
  Float_t injectorVtxX=99999.;
  Float_t injectorVtxY=99999.;
  Float_t injectorVtxZ=99999.;
  std::vector<Int_t> *tubeNumber=0;
  std::vector<Int_t> *cylLoc=0;
  std::vector<Float_t> *digiTime=0;
  std::vector<Float_t> *digiCharge=0;
  std::vector<Float_t> *pmtX=0;
  std::vector<Float_t> *pmtY=0;
  std::vector<Float_t> *pmtZ=0;
  TBranch *btubeNumber=0;
  TBranch *bdigiTime=0;
  TBranch *bdigiCharge=0;
  TBranch *bcylLoc=0;
  TBranch *bpmtX=0;
  TBranch *bpmtY=0;
  TBranch *bpmtZ=0;

  inTree->SetBranchAddress("event",&event);
  inTree->SetBranchAddress("digiHitsOD",&digiHitsOD);
  inTree->SetBranchAddress("injectorVtxX",&injectorVtxX);
  inTree->SetBranchAddress("injectorVtxY",&injectorVtxY);
  inTree->SetBranchAddress("injectorVtxZ",&injectorVtxZ);
  inTree->SetBranchAddress("tubeNumber",&tubeNumber,&btubeNumber);
  inTree->SetBranchAddress("digiTime",&digiTime,&bdigiTime);
  inTree->SetBranchAddress("digiCharge",&digiCharge,&bdigiCharge);
  inTree->SetBranchAddress("cylLoc",&cylLoc,&bcylLoc);
  inTree->SetBranchAddress("pmtX",&pmtX,&bpmtX);
  inTree->SetBranchAddress("pmtY",&pmtY,&bpmtY);
  inTree->SetBranchAddress("pmtZ",&pmtZ,&bpmtZ);

 
  int nentries = inTree->GetEntries();
  std::cerr << "Entries " << nentries << std::endl;
  
  float saturation_pe = 100.;//saturation level set to 100 pe in 16 ns 
  float saturation_window = 16.;//saturation level set to 100 pe in 16 ns 
  int num_OD_PMT = 0;
  double overall_max_charge = 0.;
  // Find the number of PMTs and the max q on a single PMT
  // for each pulse of the laser
  for (int i=0; i < nentries; i++) {
    
    int newtentry = inTree->GetEntry(i);
    btubeNumber->GetEntry(newtentry);    

    for (int ihit=0;ihit<tubeNumber->size();ihit++){
      int temp_num_OD_PMT = tubeNumber->at(ihit);
      if (temp_num_OD_PMT > num_OD_PMT) num_OD_PMT = temp_num_OD_PMT;
    }
    
  }  

  std::cerr << "num PMTs " << num_OD_PMT << std::endl;

  // set up vectors to store information needed outside the loop
  std::vector<double> total_hits(num_OD_PMT,0.);
  std::vector<double> total_charges(num_OD_PMT,0.);

  //--------------------- Tree ready to use -------------------

  // Basic histograms
  
  // charge vs distance
  TH2F *hqd = new TH2F("hqd","",202,0,808,3000,0,3000);
  TH2F *hqd_endcaps = new TH2F("hqd_endcaps","",202,0,808,3000,0,3000);
  TH2F *hqd_barrel = new TH2F("hqd_barrel","",202,0,808,3000,0,3000);
  // charge vs pmt number
  TH2F *hpmt = new TH2F("hpmt","",num_OD_PMT,0,num_OD_PMT,3000,0,3000);
  // time vs distance
  TH2F *hqt = new TH2F("hqt","",200,0,200,3000,0,3000);

  int endcap_hits=0;
  float saturation_distance = 0.;
  float charge_at_saturation = 0.;
  int firstgo=1;// only create pmt histograms on the first go
  for (Long64_t ipulse=0; ipulse < nentries; ipulse++) {

    std::vector<double> distances(num_OD_PMT,0.);
    
    inTree->GetEntry(ipulse);
    Long64_t tentry = inTree->GetEntry(ipulse);
    btubeNumber->GetEntry(tentry);
    bdigiTime->GetEntry(tentry);
    bdigiCharge->GetEntry(tentry);
    bcylLoc->GetEntry(tentry);
    bpmtX->GetEntry(tentry);
    bpmtY->GetEntry(tentry);
    bpmtZ->GetEntry(tentry);
    
    // array of histograms to hold the charge and time 
    // info for all hits for each pmt in this pulse
    std::vector<TH1D*> histograms;
    for (int ihist=0;ihist<num_OD_PMT;ihist++){
      if (!firstgo) TH1::AddDirectory(kFALSE);
      TString name = Form("h_%d",ihist);
      histograms.push_back(new TH1D(name,name,200,0,200)); 
    }
    firstgo=0;
    // create vectors for the pmt and hit and charge info
    // at the start of each pulse
    std::vector<double> charges(num_OD_PMT,0.);
    std::vector<double> times(num_OD_PMT,0.);
    std::vector<int> locations(num_OD_PMT,0);
     
    // Loop over all of the hits in this pulse
    int nhits = pmtX->size();
    for (int ihit=0; ihit<nhits;ihit++){
      // Fill  charge vs time and pmt histograms for all hits in all pulses
      hqt->Fill(digiTime->at(ihit),digiCharge->at(ihit));// all hits
      hpmt->Fill(tubeNumber->at(ihit),digiCharge->at(ihit));// all hits
      // Fill a charge vs time histogram for each PMT
      histograms[tubeNumber->at(ihit)-1]->Fill(digiTime->at(ihit),digiCharge->at(ihit));
      // save the hit time, charge and distance info for each PMT 
      // for each hit in this pulse
      charges[tubeNumber->at(ihit)-1] += digiCharge->at(ihit);// total for this pulse
//      std::cout << "tube number " << tubeNumber->at(ihit)  << ", charge " << (int)digiCharge->at(ihit) << std::endl;
      double distance = sqrt(pow(injectorVtxX-pmtX->at(ihit),2) + pow(injectorVtxY-pmtY->at(ihit),2) + pow(injectorVtxZ-pmtZ->at(ihit),2));
      if ( verbosity && charges[tubeNumber->at(ihit)-1]>100 && ihit>0 && tubeNumber->at(ihit)!=tubeNumber->at(ihit-1)){
        std::cout << injectorVtxX << ", " << pmtX->at(ihit)<< std::endl;
        std::cout << injectorVtxY << ", " << pmtY->at(ihit)<< std::endl;
        std::cout << injectorVtxZ << ", " << pmtZ->at(ihit)<< std::endl;
        std::cout << distance << std::endl;
      }
      distances[tubeNumber->at(ihit)-1] = distance;
      locations[tubeNumber->at(ihit)-1] = cylLoc->at(ihit);
      times[tubeNumber->at(ihit)-1] = digiTime->at(ihit);
//      if (digiCharge->at(ihit)>0){
//      std::cout << "hit info: " << tubeNumber->at(ihit) << ", " << distances[tubeNumber->at(ihit)-1] << ", " << locations[tubeNumber->at(ihit)-1] << ", " << times[tubeNumber->at(ihit)-1] << std::endl;
//      }
      // also save the total charges and hits for all hits in all pulses
      total_charges[tubeNumber->at(ihit)-1] += digiCharge->at(ihit);// total over all pulses
      if (digiCharge->at(ihit)>0)
      total_hits[tubeNumber->at(ihit)-1] ++;// total over all pulses
    }//nhits
   
    // Loop over all of the PMTs for each pulse
    // and fill charge vs distance if the PMT is saturated
    for (int ipmt = 0;ipmt<num_OD_PMT; ipmt++){
      //check if the PMT is saturated 
      if (charges[ipmt]>0.){
        float max_charge = max_charge_in_window(histograms[ipmt],saturation_window);
        hqd->Fill(distances[ipmt],max_charge);
        if (locations[ipmt]==3 or locations[ipmt]==5){
          hqd_endcaps->Fill(distances[ipmt],max_charge);
          endcap_hits++;
        }
        else{
          hqd_barrel->Fill(distances[ipmt],max_charge);
        }
        if (max_charge>saturation_pe && saturation_distance<distances[ipmt]){
          saturation_distance = distances[ipmt];
          charge_at_saturation = max_charge;
        }
        if (charges[ipmt] > overall_max_charge) overall_max_charge = max_charge;
      }
    }
    // TODO adjust the error for the number of hits
  }//entries (pulses)


  /***********************************************************************/
  // Finally, draw the plots

  TLine *line = new TLine(5,100,805,100);
  line->SetLineColor(kRed);

  // Plot 1: mean charge vs distance	
  TCanvas *c2 = new TCanvas();
  TProfile *tpqd = hqd->ProfileX();
  tpqd->SetStats(0);
  tpqd->SetTitle(";Distance between PMT and injector (cm);Mean charge (pe)");
  tpqd->SetMarkerColor(kBlue+2);
  tpqd->SetMarkerSize(0.9);
  tpqd->SetMarkerStyle(20);
  tpqd->SetErrorOption("s");
  tpqd->Draw();
 
  std::ofstream out;
  out.open(Form("results_%s.txt",filename.c_str()));
  out << filename.c_str() << "\n";
  float max_saturation_distance= saturation_distance;
  int maxbin = tpqd->FindBin(max_saturation_distance);
  float charge_at_max_saturation = tpqd->GetBinContent(maxbin)+tpqd->GetBinError(maxbin)*2;

  out << "maximum saturation distance " << max_saturation_distance << "\n";
  out << "mean charge at max saturation distance " << tpqd->GetBinContent(maxbin) << " +/- " << tpqd->GetBinError(maxbin)<< "\n";
  out << "max charge at max saturation distance " << charge_at_max_saturation << "\n";
  
  saturation_distance=0;
  charge_at_saturation=0; 
  for (int ibin=0;ibin<tpqd->GetNbinsX();ibin++){
    if (tpqd->GetBinContent(ibin)>saturation_pe && tpqd->GetBinCenter(ibin)>saturation_distance){
      saturation_distance=tpqd->GetBinCenter(ibin);
      charge_at_saturation=tpqd->GetBinContent(ibin);
    }
  }
  out << "saturation distance " << saturation_distance << "\n";
  out << "mean charge at saturation distance " << charge_at_saturation << "\n";
  out.close();
  
  TProfile *tpqd_endcaps = hqd_endcaps->ProfileX();
  tpqd_endcaps->SetStats(0);
  tpqd_endcaps->SetMarkerColor(kBlack);
  tpqd_endcaps->SetMarkerSize(0.9);
  tpqd_endcaps->SetMarkerStyle(20);
  tpqd_endcaps->Draw("p same");

  TProfile *tpqd_barrel = hqd_barrel->ProfileX();
  tpqd_barrel->SetStats(0);
  tpqd_barrel->SetMarkerColor(kRed+2);
  tpqd_barrel->SetMarkerSize(0.9);
  tpqd_barrel->SetMarkerStyle(20);
  tpqd_barrel->Draw("p same");

  line->Draw();

  TLegend *leg = new TLegend(0.6,0.7,0.88,0.88);
  leg->AddEntry(tpqd_barrel,"Barrel PMTs","lp");
  if (endcap_hits>0){
    leg->AddEntry(tpqd_endcaps,"Endcap PMTs","lp");
  }
  c2->SaveAs(Form("results/mean_charge_distance_%s.C",filename.c_str()));
  c2->SaveAs(Form("results/mean_charge_distance_%s.png",filename.c_str()));

  // Plot 2: 2D plot of charge vs PMT
  // TODO consider a plot of mean charge vs PMT
  TCanvas *chpmt = new TCanvas();
  hpmt->SetStats(0);
  hpmt->SetTitle(";PMT number; Charge (pe)");
  hpmt->GetYaxis()->SetRangeUser(0,overall_max_charge+50);
  hpmt->Draw("colz");
  chpmt->SaveAs(Form("results/total_charge_pmt_number_%s.C",filename.c_str()));
  chpmt->SaveAs(Form("results/total_charge_pmt_number_%s.png",filename.c_str()));

  // Plot 3: 2D plot of charge vs distance
  myStyle->SetPadRightMargin(0.15);
  TCanvas *c1 = new TCanvas();
  hqd->SetStats(0);
  hqd->Draw("colz");
  hqd->SetTitle(";Distance between PMT and injector (cm); Charge (pe)");
  hqd->GetYaxis()->SetRangeUser(0,overall_max_charge+50);
  line->Draw();
  c1->SaveAs(Form("results/charge_distance_%s.C",filename.c_str()));
  c1->SaveAs(Form("results/charge_distance_%s.png",filename.c_str()));

  // Plot 4: 2D plot of charge vs time
  myStyle->SetPadRightMargin(0.15);
  TCanvas *cqt = new TCanvas();
  hqt->SetStats(0);
  hqt->Draw("colz");
  hqt->SetTitle(";Hit time (ns); Charge (pe)");
  hqt->GetYaxis()->SetRangeUser(0,overall_max_charge+50);
  TLine *line2 = new TLine(0,100,200,100);
  line2->SetLineColor(kRed);
  line2->Draw();
  cqt->SaveAs(Form("results/charge_time_%s.C",filename.c_str()));
  cqt->SaveAs(Form("results/charge_time_%s.png",filename.c_str()));



}

