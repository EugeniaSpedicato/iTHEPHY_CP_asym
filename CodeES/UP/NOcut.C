#define ntp_cxx
#include "NOcut.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void ntp::Loop()
{
  Double_t P1_pos=0;
 Double_t P1_pos_rec=0;
 Double_t P1_neg=0;
Double_t P1_neg_rec=0;
 Double_t P1_rec=0;
 
 Double_t P2_pos_rec=0;
 Double_t P2_pos=0;
 Double_t P2_neg=0;
 Double_t P2_neg_rec=0;
 Double_t P2_rec=0;
 
 Double_t sPi_pos=0;
 Double_t sPi_pos_rec=0;
 Double_t sPi_neg=0;
 Double_t sPi_neg_rec=0;
 Double_t sPi_rec=0;
 
Double_t D0_pos=0;
Double_t D0_pos_rec=0;
Double_t D0_neg=0;
Double_t D0_neg_rec=0;
Double_t D0_rec=0;
 
 Double_t Dst_pos=0;
 Double_t Dst_pos_rec=0;
 Double_t Dst_neg=0;
 Double_t Dst_neg_rec=0;
 Double_t Dst_rec=0;
 
TH1F* sPiphi_rec_pos=new TH1F("h1", "sPi_PHI_reco_pos", 50,-4,4);
    TH1F* sPiphi_pos=new TH1F("h2", "sPi_PHI_pos", 50,-4,4);
TH1F* sPiphi_rec_neg=new TH1F("h1", "sPi_PHI_reco_neg", 50,-4,4);
    TH1F* sPiphi_neg=new TH1F("h2", "sPi_PHI_neg", 50,-4,4);
    
TH1F* sPieta_rec_pos=new TH1F("h1", "sPi_eta_reco_pos", 50,2,5);
    TH1* sPieta_pos=new TH1F("h2", "sPi_eta", 50,2,5);
TH1F* sPieta_rec_neg=new TH1F("h1", "sPi_eta_reco_neg", 50,2,5);
    TH1* sPieta_neg=new TH1F("h2", "sPi_eta_neg", 50,2,5);
    
TH1F* sPipt_rec_pos=new TH1F("h1", "sPi_PT_reco_pos", 50,0,900);
    TH1* sPipt_pos=new TH1F("h1", "sPi_PT_reco_pos", 50,0,900);
TH1F* sPipt_rec_neg=new TH1F("h1", "sPi_PT_reco_neg", 50,0,900);
    TH1* sPipt_neg=new TH1F("h1", "sPi_PT_reco_neg", 50,0,900);
    
TH1F* sPitheta_rec_pos=new TH1F("h1", "sPi_THETA_reco_pos", 50,0,0.2);
    TH1F* sPitheta_pos=new TH1F("h2", "sPi_THETA_reco_pos", 50,0,0.2);
TH1F* sPitheta_rec_neg=new TH1F("h1", "sPi_THETA_reco_neg", 50,0,0.2);
    TH1F* sPitheta_neg=new TH1F("h2", "sPi_THETA_reco_neg", 50,0,0.2);

//---------------------------- 
 
 TH1F* P1phi_rec_pos=new TH1F("h1", "P1_PHI_reco_pos", 50,-4,4);
    TH1F* P1phi_pos=new TH1F("h2", "P1_PHI_pos", 50,-4,4);
 TH1F* P1phi_rec_neg=new TH1F("h1", "P1_PHI_reco_neg", 50,-4,4);
    TH1F* P1phi_neg=new TH1F("h2", "P1_PHI_neg", 50,-4,4);
 
    
TH1F* P1eta_rec_pos=new TH1F("h1", "P1_eta_reco_pos", 50,2,5);
    TH1* P1eta_pos=new TH1F("h2", "P1_eta_pos", 50,2,5);
TH1F* P1eta_rec_neg=new TH1F("h1", "P1_eta_reco_neg", 50,2,5);
    TH1* P1eta_neg=new TH1F("h2", "P1_eta_neg", 50,2,5);
    
TH1F* P1pt_rec_pos=new TH1F("h1", "P1_PT_reco_pos", 50,0,6000);
    TH1* P1pt_pos=new TH1F("h2", "sPi_PT_reco_pos", 50,0,6000);
 TH1F* P1pt_rec_neg=new TH1F("h1", "P1_PT_reco_neg", 50,0,6000);
    TH1* P1pt_neg=new TH1F("h2", "sPi_PT_reco_neg", 50,0,6000);
    
TH1* P1theta_rec_pos=new TH1F("h1", "P1_THETA_reco_pos", 50,0,0.25);
    TH1F* P1theta_pos=new TH1F("h2", "P1_THETA_reco_pos", 50,0,0.25);
TH1* P1theta_rec_neg=new TH1F("h1", "P1_THETA_reco_neg", 50,0,0.25);
    TH1F* P1theta_neg=new TH1F("h2", "P1_THETA_reco_neg", 50,0,0.25);
//-----------------------------
 
 TH1F* P2phi_rec_pos=new TH1F("h1", "P2_PHI_reco_pos", 50,-4,4);
    TH1F* P2phi_pos=new TH1F("h2", "P2_PHI_pos", 50,-4,4);
 TH1F* P2phi_rec_neg=new TH1F("h1", "P2_PHI_reco_neg", 50,-4,4);
    TH1F* P2phi_neg=new TH1F("h2", "P2_PHI_neg", 50,-4,4);
    
TH1F* P2eta_rec_pos=new TH1F("h1", "P2_eta_reco_pos", 50,2,5);
    TH1* P2eta_pos=new TH1F("h2", "P2_eta_pos", 50,2,5);
 TH1F* P2eta_rec_neg=new TH1F("h1", "P2_eta_reco_neg", 50,2,5);
    TH1* P2eta_neg=new TH1F("h2", "P2_eta_neg", 50,2,5);
    
 TH1F* P2pt_rec_pos=new TH1F("h1", "P2_PT_reco_pos", 50,0,6200);
    TH1* P2pt_pos=new TH1F("h2", "P2_PT_reco_pos", 50,0,6200);
 TH1F* P2pt_rec_neg=new TH1F("h1", "P2_PT_reco_neg", 50,0,6200);
    TH1* P2pt_neg=new TH1F("h2", "P2_PT_reco_neg", 50,0,6200);
    
TH1F* P2theta_rec_pos=new TH1F("h1", "P2_THETA_reco_pos", 50,0,0.25);
    TH1F* P2theta_pos=new TH1F("h2", "P2_THETA_reco_pos", 50,0,0.25);
 TH1F* P2theta_rec_neg=new TH1F("h1", "P2_THETA_reco_neg", 50,0,0.25);
    TH1F* P2theta_neg=new TH1F("h2", "P2_THETA_reco_neg", 50,0,0.25);
 
 //---------------------------
 
 TH1F* D0phi_rec_pos=new TH1F("h1", "D0_PHI_reco_pos", 50,-4,4);
    TH1F* D0phi_pos=new TH1F("h2", "D0_PHI_pos", 50,-4,4);
 TH1F* D0phi_rec_neg=new TH1F("h1", "D0_PHI_reco_neg", 50,-4,4);
    TH1F* D0phi_neg=new TH1F("h2", "D0_PHI_neg", 50,-4,4);
    
TH1F* D0eta_rec_pos=new TH1F("h1", "DO_eta_reco_pos", 50,2,5);
    TH1* D0eta_pos=new TH1F("h2", "D0_eta_pos", 50,2,5);
TH1F* D0eta_rec_neg=new TH1F("h1", "DO_eta_reco_neg", 50,2,5);
    TH1* D0eta_neg=new TH1F("h2", "D0_eta_neg", 50,2,5);
    
TH1F* D0pt_rec_pos=new TH1F("h1", "D0_PT_reco_pos", 50,0,9500);
    TH1* D0pt_pos=new TH1F("h2", "D0_PT_reco_pos", 50,0,9500);
 TH1F* D0pt_rec_neg=new TH1F("h1", "D0_PT_reco_pos_neg", 50,0,9500);
    TH1* D0pt_neg=new TH1F("h2", "D0_PT_reco_neg", 50,0,9500);
    
    
 TH1F* D0theta_rec_pos=new TH1F("h1", "D0_THETA_reco_pos", 50,0,0.2);
    TH1F* D0theta_pos=new TH1F("h2", "D0_THETA_reco_pos", 50,0,0.2);
 TH1F* D0theta_rec_neg=new TH1F("h1", "D0_THETA_reco_neg", 50,0,0.2);
    TH1F* D0theta_neg=new TH1F("h2", "D0_THETA_reco_neg", 50,0,0.2);
 
 //----------------------------
 
 TH1F* Dstphi_rec_pos=new TH1F("h1", "Dst_PHI_reco_pos", 50,-4,4);
    TH1F* Dstphi_pos=new TH1F("h2", "Dst_PHI_pos", 50,-4,4);
  TH1F* Dstphi_rec_neg=new TH1F("h1", "Dst_PHI_reco_neg", 50,-4,4);
    TH1F* Dstphi_neg=new TH1F("h2", "Dst_PHI_neg", 50,-4,4);
    
TH1F* Dsteta_rec_pos=new TH1F("h1", "Dst_eta_reco_pos", 50,2,5);
    TH1* Dsteta_pos=new TH1F("h2", "Dst_eta_pos", 50,2,5);
 TH1F* Dsteta_rec_neg=new TH1F("h1", "Dst_eta_reco_neg", 50,2,5);
    TH1* Dsteta_neg=new TH1F("h2", "Dst_eta_neg", 50,2,5);
    
TH1F* Dstpt_rec_pos=new TH1F("h1", "Dst_PT_reco_pos", 50,0,10000);
    TH1* Dstpt_pos=new TH1F("h2", "Dst_PT_reco_pos", 50,0,10000);
 TH1F* Dstpt_rec_neg=new TH1F("h1", "Dst_PT_reco_neg", 50,0,10000);
    TH1* Dstpt_neg=new TH1F("h2", "Dst_PT_reco_neg", 50,0,10000);
 
    
TH1F* Dsttheta_rec_pos=new TH1F("h1", "Dst_THETA_reco_pos", 50,0,0.2);
    TH1F* Dsttheta_pos=new TH1F("h2", "Dst_THETA_reco_pos", 50,0,0.2);
 TH1F* Dsttheta_rec_neg=new TH1F("h1", "Dst_THETA_reco_neg", 50,0,0.2);
    TH1F* Dsttheta_neg=new TH1F("h2", "Dst_THETA_reco_neg", 50,0,0.2);
     
TH1F* sPiX_rec_pos=new TH1F("h1", "sPi X Rec pos",50,0.6,1.1);
    TH1F* sPiX_pos=new TH1F("h2", "sPi X pos",50,0.6,1.1);

TH1F* sPiX_rec_neg =new TH1F("h1", "sPi X Rec neg",50,0.6,1.1);
    TH1F* sPiX_neg =new TH1F("h2", "sPi X neg",50,0.6,1.1);

 
 
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
 


if (P1_Reconstructed==1 && P2_Reconstructed==1 && sPi_Reconstructed==1)
{
   Dst_rec++; 
    if (Dst_ID>0)
{
   Dst_pos_rec++; 
    Dsteta_rec_pos->Fill(Dst_ETA);
    Dstphi_rec_pos->Fill(Dst_PHI);
    Dstpt_rec_pos->Fill(Dst_PT);
    Dsttheta_rec_pos->Fill(Dst_THETA);
}
if (Dst_ID<0)
{
   Dst_neg_rec++;
    Dsteta_rec_neg->Fill(Dst_ETA);
    Dstphi_rec_neg->Fill(Dst_PHI);
    Dstpt_rec_neg->Fill(Dst_PT);
    Dsttheta_rec_neg->Fill(Dst_THETA);
} 
}
//----

       
if (Dst_ID>0)
{
    Dst_pos++; 
    Dstphi_pos->Fill(Dst_PHI);
    Dsteta_pos->Fill(Dst_ETA);
    Dstpt_pos->Fill(Dst_PT);
    Dsttheta_pos->Fill(Dst_THETA);
    
}
if (Dst_ID<0)
{
   Dst_neg++;
    Dsteta_neg->Fill(Dst_ETA);
    Dstphi_neg->Fill(Dst_PHI);
    Dstpt_neg->Fill(Dst_PT);
    Dsttheta_neg->Fill(Dst_THETA);
    
}
    
       
if (P1_Reconstructed==1 && P2_Reconstructed==1)
{
   D0_rec++; 
    if (D0_ID>0)
{
   D0_pos_rec++; 
        
    D0phi_rec_pos->Fill(D0_PHI);
    D0eta_rec_pos->Fill(D0_ETA);
    D0pt_rec_pos->Fill(D0_PT);
    D0theta_rec_pos->Fill(D0_THETA);
}
if (D0_ID<0)
{
   D0_neg_rec++;

    D0phi_rec_neg->Fill(D0_PHI);
    D0eta_rec_neg->Fill(D0_ETA);
    D0pt_rec_neg->Fill(D0_PT);
    D0theta_rec_neg->Fill(D0_THETA);
    
}    
}  
//-----
if (D0_ID>0)
{
   D0_pos++; 
    D0phi_pos->Fill(D0_PHI);
    D0eta_pos->Fill(D0_ETA);
    D0pt_pos->Fill(D0_PT);
    D0theta_pos->Fill(D0_THETA);
    
    
    
}
if (D0_ID<0)
{
   D0_neg++;
    
    D0phi_neg->Fill(D0_PHI);
    D0eta_neg->Fill(D0_ETA);
    D0pt_neg->Fill(D0_PT);
    D0theta_neg->Fill(D0_THETA);
} 
     
      
if (P2_Reconstructed==1)
{
   P2_rec++; 
    if (P2_ID>0)
{
   P2_pos_rec++; 
    P2theta_rec_pos->Fill(P2_THETA);
    P2pt_rec_pos->Fill(P2_PT);
    P2phi_rec_pos->Fill(P2_PHI);       
    P2eta_rec_pos->Fill(P2_ETA);
}
if (P2_ID<0)
{
   P2_neg_rec++;
    P2eta_rec_neg->Fill(P2_ETA);
    P2phi_rec_neg->Fill(P2_PHI);      
    P2pt_rec_neg->Fill(P2_PT);
    P2theta_rec_neg->Fill(P2_THETA);
} 
}  
//------  
if (P2_ID>0)
{
   P2_pos++; 
    P2theta_pos->Fill(P2_THETA);
    P2pt_pos->Fill(P2_PT);
    P2phi_pos->Fill(P2_PHI);       
    P2eta_pos->Fill(P2_ETA);
}
if (P2_ID<0)
{
   P2_neg++;
    P2eta_neg->Fill(P2_ETA);
    P2phi_neg->Fill(P2_PHI);      
    P2pt_neg->Fill(P2_PT);
    P2theta_neg->Fill(P2_THETA);
} 

       
       
       
if (P1_Reconstructed==1)
{
   P1_rec++; 
    if (P1_ID>0)
{
   P1_pos_rec++;
    P1theta_rec_pos->Fill(P1_THETA); 
    P1pt_rec_pos->Fill(P1_PT);  
    P1phi_rec_pos->Fill(P1_PHI);  
    P1eta_rec_pos->Fill(P1_ETA);
       
}
if (P1_ID<0)
{
   P1_neg_rec++;
    P1eta_rec_neg->Fill(P1_ETA);
    P1phi_rec_neg->Fill(P1_PHI);      
    P1pt_rec_neg->Fill(P1_PT);
    P1theta_rec_neg->Fill(P1_THETA);
} 
}  
//------  
if (P1_ID>0)
{
   P1_pos++; 
    P1theta_pos->Fill(P1_THETA); 
    P1pt_pos->Fill(P1_PT);  
    P1phi_pos->Fill(P1_PHI);  
    P1eta_pos->Fill(P1_ETA);
}
if (P1_ID<0)
{
   P1_neg++;
    P1eta_neg->Fill(P1_ETA);
    P1phi_neg->Fill(P1_PHI);      
    P1pt_neg->Fill(P1_PT);
    P1theta_neg->Fill(P1_THETA);
} 
    

    
       
if (sPi_Reconstructed==1)
{
   sPi_rec++; 
    if (sPi_ID>0)
{
   sPi_pos_rec++; 
    sPipt_rec_pos->Fill(sPi_PT);
    sPiphi_rec_pos->Fill(sPi_PHI);
    sPieta_rec_pos->Fill(sPi_ETA);
    sPitheta_rec_pos->Fill(sPi_THETA);
    sPiX_rec_pos->Fill(sPi_TRUEORIGINVERTEX_X);
        
}
if (sPi_ID<0)
{
   sPi_neg_rec++;
    sPieta_rec_neg->Fill(sPi_ETA);
    sPiphi_rec_neg->Fill(sPi_PHI);
    sPipt_rec_neg->Fill(sPi_PT);
    sPitheta_rec_neg->Fill(sPi_THETA);
    sPiX_rec_neg->Fill(sPi_TRUEORIGINVERTEX_X);
} 


    
}         
//------        
    if (sPi_ID>0)
{
   sPi_pos++; 
    sPipt_pos->Fill(sPi_PT);
    sPiphi_pos->Fill(sPi_PHI);
    sPieta_pos->Fill(sPi_ETA);
    sPitheta_pos->Fill(sPi_THETA);
    sPiX_pos->Fill(sPi_TRUEORIGINVERTEX_X);
        
}
if (sPi_ID<0)
{
   sPi_neg++;
    sPieta_neg->Fill(sPi_ETA);
    sPiphi_neg->Fill(sPi_PHI);
    sPipt_neg->Fill(sPi_PT);
    sPitheta_neg->Fill(sPi_THETA);
    sPiX_neg->Fill(sPi_TRUEORIGINVERTEX_X);
    
} 
      
      // if (Cut(ientry) < 0) continue;
   }

    Double_t c=nentries; 
 

    
       
    Double_t eff_P1_pos=P1_pos_rec/P1_pos;
    Double_t eff_P1_neg=P1_neg_rec/P1_neg;
 
    Double_t eff_P2_pos=P2_pos_rec/P2_pos;
    Double_t eff_P2_neg=P2_neg_rec/P2_neg;
 
    Double_t eff_sPi_pos=sPi_pos_rec/sPi_pos;
    Double_t eff_sPi_neg=sPi_neg_rec/sPi_neg;
 
    Double_t eff_D0_pos=D0_pos_rec/D0_pos;
    Double_t eff_D0_neg=D0_neg_rec/D0_neg;
 
    Double_t eff_Dst_pos=Dst_pos_rec/Dst_pos;
    Double_t eff_Dst_neg=Dst_neg_rec/Dst_neg;
 
    //Binomial
    Double_t P1_pos_err=sqrt((eff_P1_pos*(1-eff_P1_pos))/P1_pos);

    Double_t P1_neg_err=sqrt((eff_P1_neg*(1-eff_P1_neg))/P1_neg);
 
    Double_t P2_pos_err=sqrt((eff_P2_pos*(1-eff_P2_pos))/P2_pos);
 
    Double_t P2_neg_err=sqrt((eff_P2_neg*(1-eff_P2_neg))/P2_neg);
 
    Double_t sPi_pos_err=sqrt((eff_sPi_pos*(1-eff_sPi_pos))/sPi_pos);
    Double_t sPi_neg_err=sqrt((eff_sPi_neg*(1-eff_sPi_neg))/sPi_neg);
 
    Double_t D0_pos_err=sqrt((eff_D0_pos*(1-eff_D0_pos))/D0_pos);
    Double_t D0_neg_err=sqrt((eff_D0_neg*(1-eff_D0_neg))/D0_neg);
 
    Double_t Dst_pos_err=sqrt((eff_Dst_pos*(1-eff_Dst_pos))/Dst_pos);
    Double_t Dst_neg_err=sqrt((eff_Dst_neg*(1-eff_Dst_neg))/Dst_neg);
 
    // print the number of recontructed events for each particle;
    
    Double_t dis_P1 = (eff_P1_pos-eff_P1_neg)/(eff_P1_pos+eff_P1_neg);
    Double_t err_dis_P1 = sqrt(pow(1/(eff_P1_pos+eff_P1_neg)-(eff_P1_pos-eff_P1_neg)/((eff_P1_pos+eff_P1_neg)*(eff_P1_pos+eff_P1_neg)),2)*P1_pos_err*P1_pos_err+pow(1/(eff_P1_pos+eff_P1_neg)+(eff_P1_pos-eff_P1_neg)/((eff_P1_pos+eff_P1_neg)*(eff_P1_pos+eff_P1_neg)),2)*P1_neg_err*P1_neg_err);
    
    Double_t dis_P2 = (eff_P2_pos-eff_P2_neg)/(eff_P2_pos+eff_P2_neg);
    Double_t err_dis_P2 = sqrt(pow(1/(eff_P2_pos+eff_P2_neg)-(eff_P2_pos-eff_P2_neg)/((eff_P2_pos+eff_P2_neg)*(eff_P2_pos+eff_P2_neg)),2)*P2_pos_err*P2_pos_err+pow(1/(eff_P2_pos+eff_P2_neg)+(eff_P2_pos-eff_P2_neg)/((eff_P2_pos+eff_P2_neg)*(eff_P2_pos+eff_P2_neg)),2)*P2_neg_err*P2_neg_err);
    
    Double_t dis_sPi = (eff_sPi_pos-eff_sPi_neg)/(eff_sPi_pos+eff_sPi_neg);
    Double_t err_dis_sPi = sqrt(pow(1/(eff_sPi_pos+eff_sPi_neg)-(eff_sPi_pos-eff_sPi_neg)/((eff_sPi_pos+eff_sPi_neg)*(eff_sPi_pos+eff_sPi_neg)),2)*sPi_pos_err*sPi_pos_err+pow(1/(eff_sPi_pos+eff_sPi_neg)+(eff_sPi_pos-eff_sPi_neg)/((eff_sPi_pos+eff_sPi_neg)*(eff_sPi_pos+eff_sPi_neg)),2)*sPi_neg_err*sPi_neg_err);
    
    Double_t dis_D0 = (eff_D0_pos-eff_D0_neg)/(eff_D0_pos+eff_D0_neg);
    Double_t err_dis_D0 = sqrt(pow(1/(eff_D0_pos+eff_D0_neg)-(eff_D0_pos-eff_D0_neg)/((eff_D0_pos+eff_D0_neg)*(eff_D0_pos+eff_D0_neg)),2)*D0_pos_err*D0_pos_err+pow(1/(eff_D0_pos+eff_D0_neg)+(eff_D0_pos-eff_D0_neg)/((eff_D0_pos+eff_D0_neg)*(eff_D0_pos+eff_D0_neg)),2)*D0_neg_err*D0_neg_err);
    
    
    Double_t dis_Dst = (eff_Dst_pos-eff_Dst_neg)/(eff_Dst_pos+eff_Dst_neg);
    Double_t err_dis_Dst = sqrt(pow(1/(eff_Dst_pos+eff_Dst_neg)-(eff_Dst_pos-eff_Dst_neg)/((eff_Dst_pos+eff_Dst_neg)*(eff_Dst_pos+eff_Dst_neg)),2)*Dst_pos_err*Dst_pos_err+pow(1/(eff_Dst_pos+eff_Dst_neg)+(eff_Dst_pos-eff_Dst_neg)/((eff_Dst_pos+eff_Dst_neg)*(eff_Dst_pos+eff_Dst_neg)),2)*Dst_neg_err*Dst_neg_err);
    
    double disN_P1 = (P1_pos_rec-P1_neg_rec)/(P1_pos_rec+P1_neg_rec);
    Double_t err_disN_P1 = sqrt(pow(1/(P1_pos_rec+P1_neg_rec)-(P1_pos_rec-P1_neg_rec)/((P1_pos_rec+P1_neg_rec)*(P1_pos_rec+P1_neg_rec)),2)*P1_pos_rec+pow(1/(P1_pos_rec+P1_neg_rec)+(P1_pos_rec-P1_neg_rec)/((P1_pos_rec+P1_neg_rec)*(P1_pos_rec+P1_neg_rec)),2)*P1_neg_rec);
    
    
    double disN_P2 = (P2_pos_rec-P2_neg_rec)/(P2_pos_rec+P2_neg_rec);
    Double_t err_disN_P2 = sqrt(pow(1/(P2_pos_rec+P2_neg_rec)-(P2_pos_rec-P2_neg_rec)/((P2_pos_rec+P2_neg_rec)*(P2_pos_rec+P2_neg_rec)),2)*P2_pos_rec+pow(1/(P2_pos_rec+P2_neg_rec)+(P2_pos_rec-P2_neg_rec)/((P2_pos_rec+P2_neg_rec)*(P2_pos_rec+P2_neg_rec)),2)*P2_neg_rec);
    
    
    double disN_sPi = (sPi_pos_rec-sPi_neg_rec)/(sPi_pos_rec+sPi_neg_rec);
    Double_t err_disN_sPi = sqrt(pow(1/(sPi_pos_rec+sPi_neg_rec)-(sPi_pos_rec-sPi_neg_rec)/((sPi_pos_rec+sPi_neg_rec)*(sPi_pos_rec+sPi_neg_rec)),2)*sPi_pos_rec+pow(1/(sPi_pos_rec+sPi_neg_rec)+(sPi_pos_rec-sPi_neg_rec)/((sPi_pos_rec+sPi_neg_rec)*(sPi_pos_rec+sPi_neg_rec)),2)*sPi_neg_rec);
    
    
    double disN_D0 = (D0_pos_rec-D0_neg_rec)/(D0_pos_rec+D0_neg_rec);
    Double_t err_disN_D0 = sqrt(pow(1/(D0_pos_rec+D0_neg_rec)-(D0_pos_rec-D0_neg_rec)/((D0_pos_rec+D0_neg_rec)*(D0_pos_rec+D0_neg_rec)),2)*D0_pos_rec+pow(1/(D0_pos_rec+D0_neg_rec)+(D0_pos_rec-D0_neg_rec)/((D0_pos_rec+D0_neg_rec)*(D0_pos_rec+D0_neg_rec)),2)*D0_neg_rec);
    
    double disN_Dst = (Dst_pos_rec-Dst_neg_rec)/(Dst_pos_rec+Dst_neg_rec);
    Double_t err_disN_Dst = sqrt(pow(1/(Dst_pos_rec+Dst_neg_rec)-(Dst_pos_rec-Dst_neg_rec)/((Dst_pos_rec+Dst_neg_rec)*(Dst_pos_rec+Dst_neg_rec)),2)*Dst_pos_rec+pow(1/(Dst_pos_rec+Dst_neg_rec)+(Dst_pos_rec-Dst_neg_rec)/((Dst_pos_rec+Dst_neg_rec)*(Dst_pos_rec+Dst_neg_rec)),2)*Dst_neg_rec);
    
    cout<<"P1 asymmetry "<< disN_P1<<" +- " <<err_disN_P1<<  endl;
    cout<<"P2 asymmetry "<< disN_P2<<" +- " <<err_disN_P2<< endl;
    cout<<"sPi asymmetry"<< disN_sPi<<" +- " <<err_disN_sPi<<endl;
    cout<<"D0 asymmetry "<< disN_D0<< " +- " <<err_disN_D0<<endl;
    cout<<"Dst asymmetry"<< disN_Dst<<" +- " <<err_disN_Dst<< endl;
    
    cout<<"P1 reco pos " << P1_pos_rec <<" P1 reco neg " << P1_neg_rec <<endl;
    cout<<"P2 reco pos " << P2_pos_rec <<" P2 reco neg " << P2_neg_rec <<endl;
    cout<<"sPi reco pos " << sPi_pos_rec <<" sPi reco neg " << sPi_neg_rec <<endl;
    cout<<"D0 reco pos " << D0_pos_rec <<" D0 reco neg " << D0_neg_rec <<endl;
    cout<<"Dst reco pos " << Dst_pos_rec <<" Dst reco neg " << Dst_neg_rec <<endl;
        
        
    cout<<"Pions pos efficiency: "<< eff_P1_pos<<" +- "<< P1_pos_err  <<'\n';
    cout<<"Pions neg efficiency: "<< eff_P1_neg<<" +- "<< P1_neg_err <<'\n';
    cout<<"Kaons pos efficiency: "<<eff_P2_pos
        <<" +- "<< P2_pos_err<<'\n';
    cout<<"Kaons neg efficiency: "<<eff_P2_neg <<" +- "<< P2_neg_err<<'\n';
    cout<<"Soft Pions pos efficiency: "<<eff_sPi_pos<<" +- "<< sPi_pos_err<<'\n';
    cout<<"Soft Pions neg efficiency: "<<eff_sPi_neg<<" +- "<< sPi_neg_err<<'\n';
    
    cout<<"D0 pos efficiency: "<<eff_D0_pos <<" +- "<< D0_pos_err<<'\n';
    cout<<"D0 neg efficiency: "<<eff_D0_neg <<" +- "<< D0_neg_err<<'\n';
    cout<<"D*+ pos efficiency: "<<eff_Dst_pos<<" +- "<< Dst_pos_err<<'\n';
    cout<<"D*+ neg efficiency: "<<eff_Dst_neg <<" +- "<< Dst_neg_err<<'\n';

 Double_t prod_effP_D0=eff_P1_pos*eff_P2_pos;
 Double_t err_prod_effP_D0= sqrt(P1_pos_err*P2_pos_err+P1_pos_err*P2_pos_err);
 Double_t prod_effN_D0=eff_P1_neg*eff_P2_neg;
 Double_t err_prod_effN_D0= sqrt(P1_neg_err*P2_neg_err+P1_neg_err*P2_neg_err);
 
    cout << "effD0 = " << eff_D0_pos <<" +- "<< D0_pos_err<<" = " << prod_effP_D0 << " +- " << err_prod_effP_D0 << endl;
 
    cout << "effD0 = " << eff_D0_pos <<" +- "<< D0_pos_err<<" = " << prod_effN_D0 << " +- " << err_prod_effN_D0 << endl;
 
 
 Double_t prod_effP_Dst=eff_P1_pos*eff_P2_pos;
 Double_t err_prod_effP_Dst= sqrt(P1_neg_err*P2_neg_err+P1_neg_err*P2_neg_err);
 Double_t prod_effN_Dst=eff_P1_neg*eff_P2_neg;
 Double_t err_prod_effN_Dst= sqrt(P1_neg_err*P2_neg_err+P1_neg_err*P2_neg_err);
 
    cout << "effDst = " << eff_Dst_pos <<" +- "<< Dst_pos_err<<" = " << prod_effP_Dst << " +- " << err_prod_effP_Dst << endl;
 
    cout << "effDst = " << eff_Dst_pos <<" +- "<< Dst_pos_err<<" = " << prod_effN_Dst << " +- " << err_prod_effN_Dst << endl;
 
