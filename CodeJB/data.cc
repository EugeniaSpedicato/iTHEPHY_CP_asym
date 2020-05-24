#pragma
#include "eff.h"
#include <chrono>
#include <fstream>
#include <thread>
#include "TH2F.h"
#include "RooGaussian.h"
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
#include "RooMinuit.h"
#include "TROOT.h"
using namespace RooFit;

void printdevhists(TH1F *h_pos, TH1F *h_neg, string polarisation, string var, bool weighted)
{
  TF1 func("0*x", "0*x", -5., 11000.);
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
  title_name = "h_Dst_asym"+var;
  h_pos->SetName(title_name.c_str());
  h_pos->SetAxisRange(-0.1, 0.1, "Y");
  h_pos->Draw();
  h_pos->Draw("hist same");
  func.Draw("same");
  save_name = "output/data/plots/"+directory+"/"+title_name+".pdf";
  c->SaveAs(save_name.c_str());
  h_pos->Write();
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
  gStyle->SetOptStat(0);
  const auto nThreads = thread::hardware_concurrency();
  /*ROOT::EnableThreadSafety();
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

  RooRealVar *DTF_Mass = new RooRealVar("DTF_Mass", "DTF_Mass", 2004.47, 2020.11);
  //RooRealVar *DTF_Mass_iso = new RooRealVar("DTF_Mass", "DTF_Mass_iso", 2012.5, 2021.);
  RooRealVar *Dst_ID_neg = new RooRealVar("Dst_ID", "Dst_ID_neg", -420., -400.);
  RooRealVar *Dst_ID_pos = new RooRealVar("Dst_ID", "Dst_ID_pos", 400., 420.);

  DTF_Mass->setRange("left", 2004.47, 2009.8);
  DTF_Mass->setRange("right", 2010.5, 2020.11);

  RooDataSet *dataset1 = new RooDataSet("dataset1", "dataset1", ntp, RooArgList(*DTF_Mass, *Dst_ID_neg));
  RooDataSet *dataset2 = new RooDataSet("dataset2", "dataset2", ntp, RooArgList(*DTF_Mass, *Dst_ID_pos));/*
  RooDataSet *dataset1b = new RooDataSet("dataset1b", "dataset1b", ntp, RooArgList(*DTF_Mass_iso, *Dst_ID_neg));
  RooDataSet *dataset2b = new RooDataSet("dataset2b", "dataset2b", ntp, RooArgList(*DTF_Mass_iso, *Dst_ID_pos));*/

  RooRealVar *N1;
  RooRealVar *a1;
  RooRealVar *c1;
  RooRealVar *b1;
  RooRealVar *N2;
  RooRealVar *a2;
  RooRealVar *c2;
  RooRealVar *b2;

  if(up)
  {
	N1 = new RooRealVar("N1", "N1", 200., 100., 10000.);
	a1 = new RooRealVar("a1", "a1", 2003.9, 2000. , 2004.47);
	b1 = new RooRealVar("b1", "b1", 1.3, 0.3, 4.5);
	c1 = new RooRealVar("c1", "c1", 0.05, 0., 0.5);
  }
  else
  {
	N1 = new RooRealVar("N1", "N1", 2122.54, 1800., 2500.);
	a1 = new RooRealVar("a1", "a1", 2003.9, 2000., 2004.47);
	b1 = new RooRealVar("b1", "b1", 1.3, 0.3, 4.5);
	c1 = new RooRealVar("c1", "c1", 0.053, 0.00001, 0.2);
  }
  if(up)
  {
	N2 = new RooRealVar("N2", "N2", 200., 100., 10000.);
	a2 = new RooRealVar("a2", "a2", 2003.9, 2000. , 2004.47);
	b2 = new RooRealVar("b2", "b2", 1.3, 0.3, 5.5);
	c2 = new RooRealVar("c2", "c2", 0.05, 0., 0.5);
  }
  else
  {
	N2 = new RooRealVar("N2", "N2", 1648.80, 1500., 2000.);
	a2 = new RooRealVar("a2", "a2", 2003.9, 2000. , 2004.47);
	b2 = new RooRealVar("b2", "b2", 1.3, 0.3, 5.5);
	c2 = new RooRealVar("c2", "c2", 0.09, 0.00001, 0.2);
  }
  RooRealVar *mean = new RooRealVar("mean", "mean", 2010., 2008., 2012.);
  RooRealVar *sigma = new RooRealVar("sigma", "sigma", 0.31, 0.1, 1.);
  RooRealVar *mean2 = new RooRealVar("mean2", "mean2", 2010., 2008., 2012.);
  RooRealVar *sigma2 = new RooRealVar("sigma2", "sigma2", 0.31, 0.1, 1.);
  RooRealVar *sig_yield = (up)? new RooRealVar("sig_yield", "sig_yield_2", 1000000., 0., 1250000.): new RooRealVar("sig_yield", "sig_yield", 1000000., 0., 1600000.);
  RooRealVar *bkg_yield = new RooRealVar("bkg_yield", "bkg_yield", 280000., 0., 700000.);
  RooRealVar *sig_yield_2 = (up)? new RooRealVar("sig_yield_2", "sig_yield_2", 1000000., 0., 1250000.): new RooRealVar("sig_yield_2", "sig_yield_2", 1000000., 0., 1600000.);
  RooRealVar *bkg_yield_2 = new RooRealVar("bkg_yield_2", "bkg_yield_2", 280000., 0., 700000.);

  RooBreitWigner *sig_neg = new RooBreitWigner("sig_neg", "sig_neg", *DTF_Mass, *mean, *sigma);
  RooBreitWigner *sig_pos = new RooBreitWigner("sig_pos", "sig_pos", *DTF_Mass, *mean2, *sigma2);

//  RooGaussian *sig_neg = new RooGaussian("sig_neg", "sig_neg", *DTF_Mass, *mean, *sigma);
//  RooGaussian *sig_pos = new RooGaussian("sig_pos", "sig_pos", *DTF_Mass, *mean2, *sigma2);

  //RooAbsPdf *arg_neg = (up)? RooClassFactory::makePdfInstance("arg_neg", "pow(DTF_Mass-a1,b1)*exp(-c1*(DTF_Mass-a1))", RooArgSet(*DTF_Mass, *a1, *b1, *c1))
  //RooAbsPdf *arg_neg =  RooClassFactory::makePdfInstance("arg_neg", "N1*pow(DTF_Mass-a1,b1)*exp(-c1*(DTF_Mass-a1))", RooArgSet(*DTF_Mass, *N1, *a1, *b1, *c1));
  RooAbsPdf *arg_neg =  RooClassFactory::makePdfInstance("arg_neg", "pow(DTF_Mass-a1,b1)", RooArgSet(*DTF_Mass, *a1, *b1));
  //RooAbsPdf *arg_pos = (up)? RooClassFactory::makePdfInstance("arg_pos", "pow(DTF_Mass-a2,b2)*exp(-c2*(DTF_Mass-a2))", RooArgSet(*DTF_Mass, *a2, *b2, *c2))
  //RooAbsPdf *arg_pos =  RooClassFactory::makePdfInstance("arg_pos", "N2*pow(DTF_Mass-a2,b2)*exp(-c2*(DTF_Mass-a2))", RooArgSet(*DTF_Mass, *N2, *a2, *b2, *c2));
  RooAbsPdf *arg_pos =  RooClassFactory::makePdfInstance("arg_pos", "pow(DTF_Mass-a2,b2)", RooArgSet(*DTF_Mass, *a2, *b2));
  //RooAbsPdf *arg_neg = RooClassFactory::makePdfInstance("arg_neg", "pow(DTF_Mass-a1,b1)*exp(-c1*(DTF_Mass-a1))", RooArgSet(*DTF_Mass, *a1, *b1, *c1));
  //RooAbsPdf *arg_pos = RooClassFactory::makePdfInstance("arg_pos", "pow(DTF_Mass-a2,b2)*exp(-c2*(DTF_Mass-a2))", RooArgSet(*DTF_Mass, *a2, *b2, *c2));
  RooAddPdf *model_neg = new RooAddPdf("model_neg", "model_neg", RooArgList(*sig_neg, *arg_neg),RooArgList(*sig_yield, *bkg_yield));
  RooAddPdf *model_pos = new RooAddPdf("model_pos", "model_pos", RooArgList(*sig_pos, *arg_pos),RooArgList(*sig_yield_2, *bkg_yield_2));

  ROOT::EnableThreadSafety();
  RooAbsReal* nll_neg = (up)? model_neg->createNLL(*dataset1, Extended(), NumCPU(nThreads), Offset(true)) : model_neg->createNLL(*dataset1, Extended(), NumCPU(nThreads), SumCoefRange("left,right"));
  RooMinuit(*nll_neg).hesse();
  RooMinuit(*nll_neg).migrad();
  RooMinuit(*nll_neg).improve();
  RooMinuit(*nll_neg).hesse();
  RooMinuit(*nll_neg).optimizeConst(true);
  RooMinuit(*nll_neg).minos();
  //model_neg->fitTo(*dataset1, Extended(), NumCPU(nThreads), RooFit::PrintLevel(-1), RooFit::PrintEvalErrors(-1));
  RooStats::SPlot *sData = new RooStats::SPlot("sData", "An SPlot", *dataset1, model_neg, RooArgList(*sig_yield, *bkg_yield));
  RooAbsReal* nll_pos = (up)? model_pos->createNLL(*dataset2, Extended(), NumCPU(nThreads), Offset(true)) : model_pos->createNLL(*dataset2, Extended(), NumCPU(nThreads), SumCoefRange("left,right"));
  RooMinuit(*nll_pos).hesse();
  RooMinuit(*nll_pos).migrad();
  RooMinuit(*nll_pos).improve();
  RooMinuit(*nll_pos).hesse();
  RooMinuit(*nll_pos).optimizeConst(true);
  RooMinuit(*nll_pos).minos();
  //model_pos->fitTo(*dataset2, Extended(), NumCPU(nThreads), RooFit::PrintLevel(-1), RooFit::PrintEvalErrors(-1));
  RooStats::SPlot *sData2 = new RooStats::SPlot("sData2", "An SPlot2", *dataset2, model_pos, RooArgList(*sig_yield_2, *bkg_yield_2));

  TFile *f = (up)? new TFile("output/histOut_minisample_Dst2D0pi_D02Kpi_2016_Up_GEN.root"): new TFile("output/histOut_minisample_Dst2D0pi_D02Kpi_2016_Dw_GEN.root");

  TH1F *h_Dst_pT_MC = (TH1F*)f->Get("h_pT_Dst");
  double nMCEvents = h_Dst_pT_MC->GetEntries();
  h_Dst_pT_MC->Scale(1./nMCEvents);
  h_Dst_pT_MC->SetLineColor(kAzure);

  TH1F *h_Dst_DTF_pos = new TH1F("h_Dst_DTF_pos", ";DTF Mass/MeV; Event", 30, 2005., 2020.);
  TH1F *h_Dst_DTF_neg = new TH1F("h_Dst_DTF_neg", ";DsTF Mass/MeV; Event", 30, 2005., 2020.);
  TH1F *h_Dst_DTF_pos_sw = new TH1F("h_Dst_DTF_pos_sw", ";DTF Mass/MeV; Event", 30, 2005., 2020.);
  TH1F *h_Dst_DTF_neg_sw = new TH1F("h_Dst_DTF_neg_sw", ";DsTF Mass/MeV; Event", 30, 2005., 2020.);

  TH1F *h_Dst_pT_data_neg = new TH1F("h_Dst_pT_data_neg", ";Dst pT/MeV; Event", 22, 2000., 10800.);
  TH1F *h_Dst_pT_data_pos = new TH1F("h_Dst_pT_data_pos", ";Dst pT/MeV; Event", 22, 2000., 10800.);
  TH1F *h_Dst_pT_data_neg_sw = new TH1F("h_Dst_pT_data_neg_sw", ";Dst pT/MeV; Event", 22, 2000., 10800.);
  TH1F *h_Dst_pT_data_pos_sw = new TH1F("h_Dst_pT_data_pos_sw", ";Dst pT/MeV; Event", 22, 2000., 10800.);

  TH1F *h_Dst_pT_data = new TH1F("h_Dst_pT_data", ";Dst pT/MeV; Event", 180, 2000., 11000.);
  TH1F *h_Dst_pT_data_sw = new TH1F("h_Dst_pT_data_sw", ";Dst pT/MeV; Event", 180, 2000., 11000.);
  TH1F *h_Dst_pT_data_nw = new TH1F("h_Dst_pT_data_nw", ";Dst pT/MeV; Event", 180, 2000., 11000.);
  TH2F *h_Dst_eta_phi_plane_pos = new TH2F("h_Dst_eta_phi_plane_pos", "; #phi; #eta", 35, -3.5, 3.5, 30, 2.5, 4.0);
  TH2F *h_Dst_eta_phi_plane_neg = new TH2F("h_Dst_eta_phi_plane_neg", "; #phi; #eta", 35, -3.5, 3.5, 30, 2.5, 4.0);


  TH1F *h_phi_Dst_neg = new TH1F("h_phi_Dst_neg", ";#phi;Events", 35, -3.5, 3.5);
  TH1F *h_phi_Dst_pos = new TH1F("h_phi_Dst_pos", ";#phi;Events", 35, -3.5, 3.5);
  TH1F *h_phi_Dst_neg_sw = new TH1F("h_phi_Dst_neg_sw", ";#phi;Events", 35, -3.5, 3.5);
  TH1F *h_phi_Dst_pos_sw = new TH1F("h_phi_Dst_pos_sw", ";#phi;Events", 35, -3.5, 3.5);

  TH1F *h_D0_M_pos = new TH1F("h_D0_M_pos",";D0 mass/MeV", 48, 1840., 1888.);
  TH1F *h_D0_M_neg = new TH1F("h_D0_M_neg",";D0 mass/MeV", 48, 1840., 1888.);
  TH1F *h_D0_M_pos_sw = new TH1F("h_D0_M_pos_sw",";D0 mass/MeV", 48, 1840., 1888.);
  TH1F *h_D0_M_neg_sw = new TH1F("h_D0_M_neg_sw",";D0 mass/MeV", 48, 1840., 1888.);

  h_D0_M_pos->Sumw2();
  h_D0_M_neg->Sumw2();
  h_D0_M_pos_sw->Sumw2();
  h_D0_M_neg_sw->Sumw2();
  h_phi_Dst_neg->Sumw2();
  h_phi_Dst_pos->Sumw2();
  h_phi_Dst_neg_sw->Sumw2();
  h_phi_Dst_pos_sw->Sumw2();
  h_Dst_DTF_pos_sw->Sumw2();
  h_Dst_DTF_neg_sw->Sumw2();
  h_Dst_DTF_pos->Sumw2();
  h_Dst_DTF_neg->Sumw2();
  h_Dst_pT_data->Sumw2();
  h_Dst_pT_data_sw->Sumw2();
  h_Dst_pT_data_nw->Sumw2();
  
  h_Dst_pT_data_neg->Sumw2();
  h_Dst_pT_data_neg_sw->Sumw2();
  h_Dst_pT_data_pos->Sumw2();
  h_Dst_pT_data_pos_sw->Sumw2();

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
      h_Dst_pT_data_sw->Fill(Dst_pT, sData->GetSWeight(i_neg, "sig_yield"));

      h_Dst_pT_data_neg->Fill(Dst_pT);
      h_Dst_pT_data_neg_sw->Fill(Dst_pT, sData->GetSWeight(i_neg, "sig_yield"));

      h_Dst_DTF_neg_sw->Fill(DTF_mass, sData->GetSWeight(i_neg, "sig_yield"));
      h_Dst_DTF_neg->Fill(DTF_mass);

      h_phi_Dst_neg_sw->Fill(Dst_phi, sData->GetSWeight(i_neg, "sig_yield"));
      h_phi_Dst_neg->Fill(Dst_phi);

      h_D0_M_neg_sw->Fill(D0_mass, sData->GetSWeight(i_neg, "sig_yield"));
      h_D0_M_neg->Fill(D0_mass);

      h_Dst_eta_phi_plane_neg->Fill(Dst_phi, Dst_eta, sData->GetSWeight(i_neg, "sig_yield"));
      ++i_neg;
    }
    else
    {
      h_Dst_pT_data->Fill(Dst_pT, sData2->GetSumOfEventSWeight(i_pos));
      h_Dst_pT_data_sw->Fill(Dst_pT, sData2->GetSWeight(i_pos, "sig_yield_2"));

      h_Dst_pT_data_pos->Fill(Dst_pT);
      h_Dst_pT_data_pos_sw->Fill(Dst_pT, sData2->GetSWeight(i_pos, "sig_yield_2"));

      h_Dst_DTF_pos_sw->Fill(DTF_mass, sData2->GetSWeight(i_pos, "sig_yield_2"));
      h_Dst_DTF_pos->Fill(DTF_mass);

      h_phi_Dst_pos_sw->Fill(Dst_phi, sData2->GetSWeight(i_pos, "sig_yield_2"));
      h_phi_Dst_pos->Fill(Dst_phi);

      h_D0_M_pos_sw->Fill(D0_mass, sData2->GetSWeight(i_pos, "sig_yield_2"));
      h_D0_M_pos->Fill(D0_mass);

      h_Dst_eta_phi_plane_pos->Fill(Dst_phi, Dst_eta, sData2->GetSWeight(i_pos, "sig_yield_2"));
      ++i_pos;
    }
    h_Dst_pT_data_nw->Fill(Dst_pT);
  }


  double nDataEvents = h_Dst_pT_data->GetSumOfWeights();
  h_Dst_pT_data->Scale(1./nDataEvents);
  h_Dst_pT_data_nw->Scale(1./h_Dst_pT_data_nw->GetEntries());
  h_Dst_pT_data_sw->Scale(1./h_Dst_pT_data_sw->GetSumOfWeights());
  h_Dst_pT_data->SetLineColor(kRed);
  h_Dst_pT_data_nw->SetLineColor(kBlack);
  h_Dst_pT_data_sw->SetLineColor(kGreen);

  TCanvas *canvas2 = new TCanvas();
  RooPlot *frame = DTF_Mass->frame();
  RooPlot *frame2 = DTF_Mass->frame();
  model_neg->plotOn(frame, Range(2004.47, 2020.11));
  model_neg->plotOn(frame, Range(2004.47, 2020.11), RooFit::Components("arg_neg"), RooFit::FillColor(kRed), RooFit::LineStyle(kDashed),RooFit::DrawOption("f"));
  

  frame->Draw();
  if(up) canvas2->SaveAs("output/data/plots/up/model.pdf");
  else canvas2->SaveAs("output/data/plots/down/model.pdf");


  dataset1->plotOn(frame);
  model_neg->plotOn(frame, Range(2004.47, 2020.11));
  model_neg->plotOn(frame, Range(2004.47, 2020.11), RooFit::Components("arg_neg"), RooFit::FillColor(kRed), RooFit::LineStyle(kDashed),RooFit::DrawOption("f") );
  model_neg->paramOn(frame, Layout(0.45, 1., 0.9), Format("NEU", AutoPrecision(1)));
  frame->Draw();
  if(up) canvas2->SaveAs("output/data/plots/up/model_data.pdf");
  else canvas2->SaveAs("output/data/plots/down/model_data.pdf");

  model_pos->plotOn(frame2, Range(2004.47, 2020.11));
  model_pos->plotOn(frame2, Range(2004.47, 2020.11), RooFit::Components("arg_neg"), RooFit::FillColor(kRed), RooFit::LineStyle(kDashed),RooFit::DrawOption("f") );

  frame2->Draw();
  if(up) canvas2->SaveAs("output/data/plots/up/model_pos.pdf");
  else canvas2->SaveAs("output/data/plots/down/model_pos.pdf");


  dataset2->plotOn(frame2);
  model_pos->plotOn(frame2, Range(2004.47, 2020.11));
  model_pos->plotOn(frame2, Range(2004.47, 2020.11), RooFit::Components("arg_neg"), RooFit::FillColor(kRed), RooFit::LineStyle(kDashed),RooFit::DrawOption("f") );
  model_pos->paramOn(frame2, Layout(0.45, 1., 0.9), Format("NEU", AutoPrecision(1)));
  frame2->Draw();
  if(up) canvas2->SaveAs("output/data/plots/up/model_data_pos.pdf");
  else canvas2->SaveAs("output/data/plots/down/model_data_pos.pdf");


  h_Dst_pT_MC->Draw();
  h_Dst_pT_MC->Draw("hist same");
  h_Dst_pT_data->Draw("same");
  h_Dst_pT_data->Draw("hist same");
  h_Dst_pT_data_nw->Draw("same");
  h_Dst_pT_data_nw->Draw("hist same");
  h_Dst_pT_data_sw->Draw("same");
  h_Dst_pT_data_sw->Draw("hist same");
  if(up) canvas2->SaveAs("output/data/plots/up/MC_data_comp.pdf");
  else canvas2->SaveAs("output/data/plots/down/MC_data_comp.pdf");


  h_Dst_eta_phi_plane_pos->Add(h_Dst_eta_phi_plane_neg, -1.);
  h_Dst_eta_phi_plane_neg->Scale(2.);
  h_Dst_eta_phi_plane_neg->Add(h_Dst_eta_phi_plane_pos);
  h_Dst_eta_phi_plane_pos->Divide(h_Dst_eta_phi_plane_neg);
  h_Dst_eta_phi_plane_pos->Draw("SURF4 FB");
  if(up) canvas2->SaveAs("output/data/plots/up/eta_phi_plane.pdf");
  else canvas2->SaveAs("output/data/plots/down/eta_phi_plane.pdf");

  double nPos = h_Dst_DTF_pos->GetSumOfWeights();
  double nPosSW = h_Dst_pT_data_pos_sw->GetSumOfWeights();
  double nNeg = h_Dst_DTF_neg->GetSumOfWeights();
  double nNegSW = h_Dst_pT_data_neg_sw->GetSumOfWeights();
  double asym = (nPos - nNeg)/(nPos + nNeg);
  double asymSW = (nPosSW - nNegSW)/(nPosSW + nNegSW);
  double err = nPos * nNeg / pow(nPos + nNeg, 3.); err = 2 * sqrt(err);
  double errSW = nPosSW * nNegSW / pow(nPosSW + nNegSW, 3.); err = 2 * sqrt(errSW);


  string output_hist_name;
  output_hist_name = "output/histOut_"+sample+".root";
  TFile *out_hist_fi = new TFile(output_hist_name.c_str(),"RECREATE");

  printdevhists(h_Dst_DTF_pos, h_Dst_DTF_neg, pol, "DTF", false);
  printdevhists(h_Dst_DTF_pos_sw, h_Dst_DTF_neg_sw, pol, "DTF_sw", true);

  printdevhists(h_phi_Dst_pos, h_phi_Dst_neg, pol, "phi", false);
  printdevhists(h_phi_Dst_pos_sw, h_phi_Dst_neg_sw, pol, "phi_sw", true);

  printdevhists(h_D0_M_pos, h_D0_M_neg, pol, "D0m", false);
  printdevhists(h_D0_M_pos_sw, h_D0_M_neg_sw, pol, "D0m_sw", true);

  printdevhists(h_Dst_pT_data_pos, h_Dst_pT_data_neg, pol, "pT", true);
  printdevhists(h_Dst_pT_data_pos_sw, h_Dst_pT_data_neg_sw, pol, "pT_sw", true);

  h_Dst_eta_phi_plane_pos->Write();
  out_hist_fi->Write();
  out_hist_fi->Close();

  cout << "Total asymmetry before weighting: " << asym << " +/- " << err << endl;
  cout << "Total asymmetry after signal weighting: " << asymSW << " +/- " << errSW << endl;

  uint64_t end_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
  float elapsed = (end_time - start_time)*0.000001;
  std::cout << "computation time/s: " << elapsed << std::endl;
  std::cout << "computation time/min: " << elapsed/60. << std::endl;
}
