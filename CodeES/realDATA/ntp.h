//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Apr 23 13:20:16 2020 by ROOT version 6.12/06
// from TTree ntp/ntp
// found on file: D02Kmpip_15_Up.root
//////////////////////////////////////////////////////////

#ifndef ntp_h
#define ntp_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class ntp {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        D0_M;
   Double_t        Dst_DTF_D0_M;
   Int_t           Dst_ID;
   Int_t           D0_ID;
   Int_t           P1_ID;
   Int_t           P2_ID;
   Double_t        Dst_P;
   Double_t        Dst_PT;
   Double_t        Dst_PX;
   Double_t        Dst_PY;
   Double_t        Dst_PZ;
   Double_t        Dst_ETA;
   Double_t        Dst_PHI;
   Double_t        Dst_DTF_P;
   Double_t        Dst_DTF_PT;
   Double_t        Dst_DTF_PX;
   Double_t        Dst_DTF_PY;
   Double_t        Dst_DTF_PZ;
   Double_t        Dst_DTF_ETA;
   Double_t        Dst_DTF_PHI;
   Double_t        D0_P;
   Double_t        D0_PT;
   Double_t        D0_PX;
   Double_t        D0_PY;
   Double_t        D0_PZ;
   Double_t        D0_ETA;
   Double_t        D0_PHI;
   Double_t        X_P;
   Double_t        X_PT;
   Double_t        X_PX;
   Double_t        X_PY;
   Double_t        X_PZ;
   Double_t        X_ETA;
   Double_t        X_PHI;
   Double_t        Dst_DTF_D0_P;
   Double_t        Dst_DTF_D0_PT;
   Double_t        Dst_DTF_D0_PX;
   Double_t        Dst_DTF_D0_PY;
   Double_t        Dst_DTF_D0_PZ;
   Double_t        Dst_DTF_D0_ETA;
   Double_t        Dst_DTF_D0_PHI;
   Double_t        P1_P;
   Double_t        P1_PT;
   Double_t        P1_PX;
   Double_t        P1_PY;
   Double_t        P1_PZ;
   Double_t        P1_ETA;
   Double_t        P1_PHI;
   Double_t        Dst_DTF_P1_P;
   Double_t        Dst_DTF_P1_PT;
   Double_t        Dst_DTF_P1_PX;
   Double_t        Dst_DTF_P1_PY;
   Double_t        Dst_DTF_P1_PZ;
   Double_t        Dst_DTF_P1_ETA;
   Double_t        Dst_DTF_P1_PHI;
   Double_t        P2_P;
   Double_t        P2_PT;
   Double_t        P2_PX;
   Double_t        P2_PY;
   Double_t        P2_PZ;
   Double_t        P2_ETA;
   Double_t        P2_PHI;
   Double_t        Dst_DTF_P2_P;
   Double_t        Dst_DTF_P2_PT;
   Double_t        Dst_DTF_P2_PX;
   Double_t        Dst_DTF_P2_PY;
   Double_t        Dst_DTF_P2_PZ;
   Double_t        Dst_DTF_P2_ETA;
   Double_t        Dst_DTF_P2_PHI;
   Double_t        sPi_P;
   Double_t        sPi_PT;
   Double_t        sPi_PX;
   Double_t        sPi_PY;
   Double_t        sPi_PZ;
   Double_t        sPi_ETA;
   Double_t        sPi_PHI;
   Double_t        Dst_DTF_sPi_P;
   Double_t        Dst_DTF_sPi_PT;
   Double_t        Dst_DTF_sPi_PX;
   Double_t        Dst_DTF_sPi_PY;
   Double_t        Dst_DTF_sPi_PZ;
   Double_t        Dst_DTF_sPi_ETA;
   Double_t        Dst_DTF_sPi_PHI;
   Double_t        D0_IP_OWNPV;
   Double_t        DTF_Mass;
   Double_t        THETA_X_sPi;
 //  Double_t        X_PX;
  // Double_t        X_PY;
  // Double_t        X_PZ;

   // List of branches
   TBranch        *b_D0_M;   //!
   TBranch        *b_Dst_DTF_D0_M;   //!
   TBranch        *b_Dst_ID;   //!
   TBranch        *b_D0_ID;   //!
   TBranch        *b_P1_ID;   //!
   TBranch        *b_P2_ID;   //!
   TBranch        *b_Dst_P;   //!
   TBranch        *b_Dst_PT;   //!
   TBranch        *b_Dst_PX;   //!
   TBranch        *b_Dst_PY;   //!
   TBranch        *b_Dst_PZ;   //!
   TBranch        *b_Dst_ETA;   //!
   TBranch        *b_Dst_PHI;   //!
   TBranch        *b_Dst_DTF_P;   //!
   TBranch        *b_Dst_DTF_PT;   //!
   TBranch        *b_Dst_DTF_PX;   //!
   TBranch        *b_Dst_DTF_PY;   //!
   TBranch        *b_Dst_DTF_PZ;   //!
   TBranch        *b_Dst_DTF_ETA;   //!
   TBranch        *b_Dst_DTF_PHI;   //!
   TBranch        *b_D0_P;   //!
   TBranch        *b_D0_PT;   //!
   TBranch        *b_D0_PX;   //!
   TBranch        *b_D0_PY;   //!
   TBranch        *b_D0_PZ;   //!
   TBranch        *b_D0_ETA;   //!
   TBranch        *b_D0_PHI;   //!
   TBranch        *b_X_P;   //!
   TBranch        *b_X_PT;   //!
   TBranch        *b_X_PX;   //!
   TBranch        *b_X_PY;   //!
   TBranch        *b_X_PZ;   //!
   TBranch        *b_X_ETA;   //!
   TBranch        *b_X_PHI;   //!
   TBranch        *b_Dst_DTF_D0_P;   //!
   TBranch        *b_Dst_DTF_D0_PT;   //!
   TBranch        *b_Dst_DTF_D0_PX;   //!
   TBranch        *b_Dst_DTF_D0_PY;   //!
   TBranch        *b_Dst_DTF_D0_PZ;   //!
   TBranch        *b_Dst_DTF_D0_ETA;   //!
   TBranch        *b_Dst_DTF_D0_PHI;   //!
   TBranch        *b_P1_P;   //!
   TBranch        *b_P1_PT;   //!
   TBranch        *b_P1_PX;   //!
   TBranch        *b_P1_PY;   //!
   TBranch        *b_P1_PZ;   //!
   TBranch        *b_P1_ETA;   //!
   TBranch        *b_P1_PHI;   //!
   TBranch        *b_Dst_DTF_P1_P;   //!
   TBranch        *b_Dst_DTF_P1_PT;   //!
   TBranch        *b_Dst_DTF_P1_PX;   //!
   TBranch        *b_Dst_DTF_P1_PY;   //!
   TBranch        *b_Dst_DTF_P1_PZ;   //!
   TBranch        *b_Dst_DTF_P1_ETA;   //!
   TBranch        *b_Dst_DTF_P1_PHI;   //!
   TBranch        *b_P2_P;   //!
   TBranch        *b_P2_PT;   //!
   TBranch        *b_P2_PX;   //!
   TBranch        *b_P2_PY;   //!
   TBranch        *b_P2_PZ;   //!
   TBranch        *b_P2_ETA;   //!
   TBranch        *b_P2_PHI;   //!
   TBranch        *b_Dst_DTF_P2_P;   //!
   TBranch        *b_Dst_DTF_P2_PT;   //!
   TBranch        *b_Dst_DTF_P2_PX;   //!
   TBranch        *b_Dst_DTF_P2_PY;   //!
   TBranch        *b_Dst_DTF_P2_PZ;   //!
   TBranch        *b_Dst_DTF_P2_ETA;   //!
   TBranch        *b_Dst_DTF_P2_PHI;   //!
   TBranch        *b_sPi_P;   //!
   TBranch        *b_sPi_PT;   //!
   TBranch        *b_sPi_PX;   //!
   TBranch        *b_sPi_PY;   //!
   TBranch        *b_sPi_PZ;   //!
   TBranch        *b_sPi_ETA;   //!
   TBranch        *b_sPi_PHI;   //!
   TBranch        *b_Dst_DTF_sPi_P;   //!
   TBranch        *b_Dst_DTF_sPi_PT;   //!
   TBranch        *b_Dst_DTF_sPi_PX;   //!
   TBranch        *b_Dst_DTF_sPi_PY;   //!
   TBranch        *b_Dst_DTF_sPi_PZ;   //!
   TBranch        *b_Dst_DTF_sPi_ETA;   //!
   TBranch        *b_Dst_DTF_sPi_PHI;   //!
   TBranch        *b_D0_IP_OWNPV;   //!
   TBranch        *b_DTF_Mass;   //!
   TBranch        *b_THETA_X_sPi;   //!
 //  TBranch        *b_X_PX;   //!
  // TBranch        *b_X_PY;   //!
 //  TBranch        *b_X_PZ;   //!

   ntp(TTree *tree=0);
   virtual ~ntp();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef ntp_cxx
