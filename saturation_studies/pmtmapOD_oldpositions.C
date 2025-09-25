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

// Defines
#define PI 3.141592654


/*
 * To run this script just type:  root -l -x llib.C 'ODAnalysis.C("wcsim.root", "ODHits.root", false)' 
 * or replace wcsim.root and ODHits.root for your input and output filenames respectively
 * The final true can be changed to true to turn on verbosity.
 * The default: root -l -x llib.C ODAnalysis.C will run with the variables mentioned above
 */



// A function to convert radians to degress
float RadToDeg(float x){
  return x*180/PI;
}
// A function to convert degress to radians
float DegToRad(float x){
  return x*PI/180;
}

// A function to calculate the distance to the nearest injector
Double_t PMTInjectorDistance(float pmtx, float pmty, float pmtz, std::vector<float> injectorPosX,std::vector<float> injectorPosY,std::vector<float> injectorPosZ ) {
  Double_t distance = 999999;
  for (int i = 0; i < injectorPosX.size(); i++) {
    double injx = injectorPosX[i];
    double injy = injectorPosY[i];
    double injz = injectorPosZ[i];

    //std::cerr << " IX " << injx << " IY " << injy << " IZ " << injz << std::endl;
    //std::cerr << " PX " << pmt[0] << " PY " << pmt[1] << " PZ " << pmt[2] << std::endl;

    Double_t xsquared = pow((pmtx - injx),2.0);
    Double_t ysquared = pow((pmty - injy),2.0);
    Double_t zsquared = pow((pmtz - injz),2.0);
    Double_t temp_dist = sqrt(xsquared + ysquared + zsquared);
    //std::cerr << distance << " " << temp_dist << std::endl;
    if (temp_dist < distance) distance = temp_dist;
    //std::cerr << distance << std::endl;
  }
  return distance;

}


