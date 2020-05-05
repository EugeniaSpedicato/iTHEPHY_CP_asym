#include "eff.h"
#include <chrono>
#include "RooRealVar.h"
#include "RooBreitWigner.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooPlot.h"
#include "RooAddPdf.h"
#include "RooUniform.h"

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
  uint64_t start_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
  string input_name = dir+"/"+sample+".root";
  TChain *ntp = new TChain();
  ntp->AddFile(input_name.c_str(),-1,"ntp;25");
  ntp->AddFile(input_name.c_str(),-1,"ntp;26");
  int nEvents = ntp->GetEntries();

  TCanvas *canvas2 = new TCanvas();
  TFile *f = new TFile("output/histOut_minisample_Dst2D0pi_D02Kpi_2016_Up_GEN.root");
  TH1F *h_pT_Dst = (TH1F*)f->Get("h_pT_reco_Dst");
  int nMCEvents = h_pT_Dst->GetEntries();

  h_pT_Dst->Scale(double(nEvents)/nMCEvents);

  double nDst_pos = 0.; double nDst_neg = 0.;
  int Dst_ID, D0_ID, Pi_ID, K_ID;
  double D0_mass;
  double DTF_mass;

  RooRealVar *y = new RooRealVar("Dst_PT", "Dstar pT/GeV", 2000.,11100.);
  RooDataSet *datahist = new RooDataSet("data_pT", "Dstar pT data", ntp, RooArgSet(*y));
  RooPlot *yframe = y->frame();
  datahist->plotOn(yframe, RooFit::Binning(182));
  yframe->Draw();
  h_pT_Dst->Draw("same");
  h_pT_Dst->Draw("same hist");
  canvas2->SaveAs("output/data/plots/pT_MC_data.pdf");
