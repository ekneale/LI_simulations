void collimator_compare_refl()
{
//=========Macro generated from canvas: c1_n3/c1_n3
//=========  (Tue Oct 10 14:44:28 2023) by ROOT version 6.20/04
   TCanvas *c1_n3 = new TCanvas("c1_n3", "c1_n3",10,47,700,500);
   c1_n3->Range(0.68625,-21.33669,0.93375,192.0302);
   c1_n3->SetFillColor(0);
   c1_n3->SetBorderMode(0);
   c1_n3->SetBorderSize(2);
   c1_n3->SetFrameBorderMode(0);
   c1_n3->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle("; Reflectivity; Chi square/ndof");
   
   Double_t Graph_fx1007[10] = {
   0.9,
   0.72,
   0.81,
   0.828,
   0.846,
   0.8595,
   0.8685,
   0.8775,
   0.8865,
   0.8955};
   Double_t Graph_fy1007[10] = {
   0,
   90.64671,
   43.5278,
   32.83357,
   22.2289,
   14.54659,
   10.05554,
   5.892422,
   2.929281,
   1.147723};
   Double_t Graph_fex1007[10] = {
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
   Double_t Graph_fey1007[10] = {
   -nan,
   3.008789,
   2.161347,
   1.904598,
   1.644327,
   1.399975,
   1.1773,
   0.87312,
   0.5473664,
   0.2535041};
   TGraphErrors *gre = new TGraphErrors(10,Graph_fx1007,Graph_fy1007,Graph_fex1007,Graph_fey1007);
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
   
   TH1F *Graph_Graph_Graph10021007 = new TH1F("Graph_Graph_Graph10021007","Graph",100,0.702,0.918);
   Graph_Graph_Graph10021007->SetMinimum(0);
   Graph_Graph_Graph10021007->SetMaximum(103.021);
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
   
   Double_t Graph_fx1008[10] = {
   0.9,
   0.72,
   0.81,
   0.828,
   0.846,
   0.8595,
   0.8685,
   0.8775,
   0.8865,
   0.8955};
   Double_t Graph_fy1008[10] = {
   0,
   157.6516,
   71.49221,
   52.39078,
   34.24746,
   21.75776,
   14.83557,
   8.622255,
   4.031466,
   1.234566};
   Double_t Graph_fex1008[10] = {
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
   Double_t Graph_fey1008[10] = {
   -nan,
   4.913633,
   2.801316,
   2.44559,
   2.070731,
   1.718677,
   1.428331,
   1.094515,
   0.6858054,
   0.2705821};
   gre = new TGraphErrors(10,Graph_fx1008,Graph_fy1008,Graph_fex1008,Graph_fey1008);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(7);
   gre->SetMarkerSize(3);
   
   TH1F *Graph_Graph_Graph10051008 = new TH1F("Graph_Graph_Graph10051008","Graph",100,0.702,0.918);
   Graph_Graph_Graph10051008->SetMinimum(0);
   Graph_Graph_Graph10051008->SetMaximum(178.8218);
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
   multigraph->GetXaxis()->SetLimits(0.711, 0.909);
   multigraph->GetXaxis()->SetTitle(" Reflectivity");
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
   TLegendEntry *entry=leg->AddEntry("Graph","barrel, with dark noise","lp");

   ci = TColor::GetColor("#990000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#990000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(7);
   entry->SetMarkerSize(3);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","barrel, no dark noise","lp");

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