void pmtmapOD( const char *inFileName = "/data2/kneale/hk-software/diffuser_sims/reduced_od_diffuser_test.root", bool verbosity = 1, float saturation_distance = 422.00, float saturation_limit = 599.0654){ 
	
  // Some nicely formatted text options
  //std::cout << std::scientific; // This causes all numbers to be displayed in scientific notation.
  //std::cout << std::setprecision(5); // Sets the decimal precision (no more than two decimal places)
  std::cout << std::left; // Sets the text justification to left
  const int txtW = 20; // Width of "box" holding text
  const int numW = 10; // Width of "box" holding numbers
  
  
  // Get the positions of the injectors
  int num_columns = 12;
  int num_rows = 7;
  int num_injectors = num_columns*num_rows+38;
  float injRad=3305.27;
  float rowPositions[7] = {-2719.91,-1871.7,-1023.49,-175.282,672.926,1521.13,2369.34};
  std::vector<float> injectorPosX; 
  std::vector<float> injectorPosY;
  std::vector<float> injectorPosZ;
  std::vector<float> injectorLoc;
  float injector_x[num_injectors];
  float injector_y[num_injectors];
  float pi = 3.141592653589793;
  int injectorNumber=0;

  std::ofstream injectorPositionsFile;
  injectorPositionsFile.open("injectorPositions.txt");
  std::cout << injectorPositionsFile.is_open() <<std::endl;

  if(verbosity){
    injectorPositionsFile << "Barrel positions \n" << std::endl;
  }

  // Add the barrel injectors
  for (int rowIdx=0; rowIdx <num_rows; rowIdx++){

    // Five rows with 16 injectors
    // Find the angular spacing between injectors
    int injectorIdx;
    float theta = 2*pi/num_columns;
    float offset = 0;
    // offset two of the rows
    if (rowIdx%2==0){
      offset = 0.5*theta;
    }
    // Find the injector positions with this spacing
    for (int colIdx=0;colIdx<num_columns;colIdx++){
      float injTheta = colIdx*theta+offset;
      float x = injRad*cos(injTheta);
      float y = injRad*sin(injTheta);
      float z = rowPositions[rowIdx];
      if(verbosity){
        injectorPositionsFile << x << ", " << y << ", " << z << std::endl;
      }
      injectorPosX.push_back(x);
      injectorPosY.push_back(y);
      injectorPosZ.push_back(z);
      float plotTheta = std::atan(y/x);
      if (x>=0){
        plotTheta += (std::acos(-1)/2);
      }
      else {
        plotTheta -= (std::acos(-1)/2);
      }
      double injRadTheta = injRad*plotTheta;
      double ODpolyX = injRadTheta;
      double ODpolyY = z;
      injector_x[injectorIdx] = ODpolyX;
      injector_y[injectorIdx] = ODpolyY;
      injectorIdx++;
      if (verbosity){
        std::cout << "projected injector position: " << ODpolyX << ", " << ODpolyY  << std::endl;
      }
    }
 
  }

  // Add the top and bottom cap injectors
  float radius = 3305.27;
  float halfheight = 3350.82;
  std::vector<float>capPosX;
  std::vector<float>capPosY;
  
  if(verbosity){
    injectorPositionsFile << "\n\n\nEndcap positions \n" << std::endl;
      injectorPositionsFile << "top cap z position " << halfheight << std::endl;
      injectorPositionsFile << "bottom cap z position -" << halfheight << "\n" << std::endl;
      injectorPositionsFile << "endcap x and y positions:" << std::endl;
  }
  
  // central row
  float positions_centre[5] = {-2259.2,-1129.6,0.,1129.6,2259.2}; //5 per row
  for (int i=0;i<5;i++){
    float y = 0.;
    float x = positions_centre[i];
    capPosX.push_back(x);
    capPosY.push_back(y);
  }
  // top and bottom row
  float positions_outer[3] = {-1129.6,0,1129.6}; // 3 per row
  for (int i=0;i<3;i++){
    float x = positions_outer[i];
    float y = 2118.0;
    capPosX.push_back(x);
    capPosY.push_back(y);
    y = -2118.0;
    capPosX.push_back(x);
    capPosY.push_back(y);
  }
  // middle two rows
  float positions_inner[4]= {-1835.6,-706.0,706.0,1835.6};
  for (int i=0;i<4;i++){
    float x = positions_inner[i];
    float y = 1059.0;
    capPosX.push_back(x);
    capPosY.push_back(y);
    y = -1059.0;
    capPosX.push_back(x);
    capPosY.push_back(y);
  }
  
  for (int i=0;i<19;i++){
    int size = injectorPosX.size();
    injectorPosX.push_back(capPosX[i]);
    injectorPosY.push_back(capPosY[i]);
    injectorPosZ.push_back(halfheight);
    injectorPosX.push_back(capPosX[i]);
    injectorPosY.push_back(capPosY[i]);
    injectorPosZ.push_back(-halfheight);
    // top
    double ODpolyX = capPosX[i];
    double ODpolyY = -(capPosY[i]+radius+halfheight+500);
    injector_x[size] = ODpolyX;
    injector_y[size] = ODpolyY;
    if(verbosity){
    }
    // bottom
    ODpolyY = (capPosY[i]+radius+halfheight+500);
    injector_x[size+1] = ODpolyX;
    injector_y[size+1] = ODpolyY;
    
    if (verbosity){
      injectorPositionsFile << capPosX[i] << ", " << capPosY[i] << std::endl;
      std::cout << injector_x[size] << ", " << injector_y[size] << std::endl;
      std::cout << injector_x[size+1] << ", " << injector_y[size+1] << std::endl;
    }
  }
  // Add the endcap injectors
  injectorPositionsFile.close();


  // Open the WCSim file
  TFile *inFile = new TFile(inFileName, "READ"); 
  if ( !inFile->IsOpen() ){
    std::cout << "Error: could not open input file \"" << inFileName << "\"." <<std::endl; 	
  } else if (verbosity) {
    std::cout << "Input file: " << inFileName << std::endl;
  }
	
  //-------------------- Reading in ----------------------

  //inFile->ls();
  // Geometry tree
  TTree *geoTree = (TTree*) inFile->Get("wcsimGeoT");
  WCSimRootGeom *geo = nullptr;//new WCSimRootGeom();
  geoTree->SetBranchAddress("wcsimrootgeom",&geo);
  if (verbosity) {std::cout << "Geotree has " << geoTree->GetEntries() << " entries." << std::endl;}
  geoTree->GetEntry(0);

  int num_OD_PMT = geo->GetODWCNumPMT(); 
  std::vector<double> xpos(num_OD_PMT);
  std::vector<double> ypos(num_OD_PMT);
  std::vector<double> zpos(num_OD_PMT);
  std::vector<double> cyl(num_OD_PMT);
  std::vector<double> nearestInjector(num_OD_PMT);
  double barrelposx = -99999;
  double barrelposy = -99999;
  double toppos = -99999;
  double bottompos = -99999;
  float pmt_x[num_OD_PMT];
  float pmt_y[num_OD_PMT];


  TH1D *h1 = new TH1D("h1","",1100,0,1500);

  int saturated_barrel_pmts=0;
  int barrel_pmts=0;
  int saturated_top_cap_pmts=0;
  int top_cap_pmts=0;
  int saturated_bottom_cap_pmts=0;
  int bottom_cap_pmts=0;
  for (int ipmt=0;ipmt<num_OD_PMT;ipmt++){

      WCSimRootPMT pmt = geo->GetODPMT(ipmt);

      float geopmtX=pmt.GetPosition(0);
      float geopmtY=pmt.GetPosition(1);
      float geopmtZ=pmt.GetPosition(2);
      int location = pmt.GetCylLoc();
      xpos.at(ipmt) = geopmtX;
      ypos.at(ipmt) = geopmtY;
      zpos.at(ipmt) = geopmtZ;
      cyl.at(ipmt) = location;

      float nearestInjectorTmp = PMTInjectorDistance(geopmtX,geopmtY,geopmtZ,injectorPosX,injectorPosY,injectorPosZ);  
      nearestInjector.at(ipmt) = nearestInjectorTmp;
      h1->Fill(PMTInjectorDistance(geopmtX,geopmtY,geopmtZ,injectorPosX,injectorPosY,injectorPosZ));
  
      if (location == 4) {
        barrelposx = geopmtX;
        barrelposy = geopmtY;
        barrel_pmts++;
//        if (nearestInjectorTmp<saturation_limit || nearestInjectorTmp==saturation_limit) {
        if (nearestInjectorTmp<saturation_distance || nearestInjectorTmp==saturation_distance) {
          saturated_barrel_pmts++;
        } 
      }
      else if (location == 5) {
        toppos = geopmtZ;
        top_cap_pmts++;
        if (nearestInjectorTmp<saturation_limit || nearestInjectorTmp==saturation_limit) {
//        if (nearestInjectorTmp<saturation_distance || nearestInjectorTmp==saturation_distance) {
          saturated_top_cap_pmts++;
        } 
      }
      else if (location == 3) {
        bottompos = geopmtZ;
        bottom_cap_pmts++;
        if (nearestInjectorTmp<saturation_limit || nearestInjectorTmp==saturation_limit) {
//        if (nearestInjectorTmp<saturation_distance || nearestInjectorTmp==saturation_distance) {
          saturated_bottom_cap_pmts++;
        } 
      }
  }

  double percent_saturated_barrel_pmts = saturated_barrel_pmts/(float)(barrel_pmts)*100;
  std::cout << "saturated barrel pmts " << saturated_barrel_pmts << std::endl;
  std::cout << "per cent saturated barrel pmts " << percent_saturated_barrel_pmts << std::endl;
  double percent_saturated_top_cap_pmts = saturated_top_cap_pmts/(float)(top_cap_pmts)*100;
  std::cout << "saturated top_cap pmts " << saturated_top_cap_pmts << std::endl;
  std::cout << "per cent saturated top_cap pmts " << percent_saturated_top_cap_pmts << std::endl;
  double percent_saturated_bottom_cap_pmts = saturated_bottom_cap_pmts/(float)(bottom_cap_pmts)*100;
  std::cout << "saturated bottom_cap pmts " << saturated_bottom_cap_pmts << std::endl;
  std::cout << "per cent saturated bottom_cap pmts " << percent_saturated_bottom_cap_pmts << std::endl;

  double RadiusOD = sqrt( pow(barrelposx,2) + pow(barrelposy,2) );
  double HeightOD = 2*(abs(toppos));
  std::cerr << "radius " << RadiusOD << " height " << HeightOD << std::endl;
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
  
  TBranch *btubeNumber=0;
  TBranch *bdigiTime=0;
  TBranch *bdigiCharge=0;
  TBranch *bcylLoc=0;
  TBranch *bpmtX=0;
  TBranch *bpmtY=0;
  TBranch *bpmtZ=0;

  inTree->SetBranchAddress("event",&event);
  inTree->SetBranchAddress("tubeNumber",&tubeNumber,&btubeNumber);
  inTree->SetBranchAddress("digiTime",&digiTime,&bdigiTime);
  inTree->SetBranchAddress("digiCharge",&digiCharge,&bdigiCharge);
  inTree->SetBranchAddress("cylLoc",&cylLoc,&bcylLoc);
  inTree->SetBranchAddress("pmtX",&pmtX,&bpmtX);
  inTree->SetBranchAddress("pmtY",&pmtY,&bpmtY);
  inTree->SetBranchAddress("pmtZ",&pmtZ,&bpmtZ);

  double WLSLength = 60;

  int n = inTree->GetEntries();


  // ---------------------------- Light coverage plots

  
  TH2Poly *ODQpoly = new TH2Poly("ODQ","Charge in OD PMTs",-12000,12000,-12000,12000);
   int total_pmts=0;
  for (int polybin = 0; polybin < num_OD_PMT; polybin++) {
    
    double tube[3];
    int cylLoc = cyl[polybin];
    tube[0] = xpos[polybin];
    tube[1] = ypos[polybin];
    tube[2] = zpos[polybin];
    
    float x = -9999;
    float y = -9999;

    // Bottom OD
    if ( cylLoc == 3){
      x = tube[0];
      y = -(tube[1] + RadiusOD + halfheight + 500.);
    }
    // Top OD
    else if ( cylLoc == 5){
      x = tube[0];
      y = (halfheight +RadiusOD +tube[1] + 500);
    }
    // Barrel OD
    else {

      double l = sqrt( pow((0 - tube[0]),2) + pow((-RadiusOD - tube[1]),2));
      double angle = 2*asin(l/(2*RadiusOD));
      double length = angle*RadiusOD ;
      if (tube[0]<0) length *= -1;
      x = length;
      y = tube[2];
    }
    pmt_x[polybin] = x;
    pmt_y[polybin] = y;
    ODQpoly->AddBin(x - WLSLength, y - WLSLength, x + WLSLength, y + WLSLength);
  }


  // Now loop over all hits in all pulses to fill
  // light coverage plots
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
    for (int ihit=0; ihit<nhits;ihit++){

      double pmtRad = sqrt((pow(pmtX->at(ihit), 2.0))+(pow(pmtY->at(ihit), 2.0)));
      double pmtTheta = std::atan(pmtY->at(ihit)/pmtX->at(ihit));
      double l = sqrt((pow((0-pmtX->at(ihit)),2)) + pow((-(halfheight)-pmtY->at(ihit)),2));
      double angle = 2*asin(l/2*RadiusOD);
      double length = angle*RadiusOD;
      double ODpolyX;
      double ODpolyY;
      
      // Top
      if (cylLoc->at(ihit) == 5) {
        ODpolyX = pmtX->at(ihit);
        ODpolyY = (pmtY->at(ihit) + RadiusOD + halfheight + 500);
      }
      // Bottom
      else if (cylLoc->at(ihit) == 3) {
        ODpolyX = pmtX->at(ihit);
        ODpolyY = -(halfheight +RadiusOD + pmtY->at(ihit) + 500);
      }
      else if (cylLoc->at(ihit) == 4) {
        if (pmtX->at(ihit)>0) pmtTheta += (std::acos(-1)/2);
        else pmtTheta -= (std::acos(-1)/2);
        double pmtRadTheta = pmtRad*pmtTheta;
        ODpolyX = pmtRadTheta;
        ODpolyY = pmtZ->at(ihit);
      }
      ODQpoly->Fill(ODpolyX,ODpolyY,digiCharge->at(ihit));
    }
  }

  ODQpoly->Scale(1/(float)n);

  gStyle->SetOptStat(0);
  gStyle -> SetOptTitle(kFALSE);
  gStyle->SetPalette(55);

  TCanvas *cpq = new TCanvas("cpq","cpq",1800,1800);
  ODQpoly->GetZaxis()->SetTitle("Total digitised charge per pulse (pe)");
  ODQpoly->GetZaxis()->SetTitleOffset(1.3);
  cpq->SetFrameFillColor(0);
  cpq->SetFrameFillStyle(0);
  cpq->SetFrameLineColor(0);
  cpq->SetFrameBorderMode(0);
  cpq->SetRightMargin(0.15);
  ODQpoly->GetZaxis()->SetTitleOffset(1.4);
  ODQpoly->SetMinimum(ODQpoly->GetMinimum(0.));
  gPad->SetLogz(1);
