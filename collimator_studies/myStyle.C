/*----------
  PURPOSE
  TStyle for WATCHMAN
  Matthew Needham 10 07 19

  ORIGIN (also see comments below ////////////)
  Developed from LHCB style settings for use as a macro.
  
  MODIFIED 12 07 19
  gary.smith@ed.ac.uk
  
  MODIFICATIONS
  Developed for general usage 
  (including in compiled code)
  as Getter function which
  returns TStyle object
  
  Lines removed from the end of the file 
  gROOT->SetStyle("myStyle");
  gROOT->ForceStyle();
  now have to be implemented locally
  
  USAGE
  #include "TStyle.h"
  #include "myStyle.C"
  
  //..... code
  
  TStyle * myStyle = GetmyStyle();
  
  gROOT->SetStyle("myStyle");
  gROOT->ForceStyle();
  
  //....  code
  
*/



////////////////////////////////////////////////////////////////////
// PURPOSE:
//
// This macro defines a reasonable style for (black-and-white) 
// "publication quality" ROOT plots. The default settings contain 
// many features that are either not desirable for printing on white 
// paper or impair the general readibility of plots.
//
// USAGE:
//
// Simply include the line
//   gROOT->ProcessLine(".x $LHCBSTYLE/root/lhcbstyle.C");
// at the beginning of your root macro.
//
// SOME COMMENTS:
//
// Statistics and fit boxes:
//
// "Decorative" items around the histogram are kept to a minimum.
// In particular there is no box with statistics or fit information.
// You can easily change this either by editing your private copy
// of this style file or by calls to "gStyle" in your macro.
// For example, 
//   gStyle->SetOptFit(1011);
// will add some fit information.
//
// Font:
// 
// The font is chosen to be 62, i.e.helvetica-bold-r-normal with
// precision 2. Font is of course a matter of taste, but most people
// will probably agree that Helvetica bold gives close to optimal
// readibility in presentations. It appears to be the ROOT default, 
// and since there are still some features in ROOT that simply won't 
// respond to any font requests, it is the wise choice to avoid 
// ugly font mixtures on the same plot... The precision of the font (2)
// is chosen in order to have a rotatable and scalable font. Be sure
// to use true-type fonts! I.e.
// Unix.*.Root.UseTTFonts: true  in your .rootrc file. 
//
// "Landscape histograms":
//
// The style here is designed for more or less quadratic plots.
// For very long histograms, adjustements are needed. For instance, 
// for a canvas with 1x5 histograms:
//  TCanvas* c1 = new TCanvas("c1", "L0 muons", 600, 800);
//  c1->Divide(1,5);
// adaptions like the following will be needed:
//  gStyle->SetTickLength(0.05,"x");
//  gStyle->SetTickLength(0.01,"y");
//  gStyle->SetLabelSize(0.15,"x");
//  gStyle->SetLabelSize(0.1,"y");
//  gStyle->SetStatW(0.15);
//  gStyle->SetStatH(0.5);
//
////////////////////////////////////////////////////////////////////
//    Thomas.Schietinger@cern.ch" << endl;
////////////////////////////////////////////////////////////////////


#include "TStyle.h"
#include "TPaveText.h"
#include "TLatex.h"

