#include "eff.h"

void up_plus_down_data()
{
  TFile f_up("output/histOut_D02Kmpip_15_Up.root.root");
  TFile f_dw("output/histOut_D02Kmpip_15_Dw.root.root");

 
  string save_name;
  TCanvas *c = new TCanvas();
  gStyle->SetOptStat(0);
  TF1 func("0*x", "0*x", -5., 9600.);
  for (int i =0; i < size;++i)
  {
    v_h_dev_up_eta.at(i)->Add(v_h_dev_dw_eta.at(i));
    save_name = "output/data/up_plus_down_pdf/eta_"+to_string(i)+".pdf";
    v_h_dev_up_eta.at(i)->Draw();
    func.Draw("same");
    c->SaveAs(save_name.c_str());
    v_h_dev_up_pT.at(i)->Add(v_h_dev_dw_pT.at(i));
    save_name = "output/data/up_plus_down_pdf/pT_"+to_string(i)+".pdf";
    v_h_dev_up_pT.at(i)->Draw();
    func.Draw("same");
    c->SaveAs(save_name.c_str());
    v_h_dev_up_phi.at(i)->Add(v_h_dev_dw_phi.at(i));
    save_name = "output/data/up_plus_down_pdf/phi_"+to_string(i)+".pdf";
    v_h_dev_up_phi.at(i)->Draw();
    func.Draw("same");
    c->SaveAs(save_name.c_str());
    v_h_dev_up_theta.at(i)->Add(v_h_dev_dw_theta.at(i));
    save_name = "output/data/up_plus_down_pdf/theta_"+to_string(i)+".pdf";
    v_h_dev_up_theta.at(i)->Draw();
    func.Draw("same");
    c->SaveAs(save_name.c_str());
  }
}