sPiphi_rec_pos->Sumw2();
sPiphi_pos->Sumw2();
sPiphi_rec_neg->Sumw2();
sPiphi_neg->Sumw2();
    
sPieta_rec_pos->Sumw2();
sPieta_pos->Sumw2();
sPieta_rec_neg->Sumw2();
sPieta_neg->Sumw2();
    
sPipt_rec_pos->Sumw2();
sPipt_pos->Sumw2();
sPipt_rec_neg->Sumw2();
sPipt_neg->Sumw2();
    
sPitheta_rec_pos->Sumw2();
sPitheta_pos->Sumw2();
sPitheta_rec_neg->Sumw2();
sPitheta_neg->Sumw2(); 
    
sPiX_rec_pos->Sumw2();
sPiX_pos->Sumw2();
sPiX_rec_neg->Sumw2();
sPiX_neg->Sumw2();     
    

//---------------------- 
Dstphi_rec_pos->Sumw2();
Dstphi_pos->Sumw2();
Dstphi_rec_neg->Sumw2();
Dstphi_neg->Sumw2();
    
Dsteta_rec_pos->Sumw2();
Dsteta_pos->Sumw2();
Dsteta_rec_neg->Sumw2();
Dsteta_neg->Sumw2();
    
Dstpt_rec_pos->Sumw2();
Dstpt_pos->Sumw2();
Dstpt_rec_neg->Sumw2();
Dstpt_neg->Sumw2();
    
