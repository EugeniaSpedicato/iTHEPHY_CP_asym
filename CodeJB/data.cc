#pragma
#include "eff.h"
#include <chrono>
#include <fstream>
#include <thread>
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
#include "RooMinuit.h"
using namespace RooFit;

void printdevhists(TH1F *h_pos, TH1F *h_neg, string polarisation, string var, bool weighted)
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
  title_name = "h_Dst_asym"+var;
  h_pos->SetName(title_name.c_str());
  h_pos->SetAxisRange(-0.1, 0.1, "Y");
  h_pos->Draw();
  h_pos->Draw("hist same");
  func.Draw("same");
  if(weighted) save_name = "output/data/plots/"+directory+"/"+title_name+"w.pdf";
  else save_name = "output/data/plots/"+directory+"/"+title_name+".pdf";
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

  RooRealVar *DTF_Mass = new RooRealVar("DTF_Mass", "DTF_Mass", 2004., 2021.);
  //RooRealVar *DTF_Mass_iso = new RooRealVar("DTF_Mass", "DTF_Mass_iso", 2012.5, 2021.);
  RooRealVar *Dst_ID_neg = new RooRealVar("Dst_ID", "Dst_ID_neg", -420., -400.);
  RooRealVar *Dst_ID_pos = new RooRealVar("Dst_ID", "Dst_ID_pos", 400., 420.);

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
	N1 = new RooRealVar("N1", "N1", 0.005, 0.000001, 0.01);
	a1 = new RooRealVar("a1", "a1", 2004., 2000. , 2010.);
	c1 = new RooRealVar("c1", "c1", 0.05, 0., 0.3);
	b1 = new RooRealVar("b1", "b1", 0.681, 0.3, 2.);  
  }
  else
  {
	N1 = new RooRealVar("N1", "N1", 0.002, 0., 0.01);
	a1 = new RooRealVar("a1", "a1", 2003.9, 2002. , 2008.);
	c1 = new RooRealVar("c1", "c1", 0.05, 0., 0.5);
	b1 = new RooRealVar("b1", "b1", 0.681, 0., 2.);
  }
  if(up)
  {
	N2 = new RooRealVar("N2", "N2", 0.005, 0.000001, 0.01);
	a2 = new RooRealVar("a2", "a2", 2004., 2000. , 2010.);
	c2 = new RooRealVar("c2", "c2", 0.05, 0., 0.3);
	b2 = new RooRealVar("b2", "b2", 0.681, 0.3, 1.8);  
  }
  else
  {
	N2 = new RooRealVar("N2", "N2", 0.005, 0., 0.03);
	a2 = new RooRealVar("a2", "a2", 2004., 2000. , 2008.);
	c2 = new RooRealVar("c2", "c2", 0.05, 0., 0.5);
	b2 = new RooRealVar("b2", "b2", 0.681, 0., 2.);
  }
  RooRealVar *mean = new RooRealVar("mean", "mean", 2010., 2008., 2012.);
  RooRealVar *sigma = new RooRealVar("sigma", "sigma", 0.31, 0., 1.);
  RooRealVar *mean2 = new RooRealVar("mean2", "mean2", 2010., 2008., 2012.);
  RooRealVar *sigma2 = new RooRealVar("sigma2", "sigma2", 0.31, 0., 1.);
  RooRealVar *sig_yield = (up)? new RooRealVar("sig_yield", "sig_yield_2", 1000000., 700000., 1250000.): new RooRealVar("sig_yield", "sig_yield", 1400000., 1000000., 1650000.);
  RooRealVar *bkg_yield = new RooRealVar("bkg_yield", "bkg_yield", 280000., 100000., 450000.);
  RooRealVar *sig_yield_2 = (up)? new RooRealVar("sig_yield_2", "sig_yield_2", 1000000., 700000., 1250000.): new RooRealVar("sig_yield_2", "sig_yield_2", 1400000., 1000000., 1650000.);
  RooRealVar *bkg_yield_2 = new RooRealVar("bkg_yield_2", "bkg_yield_2", 280000., 100000., 450000.);

  RooBreitWigner *sig_neg = new RooBreitWigner("sig_neg", "sig_neg", *DTF_Mass, *mean, *sigma);
  RooBreitWigner *sig_pos = new RooBreitWigner("sig_pos", "sig_pos", *DTF_Mass, *mean2, *sigma2);
  RooAbsPdf *arg_neg = RooClassFactory::makePdfInstance("arg_neg", "1./N1*pow(DTF_Mass-a1,b1)*exp(-c1*(DTF_Mass-a1))", RooArgSet(*DTF_Mass, *N1, *a1, *b1, *c1));
  RooAbsPdf *arg_pos = RooClassFactory::makePdfInstance("arg_pos", "1./N2*pow(DTF_Mass-a2,b2)*exp(-c2*(DTF_Mass-a2))", RooArgSet(*DTF_Mass, *N2, *a2, *b2, *c2));
  RooAddPdf *model_neg = new RooAddPdf("model_neg", "model_neg", RooArgList(*sig_neg, *arg_neg),RooArgList(*sig_yield, *bkg_yield));
  RooAddPdf *model_pos = new RooAddPdf("model_pos", "model_pos", RooArgList(*sig_pos, *arg_pos),RooArgList(*sig_yield_2, *bkg_yield_2));

  ROOT::EnableThreadSafety();
  RooAbsReal* nll_neg = model_neg->createNLL(*dataset1, Extended(), NumCPU(nThreads,2), RooFit::PrintLevel(-1), RooFit::PrintEvalErrors(-1), Offset(true));
  RooMinuit(*nll_neg).migrad();
  RooStats::SPlot *sData = new RooStats::SPlot("sData", "An SPlot", *dataset1, model_neg, RooArgList(*sig_yield, *bkg_yield));
  RooAbsReal* nll_pos = model_pos->createNLL(*dataset2, Extended(), NumCPU(nThreads,2), RooFit::PrintLevel(-1), RooFit::PrintEvalErrors(-1), Offset(true));
  RooMinuit(*nll_pos).migrad();
  //model_pos->fitTo(*dataset2, Extended(), RooFit::PrintLevel(-1), RooFit::PrintEvalErrors(-1));
  RooStats::SPlot *sData2 = new RooStats::SPlot("sData2", "An SPlot2", *dataset2, model_pos, RooArgList(*sig_yield_2, *bkg_yield_2));

  TFile *f = (up)? new TFile("output/histOut_minisample_Dst2D0pi_D02Kpi_2016_Up_GEN.root"): new TFile("output/histOut_minisample_Dst2D0pi_D02Kpi_2016_Dw_GEN.root");

  TH1F *h_Dst_pT_MC = (TH1F*)f->Get("h_pT_Dst");
  double nMCEvents = h_Dst_pT_MC->GetEntries();
  h_Dst_pT_MC->Scale(1./nMCEvents);
  h_Dst_pT_MC->SetLineColor(kAzure);

  TH1F *h_Dst_DTF_pos = new TH1F("h_Dst_DTF_pos", ";DTF Mass/MeV; Event", 34, 2004., 2021.);
  TH1F *h_Dst_DTF_neg = new TH1F("h_Dst_DTF_neg", ";DsTF Mass/MeV; Event", 34, 2004., 2021.);
  TH1F *h_Dst_DTF_pos_w = new TH1F("h_Dst_DTF_pos_w", ";DTF Mass/MeV; Event", 34, 2004., 2021.);
  TH1F *h_Dst_DTF_neg_w = new TH1F("h_Dst_DTF_neg_w", ";DsTF Mass/MeV; Event", 34, 2004., 2021.);
  TH1F *h_Dst_DTF_pos_sw = new TH1F("h_Dst_DTF_pos_sw", ";DTF Mass/MeV; Event", 34, 2004., 2021.);
  TH1F *h_Dst_DTF_neg_sw = new TH1F("h_Dst_DTF_neg_sw", ";DsTF Mass/MeV; Event", 34, 2004., 2021.);

  TH1F *h_Dst_pT_data_neg_w = new TH1F("h_Dst_pT_data_neg_w", ";Dst pT/MeV; Event", 45, 2000., 11000.);
  TH1F *h_Dst_pT_data_pos_w = new TH1F("h_Dst_pT_data_pos_w", ";Dst pT/MeV; Event", 45, 2000., 11000.);
  TH1F *h_Dst_pT_data_neg_sw = new TH1F("h_Dst_pT_data_neg_sw", ";Dst pT/MeV; Event", 45, 2000., 11000.);
  TH1F *h_Dst_pT_data_pos_sw = new TH1F("h_Dst_pT_data_pos_sw", ";Dst pT/MeV; Event", 45, 2000., 11000.);
 
  TH1F *h_Dst_pT_data = new TH1F("h_Dst_pT_data", ";Dst pT/MeV; Event", 180, 2000., 11000.);
  TH1F *h_Dst_pT_data_sw = new TH1F("h_Dst_pT_data_sw", ";Dst pT/MeV; Event", 180, 2000., 11000.);
  TH1F *h_Dst_pT_data_nw = new TH1F("h_Dst_pT_data_nw", ";Dst pT/MeV; Event", 180, 2000., 11000.);
  TH2F *h_Dst_eta_phi_plane_pos = new TH2F("h_Dst_eta_phi_plane_pos", "; #phi; #eta", 70, -3.5, 3.5, 30, 2.5, 4.0);
  TH2F *h_Dst_eta_phi_plane_neg = new TH2F("h_Dst_eta_phi_plane_neg", "; #phi; #eta", 70, -3.5, 3.5, 30, 2.5, 4.0);


  TH1F *h_phi_Dst_neg = new TH1F("h_phi_Dst_neg", ";#phi;Events", 70, -3.5, 3.5);
  TH1F *h_phi_Dst_pos = new TH1F("h_phi_Dst_pos", ";#phi;Events", 70, -3.5, 3.5);
  TH1F *h_phi_Dst_neg_w = new TH1F("h_phi_Dst_neg_w", ";#phi;Events", 70, -3.5, 3.5);
  TH1F *h_phi_Dst_pos_w = new TH1F("h_phi_Dst_pos_w", ";#phi;Events", 70, -3.5, 3.5);
  TH1F *h_phi_Dst_neg_sw = new TH1F("h_phi_Dst_neg_sw", ";#phi;Events", 70, -3.5, 3.5);
  TH1F *h_phi_Dst_pos_sw = new TH1F("h_phi_Dst_pos_sw", ";#phi;Events", 70, -3.5, 3.5);

  TH1F *h_D0_M_pos = new TH1F("h_D0_M_pos",";D0 mass/MeV", 96, 1840., 1888.);
  TH1F *h_D0_M_neg = new TH1F("h_D0_M_neg",";D0 mass/MeV", 96, 1840., 1888.);
  TH1F *h_D0_M_pos_w = new TH1F("h_D0_M_pos_w",";D0 mass/MeV", 96, 1840., 1888.);
  TH1F *h_D0_M_neg_w = new TH1F("h_D0_M_neg_w",";D0 mass/MeV", 96, 1840., 1888.);
  TH1F *h_D0_M_pos_sw = new TH1F("h_D0_M_pos_sw",";D0 mass/MeV", 96, 1840., 1888.);
  TH1F *h_D0_M_neg_sw = new TH1F("h_D0_M_neg_sw",";D0 mass/MeV", 96, 1840., 1888.);

  h_phi_Dst_neg->Sumw2();
  h_phi_Dst_pos->Sumw2();
  h_phi_Dst_neg_w->Sumw2();
  h_phi_Dst_pos_w->Sumw2();
  h_phi_Dst_neg_sw->Sumw2();
  h_phi_Dst_pos_sw->Sumw2();
  h_Dst_DTF_pos_w->Sumw2();
  h_Dst_DTF_neg_w->Sumw2();
  h_Dst_DTF_pos_sw->Sumw2();
  h_Dst_DTF_neg_sw->Sumw2();
  h_Dst_DTF_pos->Sumw2();
  h_Dst_DTF_neg->Sumw2();
  h_Dst_pT_data->Sumw2();
  h_Dst_pT_data_sw->Sumw2();
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
      h_Dst_pT_data_sw->Fill(Dst_pT, sData->GetSWeight(i_neg, "sig_yield"));
      
      h_Dst_pT_data_neg_w->Fill(Dst_pT, sData->GetSumOfEventSWeight(i_neg));
      h_Dst_pT_data_neg_sw->Fill(Dst_pT, sData->GetSWeight(i_neg, "sig_yield"));
      
      h_Dst_DTF_neg_w->Fill(DTF_mass, sData->GetSumOfEventSWeight(i_neg));
      h_Dst_DTF_neg_sw->Fill(DTF_mass, sData->GetSWeight(i_neg, "sig_yield"));
      h_Dst_DTF_neg->Fill(DTF_mass);

      h_phi_Dst_neg_w->Fill(Dst_phi, sData->GetSumOfEventSWeight(i_neg));
      h_phi_Dst_neg_sw->Fill(Dst_phi, sData->GetSWeight(i_neg, "sig_yield"));
      h_phi_Dst_neg->Fill(Dst_phi);
      
      h_D0_M_neg_w->Fill(D0_mass, sData->GetSumOfEventSWeight(i_neg));
      h_D0_M_neg_sw->Fill(D0_mass, sData->GetSWeight(i_neg, "sig_yield"));
      h_D0_M_neg->Fill(D0_mass);
      
      h_Dst_eta_phi_plane_neg->Fill(Dst_phi, Dst_eta, sData->GetSWeight(i_neg, "sig_yield"));
      ++i_neg;
    }
    else
    {
      h_Dst_pT_data->Fill(Dst_pT, sData2->GetSumOfEventSWeight(i_pos));
      h_Dst_pT_data_sw->Fill(Dst_pT, sData2->GetSWeight(i_pos, "sig_yield_2"));
      
      h_Dst_pT_data_pos_w->Fill(Dst_pT, sData2->GetSumOfEventSWeight(i_pos));
      h_Dst_pT_data_pos_sw->Fill(Dst_pT, sData2->GetSWeight(i_pos, "sig_yield_2"));
      
      h_Dst_DTF_pos_w->Fill(DTF_mass, sData2->GetSumOfEventSWeight(i_pos));
      h_Dst_DTF_pos_sw->Fill(DTF_mass, sData2->GetSWeight(i_pos, "sig_yield_2"));
      h_Dst_DTF_pos->Fill(DTF_mass);

      h_phi_Dst_pos_w->Fill(Dst_phi, sData2->GetSumOfEventSWeight(i_pos));
      h_phi_Dst_pos_sw->Fill(Dst_phi, sData2->GetSWeight(i_pos, "sig_yield_2"));
      h_phi_Dst_pos->Fill(Dst_phi);
      
      h_D0_M_pos_w->Fill(D0_mass, sData2->GetSumOfEventSWeight(i_pos));
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
  model_neg->plotOn(frame);
  model_neg->plotOn(frame, Components("arg_neg"), FillStyle(2), FillColor(kRed), DrawOption("F"));
  
  frame->Draw();
  if(up) canvas2->SaveAs("output/data/plots/up/model.pdf");
  else canvas2->SaveAs("output/data/plots/down/model.pdf");
  
 
  dataset1->plotOn(frame);
  model_neg->plotOn(frame);
  model_neg->plotOn(frame, Components("arg_neg"), FillColor(kRed), DrawOption("F"));
  model_neg->paramOn(frame, Layout(0.45, 1., 0.9), Format("NEU", AutoPrecision(1)));
  frame->Draw();
  if(up) canvas2->SaveAs("output/data/plots/up/model_data.pdf");
  else canvas2->SaveAs("output/data/plots/down/model_data.pdf");
  
  model_pos->plotOn(frame2);
  model_pos->plotOn(frame2, Components("arg_pos"), FillStyle(2), FillColor(kRed), DrawOption("F"));

  frame2->Draw();
  if(up) canvas2->SaveAs("output/data/plots/up/model_pos.pdf");
  else canvas2->SaveAs("output/data/plots/down/model_pos.pdf");
 
  
  dataset2->plotOn(frame2);
  model_pos->plotOn(frame2);
  model_pos->plotOn(frame2, Components("arg_pos"), FillStyle(2), FillColor(kRed), DrawOption("F"));
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
  double nPosW = h_Dst_pT_data_pos_w->GetSumOfWeights();
  double nPosSW = h_Dst_pT_data_pos_sw->GetSumOfWeights();
  double nNeg = h_Dst_DTF_neg->GetSumOfWeights();
  double nNegW = h_Dst_pT_data_neg_w->GetSumOfWeights();
  double nNegSW = h_Dst_pT_data_neg_sw->GetSumOfWeights();
  double asym = (nPos - nNeg)/(nPos + nNeg);
  double asymW = (nPosW - nNegW)/(nPosW + nNegW);
  double asymSW = (nPosSW - nNegSW)/(nPosSW + nNegSW);
  double err = 2./pow(nPos + nNeg, 2.)*sqrt((pow(nPos,3.)+pow(nNeg, 3.))/(nPos * nNeg));
  double errW = 2./pow(nPosW + nNegW, 2.)*sqrt((pow(nPosW,3.)+pow(nNegW, 3.))/(nPosW * nNegW));
  double errSW = 2./pow(nPosSW + nNegSW, 2.)*sqrt((pow(nPosSW,3.)+pow(nNegSW, 3.))/(nPosSW * nNegSW));


  string output_hist_name;
  output_hist_name = "output/histOut_"+sample+".root";
  TFile *out_hist_fi = new TFile(output_hist_name.c_str(),"RECREATE");

  printdevhists(h_Dst_DTF_pos, h_Dst_DTF_neg, pol, "DTF", false);
  printdevhists(h_Dst_DTF_pos_w, h_Dst_DTF_neg_w, pol, "DTF_", true);
  printdevhists(h_Dst_DTF_pos_sw, h_Dst_DTF_neg_sw, pol, "DTF_s", true);

  printdevhists(h_phi_Dst_pos, h_phi_Dst_neg, pol, "phi", false);
  printdevhists(h_phi_Dst_pos_w, h_phi_Dst_neg_w, pol, "phi_", true);
  printdevhists(h_phi_Dst_pos_sw, h_phi_Dst_neg_sw, pol, "phi_s", true);
  
  printdevhists(h_D0_M_pos, h_D0_M_neg, pol, "D0m", false);
  printdevhists(h_D0_M_pos_w, h_D0_M_neg_w, pol, "D0m_", true);
  printdevhists(h_D0_M_pos_sw, h_D0_M_neg_sw, pol, "D0m_s", true);
  
  printdevhists(h_Dst_pT_data_pos_w, h_Dst_pT_data_neg_w, pol, "pT_", true);
  printdevhists(h_Dst_pT_data_pos_sw, h_Dst_pT_data_neg_sw, pol, "pT_s", true);

  h_Dst_eta_phi_plane_pos->Write();
  out_hist_fi->Write();
  out_hist_fi->Close();

  cout << "Total asymmetry before weighting: " << asym << " +/- " << err << endl;
  cout << "Total asymmetry after weighting: " << asymW << " +/- " << errW << endl;
  cout << "Total asymmetry after signal weighting: " << asymSW << " +/- " << errSW << endl;

  uint64_t end_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
  float elapsed = (end_time - start_time)*0.000001;
  std::cout << "computation time/s: " << elapsed << std::endl;
  std::cout << "computation time/min: " << elapsed/60. << std::endl;
}