//  ODQpoly->GetXaxis()->SetRangeUser(-4000,4000);
//  ODQpoly->GetYaxis()->SetRangeUser(-10000,-4000);
  ODQpoly->Draw("COLZ");
  
  TGraph *tginjector = new TGraph(num_injectors,injector_x,injector_y);
  tginjector->SetMarkerStyle(20);
  tginjector->SetMarkerSize(2.0);
  tginjector->Draw("p same");
  for (int i=0;i<num_injectors;i++){
      if(injector_x[i]>-4000 && injector_x[i]<4000 && injector_y[i]>-10000 && injector_y[i]<-4000){
      auto circle = new TEllipse(injector_x[i],injector_y[i],saturation_distance+10);
      circle->SetLineColor(kRed);
      circle->SetLineWidth(2);
      circle->SetFillStyle(0);
      circle->Draw("same");
      auto circle2 = new TEllipse(injector_x[i],injector_y[i],saturation_limit+10);
      circle2->SetLineColor(kBlue);
      circle2->SetLineWidth(2);
      circle2->SetFillStyle(0);
      circle2->Draw("same");
      }
  }
  cpq->SaveAs("diffuse_QCoverage.png");

  TCanvas *ctg = new TCanvas("ctg","ctg",650,600);
  TGraph *tgpmt = new TGraph(num_OD_PMT,pmt_x,pmt_y);
  std::cout << "number of injectors: " << sizeof(injector_x)/sizeof(int) << std::endl;
  tgpmt->SetMarkerColor(2);
  tgpmt->SetMarkerStyle(20);
  tgpmt->SetMarkerSize(1);
  tginjector->SetMarkerStyle(20);
  tginjector->SetMarkerSize(2);
  tgpmt->Draw("ap");
  tginjector->Draw("p same");
  tgpmt->Draw("p same");

  TCanvas *c1 = new TCanvas("c1","c1",650,600);
  h1->Draw();
}


