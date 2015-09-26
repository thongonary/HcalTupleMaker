#define MET_cxx
// The class definition in MET.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("MET.C")
// root> T->Process("MET.C","some options")
// root> T->Process("MET.C+")
//

#include "MET.h"
#include <TH2.h>
#include <TStyle.h>
#include <iostream>

using namespace std;
void MET::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void MET::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   FlaggedEnergy = new TH1F("FlaggedEnergy","HBHERecHitFlaggedEnergy;Energy (GeV); Events/(4.0 GeV)",50,0,200);
   FlaggedEt = new TH1F("FlaggedEt","HBHERecHitFlaggedEt;E_{T} (GeV); Events/(4.0 GeV)",50,0,200);
   FlaggedSumEnergy = new TH1F("FlaggedSumEnergy","HBHERecHitFlaggedSumEnergy;Energy (GeV); Events/(7.0 GeV)",100,0,400);
   //FlaggedSumEnergy_Extracted = new TH1F("FlaggedSumEnergy_Extracted","HBHERecHitFlaggedSumEnergy extracted ;Energy (GeV); Events/(7.0 GeV)",100,0,700);
   FlaggedSumEt = new TH1F("FlaggedSumEt","HBHERecHitFlaggedSumEt;Et (GeV); Events/(7.0 GeV)",100,0,400);
//   FlaggedSumEt_Extracted = new TH1F("FlaggedSumEt_Extracted","HBHERecHitFlaggedSumEt extracted ;Et (GeV); Events/(7.0 GeV)",100,0,700);
   FlaggedCount = new TH1I("FlaggedCount","HBHERecHit Flagged Count; Count; Events",7,0,7);
 //  FlaggedCount_Extracted = new TH1I("FlaggedCount_Extracted","HBHERecHit Flagged Count extracted; Count; Events",5,0,5);
   Energy_Count = new TH2F("Energy_Count","HBHERecHitFlagged Sum Energy vs. Count;Energy (GeV); Count",100,0,400,7,0,7);
   ChargeTS = new TH1I("ChargeTS","HBHERecHitAuxFC;TS;Charges",10,0,10);


   CleanMETx = new TH1F("CleanMETx","CleanMETx",100,-500,500); 
   CleanMETy = new TH1F("CleanMETy","CleanMETy",100,-500,500); 
   METx = new TH1F("METx","METx",100,-500,500); 
   METy = new TH1F("METy","METy",100,-500,500); 
   
   CleanMET = new TH1F("CleanMET","Cleaned Hcal MET;Hcal MET (GeV);Events/(5 GeV)",100,0,300); 
   NonCleanMET = new TH1F("NonCleanMET","Orignal Hcal MET;Hcal MET (GeV);Events/(5 GeV)",100,0,300); 
   METCorrelate = new TH2F("METCorrelate","METCorrelate;Original Hcal MET (GeV); NEF Cleaned Hcal MET (GeV)",100,0,300,100,0,300);
   
   R45_NEFFlagged = new TH1F("R45_NEFFlagged","R45_NEFFlagged;(TS4-TS5)/(TS4+TS5);Events",100,-1.5,1.5);
   R45_NEFNonFlagged = new TH1F("R45_NEFNonFlagged","R45_NEFNonFlagged;(TS4-TS5)/(TS4+TS5);Events",100,-30,30);
   
   R45_NEFFlaggedSum45 = new TH2F("R45_NEFFlaggedSum45","R45_NEFFlaggedSum45;(TS4+TS5);(TS4-TS5)/(TS4+TS5)",100,0,1000,100,-1.5,1.5);
   R45_NEFNonFlaggedSum45 = new TH2F("R45_NEFNonFlaggedSum45","R45_NEFNonFlaggedSum45;(TS4+TS5);(TS4-TS5)/(TS4+TS5)",100,0,1000,100,-1.5,1.5);

   
   TS03Flagged = new TH1F("TS03Flagged","TS03Flagged;Average;Events",100,-1,1);
   TS03NonFlagged = new TH1F("TS03NonFlagged","TS03NonFlagged;Average;Events",100,-1,1);

   FlagCorrelate = new TH2F("FlagCorrelate","Flag Correlation; NEF Flagged; Spike-like Flagged",2,0.,2.,2,0.,2.);

   fOutput->Add(R45_NEFFlaggedSum45);
   fOutput->Add(R45_NEFNonFlaggedSum45);
   fOutput->Add(FlaggedEt);
   fOutput->Add(FlaggedEnergy);
   fOutput->Add(FlaggedSumEnergy);
