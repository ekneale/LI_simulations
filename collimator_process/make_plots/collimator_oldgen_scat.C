void collimator_oldgen_scat()
{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Tue Sep 26 19:22:10 2023) by ROOT version 6.20/04
   TCanvas *c1_n2 = new TCanvas("c1_n2", "c1_n2",10,47,700,500);
   c1_n2->Range(0.4851562,1.329322,1.052344,23.16749);
   c1_n2->SetFillColor(0);
   c1_n2->SetBorderMode(0);
   c1_n2->SetBorderSize(2);
   c1_n2->SetFrameBorderMode(0);
   c1_n2->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle("; Scattering; Chi square/ndof");
   
   Double_t Graph_fx1004[10] = {
   0.5625,
   0.6375,
   0.7125,
   0.7275,
   0.7425,
   0.765,
   0.78,
   0.825,
   0.975,
   0.9};
   Double_t Graph_fy1004[10] = {
   5.812962,
   5.673338,
   5.297411,
   6.169776,
   5.756613,
   5.486395,
   5.470973,
   5.54135,
   5.945087,
   5.735545};
   Double_t Graph_fex1004[10] = {
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
   Double_t Graph_fey1004[10] = {
   1.04529,
   1.050542,
   0.9901566,
   1.133529,
   1.062544,
   1.013481,
   1.040323,
   1.031016,
   1.065684,
   1.023308};
   TGraphErrors *gre = new TGraphErrors(10,Graph_fx1004,Graph_fy1004,Graph_fex1004,Graph_fey1004);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#000099");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(3);
   
   TH1F *Graph_Graph1004 = new TH1F("Graph_Graph1004","Graph",100,0.52125,1.01625);
   Graph_Graph1004->SetMinimum(4.007649);
   Graph_Graph1004->SetMaximum(7.60291);
   Graph_Graph1004->SetDirectory(0);
   Graph_Graph1004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1004->SetLineColor(ci);
   Graph_Graph1004->GetXaxis()->SetLabelFont(42);
   Graph_Graph1004->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1004->GetXaxis()->SetTitleFont(42);
   Graph_Graph1004->GetYaxis()->SetLabelFont(42);
   Graph_Graph1004->GetYaxis()->SetTitleFont(42);
   Graph_Graph1004->GetZaxis()->SetLabelFont(42);
   Graph_Graph1004->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1004->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1004);
   
   multigraph->Add(gre,"p");
   
   Double_t Graph_fx1005[9] = {
   0.6375,
   0.7125,
   0.7275,
   0.7425,
   0.765,
   0.78,
   0.825,
   0.975,
   0.9};
   Double_t Graph_fy1005[9] = {
   17.26188,
   9.292148,
   8.998222,
   7.632745,
   7.827375,
   7.086635,
   7.60275,
   12.13103,
   8.839494};
   Double_t Graph_fex1005[9] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1005[9] = {
   2.927682,
   1.878068,
   1.81292,
   1.556615,
   1.55665,
   1.449568,
   1.460729,
   1.816521,
   1.532772};
   gre = new TGraphErrors(9,Graph_fx1005,Graph_fy1005,Graph_fex1005,Graph_fey1005);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#990000");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#990000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(3);
   
   TH1F *Graph_Graph1005 = new TH1F("Graph_Graph1005","Graph",100,0.60375,1.00875);
   Graph_Graph1005->SetMinimum(4.181818);
   Graph_Graph1005->SetMaximum(21.64481);
   Graph_Graph1005->SetDirectory(0);
   Graph_Graph1005->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1005->SetLineColor(ci);
   Graph_Graph1005->GetXaxis()->SetLabelFont(42);
   Graph_Graph1005->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1005->GetXaxis()->SetTitleFont(42);
   Graph_Graph1005->GetYaxis()->SetLabelFont(42);
   Graph_Graph1005->GetYaxis()->SetTitleFont(42);
   Graph_Graph1005->GetZaxis()->SetLabelFont(42);
   Graph_Graph1005->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1005->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1005);
   
   multigraph->Add(gre,"p");
   
   Double_t Graph_fx1006[10] = {
   0.5625,
   0.6375,
   0.7125,
   0.7275,
   0.7425,
   0.765,
   0.78,
   0.825,
   0.975,
   0.9};
   Double_t Graph_fy1006[10] = {
   7.164833,
   7.78154,
   7.319163,
   6.744658,
   6.053271,
   7.029389,
   6.264878,
   6.967076,
   6.952612,
   6.707395};
   Double_t Graph_fex1006[10] = {
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
   Double_t Graph_fey1006[10] = {
   1.249037,
   1.385249,
   1.34658,
   1.239563,
   1.123997,
   1.293096,
   1.137607,
   1.323009,
   1.302575,
   1.229053};
   gre = new TGraphErrors(10,Graph_fx1006,Graph_fy1006,Graph_fex1006,Graph_fey1006);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#009900");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#009900");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(3);
   
   TH1F *Graph_Graph1006 = new TH1F("Graph_Graph1006","Graph",100,0.52125,1.01625);
   Graph_Graph1006->SetMinimum(4.505523);
   Graph_Graph1006->SetMaximum(9.590541);
   Graph_Graph1006->SetDirectory(0);
   Graph_Graph1006->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1006->SetLineColor(ci);
   Graph_Graph1006->GetXaxis()->SetLabelFont(42);
   Graph_Graph1006->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1006->GetXaxis()->SetTitleFont(42);
   Graph_Graph1006->GetYaxis()->SetLabelFont(42);
   Graph_Graph1006->GetYaxis()->SetTitleFont(42);
   Graph_Graph1006->GetZaxis()->SetLabelFont(42);
   Graph_Graph1006->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1006->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1006);
   
   multigraph->Add(gre,"p");
   multigraph->Draw("a");
   multigraph->GetXaxis()->SetLimits(0.541875, 0.995625);
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
   TLegendEntry *entry=leg->AddEntry("Graph","bottom, all hits","lp");

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#000099");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(3);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","barrel, all hits","lp");

   ci = TColor::GetColor("#990000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#990000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(3);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","top, all hits","lp");

   ci = TColor::GetColor("#009900");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#009900");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(3);
   entry->SetTextFont(42);
   leg->Draw();
   c1_n2->Modified();
   c1_n2->cd();
   c1_n2->SetSelected(c1_n2);
}
