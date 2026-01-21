// C++ Includes
#include <iostream>
#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <utility>


// ROOT Includes
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TMath.h"

// Defines
#define PI 3.141592654


/*
 * To run this script just type:  root -l -x llib.C 'ODAnalysis.C("wcsim.root", "ODHits.root", false)' 
 * or replace wcsim.root and ODHits.root for your input and output filenames respectively
 * The final true can be changed to true to turn on verbosity.
 * The default: root -l -x llib.C ODAnalysis.C will run with the variables mentioned above
 */



void pmtmapID( const char *inFileName = "/data2/kneale/hk-software/collimator_sims/collimator_13/reduced_wcsim_output_no_projection.root", bool verbosity = 1){ 
	
  // Some nicely formatted text options
  //std::cout << std::scientific; // This causes all numbers to be displayed in scientific notation.
  //std::cout << std::setprecision(5); // Sets the decimal precision (no more than two decimal places)
  std::cout << std::left; // Sets the text justification to left
  const int txtW = 20; // Width of "box" holding text
  const int numW = 10; // Width of "box" holding numbers
  
  
  // Open the WCSim file
  TFile *inFile = new TFile(inFileName, "READ"); 
  if ( !inFile->IsOpen() ){
    std::cout << "Error: could not open input file \"" << inFileName << "\"." <<std::endl; 	
  } else if (verbosity) {
    std::cout << "Input file: " << inFileName << std::endl;
  }

  TFile *profileX = new TFile("/data2/kneale/hk-software/diffuser_sims/ligen_bug/profile.root","READ");  
  if ( !profileX->IsOpen() ){
    std::cout << "Error: could not open diffuser profile x projection" <<std::endl; 	
  }
  TH2D *hProfX = (TH2D*)profileX->Get("h2_px"); 
  hProfX->Scale(1/hProfX->Integral());
  //-------------------- Reading in ----------------------

  //inFile->ls();
  // Geometry tree
  TTree *geoTree = (TTree*) inFile->Get("wcsimGeoT");
  WCSimRootGeom *geo = nullptr;//new WCSimRootGeom();
  geoTree->SetBranchAddress("wcsimrootgeom",&geo);
  if (verbosity) {std::cout << "Geotree has " << geoTree->GetEntries() << " entries." << std::endl;}
  geoTree->GetEntry(0);

  int num_ID_PMT = geo->GetWCNumPMT(); 
  std::vector<double> xpos(num_ID_PMT);
  std::vector<double> ypos(num_ID_PMT);
  std::vector<double> zpos(num_ID_PMT);
  std::vector<double> cyl(num_ID_PMT);
  std::vector<double> nearestInjector(num_ID_PMT);
  double barrelposx = -99999;
  double barrelposy = -99999;
  double toppos = -99999;
  double bottompos = -99999;
  float pmt_x[num_ID_PMT];
  float pmt_y[num_ID_PMT];

  for (int ipmt=0;ipmt<num_ID_PMT;ipmt++){

      WCSimRootPMT pmt = geo->GetPMT(ipmt);

      float geopmtX=pmt.GetPosition(0);
      float geopmtY=pmt.GetPosition(1);
      float geopmtZ=pmt.GetPosition(2);
      int location = pmt.GetCylLoc();
      xpos.at(ipmt) = geopmtX;
      ypos.at(ipmt) = geopmtY;
      zpos.at(ipmt) = geopmtZ;
      cyl.at(ipmt) = location;

      if (location== 1) {
        barrelposx = geopmtX;
        barrelposy = geopmtY;
      }
      else if (location ==0) {
        toppos = geopmtZ;
      }
      else if (location ==2) {
        bottompos = geopmtZ;
      }
  }

  double RadiusID = sqrt( pow(barrelposx,2) + pow(barrelposy,2) );
  double HeightID = 2*(abs(toppos));
  std::cerr << "radius " << RadiusID << " height " << HeightID/2 << std::endl;
  std::cerr << "top pmts " << toppos << " bottom pmts " << bottompos << std::endl;



  // TTree *inTree = Events;  
  TTree *inTree = (TTree*)inFile->Get("simulation");

  Long64_t nentries = inTree->GetEntries();

  std::cerr << "Entries " << nentries << std::endl;

  Int_t event;
  std::vector<Int_t> *tubeNumber=0;
  std::vector<Int_t> *cylLoc=0;
  std::vector<Float_t> *digiTime=0;
  std::vector<Float_t> *digiCharge=0;
  std::vector<Float_t> *pmtX=0;
  std::vector<Float_t> *pmtY=0;
  std::vector<Float_t> *pmtZ=0;
  Float_t injectorVtxX=0;
  Float_t injectorVtxY=0;
  Float_t injectorVtxZ=0;
  Float_t injectorDirX=0;
  Float_t injectorDirY=0;
  Float_t injectorDirZ=0;
  
  TBranch *binjectorDirX=0;
  TBranch *binjectorDirY=0;
  TBranch *binjectorDirZ=0;
  TBranch *binjectorVtxX=0;
  TBranch *binjectorVtxY=0;
  TBranch *binjectorVtxZ=0;
  TBranch *btubeNumber=0;
  TBranch *bdigiTime=0;
  TBranch *bdigiCharge=0;
  TBranch *bcylLoc=0;
  TBranch *bpmtX=0;
  TBranch *bpmtY=0;
  TBranch *bpmtZ=0;

  inTree->SetBranchAddress("injectorDirX",&injectorDirX,&binjectorDirX);
  inTree->SetBranchAddress("injectorDirY",&injectorDirY,&binjectorDirY);
  inTree->SetBranchAddress("injectorDirZ",&injectorDirZ,&binjectorDirZ);
  inTree->SetBranchAddress("injectorVtxX",&injectorVtxX,&binjectorVtxX);
  inTree->SetBranchAddress("injectorVtxY",&injectorVtxY,&binjectorVtxY);
  inTree->SetBranchAddress("injectorVtxZ",&injectorVtxZ,&binjectorVtxZ);
  inTree->SetBranchAddress("event",&event);
  inTree->SetBranchAddress("tubeNumber",&tubeNumber,&btubeNumber);
  inTree->SetBranchAddress("digiTime",&digiTime,&bdigiTime);
  inTree->SetBranchAddress("digiCharge",&digiCharge,&bdigiCharge);
  inTree->SetBranchAddress("cylLoc",&cylLoc,&bcylLoc);
  inTree->SetBranchAddress("pmtX",&pmtX,&bpmtX);
  inTree->SetBranchAddress("pmtY",&pmtY,&bpmtY);
  inTree->SetBranchAddress("pmtZ",&pmtZ,&bpmtZ);

  double WLSLength = 40;

  int n = inTree->GetEntries();


  // ---------------------------- Light coverage plots

  
  TH2Poly *IDQpoly = new TH2Poly("IDQpoly","Charge in ID PMTs",-12000,12000,-12000,12000);
  int total_pmts=0;
  for (int polybin = 0; polybin < num_ID_PMT; polybin++) {
    
    double tube[3];
    int cylLoc = cyl[polybin];
    tube[0] = xpos[polybin];
    tube[1] = ypos[polybin];
    tube[2] = zpos[polybin];
    
    float x = -9999;
    float y = -9999;

    // Bottom ID
    if ( cylLoc == 2){
      x = tube[0];
      y = -(tube[1] + RadiusID + HeightID/2 + 500.);
    }
    // Top ID
    else if ( cylLoc == 0){
      x = tube[0];
      y = (HeightID/2 +RadiusID +tube[1] + 500);
    }
    // Barrel ID
    else if ( cylLoc == 1) {

      double l = sqrt( pow((0 - tube[0]),2) + pow((-RadiusID - tube[1]),2));
      double angle = 2*asin(l/(2*RadiusID));
      double length = angle*RadiusID ;
      if (tube[0]<0) length *= -1;
      x = length;
      y = tube[2];
    }
    pmt_x[polybin] = x;
    pmt_y[polybin] = y;
    IDQpoly->AddBin(x - WLSLength, y - WLSLength, x + WLSLength, y + WLSLength);
  }

  // Now loop over all hits in all pulses to fill
  // light coverage plots
  std::vector<int> hits_per_pmt(num_ID_PMT,0);
  TGraph *tg = new TGraph();
  TH1D *hProfilethetahits = new TH1D("hProfilethetahits",";#theta(#circ)",180,-90,90);
  TH1D *hProfilethetacharge = new TH1D("hProfilethetacharge",";#theta(#circ)",180,-90,90);
  TH1D *hProfilephi = new TH1D("hProfilephi",";#phi(#circ)",360,-180,180);
  inTree->GetEntry(0);
  Long64_t firstentry = inTree->GetEntry(0);
  binjectorDirX->GetEntry(firstentry);
  binjectorDirY->GetEntry(firstentry);
  binjectorDirZ->GetEntry(firstentry);
  binjectorVtxX->GetEntry(firstentry);
  binjectorVtxY->GetEntry(firstentry);
  binjectorVtxZ->GetEntry(firstentry);
  std::cout << "inj x: " << injectorVtxX << ", inj y: " << injectorVtxY << ", inj z: " << injectorVtxZ << std::endl;
  for (Long64_t i=0; i < n; i++) {
    //
    inTree->GetEntry(i);
    Long64_t tentry = inTree->GetEntry(i);
    btubeNumber->GetEntry(tentry);
    bdigiTime->GetEntry(tentry);
    bdigiCharge->GetEntry(tentry);
    bcylLoc->GetEntry(tentry);
    bpmtX->GetEntry(tentry);
    bpmtY->GetEntry(tentry);
    bpmtZ->GetEntry(tentry);
    
    // Loop over all of the hits in this pulse
    int nhits = pmtX->size();
    std::cout << nhits << " PMTs hit" << std::endl;
    for (int ihit=0; ihit<nhits;ihit++){

      double pmtRad = sqrt((pow(pmtX->at(ihit), 2.0))+(pow(pmtY->at(ihit), 2.0)));
      double pmtTheta = std::atan(pmtY->at(ihit)/pmtX->at(ihit));
      double l = sqrt((pow((0-pmtX->at(ihit)),2)) + pow((-(HeightID/2.)-pmtY->at(ihit)),2));
      double angle = 2*asin(l/2*RadiusID);
      double length = angle*RadiusID;
      double IDpolyX;
      double IDpolyY;
//      if (digiTime->at(ihit)>1000) continue; 
      // Top
      if (cylLoc->at(ihit) == 0) {
        IDpolyX = pmtX->at(ihit);
        IDpolyY = (pmtY->at(ihit) + RadiusID + HeightID/2. + 500);
      }
      // Bottom
      else if (cylLoc->at(ihit) == 2) {
        IDpolyX = pmtX->at(ihit);
        IDpolyY = -(HeightID/2. +RadiusID + pmtY->at(ihit) + 500);
      }
      else if (cylLoc->at(ihit) == 1) {
        if (pmtX->at(ihit)>0) pmtTheta += (std::acos(-1)/2);
        else pmtTheta -= (std::acos(-1)/2);
        double pmtRadTheta = pmtRad*pmtTheta;
        IDpolyX = pmtRadTheta;
        IDpolyY = pmtZ->at(ihit);
      }
      IDQpoly->Fill(IDpolyX,IDpolyY,digiCharge->at(ihit));

      // Calculate the angle of the photon from the injector in theta and phi 
      // and fill a profile histogram to check the sampling
      // first get the x, y and z vectors from the injector to the pmt
      double dx = pmtX->at(ihit)-injectorVtxX;
      double dy = pmtY->at(ihit)-injectorVtxY;
      double dz = pmtZ->at(ihit)-injectorVtxZ;
      // use the unit vector
//      double r = sqrt(dx*dx+dy*dy+dz*dz);
//      dx = dx/r;
//      dy = dy/r;
//      dz = dz/r;
      // from this we can convert back to theta and phi
      double theta = atan(dx/dz)*180/TMath::Pi();
      double phi = atan2(dy,dx)*180/TMath::Pi();
      hProfilethetahits->Fill(theta);
      hProfilethetacharge->Fill(theta,digiCharge->at(ihit));
      hProfilephi->Fill(phi,digiCharge->at(ihit));
      tg->SetPoint(ihit,theta,phi);
    }

  }
  
  // Fill histograms of the number of PMTs in each theta and phi bin
  TH1D *hPMTsTheta = new TH1D("hPMTsTheta",";#theta(#circ)",180,-90,90);
  TH1D *hPMTsPhi = new TH1D("hPMTsPhi",";#phi(#circ)",360,-180,180);
  for (int ipmt=0;ipmt<num_ID_PMT;ipmt++){

      WCSimRootPMT pmt = geo->GetPMT(ipmt);

      float geopmtX=pmt.GetPosition(0);
      float geopmtY=pmt.GetPosition(1);
      float geopmtZ=pmt.GetPosition(2);
      double dx = geopmtX-injectorVtxX;
      double dy = geopmtY-injectorVtxY;
      double dz = geopmtZ-injectorVtxZ;
      double theta = atan(dx/dz)*180/TMath::Pi();
      double phi = atan2(dy,dx)*180/TMath::Pi();
      hPMTsTheta->Fill(theta);
      hPMTsPhi->Fill(phi);
  }
  

//  IDQpoly->Scale(1/(float)n);

  gStyle->SetOptStat(0);
  gStyle -> SetOptTitle(kFALSE);
  gStyle->SetPalette(55);

  TCanvas *cpq = new TCanvas("cpq","cpq");
  IDQpoly->GetZaxis()->SetTitle("Total digitised charge per pulse (pe)");
  IDQpoly->GetZaxis()->SetTitleOffset(1.3);
  cpq->SetFrameFillColor(0);
  cpq->SetFrameFillStyle(0);
  cpq->SetFrameLineColor(0);
  cpq->SetFrameBorderMode(0);
  cpq->SetRightMargin(0.15);
  IDQpoly->GetZaxis()->SetTitleOffset(1.4);
  IDQpoly->SetMinimum(IDQpoly->GetMinimum(0.));
  gPad->SetLogz(1);
//  IDQpoly->GetXaxis()->SetRangeUser(-4000,4000);
//  IDQpoly->GetYaxis()->SetRangeUser(-10000,-4000);
  IDQpoly->Draw("COLZ");
  cpq->SaveAs("diffuser_QCoverage.png");

//  TCanvas *cprofiletheta = new TCanvas("cprofiletheta","cprofiletheta",800,900);
//  hProfiletheta->Scale(1/hProfiletheta->Integral());
//  hProfiletheta->Draw("hist");
//  hProfX->Draw("histsame");
//  gPad->SetLogy();
//  cprofiletheta->SaveAs("reconstructed_diffuser_profile_normalised_fittotheta.C");
//  TCanvas *cprofilephi = new TCanvas("cprofilephi","cprofilephi",800,900);
//  hProfilephi->Draw();
//  cprofilephi->SaveAs("reconstructed_diffuser_profilephi.png");
  
  // Hits in theta and phi averaged over number of PMTs per theta and phi bin
 // TH1D *hProfiletheta2 = (TH1D*)hProfiletheta->Clone("hProfiletheta2");
  //hProfiletheta2->Divide(hPMTsTheta);
  hProfilethetacharge->Divide(hProfilethetahits);
  hProfilethetacharge->Scale(1/hProfilethetacharge->Integral());
  //hProfilethetahits->Divide(hPMTsTheta);
  //hProfilethetahits->Scale(1/hProfilethetahits->Integral());
  TH1D *hProfilephi2 = (TH1D*)hProfilephi->Clone("hProfilephi2");
  hProfilephi2->Divide(hPMTsPhi);

  TCanvas *cprofilethetacharge = new TCanvas("cprofilethetacharge","cprofilethetacharge",800,900);
  hProfX->Draw("hist");
  hProfilethetacharge->Draw("histsame");
//  gPad->SetLogy();
  cprofilethetacharge->SaveAs("reconstructed_diffuser_profile_normalised_fittotheta_average.C");
  TCanvas *cprofilephi2 = new TCanvas("cprofilephi2","cprofilephi2",800,900);
  hProfilephi2->Draw("hist");
  cprofilephi2->SaveAs("reconstructed_diffuser_profilephi2.png");
}


