void collimator_compare_gen_scat()
{
//=========Macro generated from canvas: c1_n3/c1_n3
//=========  (Tue Sep 26 19:22:14 2023) by ROOT version 6.20/04
   TCanvas *c1_n3 = new TCanvas("c1_n3", "c1_n3",10,47,700,500);
   c1_n3->Range(0.5742187,2.908475,1.038281,22.91815);
   c1_n3->SetFillColor(0);
   c1_n3->SetBorderMode(0);
   c1_n3->SetBorderSize(2);
   c1_n3->SetFrameBorderMode(0);
   c1_n3->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle("; Scattering; Chi square/ndof");
   
   Double_t Graph_fx1007[9] = {
   0.6375,
   0.7125,
   0.7275,
   0.7425,
   0.765,
   0.78,
   0.825,
   0.975,
   0.9};
   Double_t Graph_fy1007[9] = {
   17.26188,
   9.292148,
   8.998222,
   7.632745,
   7.827375,
   7.086635,
   7.60275,
   12.13103,
   8.839494};
   Double_t Graph_fex1007[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1007[9] = {
   2.927682,
   1.878068,
   1.81292,
   1.556615,
   1.55665,
   1.449568,
   1.460729,
   1.816521,
   1.532772};
   TGraphErrors *gre = new TGraphErrors(9,Graph_fx1007,Graph_fy1007,Graph_fex1007,Graph_fey1007);
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
   
   TH1F *Graph_Graph_Graph10021007 = new TH1F("Graph_Graph_Graph10021007","Graph",100,0.60375,1.00875);
   Graph_Graph_Graph10021007->SetMinimum(4.181818);
   Graph_Graph_Graph10021007->SetMaximum(21.64481);
   Graph_Graph_Graph10021007->SetDirectory(0);
   Graph_Graph_Graph10021007->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph10021007->SetLineColor(ci);
   Graph_Graph_Graph10021007->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph10021007->GetXaxis()->SetTitleOffset(1);
   Graph_Graph_Graph10021007->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph10021007->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph10021007->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph10021007->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph10021007->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph10021007->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph10021007);
   
   multigraph->Add(gre,"p");
   
   Double_t Graph_fx1008[9] = {
   0.6375,
   0.7125,
   0.7275,
   0.7425,
   0.765,
   0.78,
   0.825,
   0.975,
   0.9};
   Double_t Graph_fy1008[9] = {
   17.26188,
   9.292148,
   8.998222,
   7.632745,
   7.827375,
   7.086635,
   7.60275,
   12.13103,
   8.839494};
   Double_t Graph_fex1008[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1008[9] = {
   2.927682,
   1.878068,
   1.81292,
   1.556615,
   1.55665,
   1.449568,
   1.460729,
   1.816521,
   1.532772};
   gre = new TGraphErrors(9,Graph_fx1008,Graph_fy1008,Graph_fex1008,Graph_fey1008);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(3);
   
   TH1F *Graph_Graph_Graph10051008 = new TH1F("Graph_Graph_Graph10051008","Graph",100,0.60375,1.00875);
   Graph_Graph_Graph10051008->SetMinimum(4.181818);
   Graph_Graph_Graph10051008->SetMaximum(21.64481);
   Graph_Graph_Graph10051008->SetDirectory(0);
   Graph_Graph_Graph10051008->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph10051008->SetLineColor(ci);
   Graph_Graph_Graph10051008->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph10051008->GetXaxis()->SetTitleOffset(1);
   Graph_Graph_Graph10051008->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph10051008->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph10051008->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph10051008->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph10051008->GetZaxis()->SetTitleOffset(1);
   Graph_Graph_Graph10051008->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph10051008);
   
   multigraph->Add(gre,"p");
   multigraph->Draw("a");
   multigraph->GetXaxis()->SetLimits(0.620625, 0.991875);
   multigraph->GetXaxis()->SetTitle(" Scattering");
   multigraph->GetXaxis()->SetLabelFont(42);
   multigraph->GetXaxis()->SetTitleOffset(1);
   multigraph->GetXaxis()->SetTitleFont(42);
   multigraph->GetYaxis()->SetTitle(" Chi square/ndof");
   multigraph->GetYaxis()->SetLabelFont(42);
   multigraph->GetYaxis()->SetTitleFont(42);
   
   TLegend *leg = new TLegend(0.55,0.65,0.88,0.85,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph","PMT ID","lp");

   ci = TColor::GetColor("#990000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#990000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(3);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","Distance from collimator","lp");

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