Dsttheta_rec_pos->Sumw2();
Dsttheta_pos->Sumw2();
Dsttheta_rec_neg->Sumw2();
Dsttheta_neg->Sumw2(); 
//---------------------- 
D0phi_rec_pos->Sumw2();
D0phi_pos->Sumw2();
D0phi_rec_neg->Sumw2();
D0phi_neg->Sumw2();
    
D0eta_rec_pos->Sumw2();
D0eta_pos->Sumw2();
D0eta_rec_neg->Sumw2();
D0eta_neg->Sumw2();
    
D0pt_rec_pos->Sumw2();
D0pt_pos->Sumw2();
D0pt_rec_neg->Sumw2();
D0pt_neg->Sumw2();
    
D0theta_rec_pos->Sumw2();
D0theta_pos->Sumw2();
D0theta_rec_neg->Sumw2();
D0theta_neg->Sumw2(); 
//----------------------
P2phi_rec_pos->Sumw2();
P2phi_pos->Sumw2();
P2phi_rec_neg->Sumw2();
P2phi_neg->Sumw2();
    
P2eta_rec_pos->Sumw2();
P2eta_pos->Sumw2();
P2eta_rec_neg->Sumw2();
P2eta_neg->Sumw2();
    
P2pt_rec_pos->Sumw2();
P2pt_pos->Sumw2();
P2pt_rec_neg->Sumw2();
P2pt_neg->Sumw2();
    
