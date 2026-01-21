#include <stdio.h>     
#include <stdlib.h>
#include "TMath.h"
#include <vector>
#include <utility>
#include <iostream>
#include <fstream>

// #include <libgen.h>

void calculate_chi_squared_errors_colBarrel(char *filename1=NULL, char *filename2=NULL, char *col_idx =NULL) {

 // Open the WCSim file
  TFile *inFile1 = new TFile(filename1, "READ"); 
  if ( !inFile1->IsOpen() ){
    std::cout << "Error: could not open input file \"" << filename1 << "\"." <<std::endl; 
	
  }	
  TFile *inFile2 = new TFile(filename2, "READ"); 
  if ( !inFile2->IsOpen() ){
    std::cout << "Error: could not open input file \"" << filename2 << "\"." <<std::endl; 
	
  }	
  
  TTree *inTree1 = (TTree*)inFile1->Get("Events");

  Long64_t nentries1 = inTree1->GetEntries();

  std::cerr << "Entries " << nentries1 << std::endl;
  TLeaf *eventid = inTree1->GetLeaf("eventId");
  eventid->GetBranch()->GetEntry(nentries1-1);
  int numevents = eventid->GetValue();


  int num_OD_PMT = 0;
  for (Long64_t i=0; i < nentries1; i++) {
    TLeaf *tubeid = inTree1->GetLeaf("tubeId");
    tubeid->GetBranch()->GetEntry(i);
    int temp_num_OD_PMT = tubeid->GetValue();
    if (temp_num_OD_PMT > num_OD_PMT) num_OD_PMT = temp_num_OD_PMT;
  }  

  TTree *inTree2 = (TTree*)inFile2->Get("Events");

  Long64_t nentries2 = inTree2->GetEntries();

  std::cerr << "Entries " << nentries2 << std::endl;

  int num_elements = num_OD_PMT;
  int default_value = 0;

    double total_chi_squared = 0;
    double total_chi_squared_lowt = 0;
    double total_chi_squared_hight = 0;
    double error_chi_squared = 0;
    double error_chi_squared_lowt = 0;
    double error_chi_squared_hight = 0;
    int locations[3] = {3,4,5};
    int location;
    int colIdx = atoi(col_idx);
    float colAngle = 2.00;
  float scat = 0.75;
  float abs = 1.30;
  float refl = 0.90;
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
    string outputFile = Form("chisquare_collimator_%d.root",colIdx);
    printf("Opening output file %s",outputFile.c_str());
    ifstream f(outputFile.c_str());
    TFile *fout;
    TTree *outputTree;
    if (f.good()) {
	fout = new TFile(outputFile.c_str(), "UPDATE");
        outputTree = (TTree*)fout->Get("chisquareT");
	// Set the branch addresses we need to fill in the ntuple
	outputTree->SetBranchAddress("err_chi2",&error_chi_squared);
	outputTree->SetBranchAddress("err_chi2_lowt",&error_chi_squared_lowt);
	outputTree->SetBranchAddress("err_chi2_hight",&error_chi_squared_hight);
	outputTree->SetBranchAddress("chi2",&total_chi_squared);
	outputTree->SetBranchAddress("chi2_lowt",&total_chi_squared_lowt);
	outputTree->SetBranchAddress("chi2_hight",&total_chi_squared_hight);
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
	outputTree->Branch("err_chi2",&error_chi_squared,"err_chi2/D");
	outputTree->Branch("err_chi2_lowt",&error_chi_squared_lowt,"err_chi2_lowt/D");
	outputTree->Branch("err_chi2_hight",&error_chi_squared_hight,"err_chi2_hight/D");
	outputTree->Branch("chi2",&total_chi_squared,"chi2/D");
	outputTree->Branch("chi2_lowt",&total_chi_squared_lowt,"chi2_lowt/D");
	outputTree->Branch("chi2_hight",&total_chi_squared_hight,"chi2_hight/D");
	outputTree->Branch("cylLoc",&location,"cylLoc/I");
	outputTree->Branch("colAngle",&colAngle,"colAngle/F");
	outputTree->Branch("colIdx",&colIdx,"colIdx/I");
	outputTree->Branch("refl",&refl,"refl/F");
	outputTree->Branch("abs",&abs,"abs/F");
	outputTree->Branch("scat",&scat,"scat/F");
    }


  
  int n1 = inTree1->Draw("eventId:tubeId:trueTime:recTime:trueNumPhotons:recCharge:cylLoc:pmtX:pmtY:pmtZ","","goff");
  int n2 = inTree2->Draw("eventId:tubeId:trueTime:recTime:trueNumPhotons:recCharge:cylLoc:pmtX:pmtY:pmtZ","","goff");

  int n_cycles = 10;
  int n1_per_cycle = n1/n_cycles;
  int n2_per_cycle = n2/n_cycles;
  
  for (int loc =0;loc<3;loc++){
	location = locations[loc];
	  std::vector<double> total_charge_vec_1(num_elements,default_value);
	  std::vector<double> total_charge_vec_2(num_elements,default_value);
	  std::vector<double> total_charge_lowt_vec_1(num_elements,default_value);
	  std::vector<double> total_charge_lowt_vec_2(num_elements,default_value);
	  std::vector<double> total_charge_hight_vec_1(num_elements,default_value);
	  std::vector<double> total_charge_hight_vec_2(num_elements,default_value);
	  std::vector<double> chi2values;
	  std::vector<double> chi2values_lowt;
	  std::vector<double> chi2values_hight;
	  double sum_chi2 = 0;
	  double sum_chi2_lowt = 0;
	  double sum_chi2_hight = 0;
	  double ndof = 0;
	  double ndof_lowt = 0;
	  double ndof_hight = 0;

	  for(long unsigned int cycle = 0; cycle < n_cycles; cycle++) {

		std::vector<double> charge_vec_1(num_elements,default_value);
		std::vector<double> charge_vec_2(num_elements,default_value);
		std::vector<double> charge_lowt_vec_1(num_elements,default_value);
		std::vector<double> charge_lowt_vec_2(num_elements,default_value);
		std::vector<double> charge_hight_vec_1(num_elements,default_value);
		std::vector<double> charge_hight_vec_2(num_elements,default_value);
	    

	    for (Long64_t i=(cycle*n1_per_cycle); i < (cycle+1)*n1_per_cycle; i++) {
	      //
	      inTree1->GetEntry(i);
	      TLeaf *_cylLoc = inTree1->GetLeaf("cylLoc");
	      _cylLoc->GetBranch()->GetEntry(i);
	      int cylLoc = _cylLoc->GetValue();
	      TLeaf *_tubeId = inTree1->GetLeaf("tubeId");
	      _tubeId->GetBranch()->GetEntry(i);
	      int tubeId = _tubeId->GetValue();
	      TLeaf *_recCharge = inTree1->GetLeaf("recCharge");
	      _recCharge->GetBranch()->GetEntry(i);
	      double recCharge = _recCharge->GetValue();
	      TLeaf *_pmtX = inTree1->GetLeaf("pmtX");
	      _pmtX->GetBranch()->GetEntry(i);
	      double pmtX = _pmtX->GetValue();
	      TLeaf *_pmtY = inTree1->GetLeaf("pmtY");
	      _pmtY->GetBranch()->GetEntry(i);
	      double pmtY = _pmtY->GetValue();
	      TLeaf *_pmtZ = inTree1->GetLeaf("pmtZ");
	      _pmtZ->GetBranch()->GetEntry(i);
	      double pmtZ = _pmtZ->GetValue();
	      TLeaf *_recTime = inTree1->GetLeaf("recTime");
	      _recTime->GetBranch()->GetEntry(i);
	      double recTime = _recTime->GetValue();
	      if (i%(n1/10) == 0) std::cerr << i << " out of " << n1 << " entries" << std::endl;

	      if (cylLoc==locations[loc]) {
		  charge_vec_1[tubeId-1] += recCharge;
		  total_charge_vec_1[tubeId-1] += recCharge;
	      }
	      
		if (cylLoc==locations[loc] && recTime<220){
		  charge_lowt_vec_1[tubeId-1] += recCharge;
		  total_charge_lowt_vec_1[tubeId-1] += recCharge;
		}
		if (cylLoc==locations[loc] && recTime>220){
		  charge_hight_vec_1[tubeId-1] += recCharge;
		  total_charge_hight_vec_1[tubeId-1] += recCharge;
		}
		
	    }



	    for (Long64_t i=(cycle*n2_per_cycle); i < (cycle+1)*n2_per_cycle; i++) {
	      //
	      inTree2->GetEntry(i);
	      TLeaf *_cylLoc = inTree2->GetLeaf("cylLoc");
	      _cylLoc->GetBranch()->GetEntry(i);
	      int cylLoc = _cylLoc->GetValue();
	      TLeaf *_tubeId = inTree2->GetLeaf("tubeId");
	      _tubeId->GetBranch()->GetEntry(i);
	      int tubeId = _tubeId->GetValue();
	      TLeaf *_recCharge = inTree2->GetLeaf("recCharge");
	      _recCharge->GetBranch()->GetEntry(i);
	      double recCharge = _recCharge->GetValue();
	      TLeaf *_pmtX = inTree2->GetLeaf("pmtX");
	      _pmtX->GetBranch()->GetEntry(i);
	      double pmtX = _pmtX->GetValue();
	      TLeaf *_pmtY = inTree2->GetLeaf("pmtY");
	      _pmtY->GetBranch()->GetEntry(i);
	      double pmtY = _pmtY->GetValue();
	      TLeaf *_pmtZ = inTree2->GetLeaf("pmtZ");
	      _pmtZ->GetBranch()->GetEntry(i);
	      double pmtZ = _pmtZ->GetValue();
	      TLeaf *_recTime = inTree2->GetLeaf("recTime");
	      _recTime->GetBranch()->GetEntry(i);
	      double recTime = _recTime->GetValue();

	      if (i%(n2/10) == 0) std::cerr << i << " out of " << n2 << " entries" << std::endl;

	      if (cylLoc==locations[loc]) {
		  charge_vec_2[tubeId-1] += recCharge;
		  total_charge_vec_2[tubeId-1] += recCharge;
	      }
		if (cylLoc==locations[loc] && recTime<220){
		  charge_lowt_vec_2[tubeId-1] += recCharge;
		  total_charge_lowt_vec_2[tubeId-1] += recCharge;
		}
		if (cylLoc==locations[loc] && recTime>220){
		  charge_hight_vec_2[tubeId-1] += recCharge;
		  total_charge_hight_vec_2[tubeId-1] += recCharge;
		}
	    }

	    ndof =  total_charge_vec_1.size() - std::count(total_charge_vec_1.begin(), total_charge_vec_1.end(), 0 ) - 1;
	    ndof_lowt = total_charge_lowt_vec_1.size() - std::count(total_charge_lowt_vec_1.begin(), total_charge_lowt_vec_1.end(), 0 ) - 1;
	    ndof_hight = total_charge_hight_vec_1.size() - std::count(total_charge_hight_vec_1.begin(), total_charge_hight_vec_1.end(), 0 ) - 1;

	    // calculate values for error for all hit times
	    double chi_squared = 0;

	    for (int i = 0; i < charge_vec_1.size(); i++) {
	      double observed = charge_vec_1[i];
	      double expected = charge_vec_2[i];
	      if (observed > 0 && expected > 0) {
		double chi_i = pow(observed-expected,2.0) / expected;
		chi_squared += chi_i;
	      }
	    }
	   
	    printf("chi2 %f \n",chi_squared);
	    chi_squared /= ndof;
	    printf("chi2/ndof %f \n",chi_squared);
	    sum_chi2 += chi_squared;
	    chi2values.push_back(chi_squared);

	    // calculate values for error for hit times < 220
	    double chi_squared_lowt = 0;

	    for (int i = 0; i < charge_lowt_vec_1.size(); i++) {
	      double observed = charge_lowt_vec_1[i];
	      double expected = charge_lowt_vec_2[i];
	      if (observed > 0 && expected > 0) {
		double chi_i = pow(observed-expected,2.0) / expected;
		chi_squared_lowt += chi_i;
	      }
	    }
	    
	    chi_squared_lowt /= ndof_lowt;

	    sum_chi2_lowt += chi_squared_lowt;
	    chi2values_lowt.push_back(chi_squared_lowt);

	    // calculate values for error for hit times > 220
	    double chi_squared_hight = 0;

	    for (int i = 0; i < charge_hight_vec_1.size(); i++) {
	      double observed = charge_hight_vec_1[i];
	      double expected = charge_hight_vec_2[i];
	      if (observed > 0 && expected > 0) {
		double chi_i = pow(observed-expected,2.0) / expected;
		chi_squared_hight += chi_i;
	      }
	    }
	    
	    chi_squared_hight /= ndof_hight;

	    sum_chi2_hight += chi_squared_hight;
	    chi2values_hight.push_back(chi_squared_hight);
	  }

	  // calculate the error for all hit times
	  double mean_chi2 = sum_chi2/chi2values.size();
	  std::cerr << "mean " << mean_chi2 << std::endl;
	  double var_chi2 = 0;
	  double sigma_chi2 = -9999;

	  for (int i = 0; i<chi2values.size(); i++) {
	    std::cerr << "chi 2 value for " << i << ", " << chi2values.at(i) << ", var " << pow((chi2values.at(i)-mean_chi2),2) << std::endl;
	    var_chi2 += pow((chi2values.at(i)-mean_chi2),2);
	  }

	  sigma_chi2 = sqrt(var_chi2/n_cycles);

	  std::cerr << "Std dev: " << sigma_chi2 << std::endl;
	  double relative_sigma = sigma_chi2/mean_chi2;

	  // calculate the error for hit times < 220
	  double mean_chi2_lowt = sum_chi2_lowt/chi2values_lowt.size();
	  std::cerr << "mean < 220 ns" << mean_chi2_lowt << std::endl;
	  double var_chi2_lowt = 0;
	  double sigma_chi2_lowt = -9999;

	  for (int i = 0; i<chi2values_lowt.size(); i++) {
	    std::cerr << "chi 2 value < 220 ns for " << i << ", " << chi2values_lowt.at(i) << ", var " << pow((chi2values_lowt.at(i)-mean_chi2_lowt),2) << std::endl;
	    var_chi2_lowt += pow((chi2values_lowt.at(i)-mean_chi2_lowt),2);
	  }

	  sigma_chi2_lowt = sqrt(var_chi2_lowt/n_cycles);

	  std::cerr << "Std dev < 220 ns: " << sigma_chi2_lowt << std::endl;
	  double relative_sigma_lowt = sigma_chi2_lowt/mean_chi2_lowt;

	  // calculate the error for hit times > 220
	  double mean_chi2_hight = sum_chi2_hight/chi2values_hight.size();
	  std::cerr << "mean > 220 ns" << mean_chi2_hight << std::endl;
	  double var_chi2_hight = 0;
	  double sigma_chi2_hight = -9999;

	  for (int i = 0; i<chi2values_hight.size(); i++) {
	    std::cerr << "chi 2 value > 220 ns for " << i << ", " << chi2values_hight.at(i) << ", var " << pow((chi2values_hight.at(i)-mean_chi2_hight),2) << std::endl;
	    var_chi2_hight += pow((chi2values_hight.at(i)-mean_chi2_hight),2);
	  }

	  sigma_chi2_hight = sqrt(var_chi2_hight/n_cycles);

	  std::cerr << "Std dev > 220 ns: " << sigma_chi2_hight << std::endl;
	  double relative_sigma_hight = sigma_chi2_hight/mean_chi2_hight;
	  

	  // calculate chi square and error for all hit times
	  total_chi_squared = 0.;

	  for (int i = 0; i < total_charge_vec_1.size(); i++) {
	    double observed = total_charge_vec_1[i];
	    double expected = total_charge_vec_2[i];
	    if (observed > 0 && expected > 0) {
	      double chi_i = pow((observed-expected),2.0) / expected;
	      //                  std::cerr << "chi_squred " << total_chi_squared << ", chi_i " << chi_i << ", expected " << expected << ", observed " << observed << std::endl;
	      total_chi_squared += chi_i;
	    }
	  }

	  total_chi_squared /= ndof;

	  error_chi_squared = total_chi_squared*relative_sigma;

	  std::cerr << "CHI2 " << total_chi_squared << ", error " << error_chi_squared << std::endl;

	  // calculate chi square and error for hit times < 220 ns
	  total_chi_squared_lowt = 0.;

	  for (int i = 0; i < total_charge_lowt_vec_1.size(); i++) {
	    double observed = total_charge_lowt_vec_1[i];
	    double expected = total_charge_lowt_vec_2[i];
	    if (observed > 0 && expected > 0) {
	      double chi_i = pow((observed-expected),2.0) / expected;
	      //                  std::cerr << "chi_squred " << total_chi_squared << ", chi_i " << chi_i << ", expected " << expected << ", observed " << observed << std::endl;
	      total_chi_squared_lowt += chi_i;
	    }
	  }
	  total_chi_squared_lowt /= ndof_lowt;

	  error_chi_squared_lowt = total_chi_squared_lowt*relative_sigma_lowt;

	  std::cerr << "CHI2<220 ns " << total_chi_squared_lowt << ", error < 220 ns " << error_chi_squared_lowt << std::endl;
	  
	  // calculate chi square and error for hit times > 220 ns
	  total_chi_squared_hight = 0.;

	  for (int i = 0; i < total_charge_hight_vec_1.size(); i++) {
	    double observed = total_charge_hight_vec_1[i];
	    double expected = total_charge_hight_vec_2[i];
	    if (observed > 0 && expected > 0) {
	      double chi_i = pow((observed-expected),2.0) / expected;
	      //                  std::cerr << "chi_squred " << total_chi_squared << ", chi_i " << chi_i << ", expected " << expected << ", observed " << observed << std::endl;
	      total_chi_squared_hight += chi_i;
	    }
	  }

	  total_chi_squared_hight /= ndof_hight;

	  error_chi_squared_hight = total_chi_squared_hight*relative_sigma_hight;

	  std::cerr << "CHI2>220 ns " << total_chi_squared_hight << ", error > 220 ns " << error_chi_squared_hight << std::endl;


	  outputTree->Fill();

  }
  	fout->cd();
  	outputTree->Write();
	delete outputTree;
	fout->Close(); 
} // END MACRO
