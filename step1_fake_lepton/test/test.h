//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Nov 14 12:15:48 2020 by ROOT version 6.12/07
// from TTree tree2/tree2
// found on file: treePKU_754.root
//////////////////////////////////////////////////////////

#ifndef test_h
#define test_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class test {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        theWeight;
   Double_t        hasphoton;
   Int_t           jet1hf_orig;
   Int_t           jet1pf_orig;
   Int_t           jet2hf_orig;
   Int_t           jet2pf_orig;
   Double_t        jet1pt_orig;
   Double_t        jet1phi_orig;
   Double_t        jet1eta_orig;
   Double_t        jet1e_orig;
   Double_t        jet1csv_orig;
   Double_t        jet1deepcsv_probb_orig;
   Double_t        jet1deepcsv_probbb_orig;
   Double_t        jet1deepcsv_probc_orig;
   Double_t        jet1deepcsv_probcc_orig;
   Double_t        jet1icsv_orig;
   Double_t        drj1a_orig;
   Double_t        drj1l_orig;
   Double_t        jet2pt_orig;
   Double_t        jet2phi_orig;
   Double_t        jet2eta_orig;
   Double_t        jet2e_orig;
   Double_t        jet2csv_orig;
   Double_t        jet2deepcsv_probb_orig;
   Double_t        jet2deepcsv_probbb_orig;
   Double_t        jet2deepcsv_probc_orig;
   Double_t        jet2deepcsv_probcc_orig;
   Double_t        mtVlepJECnew_new;
   Double_t        jet2icsv_orig;
   Double_t        drj2a_orig;
   Double_t        drj2l_orig;
   Float_t         rawPt;
   Int_t           nevent;
   Int_t           run;
   Int_t           ls;
   Double_t        ptlep1;
   Double_t        etalep1;
   Double_t        philep1;
   Double_t        energylep1;
   Double_t        MET_et_new;
   Int_t           HLT_Ele1;
   Int_t           HLT_Ele2;
   Int_t           HLT_Mu1;
   Int_t           HLT_Mu2;
   Int_t           HLT_Mu3;

   // List of branches
   TBranch        *b_theWeight;   //!
   TBranch        *b_hasphoton;   //!
   TBranch        *b_jet1hf_orig;   //!
   TBranch        *b_jet1pf_orig;   //!
   TBranch        *b_jet2hf_orig;   //!
   TBranch        *b_jet2pf_orig;   //!
   TBranch        *b_jet1pt_orig;   //!
   TBranch        *b_jet1phi_orig;   //!
   TBranch        *b_jet1eta_orig;   //!
   TBranch        *b_jet1e_orig;   //!
   TBranch        *b_jet1csv_orig;   //!
   TBranch        *b_jet1deepcsv_probb_orig;   //!
   TBranch        *b_jet1deepcsv_probbb_orig;   //!
   TBranch        *b_jet1deepcsv_probc_orig;   //!
   TBranch        *b_jet1deepcsv_probcc_orig;   //!
   TBranch        *b_jet1icsv_orig;   //!
   TBranch        *b_drj1a_orig;   //!
   TBranch        *b_drj1l_orig;   //!
   TBranch        *b_jet2pt_orig;   //!
   TBranch        *b_jet2phi_orig;   //!
   TBranch        *b_jet2eta_orig;   //!
   TBranch        *b_jet2e_orig;   //!
   TBranch        *b_jet2csv_orig;   //!
   TBranch        *b_jet2deepcsv_probb_orig;   //!
   TBranch        *b_jet2deepcsv_probbb_orig;   //!
   TBranch        *b_jet2deepcsv_probc_orig;   //!
   TBranch        *b_jet2deepcsv_probcc_orig;   //!
   TBranch        *b_mtVlepJECnew_new;   //!
   TBranch        *b_jet2icsv_orig;   //!
   TBranch        *b_drj2a_orig;   //!
   TBranch        *b_drj2l_orig;   //!
   TBranch        *b_rawPt;   //!
   TBranch        *b_nevent;   //!
   TBranch        *b_run;   //!
   TBranch        *b_ls;   //!
   TBranch        *b_ptlep1;   //!
   TBranch        *b_etalep1;   //!
   TBranch        *b_philep1;   //!
   TBranch        *b_energylep1;   //!
   TBranch        *b_MET_et_new;   //!
   TBranch        *b_HLT_Ele1;   //!
   TBranch        *b_HLT_Ele2;   //!
   TBranch        *b_HLT_Mu1;   //!
   TBranch        *b_HLT_Mu2;   //!
   TBranch        *b_HLT_Mu3;   //!

   test(TTree *tree=0);
   virtual ~test();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef test_cxx
test::test(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("treePKU_754.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("treePKU_754.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("treePKU_754.root:/treeDumper");
      dir->GetObject("tree2",tree);

   }
   Init(tree);
}

test::~test()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t test::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t test::LoadTree(Long64_t entry)
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