P2theta_rec_pos->Sumw2();
P2theta_pos->Sumw2();
P2theta_rec_neg->Sumw2();
P2theta_neg->Sumw2();
//-------------------
P1phi_rec_pos->Sumw2();
P1phi_pos->Sumw2();
P1phi_rec_neg->Sumw2();
P1phi_neg->Sumw2();
    
P1eta_rec_pos->Sumw2();
P1eta_pos->Sumw2();
P1eta_rec_neg->Sumw2();
P1eta_neg->Sumw2();
    
P1pt_rec_pos->Sumw2();
P1pt_pos->Sumw2();
P1pt_rec_neg->Sumw2();
P1pt_neg->Sumw2();
    
P1theta_rec_pos->Sumw2();
P1theta_pos->Sumw2();
P1theta_rec_neg->Sumw2();
P1theta_neg->Sumw2();
 

TH1F *h3_sPiphi_pos = (TH1F*)sPiphi_rec_pos->Clone("h3_phi_pos"); h3_sPiphi_pos->Divide(sPiphi_rec_pos,sPiphi_pos);
TH1F *h3_sPiphi_neg = (TH1F*)sPiphi_rec_neg->Clone("h3_phi_neg"); h3_sPiphi_neg->Divide(sPiphi_rec_neg,sPiphi_neg);

 TH1F *h3_sPieta_pos = (TH1F*)sPieta_rec_pos->Clone("h3_sPieta_pos"); h3_sPieta_pos->Divide(sPieta_rec_pos,sPieta_pos);
 TH1F *h3_sPieta_neg = (TH1F*)sPieta_rec_neg->Clone("h3_sPieta_neg"); h3_sPieta_neg->Divide(sPieta_rec_neg,sPieta_neg);
    