TStyle * GetmyStyle(){
  
  TStyle *myStyle= new TStyle("myStyle","plots style");
  
  // use helvetica-bold-r-normal, precision 2 (rotatable)
  Int_t wmFont = 132;
  // line thickness
  Double_t wmWidth = 1.30;
 
  myStyle->SetPalette(kLake); 
  // use plain black on white colors
  myStyle->SetFrameBorderMode(0);
  myStyle->SetCanvasBorderMode(0);
  myStyle->SetPadBorderMode(0);
  myStyle->SetPadColor(0);
  myStyle->SetCanvasColor(0);
  myStyle->SetStatColor(0);
  //myStyle->SetPalette(1);
  //myStyle->SetTitleColor(0);
  //myStyle->SetFillColor(0);
  
  // set the paper & margin sizes
  myStyle->SetPaperSize(20,26);
  myStyle->SetPadTopMargin(0.05);
  //myStyle->SetPadTopMargin(0.08);
  myStyle->SetPadRightMargin(0.05); // increase for colz plots!!
  //myStyle->SetPadRightMargin(0.08); // increase for colz plots!!
  //
  myStyle->SetPadBottomMargin(0.15);
  myStyle->SetPadLeftMargin(0.15);

  
  // use large fonts
//  myStyle->SetTextFont(wmFont);
  myStyle->SetTextSize(0.06);
//  myStyle->SetLabelFont(wmFont,"x");
//  myStyle->SetLabelFont(wmFont,"y");
//  myStyle->SetLabelFont(wmFont,"z");
  myStyle->SetLabelSize(0.05,"x");
  myStyle->SetLabelSize(0.05,"y");
  myStyle->SetLabelSize(0.05,"z");
//  myStyle->SetTitleFont(wmFont,"x");
//  myStyle->SetTitleFont(wmFont,"y");
  myStyle->SetTitleSize(0.06,"x");
  myStyle->SetTitleSize(0.06,"y");
  myStyle->SetTitleSize(0.06,"z");
  
  // use bold lines and markers
  //myStyle->SetLineWidth(wmWidth);
  //myStyle->SetFrameLineWidth(wmWidth);
  //myStyle->SetHistLineWidth(wmWidth);
  //myStyle->SetFuncWidth(wmWidth);
  //myStyle->SetGridWidth(wmWidth);
  //myStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes
  //myStyle->SetMarkerStyle(15);
  //myStyle->SetMarkerStyle(20);
  // myStyle->SetMarkerSize(1.5);
  //myStyle->SetMarkerSize(1.);
  
  //myStyle->SetTitleYOffset(1.);
  myStyle->SetTitleYOffset(1.1);
  myStyle->SetTitleXOffset(1.1);
  // myStyle->SetTitleYSize(0.02)
  // by default, do not display histogram decorations:
//  myStyle->SetOptStat(0);  
  //myStyle->SetOptStat(1110);  // show only nent, mean, rms
  myStyle->SetOptTitle(0);
  myStyle->SetOptFit(0);
  //myStyle->SetOptFit(1011); // show probability, parameters and errors
  
  // look of the statistics box:
  myStyle->SetStatBorderSize(1);
  myStyle->SetStatFont(wmFont);
  myStyle->SetStatFontSize(0.05);
  /*
    myStyle->SetStatX(0.9);
    myStyle->SetStatY(0.9);
    myStyle->SetStatW(0.25);
    myStyle->SetStatH(0.15);
  */
  // put tick marks on top and RHS of plots
  //myStyle->SetPadTickX(1);
  //myStyle->SetPadTickY(1);
  
  // histogram divisions: only 5 in x to avoid label overlaps
  //myStyle->SetNdivisions(505,"x");
  //myStyle->SetNdivisions(510,"y");
  
  TPaveText *wmName = new TPaveText(0.65,0.8,0.9,0.9,"BRNDC");
  // TPaveText *wmName = new TPaveText(0.2,0.3,0.45,0.4,"BRNDC");
  wmName->SetFillColor(0);
  wmName->SetTextAlign(12);
  wmName->SetBorderSize(0);
  // wmName->AddText("Wm");
  wmName->AddText("#splitline{#splitline{Wm}{Preliminary}}{#scale[0.7]{#sqrt{s} = 7 TeV Data}}");
  
  TText *wmLabel = new TText();
//  wmLabel->SetTextFont(wmFont);
  wmLabel->SetTextColor(1);
  wmLabel->SetTextSize(0.04);
  wmLabel->SetTextAlign(12);
  
  TLatex *wmLatex = new TLatex();
  wmLatex->SetTextFont(wmFont);
  wmLatex->SetTextColor(1);
  wmLatex->SetTextSize(0.04);
  wmLatex->SetTextAlign(12);
  

  // Gary 5th Sept 19
  myStyle->SetLegendBorderSize(0);

 return myStyle;

}