void test::Init(TTree *tree)
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

   fChain->SetBranchAddress("theWeight", &theWeight, &b_theWeight);
   fChain->SetBranchAddress("hasphoton", &hasphoton, &b_hasphoton);
   fChain->SetBranchAddress("jet1hf_orig", &jet1hf_orig, &b_jet1hf_orig);
   fChain->SetBranchAddress("jet1pf_orig", &jet1pf_orig, &b_jet1pf_orig);
   fChain->SetBranchAddress("jet2hf_orig", &jet2hf_orig, &b_jet2hf_orig);
   fChain->SetBranchAddress("jet2pf_orig", &jet2pf_orig, &b_jet2pf_orig);
   fChain->SetBranchAddress("jet1pt_orig", &jet1pt_orig, &b_jet1pt_orig);
   fChain->SetBranchAddress("jet1phi_orig", &jet1phi_orig, &b_jet1phi_orig);
   fChain->SetBranchAddress("jet1eta_orig", &jet1eta_orig, &b_jet1eta_orig);
   fChain->SetBranchAddress("jet1e_orig", &jet1e_orig, &b_jet1e_orig);
   fChain->SetBranchAddress("jet1csv_orig", &jet1csv_orig, &b_jet1csv_orig);
   fChain->SetBranchAddress("jet1deepcsv_probb_orig", &jet1deepcsv_probb_orig, &b_jet1deepcsv_probb_orig);
   fChain->SetBranchAddress("jet1deepcsv_probbb_orig", &jet1deepcsv_probbb_orig, &b_jet1deepcsv_probbb_orig);
   fChain->SetBranchAddress("jet1deepcsv_probc_orig", &jet1deepcsv_probc_orig, &b_jet1deepcsv_probc_orig);
   fChain->SetBranchAddress("jet1deepcsv_probcc_orig", &jet1deepcsv_probcc_orig, &b_jet1deepcsv_probcc_orig);
   fChain->SetBranchAddress("jet1icsv_orig", &jet1icsv_orig, &b_jet1icsv_orig);
   fChain->SetBranchAddress("drj1a_orig", &drj1a_orig, &b_drj1a_orig);
   fChain->SetBranchAddress("drj1l_orig", &drj1l_orig, &b_drj1l_orig);
   fChain->SetBranchAddress("jet2pt_orig", &jet2pt_orig, &b_jet2pt_orig);
   fChain->SetBranchAddress("jet2phi_orig", &jet2phi_orig, &b_jet2phi_orig);
   fChain->SetBranchAddress("jet2eta_orig", &jet2eta_orig, &b_jet2eta_orig);
   fChain->SetBranchAddress("jet2e_orig", &jet2e_orig, &b_jet2e_orig);
   fChain->SetBranchAddress("jet2csv_orig", &jet2csv_orig, &b_jet2csv_orig);
   fChain->SetBranchAddress("jet2deepcsv_probb_orig", &jet2deepcsv_probb_orig, &b_jet2deepcsv_probb_orig);
   fChain->SetBranchAddress("jet2deepcsv_probbb_orig", &jet2deepcsv_probbb_orig, &b_jet2deepcsv_probbb_orig);
   fChain->SetBranchAddress("jet2deepcsv_probc_orig", &jet2deepcsv_probc_orig, &b_jet2deepcsv_probc_orig);
   fChain->SetBranchAddress("jet2deepcsv_probcc_orig", &jet2deepcsv_probcc_orig, &b_jet2deepcsv_probcc_orig);
   fChain->SetBranchAddress("mtVlepJECnew_new", &mtVlepJECnew_new, &b_mtVlepJECnew_new);
   fChain->SetBranchAddress("jet2icsv_orig", &jet2icsv_orig, &b_jet2icsv_orig);
   fChain->SetBranchAddress("drj2a_orig", &drj2a_orig, &b_drj2a_orig);
   fChain->SetBranchAddress("drj2l_orig", &drj2l_orig, &b_drj2l_orig);
   fChain->SetBranchAddress("rawPt", &rawPt, &b_rawPt);
   fChain->SetBranchAddress("nevent", &nevent, &b_nevent);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("ls", &ls, &b_ls);
   fChain->SetBranchAddress("ptlep1", &ptlep1, &b_ptlep1);
   fChain->SetBranchAddress("etalep1", &etalep1, &b_etalep1);
   fChain->SetBranchAddress("philep1", &philep1, &b_philep1);
   fChain->SetBranchAddress("energylep1", &energylep1, &b_energylep1);
   fChain->SetBranchAddress("MET_et_new", &MET_et_new, &b_MET_et_new);
   fChain->SetBranchAddress("HLT_Ele1", &HLT_Ele1, &b_HLT_Ele1);
   fChain->SetBranchAddress("HLT_Ele2", &HLT_Ele2, &b_HLT_Ele2);
   fChain->SetBranchAddress("HLT_Mu1", &HLT_Mu1, &b_HLT_Mu1);
   fChain->SetBranchAddress("HLT_Mu2", &HLT_Mu2, &b_HLT_Mu2);
   fChain->SetBranchAddress("HLT_Mu3", &HLT_Mu3, &b_HLT_Mu3);
   Notify();
}

Bool_t test::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void test::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t test::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef test_cxx
