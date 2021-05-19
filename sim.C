// reading a text file
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
//
void sim(){
  const Int_t nYears = 30;
  const Int_t nMonth = 12;
  const Int_t nYearOut = 0;
  const Int_t nnMax = nYears*nMonth;
  Double_t xa[nnMax];
  Double_t ya[nnMax];
  Int_t i = 0;
  //Int_t n_inc = 12;
  /*
  Double_t s0    = 2532.0;
  Double_t sLast = 4500.0;
  Double_t dt    = 15.0;             //years
  Double_t sYearOut = 5000.0;
  */
  Double_t s0    = 2500.0;
  Double_t sLast = 4500.0;
  Double_t dt    = 20.0;             //years
  Double_t sYearOut = 5000.0;  
  //
  /*
  Double_t s0    = 4000.0;
  Double_t sLast = 7000.0;
  Double_t dt    = 5.0;             //years
  */
  //
  Double_t k     = (sLast - s0)/dt;  //eur/year
  Double_t tot = 0;
  //  
  for(i = 0;i<nnMax;i++){
    xa[i] = i;
    Double_t sc = s0 + k*((i-nYearOut*12)/nMonth);
    if ( sc > sLast)
      ya[i] = sLast;
    else if (i>=0 && i<nYearOut*12)
      ya[i] = sYearOut;
    else
      ya[i] = sc;
  }
  for(i = 0;i<nnMax;i++)
    tot += ya[i];
  cout<<"tot = "<<tot<<endl;
  cout<<"tot/month = "<<tot/nnMax<<endl;
  //
  TGraph *gr = new TGraph(nnMax,xa,ya);
  gr->SetName("gr");
  gr->SetTitle("Current vs position");
  gr->SetMarkerStyle(21);
  gr->SetMarkerColor(kRed);
  gr->SetLineColor(kBlack);
  gr->SetLineWidth(3);
  gr->GetXaxis()->SetTitle("x");
  gr->GetYaxis()->SetTitle("s");
  //
  gStyle->SetPalette(1);
  gStyle->SetFrameBorderMode(0);
  gROOT->ForceStyle();
  gStyle->SetStatColor(kWhite);
  gStyle->SetOptStat(kFALSE);
  //  
  TCanvas *c1 = new TCanvas("c1","plots",10,10,800,800);
  c1->Clear();
  c1->SetFillColor(kWhite);
  c1->GetPad(0)->SetLeftMargin(0.12);
  c1->GetPad(0)->SetRightMargin(0.02);
  c1->GetPad(0)->SetTopMargin(0.07);
  //c1->GetPad(0)->SetBottomMargin(0.02);
  //  
  gr->SetMinimum(0.0);
  gr->Draw("APL");

  ///////////
  //
  ///////////
  cout<<"M   = "<<(56.2323*572/12.0 + (80.41 + 28.97 + 453.74 - 32.42))*(1.0 - 0.279)<<endl;
  cout<<"Ma  = "<<(56.2323*1067/12.0 + (80.41 + 28.97 + 453.74 - 32.42))*(1.0 - 0.279)<<endl;
  cout<<"MaM = "<<(56.2323*1329/12.0 + (80.41 + 28.97 + 453.74 - 32.42))*(1.0 - 0.279)<<endl;
}
