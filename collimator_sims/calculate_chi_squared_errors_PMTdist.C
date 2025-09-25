#include <stdio.h>     
#include <stdlib.h>
#include "TMath.h"
#include <vector>
#include <utility>
#include <iostream>
#include <fstream>

void calculate_chi_squared_errors_PMTdist(char *filename1=NULL, char *filename2=NULL, char *col_idx =NULL) {

    // Open the WCSim files
    // inFile1 should be the file with varied params
    TFile *inFile1 = new TFile(filename1, "READ"); 
    if ( !inFile1->IsOpen() ){
      std::cout << "Error: could not open input file \"" << filename1 << "\"." <<std::endl; 
      
    }	
    // inFile2 should be the file with baseline params
    TFile *inFile2 = new TFile(filename2, "READ"); 
    if ( !inFile2->IsOpen() ){
      std::cout << "Error: could not open input file \"" << filename2 << "\"." <<std::endl; 
      
    }	

    // Get the trees
    TTree *t1 = (TTree*)inFile1->Get("simulation");
    int n1 = t1->GetEntries();
 
    TTree *t2 = (TTree*)inFile2->Get("simulation");
    int n2 = t2->GetEntries();

    // define variables for output file 
    double chi2 = 0;
    double chi2_lowt = 0;
    double chi2_hight = 0;
    double err_chi2 = 0;
    double err_chi2_lowt = 0;
    double err_chi2_hight = 0;
    int locations[3] = {3,4,5};
    int location=0;
    int colIdx = atoi(col_idx);
    float colAngle = 2.00;
    float scat = 0.75;
    float abs = 1.30;
    float refl = 0.90;
    // TODO grab collimator positions from file
    float colX = 3314.91;
    float colY=0;
    float colZ=-3352.01;

    // Get the varied water parameters from the name of the input file
    string f1 = filename1;
    if(strstr(filename1,"refl")){
	int pos1 = f1.find("refl_");
        int pos2 = f1.find(".root");
        string refl_val = f1.substr(pos1+5,pos2);
	refl = stof(refl_val);
    }
    if(strstr(filename1,"abwff")){
      int pos1 = f1.find("abwff_");
          int pos2 = f1.find(".root");
          string abs_val = f1.substr(pos1+6,pos2);
	abs = stof(abs_val);
    }
    if(strstr(filename1,"rayff")){
      int pos1 = f1.find("rayff_");
          int pos2 = f1.find(".root");
      string scat_val = f1.substr(pos1+6,pos2);
        scat = stof(scat_val);
    }
    printf("refl %f, abs %f, scat %f \n",refl,abs,scat);

    // Make the output file
    string outputFile = Form("chisquare_collimator_%d_dr.root",colIdx);
    printf("Opening output file %s",outputFile.c_str());
    ifstream f(outputFile.c_str());
    TFile *fout;
    TTree *outputTree;
    // Set up the output tree 
    // TODO move to separate function
    if (f.good()) {
        fout = new TFile(outputFile.c_str(), "UPDATE");
        outputTree = (TTree*)fout->Get("chisquareT");
        // Set the branch addresses we need to fill in the ntuple
        outputTree->SetBranchAddress("err_chi2",&err_chi2);
        outputTree->SetBranchAddress("err_chi2_lowt",&err_chi2_lowt);
        outputTree->SetBranchAddress("err_chi2_hight",&err_chi2_hight);
        outputTree->SetBranchAddress("chi2",&chi2);
        outputTree->SetBranchAddress("chi2_lowt",&chi2_lowt);
        outputTree->SetBranchAddress("chi2_hight",&chi2_hight);
        outputTree->SetBranchAddress("cylLoc",&location);
        outputTree->SetBranchAddress("colAngle",&colAngle);
        outputTree->SetBranchAddress("colIdx",&colIdx);
        outputTree->SetBranchAddress("refl",&refl);
        outputTree->SetBranchAddress("abs",&abs);
        outputTree->SetBranchAddress("scat",&scat);
    }
    else{
   	fout = new TFile(outputFile.c_str(),"CREATE");
   	outputTree = new TTree("chisquareT", "Chi square results");
   	// Set the branches we need to fill in the ntuple
   	outputTree->Branch("err_chi2",&err_chi2,"err_chi2/D");
   	outputTree->Branch("err_chi2_lowt",&err_chi2_lowt,"err_chi2_lowt/D");
   	outputTree->Branch("err_chi2_hight",&err_chi2_hight,"err_chi2_hight/D");
   	outputTree->Branch("chi2",&chi2,"chi2/D");
   	outputTree->Branch("chi2_lowt",&chi2_lowt,"chi2_lowt/D");
   	outputTree->Branch("chi2_hight",&chi2_hight,"chi2_hight/D");
   	outputTree->Branch("cylLoc",&location,"cylLoc/I");
   	outputTree->Branch("colAngle",&colAngle,"colAngle/F");
   	outputTree->Branch("colIdx",&colIdx,"colIdx/I");
   	outputTree->Branch("refl",&refl,"refl/F");
   	outputTree->Branch("abs",&abs,"abs/F");
	outputTree->Branch("scat",&scat,"scat/F");
    }


  
    int n_subsets = 10;
    int n1_per_subset = n1/n_subsets;
    int n2_per_subset = n2/n_subsets;

    int n = 950;
    // Define the histograms to be filled
    // TODO define dynamically
    TH1D *h1_all_t = new TH1D("h1_all_t","h1_all_t",n,0,n*10);
    TH1D *h1_low_t = new TH1D("h1_low_t","h1_all_t",n,0,n*10);
    TH1D *h1_high_t = new TH1D("h1_high_t","h1_all_t",n,0,n*10);
    TH1D *h2_all_t = new TH1D("h2_all_t","h2_all_t",n,0,n*10);
    TH1D *h2_low_t = new TH1D("h2_low_t","h2_all_t",n,0,n*10);
    TH1D *h2_high_t = new TH1D("h2_high_t","h2_all_t",n,0,n*10);
    // Histograms for subsets of events for error calculation
    TH1D *h1sub_all_t = new TH1D("h1sub_all_t","h1sub_all_t",n,0,n*10);
//            TH1D *h1sub_low_t = new TH1D("h1sub_low_t","h1sub_all_t",n,0,n*10);
//            TH1D *h1sub_high_t = new TH1D("h1sub_high_t","h1sub_all_t",n,0,n*10);
    TH1D *h2sub_all_t = new TH1D("h2sub_all_t","h2sub_all_t",n,0,n*10);
//            TH1D *h2sub_low_t = new TH1D("h2sub_low_t","h2sub_all_t",n,0,n*10);
//            TH1D *h2sub_high_t = new TH1D("h2sub_high_t","h2sub_all_t",n,0,n*10);

    for (int loc =0;loc<3;loc++){
        location=locations[loc];
        // Create a histogram of all of the events for the varied params
        // TODO draw dynamically
        t1->Draw(Form("sqrt(pow(pmtX-%f,2)+pow(pmtY-%f,2)+pow(pmtZ-%f,2))>>h1_all_t",colX,colY,colZ),Form("(cylLoc==%d)*digiCharge",locations[loc]),"goff");
        t1->Draw(Form("sqrt(pow(pmtX-%f,2)+pow(pmtY-%f,2)+pow(pmtZ-%f,2))>>h1_low_t",colX,colY,colZ),Form("(cylLoc==%d && digiTime<220)*digiCharge",locations[loc]),"goff");
        t1->Draw(Form("sqrt(pow(pmtX-%f,2)+pow(pmtY-%f,2)+pow(pmtZ-%f,2))>>h1_high_t",colX,colY,colZ),Form("(cylLoc==%d && digiTime>220)*digiCharge",locations[loc]),"goff");
        // Create m of all of the events for the baseline params
        t2->Draw(Form("sqrt(pow(pmtX-%f,2)+pow(pmtY-%f,2)+pow(pmtZ-%f,2))>>h2_all_t",colX,colY,colZ),Form("(cylLoc==%d)*digiCharge",locations[loc]),"goff");
        t2->Draw(Form("sqrt(pow(pmtX-%f,2)+pow(pmtY-%f,2)+pow(pmtZ-%f,2))>>h2_low_t",colX,colY,colZ),Form("(cylLoc==%d && digiTime<220)*digiCharge",locations[loc]),"goff");
        t2->Draw(Form("sqrt(pow(pmtX-%f,2)+pow(pmtY-%f,2)+pow(pmtZ-%f,2))>>h2_high_t",colX,colY,colZ),Form("(cylLoc==%d && digiTime>220)*digiCharge",locations[loc]),"goff");

        // Calculate chi2 for all instances
        //TODO plot or output res: "analysis of the residuals is often helpful in identifying the bins of histograms responsible for a significant overall value"
        double res[n];  
        // Chi2Test with options "WW CHI2/NDF P": comparison of weighted-weighted histograms, returns chi2/ndf, prints out results
        // https://arxiv.org/pdf/physics/0605123.pdf for details
        chi2 = h1_all_t->Chi2Test(h2_all_t,"WW CHI2/NDF P",res);
        chi2_lowt = h1_low_t->Chi2Test(h2_low_t,"WW CHI2/NDF P",res);
        chi2_hight = h1_high_t->Chi2Test(h2_high_t,"WW CHI2/NDF P",res); 
        
        // TODO Calculate values for error for each h1 histogram
        // Sum normalised chi square over x bins for each h1 subset histogram
        // Divide by ndof for each subset histogram
        // Calculate relative standard deviation (normalised) for each h1 histogram
        float var_chi2=0;
        float sum_chi2=0;
        
        for(int subset = 0; subset < n_subsets; subset++) {
            int first1 = subset*n1_per_subset;
            int first2 = subset*n2_per_subset;
            t1->Draw(Form("sqrt(pow(pmtX-%f,2)+pow(pmtY-%f,2)+pow(pmtZ-%f,2))>>h1sub_all_t",colX,colY,colZ),Form("(cylLoc==%d)*digiCharge",locations[loc]),"goff",n1_per_subset,first1);
//            t1->Draw("sqrt(pow(pmtX-colX,2)+pow(pmtY-colY,2)+pow(pmtZ-colZ,2)>>h1sub_low_t",Form("(cylLoc==%d && digiTime<220)*digiCharge",locations[loc]),"goff",n1_per_subset,first1);
//            t1->Draw("sqrt(pow(pmtX-colX,2)+pow(pmtY-colY,2)+pow(pmtZ-colZ,2)>>h1sub_high_t",Form("(cylLoc==%d && digiTime>220)*digiCharge",locations[loc]),"goff",n1_per_subset,first1);
            t2->Draw(Form("sqrt(pow(pmtX-%f,2)+pow(pmtY-%f,2)+pow(pmtZ-%f,2))>>h2sub_all_t",colX,colY,colZ),Form("(cylLoc==%d)*digiCharge",locations[loc]),"goff",n2_per_subset,first2);
//            t2->Draw("sqrt(pow(pmtX-colX,2)+pow(pmtY-colY,2)+pow(pmtZ-colZ,2)>>h2sub_low_t",Form("(cylLoc==%d && digiTime<220)*digiCharge",locations[loc]),"goff",n2_per_subset,first2);
//            t2->Draw("sqrt(pow(pmtX-colX,2)+pow(pmtY-colY,2)+pow(pmtZ-colZ,2)>>h2sub_high_t",Form("(cylLoc==%d && digiTime>220)*digiCharge",locations[loc]),"goff",n2_per_subset,first2);
//
            // TODO calculate chi2 for all instances
            float chi2sub = h1sub_all_t->Chi2Test(h2sub_all_t,"WW CHI2/NDF");
            var_chi2 += pow((chi2sub-chi2/n_subsets),2); // Celeste's method divides by mean chi square over bins but going to use deviation from total chi2 - TODO is this correct?
            sum_chi2 += chi2sub;
            h1sub_all_t->Reset();
            h2sub_all_t->Reset();
 
        } //end subsets

        float sigma_chi2 = sqrt(var_chi2/n_subsets);
        float mean_chi2 = sum_chi2/n_subsets;
          
        double relative_sigma = sigma_chi2/mean_chi2;
        err_chi2 = chi2*relative_sigma;


        outputTree->Fill();

    }

    fout->cd();
    outputTree->Write();
    delete outputTree;
    fout->Close(); 
} // END MACRO