//   fOutput->Add(FlaggedSumEnergy_Extracted);
   fOutput->Add(FlaggedSumEt);
//   fOutput->Add(FlaggedSumEt_Extracted);
   fOutput->Add(FlaggedCount);
//   fOutput->Add(FlaggedCount_Extracted);
   fOutput->Add(Energy_Count);
   fOutput->Add(ChargeTS);
   fOutput->Add(CleanMETx);
   fOutput->Add(CleanMETy);
   fOutput->Add(CleanMET);
   fOutput->Add(NonCleanMET);
   fOutput->Add(METx);
   fOutput->Add(METy);
   fOutput->Add(METCorrelate);
   fOutput->Add(R45_NEFFlagged);
   fOutput->Add(R45_NEFNonFlagged);
   fOutput->Add(TS03Flagged);
   fOutput->Add(TS03NonFlagged);
   fOutput->Add(FlagCorrelate);
}

Bool_t MET::Process(Long64_t entry)
{
   fChain->GetTree()->GetEntry(entry);
//   fStatus;

    if (OfficialDecisionRun2L->at(0)==1 || OfficialDecisionRun2T->at(0)==1) 
  {
  // Count the number of flagged per event 
   Int_t flag_count = 0;
   Float_t sum_energy = 0;
   Float_t sum_et = 0;
   Float_t sumFlaggedMETx = 0;
   Float_t sumFlaggedMETy = 0;
   // Loop through all the RecHits in 1 event. If it's flagged by NEF then print out its energy.
   for (unsigned int i = 0; i < HBHERecHitFlags->size(); i++)
   {
        Int_t flagword = HBHERecHitFlags->at(i);
        //Int_t flagword = (*HBHERecHitFlags)[i];
        if (FlagWordDecoder(flagword,27))
        {

            ++NumberOfNEFFlags;
            flag_count++;
            FlaggedEnergy->Fill((*HBHERecHitEnergy)[i]);
            Double_t et = (*HBHERecHitEnergy)[i]/cosh((*HBHERecHitEta)[i]);
            FlaggedEt->Fill(et);
            sum_energy += (*HBHERecHitEnergy)[i];
            sum_et += (*HBHERecHitEnergy)[i]/cosh((*HBHERecHitEta)[i]);
            // Calculate the flagged MET 
            sumFlaggedMETx += (*HBHERecHitEnergy)[i]/cosh((*HBHERecHitEta)[i]) * cos((*HBHERecHitPhi)[i]);
            sumFlaggedMETy += (*HBHERecHitEnergy)[i]/cosh((*HBHERecHitEta)[i]) * sin((*HBHERecHitPhi)[i]);
            //TString msg = TString::Format("HBHERecHitEnergy[%d] = %f", i, (*HBHERecHitEnergy)[i]);
            //if (gProofServ) gProofServ->SendAsynMessage(msg);
            vector<double> FC = (*HBHERecHitAuxFC)[i];
            R45_NEFFlagged->Fill((FC[4]-FC[5])/(FC[4]+FC[5]));
            R45_NEFFlaggedSum45->Fill((FC[4]+FC[5]),(FC[4]-FC[5])/(FC[4]+FC[5]));
            TS03Flagged->Fill((FC[0]+FC[1]+FC[2]+FC[3])/4);
            for (unsigned int j = 0; j < FC.size(); ++j)
            {
                ChargeTS->AddBinContent(j+1,FC[j]);
                //cout << FC[j] << "\t";
            }
            if (FlagWordDecoder(flagword,13)) FlagCorrelate->Fill(1.,1.);
            else 
            {
                    FlagCorrelate->Fill(1.,0.);
                    for (unsigned int j = 0; j < FC.size(); ++j)
                    {
            //         cout << FC[j] << "\t";
                    }
            //cout << endl;
            }
        }
        else 
        {
            vector<double> FC = (*HBHERecHitAuxFC)[i];
            R45_NEFNonFlagged->Fill((FC[4]-FC[5])/(FC[4]+FC[5]));
            if (abs((*HBHERecHitIEta)[i]) != 28 && abs((*HBHERecHitIEta)[i]) != 29) R45_NEFNonFlaggedSum45->Fill((FC[4]+FC[5]),(FC[4]-FC[5])/(FC[4]+FC[5]));
            TS03NonFlagged->Fill((FC[0]+FC[1]+FC[2]+FC[3])/4);
            for (unsigned int j = 0; j < FC.size(); ++j)
            {
            //    cout << FC[j] << "\t";
            }
            if (FlagWordDecoder(flagword,13)) 
            {
                    FlagCorrelate->Fill(0.,1.);
                    for (unsigned int j = 0; j < FC.size(); ++j)
                    {
    //                 cout << FC[j] << "\t";
                    }
            //cout << endl;
            }
        }
        if (FlagWordDecoder(flagword,13)) ++NumberOfSpikeFlags;     
   }
   
  
   TVector3 METvector(HBET->at(0)+HEET->at(0), HBET->at(1)+HEET->at(1),0);
   METx->Fill(METvector.x());
   METy->Fill(METvector.y());
   
   Double_t noncleanMET = sqrt(pow(METvector.x(),2)+pow(METvector.y(),2));
   NonCleanMET->Fill(noncleanMET);
   CleanMETx->Fill(METvector.x()-sumFlaggedMETx);
   CleanMETy->Fill(METvector.y()-sumFlaggedMETy);
   Double_t cleanMET = sqrt(pow(METvector.x()-sumFlaggedMETx,2)+pow(METvector.y()-sumFlaggedMETy,2));
   CleanMET->Fill(cleanMET);
   METCorrelate->Fill(noncleanMET,cleanMET);
           
   FlaggedCount->Fill(flag_count);

//   FlaggedCount_Extracted->Fill((*NumNegativeNoiseChannels)[0]);
   if (flag_count != 0) 
    {
           Energy_Count->Fill(sum_energy, flag_count);
           FlaggedSumEnergy->Fill(sum_energy);
           //cout << "NegativeNoiseSumE->size() " << NegativeNoiseSumE->size() << endl;
           //FlaggedSumEnergy_Extracted->Fill((*NegativeNoiseSumE)[0]);
  //         FlaggedSumEnergy_Extracted->Fill(NegativeNoiseSumE->at(0));
           FlaggedSumEt->Fill(sum_et);
    //       FlaggedSumEt_Extracted->Fill((*NegativeNoiseSumEt)[0]);
    }
  }
 
    // Calculate mistag rate
   for (unsigned int i = 0; i < HBHERecHitFlags->size(); i++)
   {
        if (HBHERecHitEnergy->at(i) >= 0 && HBHERecHitEnergy->at(i) < 10) 
        {
            totalRange[0]++;
            if (FlagWordDecoder(HBHERecHitFlags->at(i),27))
            mistag[0]++;
        }
        if (HBHERecHitEnergy->at(i) >= 10 && HBHERecHitEnergy->at(i) < 20) 
        {
            totalRange[1]++;
            if (FlagWordDecoder(HBHERecHitFlags->at(i),27))
            mistag[1]++;
        }
        if (HBHERecHitEnergy->at(i) >= 20 && HBHERecHitEnergy->at(i) < 30) 
        {
            totalRange[2]++;
            if (FlagWordDecoder(HBHERecHitFlags->at(i),27))
            mistag[2]++;
        }
        if (HBHERecHitEnergy->at(i) >= 30 && HBHERecHitEnergy->at(i) < 40) 
        {
            totalRange[3]++;
            if (FlagWordDecoder(HBHERecHitFlags->at(i),27))
            mistag[3]++;
        }
        if (HBHERecHitEnergy->at(i) >= 40 && HBHERecHitEnergy->at(i) < 50) 
        {
            totalRange[4]++;
            if (FlagWordDecoder(HBHERecHitFlags->at(i),27))
            mistag[4]++;
        }
        if (HBHERecHitEnergy->at(i) >= 50 && HBHERecHitEnergy->at(i) < 60) 
        {
            totalRange[5]++;
            if (FlagWordDecoder(HBHERecHitFlags->at(i),27))
            mistag[5]++;
        }
        if (HBHERecHitEnergy->at(i) >= 60 && HBHERecHitEnergy->at(i) < 70) 
        {
            totalRange[6]++;
            if (FlagWordDecoder(HBHERecHitFlags->at(i),27))
            mistag[6]++;
        }
        if (HBHERecHitEnergy->at(i) >= 70 && HBHERecHitEnergy->at(i) < 80) 
        {
            totalRange[7]++;
            if (FlagWordDecoder(HBHERecHitFlags->at(i),27))
            mistag[7]++;
        }
        if (HBHERecHitEnergy->at(i) >= 80 && HBHERecHitEnergy->at(i) < 90) 
        {
            totalRange[8]++;
            if (FlagWordDecoder(HBHERecHitFlags->at(i),27))
            mistag[8]++;
        }
        if (HBHERecHitEnergy->at(i) >= 90 && HBHERecHitEnergy->at(i) < 100) 
        {
            totalRange[9]++;
            if (FlagWordDecoder(HBHERecHitFlags->at(i),27))
            mistag[9]++;
        }
        if (HBHERecHitEnergy->at(i) >= 100 && HBHERecHitEnergy->at(i) < 110) 
        {
            totalRange[10]++;
            if (FlagWordDecoder(HBHERecHitFlags->at(i),27))
            mistag[10]++;
        }
        if (HBHERecHitEnergy->at(i) >= 110 && HBHERecHitEnergy->at(i) < 120) 
        {
            totalRange[11]++;
            if (FlagWordDecoder(HBHERecHitFlags->at(i),27))
            mistag[11]++;
        }
        if (HBHERecHitEnergy->at(i) >= 120 && HBHERecHitEnergy->at(i) < 130) 
        {
            totalRange[12]++;
            if (FlagWordDecoder(HBHERecHitFlags->at(i),27))
            mistag[12]++;
        }
        if (HBHERecHitEnergy->at(i) >= 130 && HBHERecHitEnergy->at(i) < 140) 
        {
            totalRange[13]++;
            if (FlagWordDecoder(HBHERecHitFlags->at(i),27))
            mistag[13]++;
        }
        if (HBHERecHitEnergy->at(i) >= 140 && HBHERecHitEnergy->at(i) < 150) 
        {
            totalRange[14]++;
            if (FlagWordDecoder(HBHERecHitFlags->at(i),27))
            mistag[14]++;
        }
        if (HBHERecHitEnergy->at(i) >= 150 && HBHERecHitEnergy->at(i) < 160) 
        {
            totalRange[15]++;
            if (FlagWordDecoder(HBHERecHitFlags->at(i),27))
            mistag[15]++;
        }
        if (HBHERecHitEnergy->at(i) >= 160 && HBHERecHitEnergy->at(i) < 170) 
        {
            totalRange[16]++;
            if (FlagWordDecoder(HBHERecHitFlags->at(i),27))
            mistag[16]++;
        }
        if (HBHERecHitEnergy->at(i) >= 170 && HBHERecHitEnergy->at(i) < 180) 
        {
            totalRange[17]++;
            if (FlagWordDecoder(HBHERecHitFlags->at(i),27))
            mistag[17]++;
        }
        if (HBHERecHitEnergy->at(i) >= 180 && HBHERecHitEnergy->at(i) < 190) 
        {
            totalRange[18]++;
            if (FlagWordDecoder(HBHERecHitFlags->at(i),27))
            mistag[18]++;
        }
        if (HBHERecHitEnergy->at(i) >= 190 && HBHERecHitEnergy->at(i) < 200) 
        {
            totalRange[19]++;
            if (FlagWordDecoder(HBHERecHitFlags->at(i),27))
            mistag[19]++;
        }
    }
   return kTRUE;
}

