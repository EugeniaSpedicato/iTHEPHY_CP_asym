//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Mar 20 13:14:22 2020 by ROOT version 6.12/06
// from TTree ntp/ntp
// found on file: minisample_Dst2D0pi_D02Kpi_2016_Up_GEN.root
//////////////////////////////////////////////////////////

#ifndef NOcut_h
#define NOcut_h

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
   Double_t        Dst_ETA;
   Double_t        Dst_PHI;
   Double_t        Dst_PT;
   Double_t        Dst_THETA;
   ULong64_t       Dst_MCP_numPseudoTypes;
   Int_t           Dst_MCP_MCP_PseudoLen;
   Float_t         Dst_MCP_PseudoTypes[20];   //[Dst_MCP_MCP_PseudoLen]
   Int_t           Dst_MC_MOTHER_ID;
   Int_t           Dst_MC_MOTHER_KEY;
   Int_t           Dst_MC_GD_MOTHER_ID;
   Int_t           Dst_MC_GD_MOTHER_KEY;
   Int_t           Dst_MC_GD_GD_MOTHER_ID;
   Int_t           Dst_MC_GD_GD_MOTHER_KEY;
   Double_t        Dst_TRUEP_E;
   Double_t        Dst_TRUEP_X;
   Double_t        Dst_TRUEP_Y;
   Double_t        Dst_TRUEP_Z;
   Double_t        Dst_TRUEPT;
   Double_t        Dst_TRUEORIGINVERTEX_X;
   Double_t        Dst_TRUEORIGINVERTEX_Y;
   Double_t        Dst_TRUEORIGINVERTEX_Z;
   Double_t        Dst_TRUEENDVERTEX_X;
   Double_t        Dst_TRUEENDVERTEX_Y;
   Double_t        Dst_TRUEENDVERTEX_Z;
   Bool_t          Dst_TRUEISSTABLE;
   Double_t        Dst_TRUETAU;
   Int_t           Dst_ID;
   Int_t           Dst_Reconstructible;
   Int_t           Dst_Reconstructed;
   Int_t           Dst_ProtoParticles;
   Float_t         Dst_PP_PX[20];   //[Dst_ProtoParticles]
   Float_t         Dst_PP_PY[20];   //[Dst_ProtoParticles]
   Float_t         Dst_PP_PZ[20];   //[Dst_ProtoParticles]
   Float_t         Dst_PP_Weight[20];   //[Dst_ProtoParticles]
   Float_t         Dst_PP_tr_pchi2[20];   //[Dst_ProtoParticles]
   Float_t         Dst_PP_DLLe[20];   //[Dst_ProtoParticles]
   Float_t         Dst_PP_DLLk[20];   //[Dst_ProtoParticles]
   Float_t         Dst_PP_DLLp[20];   //[Dst_ProtoParticles]
   Float_t         Dst_PP_DLLmu[20];   //[Dst_ProtoParticles]
   Double_t        D0_ETA;
   Double_t        D0_PHI;
   Double_t        D0_PT;
   Double_t        D0_THETA;
   ULong64_t       D0_MCP_numPseudoTypes;
   Int_t           D0_MCP_MCP_PseudoLen;
   Float_t         D0_MCP_PseudoTypes[20];   //[D0_MCP_MCP_PseudoLen]
   Int_t           D0_MC_MOTHER_ID;
   Int_t           D0_MC_MOTHER_KEY;
   Int_t           D0_MC_GD_MOTHER_ID;
   Int_t           D0_MC_GD_MOTHER_KEY;
   Int_t           D0_MC_GD_GD_MOTHER_ID;
   Int_t           D0_MC_GD_GD_MOTHER_KEY;
   Double_t        D0_TRUEP_E;
   Double_t        D0_TRUEP_X;
   Double_t        D0_TRUEP_Y;
   Double_t        D0_TRUEP_Z;
   Double_t        D0_TRUEPT;
   Double_t        D0_TRUEORIGINVERTEX_X;
   Double_t        D0_TRUEORIGINVERTEX_Y;
   Double_t        D0_TRUEORIGINVERTEX_Z;
   Double_t        D0_TRUEENDVERTEX_X;
   Double_t        D0_TRUEENDVERTEX_Y;
   Double_t        D0_TRUEENDVERTEX_Z;
   Bool_t          D0_TRUEISSTABLE;
   Double_t        D0_TRUETAU;
   Int_t           D0_ID;
   Int_t           D0_Reconstructible;
   Int_t           D0_Reconstructed;
   Int_t           D0_ProtoParticles;
   Float_t         D0_PP_PX[20];   //[D0_ProtoParticles]
   Float_t         D0_PP_PY[20];   //[D0_ProtoParticles]
   Float_t         D0_PP_PZ[20];   //[D0_ProtoParticles]
   Float_t         D0_PP_Weight[20];   //[D0_ProtoParticles]
   Float_t         D0_PP_tr_pchi2[20];   //[D0_ProtoParticles]
   Float_t         D0_PP_DLLe[20];   //[D0_ProtoParticles]
   Float_t         D0_PP_DLLk[20];   //[D0_ProtoParticles]
   Float_t         D0_PP_DLLp[20];   //[D0_ProtoParticles]
   Float_t         D0_PP_DLLmu[20];   //[D0_ProtoParticles]
   Double_t        P2_ETA;
   Double_t        P2_PHI;
   Double_t        P2_PT;
   Double_t        P2_THETA;
   ULong64_t       P2_MCP_numPseudoTypes;
   Int_t           P2_MCP_MCP_PseudoLen;
   Float_t         P2_MCP_PseudoTypes[20];   //[P2_MCP_MCP_PseudoLen]
   Int_t           P2_MC_MOTHER_ID;
   Int_t           P2_MC_MOTHER_KEY;
   Int_t           P2_MC_GD_MOTHER_ID;
   Int_t           P2_MC_GD_MOTHER_KEY;
   Int_t           P2_MC_GD_GD_MOTHER_ID;
   Int_t           P2_MC_GD_GD_MOTHER_KEY;
   Double_t        P2_TRUEP_E;
   Double_t        P2_TRUEP_X;
   Double_t        P2_TRUEP_Y;
   Double_t        P2_TRUEP_Z;
   Double_t        P2_TRUEPT;
   Double_t        P2_TRUEORIGINVERTEX_X;
   Double_t        P2_TRUEORIGINVERTEX_Y;
   Double_t        P2_TRUEORIGINVERTEX_Z;
   Double_t        P2_TRUEENDVERTEX_X;
   Double_t        P2_TRUEENDVERTEX_Y;
   Double_t        P2_TRUEENDVERTEX_Z;
   Bool_t          P2_TRUEISSTABLE;
   Double_t        P2_TRUETAU;
   Int_t           P2_ID;
   Int_t           P2_Reconstructible;
   Int_t           P2_Reconstructed;
   Int_t           P2_ProtoParticles;
   Float_t         P2_PP_PX[20];   //[P2_ProtoParticles]
   Float_t         P2_PP_PY[20];   //[P2_ProtoParticles]
   Float_t         P2_PP_PZ[20];   //[P2_ProtoParticles]
   Float_t         P2_PP_Weight[20];   //[P2_ProtoParticles]
   Float_t         P2_PP_tr_pchi2[20];   //[P2_ProtoParticles]
   Float_t         P2_PP_DLLe[20];   //[P2_ProtoParticles]
   Float_t         P2_PP_DLLk[20];   //[P2_ProtoParticles]
   Float_t         P2_PP_DLLp[20];   //[P2_ProtoParticles]
   Float_t         P2_PP_DLLmu[20];   //[P2_ProtoParticles]
   Double_t        P1_ETA;
   Double_t        P1_PHI;
   Double_t        P1_PT;
   Double_t        P1_THETA;
   ULong64_t       P1_MCP_numPseudoTypes;
   Int_t           P1_MCP_MCP_PseudoLen;
   Float_t         P1_MCP_PseudoTypes[20];   //[P1_MCP_MCP_PseudoLen]
   Int_t           P1_MC_MOTHER_ID;
   Int_t           P1_MC_MOTHER_KEY;
   Int_t           P1_MC_GD_MOTHER_ID;
   Int_t           P1_MC_GD_MOTHER_KEY;
   Int_t           P1_MC_GD_GD_MOTHER_ID;
   Int_t           P1_MC_GD_GD_MOTHER_KEY;
   Double_t        P1_TRUEP_E;
   Double_t        P1_TRUEP_X;
   Double_t        P1_TRUEP_Y;
   Double_t        P1_TRUEP_Z;
   Double_t        P1_TRUEPT;
   Double_t        P1_TRUEORIGINVERTEX_X;
   Double_t        P1_TRUEORIGINVERTEX_Y;
   Double_t        P1_TRUEORIGINVERTEX_Z;
   Double_t        P1_TRUEENDVERTEX_X;
   Double_t        P1_TRUEENDVERTEX_Y;
   Double_t        P1_TRUEENDVERTEX_Z;
   Bool_t          P1_TRUEISSTABLE;
   Double_t        P1_TRUETAU;
   Int_t           P1_ID;
   Int_t           P1_Reconstructible;
   Int_t           P1_Reconstructed;
   Int_t           P1_ProtoParticles;
   Float_t         P1_PP_PX[20];   //[P1_ProtoParticles]
   Float_t         P1_PP_PY[20];   //[P1_ProtoParticles]
   Float_t         P1_PP_PZ[20];   //[P1_ProtoParticles]
   Float_t         P1_PP_Weight[20];   //[P1_ProtoParticles]
   Float_t         P1_PP_tr_pchi2[20];   //[P1_ProtoParticles]
   Float_t         P1_PP_DLLe[20];   //[P1_ProtoParticles]
   Float_t         P1_PP_DLLk[20];   //[P1_ProtoParticles]
   Float_t         P1_PP_DLLp[20];   //[P1_ProtoParticles]
   Float_t         P1_PP_DLLmu[20];   //[P1_ProtoParticles]
   Double_t        sPi_ETA;
   Double_t        sPi_PHI;
   Double_t        sPi_PT;
   Double_t        sPi_THETA;
   ULong64_t       sPi_MCP_numPseudoTypes;
   Int_t           sPi_MCP_MCP_PseudoLen;
   Float_t         sPi_MCP_PseudoTypes[20];   //[sPi_MCP_MCP_PseudoLen]
   Int_t           sPi_MC_MOTHER_ID;
   Int_t           sPi_MC_MOTHER_KEY;
   Int_t           sPi_MC_GD_MOTHER_ID;
   Int_t           sPi_MC_GD_MOTHER_KEY;
   Int_t           sPi_MC_GD_GD_MOTHER_ID;
   Int_t           sPi_MC_GD_GD_MOTHER_KEY;
   Double_t        sPi_TRUEP_E;
   Double_t        sPi_TRUEP_X;
   Double_t        sPi_TRUEP_Y;
   Double_t        sPi_TRUEP_Z;
   Double_t        sPi_TRUEPT;
   Double_t        sPi_TRUEORIGINVERTEX_X;
   Double_t        sPi_TRUEORIGINVERTEX_Y;
   Double_t        sPi_TRUEORIGINVERTEX_Z;
   Double_t        sPi_TRUEENDVERTEX_X;
   Double_t        sPi_TRUEENDVERTEX_Y;
   Double_t        sPi_TRUEENDVERTEX_Z;
   Bool_t          sPi_TRUEISSTABLE;
   Double_t        sPi_TRUETAU;
   Int_t           sPi_ID;
   Int_t           sPi_Reconstructible;
   Int_t           sPi_Reconstructed;
   Int_t           sPi_ProtoParticles;
   Float_t         sPi_PP_PX[20];   //[sPi_ProtoParticles]
   Float_t         sPi_PP_PY[20];   //[sPi_ProtoParticles]
   Float_t         sPi_PP_PZ[20];   //[sPi_ProtoParticles]
   Float_t         sPi_PP_Weight[20];   //[sPi_ProtoParticles]
   Float_t         sPi_PP_tr_pchi2[20];   //[sPi_ProtoParticles]
   Float_t         sPi_PP_DLLe[20];   //[sPi_ProtoParticles]
   Float_t         sPi_PP_DLLk[20];   //[sPi_ProtoParticles]
   Float_t         sPi_PP_DLLp[20];   //[sPi_ProtoParticles]
   Float_t         sPi_PP_DLLmu[20];   //[sPi_ProtoParticles]
   UInt_t          nCandidate;
   ULong64_t       totCandidates;
   ULong64_t       EventInSequence;
   Int_t           MCPVs;
   Float_t         MCPVX[50];   //[MCPVs]
   Float_t         MCPVY[50];   //[MCPVs]
   Float_t         MCPVZ[50];   //[MCPVs]
   Float_t         MCPVT[50];   //[MCPVs]
   UInt_t          runNumber;
   ULong64_t       eventNumber;
   UInt_t          BCID;
   Int_t           BCType;
   UInt_t          OdinTCK;
   UInt_t          L0DUTCK;
   UInt_t          HLT1TCK;
   UInt_t          HLT2TCK;
   ULong64_t       GpsTime;
   Short_t         Polarity;

   // List of branches
   TBranch        *b_Dst_ETA;   //!
   TBranch        *b_Dst_PHI;   //!
   TBranch        *b_Dst_PT;   //!
   TBranch        *b_Dst_THETA;   //!
   TBranch        *b_Dst_MCP_numPseudoTypes;   //!
   TBranch        *b_Dst_MCP_MCP_PseudoLen;   //!
   TBranch        *b_Dst_MCP_PseudoTypes;   //!
   TBranch        *b_Dst_MC_MOTHER_ID;   //!
   TBranch        *b_Dst_MC_MOTHER_KEY;   //!
   TBranch        *b_Dst_MC_GD_MOTHER_ID;   //!
   TBranch        *b_Dst_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_Dst_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_Dst_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_Dst_TRUEP_E;   //!
   TBranch        *b_Dst_TRUEP_X;   //!
   TBranch        *b_Dst_TRUEP_Y;   //!
   TBranch        *b_Dst_TRUEP_Z;   //!
   TBranch        *b_Dst_TRUEPT;   //!
   TBranch        *b_Dst_TRUEORIGINVERTEX_X;   //!
   TBranch        *b_Dst_TRUEORIGINVERTEX_Y;   //!
   TBranch        *b_Dst_TRUEORIGINVERTEX_Z;   //!
   TBranch        *b_Dst_TRUEENDVERTEX_X;   //!
   TBranch        *b_Dst_TRUEENDVERTEX_Y;   //!
   TBranch        *b_Dst_TRUEENDVERTEX_Z;   //!
   TBranch        *b_Dst_TRUEISSTABLE;   //!
   TBranch        *b_Dst_TRUETAU;   //!
   TBranch        *b_Dst_ID;   //!
   TBranch        *b_Dst_Reconstructible;   //!
   TBranch        *b_Dst_Reconstructed;   //!
   TBranch        *b_Dst_ProtoParticles;   //!
   TBranch        *b_Dst_PP_PX;   //!
   TBranch        *b_Dst_PP_PY;   //!
   TBranch        *b_Dst_PP_PZ;   //!
   TBranch        *b_Dst_PP_Weight;   //!
   TBranch        *b_Dst_PP_tr_pchi2;   //!
   TBranch        *b_Dst_PP_DLLe;   //!
   TBranch        *b_Dst_PP_DLLk;   //!
   TBranch        *b_Dst_PP_DLLp;   //!
   TBranch        *b_Dst_PP_DLLmu;   //!
   TBranch        *b_D0_ETA;   //!
   TBranch        *b_D0_PHI;   //!
   TBranch        *b_D0_PT;   //!
   TBranch        *b_D0_THETA;   //!
   TBranch        *b_D0_MCP_numPseudoTypes;   //!
   TBranch        *b_D0_MCP_MCP_PseudoLen;   //!
   TBranch        *b_D0_MCP_PseudoTypes;   //!
   TBranch        *b_D0_MC_MOTHER_ID;   //!
   TBranch        *b_D0_MC_MOTHER_KEY;   //!
   TBranch        *b_D0_MC_GD_MOTHER_ID;   //!
   TBranch        *b_D0_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_D0_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_D0_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_D0_TRUEP_E;   //!
   TBranch        *b_D0_TRUEP_X;   //!
   TBranch        *b_D0_TRUEP_Y;   //!
   TBranch        *b_D0_TRUEP_Z;   //!
   TBranch        *b_D0_TRUEPT;   //!
   TBranch        *b_D0_TRUEORIGINVERTEX_X;   //!
   TBranch        *b_D0_TRUEORIGINVERTEX_Y;   //!
   TBranch        *b_D0_TRUEORIGINVERTEX_Z;   //!
   TBranch        *b_D0_TRUEENDVERTEX_X;   //!
   TBranch        *b_D0_TRUEENDVERTEX_Y;   //!
   TBranch        *b_D0_TRUEENDVERTEX_Z;   //!
   TBranch        *b_D0_TRUEISSTABLE;   //!
   TBranch        *b_D0_TRUETAU;   //!
   TBranch        *b_D0_ID;   //!
   TBranch        *b_D0_Reconstructible;   //!
   TBranch        *b_D0_Reconstructed;   //!
   TBranch        *b_D0_ProtoParticles;   //!
   TBranch        *b_D0_PP_PX;   //!
   TBranch        *b_D0_PP_PY;   //!
   TBranch        *b_D0_PP_PZ;   //!
   TBranch        *b_D0_PP_Weight;   //!
   TBranch        *b_D0_PP_tr_pchi2;   //!
   TBranch        *b_D0_PP_DLLe;   //!
   TBranch        *b_D0_PP_DLLk;   //!
   TBranch        *b_D0_PP_DLLp;   //!
   TBranch        *b_D0_PP_DLLmu;   //!
   TBranch        *b_P2_ETA;   //!
   TBranch        *b_P2_PHI;   //!
   TBranch        *b_P2_PT;   //!
   TBranch        *b_P2_THETA;   //!
   TBranch        *b_P2_MCP_numPseudoTypes;   //!
   TBranch        *b_P2_MCP_MCP_PseudoLen;   //!
   TBranch        *b_P2_MCP_PseudoTypes;   //!
   TBranch        *b_P2_MC_MOTHER_ID;   //!
   TBranch        *b_P2_MC_MOTHER_KEY;   //!
   TBranch        *b_P2_MC_GD_MOTHER_ID;   //!
   TBranch        *b_P2_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_P2_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_P2_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_P2_TRUEP_E;   //!
   TBranch        *b_P2_TRUEP_X;   //!
   TBranch        *b_P2_TRUEP_Y;   //!
   TBranch        *b_P2_TRUEP_Z;   //!
   TBranch        *b_P2_TRUEPT;   //!
   TBranch        *b_P2_TRUEORIGINVERTEX_X;   //!
   TBranch        *b_P2_TRUEORIGINVERTEX_Y;   //!
   TBranch        *b_P2_TRUEORIGINVERTEX_Z;   //!
   TBranch        *b_P2_TRUEENDVERTEX_X;   //!
   TBranch        *b_P2_TRUEENDVERTEX_Y;   //!
   TBranch        *b_P2_TRUEENDVERTEX_Z;   //!
   TBranch        *b_P2_TRUEISSTABLE;   //!
   TBranch        *b_P2_TRUETAU;   //!
   TBranch        *b_P2_ID;   //!
   TBranch        *b_P2_Reconstructible;   //!
   TBranch        *b_P2_Reconstructed;   //!
   TBranch        *b_P2_ProtoParticles;   //!
   TBranch        *b_P2_PP_PX;   //!
   TBranch        *b_P2_PP_PY;   //!
   TBranch        *b_P2_PP_PZ;   //!
   TBranch        *b_P2_PP_Weight;   //!
   TBranch        *b_P2_PP_tr_pchi2;   //!
   TBranch        *b_P2_PP_DLLe;   //!
   TBranch        *b_P2_PP_DLLk;   //!
   TBranch        *b_P2_PP_DLLp;   //!
   TBranch        *b_P2_PP_DLLmu;   //!
   TBranch        *b_P1_ETA;   //!
   TBranch        *b_P1_PHI;   //!
   TBranch        *b_P1_PT;   //!
   TBranch        *b_P1_THETA;   //!
   TBranch        *b_P1_MCP_numPseudoTypes;   //!
   TBranch        *b_P1_MCP_MCP_PseudoLen;   //!
   TBranch        *b_P1_MCP_PseudoTypes;   //!
   TBranch        *b_P1_MC_MOTHER_ID;   //!
   TBranch        *b_P1_MC_MOTHER_KEY;   //!
   TBranch        *b_P1_MC_GD_MOTHER_ID;   //!
   TBranch        *b_P1_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_P1_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_P1_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_P1_TRUEP_E;   //!
   TBranch        *b_P1_TRUEP_X;   //!
   TBranch        *b_P1_TRUEP_Y;   //!
   TBranch        *b_P1_TRUEP_Z;   //!
   TBranch        *b_P1_TRUEPT;   //!
   TBranch        *b_P1_TRUEORIGINVERTEX_X;   //!
   TBranch        *b_P1_TRUEORIGINVERTEX_Y;   //!
   TBranch        *b_P1_TRUEORIGINVERTEX_Z;   //!
   TBranch        *b_P1_TRUEENDVERTEX_X;   //!
   TBranch        *b_P1_TRUEENDVERTEX_Y;   //!
   TBranch        *b_P1_TRUEENDVERTEX_Z;   //!
   TBranch        *b_P1_TRUEISSTABLE;   //!
   TBranch        *b_P1_TRUETAU;   //!
   TBranch        *b_P1_ID;   //!
   TBranch        *b_P1_Reconstructible;   //!
   TBranch        *b_P1_Reconstructed;   //!
   TBranch        *b_P1_ProtoParticles;   //!
   TBranch        *b_P1_PP_PX;   //!
   TBranch        *b_P1_PP_PY;   //!
   TBranch        *b_P1_PP_PZ;   //!
   TBranch        *b_P1_PP_Weight;   //!
   TBranch        *b_P1_PP_tr_pchi2;   //!
   TBranch        *b_P1_PP_DLLe;   //!
   TBranch        *b_P1_PP_DLLk;   //!
   TBranch        *b_P1_PP_DLLp;   //!
   TBranch        *b_P1_PP_DLLmu;   //!
   TBranch        *b_sPi_ETA;   //!
   TBranch        *b_sPi_PHI;   //!
   TBranch        *b_sPi_PT;   //!
   TBranch        *b_sPi_THETA;   //!
   TBranch        *b_sPi_MCP_numPseudoTypes;   //!
   TBranch        *b_sPi_MCP_MCP_PseudoLen;   //!
   TBranch        *b_sPi_MCP_PseudoTypes;   //!
   TBranch        *b_sPi_MC_MOTHER_ID;   //!
   TBranch        *b_sPi_MC_MOTHER_KEY;   //!
   TBranch        *b_sPi_MC_GD_MOTHER_ID;   //!
   TBranch        *b_sPi_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_sPi_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_sPi_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_sPi_TRUEP_E;   //!
   TBranch        *b_sPi_TRUEP_X;   //!
   TBranch        *b_sPi_TRUEP_Y;   //!
   TBranch        *b_sPi_TRUEP_Z;   //!
   TBranch        *b_sPi_TRUEPT;   //!
   TBranch        *b_sPi_TRUEORIGINVERTEX_X;   //!
   TBranch        *b_sPi_TRUEORIGINVERTEX_Y;   //!
   TBranch        *b_sPi_TRUEORIGINVERTEX_Z;   //!
   TBranch        *b_sPi_TRUEENDVERTEX_X;   //!
   TBranch        *b_sPi_TRUEENDVERTEX_Y;   //!
   TBranch        *b_sPi_TRUEENDVERTEX_Z;   //!
   TBranch        *b_sPi_TRUEISSTABLE;   //!
   TBranch        *b_sPi_TRUETAU;   //!
   TBranch        *b_sPi_ID;   //!
   TBranch        *b_sPi_Reconstructible;   //!
   TBranch        *b_sPi_Reconstructed;   //!
   TBranch        *b_sPi_ProtoParticles;   //!
   TBranch        *b_sPi_PP_PX;   //!
   TBranch        *b_sPi_PP_PY;   //!
   TBranch        *b_sPi_PP_PZ;   //!
   TBranch        *b_sPi_PP_Weight;   //!
   TBranch        *b_sPi_PP_tr_pchi2;   //!
   TBranch        *b_sPi_PP_DLLe;   //!
   TBranch        *b_sPi_PP_DLLk;   //!
   TBranch        *b_sPi_PP_DLLp;   //!
   TBranch        *b_sPi_PP_DLLmu;   //!
   TBranch        *b_nCandidate;   //!
   TBranch        *b_totCandidates;   //!
   TBranch        *b_EventInSequence;   //!
   TBranch        *b_MCPVs;   //!
   TBranch        *b_MCPVX;   //!
   TBranch        *b_MCPVY;   //!
   TBranch        *b_MCPVZ;   //!
   TBranch        *b_MCPVT;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_BCID;   //!
   TBranch        *b_BCType;   //!
   TBranch        *b_OdinTCK;   //!
   TBranch        *b_L0DUTCK;   //!
   TBranch        *b_HLT1TCK;   //!
   TBranch        *b_HLT2TCK;   //!
   TBranch        *b_GpsTime;   //!
   TBranch        *b_Polarity;   //!

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
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("minisample_Dst2D0pi_D02Kpi_2016_Up_GEN.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("minisample_Dst2D0pi_D02Kpi_2016_Up_GEN.root");
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

   fChain->SetBranchAddress("Dst_ETA", &Dst_ETA, &b_Dst_ETA);
   fChain->SetBranchAddress("Dst_PHI", &Dst_PHI, &b_Dst_PHI);
   fChain->SetBranchAddress("Dst_PT", &Dst_PT, &b_Dst_PT);
   fChain->SetBranchAddress("Dst_THETA", &Dst_THETA, &b_Dst_THETA);
   fChain->SetBranchAddress("Dst_MCP_numPseudoTypes", &Dst_MCP_numPseudoTypes, &b_Dst_MCP_numPseudoTypes);
   fChain->SetBranchAddress("Dst_MCP_MCP_PseudoLen", &Dst_MCP_MCP_PseudoLen, &b_Dst_MCP_MCP_PseudoLen);
   fChain->SetBranchAddress("Dst_MCP_PseudoTypes", Dst_MCP_PseudoTypes, &b_Dst_MCP_PseudoTypes);
   fChain->SetBranchAddress("Dst_MC_MOTHER_ID", &Dst_MC_MOTHER_ID, &b_Dst_MC_MOTHER_ID);
   fChain->SetBranchAddress("Dst_MC_MOTHER_KEY", &Dst_MC_MOTHER_KEY, &b_Dst_MC_MOTHER_KEY);
   fChain->SetBranchAddress("Dst_MC_GD_MOTHER_ID", &Dst_MC_GD_MOTHER_ID, &b_Dst_MC_GD_MOTHER_ID);
   fChain->SetBranchAddress("Dst_MC_GD_MOTHER_KEY", &Dst_MC_GD_MOTHER_KEY, &b_Dst_MC_GD_MOTHER_KEY);
   fChain->SetBranchAddress("Dst_MC_GD_GD_MOTHER_ID", &Dst_MC_GD_GD_MOTHER_ID, &b_Dst_MC_GD_GD_MOTHER_ID);
   fChain->SetBranchAddress("Dst_MC_GD_GD_MOTHER_KEY", &Dst_MC_GD_GD_MOTHER_KEY, &b_Dst_MC_GD_GD_MOTHER_KEY);
   fChain->SetBranchAddress("Dst_TRUEP_E", &Dst_TRUEP_E, &b_Dst_TRUEP_E);
   fChain->SetBranchAddress("Dst_TRUEP_X", &Dst_TRUEP_X, &b_Dst_TRUEP_X);
   fChain->SetBranchAddress("Dst_TRUEP_Y", &Dst_TRUEP_Y, &b_Dst_TRUEP_Y);
   fChain->SetBranchAddress("Dst_TRUEP_Z", &Dst_TRUEP_Z, &b_Dst_TRUEP_Z);
   fChain->SetBranchAddress("Dst_TRUEPT", &Dst_TRUEPT, &b_Dst_TRUEPT);
   fChain->SetBranchAddress("Dst_TRUEORIGINVERTEX_X", &Dst_TRUEORIGINVERTEX_X, &b_Dst_TRUEORIGINVERTEX_X);
   fChain->SetBranchAddress("Dst_TRUEORIGINVERTEX_Y", &Dst_TRUEORIGINVERTEX_Y, &b_Dst_TRUEORIGINVERTEX_Y);
   fChain->SetBranchAddress("Dst_TRUEORIGINVERTEX_Z", &Dst_TRUEORIGINVERTEX_Z, &b_Dst_TRUEORIGINVERTEX_Z);
   fChain->SetBranchAddress("Dst_TRUEENDVERTEX_X", &Dst_TRUEENDVERTEX_X, &b_Dst_TRUEENDVERTEX_X);
   fChain->SetBranchAddress("Dst_TRUEENDVERTEX_Y", &Dst_TRUEENDVERTEX_Y, &b_Dst_TRUEENDVERTEX_Y);
   fChain->SetBranchAddress("Dst_TRUEENDVERTEX_Z", &Dst_TRUEENDVERTEX_Z, &b_Dst_TRUEENDVERTEX_Z);
   fChain->SetBranchAddress("Dst_TRUEISSTABLE", &Dst_TRUEISSTABLE, &b_Dst_TRUEISSTABLE);
   fChain->SetBranchAddress("Dst_TRUETAU", &Dst_TRUETAU, &b_Dst_TRUETAU);
   fChain->SetBranchAddress("Dst_ID", &Dst_ID, &b_Dst_ID);
   fChain->SetBranchAddress("Dst_Reconstructible", &Dst_Reconstructible, &b_Dst_Reconstructible);
   fChain->SetBranchAddress("Dst_Reconstructed", &Dst_Reconstructed, &b_Dst_Reconstructed);
   fChain->SetBranchAddress("Dst_ProtoParticles", &Dst_ProtoParticles, &b_Dst_ProtoParticles);
   fChain->SetBranchAddress("Dst_PP_PX", Dst_PP_PX, &b_Dst_PP_PX);
   fChain->SetBranchAddress("Dst_PP_PY", Dst_PP_PY, &b_Dst_PP_PY);
   fChain->SetBranchAddress("Dst_PP_PZ", Dst_PP_PZ, &b_Dst_PP_PZ);
   fChain->SetBranchAddress("Dst_PP_Weight", Dst_PP_Weight, &b_Dst_PP_Weight);
   fChain->SetBranchAddress("Dst_PP_tr_pchi2", Dst_PP_tr_pchi2, &b_Dst_PP_tr_pchi2);
   fChain->SetBranchAddress("Dst_PP_DLLe", Dst_PP_DLLe, &b_Dst_PP_DLLe);
   fChain->SetBranchAddress("Dst_PP_DLLk", Dst_PP_DLLk, &b_Dst_PP_DLLk);
   fChain->SetBranchAddress("Dst_PP_DLLp", Dst_PP_DLLp, &b_Dst_PP_DLLp);
   fChain->SetBranchAddress("Dst_PP_DLLmu", Dst_PP_DLLmu, &b_Dst_PP_DLLmu);
   fChain->SetBranchAddress("D0_ETA", &D0_ETA, &b_D0_ETA);
   fChain->SetBranchAddress("D0_PHI", &D0_PHI, &b_D0_PHI);
   fChain->SetBranchAddress("D0_PT", &D0_PT, &b_D0_PT);
   fChain->SetBranchAddress("D0_THETA", &D0_THETA, &b_D0_THETA);
   fChain->SetBranchAddress("D0_MCP_numPseudoTypes", &D0_MCP_numPseudoTypes, &b_D0_MCP_numPseudoTypes);
   fChain->SetBranchAddress("D0_MCP_MCP_PseudoLen", &D0_MCP_MCP_PseudoLen, &b_D0_MCP_MCP_PseudoLen);
   fChain->SetBranchAddress("D0_MCP_PseudoTypes", D0_MCP_PseudoTypes, &b_D0_MCP_PseudoTypes);
   fChain->SetBranchAddress("D0_MC_MOTHER_ID", &D0_MC_MOTHER_ID, &b_D0_MC_MOTHER_ID);
   fChain->SetBranchAddress("D0_MC_MOTHER_KEY", &D0_MC_MOTHER_KEY, &b_D0_MC_MOTHER_KEY);
   fChain->SetBranchAddress("D0_MC_GD_MOTHER_ID", &D0_MC_GD_MOTHER_ID, &b_D0_MC_GD_MOTHER_ID);
   fChain->SetBranchAddress("D0_MC_GD_MOTHER_KEY", &D0_MC_GD_MOTHER_KEY, &b_D0_MC_GD_MOTHER_KEY);
   fChain->SetBranchAddress("D0_MC_GD_GD_MOTHER_ID", &D0_MC_GD_GD_MOTHER_ID, &b_D0_MC_GD_GD_MOTHER_ID);
   fChain->SetBranchAddress("D0_MC_GD_GD_MOTHER_KEY", &D0_MC_GD_GD_MOTHER_KEY, &b_D0_MC_GD_GD_MOTHER_KEY);
   fChain->SetBranchAddress("D0_TRUEP_E", &D0_TRUEP_E, &b_D0_TRUEP_E);
   fChain->SetBranchAddress("D0_TRUEP_X", &D0_TRUEP_X, &b_D0_TRUEP_X);
   fChain->SetBranchAddress("D0_TRUEP_Y", &D0_TRUEP_Y, &b_D0_TRUEP_Y);
   fChain->SetBranchAddress("D0_TRUEP_Z", &D0_TRUEP_Z, &b_D0_TRUEP_Z);
   fChain->SetBranchAddress("D0_TRUEPT", &D0_TRUEPT, &b_D0_TRUEPT);
   fChain->SetBranchAddress("D0_TRUEORIGINVERTEX_X", &D0_TRUEORIGINVERTEX_X, &b_D0_TRUEORIGINVERTEX_X);
   fChain->SetBranchAddress("D0_TRUEORIGINVERTEX_Y", &D0_TRUEORIGINVERTEX_Y, &b_D0_TRUEORIGINVERTEX_Y);
   fChain->SetBranchAddress("D0_TRUEORIGINVERTEX_Z", &D0_TRUEORIGINVERTEX_Z, &b_D0_TRUEORIGINVERTEX_Z);
   fChain->SetBranchAddress("D0_TRUEENDVERTEX_X", &D0_TRUEENDVERTEX_X, &b_D0_TRUEENDVERTEX_X);
   fChain->SetBranchAddress("D0_TRUEENDVERTEX_Y", &D0_TRUEENDVERTEX_Y, &b_D0_TRUEENDVERTEX_Y);
   fChain->SetBranchAddress("D0_TRUEENDVERTEX_Z", &D0_TRUEENDVERTEX_Z, &b_D0_TRUEENDVERTEX_Z);
   fChain->SetBranchAddress("D0_TRUEISSTABLE", &D0_TRUEISSTABLE, &b_D0_TRUEISSTABLE);
   fChain->SetBranchAddress("D0_TRUETAU", &D0_TRUETAU, &b_D0_TRUETAU);
   fChain->SetBranchAddress("D0_ID", &D0_ID, &b_D0_ID);
   fChain->SetBranchAddress("D0_Reconstructible", &D0_Reconstructible, &b_D0_Reconstructible);
   fChain->SetBranchAddress("D0_Reconstructed", &D0_Reconstructed, &b_D0_Reconstructed);
   fChain->SetBranchAddress("D0_ProtoParticles", &D0_ProtoParticles, &b_D0_ProtoParticles);
   fChain->SetBranchAddress("D0_PP_PX", D0_PP_PX, &b_D0_PP_PX);
   fChain->SetBranchAddress("D0_PP_PY", D0_PP_PY, &b_D0_PP_PY);
   fChain->SetBranchAddress("D0_PP_PZ", D0_PP_PZ, &b_D0_PP_PZ);
   fChain->SetBranchAddress("D0_PP_Weight", D0_PP_Weight, &b_D0_PP_Weight);
   fChain->SetBranchAddress("D0_PP_tr_pchi2", D0_PP_tr_pchi2, &b_D0_PP_tr_pchi2);
   fChain->SetBranchAddress("D0_PP_DLLe", D0_PP_DLLe, &b_D0_PP_DLLe);
   fChain->SetBranchAddress("D0_PP_DLLk", D0_PP_DLLk, &b_D0_PP_DLLk);
   fChain->SetBranchAddress("D0_PP_DLLp", D0_PP_DLLp, &b_D0_PP_DLLp);
   fChain->SetBranchAddress("D0_PP_DLLmu", D0_PP_DLLmu, &b_D0_PP_DLLmu);
   fChain->SetBranchAddress("P2_ETA", &P2_ETA, &b_P2_ETA);
   fChain->SetBranchAddress("P2_PHI", &P2_PHI, &b_P2_PHI);
   fChain->SetBranchAddress("P2_PT", &P2_PT, &b_P2_PT);
   fChain->SetBranchAddress("P2_THETA", &P2_THETA, &b_P2_THETA);
   fChain->SetBranchAddress("P2_MCP_numPseudoTypes", &P2_MCP_numPseudoTypes, &b_P2_MCP_numPseudoTypes);
   fChain->SetBranchAddress("P2_MCP_MCP_PseudoLen", &P2_MCP_MCP_PseudoLen, &b_P2_MCP_MCP_PseudoLen);
   fChain->SetBranchAddress("P2_MCP_PseudoTypes", P2_MCP_PseudoTypes, &b_P2_MCP_PseudoTypes);
   fChain->SetBranchAddress("P2_MC_MOTHER_ID", &P2_MC_MOTHER_ID, &b_P2_MC_MOTHER_ID);
   fChain->SetBranchAddress("P2_MC_MOTHER_KEY", &P2_MC_MOTHER_KEY, &b_P2_MC_MOTHER_KEY);
   fChain->SetBranchAddress("P2_MC_GD_MOTHER_ID", &P2_MC_GD_MOTHER_ID, &b_P2_MC_GD_MOTHER_ID);
   fChain->SetBranchAddress("P2_MC_GD_MOTHER_KEY", &P2_MC_GD_MOTHER_KEY, &b_P2_MC_GD_MOTHER_KEY);
   fChain->SetBranchAddress("P2_MC_GD_GD_MOTHER_ID", &P2_MC_GD_GD_MOTHER_ID, &b_P2_MC_GD_GD_MOTHER_ID);
   fChain->SetBranchAddress("P2_MC_GD_GD_MOTHER_KEY", &P2_MC_GD_GD_MOTHER_KEY, &b_P2_MC_GD_GD_MOTHER_KEY);
   fChain->SetBranchAddress("P2_TRUEP_E", &P2_TRUEP_E, &b_P2_TRUEP_E);
   fChain->SetBranchAddress("P2_TRUEP_X", &P2_TRUEP_X, &b_P2_TRUEP_X);
   fChain->SetBranchAddress("P2_TRUEP_Y", &P2_TRUEP_Y, &b_P2_TRUEP_Y);
   fChain->SetBranchAddress("P2_TRUEP_Z", &P2_TRUEP_Z, &b_P2_TRUEP_Z);
   fChain->SetBranchAddress("P2_TRUEPT", &P2_TRUEPT, &b_P2_TRUEPT);
   fChain->SetBranchAddress("P2_TRUEORIGINVERTEX_X", &P2_TRUEORIGINVERTEX_X, &b_P2_TRUEORIGINVERTEX_X);
   fChain->SetBranchAddress("P2_TRUEORIGINVERTEX_Y", &P2_TRUEORIGINVERTEX_Y, &b_P2_TRUEORIGINVERTEX_Y);
   fChain->SetBranchAddress("P2_TRUEORIGINVERTEX_Z", &P2_TRUEORIGINVERTEX_Z, &b_P2_TRUEORIGINVERTEX_Z);
   fChain->SetBranchAddress("P2_TRUEENDVERTEX_X", &P2_TRUEENDVERTEX_X, &b_P2_TRUEENDVERTEX_X);
   fChain->SetBranchAddress("P2_TRUEENDVERTEX_Y", &P2_TRUEENDVERTEX_Y, &b_P2_TRUEENDVERTEX_Y);
   fChain->SetBranchAddress("P2_TRUEENDVERTEX_Z", &P2_TRUEENDVERTEX_Z, &b_P2_TRUEENDVERTEX_Z);
   fChain->SetBranchAddress("P2_TRUEISSTABLE", &P2_TRUEISSTABLE, &b_P2_TRUEISSTABLE);
   fChain->SetBranchAddress("P2_TRUETAU", &P2_TRUETAU, &b_P2_TRUETAU);
   fChain->SetBranchAddress("P2_ID", &P2_ID, &b_P2_ID);
   fChain->SetBranchAddress("P2_Reconstructible", &P2_Reconstructible, &b_P2_Reconstructible);
   fChain->SetBranchAddress("P2_Reconstructed", &P2_Reconstructed, &b_P2_Reconstructed);
   fChain->SetBranchAddress("P2_ProtoParticles", &P2_ProtoParticles, &b_P2_ProtoParticles);
   fChain->SetBranchAddress("P2_PP_PX", P2_PP_PX, &b_P2_PP_PX);
   fChain->SetBranchAddress("P2_PP_PY", P2_PP_PY, &b_P2_PP_PY);
   fChain->SetBranchAddress("P2_PP_PZ", P2_PP_PZ, &b_P2_PP_PZ);
   fChain->SetBranchAddress("P2_PP_Weight", P2_PP_Weight, &b_P2_PP_Weight);
   fChain->SetBranchAddress("P2_PP_tr_pchi2", P2_PP_tr_pchi2, &b_P2_PP_tr_pchi2);
   fChain->SetBranchAddress("P2_PP_DLLe", P2_PP_DLLe, &b_P2_PP_DLLe);
   fChain->SetBranchAddress("P2_PP_DLLk", P2_PP_DLLk, &b_P2_PP_DLLk);
   fChain->SetBranchAddress("P2_PP_DLLp", P2_PP_DLLp, &b_P2_PP_DLLp);
   fChain->SetBranchAddress("P2_PP_DLLmu", P2_PP_DLLmu, &b_P2_PP_DLLmu);
   fChain->SetBranchAddress("P1_ETA", &P1_ETA, &b_P1_ETA);
   fChain->SetBranchAddress("P1_PHI", &P1_PHI, &b_P1_PHI);
   fChain->SetBranchAddress("P1_PT", &P1_PT, &b_P1_PT);
   fChain->SetBranchAddress("P1_THETA", &P1_THETA, &b_P1_THETA);
   fChain->SetBranchAddress("P1_MCP_numPseudoTypes", &P1_MCP_numPseudoTypes, &b_P1_MCP_numPseudoTypes);
   fChain->SetBranchAddress("P1_MCP_MCP_PseudoLen", &P1_MCP_MCP_PseudoLen, &b_P1_MCP_MCP_PseudoLen);
   fChain->SetBranchAddress("P1_MCP_PseudoTypes", P1_MCP_PseudoTypes, &b_P1_MCP_PseudoTypes);
   fChain->SetBranchAddress("P1_MC_MOTHER_ID", &P1_MC_MOTHER_ID, &b_P1_MC_MOTHER_ID);
   fChain->SetBranchAddress("P1_MC_MOTHER_KEY", &P1_MC_MOTHER_KEY, &b_P1_MC_MOTHER_KEY);
   fChain->SetBranchAddress("P1_MC_GD_MOTHER_ID", &P1_MC_GD_MOTHER_ID, &b_P1_MC_GD_MOTHER_ID);
   fChain->SetBranchAddress("P1_MC_GD_MOTHER_KEY", &P1_MC_GD_MOTHER_KEY, &b_P1_MC_GD_MOTHER_KEY);
   fChain->SetBranchAddress("P1_MC_GD_GD_MOTHER_ID", &P1_MC_GD_GD_MOTHER_ID, &b_P1_MC_GD_GD_MOTHER_ID);
   fChain->SetBranchAddress("P1_MC_GD_GD_MOTHER_KEY", &P1_MC_GD_GD_MOTHER_KEY, &b_P1_MC_GD_GD_MOTHER_KEY);
   fChain->SetBranchAddress("P1_TRUEP_E", &P1_TRUEP_E, &b_P1_TRUEP_E);
   fChain->SetBranchAddress("P1_TRUEP_X", &P1_TRUEP_X, &b_P1_TRUEP_X);
   fChain->SetBranchAddress("P1_TRUEP_Y", &P1_TRUEP_Y, &b_P1_TRUEP_Y);
   fChain->SetBranchAddress("P1_TRUEP_Z", &P1_TRUEP_Z, &b_P1_TRUEP_Z);
   fChain->SetBranchAddress("P1_TRUEPT", &P1_TRUEPT, &b_P1_TRUEPT);
   fChain->SetBranchAddress("P1_TRUEORIGINVERTEX_X", &P1_TRUEORIGINVERTEX_X, &b_P1_TRUEORIGINVERTEX_X);
   fChain->SetBranchAddress("P1_TRUEORIGINVERTEX_Y", &P1_TRUEORIGINVERTEX_Y, &b_P1_TRUEORIGINVERTEX_Y);
   fChain->SetBranchAddress("P1_TRUEORIGINVERTEX_Z", &P1_TRUEORIGINVERTEX_Z, &b_P1_TRUEORIGINVERTEX_Z);
   fChain->SetBranchAddress("P1_TRUEENDVERTEX_X", &P1_TRUEENDVERTEX_X, &b_P1_TRUEENDVERTEX_X);
   fChain->SetBranchAddress("P1_TRUEENDVERTEX_Y", &P1_TRUEENDVERTEX_Y, &b_P1_TRUEENDVERTEX_Y);
   fChain->SetBranchAddress("P1_TRUEENDVERTEX_Z", &P1_TRUEENDVERTEX_Z, &b_P1_TRUEENDVERTEX_Z);
   fChain->SetBranchAddress("P1_TRUEISSTABLE", &P1_TRUEISSTABLE, &b_P1_TRUEISSTABLE);
   fChain->SetBranchAddress("P1_TRUETAU", &P1_TRUETAU, &b_P1_TRUETAU);
   fChain->SetBranchAddress("P1_ID", &P1_ID, &b_P1_ID);
   fChain->SetBranchAddress("P1_Reconstructible", &P1_Reconstructible, &b_P1_Reconstructible);
   fChain->SetBranchAddress("P1_Reconstructed", &P1_Reconstructed, &b_P1_Reconstructed);
   fChain->SetBranchAddress("P1_ProtoParticles", &P1_ProtoParticles, &b_P1_ProtoParticles);
   fChain->SetBranchAddress("P1_PP_PX", P1_PP_PX, &b_P1_PP_PX);
   fChain->SetBranchAddress("P1_PP_PY", P1_PP_PY, &b_P1_PP_PY);
   fChain->SetBranchAddress("P1_PP_PZ", P1_PP_PZ, &b_P1_PP_PZ);
   fChain->SetBranchAddress("P1_PP_Weight", P1_PP_Weight, &b_P1_PP_Weight);
   fChain->SetBranchAddress("P1_PP_tr_pchi2", P1_PP_tr_pchi2, &b_P1_PP_tr_pchi2);
   fChain->SetBranchAddress("P1_PP_DLLe", P1_PP_DLLe, &b_P1_PP_DLLe);
   fChain->SetBranchAddress("P1_PP_DLLk", P1_PP_DLLk, &b_P1_PP_DLLk);
   fChain->SetBranchAddress("P1_PP_DLLp", P1_PP_DLLp, &b_P1_PP_DLLp);
   fChain->SetBranchAddress("P1_PP_DLLmu", P1_PP_DLLmu, &b_P1_PP_DLLmu);
   fChain->SetBranchAddress("sPi_ETA", &sPi_ETA, &b_sPi_ETA);
   fChain->SetBranchAddress("sPi_PHI", &sPi_PHI, &b_sPi_PHI);
   fChain->SetBranchAddress("sPi_PT", &sPi_PT, &b_sPi_PT);
   fChain->SetBranchAddress("sPi_THETA", &sPi_THETA, &b_sPi_THETA);
   fChain->SetBranchAddress("sPi_MCP_numPseudoTypes", &sPi_MCP_numPseudoTypes, &b_sPi_MCP_numPseudoTypes);
   fChain->SetBranchAddress("sPi_MCP_MCP_PseudoLen", &sPi_MCP_MCP_PseudoLen, &b_sPi_MCP_MCP_PseudoLen);
   fChain->SetBranchAddress("sPi_MCP_PseudoTypes", sPi_MCP_PseudoTypes, &b_sPi_MCP_PseudoTypes);
   fChain->SetBranchAddress("sPi_MC_MOTHER_ID", &sPi_MC_MOTHER_ID, &b_sPi_MC_MOTHER_ID);
   fChain->SetBranchAddress("sPi_MC_MOTHER_KEY", &sPi_MC_MOTHER_KEY, &b_sPi_MC_MOTHER_KEY);
   fChain->SetBranchAddress("sPi_MC_GD_MOTHER_ID", &sPi_MC_GD_MOTHER_ID, &b_sPi_MC_GD_MOTHER_ID);
   fChain->SetBranchAddress("sPi_MC_GD_MOTHER_KEY", &sPi_MC_GD_MOTHER_KEY, &b_sPi_MC_GD_MOTHER_KEY);
   fChain->SetBranchAddress("sPi_MC_GD_GD_MOTHER_ID", &sPi_MC_GD_GD_MOTHER_ID, &b_sPi_MC_GD_GD_MOTHER_ID);
   fChain->SetBranchAddress("sPi_MC_GD_GD_MOTHER_KEY", &sPi_MC_GD_GD_MOTHER_KEY, &b_sPi_MC_GD_GD_MOTHER_KEY);
   fChain->SetBranchAddress("sPi_TRUEP_E", &sPi_TRUEP_E, &b_sPi_TRUEP_E);
   fChain->SetBranchAddress("sPi_TRUEP_X", &sPi_TRUEP_X, &b_sPi_TRUEP_X);
   fChain->SetBranchAddress("sPi_TRUEP_Y", &sPi_TRUEP_Y, &b_sPi_TRUEP_Y);
   fChain->SetBranchAddress("sPi_TRUEP_Z", &sPi_TRUEP_Z, &b_sPi_TRUEP_Z);
   fChain->SetBranchAddress("sPi_TRUEPT", &sPi_TRUEPT, &b_sPi_TRUEPT);
   fChain->SetBranchAddress("sPi_TRUEORIGINVERTEX_X", &sPi_TRUEORIGINVERTEX_X, &b_sPi_TRUEORIGINVERTEX_X);
   fChain->SetBranchAddress("sPi_TRUEORIGINVERTEX_Y", &sPi_TRUEORIGINVERTEX_Y, &b_sPi_TRUEORIGINVERTEX_Y);
   fChain->SetBranchAddress("sPi_TRUEORIGINVERTEX_Z", &sPi_TRUEORIGINVERTEX_Z, &b_sPi_TRUEORIGINVERTEX_Z);
   fChain->SetBranchAddress("sPi_TRUEENDVERTEX_X", &sPi_TRUEENDVERTEX_X, &b_sPi_TRUEENDVERTEX_X);
   fChain->SetBranchAddress("sPi_TRUEENDVERTEX_Y", &sPi_TRUEENDVERTEX_Y, &b_sPi_TRUEENDVERTEX_Y);
   fChain->SetBranchAddress("sPi_TRUEENDVERTEX_Z", &sPi_TRUEENDVERTEX_Z, &b_sPi_TRUEENDVERTEX_Z);
   fChain->SetBranchAddress("sPi_TRUEISSTABLE", &sPi_TRUEISSTABLE, &b_sPi_TRUEISSTABLE);
   fChain->SetBranchAddress("sPi_TRUETAU", &sPi_TRUETAU, &b_sPi_TRUETAU);
   fChain->SetBranchAddress("sPi_ID", &sPi_ID, &b_sPi_ID);
   fChain->SetBranchAddress("sPi_Reconstructible", &sPi_Reconstructible, &b_sPi_Reconstructible);
   fChain->SetBranchAddress("sPi_Reconstructed", &sPi_Reconstructed, &b_sPi_Reconstructed);
   fChain->SetBranchAddress("sPi_ProtoParticles", &sPi_ProtoParticles, &b_sPi_ProtoParticles);
   fChain->SetBranchAddress("sPi_PP_PX", sPi_PP_PX, &b_sPi_PP_PX);
   fChain->SetBranchAddress("sPi_PP_PY", sPi_PP_PY, &b_sPi_PP_PY);
   fChain->SetBranchAddress("sPi_PP_PZ", sPi_PP_PZ, &b_sPi_PP_PZ);
   fChain->SetBranchAddress("sPi_PP_Weight", sPi_PP_Weight, &b_sPi_PP_Weight);
   fChain->SetBranchAddress("sPi_PP_tr_pchi2", sPi_PP_tr_pchi2, &b_sPi_PP_tr_pchi2);
   fChain->SetBranchAddress("sPi_PP_DLLe", sPi_PP_DLLe, &b_sPi_PP_DLLe);
   fChain->SetBranchAddress("sPi_PP_DLLk", sPi_PP_DLLk, &b_sPi_PP_DLLk);
   fChain->SetBranchAddress("sPi_PP_DLLp", sPi_PP_DLLp, &b_sPi_PP_DLLp);
   fChain->SetBranchAddress("sPi_PP_DLLmu", sPi_PP_DLLmu, &b_sPi_PP_DLLmu);
   fChain->SetBranchAddress("nCandidate", &nCandidate, &b_nCandidate);
   fChain->SetBranchAddress("totCandidates", &totCandidates, &b_totCandidates);
   fChain->SetBranchAddress("EventInSequence", &EventInSequence, &b_EventInSequence);
   fChain->SetBranchAddress("MCPVs", &MCPVs, &b_MCPVs);
   fChain->SetBranchAddress("MCPVX", MCPVX, &b_MCPVX);
   fChain->SetBranchAddress("MCPVY", MCPVY, &b_MCPVY);
   fChain->SetBranchAddress("MCPVZ", MCPVZ, &b_MCPVZ);
   fChain->SetBranchAddress("MCPVT", MCPVT, &b_MCPVT);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("BCID", &BCID, &b_BCID);
   fChain->SetBranchAddress("BCType", &BCType, &b_BCType);
   fChain->SetBranchAddress("OdinTCK", &OdinTCK, &b_OdinTCK);
   fChain->SetBranchAddress("L0DUTCK", &L0DUTCK, &b_L0DUTCK);
   fChain->SetBranchAddress("HLT1TCK", &HLT1TCK, &b_HLT1TCK);
   fChain->SetBranchAddress("HLT2TCK", &HLT2TCK, &b_HLT2TCK);
   fChain->SetBranchAddress("GpsTime", &GpsTime, &b_GpsTime);
   fChain->SetBranchAddress("Polarity", &Polarity, &b_Polarity);
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
