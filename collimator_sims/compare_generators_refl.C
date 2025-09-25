//:set tabtop=4 shiftwidth=4

#include <vector>

void compare_generators_refl(char const *filename, char const *filename2){

    TFile *f1 = new TFile(filename, "read");
    TTree *t1 = (TTree*)f1->Get("chisquareT");
    TFile *f2 = new TFile(filename2, "read");
    TTree *t2 = (TTree*)f2->Get("chisquareT");
	int n=62;

	// first collimator angle
	// plot with all times in different locs
	int n1 = t1->Draw("chi2:refl:err_chi2/4.","cylLoc==3 && scat>0.749 && scat<0.7501 && abs>1.299 && abs<1.301 && chi2<2000 && refl>0.7","goff"); 
    vector<double> xerrors(n1,0);
    TGraph *g1 = new TGraphErrors(n1,t1->GetV2(),t1->GetV1(),&xerrors[0],t1->GetV3()); 
	int n2 = t1->Draw("chi2:refl:err_chi2/4.","cylLoc==4 && scat>0.749 && scat<0.7501&& abs>1.299 && abs<1.301 && chi2<2000 && refl>0.7","goff"); 
    vector <double> xerrors2(n2,0);
    TGraph *g2 = new TGraphErrors(n2,t1->GetV2(),t1->GetV1(),&xerrors2[0],t1->GetV3()); 
	int n3 = t1->Draw("chi2:refl:err_chi2/4.","cylLoc==5 && scat>0.749 && scat<0.7501&& abs>1.299 && abs<1.301 && chi2<2000 && refl>0.7","goff"); 
    vector <double> xerrors3(n3,0);
    TGraph *g3 = new TGraphErrors(n3,t1->GetV2(),t1->GetV1(),&xerrors3[0],t1->GetV3()); 

	// plot with hit times <220 ns in different locs
	/*
	int n1lowt = t1->Draw("chi2_lowt:refl:err_chi2/4._lowt","cylLoc==3 && refl>0.899 && refl<0.901 && abs>1.299 && abs<1.301 && chi2<2000 && refl>0.7","goff"); 
    vector <double> xerrors1_lowt(n,0);
    TGraph *g1lowt = new TGraphErrors(n,t1->GetV2(),t1->GetV1(),&xerrors1_lowt[0],t1->GetV3()); 
	int n2lowt = t1->Draw("chi2_lowt:refl:err_chi2/4._lowt","cylLoc==4 && refl>0.899 && refl<0.901 && abs>1.299 && abs<1.301 && chi2<2000 && refl>0.7","goff"); 
    vector <double> xerrors2_lowt(n,0);
    TGraph *g2lowt = new TGraphErrors(n,t1->GetV2(),t1->GetV1(),&xerrors2_lowt[0],t1->GetV3()); 
	int n3lowt = t1->Draw("chi2_lowt:refl:err_chi2/4._lowt","cylLoc==5 && refl>0.899 && refl<0.901 && abs>1.299 && abs<1.301 && chi2<2000 && refl>0.7","goff"); 
    vector <double> xerrors3_lowt(n,0);
    TGraph *g3lowt = new TGraphErrors(n,t1->GetV2(),t1->GetV1(),&xerrors3_lowt[0],t1->GetV3()); 

	// plot with hit times >220 ns in different locs
	int n1hight = t1->Draw("chi2_hight:refl:err_chi2/4._hight","cylLoc==3 && refl>0.899 && refl<0.901 && abs>1.299 && abs<1.301 && chi2<2000 && refl>0.7","goff"); 
    vector <double> xerrors1_hight(n,0);
    TGraph *g1hight = new TGraphErrors(n,t1->GetV2(),t1->GetV1(),&xerrors1_hight[0],t1->GetV3()); 
	int n2hight = t1->Draw("chi2_hight:refl:err_chi2/4._hight","cylLoc==4 && refl>0.899 && refl<0.901 && abs>1.299 && abs<1.301 && chi2<2000 && refl>0.7","goff"); 
    vector <double> xerrors2_hight(n,0);
    TGraph *g2hight = new TGraphErrors(n,t1->GetV2(),t1->GetV1(),&xerrors2_hight[0],t1->GetV3()); 
	int n3hight = t1->Draw("chi2_hight:refl:err_chi2/4._hight","cylLoc==5 && refl>0.899 && refl<0.901 && abs>1.299 && abs<1.301 && chi2<2000 && refl>0.7","goff"); 
    vector <double> xerrors3_hight(n,0);
    TGraph *g3hight = new TGraphErrors(n,t1->GetV2(),t1->GetV1(),&xerrors3_hight[0],t1->GetV3()); 
	*/

	// second collimator angle
	// plot with all times in different locs
	int n1_2 = t2->Draw("chi2:refl:err_chi2/4.","cylLoc==3 && scat>0.749 && scat<0.7501&& abs>1.299 && abs<1.301 && chi2<2000 && refl>0.7","goff"); 
    vector <double> xerrors1_2(n1_2,0);
    TGraph *g1_2 = new TGraphErrors(n1_2,t2->GetV2(),t2->GetV1(),&xerrors1_2[0],t2->GetV3()); 
	int n2_2 = t2->Draw("chi2:refl:err_chi2/4.","cylLoc==4 && scat>0.749 && scat<0.7501&& abs>1.299 && abs<1.301 && chi2<2000 && refl>0.7","goff"); 
    vector <double> xerrors2_2(n2_2,0);
    TGraph *g2_2 = new TGraphErrors(n2_2,t2->GetV2(),t2->GetV1(),&xerrors2_2[0],t2->GetV3()); 
	int n3_2 = t2->Draw("chi2:refl:err_chi2/4.","cylLoc==5 && scat>0.749 && scat<0.7501&& abs>1.299 && abs<1.301 && chi2<2000 && refl>0.7","goff"); 
    vector <double> xerrors3_2(n3_2,0);
    TGraph *g3_2 = new TGraphErrors(n3_2,t2->GetV2(),t2->GetV1(),&xerrors3_2[0],t2->GetV3()); 

/*	// plot with hit times <220 ns in different locs
	int n1lowt_2 = t2->Draw("chi2_lowt:refl:err_chi2/4._lowt","cylLoc==3 && refl>0.899 && refl<0.901 && abs>1.299 && abs<1.301 && chi2<2000 && refl>0.7","goff"); 
    vector <double> xerrors1lowt_2(n,0);
    TGraph *g1lowt_2 = new TGraphErrors(n,t2->GetV2(),t2->GetV1(),&xerrors1lowt_2[0],t2->GetV3()); 
	int n2lowt_2 = t2->Draw("chi2_lowt:refl:err_chi2/4._lowt","cylLoc==4 && refl>0.899 && refl<0.901 && abs>1.299 && abs<1.301 && chi2<2000 && refl>0.7","goff"); 
    vector <double> xerrors2lowt_2(n,0);
    TGraph *g2lowt_2 = new TGraphErrors(n,t2->GetV2(),t2->GetV1(),&xerrors2lowt_2[0],t2->GetV3()); 
	int n3lowt_2 = t2->Draw("chi2_lowt:refl:err_chi2/4._lowt","cylLoc==5 && refl>0.899 && refl<0.901 && abs>1.299 && abs<1.301 && chi2<2000 && refl>0.7","goff"); 
    vector <double> xerrors3lowt_2(n,0);
    TGraph *g3lowt_2 = new TGraphErrors(n,t2->GetV2(),t2->GetV1(),&xerrors3lowt_2[0],t2->GetV3()); 

	// plot with hit times >220 ns in different locs
	int n1hight_2 = t2->Draw("chi2_hight:refl:err_chi2/4._hight","cylLoc==3 && refl>0.899 && refl<0.901 && abs>1.299 && abs<1.301 && chi2<2000 && refl>0.7","goff"); 
    vector <double> xerrors1hight_2(n,0);
    TGraph *g1hight_2 = new TGraphErrors(n,t2->GetV2(),t2->GetV1(),&xerrors1hight_2[0],t2->GetV3()); 
	int n2hight_2 = t2->Draw("chi2_hight:refl:err_chi2/4._hight","cylLoc==4 && refl>0.899 && refl<0.901 && abs>1.299 && abs<1.301 && chi2<2000 && refl>0.7","goff"); 
    vector <double> xerrors2hight_2(n,0);
    TGraph *g2hight_2 = new TGraphErrors(n,t2->GetV2(),t2->GetV1(),&xerrors2hight_2[0],t2->GetV3()); 
	int n3hight_2 = t2->Draw("chi2_hight:refl:err_chi2/4._hight","cylLoc==5 && refl>0.899 && refl<0.901 && abs>1.299 && abs<1.301 && chi2<2000 && refl>0.7","goff"); 
    vector <double> xerrors3hight_2(n,0);
    TGraph *g3hight_2 = new TGraphErrors(n,t2->GetV2(),t2->GetV1(),&xerrors3hight_2[0],t2->GetV3()); 
*/
    // Draw the graphs of the first collimator 

	g1->SetLineColor(kBlue+2);
    g2->SetLineColor(kRed+2);
    g3->SetLineColor(kGreen+2);
/*	g1lowt->SetLineColor(kBlue+2);
    g2lowt->SetLineColor(kRed+2);
    g3lowt->SetLineColor(kGreen+2);
	g1hight->SetLineColor(kBlue+2);
    g2hight->SetLineColor(kRed+2);
    g3hight->SetLineColor(kGreen+2);
*/
	g1->SetMarkerColor(kBlue+2);
    g2->SetMarkerColor(kRed+2);
    g3->SetMarkerColor(kGreen+2);
/*	g1lowt->SetMarkerColor(kBlue+2);
    g2lowt->SetMarkerColor(kRed+2);
    g3lowt->SetMarkerColor(kGreen+2);
	g1hight->SetMarkerColor(kBlue+2);
    g2hight->SetMarkerColor(kRed+2);
    g3hight->SetMarkerColor(kGreen+2);
*/

	g1->SetMarkerStyle(7);
    g2->SetMarkerStyle(7);
    g3->SetMarkerStyle(7);
/*	g1lowt->SetMarkerStyle(7);
    g2lowt->SetMarkerStyle(7);
    g3lowt->SetMarkerStyle(7);
	g1hight->SetMarkerStyle(7);
    g2hight->SetMarkerStyle(7);
    g3hight->SetMarkerStyle(7);
*/
	g1->SetMarkerSize(3);
    g2->SetMarkerSize(3);
    g3->SetMarkerSize(3);
/*	g1lowt->SetMarkerSize(3);
    g2lowt->SetMarkerSize(3);
    g3lowt->SetMarkerSize(3);
	g1hight->SetMarkerSize(3);
    g2hight->SetMarkerSize(3);
    g3hight->SetMarkerSize(3);
*/
	g1_2->SetLineColor(kBlue+2);
    g2_2->SetLineColor(kRed+2);
    g3_2->SetLineColor(kGreen+2);
/*
	g1lowt_2->SetLineColor(kBlue+2);
    g2lowt_2->SetLineColor(kRed+2);
    g3lowt_2->SetLineColor(kGreen+2);
	g1hight_2->SetLineColor(kBlue+2);
    g2hight_2->SetLineColor(kRed+2);
    g3hight_2->SetLineColor(kGreen+2);
*/
	g1_2->SetMarkerColor(kBlue+2);
    g2_2->SetMarkerColor(kRed+2);
    g3_2->SetMarkerColor(kGreen+2);
/*
	g1lowt_2->SetMarkerColor(kBlue+2);
    g2lowt_2->SetMarkerColor(kRed+2);
    g3lowt_2->SetMarkerColor(kGreen+2);
	g1hight_2->SetMarkerColor(kBlue+2);
    g2hight_2->SetMarkerColor(kRed+2);
    g3hight_2->SetMarkerColor(kGreen+2);
*/
	g1_2->SetMarkerStyle(7);
    g2_2->SetMarkerStyle(7);
    g3_2->SetMarkerStyle(7);
/*
	g1lowt_2->SetMarkerStyle(7);
    g2lowt_2->SetMarkerStyle(7);
    g3lowt_2->SetMarkerStyle(7);
	g1hight_2->SetMarkerStyle(7);
    g2hight_2->SetMarkerStyle(7);
    g3hight_2->SetMarkerStyle(7);
*/
	g1_2->SetMarkerSize(3);
    g2_2->SetMarkerSize(3);
    g3_2->SetMarkerSize(3);
/*
	g1lowt_2->SetMarkerSize(3);
    g2lowt_2->SetMarkerSize(3);
    g3lowt_2->SetMarkerSize(3);
	g1hight_2->SetMarkerSize(3);
    g2hight_2->SetMarkerSize(3);
    g3hight_2->SetMarkerSize(3);
*/

    TCanvas *c1 = new TCanvas();
	TMultiGraph *mg1 = new TMultiGraph();
	mg1->Add(g1,"p");
	mg1->Add(g2,"p");
	mg1->Add(g3,"p");
	TLegend *leg = new TLegend(0.55,0.65,0.88,0.85);
	leg->AddEntry(g1,"bottom, all hits","lp");
	leg->AddEntry(g2,"barrel, all hits","lp");
	leg->AddEntry(g3,"top, all hits","lp");
	mg1->SetTitle("; Reflectivity; Chi square/ndof");
	mg1->Draw("a");
	leg->Draw();
	c1->SaveAs("collimator_dr_refl.png");
	c1->SaveAs("collimator_dr_refl.C");	
/*	
    TCanvas *c2 = new TCanvas();
	TMultiGraph *mg2 = new TMultiGraph();
    mg2->Add(g1lowt,"p");
	mg2->Add(g2lowt,"p");
	mg2->Add(g3lowt,"p");
	TLegend *leg2 = new TLegend(0.55,0.65,0.88,0.85);
	leg2->AddEntry(g1lowt,"bottom, <220 ns", "lp");
	leg2->AddEntry(g2lowt,"barrel, <220 ns", "lp");
	leg2->AddEntry(g3lowt,"top, <220 ns", "lp");
	mg2->SetTitle("; Reflectivity; Chi square/ndof");
	mg2->Draw("a");
	leg2->Draw();
	c2->SaveAs("collimator_newgen_scat_lowt.png");
	c2->SaveAs("collimator_newgen_scat_lowt.C");	
	
    TCanvas *c3 = new TCanvas();
	TMultiGraph *mg3 = new TMultiGraph();
	mg3->Add(g1hight,"p");
	mg3->Add(g2hight,"p");
	mg3->Add(g3hight,"p");
	TLegend *leg3 = new TLegend(0.55,0.65,0.88,0.85);
	leg3->AddEntry(g1hight,"bottom, >220 ns", "lp");
	leg3->AddEntry(g2hight,"barrel, >220 ns", "lp");
	leg3->AddEntry(g3hight,"top, >220 ns", "lp");
	mg3->SetTitle("; Reflectivity; Chi square/ndof");
	mg3->Draw("a");
	leg3->Draw();
	c3->SaveAs("collimator_newgen_scat_hight.png");
	c3->SaveAs("collimator_newgen_scat_hight.C");	
*/
// now the graphs of the second collimator	
    TCanvas *c1_2 = new TCanvas();
	TMultiGraph *mg1_2 = new TMultiGraph();
	mg1_2->Add(g1_2,"p");
	mg1_2->Add(g2_2,"p");
	mg1_2->Add(g3_2,"p");
	TLegend *leg_2 = new TLegend(0.55,0.65,0.88,0.85);
	leg_2->AddEntry(g1_2,"bottom, all hits","lp");
	leg_2->AddEntry(g2_2,"barrel, all hits","lp");
	leg_2->AddEntry(g3_2,"top, all hits","lp");
	mg1_2->SetTitle("; Reflectivity; Chi square/ndof");
	mg1_2->Draw("a");
	leg_2->Draw();
	c1_2->SaveAs("collimator_no_dr_refl.png");
	c1_2->SaveAs("collimator_no_dr_refl.C");	
    
/*	
    TCanvas *c2_2 = new TCanvas();
	TMultiGraph *mg2_2 = new TMultiGraph();
    mg2_2->Add(g1lowt_2,"p");
	mg2_2->Add(g2lowt_2,"p");
	mg2_2->Add(g3lowt_2,"p");
	TLegend *leg2_2 = new TLegend(0.55,0.65,0.88,0.85);
	leg2_2->AddEntry(g1lowt_2,"bottom, <220 ns", "lp");
	leg2_2->AddEntry(g2lowt_2,"barrel, <220 ns", "lp");
	leg2_2->AddEntry(g3lowt_2,"top, <220 ns", "lp");
	mg2_2->SetTitle("; Reflectivity; Chi square/ndof");
	mg2_2->Draw("a");
	leg2_2->Draw();
	c2_2->SaveAs("collimator_oldgen_scat_lowt.png");
	c2_2->SaveAs("collimator_oldgen_scat_lowt.C");	
	
   TCanvas *c3_2 = new TCanvas();
	TMultiGraph *mg3_2 = new TMultiGraph();
	mg3_2->Add(g1hight_2,"p");
	mg3_2->Add(g2hight_2,"p");
	mg3_2->Add(g3hight_2,"p");
	TLegend *leg3_2 = new TLegend(0.55,0.65,0.88,0.85);
	leg3_2->AddEntry(g1hight_2,"bottom, >220 ns", "lp");
	leg3_2->AddEntry(g2hight_2,"barrel, >220 ns", "lp");
	leg3_2->AddEntry(g3hight_2,"top, >220 ns", "lp");
	mg3_2->SetTitle("; Reflectivity; Chi square/ndof");
	mg3_2->Draw("a");
	leg3_2->Draw();
	c3_2->SaveAs("collimator_oldgen_scat_hight.png");
	c3_2->SaveAs("collimator_oldgen_scat_hight.C");	
*/


    	TCanvas *c2 = new TCanvas();
	TMultiGraph *mg2 = new TMultiGraph();
	mg2->Add(g2,"p");
        g2_2->SetLineColor(kBlue);
        g2_2->SetMarkerColor(kBlue);
	mg2->Add(g2_2,"p");
	TLegend *leg2 = new TLegend(0.55,0.65,0.88,0.85);
	leg2->AddEntry(g2,"barrel, with dark noise","lp");
	leg2->AddEntry(g2_2,"barrel, no dark noise","lp");
	mg2->SetTitle("; Reflectivity; Chi square/ndof");
	mg2->Draw("a");
	leg2->Draw();
	c2->SaveAs("collimator_compare_refl.png");
	c2->SaveAs("collimator_compare_refl.C");	

}
