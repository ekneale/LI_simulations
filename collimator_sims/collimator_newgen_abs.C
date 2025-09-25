void collimator_newgen_abs()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Oct 10 13:31:07 2023) by ROOT version 6.20/04
   TCanvas *c1 = new TCanvas("c1", "c1",10,47,700,500);
   c1->Range(0.8409375,-0.1975756,1.824063,1.778181);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle("; Absorption; Chi square/ndof");
   
   Double_t Graph_fx1001[20] = {
   0.975,
   1.105,
   1.235,
   1.261,
   1.287,
   1.326,
   1.43,
   1.56,
   1.69,
   1.3,
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
   Double_t Graph_fy1001[20] = {
   1.023022,
   0.9647959,
   0.9616601,
   0.9477287,
   0.9625325,
   0.9975888,
   0.9810277,
   0.9984919,
   0.9472501,
   0,
   0.9754628,
   1.060473,
   0.9811553,
   1.008275,
   1.101308,
   1.028274,
   1.062688,
   1.087254,
   0.9939782,
   0};
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
   0.2292128,
   0.2179675,
   0.2179107,
   0.2146692,
   0.2181831,
   0.22402,
   0.2205766,
   0.2244071,
   0.2147285,
   -nan,
   0.2208149,
   0.2372347,
   0.2213947,
   0.2271717,
   0.2465579,
   0.2300693,
   0.2373761,
   0.2430643,
   0.2244717,
   -nan};
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
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","Graph",100,0.9035,1.7615);
   Graph_Graph1001->SetMinimum(0);
   Graph_Graph1001->SetMaximum(1.482652);
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
   0.975,
   1.105,
   1.235,
   1.261,
   1.287,
   1.326,
   1.43,
   1.56,
   1.69,
   1.3,
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
   Double_t Graph_fy1002[20] = {
   1.161848,
   1.011117,
   0.9396873,
   0.9575113,
   0.8923322,
   0.9140097,
   0.9125993,
   1.033005,
   0.9795202,
   0,
   1.072569,
   0.9888662,
   0.9451532,
   0.9576947,
   0.979197,
   0.959595,
   0.8883063,
   0.9940348,
   1.085311,
   0};
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
   0.2560354,
   0.2264867,
   0.2117043,
   0.215395,
   0.2023355,
   0.2066678,
   0.2062205,
   0.2300144,
   0.2192692,
   -nan,
   0.2383164,
   0.2210637,
   0.2133563,
   0.2153212,
   0.2198267,
   0.2155014,
   0.2014489,
   0.2226017,
   0.241305,
   -nan};
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
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","Graph",100,0.9035,1.7615);
   Graph_Graph1002->SetMinimum(0);
   Graph_Graph1002->SetMaximum(1.559671);
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
   0.975,
   1.105,
   1.235,
   1.261,
   1.287,
   1.326,
   1.43,
   1.56,
   1.69,
   1.3,
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
   Double_t Graph_fy1003[20] = {
   1.208151,
   0.9536384,
   0.9471679,
   1.039011,
   1.148105,
   1.009981,
   1.133877,
   1.100311,
   0.8970151,
   0,
   1.073289,
   0.9991305,
   1.158208,
   1.081048,
   1.000027,
   1.138876,
   1.219111,
   1.131945,
   1.233361,
   0};
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
   0.2676275,
   0.2157681,
   0.215062,
   0.2334212,
   0.2559252,
   0.2277194,
   0.2547879,
   0.2478936,
   0.2038708,
   -nan,
   0.2398663,
   0.2257495,
   0.2566585,
   0.2419655,
   0.2257453,
   0.253466,
   0.2691337,
   0.2514584,
   0.2719774,
   -nan};
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
   
   TH1F *Graph_Graph1003 = new TH1F("Graph_Graph1003","Graph",100,0.9035,1.7615);
   Graph_Graph1003->SetMinimum(0);
   Graph_Graph1003->SetMaximum(1.655872);
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
   multigraph->GetXaxis()->SetLimits(0.93925, 1.72575);
   multigraph->GetXaxis()->SetTitle(" Absorption");
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