TH1F *h3_sPipt_pos = (TH1F*)sPipt_rec_pos->Clone("h3_sPipt_pos"); h3_sPipt_pos->Divide(sPipt_rec_pos,sPipt_pos);
TH1F *h3_sPipt_neg = (TH1F*)sPipt_rec_neg->Clone("h3_sPipt_neg"); h3_sPipt_neg->Divide(sPipt_rec_neg,sPipt_neg);
  

      
 TH1F *h3_sPitheta_pos = (TH1F*)sPitheta_rec_pos->Clone("h3_sPitheta_pos"); h3_sPitheta_pos->Divide(sPitheta_rec_pos,sPitheta_pos);
 TH1F *h3_sPitheta_neg = (TH1F*)sPitheta_rec_neg->Clone("h3_sPitheta_neg"); h3_sPitheta_neg->Divide(sPitheta_rec_neg,sPitheta_neg);
    
 TH1F *h3_sPiX_pos = (TH1F*)sPiX_rec_pos->Clone("h3_sPiX_pos"); h3_sPiX_pos->Divide(sPiX_rec_pos,sPiX_pos);
 TH1F *h3_sPiX_neg = (TH1F*)sPiX_rec_neg->Clone("h3_sPiX_neg"); h3_sPiX_neg->Divide(sPiX_rec_neg,sPiX_neg);
    
   

sPiphi_rec_pos->Add(sPiphi_rec_neg,-1);
sPiphi_rec_neg->Add(sPiphi_rec_pos);
sPiphi_rec_pos->Divide(sPiphi_rec_neg);
    
sPieta_rec_pos->Add(sPieta_rec_neg,-1);
sPieta_rec_neg->Add(sPieta_rec_pos);
sPieta_rec_pos->Divide(sPieta_rec_neg);

sPipt_rec_pos->Add(sPipt_rec_neg,-1);
sPipt_rec_neg->Add(sPipt_rec_pos);
sPipt_rec_pos->Divide(sPipt_rec_neg);
    
sPitheta_rec_pos->Add(sPitheta_rec_neg,-1);
sPitheta_rec_neg->Add(sPitheta_rec_pos);
sPitheta_rec_pos->Divide(sPitheta_rec_neg);

sPiphi_rec_pos->SetAxisRange(-0.15, 0.15, "Y");
sPieta_rec_pos->SetAxisRange(-0.15, 0.15, "Y");
sPipt_rec_pos->SetAxisRange(-0.15, 0.15, "Y");
sPitheta_rec_pos->SetAxisRange(-0.15, 0.15, "Y");

  
 //---------------
 TH1F *h3_P1phi_pos = (TH1F*)P1phi_rec_pos->Clone("h3_P1phi_pos"); h3_P1phi_pos->Divide(P1phi_rec_pos,P1phi_pos);
 TH1F *h3_P1phi_neg = (TH1F*)P1phi_rec_neg->Clone("h3_P1phi_neg"); h3_P1phi_neg->Divide(P1phi_rec_neg,P1phi_neg);
 
 TH1F *h3_P1eta_pos = (TH1F*)P1eta_rec_pos->Clone("h3_P1eta_pos"); h3_P1eta_pos->Divide(P1eta_rec_pos,P1eta_pos);
 TH1F *h3_P1eta_neg = (TH1F*)P1eta_rec_neg->Clone("h3_P1eta_neg"); h3_P1eta_neg->Divide(P1eta_rec_neg,P1eta_neg);

  TH1F *h3_P1pt_pos = (TH1F*)P1pt_rec_pos->Clone("h3_P1pt_pos"); h3_P1pt_pos->Divide(P1pt_rec_pos,P1pt_pos);
  TH1F *h3_P1pt_neg = (TH1F*)P1pt_rec_neg->Clone("h3_P1pt_neg"); h3_P1pt_neg->Divide(P1pt_rec_neg,P1pt_neg);

 TH1F *h3_P1theta_pos = (TH1F*)P1theta_rec_pos->Clone("h3_P1theta_pos"); h3_P1theta_pos->Divide(P1theta_rec_pos,P1theta_pos);
 TH1F *h3_P1theta_neg = (TH1F*)P1theta_rec_neg->Clone("h3_P1theta_neg"); h3_P1theta_neg->Divide(P1theta_rec_neg,P1theta_neg);
    
    
