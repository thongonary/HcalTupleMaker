//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Aug  5 06:56:47 2015 by ROOT version 6.05/01
// from TTree tree/
// found on file: TestMET.root
//////////////////////////////////////////////////////////

#ifndef MET_h
#define MET_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TH1F.h>
#include <TH1I.h>
#include <TH2F.h>
#include <THStack.h>
#include <TGraphErrors.h>
//#include <TProofServ.h>
#include <TString.h>
#include <math.h>
#include <TVector3.h>
#include <TH2F.h>
#include <TGraphAsymmErrors.h>
// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "vector"
#include "vector"

class MET : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

// Histogram
   TH1F * FlaggedEnergy, *FlaggedEt, *FlaggedSumEnergy, *FlaggedSumEnergy_Extracted, *FlaggedSumEt, *FlaggedSumEt_Extracted, *CleanMET, *NonCleanMET, *R45_NEFFlagged, *R45_NEFNonFlagged, *TS03Flagged, *TS03NonFlagged;
   TH2F * Energy_Count, *METCorrelate;
   TH1I * FlaggedCount, *FlaggedCount_Extracted, *ChargeTS;
   TH2F *FlagCorrelate, *R45_NEFFlaggedSum45, *R45_NEFNonFlaggedSum45;
    Int_t NumberOfNEFFlags, NumberOfSpikeFlags;
   //Int_t nbins;
   //Double_t energyCut[11];
   TH1F *mistag, *mistagRaw, *totalRange, *totalRawRange, *TS45, *TS456, *TS45_NEF, *TS456_NEF, *IsolatedRechitEnergy; 
   TH1F *mistagSpike, *mistagRawSpike, *TS45_Spike, *TS456_Spike; 
// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   vector<double>  *EBET;
   vector<double>  *EBSumE;
   vector<double>  *EBSumET;
   vector<double>  *EEET;
   vector<double>  *EESumE;
   vector<double>  *EESumET;
   vector<double>  *HBET;
   vector<double>  *HBSumE;
   vector<double>  *HBSumET;
   vector<double>  *HEET;
   vector<double>  *HESumE;
   vector<double>  *HESumET;
   vector<double>  *HFET;
   vector<double>  *HBHERecHitEnergyRaw;
   vector<double>  *IsolatedNoiseSumE;
   vector<double>  *IsolatedNoiseSumEt;
   vector<double>  *MaxE2E10;
   vector<double>  *MinE2E10;
   vector<double>  *NegativeNoiseSumE;
   vector<double>  *NegativeNoiseSumEt;
   vector<double>  *RBXEnergy;
   vector<double>  *RBXEnergy15;
   vector<double>  *SpikeNoiseSumE;
   vector<double>  *SpikeNoiseSumEt;
   vector<vector<double> > *HBHERecHitAuxAllfC;
   vector<vector<double> > *HBHERecHitAuxEnergy;
   vector<vector<double> > *HBHERecHitAuxFC;
   vector<vector<double> > *HBHERecHitAuxGain;
   vector<vector<double> > *HBHERecHitAuxPedFC;
   vector<vector<double> > *HBHERecHitAuxRCGain;
   vector<vector<double> > *RBXCharge;
   vector<vector<double> > *RBXCharge15;
   vector<float>   *HBHERecHitEnergy;
   vector<float>   *HBHERecHitEta;
   vector<float>   *HBHERecHitPhi;
   vector<float>   *HBHERecHitTime;
   vector<int>     *HBHERecHitAux;
   vector<int>     *HBHERecHitDepth;
   vector<int>     *HBHERecHitFlags;
   vector<int>     *HBHERecHitHPDid;
   vector<int>     *HBHERecHitIEta;
   vector<int>     *HBHERecHitIPhi;
   vector<int>     *HBHERecHitRBXid;
   vector<int>     *HPDHits;
   vector<int>     *HPDNoOtherHits;
   vector<int>     *HasBadRBXR45;
   vector<int>     *HasBadRBXRechitR45Loose;
   vector<int>     *HasBadRBXRechitR45Tight;
   vector<int>     *IsoNoiseFilterDecision;
   vector<int>     *MaxZeros;
   vector<int>     *NumIsolatedNoiseChannels;
   vector<int>     *NumNegativeNoiseChannels;
   vector<int>     *NumSpikeNoiseChannels;
   vector<int>     *OfficialDecision;
   vector<int>     *OfficialDecisionRun1;
   vector<int>     *OfficialDecisionRun2L;
   vector<int>     *OfficialDecisionRun2T;
   vector<vector<int> > *HBHERecHitAuxADC;
   vector<vector<int> > *HBHERecHitAuxCapID;
   UInt_t          event;
   UInt_t          ls;
   UInt_t          run;

   // List of branches
   TBranch        *b_EBET;   //!
   TBranch        *b_EBSumE;   //!
   TBranch        *b_EBSumET;   //!
   TBranch        *b_EEET;   //!
   TBranch        *b_EESumE;   //!
   TBranch        *b_EESumET;   //!
   TBranch        *b_HBET;   //!
   TBranch        *b_HBSumE;   //!
   TBranch        *b_HBSumET;   //!
   TBranch        *b_HEET;   //!
   TBranch        *b_HESumE;   //!
   TBranch        *b_HESumET;   //!
   TBranch        *b_HFET;   //!
   TBranch        *b_HBHERecHitEnergyRaw;   //!
   TBranch        *b_IsolatedNoiseSumE;   //!
   TBranch        *b_IsolatedNoiseSumEt;   //!
   TBranch        *b_MaxE2E10;   //!
   TBranch        *b_MinE2E10;   //!
   TBranch        *b_NegativeNoiseSumE;   //!
   TBranch        *b_NegativeNoiseSumEt;   //!
   TBranch        *b_RBXEnergy;   //!
   TBranch        *b_RBXEnergy15;   //!
   TBranch        *b_SpikeNoiseSumE;   //!
   TBranch        *b_SpikeNoiseSumEt;   //!
   TBranch        *b_HBHERecHitAuxAllfC;   //!
   TBranch        *b_HBHERecHitAuxEnergy;   //!
   TBranch        *b_HBHERecHitAuxFC;   //!
   TBranch        *b_HBHERecHitAuxGain;   //!
   TBranch        *b_HBHERecHitAuxPedFC;   //!
   TBranch        *b_HBHERecHitAuxRCGain;   //!
   TBranch        *b_RBXCharge;   //!
   TBranch        *b_RBXCharge15;   //!
   TBranch        *b_HBHERecHitEnergy;   //!
   TBranch        *b_HBHERecHitEta;   //!
   TBranch        *b_HBHERecHitPhi;   //!
   TBranch        *b_HBHERecHitTime;   //!
   TBranch        *b_HBHERecHitAux;   //!
   TBranch        *b_HBHERecHitDepth;   //!
   TBranch        *b_HBHERecHitFlags;   //!
   TBranch        *b_HBHERecHitHPDid;   //!
   TBranch        *b_HBHERecHitIEta;   //!
   TBranch        *b_HBHERecHitIPhi;   //!
   TBranch        *b_HBHERecHitRBXid;   //!
   TBranch        *b_HPDHits;   //!
   TBranch        *b_HPDNoOtherHits;   //!
   TBranch        *b_HasBadRBXR45;   //!
   TBranch        *b_HasBadRBXRechitR45Loose;   //!
   TBranch        *b_HasBadRBXRechitR45Tight;   //!
   TBranch        *b_IsoNoiseFilterDecision;   //!
   TBranch        *b_MaxZeros;   //!
   TBranch        *b_NumIsolatedNoiseChannels;   //!
   TBranch        *b_NumNegativeNoiseChannels;   //!
   TBranch        *b_NumSpikeNoiseChannels;   //!
   TBranch        *b_OfficialDecision;   //!
   TBranch        *b_OfficialDecisionRun1;   //!
   TBranch        *b_OfficialDecisionRun2L;   //!
   TBranch        *b_OfficialDecisionRun2T;   //!
   TBranch        *b_HBHERecHitAuxADC;   //!
   TBranch        *b_HBHERecHitAuxCapID;   //!
   TBranch        *b_event;   //!
   TBranch        *b_ls;   //!
   TBranch        *b_run;   //!

   MET(TTree * /*tree*/ =0) : fChain(0), NumberOfNEFFlags(0), NumberOfSpikeFlags(0) { }
   virtual ~MET() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   Bool_t FlagWordDecoder(int word, unsigned int bitNo);
   
   ClassDef(MET,0);
};

#endif

