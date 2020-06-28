#include "eff.h"
typedef unsigned int uint;
void printdevhists(vector<TH1F*> v_get_hist_pos, vector<TH1F*> v_get_hist_neg, string polarisation)
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
  string directory = polarisation+"_pdf";
  TCanvas *c = new TCanvas();
  string title_name;
  string new_title;
  string save_name;
  for (int i = 0; i < size; ++i)
  {
    v_hist_pos.at(i)->Add(v_hist_neg.at(i),-1);
    v_hist_neg.at(i)->Scale(2.);
    v_hist_neg.at(i)->Add(v_hist_pos.at(i));
    v_hist_pos.at(i)->Divide(v_hist_neg.at(i));
    title_name = v_hist_pos.at(i)->GetName();
    new_title = title_name+"_dev";
    v_hist_pos.at(i)->SetName(new_title.c_str());
    v_hist_pos.at(i)->Draw();
    func.Draw("same");
    save_name = "output/"+directory+"/new_deviation/"+new_title+".pdf";
    c->SaveAs(save_name.c_str());
  }
  cout << endl << "Asym: " << v_hist_pos.at(1)->GetSumOfWeights() << endl << endl;
}


void K_w()
{
    TFile f_up("output/histOut_minisample_Dst2D0pi_D02Kpi_2016_Up_GEN.root");
    TFile f_dw("output/histOut_minisample_Dst2D0pi_D02Kpi_2016_Dw_GEN.root");
    TFile f_all("output/histOut_all.root");


    string directory = "up_pdf";

    TCanvas *c = new TCanvas();
    vector<TH1F*> v_D0_p_r_u = {(TH1F*)f_up.Get("h_pT_reco_D0_pos"), (TH1F*)f_up.Get("h_eta_reco_D0_pos"), (TH1F*)f_up.Get("h_phi_reco_D0_pos"), (TH1F*)f_up.Get("h_theta_reco_D0_pos")};
    vector<TH1F*> v_Dst_p_r_u = {(TH1F*)f_up.Get("h_pT_reco_Dst_pos"), (TH1F*)f_up.Get("h_eta_reco_Dst_pos"), (TH1F*)f_up.Get("h_phi_reco_Dst_pos"), (TH1F*)f_up.Get("h_theta_reco_Dst_pos")};

    vector<TH1F*> v_D0_p_r_d= {(TH1F*)f_dw.Get("h_pT_reco_D0_pos"), (TH1F*)f_dw.Get("h_eta_reco_D0_pos"), (TH1F*)f_dw.Get("h_phi_reco_D0_pos"), (TH1F*)f_dw.Get("h_theta_reco_D0_pos")};
    vector<TH1F*> v_Dst_p_r_d= {(TH1F*)f_dw.Get("h_pT_reco_Dst_pos"), (TH1F*)f_dw.Get("h_eta_reco_Dst_pos"), (TH1F*)f_dw.Get("h_phi_reco_Dst_pos"), (TH1F*)f_dw.Get("h_theta_reco_Dst_pos")};

    vector<TH1F*> v_D0_p_r_a= {(TH1F*)f_all.Get("h_pT_reco_D0_pos"), (TH1F*)f_all.Get("h_eta_reco_D0_pos"), (TH1F*)f_all.Get("h_phi_reco_D0_pos"), (TH1F*)f_all.Get("h_theta_reco_D0_pos")};
    vector<TH1F*> v_Dst_p_r_a= {(TH1F*)f_all.Get("h_pT_reco_Dst_pos"), (TH1F*)f_all.Get("h_eta_reco_Dst_pos"), (TH1F*)f_all.Get("h_phi_reco_Dst_pos"), (TH1F*)f_all.Get("h_theta_reco_Dst_pos")};


    vector<TH1F*> v_D0_n_r_u = {(TH1F*)f_up.Get("h_pT_reco_D0_neg"), (TH1F*)f_up.Get("h_eta_reco_D0_neg"), (TH1F*)f_up.Get("h_phi_reco_D0_neg"), (TH1F*)f_up.Get("h_theta_reco_D0_neg")};
    vector<TH1F*> v_Dst_n_r_u = {(TH1F*)f_up.Get("h_pT_reco_Dst_neg"), (TH1F*)f_up.Get("h_eta_reco_Dst_neg"), (TH1F*)f_up.Get("h_phi_reco_Dst_neg"), (TH1F*)f_up.Get("h_theta_reco_Dst_neg")};

    vector<TH1F*> v_D0_n_r_d= {(TH1F*)f_dw.Get("h_pT_reco_D0_neg"), (TH1F*)f_dw.Get("h_eta_reco_D0_neg"), (TH1F*)f_dw.Get("h_phi_reco_D0_neg"), (TH1F*)f_dw.Get("h_theta_reco_D0_neg")};
    vector<TH1F*> v_Dst_n_r_d= {(TH1F*)f_dw.Get("h_pT_reco_Dst_neg"), (TH1F*)f_dw.Get("h_eta_reco_Dst_neg"), (TH1F*)f_dw.Get("h_phi_reco_Dst_neg"), (TH1F*)f_dw.Get("h_theta_reco_Dst_neg")};

    vector<TH1F*> v_D0_n_r_a= {(TH1F*)f_all.Get("h_pT_reco_D0_neg"), (TH1F*)f_all.Get("h_eta_reco_D0_neg"), (TH1F*)f_all.Get("h_phi_reco_D0_neg"), (TH1F*)f_all.Get("h_theta_reco_D0_neg")};
    vector<TH1F*> v_Dst_n_r_a= {(TH1F*)f_all.Get("h_pT_reco_Dst_neg"), (TH1F*)f_all.Get("h_eta_reco_Dst_neg"), (TH1F*)f_all.Get("h_phi_reco_Dst_neg"), (TH1F*)f_all.Get("h_theta_reco_Dst_neg")};


    for(uint i = 0; i < v_Dst_n_r_a.size(); ++i)
    {
      v_D0_n_r_a.at(i)->Scale(0.5);
      v_Dst_n_r_a.at(i)->Scale(0.5);
      v_D0_n_r_u.at(i)->Scale(0.5);
      v_Dst_n_r_u.at(i)->Scale(0.5);
      v_D0_n_r_d.at(i)->Scale(0.5);
      v_Dst_n_r_d.at(i)->Scale(0.5);

      v_D0_p_r_a.at(i)->Scale(0.850425/0.842585);
      v_Dst_p_r_a.at(i)->Scale(0.850425/0.842585);
      v_D0_p_r_u.at(i)->Scale(0.85017/0.842512);
      v_Dst_p_r_u.at(i)->Scale(0.85017/0.842512);
      v_D0_p_r_d.at(i)->Scale(0.850674/0.84266);
      v_Dst_p_r_d.at(i)->Scale(0.850674/0.84266);
    }
    printdevhists(v_D0_p_r_u, v_D0_n_r_u ,"up");
    printdevhists(v_D0_p_r_d, v_D0_n_r_d ,"down");
    printdevhists(v_D0_p_r_a, v_D0_n_r_a ,"up_down");
    printdevhists(v_Dst_p_r_u, v_Dst_n_r_u ,"up");
    printdevhists(v_Dst_p_r_d, v_Dst_n_r_d ,"down");
    printdevhists(v_Dst_p_r_a, v_Dst_n_r_a ,"up_down");


}
