// C++ Includes
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <utility>

// ROOT Includes
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"

// Defines
#define PI 3.141592654
float radius = 3305.27;     // barrel injector radius
float halfheight = 3350.82; // endcap injector distance from centre

/*
 * To run this script just type:  root -l -x llib.C 'ODAnalysis.C("wcsim.root", "ODHits.root", false)'
 * or replace wcsim.root and ODHits.root for your input and output filenames respectively
 * The final true can be changed to true to turn on verbosity.
 * The default: root -l -x llib.C ODAnalysis.C will run with the variables mentioned above
 */

// A function to convert radians to degress
float RadToDeg(float x)
{
  return x * 180 / PI;
}
// A function to convert degress to radians
float DegToRad(float x)
{
  return x * PI / 180;
}

// A function to calculate the distance to the nearest injector
Double_t PMTInjectorDistance(float pmtx, float pmty, float pmtz, std::vector<float> injectorPosX, std::vector<float> injectorPosY, std::vector<float> injectorPosZ)
{
  Double_t distance = 999999;
  for (int i = 0; i < injectorPosX.size(); i++)
  {
    double injx = injectorPosX[i];
    double injy = injectorPosY[i];
    double injz = injectorPosZ[i];
    Double_t xsquared = pow((pmtx - injx), 2.0);
    Double_t ysquared = pow((pmty - injy), 2.0);
    Double_t zsquared = pow((pmtz - injz), 2.0);
    Double_t temp_dist = sqrt(xsquared + ysquared + zsquared);
    if (temp_dist < distance)
      distance = temp_dist;
  }
  return distance;
}

