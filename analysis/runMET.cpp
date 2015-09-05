void AddToChain(TChain *ch, char* inputList)
{
        ifstream fileNames;
        fileNames.open(inputList, std::ios::in);
        if (!fileNames.is_open())
                std::cout << "Error opening the input file. " << endl;
        while (!fileNames.eof())
        {
            char cs[1000];
            fileNames.getline(cs,1000);
            TString fullPath;
            fullPath = "root://eoscms//";
            fullPath+=cs;
            ch->Add(fullPath);
        }
}
void runMET()
{
    gROOT->Reset();
    gSystem->Load("libPhysics.so");

    //TProof::Open("qnguyen@lxplus0039.cern.ch:21002");
    //TProof::Open("lite://");

    TChain *c = new TChain("hcalTupleTree/tree","");
    AddToChain(c, "inputMET.txt");
    //AddToChain(c, "inputSingleMuon.txt");
    //AddToChain(c, "inputHPD.txt");
    //c->SetProof();
    c->Process("MET.C+g");
    //
}
