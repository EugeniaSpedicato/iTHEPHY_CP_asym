#define ntp_cxx
#include "ntp.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
 #include <TTree.h>

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif

#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooPlot.h"
#include "RooRealVar.h"

using namespace RooFit;

void ntp::Loop()
{

Double_t P1_pos=0;
Double_t P1_neg=0;
Double_t P1_tot=0;
 
Double_t P2_pos=0;
Double_t P2_neg=0;
Double_t P2_tot=0;
 
Double_t sPi_pos=0;
Double_t sPi_neg=0;
Double_t sPi_tot=0;
 
Double_t D0_pos=0;
Double_t D0_neg=0;
Double_t D0_tot=0;
 
Double_t Dst_pos=0;
Double_t Dst_neg=0;
Double_t Dst_tot=0;
 

    TH1F* sPiphi_pos=new TH1F("h2", "sPi_PHI_pos", 90,-4,4);
    TH1F* sPiphi_neg=new TH1F("h2", "sPi_PHI_neg", 90,-4,4);
    

    TH1* sPieta_pos=new TH1F("h2", "sPi_eta_pos", 90,2,5);
    TH1* sPieta_neg=new TH1F("h2", "sPi_eta_neg", 90,2,5);
    
    TH1F* sPipt_pos=new TH1F("h1", "sPi_PT_pos", 90,50,910);
    TH1* sPipt_neg=new TH1F("h1", "sPi_PT_neg", 90,50,910);
    


//---------------------------- 
 

    TH1F* P1phi_pos=new TH1F("h2", "P1_PHI_pos", 90,-4,4);
    TH1F* P1phi_neg=new TH1F("h2", "P1_PHI_neg", 90,-4,4);
 
    
    TH1* P1eta_pos=new TH1F("h2", "P1_eta_pos", 90,2,5);
    TH1* P1eta_neg=new TH1F("h2", "P1_eta_neg", 90,2,5);
    

    TH1* P1pt_pos=new TH1F("h2", "P1_PT_reco_pos", 90,0,6000);
    TH1* P1pt_neg=new TH1F("h2", "P1_PT_reco_neg", 90,0,6000);
    

//-----------------------------
 

    TH1F* P2phi_pos=new TH1F("h2", "P2_PHI_pos", 90,-4,4);
    TH1F* P2phi_neg=new TH1F("h2", "P2_PHI_neg", 90,-4,4);
    
    TH1* P2eta_pos=new TH1F("h2", "P2_eta_pos", 90,2,5);
    TH1* P2eta_neg=new TH1F("h2", "P2_eta_neg", 90,2,5);
    

    TH1* P2pt_pos=new TH1F("h2", "P2_PT_reco_pos", 90,0,6200);
    TH1* P2pt_neg=new TH1F("h2", "P2_PT_reco_neg", 90,0,6200);
    
 
 //---------------------------
 

    TH1F* D0phi_pos=new TH1F("h2", "D0_PHI_pos", 90,-0.3,0.3);
    TH1F* D0phi_neg=new TH1F("h2", "D0_PHI_neg", 90,-0.3,0.3);
    

    TH1* D0eta_pos=new TH1F("h2", "D0_eta_pos", 90,2,5);
    TH1* D0eta_neg=new TH1F("h2", "D0_eta_neg", 90,2,5);
    

    TH1* D0pt_pos=new TH1F("h2", "D0_PT_reco_pos", 90,1700,10100);
    TH1* D0pt_neg=new TH1F("h2", "D0_PT_reco_neg", 90,1700,10100);
    
    TH1* D0M_pos=new TH1F("h2", "D0_M_reco_pos", 90,1835,1900);
    TH1* D0M_neg=new TH1F("h2", "D0_M_reco_neg", 90,1835,1900);
    TH1* D0M=new TH1F("h2", "D0_M_reco_neg", 90,1835,1900);
    
 
 //----------------------------
 
    TH1F* Dstphi_pos=new TH1F("h2", "Dst_PHI_pos", 90,-0.3,0.3);
    TH1F* Dstphi_neg=new TH1F("h2", "Dst_PHI_neg", 90,-0.3,0.3);
    

    TH1* Dsteta_pos=new TH1F("h2", "Dst_eta_pos", 90,2,5);
    TH1* Dsteta_neg=new TH1F("h2", "Dst_eta_neg", 90,2,5);
    

    TH1* Dstpt_pos=new TH1F("h2", "Dst_PT_reco_pos", 90,1700,10100);
    TH1* Dstpt_neg=new TH1F("h2", "Dst_PT_reco_neg", 90,1700,10100);

    TH1* DstM_pos=new TH1F("h2", "Dst_reco_pos", 90,2005,2020);
    TH1* DstM_neg=new TH1F("h2", "Dst_reco_neg", 90,2005,2020);
 
 
//   In a ROOT session, you can do:
//      root> .L ntp.C
//      root> ntp t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
 
       D0M->Fill(Dst_DTF_D0_M);
       
     if (Dst_ID>0)
     { sPi_pos ++;
      
        sPiphi_pos->Fill(Dst_DTF_sPi_PHI);
        sPieta_pos->Fill(Dst_DTF_sPi_ETA);
        sPipt_pos->Fill(Dst_DTF_sPi_PT);
     }
        if (Dst_ID<0)
     { sPi_neg ++;
      
        sPiphi_neg->Fill(Dst_DTF_sPi_PHI);
        sPieta_neg->Fill(Dst_DTF_sPi_ETA);
        sPipt_neg->Fill(Dst_DTF_sPi_PT);
     }
       
       
       
           if (Dst_ID>0)
     { Dst_pos ++;
      
        Dstphi_pos->Fill(Dst_DTF_PHI);
        Dsteta_pos->Fill(Dst_DTF_ETA);
        Dstpt_pos->Fill(Dst_DTF_PT);
        DstM_pos->Fill(DTF_Mass);
      
     }
        if (Dst_ID<0)
     { Dst_neg ++;
      
        Dstphi_neg->Fill(Dst_DTF_PHI);
        Dsteta_neg->Fill(Dst_DTF_ETA);
        Dstpt_neg->Fill(Dst_DTF_PT);
        DstM_neg->Fill(DTF_Mass);
      
     }

       
       
                if (P1_ID>0)
     { P1_pos ++;
      
        P1phi_pos->Fill(Dst_DTF_P1_PHI);
        P1eta_pos->Fill(Dst_DTF_P1_ETA);
        P1pt_pos->Fill(Dst_DTF_P1_PT);
     }
        if (P1_ID<0)
     { P1_neg ++;
      
        P1phi_neg->Fill(Dst_DTF_P1_PHI);
        P1eta_neg->Fill(Dst_DTF_P1_ETA);
        P1pt_neg->Fill(Dst_DTF_P1_PT);
     }      
       
       
       if (P2_ID>0)
     { P2_pos ++;
      
        P2phi_pos->Fill(Dst_DTF_P2_PHI);
        P2eta_pos->Fill(Dst_DTF_P2_ETA);
        P2pt_pos->Fill(Dst_DTF_P2_PT);
     }
        if (P2_ID<0)
     { P2_neg ++;
      
        P2phi_neg->Fill(Dst_DTF_P2_PHI);
        P2eta_neg->Fill(Dst_DTF_P2_ETA);
        P2pt_neg->Fill(Dst_DTF_P2_PT);
     }        
       
       
       if (D0_ID>0)
     { D0_pos ++;
      
        D0phi_pos->Fill(Dst_DTF_D0_PHI);
        D0eta_pos->Fill(Dst_DTF_D0_ETA);
        D0pt_pos->Fill(Dst_DTF_D0_PT);
        D0M_pos->Fill(Dst_DTF_D0_M);
     }
        if (D0_ID<0)
     { D0_neg ++;
      
        D0phi_neg->Fill(Dst_DTF_D0_PHI);
        D0eta_neg->Fill(Dst_DTF_D0_ETA);
        D0pt_neg->Fill(Dst_DTF_D0_PT);
        D0M_neg->Fill(Dst_DTF_D0_M);
     }
       
     }  
     

    // D*
    Dstphi_pos->Add(Dstphi_neg,-1);
    Dstphi_neg->Add(Dstphi_pos);
    Dstphi_pos->Divide(Dstphi_neg);
    
    Dstpt_pos->Add(Dstpt_neg,-1);
    Dstpt_neg->Add(Dstpt_pos);
    Dstpt_pos->Divide(Dstpt_neg);
       
    Dsteta_pos->Add(Dsteta_neg,-1);
    Dsteta_neg->Add(Dsteta_pos);
    Dsteta_pos->Divide(Dsteta_neg);
    
    DstM_pos->Add(DstM_neg,-1);
    DstM_neg->Add(DstM_pos);
    DstM_pos->Divide(DstM_neg);
    
    Dstphi_pos->SetAxisRange(-0.55, 0.55, "Y"); 
    Dstpt_pos->SetAxisRange(-0.55, 0.55, "Y"); 
    Dsteta_pos->SetAxisRange(-0.55, 0.55, "Y");
    DstM_pos->SetAxisRange(-0.55, 0.55, "Y"); 
    
    
    
    
    //SOFT PION
    sPiphi_pos->Add(sPiphi_neg,-1);
    sPiphi_neg->Add(sPiphi_pos);
    sPiphi_pos->Divide(sPiphi_neg);
    
    sPipt_pos->Add(sPipt_neg,-1);
    sPipt_neg->Add(sPipt_pos);
    sPipt_pos->Divide(sPipt_neg);
    
    sPieta_pos->Add(sPieta_neg,-1);
    sPieta_neg->Add(sPieta_pos);
    sPieta_pos->Divide(sPieta_neg);
       
    sPiphi_pos->SetAxisRange(-0.55, 0.55, "Y"); 
    sPipt_pos->SetAxisRange(-0.55, 0.55, "Y"); 
    sPieta_pos->SetAxisRange(-0.55, 0.55, "Y"); 
    
    
   
    // D0
    D0phi_pos->Add(D0phi_neg,-1);
    D0phi_neg->Add(D0phi_pos);
    D0phi_pos->Divide(D0phi_neg);
    
    D0pt_pos->Add(D0pt_neg,-1);
    D0pt_neg->Add(D0pt_pos);
    D0pt_pos->Divide(D0pt_neg);
    
    D0eta_pos->Add(D0eta_neg,-1);
    D0eta_neg->Add(D0eta_pos);
    D0eta_pos->Divide(D0eta_neg);
    
    D0M_pos->Add(D0M_neg,-1);
    D0M_neg->Add(D0M_pos);
    D0M_pos->Divide(D0M_neg);
       
    D0phi_pos->SetAxisRange(-0.55, 0.55, "Y");
    D0pt_pos->SetAxisRange(-0.55, 0.55, "Y"); 
    D0eta_pos->SetAxisRange(-0.55, 0.55, "Y"); 
    D0M_pos->SetAxisRange(-0.55, 0.55, "Y"); 
    
    
    
    // PION
    P1phi_pos->Add(P1phi_neg,-1);
    P1phi_neg->Add(P1phi_pos);
    P1phi_pos->Divide(P1phi_neg);
    
    P1pt_pos->Add(P1pt_neg,-1);
    P1pt_neg->Add(P1pt_pos);
    P1pt_pos->Divide(P1pt_neg);
    
    P1eta_pos->Add(P1eta_neg,-1);
    P1eta_neg->Add(P1eta_pos);
    P1eta_pos->Divide(P1eta_neg);
       
    P1phi_pos->SetAxisRange(-0.55, 0.55, "Y");
    P1pt_pos->SetAxisRange(-0.55, 0.55, "Y"); 
    P1eta_pos->SetAxisRange(-0.55, 0.55, "Y"); 
    
    
    // KAON 
    P2phi_pos->Add(P2phi_neg,-1);
    P2phi_neg->Add(P2phi_pos);
    P2phi_pos->Divide(P2phi_neg);
    
    P2pt_pos->Add(P2pt_neg,-1);
    P2pt_neg->Add(P2pt_pos);
    P2pt_pos->Divide(P2pt_neg);
    
    P2eta_pos->Add(P2eta_neg,-1);
    P2eta_neg->Add(P2eta_pos);
    P2eta_pos->Divide(P2eta_neg);
       
    P2phi_pos->SetAxisRange(-0.55, 0.55, "Y");
    P2pt_pos->SetAxisRange(-0.55, 0.55, "Y"); 
    P2eta_pos->SetAxisRange(-0.55, 0.55, "Y"); 
    
    cout << "D*+: " << Dst_pos << " and D*-: " << Dst_neg <<endl;
    cout << "sPi+: " << sPi_pos << " and sPi-: " << sPi_neg <<endl;
    cout << "D0+: " << D0_pos << " and D0-: " << D0_neg <<endl;
    cout << "Pioni+: " << P1_pos << " and Pioni-: " << P1_neg <<endl;
    cout << "Kaoni+: " << P2_pos << " and Kaoni-: " << P2_neg <<endl;
    
    

    
       
    TCanvas * c1= new TCanvas("c1","c1",400,10,600,400);
    c1->Divide(2,2);
    c1->cd(1);
    sPiphi_pos->Draw("E");
    TLine *line1 = new TLine(-4,0,4,0); 
    line1->SetLineColor(kRed);
    line1->Draw("same");  
    c1->cd(2);
    sPipt_pos->Draw("E");
    TLine *line2 = new TLine(50,0,910,0);
    line2->SetLineColor(kRed);
    line2->Draw("same"); 
    c1->cd(3);
    sPieta_pos->Draw("E");
    TLine *line3= new TLine(2,0,5,0);
    line3->SetLineColor(kRed);
    line3->Draw("same");  
       
     c1->SaveAs("sPi.pdf");   
       
    TCanvas * c2= new TCanvas("c1","c1",400,10,600,400);
    c2->Divide(2,2);
    c2->cd(1);
    Dstphi_pos->Draw("E");
    line1->SetLineColor(kRed);
    line1->Draw("same"); 
    c2->cd(2);
    Dstpt_pos->Draw("E");
    TLine *line2a = new TLine(1700,0,10100,0);
    line2a->SetLineColor(kRed);
    line2a->Draw("same"); 
    c2->cd(3);
    Dsteta_pos->Draw("E");       
    line3->SetLineColor(kRed);
    line3->Draw("same");  
    c2->cd(4);
    DstM_pos->Draw("E");
    TLine *line4 = new TLine(2005,0,2020,0);
    line4->SetLineColor(kRed);
    line4->Draw("same");
       
     c2->SaveAs("Dst.pdf");
    
    TCanvas * c3= new TCanvas("c1","c1",400,10,600,400);
    c3->Divide(2,2);
    c3->cd(1);
    P1phi_pos->Draw("E");
    line1->SetLineColor(kRed);
    line1->Draw("same");
    c3->cd(2);
    P1pt_pos->Draw("E");
    TLine *line2b = new TLine(0,0,6000,0);
    line2b->SetLineColor(kRed);
    line2b->Draw("same"); 
    c3->cd(3);
    P1eta_pos->Draw("E");
    line3->SetLineColor(kRed);
    line3->Draw("same");  
    
       
     c3->SaveAs("P1.pdf");
    
    TCanvas * c4= new TCanvas("c1","c1",400,10,600,400);
    c4->Divide(2,2);
    c4->cd(1);
    P2phi_pos->Draw("E");
    line1->SetLineColor(kRed);
    line1->Draw("same");
    c4->cd(2);
    P2pt_pos->Draw("E");
    line2b->SetLineColor(kRed);
    line2b->Draw("same"); 
    c4->cd(3);
    P2eta_pos->Draw("E");
    line3->SetLineColor(kRed);
    line3->Draw("same");  
       
     c4->SaveAs("P2.pdf");
    
    TCanvas * c5= new TCanvas("c1","c1",400,10,600,400);
    c5->Divide(2,2);
    c5->cd(1);
    D0phi_pos->Draw("E");
    line1->SetLineColor(kRed);
    line1->Draw("same");
    c5->cd(2);
    D0pt_pos->Draw("E");
    line2a->SetLineColor(kRed);
    line2a->Draw("same"); 
    c5->cd(3);
    D0eta_pos->Draw("E");
    line3->SetLineColor(kRed);
    line3->Draw("same");
    c5->cd(4);
    TLine *line4a = new TLine(1835,0,1900,0);
    D0M_pos->Draw("E");
    line4a->SetLineColor(kRed);
    line4a->Draw("same");
       
     c5->SaveAs("D0.pdf");
    
    TCanvas * c6= new TCanvas("c1","c1",400,10,600,400);
    D0M->Draw("E");
     c6->SaveAs("D00.pdf");
    
    
RooRealVar Dst_DTF_D0_M("Dst_DTF_D0_M", "Dst_DTF_D0_M", 1820, 1910); 
RooRealVar D0_ID("D0_ID", "D0_ID",-450,-300 ); 
    RooPlot* frameneg=Dst_DTF_D0_M.frame();
    RooPlot* frame=Dst_DTF_D0_M.frame();
   
RooWorkspace w("w");
w.import(Dst_DTF_D0_M);
w.import(D0_ID);
    
  
w.factory("Gaussian::gausD(Dst_DTF_D0_M,m[1865,1860,1870],s[5,30])");


RooDataSet data1("data","data",RooArgSet(Dst_DTF_D0_M,D0_ID),ImportFromFile("/Users/eugenia/Desktop/MYithephy/upVertex/D02Kmpip_15_Up.root", "ntp;26"));
w.import(data1);    


w.pdf("gausD")->fitTo(data1);
data1.plotOn(frame,MarkerColor(kBlue),LineColor(kBlue));
w.pdf("gausD")->plotOn(frame,LineColor(kRed));
frame->Draw();



}