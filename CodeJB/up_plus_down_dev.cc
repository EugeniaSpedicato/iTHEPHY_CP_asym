#include "eff.h"

void up_plus_down_dev()
{
  TFile f_up("output/histOut_minisample_Dst2D0pi_D02Kpi_2016_Up_GEN.root");
  TFile f_dw("output/histOut_minisample_Dst2D0pi_D02Kpi_2016_Dw_GEN.root");

  vector <TH1F*> v_h_up_eta_pos = {(TH1F*)f_up.Get("h_eta_reco_Pi_pos_dev"), (TH1F*)f_up.Get("h_eta_reco_K_pos_dev"), (TH1F*)f_up.Get("h_eta_reco_SPi_pos_dev"), (TH1F*)f_up.Get("h_eta_reco_D0_pos_dev"), (TH1F*)f_up.Get("h_eta_reco_Dst_pos_dev")};

  vector <TH1F*> v_h_up_pT_pos = {(TH1F*)f_up.Get("h_pT_reco_Pi_pos_dev"), (TH1F*)f_up.Get("h_pT_reco_K_pos_dev"), (TH1F*)f_up.Get("h_pT_reco_SPi_pos_dev"), (TH1F*)f_up.Get("h_pT_reco_D0_pos_dev"), (TH1F*)f_up.Get("h_pT_reco_Dst_pos_dev")};

  vector <TH1F*> v_h_up_phi_pos = {(TH1F*)f_up.Get("h_phi_reco_Pi_pos_dev"), (TH1F*)f_up.Get("h_phi_reco_K_pos_dev"), (TH1F*)f_up.Get("h_phi_reco_SPi_pos_dev"), (TH1F*)f_up.Get("h_phi_reco_D0_pos_dev"), (TH1F*)f_up.Get("h_phi_reco_Dst_pos_dev")};

  vector <TH1F*> v_h_up_theta_pos = {(TH1F*)f_up.Get("h_theta_reco_Pi_pos_dev"), (TH1F*)f_up.Get("h_theta_reco_K_pos_dev"), (TH1F*)f_up.Get("h_theta_reco_SPi_pos_dev"), (TH1F*)f_up.Get("h_theta_reco_D0_pos_dev"), (TH1F*)f_up.Get("h_theta_reco_Dst_pos_dev")};


  vector <TH1F*> v_h_dw_eta_pos = {(TH1F*)f_dw.Get("h_eta_reco_Pi_pos_dev"), (TH1F*)f_dw.Get("h_eta_reco_K_pos_dev"), (TH1F*)f_dw.Get("h_eta_reco_SPi_pos_dev"), (TH1F*)f_dw.Get("h_eta_reco_D0_pos_dev"), (TH1F*)f_dw.Get("h_eta_reco_Dst_pos_dev")};

  vector <TH1F*> v_h_dw_pT_pos = {(TH1F*)f_dw.Get("h_pT_reco_Pi_pos_dev"), (TH1F*)f_dw.Get("h_pT_reco_K_pos_dev"), (TH1F*)f_dw.Get("h_pT_reco_SPi_pos_dev"), (TH1F*)f_dw.Get("h_pT_reco_D0_pos_dev"), (TH1F*)f_dw.Get("h_pT_reco_Dst_pos_dev")};

  vector <TH1F*> v_h_dw_phi_pos = {(TH1F*)f_dw.Get("h_phi_reco_Pi_pos_dev"), (TH1F*)f_dw.Get("h_phi_reco_K_pos_dev"), (TH1F*)f_dw.Get("h_phi_reco_SPi_pos_dev"), (TH1F*)f_dw.Get("h_phi_reco_D0_pos_dev"), (TH1F*)f_dw.Get("h_phi_reco_Dst_pos_dev")};

  vector <TH1F*> v_h_dw_theta_pos = {(TH1F*)f_dw.Get("h_theta_reco_Pi_pos_dev"), (TH1F*)f_dw.Get("h_theta_reco_K_pos_dev"), (TH1F*)f_dw.Get("h_theta_reco_SPi_pos_dev"), (TH1F*)f_dw.Get("h_theta_reco_D0_pos_dev"), (TH1F*)f_dw.Get("h_theta_reco_Dst_pos_dev")};
 
  int size = v_h_dw_eta_pos.size();
  string save_name;
  TCanvas *c = new TCanvas();
  gStyle->SetOptStat(0);
  TF1 func("0*x", "0*x", -5., 11000.);
  for (int i =0; i < size;++i)
  {
    v_h_up_eta_pos.at(i)->Add(v_h_dw_eta_pos.at(i));
    save_name = "output/up_plus_down_pdf/eta_"+to_string(i)+".pdf";
    v_h_up_eta_pos.at(i)->Draw();
    func.Draw("same");
    c->SaveAs(save_name.c_str());
    v_h_up_pT_pos.at(i)->Add(v_h_dw_pT_pos.at(i));
    save_name = "output/up_plus_down_pdf/pT_"+to_string(i)+".pdf";
    v_h_up_pT_pos.at(i)->Draw();
    func.Draw("same");
    c->SaveAs(save_name.c_str());
    v_h_up_phi_pos.at(i)->Add(v_h_dw_phi_pos.at(i));
    save_name = "output/up_plus_down_pdf/phi_"+to_string(i)+".pdf";
    v_h_up_phi_pos.at(i)->Draw();
    func.Draw("same");
    c->SaveAs(save_name.c_str());
    v_h_up_theta_pos.at(i)->Add(v_h_dw_theta_pos.at(i));
    save_name = "output/up_plus_down_pdf/theta_"+to_string(i)+".pdf";
    v_h_up_theta_pos.at(i)->Draw();
    func.Draw("same");
    c->SaveAs(save_name.c_str());
  }
}
/*
void printdevhists(vector<TH1F*> v_get_hist_pos, vector<TH1F*> v_get_hist_neg, string var)
{
  TF1 func("0*x", "0*x", -5., 11000.);
  int size = v_get_hist_pos.size();
  vector<TH1F*> v_hist_pos;
  vector<TH1F*> v_hist_neg;
  int nbins;
  double min,max;
  for (int i = 0; i < size; ++i)
  {
  nbins = v_get_hist_pos.at(i)->GetNbinsX();
  min = v_get_hist_pos.at(i)->GetXaxis()->GetBinLowEdge(1);
  max = v_get_hist_pos.at(i)->GetXaxis()->GetBinLowEdge(nbins) + v_get_hist_pos.at(i)->GetXaxis()->GetBinWidth(nbins);
  TH1F *h_temp_pos = new TH1F(v_get_hist_pos.at(i)->GetName(),v_get_hist_pos.at(i)->GetTitle(), nbins, min, max);
  h_temp_pos->Add(v_get_hist_pos.at(i));
  v_hist_pos.push_back(h_temp_pos);
  nbins = v_get_hist_neg.at(i)->GetNbinsX();
  min = v_get_hist_neg.at(i)->GetXaxis()->GetBinLowEdge(1);
  max = v_get_hist_neg.at(i)->GetXaxis()->GetBinLowEdge(nbins) + v_get_hist_neg.at(i)->GetXaxis()->GetBinWidth(nbins);
  TH1F *h_temp_neg = new TH1F(v_get_hist_neg.at(i)->GetName(),v_get_hist_neg.at(i)->GetTitle(), nbins, min, max);
  h_temp_neg->Add(v_get_hist_neg.at(i));
  v_hist_neg.push_back(h_temp_neg);
  }
  string save_name;
  TCanvas *c = new TCanvas();
  for (int i = 0; i < size; ++i)
  {
    v_hist_pos.at(i)->Add(v_hist_neg.at(i),-1);
    v_hist_neg.at(i)->Scale(2.);
    v_hist_neg.at(i)->Add(v_hist_pos.at(i));
    v_hist_pos.at(i)->Divide(v_hist_neg.at(i));/*
    if ( size > 4 && i >= 4 )
    {
      v_hist_pos.at(i)->SetAxisRange(-0.02, 0.02, "Y");
    }
    else v_hist_pos.at(i)->SetAxisRange(-0.15, 0.15, "Y");
    v_hist_pos.at(i)->Draw();
    func.Draw("same");
    save_name = "output/up_plus_down_pdf/"+var+"_"+to_string(i)+".pdf";
    c->SaveAs(save_name.c_str());
  }
}
void up_plus_down_dev()
{
  TFile f_up("output/histOut_minisample_Dst2D0pi_D02Kpi_2016_Up_GEN.root");
  TFile f_dw("output/histOut_minisample_Dst2D0pi_D02Kpi_2016_Dw_GEN.root");

  vector <TH1F*> v_h_up_eta_pos = {(TH1F*)f_up.Get("h_eta_reco_Pi_pos"), (TH1F*)f_up.Get("h_eta_reco_K_pos"), (TH1F*)f_up.Get("h_eta_reco_SPi_pos"), (TH1F*)f_up.Get("h_eta_reco_D0_pos"), (TH1F*)f_up.Get("h_eta_reco_Dst_pos")};

  vector <TH1F*> v_h_up_pT_pos = {(TH1F*)f_up.Get("h_pT_reco_Pi_pos"), (TH1F*)f_up.Get("h_pT_reco_K_pos"), (TH1F*)f_up.Get("h_pT_reco_SPi_pos"), (TH1F*)f_up.Get("h_pT_reco_D0_pos"), (TH1F*)f_up.Get("h_pT_reco_Dst_pos")};

  vector <TH1F*> v_h_up_phi_pos = {(TH1F*)f_up.Get("h_phi_reco_Pi_pos"), (TH1F*)f_up.Get("h_phi_reco_K_pos"), (TH1F*)f_up.Get("h_phi_reco_SPi_pos"), (TH1F*)f_up.Get("h_phi_reco_D0_pos"), (TH1F*)f_up.Get("h_phi_reco_Dst_pos")};

  vector <TH1F*> v_h_up_theta_pos = {(TH1F*)f_up.Get("h_theta_reco_Pi_pos"), (TH1F*)f_up.Get("h_theta_reco_K_pos"), (TH1F*)f_up.Get("h_theta_reco_SPi_pos"), (TH1F*)f_up.Get("h_theta_reco_D0_pos"), (TH1F*)f_up.Get("h_theta_reco_Dst_pos")};


  vector <TH1F*> v_h_up_eta_neg = {(TH1F*)f_up.Get("h_eta_reco_Pi_neg"), (TH1F*)f_up.Get("h_eta_reco_K_neg"), (TH1F*)f_up.Get("h_eta_reco_SPi_neg"), (TH1F*)f_up.Get("h_eta_reco_D0_neg"), (TH1F*)f_up.Get("h_eta_reco_Dst_neg")};

  vector <TH1F*> v_h_up_pT_neg = {(TH1F*)f_up.Get("h_pT_reco_Pi_neg"), (TH1F*)f_up.Get("h_pT_reco_K_neg"), (TH1F*)f_up.Get("h_pT_reco_SPi_neg"), (TH1F*)f_up.Get("h_pT_reco_D0_neg"), (TH1F*)f_up.Get("h_pT_reco_Dst_neg")};

  vector <TH1F*> v_h_up_phi_neg = {(TH1F*)f_up.Get("h_phi_reco_Pi_neg"), (TH1F*)f_up.Get("h_phi_reco_K_neg"), (TH1F*)f_up.Get("h_phi_reco_SPi_neg"), (TH1F*)f_up.Get("h_phi_reco_D0_neg"), (TH1F*)f_up.Get("h_phi_reco_Dst_neg")};

  vector <TH1F*> v_h_up_theta_neg = {(TH1F*)f_up.Get("h_theta_reco_Pi_neg"), (TH1F*)f_up.Get("h_theta_reco_K_neg"), (TH1F*)f_up.Get("h_theta_reco_SPi_neg"), (TH1F*)f_up.Get("h_theta_reco_D0_neg"), (TH1F*)f_up.Get("h_theta_reco_Dst_neg")};
  

  vector <TH1F*> v_h_dw_eta_pos = {(TH1F*)f_dw.Get("h_eta_reco_Pi_pos"), (TH1F*)f_dw.Get("h_eta_reco_K_pos"), (TH1F*)f_dw.Get("h_eta_reco_SPi_pos"), (TH1F*)f_dw.Get("h_eta_reco_D0_pos"), (TH1F*)f_dw.Get("h_eta_reco_Dst_pos")};

  vector <TH1F*> v_h_dw_pT_pos = {(TH1F*)f_dw.Get("h_pT_reco_Pi_pos"), (TH1F*)f_dw.Get("h_pT_reco_K_pos"), (TH1F*)f_dw.Get("h_pT_reco_SPi_pos"), (TH1F*)f_dw.Get("h_pT_reco_D0_pos"), (TH1F*)f_dw.Get("h_pT_reco_Dst_pos")};

  vector <TH1F*> v_h_dw_phi_pos = {(TH1F*)f_dw.Get("h_phi_reco_Pi_pos"), (TH1F*)f_dw.Get("h_phi_reco_K_pos"), (TH1F*)f_dw.Get("h_phi_reco_SPi_pos"), (TH1F*)f_dw.Get("h_phi_reco_D0_pos"), (TH1F*)f_dw.Get("h_phi_reco_Dst_pos")};

  vector <TH1F*> v_h_dw_theta_pos = {(TH1F*)f_dw.Get("h_theta_reco_Pi_pos"), (TH1F*)f_dw.Get("h_theta_reco_K_pos"), (TH1F*)f_dw.Get("h_theta_reco_SPi_pos"), (TH1F*)f_dw.Get("h_theta_reco_D0_pos"), (TH1F*)f_dw.Get("h_theta_reco_Dst_pos")};
 

  vector <TH1F*> v_h_dw_eta_neg = {(TH1F*)f_dw.Get("h_eta_reco_Pi_neg"), (TH1F*)f_dw.Get("h_eta_reco_K_neg"), (TH1F*)f_dw.Get("h_eta_reco_SPi_neg"), (TH1F*)f_dw.Get("h_eta_reco_D0_neg"), (TH1F*)f_dw.Get("h_eta_reco_Dst_neg")};

  vector <TH1F*> v_h_dw_pT_neg = {(TH1F*)f_dw.Get("h_pT_reco_Pi_neg"), (TH1F*)f_dw.Get("h_pT_reco_K_neg"), (TH1F*)f_dw.Get("h_pT_reco_SPi_neg"), (TH1F*)f_dw.Get("h_pT_reco_D0_neg"), (TH1F*)f_dw.Get("h_pT_reco_Dst_neg")};

  vector <TH1F*> v_h_dw_phi_neg = {(TH1F*)f_dw.Get("h_phi_reco_Pi_neg"), (TH1F*)f_dw.Get("h_phi_reco_K_neg"), (TH1F*)f_dw.Get("h_phi_reco_SPi_neg"), (TH1F*)f_dw.Get("h_phi_reco_D0_neg"), (TH1F*)f_dw.Get("h_phi_reco_Dst_neg")};

  vector <TH1F*> v_h_dw_theta_neg = {(TH1F*)f_dw.Get("h_theta_reco_Pi_neg"), (TH1F*)f_dw.Get("h_theta_reco_K_neg"), (TH1F*)f_dw.Get("h_theta_reco_SPi_neg"), (TH1F*)f_dw.Get("h_theta_reco_D0_neg"), (TH1F*)f_dw.Get("h_theta_reco_Dst_neg")};

  int size = v_h_dw_eta_pos.size();
  string save_name;
  gStyle->SetOptStat(0);
  TF1 func("0*x", "0*x", -5., 9600.);
  for (int i =0; i < size;++i)
  {
    v_h_up_eta_pos.at(i)->Add(v_h_dw_eta_pos.at(i));
    v_h_up_eta_neg.at(i)->Add(v_h_dw_eta_neg.at(i));
    v_h_up_pT_pos.at(i)->Add(v_h_dw_pT_pos.at(i));
    v_h_up_pT_neg.at(i)->Add(v_h_dw_pT_neg.at(i));
    v_h_up_phi_pos.at(i)->Add(v_h_dw_phi_pos.at(i));
    v_h_up_phi_neg.at(i)->Add(v_h_dw_phi_neg.at(i));
    v_h_up_theta_pos.at(i)->Add(v_h_dw_theta_pos.at(i));
    v_h_up_theta_neg.at(i)->Add(v_h_dw_theta_neg.at(i));
  }
  printdevhists(v_h_up_eta_pos,v_h_up_eta_neg, "eta");
  printdevhists(v_h_up_phi_pos,v_h_up_phi_neg, "phi");
  printdevhists(v_h_up_pT_pos,v_h_up_pT_neg, "pT");
  printdevhists(v_h_up_theta_pos,v_h_up_theta_neg, "theta");
}
*/