void pmtmapOD(const char *inFileName = "/data2/kneale/hk-software/diffuser_sims/diffuser_93/reduced_test_wcsim.root", bool verbosity = 1, bool circles = 0, float saturation_distance = 434, float saturation_limit = 667.016)
{

  // Some nicely formatted text options
  // std::cout << std::scientific; // This causes all numbers to be displayed in scientific notation.
  // std::cout << std::setprecision(5); // Sets the decimal precision (no more than two decimal places)
  std::cout << std::left; // Sets the text justification to left
  const int txtW = 20;    // Width of "box" holding text
  const int numW = 10;    // Width of "box" holding numbers

  // Get the positions of the injectors from file
  // These are the final positions provided by Sam Jenkins

  int num_injectors = 122;
  std::vector<float> injectorPosX;
  std::vector<float> injectorPosY;
  std::vector<float> injectorPosZ;
  std::vector<float> injectorLoc;
  float injector_x[num_injectors];
  float injector_y[num_injectors];
  int injectorNumber = 0;

  // read from file
  std::ifstream injectorPositionsFile("../diffuser_simulations/ODDiffusers_September2025v2.txt");
  int injectorIdx = 0;
  std::string line;
  if (!injectorPositionsFile.is_open())
  {
    std::cerr << "Error opening the file!";
    return;
  }
  else
  {
    // read x, y and z position from file

    while (std::getline(injectorPositionsFile, line))
    {
      std::vector<float> xyz;
      std::istringstream iss(line);
      while (std::getline(iss, line, ','))
      {
        xyz.push_back(std::stof(line));
      }

      // fill vectors of x,y,z positions
      float x = xyz[1];
      float y = xyz[2];
      float z = xyz[3];
      injectorPosX.push_back(x);
      injectorPosY.push_back(y);
      injectorPosZ.push_back(z);

      // now fill vectors of positions on the
      // unfolded cylinder for the plot
      if (abs(z) < halfheight)
      {
        // barrel
        float injRad = sqrt(pow(x, 2) + pow(y, 2));
        float plotTheta = std::atan(y / x);
        if (x >= 0)
        {
          plotTheta += (std::acos(-1) / 2);
        }
        else
        {
          plotTheta -= (std::acos(-1) / 2);
        }
        double injRadTheta = injRad * plotTheta;
        double ODpolyX = injRadTheta;
        double ODpolyY = z;
        injector_x[injectorIdx] = ODpolyX;
        injector_y[injectorIdx] = ODpolyY;
      }
      else if (z == halfheight)
      {
        // top
        double ODpolyY = y + radius + halfheight + 500;
        injector_x[injectorIdx] = x;
        injector_y[injectorIdx] = ODpolyY;
      }
      else if (z == -halfheight)
      {

        // bottom
        double ODpolyY = -(y + radius + halfheight + 500);
        injector_x[injectorIdx] = x;
        injector_y[injectorIdx] = ODpolyY;
      }
      else
      {
        std::cout << "ERROR Not classed as barrel or endcap PMT" << std::endl;
      }
      injectorIdx++;
    }
  }

  injectorPositionsFile.close();

  // Open the WCSim file
  TFile *inFile = new TFile(inFileName, "READ");
  if (!inFile->IsOpen())
  {
    std::cout << "Error: could not open input file \"" << inFileName << "\"." << std::endl;
  }
  else if (verbosity)
  {
    std::cout << "Input file: " << inFileName << std::endl;
  }

  //-------------------- Reading in ----------------------

  // inFile->ls();
  //  Geometry tree
  TTree *geoTree = (TTree *)inFile->Get("wcsimGeoT");
  WCSimRootGeom *geo = nullptr; // new WCSimRootGeom();
  geoTree->SetBranchAddress("wcsimrootgeom", &geo);
  if (verbosity)
  {
    std::cout << "Geotree has " << geoTree->GetEntries() << " entries." << std::endl;
  }
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

  TH1D *h1 = new TH1D("h1", "", 1100, 0, 1500);

  int saturated_barrel_pmts = 0;
  int barrel_pmts = 0;
  int saturated_top_cap_pmts = 0;
  int top_cap_pmts = 0;
  int saturated_bottom_cap_pmts = 0;
  int bottom_cap_pmts = 0;
  int barrel_pmts_in_saturation_limit = 0;
  int top_pmts_in_saturation_limit = 0;
  int bottom_pmts_in_saturation_limit = 0;
  for (int ipmt = 0; ipmt < num_OD_PMT; ipmt++)
  {

    WCSimRootPMT pmt = geo->GetODPMT(ipmt);

    float geopmtX = pmt.GetPosition(0);
    float geopmtY = pmt.GetPosition(1);
    float geopmtZ = pmt.GetPosition(2);
    int location = pmt.GetCylLoc();
    xpos.at(ipmt) = geopmtX;
    ypos.at(ipmt) = geopmtY;
    zpos.at(ipmt) = geopmtZ;
    cyl.at(ipmt) = location;

    float nearestInjectorTmp = PMTInjectorDistance(geopmtX, geopmtY, geopmtZ, injectorPosX, injectorPosY, injectorPosZ);
    nearestInjector.at(ipmt) = nearestInjectorTmp;
    h1->Fill(PMTInjectorDistance(geopmtX, geopmtY, geopmtZ, injectorPosX, injectorPosY, injectorPosZ));

    if (location == 4)
    {
      barrelposx = geopmtX;
      barrelposy = geopmtY;
      barrel_pmts++;
      if (nearestInjectorTmp<saturation_distance || nearestInjectorTmp==saturation_distance)
      {
        saturated_barrel_pmts++;
      }
      if (nearestInjectorTmp < saturation_limit || nearestInjectorTmp == saturation_limit)
      { 
        barrel_pmts_in_saturation_limit++;
      }
    }
    else if (location == 5)
    {
      toppos = geopmtZ;
      top_cap_pmts++;
      if (nearestInjectorTmp < saturation_distance || nearestInjectorTmp == saturation_distance){
        saturated_top_cap_pmts++;
      }
      if (nearestInjectorTmp < saturation_limit || nearestInjectorTmp == saturation_limit)
      { 
        top_pmts_in_saturation_limit++;
      }
    }
    else if (location == 3)
    {
      bottompos = geopmtZ;
      bottom_cap_pmts++;
      if (nearestInjectorTmp < saturation_distance || nearestInjectorTmp == saturation_distance)
      {
        saturated_bottom_cap_pmts++;
      }
      if (nearestInjectorTmp < saturation_limit || nearestInjectorTmp == saturation_limit)
      { 
        bottom_pmts_in_saturation_limit++;
      }
    }
  }

  double percent_saturated_barrel_pmts = saturated_barrel_pmts / (float)(barrel_pmts) * 100;
  double percent_barrel_pmts_in_limit = barrel_pmts_in_saturation_limit/(float)(barrel_pmts) *100;
  std::cout << "saturated barrel pmts " << saturated_barrel_pmts << std::endl;
  std::cout << "per cent saturated barrel pmts " << percent_saturated_barrel_pmts << std::endl;
  std::cout << "per cent barrel pmts within limit " << percent_barrel_pmts_in_limit << std::endl;
  double percent_saturated_top_cap_pmts = saturated_top_cap_pmts / (float)(top_cap_pmts) * 100;
  double percent_top_pmts_in_limit = top_pmts_in_saturation_limit /(float)(top_cap_pmts) * 100;
  std::cout << "saturated top_cap pmts " << saturated_top_cap_pmts << std::endl;
  std::cout << "per cent saturated top_cap pmts " << percent_saturated_top_cap_pmts << std::endl;
  std::cout << "per cent top pmts within limit " << percent_top_pmts_in_limit << std::endl;
  double percent_saturated_bottom_cap_pmts = saturated_bottom_cap_pmts / (float)(bottom_cap_pmts) * 100;
  double percent_bottom_pmts_in_limit = bottom_pmts_in_saturation_limit /(float)(bottom_cap_pmts) * 100;
  std::cout << "saturated bottom_cap pmts " << saturated_bottom_cap_pmts << std::endl;
  std::cout << "per cent saturated bottom_cap pmts " << percent_saturated_bottom_cap_pmts << std::endl;
  std::cout << "per cent bottom pmts within limit " << percent_bottom_pmts_in_limit << std::endl;

  // TTree *inTree = Events;
  TTree *inTree = (TTree *)inFile->Get("simulation");

  Long64_t nentries = inTree->GetEntries();

  std::cerr << "Entries " << nentries << std::endl;

  Int_t event;
  std::vector<Int_t> *tubeNumber = 0;
  std::vector<Int_t> *cylLoc = 0;
  std::vector<Float_t> *digiTime = 0;
  std::vector<Float_t> *digiCharge = 0;
  std::vector<Float_t> *pmtX = 0;
  std::vector<Float_t> *pmtY = 0;
  std::vector<Float_t> *pmtZ = 0;

  TBranch *btubeNumber = 0;
  TBranch *bdigiTime = 0;
  TBranch *bdigiCharge = 0;
  TBranch *bcylLoc = 0;
  TBranch *bpmtX = 0;
  TBranch *bpmtY = 0;
  TBranch *bpmtZ = 0;

  inTree->SetBranchAddress("event", &event);
  inTree->SetBranchAddress("tubeNumber", &tubeNumber, &btubeNumber);
  inTree->SetBranchAddress("digiTime", &digiTime, &bdigiTime);
  inTree->SetBranchAddress("digiCharge", &digiCharge, &bdigiCharge);
  inTree->SetBranchAddress("cylLoc", &cylLoc, &bcylLoc);
  inTree->SetBranchAddress("pmtX", &pmtX, &bpmtX);
  inTree->SetBranchAddress("pmtY", &pmtY, &bpmtY);
  inTree->SetBranchAddress("pmtZ", &pmtZ, &bpmtZ);

  double WLSLength =60;

  int n = inTree->GetEntries();

  // ---------------------------- Light coverage plots

  TH2Poly *ODQpoly = new TH2Poly("ODQ", "Charge in OD PMTs", -12000, 12000, -12000, 12000);
  int total_pmts = 0;
  for (int polybin = 0; polybin < num_OD_PMT; polybin++)
  {

    double tube[3];
    int cylLoc = cyl[polybin];
    tube[0] = xpos[polybin];
    tube[1] = ypos[polybin];
    tube[2] = zpos[polybin];

    float x = -9999;
    float y = -9999;

    // Bottom OD
    if (cylLoc == 3)
    {
      x = tube[0];
      y = -(tube[1] + radius + halfheight + 500.);
    }
    // Top OD
    else if (cylLoc == 5)
    {
      x = tube[0];
      y = (halfheight + radius + tube[1] + 500);
    }
    // Barrel OD
    else
    {

      double l = sqrt(pow((0 - tube[0]), 2) + pow((-radius - tube[1]), 2));
      double angle = 2 * asin(l / (2 * radius));
      double length = angle * radius;
      if (tube[0] < 0)
        length *= -1;
      x = length;
      y = tube[2];
    }
    pmt_x[polybin] = x;
    pmt_y[polybin] = y;
    ODQpoly->AddBin(x - WLSLength, y - WLSLength, x + WLSLength, y + WLSLength);
  }

  // Now loop over all hits in all pulses to fill
  // light coverage plots
  
  for (Long64_t i = 0; i < n; i++)
  {
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
    for (int ihit = 0; ihit < nhits; ihit++)
    {

      double pmtRad = sqrt((pow(pmtX->at(ihit), 2.0)) + (pow(pmtY->at(ihit), 2.0)));
      double pmtTheta = std::atan(pmtY->at(ihit) / pmtX->at(ihit));
      double l = sqrt((pow((0 - pmtX->at(ihit)), 2)) + pow((-(halfheight)-pmtY->at(ihit)), 2));
      double angle = 2 * asin(l / 2 * radius);
      double length = angle * radius;
      double ODpolyX;
      double ODpolyY;

      // Top
      if (cylLoc->at(ihit) == 5)
      { 
        ODpolyX = pmtX->at(ihit);
        ODpolyY = (pmtY->at(ihit) + radius + halfheight + 500);
      }
      // Bottom
      else if (cylLoc->at(ihit) == 3)
      {
        ODpolyX = pmtX->at(ihit);
        ODpolyY = -(halfheight + radius + pmtY->at(ihit) + 500);
      }
      else if (cylLoc->at(ihit) == 4)
      {
        if (pmtX->at(ihit) > 0)
          pmtTheta += (std::acos(-1) / 2);
        else
          pmtTheta -= (std::acos(-1) / 2);
        double pmtRadTheta = pmtRad * pmtTheta;
        ODpolyX = pmtRadTheta;
        ODpolyY = pmtZ->at(ihit);
      }
    ODQpoly->Fill(ODpolyX, ODpolyY, digiCharge->at(ihit));
    }
  }

  ODQpoly->Scale(1 / (float)n);
//  for (int polybin = 0; polybin < num_OD_PMT; polybin++)
//  {
//    ODQpoly->SetBinContent(polybin,0);
//  }

  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(kFALSE);
  gStyle->SetPalette(55);

  TCanvas *cpq = new TCanvas("cpq", "cpq", 1800, 1800);
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
  
  //ODQpoly->GetXaxis()->SetRangeUser(-4000,4000);
  //ODQpoly->GetYaxis()->SetRangeUser(-10000,-4000);
  ODQpoly->GetXaxis()->SetTitle("Horizontal distance from x=0 (cm)");
  ODQpoly->Draw("COL");

  TGraph *tginjector = new TGraph(num_injectors, injector_x, injector_y);
  tginjector->SetMarkerStyle(20);
  tginjector->SetMarkerSize(1.0);
  tginjector->Draw("p same");
  if(circles){
   for (int i = 0; i < num_injectors; i++)
     {
      //if (injector_x[i] > -4000 && injector_x[i] < 4000 && injector_y[i] < 10000 && injector_y[i] > -4000)
      if (injector_y[i] > -4000 && injector_y[i] < 4000 )
      {
        auto circle = new TEllipse(injector_x[i], injector_y[i], saturation_distance + 10);
        circle->SetLineColor(kRed);
        circle->SetLineWidth(2);
        circle->SetFillStyle(0);
        circle->Draw("same");
        auto circle2 = new TEllipse(injector_x[i], injector_y[i], saturation_limit + 10);
        circle2->SetLineColor(kBlue);
        circle2->SetLineWidth(2);
        circle2->SetFillStyle(0);
        circle2->Draw("same");
      }
    }
  }
  cpq->SaveAs("diffuse_QCoverage.png");

//  TCanvas *ctg = new TCanvas("ctg", "ctg", 650, 600);
  TGraph *tgpmt = new TGraph(num_OD_PMT, pmt_x, pmt_y);
  std::cout << "number of injectors: " << sizeof(injector_x) / sizeof(int) << std::endl;
  tgpmt->SetMarkerColor(2);
  tgpmt->SetMarkerStyle(20);
  tgpmt->SetMarkerSize(1);
  tginjector->SetMarkerStyle(20);
  tginjector->SetMarkerSize(1);
//  tgpmt->Draw("ap");
//  tginjector->Draw("p same");
//  tgpmt->Draw("p same");
//  TCanvas *c1 = new TCanvas("c1", "c1", 650, 600);
//  h1->Draw();
}
