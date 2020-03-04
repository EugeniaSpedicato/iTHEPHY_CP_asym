#include "eff.h"


void setcolors(vector<TH1F*> v_hist, vector<TH1F*> v_hist_pos, vector<TH1F*> v_hist_neg)
{
  int size = v_hist_pos.size();
  for(int i = 0; i < size; ++i)
  {
    v_hist_pos.at(i)->SetLineColor(kRed);
    v_hist_neg.at(i)->SetLineColor(kAzure);
    v_hist.at(i)->SetLineColor(kGreen);
  }
}


void setyaxis(vector<TH1F*> v_hist, vector<TH1F*> v_hist_pos, vector<TH1F*> v_hist_neg)
{
  int size = v_hist_pos.size();
  for(int i = 0; i < size; ++i)
  {
    v_hist_pos.at(i)->SetAxisRange(0.,1.,"Y");
    v_hist_neg.at(i)->SetAxisRange(0.,1.,"Y");
    v_hist.at(i)->SetAxisRange(0.,1.,"Y");
  }
}


void sumhisterr(vector<TH1F*> v_hist, vector<TH1F*> v_hist_pos, vector<TH1F*> v_hist_neg)
{
  int size = v_hist_pos.size();
  for(int i = 0; i < size; ++i)
  {
    v_hist_pos.at(i)->Sumw2();
    v_hist_neg.at(i)->Sumw2();
    v_hist.at(i)->Sumw2();
  }
}


void sethists(vector<TH1F*> v_hist, vector<TH1F*> v_hist_pos, vector<TH1F*> v_hist_neg)
{
  setyaxis(v_hist, v_hist_pos, v_hist_neg);
  setcolors(v_hist, v_hist_pos, v_hist_neg);
}

void printhists(vector<TH1F*> v_hist, vector<TH1F*> v_hist_pos, vector<TH1F*> v_hist_neg, string polarisation)
{
  int size = v_hist_pos.size();
  bool up_down = (polarisation == "UP")? true : false;
  string directory = (up_down == true)? "up_pdf" : "down_pdf";
  TCanvas *c = new TCanvas();
  string title_name;
  string save_name;
  for(int i = 0; i < size; ++i)
  {
    v_hist.at(i)->Draw();
    v_hist.at(i)->Draw("hist same");
    title_name = v_hist.at(i)->GetName();
    save_name = "output/"+directory+"/single/tot/"+title_name+".pdf";
    c->SaveAs(save_name.c_str());
    v_hist_pos.at(i)->Draw();
    v_hist_pos.at(i)->Draw("hist same");
    title_name = v_hist_pos.at(i)->GetName();
    save_name = "output/"+directory+"/single/pos/"+title_name+".pdf";
    c->SaveAs(save_name.c_str());
    v_hist_neg.at(i)->Draw();
    v_hist_neg.at(i)->Draw("hist same");
    title_name = v_hist_neg.at(i)->GetName();
    save_name = "output/"+directory+"/single/neg/"+title_name+".pdf";
    c->SaveAs(save_name.c_str());

    v_hist_pos.at(i)->Draw();
    v_hist_pos.at(i)->Draw("hist same");
    v_hist_neg.at(i)->Draw("same");
    v_hist_neg.at(i)->Draw("hist same");
    title_name = v_hist.at(i)->GetName();
    save_name = "output/"+directory+"/combined/"+title_name+".pdf";
    c->SaveAs(save_name.c_str());
  }
}
void printdevhists(vector<TH1F*> v_get_hist_pos, vector<TH1F*> v_get_hist_neg, string polarisation)
{
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
  TH1F *h_temp_pos = new TH1F(v_get_hist_pos.at(i)->GetName(),v_get_hist_pos.at(i)->GetName(), nbins, min, max);
  h_temp_pos->Add(v_get_hist_pos.at(i));
  v_hist_pos.push_back(h_temp_pos);
  nbins = v_get_hist_neg.at(i)->GetNbinsX();
  min = v_get_hist_neg.at(i)->GetXaxis()->GetBinLowEdge(1);
  max = v_get_hist_neg.at(i)->GetXaxis()->GetBinLowEdge(nbins) + v_get_hist_neg.at(i)->GetXaxis()->GetBinWidth(nbins);
  TH1F *h_temp_neg = new TH1F(v_get_hist_neg.at(i)->GetName(),v_get_hist_neg.at(i)->GetName(), nbins, min, max);
  h_temp_neg->Add(v_get_hist_neg.at(i));
  v_hist_neg.push_back(h_temp_neg);
  }  
  bool up_down = (polarisation == "UP")? true : false;
  string directory = (up_down == true)? "up_pdf" : "down_pdf";
  TCanvas *c = new TCanvas();
  string title_name;
  string new_title;
  string save_name;
  for (int i = 0; i < size; ++i)
  {
    //v_hist_pos.at(i)->Sumw2();
    //v_hist_neg.at(i)->Sumw2();
    v_hist_pos.at(i)->Add(v_hist_neg.at(i),-1);
    v_hist_neg.at(i)->Scale(2.);
    v_hist_neg.at(i)->Add(v_hist_pos.at(i));
    v_hist_pos.at(i)->Divide(v_hist_neg.at(i));
    v_hist_pos.at(i)->SetAxisRange(-0.15, 0.15, "Y");
    v_hist_pos.at(i)->Draw();
    title_name = v_hist_pos.at(i)->GetName();
    new_title = title_name+"_dev";
    v_hist_pos.at(i)->SetName(new_title.c_str());
    v_hist_pos.at(i)->SetTitle(new_title.c_str());
    v_hist_pos.at(i)->Write();
    save_name = "output/"+directory+"/deviation/"+new_title+".pdf";
    c->SaveAs(save_name.c_str());
  }
}

vector<double> get_eff(vector<double> v_n_ges, vector<double> v_n_reco)
{
  vector<double> v_eff = {};
  int size = v_n_reco.size();
  for(int i = 0; i < size; ++i)
  {
    v_eff.push_back(v_n_reco.at(i)/v_n_ges.at(i));
  }
  return v_eff;
}

vector<double> get_err(vector<double> v_eff, vector<double> v_n_ges)
{
  vector<double> v_err = {};
  int size = v_eff.size();
  for(int i = 0; i < size; ++i)
  {
    v_err.push_back(sqrt(v_eff.at(i) * (1 - v_eff.at(i))/v_n_ges.at(i)));
    //v_err.push_back((sqrt(v_eff.at(i)/n_ges + pow(v_eff.at(i),2.)/n_ges)));
  }
  return v_err;
}


vector<double> deviation(vector<double> v_eff_pos, vector<double> v_eff_neg)
{
  vector<double> v_dev = {};
  int size = v_eff_pos.size();
  for(int i = 0; i < size; ++i)
  {
  v_dev.push_back((v_eff_pos.at(i) - v_eff_neg.at(i)) / (v_eff_pos.at(i) + v_eff_neg.at(i)));
  }
  return v_dev;
}