/*
  RooRealVar *x = new RooRealVar("DTF_Mass", "DTF mass [MeV]", 2004., 2020.);
  RooDataSet *dataset = new RooDataSet("data", "DTF_Mass data", ntp, RooArgSet(*x));
  RooPlot *xframe = x->frame();
  dataset->plotOn(xframe, RooFit::Binning(80));
  xframe->Draw();
  canvas2->SaveAs("output/data/plots/RooData.pdf");

  RooRealVar *mean = new RooRealVar("mean", "mean", 2011., 2008., 2014.);
  RooRealVar *sigma = new RooRealVar("sigma", "sigma", 1., 0., 3.);
  RooRealVar *rel_frac = new RooRealVar("rel_frac", "Relative Fraction", 0.7, 0.0, 1.0);
  RooBreitWigner *bw = new RooBreitWigner("BW", "BW", *x, *mean, *sigma);
  RooUniform *bkg = new RooUniform("bkg", "bkg", *x);
  RooAddPdf *model = new RooAddPdf("model", "model", RooArgList(*bw,*bkg), RooArgList(*rel_frac));
  model->fitTo(*dataset, RooFit::PrintLevel(-1), RooFit::PrintEvalErrors(-1));
  RooPlot * xframe2 = x->frame();
  dataset->plotOn(xframe2);
  model->plotOn(xframe2);
  model->plotOn(xframe2, RooFit::Components("bkg"), RooFit::LineColor(kAzure), RooFit::LineStyle(kDashed));
  model->plotOn(xframe2);
  model->paramOn(xframe2, RooFit::Label("Fit Results"), RooFit::Format("NEU", RooFit::AutoPrecision(1)), RooFit::Layout(0.5,0.9,0.8));
  xframe2->Draw();
  canvas2->SaveAs("output/data/plots/RooFit.pdf");

*/
  ntp->SetBranchStatus("*",0);
  ntp->SetBranchStatus("D0_M",1); ntp->SetBranchAddress("D0_M", &(D0_mass));
  ntp->SetBranchStatus("DTF_Mass",1); ntp->SetBranchAddress("DTF_Mass", &(DTF_mass));

  ntp->SetBranchStatus("Dst_ID",1); ntp->SetBranchAddress("Dst_ID", &(Dst_ID));
  ntp->SetBranchStatus("D0_ID",1); ntp->SetBranchAddress("D0_ID", &(D0_ID));
  ntp->SetBranchStatus("P1_ID",1); ntp->SetBranchAddress("P1_ID", &(Pi_ID));
  ntp->SetBranchStatus("P2_ID",1); ntp->SetBranchAddress("P2_ID", &(K_ID));


  TH1F *h_Dst_pos_D0m = new TH1F("h_Dst_pos_D0m", ";invariant D0 mass/MeV; Events", 92, 1842., 1888.);
  TH1F *h_Dst_neg_D0m = new TH1F("h_Dst_neg_D0m", ";invariant D0 mass/MeV; Events", 92, 1842., 1888.);
  TH1F *h_Dst_asym_D0m = new TH1F("h_Dst_asym_D0m", ";invariant D0 mass/MeV; assymmetry", 92, 1842., 1888.);

  h_Dst_pos_D0m->Sumw2();
  h_Dst_neg_D0m->Sumw2();
  h_Dst_asym_D0m->Sumw2();

  TH1F *h_Dst_pos_DTFm = new TH1F("h_Dst_pos_DTFm", ";invariant DTF mass/MeV; Events", 80, 2004., 2020.);
  TH1F *h_Dst_neg_DTFm = new TH1F("h_Dst_neg_DTFm", ";invariant DTF mass/MeV; Events", 80, 2004., 2020.);
  TH1F *h_Dst_asym_DTFm = new TH1F("h_Dst_asym_DTFm", ";invariant DTF mass/MeV; assymmetry", 80, 2004., 2020.);

  h_Dst_pos_DTFm->Sumw2();
  h_Dst_neg_DTFm->Sumw2();
  h_Dst_asym_DTFm->Sumw2();

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
      ++nDst_neg;
    }
    else
    {
      h_Dst_pos_D0m->Fill(D0_mass);
      h_Dst_pos_DTFm->Fill(DTF_mass);
      ++nDst_pos;
    }
  }
  double Dst_asym = (nDst_pos-nDst_neg)/(nDst_pos+nDst_neg);

  cout << "Number of reconstructed -: " << nDst_neg << endl;
  cout << "Number of reconstructed +: " << nDst_pos << endl;
  cout << "The total Dst assymmetry is: " << Dst_asym << endl;

  printhists(h_Dst_pos_D0m);
  printhists(h_Dst_neg_D0m);
  printhists(h_Dst_pos_DTFm);
  printhists(h_Dst_neg_DTFm);

  string output_hist_name;
  output_hist_name = "output/data/histOut_"+sample+".root";
  TFile *out_hist_fi = new TFile(output_hist_name.c_str(),"RECREATE");

  h_Dst_pos_D0m->Write();
  h_Dst_neg_D0m->Write();
  h_Dst_pos_DTFm->Write();
  h_Dst_neg_DTFm->Write();

  h_Dst_pos_D0m->Add(h_Dst_neg_D0m,-1);
  h_Dst_neg_D0m->Scale(2.);
  h_Dst_neg_D0m->Add(h_Dst_pos_D0m);
  h_Dst_pos_D0m->Divide(h_Dst_neg_D0m);
  h_Dst_asym_D0m = h_Dst_pos_D0m;
  h_Dst_asym_D0m->SetName("h_Dst_asym_D0m");
  h_Dst_asym_D0m->SetTitle(";invariant D0 mass/MeV; assymmetry");
  printhists(h_Dst_asym_D0m);

  h_Dst_pos_DTFm->Add(h_Dst_neg_DTFm,-1);
  h_Dst_neg_DTFm->Scale(2.);
  h_Dst_neg_DTFm->Add(h_Dst_pos_DTFm);
  h_Dst_pos_DTFm->Divide(h_Dst_neg_DTFm);
  h_Dst_asym_DTFm = h_Dst_pos_DTFm;
  h_Dst_asym_DTFm->SetName("h_Dst_asym_DTFm");
  h_Dst_asym_DTFm->SetTitle(";invariant DTF mass/MeV; assymmetry");
  printhists(h_Dst_asym_DTFm);

  h_Dst_asym_D0m->Write();
  h_Dst_asym_DTFm->Write();
  out_hist_fi->Write();
  out_hist_fi->Close();

  uint64_t end_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
  float elapsed = (end_time - start_time)*0.000001;
  std::cout << "computation time/s: " << elapsed << std::endl;
  std::cout << "computation time/min: " << elapsed/60. << std::endl;
}