ntp::ntp(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("D02Kmpip_15_Up.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("D02Kmpip_15_Up.root");
      }
      f->GetObject("ntp",tree);

   }
   Init(tree);
}

ntp::~ntp()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t ntp::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t ntp::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void ntp::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("D0_M", &D0_M, &b_D0_M);
   fChain->SetBranchAddress("Dst_DTF_D0_M", &Dst_DTF_D0_M, &b_Dst_DTF_D0_M);
   fChain->SetBranchAddress("Dst_ID", &Dst_ID, &b_Dst_ID);
   fChain->SetBranchAddress("D0_ID", &D0_ID, &b_D0_ID);
   fChain->SetBranchAddress("P1_ID", &P1_ID, &b_P1_ID);
   fChain->SetBranchAddress("P2_ID", &P2_ID, &b_P2_ID);
   fChain->SetBranchAddress("Dst_P", &Dst_P, &b_Dst_P);
   fChain->SetBranchAddress("Dst_PT", &Dst_PT, &b_Dst_PT);
   fChain->SetBranchAddress("Dst_PX", &Dst_PX, &b_Dst_PX);
   fChain->SetBranchAddress("Dst_PY", &Dst_PY, &b_Dst_PY);
   fChain->SetBranchAddress("Dst_PZ", &Dst_PZ, &b_Dst_PZ);
   fChain->SetBranchAddress("Dst_ETA", &Dst_ETA, &b_Dst_ETA);
   fChain->SetBranchAddress("Dst_PHI", &Dst_PHI, &b_Dst_PHI);
   fChain->SetBranchAddress("Dst_DTF_P", &Dst_DTF_P, &b_Dst_DTF_P);
   fChain->SetBranchAddress("Dst_DTF_PT", &Dst_DTF_PT, &b_Dst_DTF_PT);
   fChain->SetBranchAddress("Dst_DTF_PX", &Dst_DTF_PX, &b_Dst_DTF_PX);
   fChain->SetBranchAddress("Dst_DTF_PY", &Dst_DTF_PY, &b_Dst_DTF_PY);
   fChain->SetBranchAddress("Dst_DTF_PZ", &Dst_DTF_PZ, &b_Dst_DTF_PZ);
   fChain->SetBranchAddress("Dst_DTF_ETA", &Dst_DTF_ETA, &b_Dst_DTF_ETA);
   fChain->SetBranchAddress("Dst_DTF_PHI", &Dst_DTF_PHI, &b_Dst_DTF_PHI);
   fChain->SetBranchAddress("D0_P", &D0_P, &b_D0_P);
   fChain->SetBranchAddress("D0_PT", &D0_PT, &b_D0_PT);
   fChain->SetBranchAddress("D0_PX", &D0_PX, &b_D0_PX);
   fChain->SetBranchAddress("D0_PY", &D0_PY, &b_D0_PY);
   fChain->SetBranchAddress("D0_PZ", &D0_PZ, &b_D0_PZ);
   fChain->SetBranchAddress("D0_ETA", &D0_ETA, &b_D0_ETA);
   fChain->SetBranchAddress("D0_PHI", &D0_PHI, &b_D0_PHI);
   fChain->SetBranchAddress("X_P", &X_P, &b_X_P);
   fChain->SetBranchAddress("X_PT", &X_PT, &b_X_PT);
   fChain->SetBranchAddress("X_PX", &X_PX, &b_X_PX);
   fChain->SetBranchAddress("X_PY", &X_PY, &b_X_PY);
   fChain->SetBranchAddress("X_PZ", &X_PZ, &b_X_PZ);
   fChain->SetBranchAddress("X_ETA", &X_ETA, &b_X_ETA);
   fChain->SetBranchAddress("X_PHI", &X_PHI, &b_X_PHI);
   fChain->SetBranchAddress("Dst_DTF_D0_P", &Dst_DTF_D0_P, &b_Dst_DTF_D0_P);
   fChain->SetBranchAddress("Dst_DTF_D0_PT", &Dst_DTF_D0_PT, &b_Dst_DTF_D0_PT);
   fChain->SetBranchAddress("Dst_DTF_D0_PX", &Dst_DTF_D0_PX, &b_Dst_DTF_D0_PX);
   fChain->SetBranchAddress("Dst_DTF_D0_PY", &Dst_DTF_D0_PY, &b_Dst_DTF_D0_PY);
   fChain->SetBranchAddress("Dst_DTF_D0_PZ", &Dst_DTF_D0_PZ, &b_Dst_DTF_D0_PZ);
   fChain->SetBranchAddress("Dst_DTF_D0_ETA", &Dst_DTF_D0_ETA, &b_Dst_DTF_D0_ETA);
   fChain->SetBranchAddress("Dst_DTF_D0_PHI", &Dst_DTF_D0_PHI, &b_Dst_DTF_D0_PHI);
   fChain->SetBranchAddress("P1_P", &P1_P, &b_P1_P);
   fChain->SetBranchAddress("P1_PT", &P1_PT, &b_P1_PT);
   fChain->SetBranchAddress("P1_PX", &P1_PX, &b_P1_PX);
   fChain->SetBranchAddress("P1_PY", &P1_PY, &b_P1_PY);
   fChain->SetBranchAddress("P1_PZ", &P1_PZ, &b_P1_PZ);
   fChain->SetBranchAddress("P1_ETA", &P1_ETA, &b_P1_ETA);
   fChain->SetBranchAddress("P1_PHI", &P1_PHI, &b_P1_PHI);
   fChain->SetBranchAddress("Dst_DTF_P1_P", &Dst_DTF_P1_P, &b_Dst_DTF_P1_P);
   fChain->SetBranchAddress("Dst_DTF_P1_PT", &Dst_DTF_P1_PT, &b_Dst_DTF_P1_PT);
   fChain->SetBranchAddress("Dst_DTF_P1_PX", &Dst_DTF_P1_PX, &b_Dst_DTF_P1_PX);
   fChain->SetBranchAddress("Dst_DTF_P1_PY", &Dst_DTF_P1_PY, &b_Dst_DTF_P1_PY);
   fChain->SetBranchAddress("Dst_DTF_P1_PZ", &Dst_DTF_P1_PZ, &b_Dst_DTF_P1_PZ);
   fChain->SetBranchAddress("Dst_DTF_P1_ETA", &Dst_DTF_P1_ETA, &b_Dst_DTF_P1_ETA);
   fChain->SetBranchAddress("Dst_DTF_P1_PHI", &Dst_DTF_P1_PHI, &b_Dst_DTF_P1_PHI);
   fChain->SetBranchAddress("P2_P", &P2_P, &b_P2_P);
   fChain->SetBranchAddress("P2_PT", &P2_PT, &b_P2_PT);
   fChain->SetBranchAddress("P2_PX", &P2_PX, &b_P2_PX);
   fChain->SetBranchAddress("P2_PY", &P2_PY, &b_P2_PY);
   fChain->SetBranchAddress("P2_PZ", &P2_PZ, &b_P2_PZ);
   fChain->SetBranchAddress("P2_ETA", &P2_ETA, &b_P2_ETA);
   fChain->SetBranchAddress("P2_PHI", &P2_PHI, &b_P2_PHI);
   fChain->SetBranchAddress("Dst_DTF_P2_P", &Dst_DTF_P2_P, &b_Dst_DTF_P2_P);
   fChain->SetBranchAddress("Dst_DTF_P2_PT", &Dst_DTF_P2_PT, &b_Dst_DTF_P2_PT);
   fChain->SetBranchAddress("Dst_DTF_P2_PX", &Dst_DTF_P2_PX, &b_Dst_DTF_P2_PX);
   fChain->SetBranchAddress("Dst_DTF_P2_PY", &Dst_DTF_P2_PY, &b_Dst_DTF_P2_PY);
   fChain->SetBranchAddress("Dst_DTF_P2_PZ", &Dst_DTF_P2_PZ, &b_Dst_DTF_P2_PZ);
   fChain->SetBranchAddress("Dst_DTF_P2_ETA", &Dst_DTF_P2_ETA, &b_Dst_DTF_P2_ETA);
   fChain->SetBranchAddress("Dst_DTF_P2_PHI", &Dst_DTF_P2_PHI, &b_Dst_DTF_P2_PHI);
   fChain->SetBranchAddress("sPi_P", &sPi_P, &b_sPi_P);
   fChain->SetBranchAddress("sPi_PT", &sPi_PT, &b_sPi_PT);
   fChain->SetBranchAddress("sPi_PX", &sPi_PX, &b_sPi_PX);
   fChain->SetBranchAddress("sPi_PY", &sPi_PY, &b_sPi_PY);
   fChain->SetBranchAddress("sPi_PZ", &sPi_PZ, &b_sPi_PZ);
   fChain->SetBranchAddress("sPi_ETA", &sPi_ETA, &b_sPi_ETA);
   fChain->SetBranchAddress("sPi_PHI", &sPi_PHI, &b_sPi_PHI);
   fChain->SetBranchAddress("Dst_DTF_sPi_P", &Dst_DTF_sPi_P, &b_Dst_DTF_sPi_P);
   fChain->SetBranchAddress("Dst_DTF_sPi_PT", &Dst_DTF_sPi_PT, &b_Dst_DTF_sPi_PT);
   fChain->SetBranchAddress("Dst_DTF_sPi_PX", &Dst_DTF_sPi_PX, &b_Dst_DTF_sPi_PX);
   fChain->SetBranchAddress("Dst_DTF_sPi_PY", &Dst_DTF_sPi_PY, &b_Dst_DTF_sPi_PY);
   fChain->SetBranchAddress("Dst_DTF_sPi_PZ", &Dst_DTF_sPi_PZ, &b_Dst_DTF_sPi_PZ);
   fChain->SetBranchAddress("Dst_DTF_sPi_ETA", &Dst_DTF_sPi_ETA, &b_Dst_DTF_sPi_ETA);
   fChain->SetBranchAddress("Dst_DTF_sPi_PHI", &Dst_DTF_sPi_PHI, &b_Dst_DTF_sPi_PHI);
   fChain->SetBranchAddress("D0_IP_OWNPV", &D0_IP_OWNPV, &b_D0_IP_OWNPV);
   fChain->SetBranchAddress("DTF_Mass", &DTF_Mass, &b_DTF_Mass);
   fChain->SetBranchAddress("THETA_X_sPi", &THETA_X_sPi, &b_THETA_X_sPi);
//    fChain->SetBranchAddress("X_PX", &X_PX, &b_X_PX);
//    fChain->SetBranchAddress("X_PY", &X_PY, &b_X_PY);
//    fChain->SetBranchAddress("X_PZ", &X_PZ, &b_X_PZ);
   Notify();
}

Bool_t ntp::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void ntp::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t ntp::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef ntp_cxx