vector<double> deviation_err(vector<double> v_eff_pos, vector<double> v_err_pos, vector<double> v_eff_neg, vector<double> v_err_neg)
{
  vector<double> v_dev_err ={};
  int size = v_eff_pos.size();
  for(int j = 0; j < size; ++j)
  {
    double dev_err = 2 * sqrt((pow(v_err_pos.at(j)*v_eff_neg.at(j),2.)+pow(v_err_neg.at(j)*v_eff_pos.at(j),2.)))/pow(v_eff_pos.at(j) + v_eff_neg.at(j), 2.);
    v_dev_err.push_back(dev_err);
  }
  return v_dev_err;

}

void hist_fill(vector<TH1F*> v_hist, vector<TH1F*> v_hist_reco, vector<TH1F*> v_hist_pos, vector<TH1F*> v_hist_reco_pos, vector<TH1F*> v_hist_neg, vector<TH1F*> v_hist_reco_neg, vector<double> v_var, int is_reco, double &n_reco, double &n_pos, double &n_reco_pos, int ID)
{
  int size = v_hist.size();
  for(int i = 0; i < size; ++i)
  {
    v_hist.at(i)->Fill(v_var.at(i));
  }
  if(ID > 0)
  {
    ++n_pos;
    for(int i = 0; i < size; ++i)
    {
      v_hist_pos.at(i)->Fill(v_var.at(i));
    }
  }
  else
  {
    for(int i = 0; i < size; ++i)
    {
      v_hist_neg.at(i)->Fill(v_var.at(i));
    }
  }
  if(is_reco == 1)
  {
    for(int i = 0; i < size; ++i)
    {
      v_hist_reco.at(i)->Fill(v_var.at(i));
    }
    ++n_reco;
    if(ID > 0)
    {
      ++n_reco_pos;
      for(int i = 0; i < size; ++i)
      {
        v_hist_reco_pos.at(i)->Fill(v_var.at(i));
      }
    }
    else
    {
      for(int i = 0; i < size; ++i)
      {
        v_hist_reco_neg.at(i)->Fill(v_var.at(i));
      }
    }
  }
}
void hist_divide(vector<TH1F*> v_hist, vector<TH1F*> v_hist_reco)
{
  int size = v_hist.size();
  for(int i = 0; i < size; ++i)
  {
    v_hist_reco.at(i)->Divide(v_hist.at(i));
  }
}

