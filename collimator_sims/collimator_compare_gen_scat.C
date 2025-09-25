void collimator_compare_gen_scat()
{
//=========Macro generated from canvas: c1_n3/c1_n3
//=========  (Tue Oct 10 13:31:24 2023) by ROOT version 6.20/04
   TCanvas *c1_n3 = new TCanvas("c1_n3", "c1_n3",10,47,700,500);
   c1_n3->Range(0.4851562,-2.47634,1.052344,22.28706);
   c1_n3->SetFillColor(0);
   c1_n3->SetBorderMode(0);
   c1_n3->SetBorderSize(2);
   c1_n3->SetFrameBorderMode(0);
   c1_n3->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle("; Scattering; Chi square/ndof");
   
   Double_t Graph_fx1007[20] = {
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
   Double_t Graph_fy1007[20] = {
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
   Double_t Graph_fex1007[20] = {
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
   Double_t Graph_fey1007[20] = {
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
   TGraphErrors *gre = new TGraphErrors(20,Graph_fx1007,Graph_fy1007,Graph_fex1007,Graph_fey1007);
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
   
   TH1F *Graph_Graph_Graph10021007 = new TH1F("Graph_Graph_Graph10021007","Graph",100,0.52125,1.01625);
   Graph_Graph_Graph10021007->SetMinimum(0.6331288);
   Graph_Graph_Graph10021007->SetMaximum(20.23263);
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
   Double_t Graph_fy1008[10] = {
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
   1.436246,
   0.8595091,
   0.2837095,
   0.2437676,
   0.205889,
   0.231436,
   0.2746798,
   0.4730046,
   0.8907844,
   1.218772};
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
   
   TH1F *Graph_Graph_Graph10051008 = new TH1F("Graph_Graph_Graph10051008","Graph",100,0.52125,1.01625);
   Graph_Graph_Graph10051008->SetMinimum(0.6968949);
   Graph_Graph_Graph10051008->SetMaximum(20.7135);
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
