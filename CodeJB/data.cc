#pragma
#include "eff.h"
#include <chrono>
#include <fstream>
#include "TH2F.h"
#include "RooBreitWigner.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooPlot.h"
#include "RooFit.h"
#include "RooAddPdf.h"
#include "RooClassFactory.h"
#include "RooExtendPdf.h"
#include "RooRealVar.h"
#include "RooStats/SPlot.h"
#include "RooProdPdf.h"
#include "RooAbsPdf.h"
#include "RooFitResult.h"
using namespace RooFit;

void printdevhists(TH1F *h_pos, TH1F *h_neg, string polarisation, bool weighted)
{
  TF1 func("0*x", "0*x", -5., 9600.);
  int nbins = h_pos->GetNbinsX();
  double min = h_pos->GetXaxis()->GetBinLowEdge(1);
  double max = h_pos->GetXaxis()->GetBinLowEdge(nbins) + h_pos->GetXaxis()->GetBinWidth(nbins);
  TH1F *h_temp_pos = new TH1F(h_pos->GetName(), h_pos->GetName(), nbins, min, max);
  h_temp_pos->Add(h_pos);
  TH1F *h_temp_neg = new TH1F(h_neg->GetName(), h_neg->GetName(), nbins, min, max);
  h_temp_neg->Add(h_neg);
  bool up_down = (polarisation == "UP")? true : false;
  string directory = (up_down == true)? "up" : "down";
  TCanvas *c = new TCanvas();
  string title_name;
  string new_title;
  string save_name;
  h_pos->Add(h_neg,-1);
  h_neg->Scale(2.);
  h_neg->Add(h_pos);
  h_pos->Divide(h_neg);
  h_pos->SetAxisRange(-0.15, 0.15, "Y");
  title_name = "h_Dst_DTF_asym";
  h_pos->SetName(title_name.c_str());
  h_pos->Draw();
  h_pos->Draw("hist same");
  func.Draw("same");
  if(weighted) save_name = "output/data/plots/"+directory"/"+title_name+"_w.pdf";
  else save_name = "output/data/plots/"+directory"/"+title_name+".pdf";
  c->SaveAs(save_name.c_str());
  h_pos->Write();
  }
}

void printhists(TH1F *h, bool up)
{
  TCanvas *c = new TCanvas();
  h->Draw();
  h->Draw("hist same");
  string title_name = h->GetName();
  string save_name = (up)?"output/data/plots/up/"+title_name+".pdf": "output/data/plots/down/"+title_name+".pdf";
  c->SaveAs(save_name.c_str());
}