P1phi_rec_pos->Add(P1phi_rec_neg,-1);
P1phi_rec_neg->Add(P1phi_rec_pos);
P1phi_rec_pos->Divide(P1phi_rec_neg);
    
P1eta_rec_pos->Add(P1eta_rec_neg,-1);
P1eta_rec_neg->Add(P1eta_rec_pos);
P1eta_rec_pos->Divide(P1eta_rec_neg);

P1pt_rec_pos->Add(P1pt_rec_neg,-1);
P1pt_rec_neg->Add(P1pt_rec_pos);
P1pt_rec_pos->Divide(P1pt_rec_neg);
    
P1theta_rec_pos->Add(P1theta_rec_neg,-1);
P1theta_rec_neg->Add(P1theta_rec_pos);
P1theta_rec_pos->Divide(P1theta_rec_neg);   
    
P1phi_rec_pos->SetAxisRange(-0.15, 0.15, "Y");
P1eta_rec_pos->SetAxisRange(-0.15, 0.15, "Y");
P1pt_rec_pos->SetAxisRange(-0.15, 0.15, "Y");
P1theta_rec_pos->SetAxisRange(-0.15, 0.15, "Y");
    
 //---------
  TH1F *h3_P2phi_pos = (TH1F*)P2phi_rec_pos->Clone("h3_P2phi_pos"); h3_P2phi_pos->Divide(P2phi_rec_pos,P2phi_pos);
 TH1F *h3_P2phi_neg = (TH1F*)P2phi_rec_neg->Clone("h3_P2phi_neg"); h3_P2phi_neg->Divide(P2phi_rec_neg,P2phi_neg);
 
 TH1F *h3_P2eta_pos = (TH1F*)P2eta_rec_pos->Clone("h3_P2eta_pos"); h3_P2eta_pos->Divide(P2eta_rec_pos,P2eta_pos);
 TH1F *h3_P2eta_neg = (TH1F*)P2eta_rec_neg->Clone("h3_P2eta_neg"); h3_P2eta_neg->Divide(P2eta_rec_neg,P2eta_neg);

 TH1F *h3_P2pt_pos = (TH1F*)P2pt_rec_pos->Clone("h3_P2pt_pos"); h3_P2pt_pos->Divide(P2pt_rec_pos,P2pt_pos);
  TH1F *h3_P2pt_neg = (TH1F*)P2pt_rec_neg->Clone("h3_P2pt_neg"); h3_P2pt_neg->Divide(P2pt_rec_neg,P2pt_neg);

 TH1F *h3_P2theta_pos = (TH1F*)P2theta_rec_pos->Clone("h3_P2theta_pos"); h3_P2theta_pos->Divide(P2theta_rec_pos,P2theta_pos);
 TH1F *h3_P2theta_neg = (TH1F*)P2theta_rec_neg->Clone("h3_P2theta_neg"); h3_P2theta_neg->Divide(P2theta_rec_neg,P2theta_neg);
    
P2phi_rec_pos->Add(P2phi_rec_neg,-1);
P2phi_rec_neg->Add(P2phi_rec_pos);
P2phi_rec_pos->Divide(P2phi_rec_neg);
    
P2eta_rec_pos->Add(P2eta_rec_neg,-1);
P2eta_rec_neg->Add(P2eta_rec_pos);
P2eta_rec_pos->Divide(P2eta_rec_neg);

P2pt_rec_pos->Add(P2pt_rec_neg,-1);
P2pt_rec_neg->Add(P2pt_rec_pos);
P2pt_rec_pos->Divide(P2pt_rec_neg);
    
P2theta_rec_pos->Add(P2theta_rec_neg,-1);
P2theta_rec_neg->Add(P2theta_rec_pos);
P2theta_rec_pos->Divide(P2theta_rec_neg); 
    
P2phi_rec_pos->SetAxisRange(-0.15, 0.15, "Y");
P2eta_rec_pos->SetAxisRange(-0.15, 0.15, "Y");
P2pt_rec_pos->SetAxisRange(-0.15, 0.15, "Y");
P2theta_rec_pos->SetAxisRange(-0.15, 0.15, "Y");
 
 //-----------------
  TH1F *h3_D0phi_pos = (TH1F*)D0phi_rec_pos->Clone("h3_D0phi_pos"); h3_D0phi_pos->Divide(D0phi_rec_pos,D0phi_pos);
 TH1F *h3_D0phi_neg = (TH1F*)D0phi_rec_neg->Clone("h3_D0phi_neg"); h3_D0phi_neg->Divide(D0phi_rec_neg,D0phi_neg);
 
 TH1F *h3_D0eta_pos = (TH1F*)D0eta_rec_pos->Clone("h3_D0eta_pos"); h3_D0eta_pos->Divide(D0eta_rec_pos,D0eta_pos);
 TH1F *h3_D0eta_neg = (TH1F*)D0eta_rec_neg->Clone("h3_D0eta_neg"); h3_D0eta_neg->Divide(D0eta_rec_neg,D0eta_neg);

 TH1F *h3_D0pt_pos = (TH1F*)D0pt_rec_pos->Clone("h3_D0pt_pos"); h3_D0pt_pos->Divide(D0pt_rec_pos,D0pt_pos);
  TH1F *h3_D0pt_neg = (TH1F*)D0pt_rec_neg->Clone("h3_D0pt_neg"); h3_D0pt_neg->Divide(D0pt_rec_neg,D0pt_neg);

 TH1F *h3_D0theta_pos = (TH1F*)D0theta_rec_pos->Clone("h3_D0theta_pos"); h3_D0theta_pos->Divide(D0theta_rec_pos,D0theta_pos);
 TH1F *h3_D0theta_neg = (TH1F*)D0theta_rec_neg->Clone("h3_D0theta_neg"); h3_D0theta_neg->Divide(D0theta_rec_neg,D0theta_neg);
 
 D0phi_rec_pos->Add(D0phi_rec_neg,-1);
D0phi_rec_neg->Add(D0phi_rec_pos);
D0phi_rec_pos->Divide(D0phi_rec_neg);
    
D0eta_rec_pos->Add(D0eta_rec_neg,-1);
D0eta_rec_neg->Add(D0eta_rec_pos);
D0eta_rec_pos->Divide(D0eta_rec_neg);

D0pt_rec_pos->Add(D0pt_rec_neg,-1);
D0pt_rec_neg->Add(D0pt_rec_pos);
D0pt_rec_pos->Divide(D0pt_rec_neg);
    
D0theta_rec_pos->Add(D0theta_rec_neg,-1);
D0theta_rec_neg->Add(D0theta_rec_pos);
D0theta_rec_pos->Divide(D0theta_rec_neg);
    
