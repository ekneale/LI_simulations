void collimator_scat()
{
//=========Macro generated from canvas: c1_n2/c1_n2
//=========  (Tue Oct 10 14:45:16 2023) by ROOT version 6.20/04
   TCanvas *c1_n2 = new TCanvas("c1_n2", "c1_n2",10,47,700,500);
   c1_n2->Range(0.4851562,-2.477851,1.052344,22.30066);
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
   0.9,
   0.975};
   Double_t Graph_fy1004[10] = {
   1.021502,
   1.075417,
   0.9300218,
   0.995359,
   1.040937,
   1.10309,
   1.017427,
   1.022572,
   0.9532667,
   0.9366181};
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
   0.252022,
   0.229334,
   0.2377082,
   0.2327898,
   0.2210657,
   0.2387917,
   0.2246505,
   0.2467371,
   0.2398635,
   0.2570187};
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
   Graph_Graph1004->SetMinimum(0.6133712);
   Graph_Graph1004->SetMaximum(1.40811);
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
   
   Double_t Graph_fx1005[10] = {
   0.5625,
   0.6375,
   0.7125,
   0.7275,
   0.7425,
   0.765,
   0.78,
   0.825,
   0.9,
   0.975};
   Double_t Graph_fy1005[10] = {
   17.46461,
   5.841254,
   1.473894,
   1.093905,
   0.9935196,
   1.005764,
   1.177326,
   2.391186,
   6.270402,
   11.30301};
   Double_t Graph_fex1005[10] = {
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
   Double_t Graph_fey1005[10] = {
   1.443099,
   0.838675,
   0.2791233,
   0.2451308,
   0.21449,
   0.2327009,
   0.2663588,
   0.4624622,
   0.9184587,
   1.205364};
   gre = new TGraphErrors(10,Graph_fx1005,Graph_fy1005,Graph_fex1005,Graph_fey1005);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#990000");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#990000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(3);
   
   TH1F *Graph_Graph1005 = new TH1F("Graph_Graph1005","Graph",100,0.52125,1.01625);
   Graph_Graph1005->SetMinimum(0.6957565);
   Graph_Graph1005->SetMaximum(20.72117);
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
   0.9,
   0.975};
   Double_t Graph_fy1006[10] = {
   1.068372,
   0.9642479,
   0.9539207,
   0.9453888,
   0.8876364,
   0.8934768,
   1.114282,
   0.8601613,
   1.032244,
   1.27797};
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
   0.2658718,
   0.2520435,
   0.2506408,
   0.2298289,
   0.2383639,
   0.2293095,
   0.2339272,
   0.2545505,
   0.2427254,
   0.2571813};
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
   Graph_Graph1006->SetMinimum(0.5126568);
   Graph_Graph1006->SetMaximum(1.628105);
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
