#ifdef __CLING__
#pragma cling optimize(0)
#endif
void collimator_compare_gen_abs()
{
//=========Macro generated from canvas: c1_n3/c1_n3
//=========  (Wed Jan  7 15:39:39 2026) by ROOT version 6.26/04
   TCanvas *c1_n3 = new TCanvas("c1_n3", "c1_n3",70,64,700,500);
   c1_n3->Range(0.8409375,-0.1237451,1.824063,1.113706);
   c1_n3->SetFillColor(0);
   c1_n3->SetBorderMode(0);
   c1_n3->SetBorderSize(2);
   c1_n3->SetFrameBorderMode(0);
   c1_n3->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle("; Absorption; Chi square/ndof");
   
   Double_t Graph_fx1009[10] = {
   0.975,
   1.105,
   1.235,
   1.261,
   1.287,
   1.326,
   1.43,
   1.56,
   1.69,
   1.3};
   Double_t Graph_fy1009[10] = {
   0.694455,
   0.694455,
   0.694455,
   0.694455,
   0.694455,
   0.694455,
   0.694455,
   0.694455,
   0.694455,
   0};
   Double_t Graph_fex1009[10] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1009[10] = {
   0.1739016,
   0.1739016,
   0.1739016,
   0.1739016,
   0.1739016,
   0.1739016,
   0.1739016,
   0.1739016,
   0.1739016,
   -nan};
   TGraphErrors *gre = new TGraphErrors(10,Graph_fx1009,Graph_fy1009,Graph_fex1009,Graph_fey1009);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#990000");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#990000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(3);
   
   TH1F *Graph_Graph_Graph_Graph100210071009 = new TH1F("Graph_Graph_Graph_Graph100210071009","Graph",100,0.9035,1.7615);
   Graph_Graph_Graph_Graph100210071009->SetMinimum(0);
   Graph_Graph_Graph_Graph100210071009->SetMaximum(0.9551923);
   Graph_Graph_Graph_Graph100210071009->SetDirectory(0);
   Graph_Graph_Graph_Graph100210071009->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph_Graph100210071009->SetLineColor(ci);
   Graph_Graph_Graph_Graph100210071009->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph100210071009->GetXaxis()->SetTitleOffset(1);
   Graph_Graph_Graph_Graph100210071009->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph100210071009->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph100210071009->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph100210071009->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph100210071009->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph_Graph100210071009->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph_Graph100210071009);
   
   multigraph->Add(gre,"p");
   
   Double_t Graph_fx1010[10] = {
   0.975,
   1.105,
   1.235,
   1.261,
   1.287,
   1.326,
   1.43,
   1.56,
   1.69,
   1.3};
   Double_t Graph_fy1010[10] = {
   0.7532112,
   0.7532112,
   0.7532112,
   0.7532112,
   0.7532112,
   0.7532112,
   0.7532112,
   0.7532112,
   0.7532112,
   0};
   Double_t Graph_fex1010[10] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1010[10] = {
   0.1896089,
   0.1896089,
   0.1896089,
   0.1896089,
   0.1896089,
   0.1896089,
   0.1896089,
   0.1896089,
   0.1896089,
   -nan};
   gre = new TGraphErrors(10,Graph_fx1010,Graph_fy1010,Graph_fex1010,Graph_fey1010);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(3);
   
   TH1F *Graph_Graph_Graph_Graph100510081010 = new TH1F("Graph_Graph_Graph_Graph100510081010","Graph",100,0.9035,1.7615);
   Graph_Graph_Graph_Graph100510081010->SetMinimum(0);
   Graph_Graph_Graph_Graph100510081010->SetMaximum(1.037102);
   Graph_Graph_Graph_Graph100510081010->SetDirectory(0);
   Graph_Graph_Graph_Graph100510081010->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph_Graph100510081010->SetLineColor(ci);
   Graph_Graph_Graph_Graph100510081010->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph100510081010->GetXaxis()->SetTitleOffset(1);
   Graph_Graph_Graph_Graph100510081010->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph100510081010->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph100510081010->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph_Graph100510081010->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph_Graph100510081010->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph_Graph100510081010->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph_Graph100510081010);
   
   multigraph->Add(gre,"p");
   multigraph->Draw("a");
   multigraph->GetXaxis()->SetLimits(0.93925, 1.72575);
   multigraph->GetXaxis()->SetTitle(" Absorption");
   multigraph->GetXaxis()->SetLabelFont(42);
   multigraph->GetXaxis()->SetTitleOffset(1);
   multigraph->GetXaxis()->SetTitleFont(42);
   multigraph->GetYaxis()->SetTitle(" Chi square/ndof");
   multigraph->GetYaxis()->SetLabelFont(42);
   multigraph->GetYaxis()->SetTitleFont(42);
   
   TLegend *leg = new TLegend(0.4899713,0.1932773,0.8209169,0.3928571,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph","collimator 10","lp");

   ci = TColor::GetColor("#990000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#990000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(3);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","collimator 13","lp");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#0000ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(3);
   entry->SetTextFont(42);
   leg->Draw();
   c1_n3->Modified();
   c1_n3->cd();
   c1_n3->SetSelected(c1_n3);
}