D0phi_rec_pos->SetAxisRange(-0.15, 0.15, "Y");
D0eta_rec_pos->SetAxisRange(-0.15, 0.15, "Y");
D0pt_rec_pos->SetAxisRange(-0.15, 0.15, "Y");
D0theta_rec_pos->SetAxisRange(-0.15, 0.15, "Y");
//--------
 
    TH1F *h3_Dstphi_pos = (TH1F*)Dstphi_rec_pos->Clone("h3_Dstphi_pos"); h3_Dstphi_pos->Divide(Dstphi_rec_pos,Dstphi_pos);
 TH1F *h3_Dstphi_neg = (TH1F*)Dstphi_rec_neg->Clone("h3_Dstphi_neg"); h3_Dstphi_neg->Divide(Dstphi_rec_neg,Dstphi_neg);
 
 TH1F *h3_Dsteta_pos = (TH1F*)Dsteta_rec_pos->Clone("h3_Dsteta_pos"); h3_Dsteta_pos->Divide(Dsteta_rec_pos,Dsteta_pos);
 TH1F *h3_Dsteta_neg = (TH1F*)Dsteta_rec_neg->Clone("h3_Dsteta_neg"); h3_Dsteta_neg->Divide(Dsteta_rec_neg,Dsteta_neg);

 TH1F *h3_Dstpt_pos = (TH1F*)Dstpt_rec_pos->Clone("h3_Dstpt_pos"); h3_Dstpt_pos->Divide(Dstpt_rec_pos,Dstpt_pos);
  TH1F *h3_Dstpt_neg = (TH1F*)Dstpt_rec_neg->Clone("h3_Dstpt_neg"); h3_Dstpt_neg->Divide(Dstpt_rec_neg,Dstpt_neg);

 TH1F *h3_Dsttheta_pos = (TH1F*)Dsttheta_rec_pos->Clone("h3_Dsttheta_pos"); h3_Dsttheta_pos->Divide(Dsttheta_rec_pos,Dsttheta_pos);
 TH1F *h3_Dsttheta_neg = (TH1F*)Dsttheta_rec_neg->Clone("h3_Dsttheta_neg"); h3_Dsttheta_neg->Divide(Dsttheta_rec_neg,Dsttheta_neg);
    
Dstphi_rec_pos->Add(Dstphi_rec_neg,-1);
Dstphi_rec_neg->Add(Dstphi_rec_pos);
Dstphi_rec_pos->Divide(Dstphi_rec_neg);
    
Dsteta_rec_pos->Add(Dsteta_rec_neg,-1);
Dsteta_rec_neg->Add(Dsteta_rec_pos);
Dsteta_rec_pos->Divide(Dsteta_rec_neg);

Dstpt_rec_pos->Add(Dstpt_rec_neg,-1);
Dstpt_rec_neg->Add(Dstpt_rec_pos);
Dstpt_rec_pos->Divide(Dstpt_rec_neg);
    
Dsttheta_rec_pos->Add(Dsttheta_rec_neg,-1);
Dsttheta_rec_neg->Add(Dsttheta_rec_pos);
Dsttheta_rec_pos->Divide(Dsttheta_rec_neg);
    
Dstphi_rec_pos->SetAxisRange(-0.15, 0.15, "Y");
Dsteta_rec_pos->SetAxisRange(-0.15, 0.15, "Y");
Dstpt_rec_pos->SetAxisRange(-0.15, 0.15, "Y");
Dsttheta_rec_pos->SetAxisRange(-0.15, 0.15, "Y");
    
 TCanvas * c1aa= new TCanvas("c1aa","c1aa",400,10,600,400);
c1aa->Divide(2,2);
c1aa->cd(1);
sPiphi_rec_pos->Draw("E");
TLine *line1 = new TLine(-4,0,4,0); 
line1->SetLineColor(kRed);
line1->Draw("same");

c1aa->cd(2);
sPipt_rec_pos->Draw("E");
TLine *line2 = new TLine(0,0,900,0); 
line2->SetLineColor(kRed);
line2->Draw("same");    

c1aa->cd(3);
sPieta_rec_pos->Draw("E");
TLine *line3 = new TLine(2,0,5,0); 
line3->SetLineColor(kRed);
line3->Draw("same");

c1aa->cd(4);
sPitheta_rec_pos->Draw("E");
TLine *line4 = new TLine(0,0,0.2,0); 
line4->SetLineColor(kRed);
line4->Draw("same");
c1aa ->SaveAs("asymmetriessPi.pdf"); 
    

 TCanvas * c1bb= new TCanvas("c1bb","c1bb",400,10,600,400);
c1bb->Divide(2,2);
c1bb->cd(1);
P1phi_rec_pos->Draw("E"); 
line1->SetLineColor(kRed);
line1->Draw("same");
    
c1bb->cd(2);
P1pt_rec_pos->Draw("E");
TLine *line2a = new TLine(0,0,6100,0); 
line2a->SetLineColor(kRed);
line2a->Draw("same"); 

c1bb->cd(3);
P1eta_rec_pos->Draw("E");
line3->SetLineColor(kRed);
line3->Draw("same");

c1bb->cd(4);
P1theta_rec_pos->Draw("E");
TLine *line4a = new TLine(0,0,0.25,0); 
line4a->SetLineColor(kRed);
line4a->Draw("same");
c1bb ->SaveAs("asymmetriesP1.pdf"); 
    
    
     TCanvas * c1cc= new TCanvas("c1cc","c1cc",400,10,600,400);
c1cc->Divide(2,2);
c1cc->cd(1);
P2phi_rec_pos->Draw("E");
line1->SetLineColor(kRed);
line1->Draw("same");
    
c1cc->cd(2);
P2pt_rec_pos->Draw("E");
line2a->SetLineColor(kRed);
line2a->Draw("same"); 
    
c1cc->cd(3);
P2eta_rec_pos->Draw("E");
line3->SetLineColor(kRed);
line3->Draw("same");
    
c1cc->cd(4);
P2theta_rec_pos->Draw("E");
line4a->SetLineColor(kRed);
line4a->Draw("same");
c1cc ->SaveAs("asymmetriesP2.pdf"); 
    
    
     TCanvas * c1dd= new TCanvas("c1dd","c1dd",400,10,600,400);
c1dd->Divide(2,2);
c1dd->cd(1);
D0phi_rec_pos->Draw("E"); 
line1->SetLineColor(kRed);
line1->Draw("same");
    
c1dd->cd(2);
D0pt_rec_pos->Draw("E");
TLine *line2b = new TLine(0,0,9100,0); 
line2b->SetLineColor(kRed);
line2b->Draw("same");
    
c1dd->cd(3);
D0eta_rec_pos->Draw("E");
line3->SetLineColor(kRed);
line3->Draw("same");
    
c1dd->cd(4);
D0theta_rec_pos->Draw("E");
line4->SetLineColor(kRed);
line4->Draw("same");
c1dd->SaveAs("asymmetriesD0.pdf"); 
    
    
TCanvas * c1ee= new TCanvas("c1ee","c1ee",400,10,600,400);
c1ee->Divide(2,2);
c1ee->cd(1);
Dstphi_rec_pos->Draw("E"); 
line1->SetLineColor(kRed);
line1->Draw("same");
    
c1ee->cd(2);
Dstpt_rec_pos->Draw("E");
TLine *line2c = new TLine(0,0,9500,0); 
line2c->SetLineColor(kRed);
line2c->Draw("same");
    
c1ee->cd(3);
Dsteta_rec_pos->Draw("E");
line3->SetLineColor(kRed);
line3->Draw("same");
    
c1ee->cd(4);
Dsttheta_rec_pos->Draw("E");
line4->SetLineColor(kRed);
line4->Draw("same");

c1ee ->SaveAs("asymmetriesDST.pdf"); 
    
    
    
 TCanvas * c1a= new TCanvas("c1a","c1a",400,10,600,400);
c1a->Divide(2,2);
c1a->cd(1);
h3_sPiphi_pos->Draw("E"); 
h3_sPiphi_pos->Draw("hist same"); 

 
c1a->cd(2);
h3_sPieta_pos->Draw("E"); 
h3_sPieta_pos->Draw("hist same"); 
 
