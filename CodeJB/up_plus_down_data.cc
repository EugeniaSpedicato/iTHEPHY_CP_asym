#include "eff.h"

void printhist(string var)
{
  string save_name = "output/data/plots/u_d/";
  TCanvas *c = new TCanvas();
  gStyle->SetOptStat(0);
  TF1 func("0*x", "0*x", -5., 11000.);
  TFile f_up("output/histOut_D02Kmpip_15_Up.root");
  TFile f_dw("output/histOut_D02Kmpip_15_Dw.root");
  string name = "h_Dst_asym"+var;
  TH1F* h_up = (TH1F*)f_up.Get(name.c_str());
  TH1F* h_up_sw = (TH1F*)f_up.Get((name+"_sw").c_str());
  TH1F* h_dw = (TH1F*)f_dw.Get(name.c_str());
  TH1F* h_dw_sw = (TH1F*)f_dw.Get((name+"_sw").c_str());
  h_up->Add(h_dw);
  h_up_sw->Add(h_dw_sw);
  h_up->Draw();
  h_up->Draw("same hist");
  func.Draw("same");
  c->SaveAs((save_name+name+".pdf").c_str());
  h_up_sw->Draw();
  h_up_sw->Draw("same hist");
  func.Draw("same");
  c->SaveAs((save_name+name+"sw.pdf").c_str());
}

void up_plus_down_data()
{

  printhist("DTF");
  printhist("phi");
  printhist("pT");
  printhist("D0m");
  
  printhist("DTF");
  printhist("phi");
  printhist("pT");
  printhist("D0m");
}