void data(string dir, string sample, string pol)
{
  /*ROOT::EnableThreadSafety();
  const auto nThreads = thread::hardware_concurrency();
  ROOT::EnableImplicitMT(nThreads);*/
  uint64_t start_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
  string input_name = dir+"/"+sample+".root";
  TChain *ntp = new TChain();
  bool up = (pol == "UP")? true:false;
  if(up)
  {
    ntp->AddFile(input_name.c_str(),-1,"ntp;25");
    ntp->AddFile(input_name.c_str(),-1,"ntp;26");
  }
  else
  {
    ntp->AddFile(input_name.c_str(),-1,"ntp;37");
    ntp->AddFile(input_name.c_str(),-1,"ntp;38");
  }
  int nEvents = ntp->GetEntries();



  double nDst_pos = 0.; double nDst_neg = 0.;
  int Dst_ID, D0_ID, Pi_ID, K_ID;
  double D0_mass, DTF_mass, Dst_pT, Dst_phi, Dst_eta;


  ntp->SetBranchStatus("*",0);
  ntp->SetBranchStatus("D0_M",1); ntp->SetBranchAddress("D0_M", &(D0_mass));
  ntp->SetBranchStatus("DTF_Mass",1); ntp->SetBranchAddress("DTF_Mass", &(DTF_mass));
  ntp->SetBranchStatus("Dst_PT",1); ntp->SetBranchAddress("Dst_PT", &(Dst_pT));
  ntp->SetBranchStatus("Dst_PHI",1); ntp->SetBranchAddress("Dst_PHI", &(Dst_phi));
  ntp->SetBranchStatus("Dst_ETA",1); ntp->SetBranchAddress("Dst_ETA", &(Dst_eta));

  ntp->SetBranchStatus("Dst_ID",1); ntp->SetBranchAddress("Dst_ID", &(Dst_ID));
  ntp->SetBranchStatus("D0_ID",1); ntp->SetBranchAddress("D0_ID", &(D0_ID));
  ntp->SetBranchStatus("P1_ID",1); ntp->SetBranchAddress("P1_ID", &(Pi_ID));
  ntp->SetBranchStatus("P2_ID",1); ntp->SetBranchAddress("P2_ID", &(K_ID));


//other RooFit

  RooRealVar *DTF_Mass = new RooRealVar("DTF_Mass", "DTF_Mass", 2004., 2021.);
  //RooRealVar *DTF_Mass_iso = new RooRealVar("DTF_Mass", "DTF_Mass_iso", 2012.5, 2021.);
  RooRealVar *Dst_ID_neg = new RooRealVar("Dst_ID", "Dst_ID_neg", -420., -400.);
  RooRealVar *Dst_ID_pos = new RooRealVar("Dst_ID", "Dst_ID_pos", 400., 420.);

  RooDataSet *dataset1 = new RooDataSet("dataset1", "dataset1", ntp, RooArgList(*DTF_Mass, *Dst_ID_neg));
  RooDataSet *dataset2 = new RooDataSet("dataset2", "dataset2", ntp, RooArgList(*DTF_Mass, *Dst_ID_pos));/*
  RooDataSet *dataset1b = new RooDataSet("dataset1b", "dataset1b", ntp, RooArgList(*DTF_Mass_iso, *Dst_ID_neg));
  RooDataSet *dataset2b = new RooDataSet("dataset2b", "dataset2b", ntp, RooArgList(*DTF_Mass_iso, *Dst_ID_pos));*/

  RooRealVar *N = new RooRealVar("N", "N", 0.006, 0., 0.01);
  RooRealVar *a = new RooRealVar("a", "a", 2004., 2000., 2010.);
  RooRealVar *c = new RooRealVar("c", "c", 0.05, 0., 0.5);
  RooRealVar *b = new RooRealVar("b", "b", 0.681, 0., 2.);
  RooRealVar *mean = new RooRealVar("mean", "mean", 2010., 2008., 2012.);
  RooRealVar *sigma = new RooRealVar("sigma", "sigma", 0.3, 0., 1.);
  RooRealVar *sig_yield = new RooRealVar("sig_yield", "sig_yield", 25000., 0., 200000.);
  RooRealVar *bkg_yield = new RooRealVar("bkg_yield", "bkg_yield", 1000., 0., 10000.);
  RooRealVar *sig_yield_2 = new RooRealVar("sig_yield_2", "sig_yield_2", 25000., 0., 200000.);
  RooRealVar *bkg_yield_2 = new RooRealVar("bkg_yield_2", "bkg_yield_2", 1000., 0., 10000.);

  RooBreitWigner *sig = new RooBreitWigner("sig", "sig", *DTF_Mass, *mean, *sigma);
  RooAbsPdf *arg = RooClassFactory::makePdfInstance("arg", "1./N*pow(DTF_Mass-a,b)*exp(-c*(DTF_Mass-a))", RooArgSet(*DTF_Mass, *N, *a, *b, *c));
  RooAddPdf *model_neg = new RooAddPdf("model_neg", "model_neg", RooArgList(*sig, *arg),RooArgList(*sig_yield, *bkg_yield));
  RooAddPdf *model_pos = new RooAddPdf("model_pos", "model_pos", RooArgList(*sig, *arg),RooArgList(*sig_yield_2, *bkg_yield_2));

  model_neg->fitTo(*dataset1, Extended(), RooFit::PrintLevel(-1), RooFit::PrintEvalErrors(-1));
  RooStats::SPlot *sData = new RooStats::SPlot("sData", "An SPlot", *dataset1, model_neg, RooArgList(*sig_yield, *bkg_yield));
  model_pos->fitTo(*dataset2, Extended(), RooFit::PrintLevel(-1), RooFit::PrintEvalErrors(-1));
  RooStats::SPlot *sData2 = new RooStats::SPlot("sData2", "An SPlot2", *dataset2, model_pos, RooArgList(*sig_yield_2, *bkg_yield_2));

  TFile *f = (up)? new TFile("output/histOut_minisample_Dst2D0pi_D02Kpi_2016_Up_GEN.root"): new TFile("output/histOut_minisample_Dst2D0pi_D02Kpi_2016_Dw_GEN.root");

  TH1F *h_Dst_pT_MC = (TH1F*)f->Get("h_pT_Dst");
  double nMCEvents = h_Dst_pT_MC->GetEntries();
  h_Dst_pT_MC->Scale(1./nMCEvents);
  h_Dst_pT_MC->SetLineColor(kAzure);

  TH1F *h_Dst_DTF_pos = new TH1F("h_Dst_DTF_pos", ";DTF Mass/MeV; Event", 170, 2004., 2021.);
  TH1F *h_Dst_DTF_neg = new TH1F("h_Dst_DTF_neg", ";DsTF Mass/MeV; Event", 170, 2004., 2021.);

  TH1F *h_Dst_DTF_pos_w = new TH1F("h_Dst_DTF_pos_w", ";DTF Mass/MeV; Event", 170, 2004., 2021.);
  TH1F *h_Dst_DTF_neg_w = new TH1F("h_Dst_DTF_neg_w", ";DsTF Mass/MeV; Event", 170, 2004., 2021.);

  TH1F *h_Dst_pT_data = new TH1F("h_Dst_pT_data", ";Dst pT/MeV; Event", 180, 2000., 11000.);
  TH1F *h_Dst_pT_data_nw = new TH1F("h_Dst_pT_data_nw", ";Dst pT/MeV; Event", 180, 2000., 11000.);
  TH2F *h_Dst_eta_phi_plane = new TH2F("h_Dst_eta_phi_plane", "; #phi; #eta", 70, -3.5, 3.5, 30, 2.5, 4.0);

  h_Dst_DTF_pos_w->Sumw2();
  h_Dst_DTF_neg_w->Sumw2();
  h_Dst_DTF_pos->Sumw2();
  h_Dst_DTF_neg->Sumw2();
  h_Dst_pT_data->Sumw2();
  h_Dst_pT_data_nw->Sumw2();

  int i_pos = 0;
  int i_neg = 0;

  for (int i = 0; i < nEvents; ++i)
  {
    if (i % (nEvents/10) == 0)
    {
      std::cout << "=== Event " << i/(nEvents/10) * 10 << "%" << std::endl;
    }
    ntp->GetEvent(i);
    if(Dst_ID < 0)
    {
      h_Dst_pT_data->Fill(Dst_pT, sData->GetSumOfEventSWeight(i_neg));
      h_Dst_DTF_neg_w->Fill(DTF_mass, sData->GetSumOfEventSWeight(i_neg));
      h_Dst_DTF_neg->Fill(DTF_mass);
      ++i_neg;
    }
    else
    {
      h_Dst_pT_data->Fill(Dst_pT, sData2->GetSumOfEventSWeight(i_pos));
      h_Dst_DTF_pos_w->Fill(DTF_mass, sData2->GetSumOfEventSWeight(i_pos));
      h_Dst_DTF_pos->Fill(DTF_mass);
      ++i_pos;
    }
    h_Dst_pT_data_nw->Fill(Dst_pT);
    h_Dst_pT_data_3D->Fill(Dst_phi, Dst_eta);
  }

  double nDataEvents = h_Dst_pT_data->GetSumOfWeights();
  h_Dst_pT_data->Scale(1./nDataEvents);
  h_Dst_pT_data_nw->Scale(1./h_Dst_pT_data_nw->GetEntries());
  h_Dst_pT_data->SetLineColor(kRed);
  h_Dst_pT_data_nw->SetLineColor(kBlack);

  TCanvas *canvas2 = new TCanvas();
  h_Dst_pT_MC->Draw();
  h_Dst_pT_MC->Draw("hist same");
  h_Dst_pT_data->Draw("same");
  h_Dst_pT_data->Draw("hist same");
  h_Dst_pT_data_nw->Draw("same");
  h_Dst_pT_data_nw->Draw("hist same");
  if(up) canvas2->SaveAs("output/data/plots/up/MC_data_comp.pdf");
  else canvas2->SaveAs("output/data/plots/down/MC_data_comp.pdf");

  h_Dst_pT_data_3D->Draw("SURF4 FB");
  if(up) canvas2->SaveAs("output/data/plots/up/eta_phi_plane.pdf");
  else canvas2->SaveAs("output/data/plots/down/eta_phi_plane.pdf");

  double nPos = h_Dst_DTF_pos->GetSumOfWeights();
  double nPosW = h_Dst_DTF_pos_w->GetSumOfWeights();
  double nNeg = h_Dst_DTF_neg->GetSumOfWeights();
  double nNegW = h_Dst_DTF_neg_w->GetSumOfWeights();

  printdevhists(h_Dst_DTF_pos, h_Dst_DTF_neg, pol, false)
  printdevhists(h_Dst_DTF_pos_w, h_Dst_DTF_neg_w, pol, true)

  cout << "Total asymmetry before weighting: " << (nPos - nNeg)/(nPos + nNeg) << endl;
  cout << "Total asymmetry after weighting: " << (nPosW - nNegW)/(nPosW + nNegW) << endl;

  uint64_t end_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
  float elapsed = (end_time - start_time)*0.000001;
  std::cout << "computation time/s: " << elapsed << std::endl;
  std::cout << "computation time/min: " << elapsed/60. << std::endl;
}