c1a->cd(3);
h3_sPipt_pos->Draw("E"); 
h3_sPipt_pos->Draw("hist same"); 
 
c1a->cd(4);
h3_sPitheta_pos->Draw("E"); 
h3_sPitheta_pos->Draw("hist same"); 
 
c1a->SaveAs("sPi pos.pdf"); 
    
 
TCanvas * c2a= new TCanvas("c2a","c2a",400,10,600,400);
c2a->Divide(2,2);
c2a->cd(1);
h3_sPiphi_neg->Draw("E");
h3_sPiphi_neg->Draw("hist same"); 
c2a->cd(2);
h3_sPieta_neg->Draw("E"); 
h3_sPieta_neg->Draw("hist same"); 
 
c2a->cd(3);
h3_sPipt_neg->Draw("E"); 
h3_sPipt_neg->Draw("hist same"); 
 
c2a->cd(4);
h3_sPitheta_neg->Draw("E"); 
h3_sPitheta_neg->Draw("hist same"); 
 
c2a->SaveAs("sPi neg.pdf"); 
 
 //--------
 
  TCanvas * c1b= new TCanvas("c1b","c1b",400,10,600,400);
c1b->Divide(2,2);
c1b->cd(1);
h3_P1phi_pos->Draw("E");
h3_P1phi_pos->Draw("hist same");
 
c1b->cd(2);
h3_P1eta_pos->Draw("E"); 
h3_P1eta_pos->Draw("hist same"); 
 
c1b->cd(3);
h3_P1pt_pos->Draw("E"); 
h3_P1pt_pos->Draw("hist same"); 
 
c1b->cd(4);
h3_P1theta_pos->Draw("E"); 
h3_P1theta_pos->Draw("hist same"); 
 
c1b->SaveAs("P1 pos.pdf"); 
    
 
TCanvas * c2b= new TCanvas("c2b","c2b",400,10,600,400);
c2b->Divide(2,2);
c2b->cd(1);
h3_P1phi_neg->Draw("A");
h3_P1phi_neg->Draw("hist same");
 
c2b->cd(2);
h3_P1eta_neg->Draw("E"); 
h3_P1eta_neg->Draw("hist same"); 
 
c2b->cd(3);
h3_P1pt_neg->Draw("E"); 
h3_P1pt_neg->Draw("hist same"); 
 
c2b->cd(4);
h3_P1theta_neg->Draw("E"); 
h3_P1theta_neg->Draw("hist same"); 
 
c2b->SaveAs("P1 neg.pdf"); 
    
 //-------
   TCanvas * c1c= new TCanvas("c1c","c1c",400,10,600,400);
c1c->Divide(2,2);
c1c->cd(1);
h3_P2phi_pos->Draw("E");
h3_P2phi_pos->Draw("hist same");
 
c1c->cd(2);
h3_P2eta_pos->Draw("E"); 
h3_P2eta_pos->Draw("hist same"); 
 
c1c->cd(3);
h3_P2pt_pos->Draw("E");
h3_P2pt_pos->Draw("hist same"); 
 
c1c->cd(4);
h3_P2theta_pos->Draw("E"); 
h3_P2theta_pos->Draw("hist same"); 
 
c1c->SaveAs("P2 pos.pdf"); 

    
TCanvas * c2c= new TCanvas("c2c","c2c",400,10,600,400);
c2c->Divide(2,2);
c2c->cd(1);
h3_P2phi_neg->Draw("E");
h3_P2phi_neg->Draw("hist same");
 
c2c->cd(2);
h3_P2eta_neg->Draw("E"); 
h3_P2eta_neg->Draw("hist same"); 
 
c2c->cd(3);
h3_P2pt_neg->Draw("E"); 
h3_P2pt_neg->Draw("hist same"); 
 
c2c->cd(4);
h3_P2theta_neg->Draw("E"); 
h3_P2theta_neg->Draw("hist same"); 
c2c->SaveAs("P2 neg.pdf"); 
 
 
 //-----
 
TCanvas * c1d= new TCanvas("c1d","c1d",400,10,600,400);
c1d->Divide(2,2);
c1d->cd(1);
h3_D0phi_pos->Draw("E");
h3_D0phi_pos->Draw("hist same");
 
c1d->cd(2);
h3_D0eta_pos->Draw("E"); 
h3_D0eta_pos->Draw("hist same"); 
 
c1d->cd(3);
h3_D0pt_pos->Draw("E"); 
h3_D0pt_pos->Draw("hist same"); 
 
c1d->cd(4);
h3_D0theta_pos->Draw("E"); 
h3_D0theta_pos->Draw("hist same"); 
c1d->SaveAs("D0 pos.pdf"); 
 
 
TCanvas * c2d= new TCanvas("c2d","c2d",400,10,600,400);
c2d->Divide(2,2);
c2d->cd(1);
h3_D0phi_neg->Draw("E");
h3_D0phi_neg->Draw("hist same");
 
c2d->cd(2);
h3_D0eta_neg->Draw("E"); 
h3_D0eta_neg->Draw("hist same"); 
 
c2d->cd(3);
h3_D0pt_neg->Draw("E"); 
h3_D0pt_neg->Draw("hist same");

 
c2d->cd(4);
h3_D0theta_neg->Draw("E"); 
h3_D0theta_neg->Draw("hist same"); 
c2d->SaveAs("D0 neg.pdf"); 
 
 
 //------
    TCanvas * c1e= new TCanvas("c1e","c1e",400,10,600,400);
c1e->Divide(2,2);
c1e->cd(1);
h3_Dstphi_pos->Draw("E");
h3_Dstphi_pos->Draw("hist same");
 
c1e->cd(2);
h3_Dsteta_pos->Draw("E"); 
h3_Dsteta_pos->Draw("hist same"); 
 
c1e->cd(3);
h3_Dstpt_pos->Draw("E"); 
h3_Dstpt_pos->Draw("hist same"); 
 
c1e->cd(4);
h3_Dsttheta_pos->Draw("E"); 
h3_Dsttheta_pos->Draw("hist same"); 
 
c1e->SaveAs("Dst pos.pdf"); 

    
TCanvas * c2e= new TCanvas("c2e","c2e",400,10,600,400);
c2e->Divide(2,2);
c2e->cd(1);
h3_Dstphi_neg->Draw("E");
h3_Dstphi_neg->Draw("hist same");
 
c2e->cd(2);
h3_Dsteta_neg->Draw("E"); 
h3_Dsteta_neg->Draw("hist same"); 

c2e->cd(3);
h3_Dstpt_neg->Draw("E"); 
h3_Dstpt_neg->Draw("hist same"); 
 
c2e->cd(4);
h3_Dsttheta_neg->Draw("E"); 
h3_Dsttheta_neg->Draw("hist same"); 

    c2e->SaveAs("Dst neg.pdf"); 
    
    
TCanvas * c2X= new TCanvas("c2X","c2X",400,10,600,400);
c2X->Divide(2,1);
c2X->cd(1);
sPiX_rec_neg->Draw("E");
sPiX_rec_neg->Draw("hist same");
 
c2X->cd(2);
sPiX_rec_pos->Draw("E"); 
sPiX_rec_pos->Draw("hist same"); 


    c2X->SaveAs("sPiX.pdf");     
 
 TCanvas *cpn=new TCanvas("cpn","cpn",400,10,600,400);
h3_sPipt_neg->Draw();
h3_sPipt_neg->Draw("hist same");

h3_sPipt_pos->SetMarkerColor(kRed);
h3_sPipt_pos->SetLineColor(kRed);
    
h3_sPipt_pos->Draw("same");
h3_sPipt_pos->Draw("hist same");
    
    cpn->SaveAs("sPiPTconfronto.pdf");     
    


}