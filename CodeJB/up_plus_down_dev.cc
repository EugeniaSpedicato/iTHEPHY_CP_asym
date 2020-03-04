#include "eff.h"

void up_plus_down_dev()
{
  TFile f_up("output/histOut_minisample_Dst2D0pi_D02Kpi_2016_Up_GEN.root");
  TFile f_dw("output/histOut_minisample_Dst2D0pi_D02Kpi_2016_Dw_GEN.root");
  
  vector <TH1F*> v_h_dev_up_eta = {(TH1F*)f_up.Get("h_eta_reco_Pi_pos_dev"), (TH1F*)f_up.Get("h_eta_reco_K_pos_dev"), (TH1F*)f_up.Get("h_eta_reco_SPi_pos_dev"), (TH1F*)f_up.Get("h_eta_reco_D0_pos_dev"), (TH1F*)f_up.Get("h_eta_reco_Dst_pos_dev")};
  
  vector <TH1F*> v_h_dev_up_pT = {(TH1F*)f_up.Get("h_pT_reco_Pi_pos_dev"), (TH1F*)f_up.Get("h_pT_reco_K_pos_dev"), (TH1F*)f_up.Get("h_pT_reco_SPi_pos_dev"), (TH1F*)f_up.Get("h_pT_reco_D0_pos_dev"), (TH1F*)f_up.Get("h_pT_reco_Dst_pos_dev")};
  
  vector <TH1F*> v_h_dev_up_phi = {(TH1F*)f_up.Get("h_phi_reco_Pi_pos_dev"), (TH1F*)f_up.Get("h_phi_reco_K_pos_dev"), (TH1F*)f_up.Get("h_phi_reco_SPi_pos_dev"), (TH1F*)f_up.Get("h_phi_reco_D0_pos_dev"), (TH1F*)f_up.Get("h_phi_reco_Dst_pos_dev")};
  
  vector <TH1F*> v_h_dev_up_theta = {(TH1F*)f_up.Get("h_theta_reco_Pi_pos_dev"), (TH1F*)f_up.Get("h_theta_reco_K_pos_dev"), (TH1F*)f_up.Get("h_theta_reco_SPi_pos_dev"), (TH1F*)f_up.Get("h_theta_reco_D0_pos_dev"), (TH1F*)f_up.Get("h_theta_reco_Dst_pos_dev")};
  
  
  vector <TH1F*> v_h_dev_dw_eta = {(TH1F*)f_dw.Get("h_eta_reco_Pi_pos_dev"), (TH1F*)f_dw.Get("h_eta_reco_K_pos_dev"), (TH1F*)f_dw.Get("h_eta_reco_SPi_pos_dev"), (TH1F*)f_dw.Get("h_eta_reco_D0_pos_dev"), (TH1F*)f_dw.Get("h_eta_reco_Dst_pos_dev")};
  
  vector <TH1F*> v_h_dev_dw_pT = {(TH1F*)f_dw.Get("h_pT_reco_Pi_pos_dev"), (TH1F*)f_dw.Get("h_pT_reco_K_pos_dev"), (TH1F*)f_dw.Get("h_pT_reco_SPi_pos_dev"), (TH1F*)f_dw.Get("h_pT_reco_D0_pos_dev"), (TH1F*)f_dw.Get("h_pT_reco_Dst_pos_dev")};
  
  vector <TH1F*> v_h_dev_dw_phi = {(TH1F*)f_dw.Get("h_phi_reco_Pi_pos_dev"), (TH1F*)f_dw.Get("h_phi_reco_K_pos_dev"), (TH1F*)f_dw.Get("h_phi_reco_SPi_pos_dev"), (TH1F*)f_dw.Get("h_phi_reco_D0_pos_dev"), (TH1F*)f_dw.Get("h_phi_reco_Dst_pos_dev")};
  
  vector <TH1F*> v_h_dev_dw_theta = {(TH1F*)f_dw.Get("h_theta_reco_Pi_pos_dev"), (TH1F*)f_dw.Get("h_theta_reco_K_pos_dev"), (TH1F*)f_dw.Get("h_theta_reco_SPi_pos_dev"), (TH1F*)f_dw.Get("h_theta_reco_D0_pos_dev"), (TH1F*)f_dw.Get("h_theta_reco_Dst_pos_dev")};
  
  int size = v_h_dev_dw_eta.size();
  string save_name;
  TCanvas *c = new TCanvas();
  for (int i =0; i < size;++i)
  {
    v_h_dev_up_eta.at(i)->Add(v_h_dev_dw_eta.at(i));
    save_name = "output/up_plus_down_pdf/eta_"+to_string(i)+".pdf";
    v_h_dev_up_eta.at(i)->Draw();
    c->SaveAs(save_name.c_str());
    v_h_dev_up_pT.at(i)->Add(v_h_dev_dw_pT.at(i));
    save_name = "output/up_plus_down_pdf/pT_"+to_string(i)+".pdf";
    v_h_dev_up_pT.at(i)->Draw();
    c->SaveAs(save_name.c_str());
    v_h_dev_up_phi.at(i)->Add(v_h_dev_dw_phi.at(i));
    save_name = "output/up_plus_down_pdf/phi_"+to_string(i)+".pdf";
    v_h_dev_up_phi.at(i)->Draw();
    c->SaveAs(save_name.c_str());
    v_h_dev_up_theta.at(i)->Add(v_h_dev_dw_theta.at(i));
    save_name = "output/up_plus_down_pdf/theta_"+to_string(i)+".pdf";
    v_h_dev_up_theta.at(i)->Draw();
    c->SaveAs(save_name.c_str());
  }
}
