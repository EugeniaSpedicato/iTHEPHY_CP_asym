#include "eff.h"
#include <chrono>
#include "RooBreitWigner.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooPlot.h"
#include "RooFit.h"
#include "RooAddPdf.h"
#include "RooUniform.h"
#include "RooArgusBG.h"
#include "RooGaussian.h"
#include "RooPolynomial.h"
#include <fstream>
#include "RooClassFactory.h"
#include "RooWorkspace.h"
#include "RooExtendPdf.h"
#include "TROOT.h"
#include "TThread.h"
#include <Riostream.h>
#include <thread>
#include "RooRealVar.h"
#include "RooStats/SPlot.h"
#include "RooRealVar.h"
#include "RooProdPdf.h"
#include "RooAddition.h"
#include "RooProduct.h"
#include "RooAbsPdf.h"
#include "RooFitResult.h"
#include "RooWorkspace.h"
#include "RooConstVar.h"
#include <iomanip>
using namespace RooFit;

void printhists(TH1F *h)
{
  TCanvas *c = new TCanvas();
  h->Draw();
  h->Draw("hist same");
  string title_name = h->GetName();
  string save_name = "output/data/plots/"+title_name+".pdf";
  c->SaveAs(save_name.c_str());
}

void data(string dir, string sample)
{
  /*ROOT::EnableThreadSafety();
  const auto nThreads = thread::hardware_concurrency();
  ROOT::EnableImplicitMT(nThreads);*/
  uint64_t start_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
  string input_name = dir+"/"+sample+".root";
  TChain *ntp = new TChain();
  ntp->AddFile(input_name.c_str(),-1,"ntp;25");
  ntp->AddFile(input_name.c_str(),-1,"ntp;26");
  int nEvents = ntp->GetEntries();



  double nDst_pos = 0.; double nDst_neg = 0.;
  int Dst_ID, D0_ID, Pi_ID, K_ID;
  double D0_mass;
  double DTF_mass;
  double Dst_pT;


  ntp->SetBranchStatus("*",0);
  ntp->SetBranchStatus("D0_M",1); ntp->SetBranchAddress("D0_M", &(D0_mass));
  ntp->SetBranchStatus("DTF_Mass",1); ntp->SetBranchAddress("DTF_Mass", &(DTF_mass));
  ntp->SetBranchStatus("Dst_PT",1); ntp->SetBranchAddress("Dst_PT", &(Dst_pT));

  ntp->SetBranchStatus("Dst_ID",1); ntp->SetBranchAddress("Dst_ID", &(Dst_ID));
  ntp->SetBranchStatus("D0_ID",1); ntp->SetBranchAddress("D0_ID", &(D0_ID));
  ntp->SetBranchStatus("P1_ID",1); ntp->SetBranchAddress("P1_ID", &(Pi_ID));
  ntp->SetBranchStatus("P2_ID",1); ntp->SetBranchAddress("P2_ID", &(K_ID));
/*
  RooRealVar *rel_frac = new RooRealVar("rel_frac", "rel_frac", 0.5, 0., 1.);
  RooRealVar *N = new RooRealVar("N", "N", 0.0023, 0., 0.01);
  RooRealVar *a = new RooRealVar("a", "a", 2004., 2000., 2005.);
  RooRealVar *c = new RooRealVar("c", "c", 0.159, 0., 0.5);
  RooRealVar *b = new RooRealVar("b", "b", 1.125, 0., 2.);
  RooRealVar *mean = new RooRealVar("mean", "mean", 2010., 2008., 2012.);
  RooRealVar *sigma = new RooRealVar("sigma", "sigma", 0.3, 0., 1.);
  RooRealVar *sig_yield = new RooRealVar("sig_yield", "sig_yield", 50000., 0., 400000.);
  RooRealVar *bkg_yield = new RooRealVar("bkg_yield", "bkg_yield", 2000., 0., 20000.);
  RooRealVar *dtf = new RooRealVar("DTF_Mass", "DTF_Mass", 2004.5, 2020.5);
  RooRealVar *dtf_iso = new RooRealVar("DTF_Mass", "DTF_Mass", 2012.5, 2020.5);
  RooDataSet *dataset = new RooDataSet("dataset", "dataset", ntp, RooArgList(*dtf));

  RooBreitWigner *sig = new RooBreitWigner("sig", "sig", *dtf, *mean, *sigma);
  RooAbsPdf *arg = RooClassFactory::makePdfInstance("arg", "1./N*pow(DTF_Mass-a,b)*exp(-c*(DTF_Mass-a))", RooArgSet(*dtf, *N, *a, *b, *c));
  RooAddPdf *model = new RooAddPdf("model", "model", RooArgList(*sig, *arg),RooArgList(*sig_yield, *bkg_yield));

  model->fitTo(*dataset, Extended(), RooFit::PrintLevel(-1), RooFit::PrintEvalErrors(-1));
  RooStats::SPlot *sData = new RooStats::SPlot("sData", "An SPlot", *dataset, model, RooArgList(*sig_yield, *bkg_yield));

  TCanvas *cdata = new TCanvas("sPlot", "sPlot demo", 400, 600); cdata->Divide(1, 3);

  cdata->cd(1);
  RooPlot *frame = dtf->frame();
  dataset->plotOn(frame);
  model->plotOn(frame, Name("FullModel"));
  model->plotOn(frame, Components(*sig), LineStyle(kDashed), LineColor(kRed), Name("SigModel"));
  model->plotOn(frame, Components(*arg), LineStyle(kDashed), LineColor(kGreen), Name("BkgModel"));
  frame->Draw();

  cdata->cd(2);
  RooDataSet *dataw_s = new RooDataSet(dataset->GetName(), dataset->GetTitle(), dataset, *dataset->get(), 0, "sig_yield_sw");
  RooPlot *frame2 = dtf_iso->frame();
  dataw_s->plotOn(frame2, DataError(RooAbsData::SumW2));
  frame2->Draw();

  cdata->cd(3);
  RooDataSet *dataw_b = new RooDataSet(dataset->GetName(), dataset->GetTitle(), dataset, *dataset->get(), 0, "bkg_yield_sw");
  RooPlot *frame3 = dtf_iso->frame();
  dataw_b->plotOn(frame3, DataError(RooAbsData::SumW2));
  frame3->Draw();
  cdata->SaveAs("output/data/plots/sPlot.pdf");

  TFile f("./output/histOut_minisample_Dst2D0pi_D02Kpi_2016_Up_GEN.root");
  TH1F *h_Dst_pT_MC = (TH1F*)f.Get("h_pT_reco_Dst");
  double nMCEvents = h_Dst_pT_MC->GetEntries();
  h_Dst_pT_MC->Scale(1./nMCEvents);
  h_Dst_pT_MC->SetLineColor(kAzure);
  TH1F *h_Dst_pT_data = new TH1F("h_Dst_pT_data", ";Dst pT/MeV; Event", 148, 2200., 9600.);
  h_Dst_pT_data->Sumw2();

  //ofstream weightfile("output/data/weightfile.txt", ofstream::trunc);
  //weightfile << "nEvents: " << nEvents << "\n";

  for (int i = 0; i < nEvents-1; ++i)
  {
    if (i % (nEvents/10) == 0)
    {
      std::cout << "=== Event " << i/(nEvents/10) * 10 << "%" << std::endl;
    }
    ntp->GetEvent(i);
    //weightfile << i <<": Dst weight: " << sData->GetSWeight(i-1, "sig_yield") << " bkg weight: " << sData->GetSWeight(i-1, "bkg_yield") << "Total weight: " << sData->GetSWeight(i-1, "sig_yield") << "\n";
    h_Dst_pT_data->Fill(Dst_pT, sData->GetSumOfEventSWeight(i));
  }
  //weightfile.flush();
  //weightfile.close();
  double nDataEvents = h_Dst_pT_data->GetSumOfWeights();
  h_Dst_pT_data->Scale(1./nDataEvents);
  h_Dst_pT_data->SetLineColor(kRed);

  TCanvas *c1;
  h_Dst_pT_MC->Draw();
  h_Dst_pT_MC->Draw("hist same");
  h_Dst_pT_MC->Draw("same");
  h_Dst_pT_MC->Draw("hist same");
  c1->SaveAs("output/data/plots/data_MC_comp.pdf");*/

/*
  TH1F *h_Dst_pos_D0m = new TH1F("h_Dst_pos_D0m", ";invariant D0 mass/MeV; Events", 92, 1842., 1888.);
  TH1F *h_Dst_neg_D0m = new TH1F("h_Dst_neg_D0m", ";invariant D0 mass/MeV; Events", 92, 1842., 1888.);
  TH1F *h_Dst_asym_D0m = new TH1F("h_Dst_asym_D0m", ";invariant D0 mass/MeV; assymmetry", 92, 1842., 1888.);

  h_Dst_pos_D0m->Sumw2();
  h_Dst_neg_D0m->Sumw2();
  h_Dst_asym_D0m->Sumw2();

  TH1F *h_Dst_pos_DTFm = new TH1F("h_Dst_pos_DTFm", ";invariant DTF mass/MeV; Events", 155, 2004.5, 2020.);
  TH1F *h_Dst_neg_DTFm = new TH1F("h_Dst_neg_DTFm", ";invariant DTF mass/MeV; Events", 155, 2004.5, 2020.);

  TH1F *h_Dst_pos_DTFm_gr_side = new TH1F("h_Dst_pos_DTFm_gr_side", ";invariant DTF mass/MeV; Events", 375, 2012.5, 2020.);
  TH1F *h_Dst_neg_DTFm_gr_side = new TH1F("h_Dst_neg_DTFm_gr_side", ";invariant DTF mass/MeV; Events", 375, 2012.5, 2020.);

  TH1F *h_Dst_pos_DTFm_lw_side = new TH1F("h_Dst_pos_DTFm_gr_side", ";invariant DTF mass/MeV; Events", 200, 2004.5, 2008.5);
  TH1F *h_Dst_neg_DTFm_lw_side = new TH1F("h_Dst_neg_DTFm_gr_side", ";invariant DTF mass/MeV; Events", 200, 2004.5, 2008.5);

  TH1F *h_Dst_pos_DTFm_sides = new TH1F("h_Dst_pos_DTFm_gr_side", ";invariant DTF mass/MeV; Events", 155, 2004.5, 2020.);
  TH1F *h_Dst_neg_DTFm_sides = new TH1F("h_Dst_neg_DTFm_gr_side", ";invariant DTF mass/MeV; Events", 155, 2004.5, 2020.);

  TH1F *h_Dst_asym_DTFm = new TH1F("h_Dst_asym_DTFm", ";invariant DTF mass/MeV; assymmetry", 155, 2004.5, 2020.);

  TH1F *h_delta_m_pos = new TH1F("h_delta_m_pos", "; #Delta m; Events", 124, 116., 180.);
  TH1F *h_delta_m_neg = new TH1F("h_delta_m_neg", ";#Delta m; Events", 124, 116., 180.);
  TH1F *h_delta_m_asym = new TH1F("h_delta_m_asym", ";#Delta m; assymmetry", 124, 116., 180.);

  h_Dst_pos_DTFm->Sumw2();
  h_Dst_neg_DTFm->Sumw2();
  h_Dst_asym_DTFm->Sumw2();

  h_delta_m_neg->Sumw2();
  h_delta_m_pos->Sumw2();
  h_delta_m_asym->Sumw2();

  ofstream outfile("output/data/plots/data_neg.txt", ofstream::trunc);
  outfile << "#m, E\n ";

  ofstream outfile2("output/data/plots/data_pos.txt", ofstream::trunc);
  outfile2 << "#m, E\n ";

  for (int i = 0; i < nEvents; ++i)
  {
    if (i % (nEvents/10) == 0)
    {
      std::cout << "=== Event " << i/(nEvents/10) * 10 << "%" << std::endl;
    }
    ntp->GetEvent(i);
    if(Dst_ID < 0)
    {
      h_Dst_neg_D0m->Fill(D0_mass);
      h_Dst_neg_DTFm->Fill(DTF_mass);
      h_delta_m_neg->Fill(DTF_mass - D0_mass);
      if(DTF_mass < 2008.5)
      {
        h_Dst_neg_DTFm_lw_side->Fill(DTF_mass);
        h_Dst_neg_DTFm_sides->Fill(DTF_mass);

      }
      else if(DTF_mass > 2012.5)
      {
        h_Dst_neg_DTFm_gr_side->Fill(DTF_mass);
        h_Dst_neg_DTFm_sides->Fill(DTF_mass);
      }
      ++nDst_neg;
    }
    else
    {
      h_Dst_pos_D0m->Fill(D0_mass);
      h_Dst_pos_DTFm->Fill(DTF_mass);
      h_delta_m_pos->Fill(DTF_mass-D0_mass);
      if(DTF_mass < 2008.5)
      {
        h_Dst_pos_DTFm_lw_side->Fill(DTF_mass);
        h_Dst_pos_DTFm_sides->Fill(DTF_mass);

      }
      else if(DTF_mass > 2012.5)
      {
        h_Dst_pos_DTFm_gr_side->Fill(DTF_mass);
        h_Dst_pos_DTFm_sides->Fill(DTF_mass);
      }
      ++nDst_pos;
    }
  }
  int size = h_Dst_neg_DTFm_lw_side->GetNbinsX();
  for (int i = 0; i < size; ++i)
  {
    outfile << 2004.51 + i * 0.02 << " " << h_Dst_neg_DTFm_lw_side->GetBinContent(i) << "\n";
    outfile2 << 2004.51 + i * 0.02 << " " << h_Dst_pos_DTFm_lw_side->GetBinContent(i) << "\n";
  }
  size = h_Dst_neg_DTFm_gr_side->GetNbinsX();
  for (int i = 0; i < size; ++i)
  {
    outfile << 2012.51 + i * 0.02 << " " << h_Dst_neg_DTFm_gr_side->GetBinContent(i) << "\n";
    outfile2 << 2012.51 + i * 0.02 << " " << h_Dst_pos_DTFm_gr_side->GetBinContent(i) << "\n";
  }
  outfile.flush();
  outfile.close();
  outfile2.flush();
  outfile2.close();

  double Dst_asym = (nDst_pos-nDst_neg)/(nDst_pos+nDst_neg);


  printhists(h_Dst_pos_D0m);
  printhists(h_Dst_neg_D0m);
  printhists(h_Dst_pos_DTFm);
  printhists(h_Dst_neg_DTFm);
  printhists(h_delta_m_neg);
  printhists(h_delta_m_pos);

  string output_hist_name;
  output_hist_name = "output/data/histOut_"+sample+".root";
  TFile *out_hist_fi = new TFile(output_hist_name.c_str(),"RECREATE");

  h_Dst_pos_D0m->Write();
  h_Dst_neg_D0m->Write();
  h_Dst_pos_DTFm->Write();
  h_Dst_neg_DTFm->Write();



  //RooFit things

  RooRealVar *dtf_neg_low = new RooRealVar("dtf_neg_low", "dtf_neg_low", 2004.5, 2008.5);
  RooRealVar *dtf_neg_gr = new RooRealVar("dtf_neg_gr", "dtf_neg_gr", 2012.5, 2020.);
  RooRealVar *dtf_pos_low = new RooRealVar("dtf_pos_low", "dtf_pos_low", 2004.5, 2008.5);
  RooRealVar *dtf_pos_gr = new RooRealVar("dtf_pos_gr", "dtf_pos_gr", 2012.5, 2020.);

  RooRealVar *dtf_neg_sides = new RooRealVar("dtf_neg_sides", "dtf_neg_sides", 2004.5, 2020.);
  RooRealVar *dtf_pos_sides = new RooRealVar("dtf_pos_sides", "dtf_pos_sides", 2004.5, 2020.);

  RooRealVar *dtf_neg = new RooRealVar("dtf_neg", "dtf_neg", 2004.5, 2020.);
  RooRealVar *dtf_pos = new RooRealVar("dtf_pos", "dtf_pos", 2004.5, 2020.);

  RooDataHist *data = new RooDataHist("data", "datahist", RooArgList(*dtf_neg_low), h_Dst_neg_DTFm_lw_side);
  RooDataHist *data2 =  new RooDataHist("data2", "datahist2", RooArgList(*dtf_neg_gr), h_Dst_neg_DTFm_gr_side);
  RooDataHist *data3 = new RooDataHist("data3", "datahist3", RooArgList(*dtf_pos_low), h_Dst_pos_DTFm_lw_side);
  RooDataHist *data4 =  new RooDataHist("data4", "datahist4", RooArgList(*dtf_pos_gr), h_Dst_pos_DTFm_gr_side);
  RooDataHist *data5 = new RooDataHist("data5", "datahist5", RooArgList(*dtf_pos_sides), h_Dst_pos_DTFm_sides);
  RooDataHist *data6 = new RooDataHist("data6", "datahist6", RooArgList(*dtf_neg_sides), h_Dst_neg_DTFm_sides);
  RooDataHist *data7 = new RooDataHist("data7", "datahist7", RooArgList(*dtf_pos), h_Dst_pos_DTFm);
  RooDataHist *data8 = new RooDataHist("data8", "datahist8", RooArgList(*dtf_neg), h_Dst_neg_DTFm);

  RooPlot *neg_low_frame = dtf_neg_low->frame();
  RooPlot *neg_gr_frame = dtf_neg_gr->frame();
  RooPlot *pos_low_frame = dtf_pos_low->frame();
  RooPlot *pos_gr_frame = dtf_pos_gr->frame();

  RooPlot *neg_sides_frame = dtf_neg_sides->frame();
  RooPlot *pos_sides_frame = dtf_pos_sides->frame();

  RooPlot *neg_frame = dtf_neg->frame();
  RooPlot *neg_frame2 = dtf_neg->frame();
  RooPlot *neg_frame3 = dtf_neg->frame();
  RooPlot *pos_frame = dtf_pos->frame();

  TCanvas *canvas2 = new TCanvas();

data->plotOn(neg_low_frame);
data2->plotOn(neg_gr_frame);
data3->plotOn(pos_low_frame);
data4->plotOn(pos_gr_frame);
data5->plotOn(pos_sides_frame);
data6->plotOn(neg_sides_frame);
  neg_low_frame->Draw();
  canvas2->SaveAs("output/data/plots/neg_low.pdf");
  neg_gr_frame->Draw();
  canvas2->SaveAs("output/data/plots/neg_gr.pdf");
  pos_low_frame->Draw();
  canvas2->SaveAs("output/data/plots/pos_low.pdf");
  pos_gr_frame->Draw();
  canvas2->SaveAs("output/data/plots/pos_gr.pdf");
  pos_sides_frame->Draw();
  canvas2->SaveAs("output/data/plots/pos_sides.pdf");
  neg_sides_frame->Draw();
  canvas2->SaveAs("output/data/plots/neg_sides.pdf");

  RooRealVar *sig_yield_neg = new RooRealVar("sig_yield_neg", "sig_yield_neg", 25000., 0., 200000.);
  RooRealVar *bkg_yield_neg = new RooRealVar("bkg_yield_neg", "bkg_yield_neg", 1000., 0., 10000.);
  RooRealVar *sig_yield_pos = new RooRealVar("sig_yield_pos", "sig_yield_pos", 25000., 0., 200000.);
  RooRealVar *bkg_yield_pos = new RooRealVar("bkg_yield_pos", "bkg_yield_pos", 1000., 0., 10000.);

  RooBreitWigner *sig_neg = new RooBreitWigner("sig_neg", "sig_neg", *dtf_neg, *mean, *sigma);
  RooAbsPdf *arg_neg = RooClassFactory::makePdfInstance("arg_neg", "1./N*pow(dtf_neg-a,b)*exp(-c*(dtf_neg-a))", RooArgSet(*dtf_neg, *N, *a, *b, *c));
  RooAddPdf *model_neg = new RooAddPdf("model_neg", "model_neg", RooArgList(*sig_neg, *arg_neg),RooArgList(*sig_yield_neg, *bkg_yield_neg));

  RooBreitWigner *sig_pos = new RooBreitWigner("sig_pos", "sig_pos", *dtf_pos, *mean, *sigma);
  RooAbsPdf *arg_pos = RooClassFactory::makePdfInstance("arg_pos", "1./N*pow(dtf_pos-a,b)*exp(-c*(dtf_pos-a))", RooArgSet(*dtf_pos, *N, *a, *b, *c));
  RooAddPdf *model_pos = new RooAddPdf("model_pos", "model_pos", RooArgList(*sig_pos, *arg_pos),RooArgList(*sig_yield_pos, *bkg_yield_pos));




  model_neg->fitTo(*data8, RooFit::PrintLevel(-1), RooFit::PrintEvalErrors(-1));
  data8->plotOn(neg_frame);
  model_neg->plotOn(neg_frame, RooFit::Components("arg_neg"), RooFit::FillColor(kRed), RooFit::LineStyle(kDashed),RooFit::DrawOption("F") );
  model_neg->plotOn(neg_frame);
  model_neg->paramOn(neg_frame, RooFit::Label("Fit Results"), RooFit::Format("NEU", RooFit::AutoPrecision(1)));

  neg_frame->Draw();

  canvas2->SaveAs("output/data/plots/dtf_neg_fit.pdf");


  model_pos->fitTo(*data7, RooFit::PrintLevel(-1), RooFit::PrintEvalErrors(-1));
  data7->plotOn(pos_frame);
  model_pos->plotOn(pos_frame, RooFit::Components("arg_pos"), RooFit::FillColor(kRed), RooFit::LineStyle(kDashed),RooFit::DrawOption("F") );
  model_pos->plotOn(pos_frame);
  model_pos->paramOn(pos_frame, RooFit::Label("Fit Results"), RooFit::Format("NEU", RooFit::AutoPrecision(1)));



  pos_frame->Draw();
  canvas2->SaveAs("output/data/plots/dtf_pos_fit.pdf");





  TH1F *h_sig_pos_dtf = new TH1F("h_sig_pos_dtf", "h_sig_pos_dtf", 35, 2009.9, 2010.6);
  TH1F *h_sig_neg_dtf = new TH1F("h_sig_neg_dtf", "h_sig_neg_dtf", 35, 2009.9, 2010.6);
  TH1F *h_sig_asym_dtf = new TH1F("h_sig_asym_dtf", "h_sig_asym_dtf", 35, 2009.9, 2010.6);

  h_sig_pos_dtf->Sumw2();
  h_sig_neg_dtf->Sumw2();
  h_sig_neg_dtf->Sumw2();

  for (int i = 0; i < nEvents; ++i)
  {
    if (i % (nEvents/10) == 0)
    {
      std::cout << "=== Event " << i/(nEvents/10) * 10 << "%" << std::endl;
    }
    ntp->GetEvent(i);
    if (Dst_ID < 0)
    {
      h_sig_neg_dtf->Fill(DTF_mass);
    }
    else if (Dst_ID > 0)
    {
      h_sig_pos_dtf->Fill(DTF_mass);
    }
  }

  size = h_sig_neg_dtf->GetNbinsX();
  double func, sig_bkg;
  for(int i = 0; i < size; ++i)
  {
    func = (1./0.00583*pow((2009.91+i*0.02 - 2004.395), 0.7185)*exp(-0.0512*(2009.91+i*0.02 - 2004.395)) + 1./0.00583*pow((2009.9+i*0.02 - 2004.395), 0.7185)*exp(-0.0512*(2009.9+i*0.02 - 2004.395)) + 1./0.00583*pow((2009.92+i*0.02 - 2004.39)*exp(-0.0512*(2009.92+i*0.02 - 2004.395)), 0.7185))/3.;
    sig_bkg = h_sig_neg_dtf->GetBinContent(i);
    (sig_bkg - func >=0)? h_sig_neg_dtf->SetBinContent(i, sig_bkg - func) : h_sig_neg_dtf->SetBinContent(i, 0.);

    func = (1./0.00588*pow((2009.91+i*0.02 - 2004.411), 0.6805)*exp(-0.0466*(2009.91+i*0.02 - 2004.411)) + 1./0.00588*pow((2009.9+i*0.02 - 2004.411), 0.6805)*exp(-0.0466*(2009.9+i*0.02 - 2004.411)) + 1./0.00588*pow((2009.92+i*0.02 - 2004.411)*exp(-0.0466*(2009.92+i*0.02 - 2004.411)), 0.6805))/3.;
    sig_bkg = h_sig_pos_dtf->GetBinContent(i);
    (sig_bkg - func >=0)? h_sig_pos_dtf->SetBinContent(i, sig_bkg - func) : h_sig_pos_dtf->SetBinContent(i, 0.);
  }

  h_sig_neg_dtf->Write();
  h_sig_pos_dtf->Write();
  printhists(h_sig_neg_dtf);
  printhists(h_sig_pos_dtf);

  double nSigPos = h_sig_pos_dtf->Integral();
  double nSigNeg = h_sig_neg_dtf->Integral();

  double sig_asym = (nSigPos - nSigNeg)/(nSigPos + nSigNeg);



  h_sig_pos_dtf->Add(h_sig_neg_dtf,-1);
  h_sig_neg_dtf->Scale(2.);
  h_sig_neg_dtf->Add(h_sig_pos_dtf);
  h_sig_pos_dtf->Divide(h_sig_neg_dtf);
  h_sig_asym_dtf = h_sig_pos_dtf;
  h_sig_asym_dtf->SetName("h_sig_asym_dtf");
  h_sig_asym_dtf->SetTitle(";m(D*)/MeV; assymmetry");
  h_sig_asym_dtf->SetAxisRange(-0.05, 0., "Y");
  printhists(h_sig_asym_dtf);

  h_Dst_asym_D0m->Write();
  h_Dst_asym_DTFm->Write();
  out_hist_fi->Write();
  out_hist_fi->Close();

  cout << "Number of reconstructed data -: " << nDst_neg << endl;
  cout << "Number of reconstructed data +: " << nDst_pos << endl;
  cout << "The total Dst assymmetry in data is: " << Dst_asym << endl;

  cout << "Number of reconstructed signal -: " << nSigNeg << endl;
  cout << "Number of reconstructed signal +: " << nSigPos << endl;
  cout << "The total Dst assymmetry in signal is: " << sig_asym << endl;*/




//other RooFit

  RooRealVar *DTF_Mass = new RooRealVar("DTF_Mass", "DTF_Mass", 2004., 2021.);
  RooRealVar *DTF_Mass_iso = new RooRealVar("DTF_Mass", "DTF_Mass_iso", 2012.5, 2021.);
  RooRealVar *Dst_ID_neg = new RooRealVar("Dst_ID", "Dst_ID_neg", -420., -400.);
  RooRealVar *Dst_ID_pos = new RooRealVar("Dst_ID", "Dst_ID_pos", 400., 420.);

  RooDataSet *dataset1 = new RooDataSet("dataset1", "dataset1", ntp, RooArgList(*DTF_Mass, *Dst_ID_neg));
  RooDataSet *dataset2 = new RooDataSet("dataset2", "dataset2", ntp, RooArgList(*DTF_Mass, *Dst_ID_pos));
  RooDataSet *dataset1b = new RooDataSet("dataset1b", "dataset1b", ntp, RooArgList(*DTF_Mass_iso, *Dst_ID_neg));
  RooDataSet *dataset2b = new RooDataSet("dataset2b", "dataset2b", ntp, RooArgList(*DTF_Mass_iso, *Dst_ID_pos));

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

  cout << "debug1" << endl << endl << endl << endl;
  model_neg->fitTo(*dataset1, Extended(), RooFit::PrintLevel(-1), RooFit::PrintEvalErrors(-1));

  cout << "debug2" << endl << endl << endl << endl;
  RooStats::SPlot *sData = new RooStats::SPlot("sData", "An SPlot", *dataset1, model_neg, RooArgList(*sig_yield, *bkg_yield));
  cout << "debug3" << endl << endl << endl << endl;
  model_pos->fitTo(*dataset2, Extended(), RooFit::PrintLevel(-1), RooFit::PrintEvalErrors(-1));
  cout << "debug4" << endl << endl << endl << endl;
  RooStats::SPlot *sData2 = new RooStats::SPlot("sData2", "An SPlot2", *dataset2, model_pos, RooArgList(*sig_yield_2, *bkg_yield_2));

  TFile f("output/histOut_minisample_Dst2D0pi_D02Kpi_2016_Up_GEN.root");

  TH1F *h_Dst_pT_MC = (TH1F*)f.Get("h_pT_reco_Dst");
  double nMCEvents = h_Dst_pT_MC->GetEntries();
  h_Dst_pT_MC->Scale(1./nMCEvents);
  h_Dst_pT_MC->SetLineColor(kAzure);
  TH1F *h_Dst_pT_data = new TH1F("h_Dst_pT_data", ";Dst pT/MeV; Event", 148, 2200., 9600.);
  h_Dst_pT_data->Sumw2();
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
      ++i_neg;
    }
    else
    {
      h_Dst_pT_data->Fill(Dst_pT, sData2->GetSumOfEventSWeight(i_pos));
      ++i_pos;
    }
  }

  double nDataEvents = h_Dst_pT_data->GetSumOfWeights();
  h_Dst_pT_data->Scale(1./nDataEvents);
  h_Dst_pT_data->SetLineColor(kRed);

  TCanvas *c1;
  h_Dst_pT_MC->Draw();
  cout << "debug5" << endl << endl << endl << endl;
  h_Dst_pT_MC->Draw("hist same");
  cout << "debug6" << endl << endl << endl << endl;
  h_Dst_pT_MC->Draw("same");
  cout << "debug7" << endl << endl << endl << endl;
  h_Dst_pT_MC->Draw("hist same");
  cout << "debug8" << endl << endl << endl << endl;
  c1->SaveAs("output/data/plots/data_MC_comp.pdf");













  uint64_t end_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
  float elapsed = (end_time - start_time)*0.000001;
  std::cout << "computation time/s: " << elapsed << std::endl;
  std::cout << "computation time/min: " << elapsed/60. << std::endl;
}