#ifdef MET_cxx
void MET::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   EBET = 0;
   EBSumE = 0;
   EBSumET = 0;
   EEET = 0;
   EESumE = 0;
   EESumET = 0;
   HBET = 0;
   HBSumE = 0;
   HBSumET = 0;
   HEET = 0;
   HESumE = 0;
   HESumET = 0;
   HFET = 0;
   HBHERecHitEnergyRaw = 0;
   IsolatedNoiseSumE = 0;
   IsolatedNoiseSumEt = 0;
   MaxE2E10 = 0;
   MinE2E10 = 0;
   NegativeNoiseSumE = 0;
   NegativeNoiseSumEt = 0;
   RBXEnergy = 0;
   RBXEnergy15 = 0;
   SpikeNoiseSumE = 0;
   SpikeNoiseSumEt = 0;
   HBHERecHitAuxAllfC = 0;
   HBHERecHitAuxEnergy = 0;
   HBHERecHitAuxFC = 0;
   HBHERecHitAuxGain = 0;
   HBHERecHitAuxPedFC = 0;
   HBHERecHitAuxRCGain = 0;
   RBXCharge = 0;
   RBXCharge15 = 0;
   HBHERecHitEnergy = 0;
   HBHERecHitEta = 0;
   HBHERecHitPhi = 0;
   HBHERecHitTime = 0;
   HBHERecHitAux = 0;
   HBHERecHitDepth = 0;
   HBHERecHitFlags = 0;
   HBHERecHitHPDid = 0;
   HBHERecHitIEta = 0;
   HBHERecHitIPhi = 0;
   HBHERecHitRBXid = 0;
   HPDHits = 0;
   HPDNoOtherHits = 0;
   HasBadRBXR45 = 0;
   HasBadRBXRechitR45Loose = 0;
   HasBadRBXRechitR45Tight = 0;
   IsoNoiseFilterDecision = 0;
   MaxZeros = 0;
   NumIsolatedNoiseChannels = 0;
   NumNegativeNoiseChannels = 0;
   NumSpikeNoiseChannels = 0;
   OfficialDecision = 0;
   OfficialDecisionRun1 = 0;
   OfficialDecisionRun2L = 0;
   OfficialDecisionRun2T = 0;
   HBHERecHitAuxADC = 0;
   HBHERecHitAuxCapID = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("EBET", &EBET, &b_EBET);
   fChain->SetBranchAddress("EBSumE", &EBSumE, &b_EBSumE);
   fChain->SetBranchAddress("EBSumET", &EBSumET, &b_EBSumET);
   fChain->SetBranchAddress("EEET", &EEET, &b_EEET);
   fChain->SetBranchAddress("EESumE", &EESumE, &b_EESumE);
   fChain->SetBranchAddress("EESumET", &EESumET, &b_EESumET);
   fChain->SetBranchAddress("HBET", &HBET, &b_HBET);
   fChain->SetBranchAddress("HBSumE", &HBSumE, &b_HBSumE);
   fChain->SetBranchAddress("HBSumET", &HBSumET, &b_HBSumET);
   fChain->SetBranchAddress("HEET", &HEET, &b_HEET);
   fChain->SetBranchAddress("HESumE", &HESumE, &b_HESumE);
   fChain->SetBranchAddress("HESumET", &HESumET, &b_HESumET);
   fChain->SetBranchAddress("HFET", &HFET, &b_HFET);
   fChain->SetBranchAddress("HBHERecHitEnergyRaw", &HBHERecHitEnergyRaw, &b_HBHERecHitEnergyRaw);
   fChain->SetBranchAddress("IsolatedNoiseSumE", &IsolatedNoiseSumE, &b_IsolatedNoiseSumE);
   fChain->SetBranchAddress("IsolatedNoiseSumEt", &IsolatedNoiseSumEt, &b_IsolatedNoiseSumEt);
   fChain->SetBranchAddress("MaxE2E10", &MaxE2E10, &b_MaxE2E10);
   fChain->SetBranchAddress("MinE2E10", &MinE2E10, &b_MinE2E10);
   fChain->SetBranchAddress("NegativeNoiseSumE", &NegativeNoiseSumE, &b_NegativeNoiseSumE);
   fChain->SetBranchAddress("NegativeNoiseSumEt", &NegativeNoiseSumEt, &b_NegativeNoiseSumEt);
   fChain->SetBranchAddress("RBXEnergy", &RBXEnergy, &b_RBXEnergy);
   fChain->SetBranchAddress("RBXEnergy15", &RBXEnergy15, &b_RBXEnergy15);
   fChain->SetBranchAddress("SpikeNoiseSumE", &SpikeNoiseSumE, &b_SpikeNoiseSumE);
   fChain->SetBranchAddress("SpikeNoiseSumEt", &SpikeNoiseSumEt, &b_SpikeNoiseSumEt);
   fChain->SetBranchAddress("HBHERecHitAuxAllfC", &HBHERecHitAuxAllfC, &b_HBHERecHitAuxAllfC);
   fChain->SetBranchAddress("HBHERecHitAuxEnergy", &HBHERecHitAuxEnergy, &b_HBHERecHitAuxEnergy);
   fChain->SetBranchAddress("HBHERecHitAuxFC", &HBHERecHitAuxFC, &b_HBHERecHitAuxFC);
   fChain->SetBranchAddress("HBHERecHitAuxGain", &HBHERecHitAuxGain, &b_HBHERecHitAuxGain);
   fChain->SetBranchAddress("HBHERecHitAuxPedFC", &HBHERecHitAuxPedFC, &b_HBHERecHitAuxPedFC);
   fChain->SetBranchAddress("HBHERecHitAuxRCGain", &HBHERecHitAuxRCGain, &b_HBHERecHitAuxRCGain);
   fChain->SetBranchAddress("RBXCharge", &RBXCharge, &b_RBXCharge);
   fChain->SetBranchAddress("RBXCharge15", &RBXCharge15, &b_RBXCharge15);
   fChain->SetBranchAddress("HBHERecHitEnergy", &HBHERecHitEnergy, &b_HBHERecHitEnergy);
   fChain->SetBranchAddress("HBHERecHitEta", &HBHERecHitEta, &b_HBHERecHitEta);
   fChain->SetBranchAddress("HBHERecHitPhi", &HBHERecHitPhi, &b_HBHERecHitPhi);
   fChain->SetBranchAddress("HBHERecHitTime", &HBHERecHitTime, &b_HBHERecHitTime);
   fChain->SetBranchAddress("HBHERecHitAux", &HBHERecHitAux, &b_HBHERecHitAux);
   fChain->SetBranchAddress("HBHERecHitDepth", &HBHERecHitDepth, &b_HBHERecHitDepth);
   fChain->SetBranchAddress("HBHERecHitFlags", &HBHERecHitFlags, &b_HBHERecHitFlags);
   fChain->SetBranchAddress("HBHERecHitHPDid", &HBHERecHitHPDid, &b_HBHERecHitHPDid);
   fChain->SetBranchAddress("HBHERecHitIEta", &HBHERecHitIEta, &b_HBHERecHitIEta);
   fChain->SetBranchAddress("HBHERecHitIPhi", &HBHERecHitIPhi, &b_HBHERecHitIPhi);
   fChain->SetBranchAddress("HBHERecHitRBXid", &HBHERecHitRBXid, &b_HBHERecHitRBXid);
   fChain->SetBranchAddress("HPDHits", &HPDHits, &b_HPDHits);
   fChain->SetBranchAddress("HPDNoOtherHits", &HPDNoOtherHits, &b_HPDNoOtherHits);
   fChain->SetBranchAddress("HasBadRBXR45", &HasBadRBXR45, &b_HasBadRBXR45);
   fChain->SetBranchAddress("HasBadRBXRechitR45Loose", &HasBadRBXRechitR45Loose, &b_HasBadRBXRechitR45Loose);
   fChain->SetBranchAddress("HasBadRBXRechitR45Tight", &HasBadRBXRechitR45Tight, &b_HasBadRBXRechitR45Tight);
   fChain->SetBranchAddress("IsoNoiseFilterDecision", &IsoNoiseFilterDecision, &b_IsoNoiseFilterDecision);
   fChain->SetBranchAddress("MaxZeros", &MaxZeros, &b_MaxZeros);
   fChain->SetBranchAddress("NumIsolatedNoiseChannels", &NumIsolatedNoiseChannels, &b_NumIsolatedNoiseChannels);
   fChain->SetBranchAddress("NumNegativeNoiseChannels", &NumNegativeNoiseChannels, &b_NumNegativeNoiseChannels);
   fChain->SetBranchAddress("NumSpikeNoiseChannels", &NumSpikeNoiseChannels, &b_NumSpikeNoiseChannels);
   fChain->SetBranchAddress("OfficialDecision", &OfficialDecision, &b_OfficialDecision);
   fChain->SetBranchAddress("OfficialDecisionRun1", &OfficialDecisionRun1, &b_OfficialDecisionRun1);
   fChain->SetBranchAddress("OfficialDecisionRun2L", &OfficialDecisionRun2L, &b_OfficialDecisionRun2L);
   fChain->SetBranchAddress("OfficialDecisionRun2T", &OfficialDecisionRun2T, &b_OfficialDecisionRun2T);
   fChain->SetBranchAddress("HBHERecHitAuxADC", &HBHERecHitAuxADC, &b_HBHERecHitAuxADC);
   fChain->SetBranchAddress("HBHERecHitAuxCapID", &HBHERecHitAuxCapID, &b_HBHERecHitAuxCapID);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("ls", &ls, &b_ls);
   fChain->SetBranchAddress("run", &run, &b_run);
}

Bool_t MET::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

Bool_t MET::FlagWordDecoder(int word, unsigned int bitNo)
{
   // The FlagWordDecoder function decodes the packed integer flagword stored in the ntuple at bit level. 
   if (((word >> bitNo ) & 1) > 0 ) return true;
   else return false;
}

#endif // #ifdef MET_cxx
