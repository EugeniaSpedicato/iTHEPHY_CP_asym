#include "eff.h"

void up_plus_down_dev()
{
  TFile f_up("output/histOut_minisample_Dst2D0pi_D02Kpi_2016_Up_GEN.root");
  TFile f_dw("output/histOut_minisample_Dst2D0pi_D02Kpi_2016_Dw_GEN.root");

  vector <TH1F*> v_h_up_eta_pos = {(TH1F*)f_up.Get("h_eta_reco_Pi_pos"), (TH1F*)f_up.Get("h_eta_reco_K_pos"), (TH1F*)f_up.Get("h_eta_reco_SPi_pos"), (TH1F*)f_up.Get("h_eta_reco_D0_pos"), (TH1F*)f_up.Get("h_eta_reco_Dst_pos")};

  vector <TH1F*> v_h_up_pT_pos = {(TH1F*)f_up.Get("h_pT_reco_Pi_pos"), (TH1F*)f_up.Get("h_pT_reco_K_pos"), (TH1F*)f_up.Get("h_pT_reco_SPi_pos"), (TH1F*)f_up.Get("h_pT_reco_D0_pos"), (TH1F*)f_up.Get("h_pT_reco_Dst_pos")};

  vector <TH1F*> v_h_up_phi_pos = {(TH1F*)f_up.Get("h_phi_reco_Pi_pos"), (TH1F*)f_up.Get("h_phi_reco_K_pos"), (TH1F*)f_up.Get("h_phi_reco_SPi_pos"), (TH1F*)f_up.Get("h_phi_reco_D0_pos"), (TH1F*)f_up.Get("h_phi_reco_Dst_pos")};

  vector <TH1F*> v_h_up_theta_pos = {(TH1F*)f_up.Get("h_theta_reco_Pi_pos"), (TH1F*)f_up.Get("h_theta_reco_K_pos"), (TH1F*)f_up.Get("h_theta_reco_SPi_pos"), (TH1F*)f_up.Get("h_theta_reco_D0_pos"), (TH1F*)f_up.Get("h_theta_reco_Dst_pos")};


  vector <TH1F*> v_h_up_eta_neg = {(TH1F*)f_dw.Get("h_eta_reco_Pi_neg"), (TH1F*)f_dw.Get("h_eta_reco_K_neg"), (TH1F*)f_dw.Get("h_eta_reco_SPi_neg"), (TH1F*)f_dw.Get("h_eta_reco_D0_neg"), (TH1F*)f_dw.Get("h_eta_reco_Dst_neg")};

  vector <TH1F*> v_h_up_pT_neg = {(TH1F*)f_dw.Get("h_pT_reco_Pi_neg"), (TH1F*)f_dw.Get("h_pT_reco_K_neg"), (TH1F*)f_dw.Get("h_pT_reco_SPi_neg"), (TH1F*)f_dw.Get("h_pT_reco_D0_neg"), (TH1F*)f_dw.Get("h_pT_reco_Dst_neg")};

  vector <TH1F*> v_h_up_phi_neg = {(TH1F*)f_dw.Get("h_phi_reco_Pi_neg"), (TH1F*)f_dw.Get("h_phi_reco_K_neg"), (TH1F*)f_dw.Get("h_phi_reco_SPi_neg"), (TH1F*)f_dw.Get("h_phi_reco_D0_neg"), (TH1F*)f_dw.Get("h_phi_reco_Dst_neg")};

  vector <TH1F*> v_h_up_theta_neg = {(TH1F*)f_dw.Get("h_theta_reco_Pi_neg"), (TH1F*)f_dw.Get("h_theta_reco_K_neg"), (TH1F*)f_dw.Get("h_theta_reco_SPi_neg"), (TH1F*)f_dw.Get("h_theta_reco_D0_neg"), (TH1F*)f_dw.Get("h_theta_reco_Dst_neg")};
  

  vector <TH1F*> v_h_dw_eta_pos = {(TH1F*)f_up.Get("h_eta_reco_Pi_pos"), (TH1F*)f_up.Get("h_eta_reco_K_pos"), (TH1F*)f_up.Get("h_eta_reco_SPi_pos"), (TH1F*)f_up.Get("h_eta_reco_D0_pos"), (TH1F*)f_up.Get("h_eta_reco_Dst_pos")};

  vector <TH1F*> v_h_dw_pT_pos = {(TH1F*)f_up.Get("h_pT_reco_Pi_pos"), (TH1F*)f_up.Get("h_pT_reco_K_pos"), (TH1F*)f_up.Get("h_pT_reco_SPi_pos"), (TH1F*)f_up.Get("h_pT_reco_D0_pos"), (TH1F*)f_up.Get("h_pT_reco_Dst_pos")};

  vector <TH1F*> v_h_dw_phi_pos = {(TH1F*)f_up.Get("h_phi_reco_Pi_pos"), (TH1F*)f_up.Get("h_phi_reco_K_pos"), (TH1F*)f_up.Get("h_phi_reco_SPi_pos"), (TH1F*)f_up.Get("h_phi_reco_D0_pos"), (TH1F*)f_up.Get("h_phi_reco_Dst_pos")};

  vector <TH1F*> v_h_dw_theta_pos = {(TH1F*)f_up.Get("h_theta_reco_Pi_pos"), (TH1F*)f_up.Get("h_theta_reco_K_pos"), (TH1F*)f_up.Get("h_theta_reco_SPi_pos"), (TH1F*)f_up.Get("h_theta_reco_D0_pos"), (TH1F*)f_up.Get("h_theta_reco_Dst_pos")};
 

  vector <TH1F*> v_h_dw_eta_neg = {(TH1F*)f_dw.Get("h_eta_reco_Pi_neg"), (TH1F*)f_dw.Get("h_eta_reco_K_neg"), (TH1F*)f_dw.Get("h_eta_reco_SPi_neg"), (TH1F*)f_dw.Get("h_eta_reco_D0_neg"), (TH1F*)f_dw.Get("h_eta_reco_Dst_neg")};

  vector <TH1F*> v_h_dw_pT_neg = {(TH1F*)f_dw.Get("h_pT_reco_Pi_neg"), (TH1F*)f_dw.Get("h_pT_reco_K_neg"), (TH1F*)f_dw.Get("h_pT_reco_SPi_neg"), (TH1F*)f_dw.Get("h_pT_reco_D0_neg"), (TH1F*)f_dw.Get("h_pT_reco_Dst_neg")};

  vector <TH1F*> v_h_dw_phi_neg = {(TH1F*)f_dw.Get("h_phi_reco_Pi_neg"), (TH1F*)f_dw.Get("h_phi_reco_K_neg"), (TH1F*)f_dw.Get("h_phi_reco_SPi_neg"), (TH1F*)f_dw.Get("h_phi_reco_D0_neg"), (TH1F*)f_dw.Get("h_phi_reco_Dst_neg")};

  vector <TH1F*> v_h_dw_theta_neg = {(TH1F*)f_dw.Get("h_theta_reco_Pi_neg"), (TH1F*)f_dw.Get("h_theta_reco_K_neg"), (TH1F*)f_dw.Get("h_theta_reco_SPi_neg"), (TH1F*)f_dw.Get("h_theta_reco_D0_neg"), (TH1F*)f_dw.Get("h_theta_reco_Dst_neg")};

  int size = v_h_dw_eta_pos.size();
  string save_name;
  TCanvas *c = new TCanvas();
  gStyle->SetOptStat(0);
  TF1 func("0*x", "0*x", -5., 9600.);
  for (int i =0; i < size;++i)
  {
    v_h_up_eta_pos.at(i)->Add(v_h_dw_eta_pos.at(i));
    v_h_up_eta_neg.at(i)->Add(v_h_dw_eta_neg.at(i));
    v_h_up_eta_pos.at(i)->Add(v_h_up_eta_neg.at(i), -1.);
    v_h_up_eta_neg.at(i)->Scale(2.);
    v_h_up_eta_neg.at(i)->Add(v_h_up_eta_pos.at(i));
    v_h_up_eta_pos.at(i)->Divide(v_h_up_eta_neg.at(i));
    save_name = "output/up_plus_down_pdf/eta_"+to_string(i)+".pdf";
    v_h_up_eta_pos.at(i)->Draw();
    func.Draw("same");
    c->SaveAs(save_name.c_str());
    v_h_up_pT_pos.at(i)->Add(v_h_dw_pT_pos.at(i));
    v_h_up_pT_neg.at(i)->Add(v_h_dw_pT_neg.at(i));
    v_h_up_pT_pos.at(i)->Add(v_h_up_pT_neg.at(i), -1.);
    v_h_up_pT_neg.at(i)->Scale(2.);
    v_h_up_pT_neg.at(i)->Add(v_h_up_pT_pos.at(i));
    v_h_up_pT_pos.at(i)->Divide(v_h_up_pT_neg.at(i));
    save_name = "output/up_plus_down_pdf/pT_"+to_string(i)+".pdf";
    v_h_up_pT_pos.at(i)->Draw();
    func.Draw("same");
    c->SaveAs(save_name.c_str());
    v_h_up_phi_pos.at(i)->Add(v_h_dw_phi_pos.at(i));
    v_h_up_phi_neg.at(i)->Add(v_h_dw_phi_neg.at(i));
    v_h_up_phi_pos.at(i)->Add(v_h_up_phi_neg.at(i), -1.);
    v_h_up_phi_neg.at(i)->Scale(2.);
    v_h_up_phi_neg.at(i)->Add(v_h_up_phi_pos.at(i));
    v_h_up_phi_pos.at(i)->Divide(v_h_up_phi_neg.at(i));
    save_name = "output/up_plus_down_pdf/phi_"+to_string(i)+".pdf";
    v_h_up_phi_pos.at(i)->Draw();
    func.Draw("same");
    c->SaveAs(save_name.c_str());
    v_h_up_theta_pos.at(i)->Add(v_h_dw_theta_pos.at(i));
    v_h_up_theta_neg.at(i)->Add(v_h_dw_theta_neg.at(i));
    v_h_up_theta_pos.at(i)->Add(v_h_up_theta_neg.at(i), -1.);
    v_h_up_theta_neg.at(i)->Scale(2.);
    v_h_up_theta_neg.at(i)->Add(v_h_up_theta_pos.at(i));
    v_h_up_theta_pos.at(i)->Divide(v_h_up_theta_neg.at(i));
    save_name = "output/up_plus_down_pdf/theta_"+to_string(i)+".pdf";
    v_h_up_theta_pos.at(i)->Draw();
    func.Draw("same");
    c->SaveAs(save_name.c_str());
  }
}
