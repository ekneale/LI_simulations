void collimator_compare_abs()
{
//=========Macro generated from canvas: c1_n3/c1_n3
//=========  (Tue Oct 10 14:44:42 2023) by ROOT version 6.20/04
   TCanvas *c1_n3 = new TCanvas("c1_n3", "c1_n3",10,47,700,500);
   c1_n3->Range(0.8409375,-0.1872737,1.824063,1.685463);
   c1_n3->SetFillColor(0);
   c1_n3->SetBorderMode(0);
   c1_n3->SetBorderSize(2);
   c1_n3->SetFrameBorderMode(0);
   c1_n3->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle("; Absorption; Chi square/ndof");
   
   Double_t Graph_fx1007[10] = {
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
   Double_t Graph_fy1007[10] = {
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
   
   TH1F *Graph_Graph_Graph10021007 = new TH1F("Graph_Graph_Graph10021007","Graph",100,0.9035,1.7615);
   Graph_Graph_Graph10021007->SetMinimum(0);
   Graph_Graph_Graph10021007->SetMaximum(1.459277);
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
   Double_t Graph_fy1008[10] = {
   1.169596,
   1.000785,
   0.9639699,
   0.9241299,
   1.002091,
   0.9007938,
   0.9954704,
   1.014813,
   1.005146,
   0};
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
   0.2572506,
   0.2237125,
   0.2166547,
   0.2087315,
   0.2234519,
   0.203353,
   0.2228916,
   0.2265179,
   0.2242969,
   -nan};
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
   
   TH1F *Graph_Graph_Graph10051008 = new TH1F("Graph_Graph_Graph10051008","Graph",100,0.9035,1.7615);
   Graph_Graph_Graph10051008->SetMinimum(0);
   Graph_Graph_Graph10051008->SetMaximum(1.569532);
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