void eff(string dir, string sample, string polarisation)
{
  string input_name = dir+"/"+sample+".root";
  TChain *ntp = new TChain("ntp");
  ntp->Add(input_name.c_str());

  int nEvents = ntp->GetEntries();
  double nTot = double(nEvents);

  double nDst_pos = 0.;
  double nD0_pos = 0.;
  double nPi_pos = 0.;
  double nK_pos = 0.;
  double nSPi_pos = 0.;

  double nDst_neg = 0.;
  double nD0_neg = 0.;
  double nPi_neg = 0.;
  double nK_neg = 0.;
  double nSPi_neg = 0.;
  
  double nDst_reco = 0.;
  double nD0_reco = 0.;
  double nPi_reco = 0.;
  double nK_reco = 0.;
  double nSPi_reco = 0.;

  double nDst_reco_pos = 0.;
  double nD0_reco_pos = 0.;
  double nPi_reco_pos = 0.;
  double nK_reco_pos = 0.;
  double nSPi_reco_pos = 0.;

  double nDst_reco_neg = 0.;
  double nD0_reco_neg = 0.;
  double nPi_reco_neg = 0.;
  double nK_reco_neg = 0.;
  double nSPi_reco_neg = 0.;

  double Dst_pT, D0_pT, Pi_pT, K_pT, SPi_pT;

  double Dst_phi, D0_phi, Pi_phi, K_phi, SPi_phi;

  double Dst_theta, D0_theta, Pi_theta, K_theta, SPi_theta;

  double Dst_eta, D0_eta, Pi_eta, K_eta, SPi_eta;

  int Dst_ID, D0_ID, Pi_ID, K_ID, SPi_ID;

  int  isPi_reco, isK_reco, isSPi_reco, isD0_reco, isDst_reco;
  ntp->SetBranchStatus("*",0);
  ntp->SetBranchStatus("P1_Reconstructed",1); ntp->SetBranchAddress("P1_Reconstructed", &(isPi_reco));
  ntp->SetBranchStatus("P2_Reconstructed",1); ntp->SetBranchAddress("P2_Reconstructed", &(isK_reco));
  ntp->SetBranchStatus("sPi_Reconstructed",1); ntp->SetBranchAddress("sPi_Reconstructed", &(isSPi_reco));

  ntp->SetBranchStatus("Dst_PT",1); ntp->SetBranchAddress("Dst_PT", &(Dst_pT));
  ntp->SetBranchStatus("D0_PT",1); ntp->SetBranchAddress("D0_PT", &(D0_pT));
  ntp->SetBranchStatus("P1_PT",1); ntp->SetBranchAddress("P1_PT", &(Pi_pT));
  ntp->SetBranchStatus("P2_PT",1); ntp->SetBranchAddress("P2_PT", &(K_pT));
  ntp->SetBranchStatus("sPi_PT",1); ntp->SetBranchAddress("sPi_PT", &(SPi_pT));

  ntp->SetBranchStatus("Dst_PHI",1); ntp->SetBranchAddress("Dst_PHI", &(Dst_phi));
  ntp->SetBranchStatus("D0_PHI",1); ntp->SetBranchAddress("D0_PHI", &(D0_phi));
  ntp->SetBranchStatus("P1_PHI",1); ntp->SetBranchAddress("P1_PHI", &(Pi_phi));
  ntp->SetBranchStatus("P2_PHI",1); ntp->SetBranchAddress("P2_PHI", &(K_phi));
  ntp->SetBranchStatus("sPi_PHI",1); ntp->SetBranchAddress("sPi_PHI", &(SPi_phi));

  ntp->SetBranchStatus("Dst_THETA",1); ntp->SetBranchAddress("Dst_THETA", &(Dst_theta));
  ntp->SetBranchStatus("D0_THETA",1); ntp->SetBranchAddress("D0_THETA", &(D0_theta));
  ntp->SetBranchStatus("P1_THETA",1); ntp->SetBranchAddress("P1_THETA", &(Pi_theta));
  ntp->SetBranchStatus("P2_THETA",1); ntp->SetBranchAddress("P2_THETA", &(K_theta));
  ntp->SetBranchStatus("sPi_THETA",1); ntp->SetBranchAddress("sPi_THETA", &(SPi_theta));

  ntp->SetBranchStatus("Dst_ETA",1); ntp->SetBranchAddress("Dst_ETA", &(Dst_eta));
  ntp->SetBranchStatus("D0_ETA",1); ntp->SetBranchAddress("D0_ETA", &(D0_eta));
  ntp->SetBranchStatus("P1_ETA",1); ntp->SetBranchAddress("P1_ETA", &(Pi_eta));
  ntp->SetBranchStatus("P2_ETA",1); ntp->SetBranchAddress("P2_ETA", &(K_eta));
  ntp->SetBranchStatus("sPi_ETA",1); ntp->SetBranchAddress("sPi_ETA", &(SPi_eta));

  ntp->SetBranchStatus("Dst_ID",1); ntp->SetBranchAddress("Dst_ID", &(Dst_ID));
  ntp->SetBranchStatus("D0_ID",1); ntp->SetBranchAddress("D0_ID", &(D0_ID));
  ntp->SetBranchStatus("P1_ID",1); ntp->SetBranchAddress("P1_ID", &(Pi_ID));
  ntp->SetBranchStatus("P2_ID",1); ntp->SetBranchAddress("P2_ID", &(K_ID));
  ntp->SetBranchStatus("sPi_ID",1); ntp->SetBranchAddress("sPi_ID", &(SPi_ID));



  TH1F *h_pT_reco_SPi = new TH1F("h_pT_reco_SPi", ";p_{T}/MeV; reconstructed Events", 35, 100., 800.);
  TH1F *h_pT_reco_Pi = new TH1F("h_pT_reco_Pi", ";p_{T}/MeV; reconstructed Events", 50, 700., 5700.);
  TH1F *h_pT_reco_K = new TH1F("h_pT_reco_K", ";p_{T}/MeV; reconstructed Events", 57, 700., 6200.);
  TH1F *h_pT_reco_D0 = new TH1F("h_pT_reco_D0", ";p_{T}/MeV; reconstructed Events", 70, 2000., 9000.);
  TH1F *h_pT_reco_Dst = new TH1F("h_pT_reco_Dst", ";p_{T}/MeV; reconstructed Events", 74, 2200., 9600.);
  TH1F *h_pT_SPi = new TH1F("h_pT_SPi", ";p_{T}/MeV;Events", 35, 100., 800.);
  TH1F *h_pT_Pi = new TH1F("h_pT_Pi", ";p_{T}/MeV;Events", 50, 700., 5700.);
  TH1F *h_pT_K = new TH1F("h_pT_K", ";p_{T}/MeV;Events", 57, 700., 6200.);
  TH1F *h_pT_D0 = new TH1F("h_pT_D0", ";p_{T}/MeV;Events", 70, 2000., 9000.);
  TH1F *h_pT_Dst = new TH1F("h_pT_Dst", ";p_{T}/MeV;Events", 74, 2200., 9600.);

  TH1F *h_phi_reco_SPi = new TH1F("h_phi_reco_SPi", ";#phi; reconstructed Events", 50, -3.5, 3.5);
  TH1F *h_phi_reco_Pi = new TH1F("h_phi_reco_Pi", ";#phi; reconstructed Events", 50, -3.5, 3.5);
  TH1F *h_phi_reco_K = new TH1F("h_phi_reco_K", ";#phi; reconstructed Events", 50, -3.5, 3.5);
  TH1F *h_phi_reco_D0 = new TH1F("h_phi_reco_D0", ";#phi; reconstructed Events", 50, -3.5, 3.5);
  TH1F *h_phi_reco_Dst = new TH1F("h_phi_reco_Dst", ";#phi; reconstructed Events", 50, -3.5, 3.5);
  TH1F *h_phi_SPi = new TH1F("h_phi_SPi", ";#phi;Events", 50, -3.5, 3.5);
  TH1F *h_phi_Pi = new TH1F("h_phi_Pi", ";#phi;Events", 50, -3.5, 3.5);
  TH1F *h_phi_K = new TH1F("h_phi_K", ";#phi;Events", 50, -3.5, 3.5);
  TH1F *h_phi_D0 = new TH1F("h_phi_D0", ";#phi;Events", 50, -3.5, 3.5);
  TH1F *h_phi_Dst = new TH1F("h_phi_Dst", ";#phi;Events", 50, -3.5, 3.5);

  TH1F *h_eta_reco_SPi = new TH1F("h_eta_reco_SPi", ";#eta; reconstructed Events", 50, 2.0, 4.5);
  TH1F *h_eta_reco_Pi = new TH1F("h_eta_reco_Pi", ";#eta; reconstructed Events", 50, 2.0, 4.5);
  TH1F *h_eta_reco_K = new TH1F("h_eta_reco_K", ";#eta; reconstructed Events", 50, 2.0, 4.5);
  TH1F *h_eta_reco_D0 = new TH1F("h_eta_reco_D0", ";#eta; reconstructed Events", 50, 2.0, 4.5);
  TH1F *h_eta_reco_Dst = new TH1F("h_eta_reco_Dst", ";#eta; reconstructed Events", 50, 2.0, 4.5);
  TH1F *h_eta_SPi = new TH1F("h_eta_SPi", ";#eta;Events", 50, 2.0, 4.5);
  TH1F *h_eta_Pi = new TH1F("h_eta_Pi", ";#eta;Events", 50, 2.0, 4.5);
  TH1F *h_eta_K = new TH1F("h_eta_K", ";#eta;Events", 50, 2.0, 4.5);
  TH1F *h_eta_D0 = new TH1F("h_eta_D0", ";#eta;Events", 50, 2.0, 4.5);
  TH1F *h_eta_Dst = new TH1F("h_eta_Dst", ";#eta;Events", 50, 2.0, 4.5);

  TH1F *h_theta_reco_SPi = new TH1F("h_theta_reco_SPi", ";#theta; reconstructed Events", 50, 0.02, 0.24);
  TH1F *h_theta_reco_Pi = new TH1F("h_theta_reco_Pi", ";#theta; reconstructed Events", 50, 0.02, 0.24);
  TH1F *h_theta_reco_K = new TH1F("h_theta_reco_K", ";#theta; reconstructed Events", 50, 0.02, 0.24);
  TH1F *h_theta_reco_D0 = new TH1F("h_theta_reco_D0", ";#theta; reconstructed Events", 50, 0.02, 0.24);
  TH1F *h_theta_reco_Dst = new TH1F("h_theta_reco_Dst", ";#theta; reconstructed Events", 50, 0.02, 0.24);
  TH1F *h_theta_SPi = new TH1F("h_theta_SPi", ";#theta;Events", 50, 0.02, 0.24);
  TH1F *h_theta_Pi = new TH1F("h_theta_Pi", ";#theta;Events", 50, 0.02, 0.24);
  TH1F *h_theta_K = new TH1F("h_theta_K", ";#theta;Events", 50, 0.02, 0.24);
  TH1F *h_theta_D0 = new TH1F("h_theta_D0", ";#theta;Events", 50, 0.02, 0.24);
  TH1F *h_theta_Dst = new TH1F("h_theta_Dst", ";#theta;Events", 50, 0.02, 0.24);


  TH1F *h_pT_reco_SPi_pos = new TH1F("h_pT_reco_SPi_pos", ";p_{T}/MeV; reconstructed Events", 35, 100., 800.);
  TH1F *h_pT_reco_Pi_pos = new TH1F("h_pT_reco_Pi_pos", ";p_{T}/MeV; reconstructed Events", 50, 700., 5700.);
  TH1F *h_pT_reco_K_pos = new TH1F("h_pT_reco_K_pos", ";p_{T}/MeV; reconstructed Events", 57, 700., 6200.);
  TH1F *h_pT_reco_D0_pos = new TH1F("h_pT_reco_D0_pos", ";p_{T}/MeV; reconstructed Events", 70, 2000., 9000.);
  TH1F *h_pT_reco_Dst_pos = new TH1F("h_pT_reco_Dst_pos", ";p_{T}/MeV; reconstructed Events", 74, 2200., 9600.);
  TH1F *h_pT_SPi_pos = new TH1F("h_pT_SPi_pos", ";p_{T}/MeV;Events", 35, 100., 800.);
  TH1F *h_pT_Pi_pos = new TH1F("h_pT_Pi_pos", ";p_{T}/MeV;Events", 50, 700., 5700.);
  TH1F *h_pT_K_pos = new TH1F("h_pT_K_pos", ";p_{T}/MeV;Events", 57, 700., 6200.);
  TH1F *h_pT_D0_pos = new TH1F("h_pT_D0_pos", ";p_{T}/MeV;Events", 70, 2000., 9000.);
  TH1F *h_pT_Dst_pos = new TH1F("h_pT_Dst_pos", ";p_{T}/MeV;Events", 74, 2200., 9600.);

  TH1F *h_phi_reco_SPi_pos = new TH1F("h_phi_reco_SPi_pos", ";#phi; reconstructed Events", 50, -3.5, 3.5);
  TH1F *h_phi_reco_Pi_pos = new TH1F("h_phi_reco_Pi_pos", ";#phi; reconstructed Events", 50, -3.5, 3.5);
  TH1F *h_phi_reco_K_pos = new TH1F("h_phi_reco_K_pos", ";#phi; reconstructed Events", 50, -3.5, 3.5);
  TH1F *h_phi_reco_D0_pos = new TH1F("h_phi_reco_D0_pos", ";#phi; reconstructed Events", 50, -3.5, 3.5);
  TH1F *h_phi_reco_Dst_pos = new TH1F("h_phi_reco_Dst_pos", ";#phi; reconstructed Events", 50, -3.5, 3.5);
  TH1F *h_phi_SPi_pos = new TH1F("h_phi_SPi_pos", ";#phi;Events", 50, -3.5, 3.5);
  TH1F *h_phi_Pi_pos = new TH1F("h_phi_Pi_pos", ";#phi;Events", 50, -3.5, 3.5);
  TH1F *h_phi_K_pos = new TH1F("h_phi_K_pos", ";#phi;Events", 50, -3.5, 3.5);
  TH1F *h_phi_D0_pos = new TH1F("h_phi_D0_pos", ";#phi;Events", 50, -3.5, 3.5);
  TH1F *h_phi_Dst_pos = new TH1F("h_phi_Dst_pos", ";#phi;Events", 50, -3.5, 3.5);

  TH1F *h_eta_reco_SPi_pos = new TH1F("h_eta_reco_SPi_pos", ";#eta; reconstructed Events", 50, 2.0, 4.5);
  TH1F *h_eta_reco_Pi_pos = new TH1F("h_eta_reco_Pi_pos", ";#eta; reconstructed Events", 50, 2.0, 4.5);
  TH1F *h_eta_reco_K_pos = new TH1F("h_eta_reco_K_pos", ";#eta; reconstructed Events", 50, 2.0, 4.5);
  TH1F *h_eta_reco_D0_pos = new TH1F("h_eta_reco_D0_pos", ";#eta; reconstructed Events", 50, 2.0, 4.5);
  TH1F *h_eta_reco_Dst_pos = new TH1F("h_eta_reco_Dst_pos", ";#eta; reconstructed Events", 50, 2.0, 4.5);
  TH1F *h_eta_SPi_pos = new TH1F("h_eta_SPi_pos", ";#eta;Events", 50, 2.0, 4.5);
  TH1F *h_eta_Pi_pos = new TH1F("h_eta_Pi_pos", ";#eta;Events", 50, 2.0, 4.5);
  TH1F *h_eta_K_pos = new TH1F("h_eta_K_pos", ";#eta;Events", 50, 2.0, 4.5);
  TH1F *h_eta_D0_pos = new TH1F("h_eta_D0_pos", ";#eta;Events", 50, 2.0, 4.5);
  TH1F *h_eta_Dst_pos = new TH1F("h_eta_Dst_pos", ";#eta;Events", 50, 2.0, 4.5);

  TH1F *h_theta_reco_SPi_pos = new TH1F("h_theta_reco_SPi_pos", ";#theta; reconstructed Events", 50, 0.02, 0.24);
  TH1F *h_theta_reco_Pi_pos = new TH1F("h_theta_reco_Pi_pos", ";#theta; reconstructed Events", 50, 0.02, 0.24);
  TH1F *h_theta_reco_K_pos = new TH1F("h_theta_reco_K_pos", ";#theta; reconstructed Events", 50, 0.02, 0.24);
  TH1F *h_theta_reco_D0_pos = new TH1F("h_theta_reco_D0_pos", ";#theta; reconstructed Events", 50, 0.02, 0.24);
  TH1F *h_theta_reco_Dst_pos = new TH1F("h_theta_reco_Dst_pos", ";#theta; reconstructed Events", 50, 0.02, 0.24);
  TH1F *h_theta_SPi_pos = new TH1F("h_theta_SPi_pos", ";#theta;Events", 50, 0.02, 0.24);
  TH1F *h_theta_Pi_pos = new TH1F("h_theta_Pi_pos", ";#theta;Events", 50, 0.02, 0.24);
  TH1F *h_theta_K_pos = new TH1F("h_theta_K_pos", ";#theta;Events", 50, 0.02, 0.24);
  TH1F *h_theta_D0_pos = new TH1F("h_theta_D0_pos", ";#theta;Events", 50, 0.02, 0.24);
  TH1F *h_theta_Dst_pos = new TH1F("h_theta_Dst_pos", ";#theta;Events", 50, 0.02, 0.24);


  TH1F *h_pT_reco_SPi_neg = new TH1F("h_pT_reco_SPi_neg", ";p_{T}/MeV; reconstructed Events", 35, 100., 800.);
  TH1F *h_pT_reco_Pi_neg = new TH1F("h_pT_reco_Pi_neg", ";p_{T}/MeV; reconstructed Events", 50, 700., 5700.);
  TH1F *h_pT_reco_K_neg = new TH1F("h_pT_reco_K_neg", ";p_{T}/MeV; reconstructed Events", 57, 700., 6200.);
  TH1F *h_pT_reco_D0_neg = new TH1F("h_pT_reco_D0_neg", ";p_{T}/MeV; reconstructed Events", 70, 2000., 9000.);
  TH1F *h_pT_reco_Dst_neg = new TH1F("h_pT_reco_Dst_neg", ";p_{T}/MeV; reconstructed Events", 74, 2200., 9600.);
  TH1F *h_pT_SPi_neg = new TH1F("h_pT_SPi_neg", ";p_{T}/MeV;Events", 35, 100., 800.);
  TH1F *h_pT_Pi_neg = new TH1F("h_pT_Pi_neg", ";p_{T}/MeV;Events", 50, 700., 5700.);
  TH1F *h_pT_K_neg = new TH1F("h_pT_K_neg", ";p_{T}/MeV;Events", 57, 700., 6200.);
  TH1F *h_pT_D0_neg = new TH1F("h_pT_D0_neg", ";p_{T}/MeV;Events", 70, 2000., 9000.);
  TH1F *h_pT_Dst_neg = new TH1F("h_pT_Dst_neg", ";p_{T}/MeV;Events", 74, 2200., 9600.);

  TH1F *h_phi_reco_SPi_neg = new TH1F("h_phi_reco_SPi_neg", ";#phi; reconstructed Events", 50, -3.5, 3.5);
  TH1F *h_phi_reco_Pi_neg = new TH1F("h_phi_reco_Pi_neg", ";#phi; reconstructed Events", 50, -3.5, 3.5);
  TH1F *h_phi_reco_K_neg = new TH1F("h_phi_reco_K_neg", ";#phi; reconstructed Events", 50, -3.5, 3.5);
  TH1F *h_phi_reco_D0_neg = new TH1F("h_phi_reco_D0_neg", ";#phi; reconstructed Events", 50, -3.5, 3.5);
  TH1F *h_phi_reco_Dst_neg = new TH1F("h_phi_reco_Dst_neg", ";#phi; reconstructed Events", 50, -3.5, 3.5);
  TH1F *h_phi_SPi_neg = new TH1F("h_phi_SPi_neg", ";#phi;Events", 50, -3.5, 3.5);
  TH1F *h_phi_Pi_neg = new TH1F("h_phi_Pi_neg", ";#phi;Events", 50, -3.5, 3.5);
  TH1F *h_phi_K_neg = new TH1F("h_phi_K_neg", ";#phi;Events", 50, -3.5, 3.5);
  TH1F *h_phi_D0_neg = new TH1F("h_phi_D0_neg", ";#phi;Events", 50, -3.5, 3.5);
  TH1F *h_phi_Dst_neg = new TH1F("h_phi_Dst_neg", ";#phi;Events", 50, -3.5, 3.5);

  TH1F *h_eta_reco_SPi_neg = new TH1F("h_eta_reco_SPi_neg", ";#eta; reconstructed Events", 50, 2.0, 4.5);
  TH1F *h_eta_reco_Pi_neg = new TH1F("h_eta_reco_Pi_neg", ";#eta; reconstructed Events", 50, 2.0, 4.5);
  TH1F *h_eta_reco_K_neg = new TH1F("h_eta_reco_K_neg", ";#eta; reconstructed Events", 50, 2.0, 4.5);
  TH1F *h_eta_reco_D0_neg = new TH1F("h_eta_reco_D0_neg", ";#eta; reconstructed Events", 50, 2.0, 4.5);
  TH1F *h_eta_reco_Dst_neg = new TH1F("h_eta_reco_Dst_neg", ";#eta; reconstructed Events", 50, 2.0, 4.5);
  TH1F *h_eta_SPi_neg = new TH1F("h_eta_SPi_neg", ";#eta;Events", 50, 2.0, 4.5);
  TH1F *h_eta_Pi_neg = new TH1F("h_eta_Pi_neg", ";#eta;Events", 50, 2.0, 4.5);
  TH1F *h_eta_K_neg = new TH1F("h_eta_K_neg", ";#eta;Events", 50, 2.0, 4.5);
  TH1F *h_eta_D0_neg = new TH1F("h_eta_D0_neg", ";#eta;Events", 50, 2.0, 4.5);
  TH1F *h_eta_Dst_neg = new TH1F("h_eta_Dst_neg", ";#eta;Events", 50, 2.0, 4.5);

  TH1F *h_theta_reco_SPi_neg = new TH1F("h_theta_reco_SPi_neg", ";#theta; reconstructed Events", 50, 0.02, 0.24);
  TH1F *h_theta_reco_Pi_neg = new TH1F("h_theta_reco_Pi_neg", ";#theta; reconstructed Events", 50, 0.02, 0.24);
  TH1F *h_theta_reco_K_neg = new TH1F("h_theta_reco_K_neg", ";#theta; reconstructed Events", 50, 0.02, 0.24);
  TH1F *h_theta_reco_D0_neg = new TH1F("h_theta_reco_D0_neg", ";#theta; reconstructed Events", 50, 0.02, 0.24);
  TH1F *h_theta_reco_Dst_neg = new TH1F("h_theta_reco_Dst_neg", ";#theta; reconstructed Events", 50, 0.02, 0.24);
  TH1F *h_theta_SPi_neg = new TH1F("h_theta_SPi_neg", ";#theta;Events", 50, 0.02, 0.24);
  TH1F *h_theta_Pi_neg = new TH1F("h_theta_Pi_neg", ";#theta;Events", 50, 0.02, 0.24);
  TH1F *h_theta_K_neg = new TH1F("h_theta_K_neg", ";#theta;Events", 50, 0.02, 0.24);
  TH1F *h_theta_D0_neg = new TH1F("h_theta_D0_neg", ";#theta;Events", 50, 0.02, 0.24);
  TH1F *h_theta_Dst_neg = new TH1F("h_theta_Dst_neg", ";#theta;Events", 50, 0.02, 0.24);


  vector<TH1F*> v_Pi_hist_reco = {h_pT_reco_Pi, h_phi_reco_Pi, h_theta_reco_Pi, h_eta_reco_Pi};
  vector<TH1F*> v_SPi_hist_reco = {h_pT_reco_SPi, h_phi_reco_SPi, h_theta_reco_SPi, h_eta_reco_SPi};
  vector<TH1F*> v_K_hist_reco = {h_pT_reco_K, h_phi_reco_K, h_theta_reco_K, h_eta_reco_K};
  vector<TH1F*> v_D0_hist_reco = {h_pT_reco_D0, h_phi_reco_D0, h_theta_reco_D0, h_eta_reco_D0};
  vector<TH1F*> v_Dst_hist_reco = {h_pT_reco_Dst, h_phi_reco_Dst, h_theta_reco_Dst, h_eta_reco_Dst};

  vector<TH1F*> v_Pi_hist = {h_pT_Pi, h_phi_Pi, h_theta_Pi, h_eta_Pi};
  vector<TH1F*> v_SPi_hist = {h_pT_SPi, h_phi_SPi, h_theta_SPi, h_eta_SPi};
  vector<TH1F*> v_K_hist = {h_pT_K, h_phi_K, h_theta_K, h_eta_K};
  vector<TH1F*> v_D0_hist = {h_pT_D0, h_phi_D0, h_theta_D0, h_eta_D0};
  vector<TH1F*> v_Dst_hist = {h_pT_Dst, h_phi_Dst, h_theta_Dst, h_eta_Dst};


  vector<TH1F*> v_Pi_hist_reco_pos = {h_pT_reco_Pi_pos, h_phi_reco_Pi_pos, h_theta_reco_Pi_pos, h_eta_reco_Pi_pos};
  vector<TH1F*> v_SPi_hist_reco_pos = {h_pT_reco_SPi_pos, h_phi_reco_SPi_pos, h_theta_reco_SPi_pos, h_eta_reco_SPi_pos};
  vector<TH1F*> v_K_hist_reco_pos = {h_pT_reco_K_pos, h_phi_reco_K_pos, h_theta_reco_K_pos, h_eta_reco_K_pos};
  vector<TH1F*> v_D0_hist_reco_pos = {h_pT_reco_D0_pos, h_phi_reco_D0_pos, h_theta_reco_D0_pos, h_eta_reco_D0_pos};
  vector<TH1F*> v_Dst_hist_reco_pos = {h_pT_reco_Dst_pos, h_phi_reco_Dst_pos, h_theta_reco_Dst_pos, h_eta_reco_Dst_pos};

  vector<TH1F*> v_Pi_hist_pos = {h_pT_Pi_pos, h_phi_Pi_pos, h_theta_Pi_pos, h_eta_Pi_pos};
  vector<TH1F*> v_SPi_hist_pos = {h_pT_SPi_pos, h_phi_SPi_pos, h_theta_SPi_pos, h_eta_SPi_pos};
  vector<TH1F*> v_K_hist_pos = {h_pT_K_pos, h_phi_K_pos, h_theta_K_pos, h_eta_K_pos};
  vector<TH1F*> v_D0_hist_pos = {h_pT_D0_pos, h_phi_D0_pos, h_theta_D0_pos, h_eta_D0_pos};
  vector<TH1F*> v_Dst_hist_pos = {h_pT_Dst_pos, h_phi_Dst_pos, h_theta_Dst_pos, h_eta_Dst_pos};


  vector<TH1F*> v_Pi_hist_reco_neg = {h_pT_reco_Pi_neg, h_phi_reco_Pi_neg, h_theta_reco_Pi_neg, h_eta_reco_Pi_neg};
  vector<TH1F*> v_SPi_hist_reco_neg = {h_pT_reco_SPi_neg, h_phi_reco_SPi_neg, h_theta_reco_SPi_neg, h_eta_reco_SPi_neg};
  vector<TH1F*> v_K_hist_reco_neg = {h_pT_reco_K_neg, h_phi_reco_K_neg, h_theta_reco_K_neg, h_eta_reco_K_neg};
  vector<TH1F*> v_D0_hist_reco_neg = {h_pT_reco_D0_neg, h_phi_reco_D0_neg, h_theta_reco_D0_neg, h_eta_reco_D0_neg};
  vector<TH1F*> v_Dst_hist_reco_neg = {h_pT_reco_Dst_neg, h_phi_reco_Dst_neg, h_theta_reco_Dst_neg, h_eta_reco_Dst_neg};

  vector<TH1F*> v_Pi_hist_neg = {h_pT_Pi_neg, h_phi_Pi_neg, h_theta_Pi_neg, h_eta_Pi_neg};
  vector<TH1F*> v_SPi_hist_neg = {h_pT_SPi_neg, h_phi_SPi_neg, h_theta_SPi_neg, h_eta_SPi_neg};
  vector<TH1F*> v_K_hist_neg = {h_pT_K_neg, h_phi_K_neg, h_theta_K_neg, h_eta_K_neg};
  vector<TH1F*> v_D0_hist_neg = {h_pT_D0_neg, h_phi_D0_neg, h_theta_D0_neg, h_eta_D0_neg};
  vector<TH1F*> v_Dst_hist_neg = {h_pT_Dst_neg, h_phi_Dst_neg, h_theta_Dst_neg, h_eta_Dst_neg};

  sumhisterr(v_Pi_hist, v_Pi_hist_pos, v_Pi_hist_neg);
  sumhisterr(v_SPi_hist, v_SPi_hist_pos, v_SPi_hist_neg);
  sumhisterr(v_K_hist, v_K_hist_pos, v_K_hist_neg);
  sumhisterr(v_D0_hist, v_D0_hist_pos, v_D0_hist_neg);
  sumhisterr(v_Dst_hist, v_Dst_hist_pos, v_Dst_hist_neg);

  sumhisterr(v_Pi_hist_reco, v_Pi_hist_reco_pos, v_Pi_hist_reco_neg);
  sumhisterr(v_SPi_hist_reco, v_SPi_hist_reco_pos, v_SPi_hist_reco_neg);
  sumhisterr(v_K_hist_reco, v_K_hist_reco_pos, v_K_hist_reco_neg);
  sumhisterr(v_D0_hist_reco, v_D0_hist_reco_pos, v_D0_hist_reco_neg);
  sumhisterr(v_Dst_hist_reco, v_Dst_hist_reco_pos, v_Dst_hist_reco_neg);


  for(int i = 0; i < nEvents; ++i)
  {
    ntp->GetEvent(i);
    if (i % (nEvents/10) == 0)cout << "=== Event " << i/(nEvents/10) * 10 << "%" << endl;

    vector<double> v_Pi_var = {Pi_pT, Pi_phi, Pi_theta, Pi_eta};
    vector<double> v_K_var = {K_pT, K_phi, K_theta, K_eta};
    vector<double> v_SPi_var = {SPi_pT, SPi_phi, SPi_theta, SPi_eta};
    vector<double> v_D0_var = {D0_pT, D0_phi, D0_theta, D0_eta};
    vector<double> v_Dst_var = {Dst_pT, Dst_phi, Dst_theta, Dst_eta};

    (isPi_reco == 1 && isK_reco == 1)? isD0_reco = 1 : isD0_reco = 0;
    (isSPi_reco == 1 && isD0_reco == 1)? isDst_reco = 1 : isDst_reco = 0;

    hist_fill(v_Pi_hist, v_Pi_hist_reco, v_Pi_hist_pos, v_Pi_hist_reco_pos, v_Pi_hist_neg, v_Pi_hist_reco_neg, v_Pi_var, isPi_reco, nPi_reco, nPi_pos, nPi_reco_pos, Pi_ID);
    hist_fill(v_K_hist, v_K_hist_reco, v_K_hist_pos, v_K_hist_reco_pos, v_K_hist_neg, v_K_hist_reco_neg, v_K_var, isK_reco, nK_reco, nK_pos, nK_reco_pos, K_ID);
    hist_fill(v_SPi_hist, v_SPi_hist_reco, v_SPi_hist_pos, v_SPi_hist_reco_pos, v_SPi_hist_neg, v_SPi_hist_reco_neg, v_SPi_var, isSPi_reco, nSPi_reco, nSPi_pos, nSPi_reco_pos, SPi_ID);
    hist_fill(v_D0_hist, v_D0_hist_reco, v_D0_hist_pos, v_D0_hist_reco_pos, v_D0_hist_neg, v_D0_hist_reco_neg, v_D0_var, isD0_reco, nD0_reco, nD0_pos, nD0_reco_pos, D0_ID);
    hist_fill(v_Dst_hist, v_Dst_hist_reco, v_Dst_hist_pos, v_Dst_hist_reco_pos, v_Dst_hist_neg, v_Dst_hist_reco_neg, v_Dst_var, isDst_reco, nDst_reco, nDst_pos, nDst_reco_pos, Dst_ID);

    v_Pi_var.clear();
    v_K_var.clear();
    v_SPi_var.clear();
    v_D0_var.clear();
    v_Dst_var.clear();
  }
  nPi_neg = nTot - nPi_pos;
  nK_neg = nTot - nK_pos;
  nSPi_neg = nTot - nSPi_pos;
  nD0_neg = nTot - nD0_pos;
  nDst_neg = nTot - nDst_pos;
 
  nPi_reco_neg = nPi_reco - nPi_reco_pos;
  nK_reco_neg = nK_reco - nK_reco_pos;
  nSPi_reco_neg = nSPi_reco - nSPi_reco_pos;
  nD0_reco_neg = nD0_reco - nD0_reco_pos;
  nDst_reco_neg = nDst_reco - nDst_reco_pos;


  vector<double> v_n_reco_ges = {nPi_reco,nK_reco,nSPi_reco,nD0_reco,nDst_reco};
  vector<double> v_n_reco_pos = {nPi_reco_pos,nK_reco_pos,nSPi_reco_pos,nD0_reco_pos,nDst_reco_pos};
  vector<double> v_n_reco_neg = {nPi_reco_neg,nK_reco_neg,nSPi_reco_neg,nD0_reco_neg,nDst_reco_neg};
  vector<double> v_n_pos = {nPi_pos, nK_pos, nSPi_pos, nD0_pos, nDst_pos};
  vector<double> v_n_neg = {nPi_neg, nK_neg, nSPi_neg, nD0_neg, nDst_neg};
  vector<double> v_nEvents = {nTot, nTot, nTot, nTot, nTot};

  vector<double> v_eff_ges = get_eff(v_nEvents,v_n_reco_ges);
  vector<double> v_eff_pos = get_eff(v_n_pos,v_n_reco_pos);
  vector<double> v_eff_neg = get_eff(v_n_neg,v_n_reco_neg);

  vector<double> v_err_ges = get_err(v_eff_ges,v_nEvents);
  vector<double> v_err_pos = get_err(v_eff_pos,v_n_pos);
  vector<double> v_err_neg = get_err(v_eff_neg,v_n_neg);

  vector<double> v_dev = deviation(v_eff_pos,v_eff_neg);
  vector<double> v_dev_err = deviation_err(v_eff_pos,v_err_pos,v_eff_neg,v_err_neg);

  
  string output_hist_name;
  output_hist_name = "output/histOut_"+sample+".root";
  TFile *out_hist_fi = new TFile(output_hist_name.c_str(),"RECREATE");
  
  printdevhists(v_Pi_hist_reco_pos, v_Pi_hist_reco_neg, polarisation);
  printdevhists(v_SPi_hist_reco_pos, v_SPi_hist_reco_neg, polarisation);
  printdevhists(v_K_hist_reco_pos, v_K_hist_reco_neg, polarisation);
  printdevhists(v_D0_hist_reco_pos, v_D0_hist_reco_neg, polarisation);
  printdevhists(v_Dst_hist_reco_pos, v_Dst_hist_reco_neg, polarisation);
  
  hist_divide(v_Pi_hist,v_Pi_hist_reco);
  hist_divide(v_K_hist,v_K_hist_reco);
  hist_divide(v_SPi_hist,v_SPi_hist_reco);
  hist_divide(v_D0_hist,v_D0_hist_reco);
  hist_divide(v_Dst_hist,v_Dst_hist_reco);

  hist_divide(v_Pi_hist_pos,v_Pi_hist_reco_pos);
  hist_divide(v_K_hist_pos,v_K_hist_reco_pos);
  hist_divide(v_SPi_hist_pos,v_SPi_hist_reco_pos);
  hist_divide(v_D0_hist_pos,v_D0_hist_reco_pos);
  hist_divide(v_Dst_hist_pos,v_Dst_hist_reco_pos);

  hist_divide(v_Pi_hist_neg,v_Pi_hist_reco_neg);
  hist_divide(v_K_hist_neg,v_K_hist_reco_neg);
  hist_divide(v_SPi_hist_neg,v_SPi_hist_reco_neg);
  hist_divide(v_D0_hist_neg,v_D0_hist_reco_neg);
  hist_divide(v_Dst_hist_neg,v_Dst_hist_reco_neg);


  h_pT_reco_Pi->Write();
  h_pT_reco_K->Write();
  h_pT_reco_SPi->Write();
  h_pT_reco_D0->Write();
  h_pT_reco_Dst->Write();

  h_phi_reco_Pi->Write();
  h_phi_reco_K->Write();
  h_phi_reco_SPi->Write();
  h_phi_reco_D0->Write();
  h_phi_reco_Dst->Write();

  h_theta_reco_Pi->Write();
  h_theta_reco_K->Write();
  h_theta_reco_SPi->Write();
  h_theta_reco_D0->Write();
  h_theta_reco_Dst->Write();

  h_eta_reco_Pi->Write();
  h_eta_reco_K->Write();
  h_eta_reco_SPi->Write();
  h_eta_reco_D0->Write();
  h_eta_reco_Dst->Write();


  h_pT_reco_Pi_pos->Write();
  h_pT_reco_K_pos->Write();
  h_pT_reco_SPi_pos->Write();
  h_pT_reco_D0_pos->Write();
  h_pT_reco_Dst_pos->Write();

  h_phi_reco_Pi_pos->Write();
  h_phi_reco_K_pos->Write();
  h_phi_reco_SPi_pos->Write();
  h_phi_reco_D0_pos->Write();
  h_phi_reco_Dst_pos->Write();

  h_theta_reco_Pi_pos->Write();
  h_theta_reco_K_pos->Write();
  h_theta_reco_SPi_pos->Write();
  h_theta_reco_D0_pos->Write();
  h_theta_reco_Dst_pos->Write();

  h_eta_reco_Pi_pos->Write();
  h_eta_reco_K_pos->Write();
  h_eta_reco_SPi_pos->Write();
  h_eta_reco_D0_pos->Write();
  h_eta_reco_Dst_pos->Write();



  h_pT_reco_Pi_neg->Write();
  h_pT_reco_K_neg->Write();
  h_pT_reco_SPi_neg->Write();
  h_pT_reco_D0_neg->Write();
  h_pT_reco_Dst_neg->Write();

  h_phi_reco_Pi_neg->Write();
  h_phi_reco_K_neg->Write();
  h_phi_reco_SPi_neg->Write();
  h_phi_reco_D0_neg->Write();
  h_phi_reco_Dst_neg->Write();

  h_theta_reco_Pi_neg->Write();
  h_theta_reco_K_neg->Write();
  h_theta_reco_SPi_neg->Write();
  h_theta_reco_D0_neg->Write();
  h_theta_reco_Dst_neg->Write();

  h_eta_reco_Pi_neg->Write();
  h_eta_reco_K_neg->Write();
  h_eta_reco_SPi_neg->Write();
  h_eta_reco_D0_neg->Write();
  h_eta_reco_Dst_neg->Write();




  out_hist_fi->Write();
  out_hist_fi->Close();

  double dev_Pi = (nPi_reco_pos - nPi_reco_neg)/(nPi_reco_pos + nPi_reco_neg);
  double dev_K = (nK_reco_pos - nK_reco_neg)/(nK_reco_pos + nK_reco_neg);
  double dev_SPi = (nSPi_reco_pos - nSPi_reco_neg)/(nSPi_reco_pos + nSPi_reco_neg);
  double dev_D0 = (nD0_reco_pos - nD0_reco_neg)/(nD0_reco_pos + nD0_reco_neg);
  double dev_Dst = (nDst_reco_pos - nDst_reco_neg)/(nDst_reco_pos + nDst_reco_neg);

  double dev_Pi_err = 2*sqrt(pow(nPi_reco_pos,2.)*nPi_reco_neg + pow(nPi_reco_neg,2.)*nPi_reco_pos)/pow(nPi_reco_pos + nPi_reco_neg,2.);
  double dev_K_err = 2*sqrt(pow(nK_reco_pos,2.)*nK_reco_neg + pow(nK_reco_neg,2.)*nK_reco_pos)/pow(nK_reco_pos + nK_reco_neg,2.);
  double dev_SPi_err = 2*sqrt(pow(nSPi_reco_pos,2.)*nSPi_reco_neg + pow(nSPi_reco_neg,2.)*nSPi_reco_pos)/pow(nSPi_reco_pos + nSPi_reco_neg,2.);
  double dev_D0_err = 2*sqrt(pow(nD0_reco_pos,2.)*nD0_reco_neg + pow(nD0_reco_neg,2.)*nD0_reco_pos)/pow(nD0_reco_pos + nD0_reco_neg,2.);
  double dev_Dst_err = 2*sqrt(pow(nDst_reco_pos,2.)*nDst_reco_neg + pow(nDst_reco_neg,2.)*nDst_reco_pos)/pow(nDst_reco_pos + nDst_reco_neg,2.);

  cout << "Total: " << endl;
  cout << "Reconstructed number of pions: " << nPi_reco << ", eff.: " << v_eff_ges.at(0) << " +/- " << v_err_ges.at(0) << endl;
  cout << "Reconstructed number of Kaons: " << nK_reco << ", eff.: " << v_eff_ges.at(1) << " +/- " << v_err_ges.at(1) << endl;
  cout << "Reconstructed number of soft pions: " << nSPi_reco << ", eff.: " << v_eff_ges.at(2) << " +/- " << v_err_ges.at(2)  << endl;
  cout << "Reconstructed number of D0: " << nD0_reco << ", eff.: " << v_eff_ges.at(3) << " +/- " << v_err_ges.at(3) << endl;
  cout << "Reconstructed number of D*: " << nDst_reco << ", eff.: " << v_eff_ges.at(4) << " +/- " << v_err_ges.at(4)  << endl;

  cout << "Charge: +" << endl;
  cout << "Reconstructed number of pions: " << nPi_reco_pos << " of " << nPi_pos << " , eff.: " << v_eff_pos.at(0) << " +/- " << v_err_pos.at(0) << endl;
  cout << "Reconstructed number of Kaons: " << nK_reco_pos << " of " << nK_pos << "  eff.: " << v_eff_pos.at(1) << " +/- " << v_err_pos.at(1) << endl;
  cout << "Reconstructed number of soft pions: " << nSPi_reco_pos << " of " << nSPi_pos << " , eff.: " << v_eff_pos.at(2) << " +/- " << v_err_pos.at(2)  << endl;
  cout << "Reconstructed number of D0: " << nD0_reco_pos << " of " << nD0_pos << " , eff.: " << v_eff_pos.at(3) << " +/- " << v_err_pos.at(3) << endl;
  cout << "Reconstructed number of D*: " << nDst_reco_pos << " of " << nDst_pos << " , eff.: " << v_eff_pos.at(4) << " +/- " << v_err_pos.at(4)  << endl;

  cout << "Charge: -" << endl;
  cout << "Reconstructed number of pions: " << nPi_reco_neg << " of " << nPi_neg << " , eff.: " << v_eff_neg.at(0) << " +/- " << v_err_neg.at(0) << endl;
  cout << "Reconstructed number of Kaons: " << nK_reco_neg << " of " << nK_neg << " , eff.: " << v_eff_neg.at(1) << " +/- " << v_err_neg.at(1) << endl;
  cout << "Reconstructed number of soft pions: " << nSPi_reco_neg << " of " << nSPi_neg << " , eff.: " << v_eff_neg.at(2) << " +/- " << v_err_neg.at(2)  << endl;
  cout << "Reconstructed number of D0: " << nD0_reco_neg << " of " << nD0_neg << " , eff.: " << v_eff_neg.at(3) << " +/- " << v_err_neg.at(3) << endl;
  cout << "Reconstructed number of D*: " << nDst_reco_neg << " of " << nDst_neg << " , eff.: " << v_eff_neg.at(4) << " +/- " << v_err_neg.at(4)  << endl;

  cout << "Deviation via efficiencies:" << endl;
  cout << "Pions: " << v_dev.at(0) << " +/- " << v_dev_err.at(0) << " , in sigmas: " << abs(v_dev.at(0)/v_dev_err.at(0)) << endl;
  cout << "Kaons: " << v_dev.at(1) << " +/- " << v_dev_err.at(1) << " , in sigmas: " << abs(v_dev.at(1)/v_dev_err.at(1)) << endl;
  cout << "soft Pions: " << v_dev.at(2) << " +/- " << v_dev_err.at(2) << " , in sigmas: " << abs(v_dev.at(2)/v_dev_err.at(2)) << endl;
  cout << "D0: " << v_dev.at(3) << " +/- " << v_dev_err.at(3) << " , in sigmas: " << abs(v_dev.at(3)/v_dev_err.at(3)) << endl;
  cout << "Dst: " << v_dev.at(4) << " +/- " << v_dev_err.at(4) << " , in sigmas: " << abs(v_dev.at(4)/v_dev_err.at(4)) << endl;

  cout << "Deviation via total numbers:" << endl;
  cout << "Pions: " << dev_Pi << " +/- " << dev_Pi_err << " , in sigmas: " << abs(dev_Pi/dev_Pi_err) << endl;
  cout << "Kaons: " << dev_K << " +/- " << dev_K_err << " , in sigmas: " << abs(dev_K/dev_K_err) << endl;
  cout << "soft Pions: " << dev_SPi << " +/- " << dev_SPi_err << " , in sigmas: " << abs(dev_SPi/dev_SPi_err) << endl;
  cout << "D0: " << dev_D0 << " +/- " << dev_D0_err << " , in sigmas: " << abs(dev_D0/dev_D0_err) << endl;
  cout << "Dst: " << dev_Dst << " +/- " << dev_Dst_err << " , in sigmas: " << abs(dev_Dst/dev_Dst_err) << endl;

  sethists(v_Pi_hist_reco, v_Pi_hist_reco_pos, v_Pi_hist_reco_neg);
  sethists(v_SPi_hist_reco, v_SPi_hist_reco_pos, v_SPi_hist_reco_neg);
  sethists(v_K_hist_reco, v_K_hist_reco_pos, v_K_hist_reco_neg);
  sethists(v_D0_hist_reco, v_D0_hist_reco_pos, v_D0_hist_reco_neg);
  sethists(v_Dst_hist_reco, v_Dst_hist_reco_pos, v_Dst_hist_reco_neg);


  gStyle->SetOptStat(0);

  printhists(v_Pi_hist_reco, v_Pi_hist_reco_pos, v_Pi_hist_reco_neg, polarisation);
  printhists(v_SPi_hist_reco, v_SPi_hist_reco_pos, v_SPi_hist_reco_neg, polarisation);
  printhists(v_K_hist_reco, v_K_hist_reco_pos, v_K_hist_reco_neg, polarisation);
  printhists(v_D0_hist_reco, v_D0_hist_reco_pos, v_D0_hist_reco_neg, polarisation);
  printhists(v_Dst_hist_reco, v_Dst_hist_reco_pos, v_Dst_hist_reco_neg, polarisation);

  


}