void MET::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void MET::Terminate()
{
        cout << "Terminating...\n";
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

   TFile *fo = new TFile("SingleMuon_mistagRate.root","recreate");
   
   TH2F * FlagCorrelate = (TH2F*)fOutput->FindObject("FlagCorrelate");
   FlagCorrelate->Write();
   
   TH1F * TS03Flagged = (TH1F*)fOutput->FindObject("TS03Flagged");
   TS03Flagged->Write();
   
   TH1F * TS03NonFlagged = (TH1F*)fOutput->FindObject("TS03NonFlagged");
   TS03NonFlagged->Write();
   
   TH1F * R45_NEFFlagged = (TH1F*)fOutput->FindObject("R45_NEFFlagged");
   R45_NEFFlagged->Write();
   
   TH1F * R45_NEFNonFlagged = (TH1F*)fOutput->FindObject("R45_NEFNonFlagged");
   R45_NEFNonFlagged->Write();
   
   TH2F * R45_NEFFlaggedSum45 = (TH2F*)fOutput->FindObject("R45_NEFFlaggedSum45");
   R45_NEFFlaggedSum45->Write();
   
   TH2F * R45_NEFNonFlaggedSum45 = (TH2F*)fOutput->FindObject("R45_NEFNonFlaggedSum45");
   R45_NEFNonFlaggedSum45->Write();
   
   TH1F * METx = (TH1F*)fOutput->FindObject("METx");
   METx->Write();
   TH1F * METy = (TH1F*)fOutput->FindObject("METy");
   METy->Write();
   TH1F * METCorrelate = (TH1F*)fOutput->FindObject("METCorrelate");
   METCorrelate->Write();
   TH1F * CleanMET = (TH1F*)fOutput->FindObject("CleanMET");
   CleanMET->Write();
   TH1F * NonCleanMET = (TH1F*)fOutput->FindObject("NonCleanMET");
   NonCleanMET->Write();
   TH1F * CleanMETx = (TH1F*)fOutput->FindObject("CleanMETx");
   CleanMETx->Write();
   TH1F * CleanMETy = (TH1F*)fOutput->FindObject("CleanMETy");
   CleanMETy->Write();
   TH1F * FlaggedEt = (TH1F*)fOutput->FindObject("FlaggedEt");
   FlaggedEt->Write();
   TH1F * FlaggedEnergy = (TH1F*)fOutput->FindObject("FlaggedEnergy");
   FlaggedEnergy->Write();
   TH1F * FlaggedSumEnergy = (TH1F*)fOutput->FindObject("FlaggedSumEnergy");
   FlaggedSumEnergy->Write();
   TH1F * FlaggedSumEt = (TH1F*)fOutput->FindObject("FlaggedSumEt");
   FlaggedSumEt->Write();
#if 0
   TH1F * FlaggedSumEnergy_Extracted = (TH1F*)fOutput->FindObject("FlaggedSumEnergy_Extracted");
   FlaggedSumEnergy_Extracted->Write();
   TH1F * FlaggedSumEt_Extracted = (TH1F*)fOutput->FindObject("FlaggedSumEt_Extracted");
   FlaggedSumEt_Extracted->Write();
   TH1F * FlaggedCount_Extracted = (TH1F*)fOutput->FindObject("FlaggedCount_Extracted");
   FlaggedCount_Extracted->Write();
#endif
   TH1I * FlaggedCount = (TH1I*)fOutput->FindObject("FlaggedCount");
   FlaggedCount->Write();
   TH2F * Energy_Count = (TH2F*)fOutput->FindObject("Energy_Count");
   Energy_Count->Write();
   TH1I * ChargeTS = (TH1I*)fOutput->FindObject("ChargeTS");
   ChargeTS->Write();
   
   
   Double_t energyRangeError[20];
   
   // Calculate the mistag rate
   for (int i = 0; i < 20; i++)
   {
       if (mistag[i] !=0) mistag[i] = mistag[i]/totalRange[i];
       cout << mistag[i] << "\t";
       energyRangeError[i] = 5.;
   }
   cout << endl;
   Double_t energyRange[20] = {5,15,25,35,45,55,65,75,85,95,155,115,125,135,145,155,165,175,185,195};
   
   Double_t mistagError[20] = {0.};
   //Double_t testgraph[20] = {1,2.,3.,4,5,6,7,8,9,10,11,12,13,14,15,16,17,3,5,7};
   TGraphErrors * mistagRate = new TGraphErrors(20,energyRange,mistag,energyRangeError,mistagError);
   mistagRate->SetName("mistagRate");
   mistagRate->Write();
   fo->Close();
 //  cout << "NEF = " << NumberOfNEFFlags << "\tSpike = " << NumberOfSpikeFlags << "\t Ratio = "<< (double) NumberOfNEFFlags/NumberOfSpikeFlags << endl;
}
