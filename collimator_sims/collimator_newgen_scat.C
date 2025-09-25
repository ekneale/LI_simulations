void collimator_newgen_scat()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Oct 10 13:31:22 2023) by ROOT version 6.20/04
   TCanvas *c1 = new TCanvas("c1", "c1",10,47,700,500);
   c1->Range(0.4851562,-2.418331,1.052344,21.76497);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle("; Scattering; Chi square/ndof");
   
   Double_t Graph_fx1001[20] = {
   0.5625,
   0.6375,
   0.7125,
   0.7275,
   0.7425,
   0.765,
   0.78,
   0.825,
   0.9,
   0.975,
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
   Double_t Graph_fy1001[20] = {
   1.047614,
   0.9712009,
   0.9028546,
   0.9929297,
   0.9510492,
   0.9759811,
   0.8669066,
   1.020107,
   0.9544125,
   1.064459,
   1.12915,
   1.019404,
   1.061742,
   1.034949,
   0.9823886,
   1.067663,
   0.9960189,
   1.104012,
   1.070601,
   1.157883};
   Double_t Graph_fex1001[20] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Graph_fey1001[20] = {
   0.2347208,
   0.2194511,
   0.2056391,
   0.2240372,
   0.2147297,
   0.2196588,
   0.1974733,
   0.2293379,
   0.2160511,
   0.238997,
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
   TGraphErrors *gre = new TGraphErrors(20,Graph_fx1001,Graph_fy1001,Graph_fex1001,Graph_fey1001);
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
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","Graph",100,0.52125,1.01625);
   Graph_Graph1001->SetMinimum(0.5948865);
   Graph_Graph1001->SetMaximum(1.489449);
   Graph_Graph1001->SetDirectory(0);
   Graph_Graph1001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1001->SetLineColor(ci);
   Graph_Graph1001->GetXaxis()->SetLabelFont(42);
   Graph_Graph1001->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1001->GetXaxis()->SetTitleFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelFont(42);
   Graph_Graph1001->GetYaxis()->SetTitleFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelFont(42);
   Graph_Graph1001->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1001);
   
   multigraph->Add(gre,"p");
   
   Double_t Graph_fx1002[20] = {
   0.5625,
   0.6375,
   0.7125,
   0.7275,
   0.7425,
   0.765,
   0.78,
   0.825,
   0.9,
   0.975,
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
   Double_t Graph_fy1002[20] = {
   17.02101,
   5.702922,
   1.308442,
   1.097066,
   0.9093655,
   1.034109,
   1.263207,
   2.420738,
   6.199105,
   11.42983,
   16.74791,
   5.572069,
   1.284467,
   1.108394,
   0.9527753,
   1.042966,
   1.216139,
   2.38169,
   6.308379,
   11.2164};
   Double_t Graph_fex1002[20] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Graph_fey1002[20] = {
   1.436246,
   0.8595091,
   0.2837095,
   0.2437676,
   0.205889,
   0.231436,
   0.2746798,
   0.4730046,
   0.8907844,
   1.218772,
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
   gre = new TGraphErrors(20,Graph_fx1002,Graph_fy1002,Graph_fex1002,Graph_fey1002);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#990000");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#990000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(3);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","Graph",100,0.52125,1.01625);
   Graph_Graph1002->SetMinimum(0.6331288);
   Graph_Graph1002->SetMaximum(20.23263);
   Graph_Graph1002->SetDirectory(0);
   Graph_Graph1002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1002->SetLineColor(ci);
   Graph_Graph1002->GetXaxis()->SetLabelFont(42);
   Graph_Graph1002->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1002->GetXaxis()->SetTitleFont(42);
   Graph_Graph1002->GetYaxis()->SetLabelFont(42);
   Graph_Graph1002->GetYaxis()->SetTitleFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelFont(42);
   Graph_Graph1002->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1002->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1002);
   
   multigraph->Add(gre,"p");
   
   Double_t Graph_fx1003[20] = {
   0.5625,
   0.6375,
   0.7125,
   0.7275,
   0.7425,
   0.765,
   0.78,
   0.825,
   0.9,
   0.975,
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
   Double_t Graph_fy1003[20] = {
   1.278725,
   0.9258269,
   0.9881642,
   1.027767,
   1.054132,
   1.094792,
   1.024499,
   0.945169,
   1.103774,
   1.15142,
   1.205596,
   1.136988,
   1.123023,
   1.022914,
   1.064079,
   1.0212,
   1.038106,
   1.148248,
   1.080756,
   1.156217};
   Double_t Graph_fex1003[20] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
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
   Double_t Graph_fey1003[20] = {
   0.2815257,
   0.2104807,
   0.222887,
   0.2322928,
   0.2362879,
   0.2458232,
   0.2299319,
   0.2163128,
   0.2478114,
   0.2568218,
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
   gre = new TGraphErrors(20,Graph_fx1003,Graph_fy1003,Graph_fex1003,Graph_fey1003);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#009900");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#009900");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(3);
   
   TH1F *Graph_Graph1003 = new TH1F("Graph_Graph1003","Graph",100,0.52125,1.01625);
   Graph_Graph1003->SetMinimum(0.6308557);
   Graph_Graph1003->SetMaximum(1.644741);
   Graph_Graph1003->SetDirectory(0);
   Graph_Graph1003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1003->SetLineColor(ci);
   Graph_Graph1003->GetXaxis()->SetLabelFont(42);
   Graph_Graph1003->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1003->GetXaxis()->SetTitleFont(42);
   Graph_Graph1003->GetYaxis()->SetLabelFont(42);
   Graph_Graph1003->GetYaxis()->SetTitleFont(42);
   Graph_Graph1003->GetZaxis()->SetLabelFont(42);
   Graph_Graph1003->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1003);
   
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
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
