#include "eff.h"
#include <chrono>
#include "RooRealVar.h"
#include "RooBreitWigner.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooPlot.h"
#include "RooAddPdf.h"
#include "RooUniform.h"
#include "RooArgusBG.h"
#include "RooGaussian.h"
#include "RooPolynomial.h"
#include <fstream>
#include "RooClassFactory.h"
#include "RooWorkspace.h"
#include "RooExtendPdf.h"

RooWorkspace w = ("w");

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


  TFile *f = new TFile("output/histOut_minisample_Dst2D0pi_D02Kpi_2016_Up_GEN.root");
  TH1F *h_pT_Dst = (TH1F*)f->Get("h_pT_reco_Dst");
  int nMCEvents = h_pT_Dst->GetEntries();

  h_pT_Dst->Scale(double(nEvents)/nMCEvents);

  double nDst_pos = 0.; double nDst_neg = 0.;
  int Dst_ID, D0_ID, Pi_ID, K_ID;
  double D0_mass;
  double DTF_mass;

/*  RooRealVar *y = new RooRealVar("Dst_DTF_PT", "Dstar pT/GeV", 2000.,11100.);
  RooDataSet *datahist = new RooDataSet("data_pT", "Dstar pT data", ntp, RooArgSet(*y));
  RooPlot *yframe = y->frame();
  datahist->plotOn(yframe, RooFit::Binning(182));
  yframe->Draw();
  h_pT_Dst->Draw("same");
  h_pT_Dst->Draw("same hist");
  canvas2->SaveAs("output/data/plots/pT_MC_data.pdf");

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
    outfile << 2004.5 + i * 0.02 << " " << h_Dst_neg_DTFm_lw_side->GetBinContent(i) << "\n";
  }
  size = h_Dst_neg_DTFm_gr_side->GetNbinsX();
  for (int i = 0; i < size; ++i)
  {
    outfile << 2012.5 + i * 0.02 << " " << h_Dst_neg_DTFm_gr_side->GetBinContent(i) << "\n";
  }
  outfile.flush();
  outfile.close();
  double Dst_asym = (nDst_pos-nDst_neg)/(nDst_pos+nDst_neg);

  cout << "Number of reconstructed -: " << nDst_neg << endl;
  cout << "Number of reconstructed +: " << nDst_pos << endl;
  cout << "The total Dst assymmetry is: " << Dst_asym << endl;

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

  RooRealVar *N = new RooRealVar("N", "N", 0.0058, 0., 0.01);
  RooRealVar *a = new RooRealVar("a", "a", 2004.38, 2000., 2004.5);
  RooRealVar *c = new RooRealVar("c", "c", 0.051, 0., 0.1);
  RooRealVar *b = new RooRealVar("b", "b", 0.72, 0., 2.);
  RooRealVar *mean = new RooRealVar("mean", "mean", 2010., 2008., 2012.);
  RooRealVar *sigma = new RooRealVar("sigma", "sigma", 0.3, 0., 1.);
  RooRealVar *rel_frac = new RooRealVar("rel_frac", "rel_frac", 0.5, 0., 1.);

  RooBreitWigner *sig_neg = new RooBreitWigner("sig_neg", "sig_neg", *dtf_neg, *mean, *sigma);
  RooAbsPdf *arg_neg = RooClassFactory::makePdfInstance("arg_neg", "1/N*pow(dtf_neg-a,b)", RooArgSet(*dtf_neg, *N, *a, *b));
  RooAddPdf *model_neg = new RooAddPdf("model_neg", "model_neg", RooArgList(*sig_neg, *arg_neg),RooArgList(*rel_frac));

  RooBreitWigner *sig_pos = new RooBreitWigner("sig_pos", "sig_pos", *dtf_pos, *mean, *sigma);
  RooAbsPdf *arg_pos = RooClassFactory::makePdfInstance("arg_pos", "1/N*pow(dtf_pos-a,b)", RooArgSet(*dtf_pos, *N, *a, *b));
  RooAddPdf *model_pos = new RooAddPdf("model_pos", "model_pos", RooArgList(*sig_pos, *arg_pos),RooArgList(*rel_frac));


  model_neg->fitTo(*data8, RooFit::PrintLevel(-1), RooFit::PrintEvalErrors(-1), RooFit.Extended(RooFit.kTrue));
  data8->plotOn(neg_frame);
  model_neg->plotOn(neg_frame, RooFit::Components("arg_neg"), RooFit::FillColor(kRed), RooFit::LineStyle(kDashed),RooFit::DrawOption("F") );
  model_neg->plotOn(neg_frame);
  model_neg->paramOn(neg_frame, RooFit::Label("Fit Results"), RooFit::Format("NEU", RooFit::AutoPrecision(1)));

  model_pos->fitTo(*data7, RooFit::PrintLevel(-1), RooFit::PrintEvalErrors(-1), RooFit.Extended(RooFit.kTrue));
  data7->plotOn(pos_frame);
  model_pos->plotOn(pos_frame, RooFit::Components("arg_pos"), RooFit::FillColor(kRed), RooFit::LineStyle(kDashed),RooFit::DrawOption("F") );
  model_pos->plotOn(pos_frame);
  model_pos->paramOn(pos_frame, RooFit::Label("Fit Results"), RooFit::Format("NEU", RooFit::AutoPrecision(1)));

  neg_frame->Draw();
  canvas2->SaveAs("output/data/plots/dtf_neg_fit.pdf");
  pos_frame->Draw();
  canvas2->SaveAs("output/data/plots/dtf_pos_fit.pdf");


  TH1F *h_sig_pos_dtf = new TH1F("h_sig_pos_dtf", "h_sig_pos_dtf", 80, 2004., 2020.);
  TH1F *h_sig_neg_dtf = new TH1F("h_sig_neg_dtf", "h_sig_neg_dtf", 80, 2004., 2020.);
  TH1F *h_sig_asym_dtf = new TH1F("h_sig_asym_dtf", "h_sig_asym_dtf", 80, 2004., 2020.);

/*  int nSigPos = 0;
  int nSigNeg = 0;

  for (int i = 0; i < 150; ++i)
  {
    if (i % (nEvents/10) == 0)
    {
      std::cout << "=== Event " << i/(nEvents/10) * 10 << "%" << std::endl;
    }
    ntp->GetEvent(i);
    if (Dst_ID < 0)
    {
      ++nSigNeg;
      cout << "neg: " << 1/0.005*pow((DTF_mass-2000.8),1.52) << endl;
      if(nSigNeg > 1/0.005*pow((DTF_mass-2000.8),1.52))
      {
        h_sig_neg_dtf->Fill(DTF_mass);
      }
    }
    else if (Dst_ID > 0)
    {
      ++nSigPos;
      cout << "pos: " << 1/0.003*pow((DTF_mass-2000.46),1.551) << endl;
      if(nSigPos > 1/0.003*pow((DTF_mass-2000.46),1.551))
      {
        h_sig_pos_dtf->Fill(DTF_mass);
      }
    }
  }
*/
  h_sig_neg_dtf->Write();
  h_sig_pos_dtf->Write();
  printhists(h_sig_neg_dtf);
  printhists(h_sig_pos_dtf);

  h_sig_pos_dtf->Add(h_sig_neg_dtf,-1);
  h_sig_neg_dtf->Scale(2.);
  h_sig_neg_dtf->Add(h_sig_pos_dtf);
  h_sig_pos_dtf->Divide(h_sig_neg_dtf);
  h_sig_asym_dtf = h_sig_pos_dtf;
  h_sig_asym_dtf->SetName("h_sig_asym_dtf");
  h_sig_asym_dtf->SetTitle(";m(D*)/MeV; assymmetry");
  //h_sig_asym_dtf->SetAxisRange(-0.05, 0.05, "Y");
  printhists(h_sig_asym_dtf);

  h_Dst_asym_D0m->Write();
  h_Dst_asym_DTFm->Write();
  out_hist_fi->Write();
  out_hist_fi->Close();

  uint64_t end_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
  float elapsed = (end_time - start_time)*0.000001;
  std::cout << "computation time/s: " << elapsed << std::endl;
  std::cout << "computation time/min: " << elapsed/60. << std::endl;
}
