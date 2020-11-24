#define test_cxx
#include "test.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include "ele_channel_scale.C"
#include "muon_channel_scale.C"
double Pi =3.1415926;
   Bool_t LEPmu,LEPele,genmuon[6],genele[6],genjet[6],genphoton[6];
   Bool_t photon,jet,dr,SignalRegion;
   Bool_t GenLEPmu,GenLEPele,GenPhoton,GenJet,GenDr,GenSignalRegion;
   Bool_t Reco,Gen, GenDrmu,GenDrele,Genmu,Genele;

int n=0, n1=0,n2=0, s1=0, s2=0, s3=0, s4=0, s5=0, s6=0, s7=0, s8=0, s9=0, s10=0, s11=0;
   double genyVlep;
   double genphiVlep;
   double genptVlep;
   double genmassVlep;
   double genWGmass;
   double genmuon1pt,genmuon1phi,genmuon1eta;
   double genele1pt,genele1phi,genele1eta;
   double genlep1pt,genlep1eta,genlep1phi,gendrjj,drjj;
   int    genlep;
   double genjet1pt,genjet2pt,genjet1eta,genjet2eta,genjet1phi,genjet2phi;
   double genjet1e,genjet2e;
   double genphotonet,genphotoneta,genphotonphi;
   double gendrj1m1,gendrj1m2,gendrj2m1,gendrj2m2;
   double gendrj1e1,gendrj2e1;
   double gendrj1a,gendrj2a,gendrj1l,gendrj2l;
   double gendrma1,gendrma2;
   double gendrea1,gendrea2;
   double genMjj,gendetajj,genzepp;
   double gendrla1;
   double gendelta_phi,genZGmass;
   double genMla,gen_Dphiwajj;
   vector<double> vector_photon,vector_jet,vector_muon,vector_ele;
   vector<double>::iterator biggest_photon,biggest_jet1,biggest_jet2,biggest_muon1,biggest_ele1;

void test::ResetValue(){
    genMla=-10;gen_Dphiwajj=-10;genWGmass=-10;
	genlep1pt=-10;genlep1eta=-10;genlep1phi=-10;
	genjet1pt=-10;genjet2pt=-10;genjet1eta=-10;genjet2eta=-10;genjet1phi=-10;genjet2phi=-10;
	genjet1e=-10;genjet2e=-10;
	genphotonet=-10;genphotoneta=-10;genphotonphi=-10;
	gendrj1a=-10;gendrj2a=-10;gendrj1l=-10;gendrj2l=-10;
    gendrla1=-10;
	genMjj=-10;gendetajj=-10;genzepp=-10;gendelta_phi=-10;genZGmass=-10;
    genmassVlep=-10;genyVlep=-10;genphiVlep=-10;genptVlep=-10;
    genlep=-10;gendrjj=-10;drjj=-10;
	genmuon1pt=-10;genmuon1eta=-10;genmuon1phi=-10;
	genele1pt=-10;genele1eta=-10;genele1phi=-10;
    GenDrmu=false;GenDrele=false;Genmu=false;Genele=false;
	for(int i=0;i<6;i++){
		genmuon[i]=false;
		genele[i]=false;
        genphoton[i]=false;
		genjet[i]=false;
	}
}


double ptlepBins[5]={20,100,400};
double photonEtBins[5]={20,100,400};
double jetptBins[5]={30,550,800};
double MvaBins[3]={100,150,1000};
double Mjj_Signal_Bins[4]={500,1000,2000};
double Mjj_Control_Bins[4]={500,1000,2000};

Double_t mjj_bins[4]={500, 800, 1200, 2000};
Double_t detajj_bins[4]={2.5, 4.5, 6.5};

TH1D * hist_ptlep = new TH1D("hist_ptlep","hist_ptlep", 2, ptlepBins);
TH1D * hist_photonEt = new TH1D("hist_photonEt","hist_photonEt", 2, photonEtBins);
TH1D * hist_jet1pt = new TH1D("hist_jet1pt","hist_jet1pt", 2, jetptBins);
TH1D * hist_Mva = new TH1D("hist_Mva","hist_Mva", 2, MvaBins);
TH2D * hist2D_Mjj_detajj = new TH2D("hist2D_Mjj_detajj","hist2D_Mjj_detajj", 3, mjj_bins, 2, detajj_bins);

TH1D * hist_Mjj_Signal = new TH1D("hist_Mjj_Signal","hist_Mjj_Signal", 2, Mjj_Signal_Bins);
TH1D * hist_Mjj_Control = new TH1D("hist_Mjj_Control","hist_Mjj_Control", 2, Mjj_Control_Bins);


TH1D * hist_gen_ptlep = new TH1D("hist_gen_ptlep","hist_gen_ptlep", 2, ptlepBins);
TH1D * hist_gen_photonEt = new TH1D("hist_gen_photonEt","hist_gen_photonEt", 2, photonEtBins);
TH1D * hist_gen_jet1pt = new TH1D("hist_gen_jet1pt","hist_gen_jet1pt", 2, jetptBins);
TH1D * hist_gen_Mva = new TH1D("hist_gen_Mva","hist_gen_Mva", 2, MvaBins);
TH2D * hist2D_gen_Mjj_detajj = new TH2D("hist2D_gen_Mjj_detajj","hist2D_gen_Mjj_detajj", 3, mjj_bins, 2, detajj_bins);

TH1D * hist_gen_Mjj_Signal = new TH1D("hist_gen_Mjj_Signal","hist_gen_Mjj_Signal", 2, Mjj_Signal_Bins);
TH1D * hist_gen_Mjj_Control = new TH1D("hist_gen_Mjj_Control","hist_gen_Mjj_Control", 2, Mjj_Control_Bins);

TH1D * hist_outgen_ptlep = new TH1D("hist_outgen_ptlep","hist_outgen_ptlep", 2, ptlepBins);
TH1D * hist_outgen_photonEt = new TH1D("hist_outgen_photonEt","hist_outgen_photonEt", 2, photonEtBins);
TH1D * hist_outgen_jet1pt = new TH1D("hist_outgen_jet1pt","hist_outgen_jet1pt", 2, jetptBins);
TH1D * hist_outgen_Mva = new TH1D("hist_outgen_Mva","hist_outgen_Mva", 2, MvaBins);
TH2D * hist2D_outgen_Mjj_detajj = new TH2D("hist2D_outgen_Mjj_detajj","hist2D_outgen_Mjj_detajj", 3, mjj_bins, 2, detajj_bins);

TH1D * hist_outgen_Mjj_Signal = new TH1D("hist_outgen_Mjj_Signal","hist_outgen_Mjj_Signal", 2, Mjj_Signal_Bins);
TH1D * hist_outgen_Mjj_Control = new TH1D("hist_outgen_Mjj_Control","hist_outgen_Mjj_Control", 2, Mjj_Control_Bins);


void test::endJob() {
   fout = new TFile(m_dataset, "RECREATE");
   fout->cd();
   hist_ptlep->Write();
   hist_photonEt->Write();
   hist_jet1pt->Write();
   hist_Mva->Write();
   hist_Mjj_Signal->Write();
   hist_Mjj_Control->Write();
   hist2D_Mjj_detajj->Write();
   hist2D_gen_Mjj_detajj->Write();
   hist2D_outgen_Mjj_detajj->Write();

   hist_gen_ptlep->Write();
   hist_gen_photonEt->Write();
   hist_gen_jet1pt->Write();
   hist_gen_Mva->Write();
   hist_gen_Mjj_Signal->Write();
   hist_gen_Mjj_Control->Write();

   hist_outgen_ptlep->Write();
   hist_outgen_photonEt->Write();
   hist_outgen_jet1pt->Write();
   hist_outgen_Mva->Write();
   hist_outgen_Mjj_Signal->Write();
   hist_outgen_Mjj_Control->Write();

   fout->Close();
   delete fout;
}

void test::hist_Sumw2()
{
   hist_ptlep->Sumw2();
   hist_photonEt->Sumw2();
   hist_jet1pt->Sumw2();
   hist_Mva->Sumw2();
   hist_Mjj_Signal->Sumw2();
   hist_Mjj_Control->Sumw2();

   hist_gen_ptlep->Sumw2();
   hist_gen_photonEt->Sumw2();
   hist_gen_jet1pt->Sumw2();
   hist_gen_Mva->Sumw2();
   hist_gen_Mjj_Signal->Sumw2();
   hist_gen_Mjj_Control->Sumw2();

   hist_outgen_ptlep->Sumw2();
   hist_outgen_photonEt->Sumw2();
   hist_outgen_jet1pt->Sumw2();
   hist_outgen_Mva->Sumw2();
   hist_outgen_Mjj_Signal->Sumw2();
   hist_outgen_Mjj_Control->Sumw2();

   hist2D_Mjj_detajj->Sumw2();
   hist2D_gen_Mjj_detajj->Sumw2();
   hist2D_outgen_Mjj_detajj->Sumw2();

}

void test::hist_Scale()
{
   if(m_type == "mc"){
      hist_ptlep->Scale(1/(p_event - n_event));
      hist_photonEt->Scale(1/(p_event - n_event));
      hist_jet1pt->Scale(1/(p_event - n_event));
      hist_Mva->Scale(1/(p_event - n_event));
      hist_Mjj_Signal->Scale(1/(p_event - n_event));
      hist_Mjj_Control->Scale(1/(p_event - n_event));

      hist_gen_ptlep->Scale(1/(p_event - n_event));
      hist_gen_photonEt->Scale(1/(p_event - n_event));
      hist_gen_jet1pt->Scale(1/(p_event - n_event));
      hist_gen_Mva->Scale(1/(p_event - n_event));
      hist_gen_Mjj_Signal->Scale(1/(p_event - n_event));
      hist_gen_Mjj_Control->Scale(1/(p_event - n_event));

      hist_outgen_ptlep->Scale(1/(p_event - n_event));
      hist_outgen_photonEt->Scale(1/(p_event - n_event));
      hist_outgen_jet1pt->Scale(1/(p_event - n_event));
      hist_outgen_Mva->Scale(1/(p_event - n_event));
      hist_outgen_Mjj_Signal->Scale(1/(p_event - n_event));
      hist_outgen_Mjj_Control->Scale(1/(p_event - n_event));

      hist2D_Mjj_detajj->Scale(1/(p_event - n_event));
      hist2D_gen_Mjj_detajj->Scale(1/(p_event - n_event));
      hist2D_outgen_Mjj_detajj->Scale(1/(p_event - n_event));
   }
  
}

Double_t test::delta_R(Double_t eta1, Double_t phi1, Double_t eta2, Double_t phi2)
{
        Double_t dp = phi1-phi2;
        if(fabs(dp) > Pi) dp = 2*Pi - fabs(dp);
        Double_t dr = sqrt((eta1-eta2)*(eta1-eta2)+dp*dp);
        return dr;
}

void test::Loop(TDirectory * dir)
{
   set_cut_value(m_year);
   double btag_cut_value;
   if(m_btag_workpoint == "tight") btag_cut_value = cut_value[0];
   if(m_btag_workpoint == "medium") btag_cut_value = cut_value[1];
   if(m_btag_workpoint == "loose") btag_cut_value = cut_value[2];


   cout<<"LUMI : "<<lumi<<endl<<"btag value cut :  "<<cut_value[1]<<endl;

   Long64_t nbytes = 0, nb = 0;
   set_cut_value(m_year);
   //cout<<cut_value[0]<<" "<<cut_value[1]<<" "<<cut_value[2]<<endl;
   int jentry = 0;

   TTreeReader fReader ;
   fReader.SetTree("PKUCandidates", dir);
   TTreeReaderValue<Double_t>    hasphoton  = {fReader, "hasphoton"};
   TTreeReaderValue<Int_t>    ngoodmus  = {fReader, "ngoodmus"};
   TTreeReaderValue<Int_t>    ngoodeles  = {fReader, "ngoodeles"};
   TTreeReaderValue<Int_t>    jet1hf_orig  = {fReader, "jet1hf_orig"};
   TTreeReaderValue<Int_t>    jet1pf_orig  = {fReader, "jet1pf_orig"};
   TTreeReaderValue<Int_t>    jet2hf_orig  = {fReader, "jet2hf_orig"};
   TTreeReaderValue<Int_t>    jet2pf_orig  = {fReader, "jet2pf_orig"};
   TTreeReaderValue<Double_t>    jet1pt_orig  = {fReader, "jet1pt_orig"};
   TTreeReaderValue<Double_t>    jet1phi_orig  = {fReader, "jet1phi_orig"};
   TTreeReaderValue<Double_t>    jet1eta_orig  = {fReader, "jet1eta_orig"};
   TTreeReaderValue<Double_t>    jet1e_orig  = {fReader, "jet1e_orig"};
   TTreeReaderValue<Double_t>    jet1csv_orig  = {fReader, "jet1csv_orig"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_orig  = {fReader, "jet1deepcsv_probb_orig"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_orig  = {fReader, "jet1deepcsv_probbb_orig"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_orig  = {fReader, "jet1deepcsv_probc_orig"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_orig  = {fReader, "jet1deepcsv_probcc_orig"};
   TTreeReaderValue<Double_t>    jet1icsv_orig  = {fReader, "jet1icsv_orig"};
   TTreeReaderValue<Double_t>    drj1a_orig  = {fReader, "drj1a_orig"};
   TTreeReaderValue<Double_t>    drj1l_orig  = {fReader, "drj1l_orig"};
   TTreeReaderValue<Double_t>    jet2pt_orig  = {fReader, "jet2pt_orig"};
   TTreeReaderValue<Double_t>    jet2phi_orig  = {fReader, "jet2phi_orig"};
   TTreeReaderValue<Double_t>    jet2eta_orig  = {fReader, "jet2eta_orig"};
   TTreeReaderValue<Double_t>    jet2e_orig  = {fReader, "jet2e_orig"};
   TTreeReaderValue<Double_t>    jet2csv_orig  = {fReader, "jet2csv_orig"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_orig  = {fReader, "jet2deepcsv_probb_orig"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_orig  = {fReader, "jet2deepcsv_probbb_orig"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_orig  = {fReader, "jet2deepcsv_probc_orig"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_orig  = {fReader, "jet2deepcsv_probcc_orig"};
   TTreeReaderValue<Double_t>    jet2icsv_orig  = {fReader, "jet2icsv_orig"};
   TTreeReaderValue<Double_t>    drj2a_orig  = {fReader, "drj2a_orig"};
   TTreeReaderValue<Double_t>    drj2l_orig  = {fReader, "drj2l_orig"};
   TTreeReaderValue<Float_t>    rawPt  = {fReader, "rawPt"};
   TTreeReaderValue<Int_t>    nevent  = {fReader, "nevent"};
   TTreeReaderValue<Int_t>    run  = {fReader, "run"};
   TTreeReaderValue<Int_t>    ls  = {fReader, "ls"};
   TTreeReaderValue<Int_t>    nVtx  = {fReader, "nVtx"};
   TTreeReaderValue<Double_t>    theWeight  = {fReader, "theWeight"};
   TTreeReaderValue<Double_t>    nump  = {fReader, "nump"};
   TTreeReaderValue<Double_t>    numm  = {fReader, "numm"};
   TTreeReaderValue<Double_t>    npT  = {fReader, "npT"};
   //TTreeReaderArray<Double_t>    pweight = {fReader, "pweight"};//for EW and QCD WG PDF
   
   double pweight[703];
   for (int ip=0; ip<703; ip++){
      pweight[ip] = 1;
   }
   
   TTreeReaderValue<Int_t>    lep  = {fReader, "lep"};
   TTreeReaderValue<Double_t>    ptVlep  = {fReader, "ptVlep"};
   TTreeReaderValue<Double_t>    ptVlepJEC  = {fReader, "ptVlepJEC"};
   TTreeReaderValue<Double_t>    yVlepJEC  = {fReader, "yVlepJEC"};
   TTreeReaderValue<Double_t>    phiVlepJEC  = {fReader, "phiVlepJEC"};
   TTreeReaderValue<Double_t>    massVlepJEC  = {fReader, "massVlepJEC"};
   TTreeReaderValue<Double_t>    mtVlepJECnew  = {fReader, "mtVlepJECnew"};
   TTreeReaderValue<Double_t>    ptVlepJEC_new  = {fReader, "ptVlepJEC_new"};
   TTreeReaderValue<Double_t>    yVlepJEC_new  = {fReader, "yVlepJEC_new"};
   TTreeReaderValue<Double_t>    phiVlepJEC_new  = {fReader, "phiVlepJEC_new"};
   TTreeReaderValue<Double_t>    massVlepJEC_new  = {fReader, "massVlepJEC_new"};
   TTreeReaderValue<Double_t>    mtVlepJECnew_new  = {fReader, "mtVlepJECnew_new"};
   TTreeReaderValue<Double_t>    ptVlepJEC_JEC_up  = {fReader, "ptVlepJEC_JEC_up"};
   TTreeReaderValue<Double_t>    yVlepJEC_JEC_up  = {fReader, "yVlepJEC_JEC_up"};
   TTreeReaderValue<Double_t>    phiVlepJEC_JEC_up  = {fReader, "phiVlepJEC_JEC_up"};
   TTreeReaderValue<Double_t>    massVlepJEC_JEC_up  = {fReader, "massVlepJEC_JEC_up"};
   TTreeReaderValue<Double_t>    mtVlepJECnew_JEC_up  = {fReader, "mtVlepJECnew_JEC_up"};
   TTreeReaderValue<Double_t>    ptVlepJEC_JEC_down  = {fReader, "ptVlepJEC_JEC_down"};
   TTreeReaderValue<Double_t>    yVlepJEC_JEC_down  = {fReader, "yVlepJEC_JEC_down"};
   TTreeReaderValue<Double_t>    phiVlepJEC_JEC_down  = {fReader, "phiVlepJEC_JEC_down"};
   TTreeReaderValue<Double_t>    massVlepJEC_JEC_down  = {fReader, "massVlepJEC_JEC_down"};
   TTreeReaderValue<Double_t>    mtVlepJECnew_JEC_down  = {fReader, "mtVlepJECnew_JEC_down"};
   TTreeReaderValue<Double_t>    ptVlepJEC_JER_up  = {fReader, "ptVlepJEC_JER_up"};
   TTreeReaderValue<Double_t>    yVlepJEC_JER_up  = {fReader, "yVlepJEC_JER_up"};
   TTreeReaderValue<Double_t>    phiVlepJEC_JER_up  = {fReader, "phiVlepJEC_JER_up"};
   TTreeReaderValue<Double_t>    massVlepJEC_JER_up  = {fReader, "massVlepJEC_JER_up"};
   TTreeReaderValue<Double_t>    mtVlepJECnew_JER_up  = {fReader, "mtVlepJECnew_JER_up"};
   TTreeReaderValue<Double_t>    ptVlepJEC_JER_down  = {fReader, "ptVlepJEC_JER_down"};
   TTreeReaderValue<Double_t>    yVlepJEC_JER_down  = {fReader, "yVlepJEC_JER_down"};
   TTreeReaderValue<Double_t>    phiVlepJEC_JER_down  = {fReader, "phiVlepJEC_JER_down"};
   TTreeReaderValue<Double_t>    massVlepJEC_JER_down  = {fReader, "massVlepJEC_JER_down"};
   TTreeReaderValue<Double_t>    mtVlepJECnew_JER_down  = {fReader, "mtVlepJECnew_JER_down"};
   TTreeReaderValue<Double_t>    Mla  = {fReader, "Mla"};
   TTreeReaderValue<Double_t>    Mla_f  = {fReader, "Mla_f"};
   TTreeReaderValue<Double_t>    Mva  = {fReader, "Mva"};
   TTreeReaderValue<Double_t>    Mva_f  = {fReader, "Mva_f"};
   TTreeReaderValue<Int_t>    nlooseeles  = {fReader, "nlooseeles"};
   TTreeReaderValue<Int_t>    nloosemus  = {fReader, "nloosemus"};
   //TTreeReaderArray<Double_t>    photon_hoe  = {fReader, "photon_hoe"};

   TTreeReaderArray<Double_t>    genphoton_pt  = {fReader, "genphoton_pt"};
   TTreeReaderArray<Double_t>    genphoton_eta  = {fReader, "genphoton_eta"};
   TTreeReaderArray<Double_t>    genphoton_phi  = {fReader, "genphoton_phi"};
   TTreeReaderArray<Double_t>    genmuon_pt  = {fReader, "genmuon_pt"};
   TTreeReaderArray<Double_t>    genmuon_eta  = {fReader, "genmuon_eta"};
   TTreeReaderArray<Double_t>    genmuon_phi  = {fReader, "genmuon_phi"};
   TTreeReaderArray<Double_t>    genelectron_pt  = {fReader, "genelectron_pt"};
   TTreeReaderArray<Double_t>    genelectron_eta  = {fReader, "genelectron_eta"};
   TTreeReaderArray<Double_t>    genelectron_phi  = {fReader, "genelectron_phi"};

   TTreeReaderArray<Double_t>    genjet_pt  = {fReader, "genjet_pt"};
   TTreeReaderArray<Double_t>    genjet_eta  = {fReader, "genjet_eta"};
   TTreeReaderArray<Double_t>    genjet_phi  = {fReader, "genjet_phi"};
   TTreeReaderArray<Double_t>    genjet_e  = {fReader, "genjet_e"};


   TTreeReaderValue<Double_t>    photon_pt  = {fReader, "photon_pt"};
   TTreeReaderValue<Double_t>    photon_eta  = {fReader, "photon_eta"};
   TTreeReaderValue<Double_t>    photon_phi  = {fReader, "photon_phi"};
   TTreeReaderValue<Double_t>    photon_e  = {fReader, "photon_e"};
   TTreeReaderValue<Double_t>    photonsc_eta  = {fReader, "photonsc_eta"};
   TTreeReaderValue<Double_t>    photonsc_phi  = {fReader, "photonsc_phi"};
   TTreeReaderValue<Bool_t>    photon_pev  = {fReader, "photon_pev"};
   TTreeReaderValue<Bool_t>    photon_pevnew  = {fReader, "photon_pevnew"};
   TTreeReaderValue<Bool_t>    photon_ppsv  = {fReader, "photon_ppsv"};
   TTreeReaderValue<Bool_t>    photon_iseb  = {fReader, "photon_iseb"};
   TTreeReaderValue<Bool_t>    photon_isee  = {fReader, "photon_isee"};
   TTreeReaderValue<Double_t>    photon_hoe  = {fReader, "photon_hoe"};
   TTreeReaderValue<Double_t>    photon_sieie  = {fReader, "photon_sieie"};
   TTreeReaderValue<Double_t>    photon_sieie2  = {fReader, "photon_sieie2"};
   TTreeReaderValue<Double_t>    photon_chiso  = {fReader, "photon_chiso"};
   TTreeReaderValue<Double_t>    photon_nhiso  = {fReader, "photon_nhiso"};
   TTreeReaderValue<Double_t>    photon_phoiso  = {fReader, "photon_phoiso"};
   TTreeReaderValue<Int_t>    photon_istrue  = {fReader, "photon_istrue"};
   TTreeReaderValue<Int_t>    photon_isprompt  = {fReader, "photon_isprompt"};
   TTreeReaderValue<Double_t>    photon_drla  = {fReader, "photon_drla"};
   TTreeReaderValue<Double_t>    photon_mla  = {fReader, "photon_mla"};
   TTreeReaderValue<Double_t>    photon_mva  = {fReader, "photon_mva"};
   TTreeReaderValue<Bool_t>    passEleVeto  = {fReader, "passEleVeto"};
   TTreeReaderValue<Bool_t>    passEleVetonew  = {fReader, "passEleVetonew"};
   TTreeReaderValue<Bool_t>    passPixelSeedVeto  = {fReader, "passPixelSeedVeto"};
   TTreeReaderValue<Bool_t>    photonhaspixelseed  = {fReader, "photonhaspixelseed"};
   TTreeReaderValue<Bool_t>    photonhaspixelseed_f  = {fReader, "photonhaspixelseed_f"};
   //TTreeReaderValue<Bool_t>    photonpasseleveto  = {fReader, "photonpasseleveto"};
   //TTreeReaderValue<Bool_t>    photonpasseleveto_f  = {fReader, "photonpasseleveto_f"};
   TTreeReaderValue<Double_t>    photonet  = {fReader, "photonet"};
   TTreeReaderValue<Double_t>    photonet_f  = {fReader, "photonet_f"};
   TTreeReaderValue<Double_t>    photoneta  = {fReader, "photoneta"};
   TTreeReaderValue<Double_t>    photoneta_f  = {fReader, "photoneta_f"};
   TTreeReaderValue<Double_t>    photonphi  = {fReader, "photonphi"};
   TTreeReaderValue<Double_t>    photonphi_f  = {fReader, "photonphi_f"};
   TTreeReaderValue<Double_t>    photone  = {fReader, "photone"};
   TTreeReaderValue<Double_t>    photone_f  = {fReader, "photone_f"};
   TTreeReaderValue<Double_t>    photonsceta  = {fReader, "photonsceta"};
   TTreeReaderValue<Double_t>    photonsceta_f  = {fReader, "photonsceta_f"};
   TTreeReaderValue<Double_t>    photonscphi  = {fReader, "photonscphi"};
   TTreeReaderValue<Double_t>    photonscphi_f  = {fReader, "photonscphi_f"};
   TTreeReaderValue<Double_t>    photonsieie  = {fReader, "photonsieie"};
   TTreeReaderValue<Double_t>    photonsieie_f  = {fReader, "photonsieie_f"};
   TTreeReaderValue<Double_t>    photonphoiso  = {fReader, "photonphoiso"};
   TTreeReaderValue<Double_t>    photonphoiso_f  = {fReader, "photonphoiso_f"};
   TTreeReaderValue<Double_t>    photonchiso  = {fReader, "photonchiso"};
   TTreeReaderValue<Double_t>    photonchiso_f  = {fReader, "photonchiso_f"};
   TTreeReaderValue<Double_t>    photonnhiso  = {fReader, "photonnhiso"};
   TTreeReaderValue<Double_t>    photonnhiso_f  = {fReader, "photonnhiso_f"};
   TTreeReaderValue<Int_t>    iphoton  = {fReader, "iphoton"};
   TTreeReaderValue<Int_t>    iphoton_f  = {fReader, "iphoton_f"};
   TTreeReaderValue<Double_t>    drla  = {fReader, "drla"};
   TTreeReaderValue<Double_t>    drla_f  = {fReader, "drla_f"};
   TTreeReaderValue<Int_t>    isTrue  = {fReader, "isTrue"};
   TTreeReaderValue<Int_t>    isprompt  = {fReader, "isprompt"};
   TTreeReaderValue<Int_t>    ispromptLep  = {fReader, "ispromptLep"};
   TTreeReaderValue<Int_t>    ak4jet_hf  = {fReader, "ak4jet_hf"};
   TTreeReaderValue<Int_t>    ak4jet_pf  = {fReader, "ak4jet_pf"};
   TTreeReaderValue<Int_t>    jet1hf  = {fReader, "jet1hf"};
   TTreeReaderValue<Int_t>    jet1pf  = {fReader, "jet1pf"};
   TTreeReaderValue<Int_t>    jet2hf  = {fReader, "jet2hf"};
   TTreeReaderValue<Int_t>    jet2pf  = {fReader, "jet2pf"};
   TTreeReaderValue<Int_t>    jet1hf_f  = {fReader, "jet1hf_f"};
   TTreeReaderValue<Int_t>    jet1pf_f  = {fReader, "jet1pf_f"};
   TTreeReaderValue<Int_t>    jet2hf_f  = {fReader, "jet2hf_f"};
   TTreeReaderValue<Int_t>    jet2pf_f  = {fReader, "jet2pf_f"};
   TTreeReaderValue<Int_t>    jet1hf_new  = {fReader, "jet1hf_new"};
   TTreeReaderValue<Int_t>    jet1pf_new  = {fReader, "jet1pf_new"};
   TTreeReaderValue<Int_t>    jet2hf_new  = {fReader, "jet2hf_new"};
   TTreeReaderValue<Int_t>    jet2pf_new  = {fReader, "jet2pf_new"};
   TTreeReaderValue<Int_t>    jet1hf_new_f  = {fReader, "jet1hf_new_f"};
   TTreeReaderValue<Int_t>    jet1pf_new_f  = {fReader, "jet1pf_new_f"};
   TTreeReaderValue<Int_t>    jet2hf_new_f  = {fReader, "jet2hf_new_f"};
   TTreeReaderValue<Int_t>    jet2pf_new_f  = {fReader, "jet2pf_new_f"};
   TTreeReaderValue<Int_t>    jet1hf_JEC_up  = {fReader, "jet1hf_JEC_up"};
   TTreeReaderValue<Int_t>    jet1pf_JEC_up  = {fReader, "jet1pf_JEC_up"};
   TTreeReaderValue<Int_t>    jet2hf_JEC_up  = {fReader, "jet2hf_JEC_up"};
   TTreeReaderValue<Int_t>    jet2pf_JEC_up  = {fReader, "jet2pf_JEC_up"};
   TTreeReaderValue<Int_t>    jet1hf_JEC_up_f  = {fReader, "jet1hf_JEC_up_f"};
   TTreeReaderValue<Int_t>    jet1pf_JEC_up_f  = {fReader, "jet1pf_JEC_up_f"};
   TTreeReaderValue<Int_t>    jet2hf_JEC_up_f  = {fReader, "jet2hf_JEC_up_f"};
   TTreeReaderValue<Int_t>    jet2pf_JEC_up_f  = {fReader, "jet2pf_JEC_up_f"};
   TTreeReaderValue<Int_t>    jet1hf_JEC_down  = {fReader, "jet1hf_JEC_down"};
   TTreeReaderValue<Int_t>    jet1pf_JEC_down  = {fReader, "jet1pf_JEC_down"};
   TTreeReaderValue<Int_t>    jet2hf_JEC_down  = {fReader, "jet2hf_JEC_down"};
   TTreeReaderValue<Int_t>    jet2pf_JEC_down  = {fReader, "jet2pf_JEC_down"};
   TTreeReaderValue<Int_t>    jet1hf_JEC_down_f  = {fReader, "jet1hf_JEC_down_f"};
   TTreeReaderValue<Int_t>    jet1pf_JEC_down_f  = {fReader, "jet1pf_JEC_down_f"};
   TTreeReaderValue<Int_t>    jet2hf_JEC_down_f  = {fReader, "jet2hf_JEC_down_f"};
   TTreeReaderValue<Int_t>    jet2pf_JEC_down_f  = {fReader, "jet2pf_JEC_down_f"};
   TTreeReaderValue<Int_t>    jet1hf_JER_up  = {fReader, "jet1hf_JER_up"};
   TTreeReaderValue<Int_t>    jet1pf_JER_up  = {fReader, "jet1pf_JER_up"};
   TTreeReaderValue<Int_t>    jet2hf_JER_up  = {fReader, "jet2hf_JER_up"};
   TTreeReaderValue<Int_t>    jet2pf_JER_up  = {fReader, "jet2pf_JER_up"};
   TTreeReaderValue<Int_t>    jet1hf_JER_up_f  = {fReader, "jet1hf_JER_up_f"};
   TTreeReaderValue<Int_t>    jet1pf_JER_up_f  = {fReader, "jet1pf_JER_up_f"};
   TTreeReaderValue<Int_t>    jet2hf_JER_up_f  = {fReader, "jet2hf_JER_up_f"};
   TTreeReaderValue<Int_t>    jet2pf_JER_up_f  = {fReader, "jet2pf_JER_up_f"};
   TTreeReaderValue<Int_t>    jet1hf_JER_down  = {fReader, "jet1hf_JER_down"};
   TTreeReaderValue<Int_t>    jet1pf_JER_down  = {fReader, "jet1pf_JER_down"};
   TTreeReaderValue<Int_t>    jet2hf_JER_down  = {fReader, "jet2hf_JER_down"};
   TTreeReaderValue<Int_t>    jet2pf_JER_down  = {fReader, "jet2pf_JER_down"};
   TTreeReaderValue<Int_t>    jet1hf_JER_down_f  = {fReader, "jet1hf_JER_down_f"};
   TTreeReaderValue<Int_t>    jet1pf_JER_down_f  = {fReader, "jet1pf_JER_down_f"};
   TTreeReaderValue<Int_t>    jet2hf_JER_down_f  = {fReader, "jet2hf_JER_down_f"};
   TTreeReaderValue<Int_t>    jet2pf_JER_down_f  = {fReader, "jet2pf_JER_down_f"};
   TTreeReaderValue<Double_t>    ak4jet_pt  = {fReader, "ak4jet_pt"};
   TTreeReaderValue<Double_t>    ak4jet_eta  = {fReader, "ak4jet_eta"};
   TTreeReaderValue<Double_t>    ak4jet_phi  = {fReader, "ak4jet_phi"};
   TTreeReaderValue<Double_t>    ak4jet_e  = {fReader, "ak4jet_e"};
   TTreeReaderValue<Double_t>    ak4jet_csv  = {fReader, "ak4jet_csv"};
   TTreeReaderValue<Double_t>    ak4jet_deepcsv_probb  = {fReader, "ak4jet_deepcsv_probb"};
   TTreeReaderValue<Double_t>    ak4jet_deepcsv_probbb  = {fReader, "ak4jet_deepcsv_probbb"};
   TTreeReaderValue<Double_t>    ak4jet_deepcsv_probc  = {fReader, "ak4jet_deepcsv_probc"};
   TTreeReaderValue<Double_t>    ak4jet_deepcsv_probcc  = {fReader, "ak4jet_deepcsv_probcc"};
   TTreeReaderValue<Double_t>    ak4jet_icsv  = {fReader, "ak4jet_icsv"};
   TTreeReaderValue<Double_t>    ak4jet_pt_old  = {fReader, "ak4jet_pt_old"};
   TTreeReaderValue<Double_t>    ak4jet_pt_new  = {fReader, "ak4jet_pt_new"};
   TTreeReaderValue<Double_t>    ak4jet_pt_JEC_up  = {fReader, "ak4jet_pt_JEC_up"};
   TTreeReaderValue<Double_t>    ak4jet_pt_JEC_down  = {fReader, "ak4jet_pt_JEC_down"};
   TTreeReaderValue<Double_t>    ak4jet_pt_JER_up  = {fReader, "ak4jet_pt_JER_up"};
   TTreeReaderValue<Double_t>    ak4jet_pt_JER_down  = {fReader, "ak4jet_pt_JER_down"};
   TTreeReaderValue<Double_t>    ak4jet_e_old  = {fReader, "ak4jet_e_old"};
   TTreeReaderValue<Double_t>    ak4jet_e_new  = {fReader, "ak4jet_e_new"};
   TTreeReaderValue<Double_t>    ak4jet_e_JEC_up  = {fReader, "ak4jet_e_JEC_up"};
   TTreeReaderValue<Double_t>    ak4jet_e_JEC_down  = {fReader, "ak4jet_e_JEC_down"};
   TTreeReaderValue<Double_t>    ak4jet_e_JER_up  = {fReader, "ak4jet_e_JER_up"};
   TTreeReaderValue<Double_t>    ak4jet_e_JER_down  = {fReader, "ak4jet_e_JER_down"};
   TTreeReaderValue<Double_t>    jet1pt  = {fReader, "jet1pt"};
   TTreeReaderValue<Double_t>    jet1pt_new  = {fReader, "jet1pt_new"};
   TTreeReaderValue<Double_t>    jet1pt_JEC_up  = {fReader, "jet1pt_JEC_up"};
   TTreeReaderValue<Double_t>    jet1pt_JER_up  = {fReader, "jet1pt_JER_up"};
   TTreeReaderValue<Double_t>    jet1pt_JEC_down  = {fReader, "jet1pt_JEC_down"};
   TTreeReaderValue<Double_t>    jet1pt_JER_down  = {fReader, "jet1pt_JER_down"};
   TTreeReaderValue<Double_t>    jet1pt_f  = {fReader, "jet1pt_f"};
   TTreeReaderValue<Double_t>    jet1pt_new_f  = {fReader, "jet1pt_new_f"};
   TTreeReaderValue<Double_t>    jet1pt_JEC_up_f  = {fReader, "jet1pt_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet1pt_JER_up_f  = {fReader, "jet1pt_JER_up_f"};
   TTreeReaderValue<Double_t>    jet1pt_JEC_down_f  = {fReader, "jet1pt_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet1pt_JER_down_f  = {fReader, "jet1pt_JER_down_f"};
   TTreeReaderValue<Double_t>    jet1eta  = {fReader, "jet1eta"};
   TTreeReaderValue<Double_t>    jet1eta_new  = {fReader, "jet1eta_new"};
   TTreeReaderValue<Double_t>    jet1eta_JEC_up  = {fReader, "jet1eta_JEC_up"};
   TTreeReaderValue<Double_t>    jet1eta_JEC_down  = {fReader, "jet1eta_JEC_down"};
   TTreeReaderValue<Double_t>    jet1eta_JER_up  = {fReader, "jet1eta_JER_up"};
   TTreeReaderValue<Double_t>    jet1eta_JER_down  = {fReader, "jet1eta_JER_down"};
   TTreeReaderValue<Double_t>    jet1eta_f  = {fReader, "jet1eta_f"};
   TTreeReaderValue<Double_t>    jet1eta_new_f  = {fReader, "jet1eta_new_f"};
   TTreeReaderValue<Double_t>    jet1eta_JEC_up_f  = {fReader, "jet1eta_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet1eta_JEC_down_f  = {fReader, "jet1eta_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet1eta_JER_up_f  = {fReader, "jet1eta_JER_up_f"};
   TTreeReaderValue<Double_t>    jet1eta_JER_down_f  = {fReader, "jet1eta_JER_down_f"};
   TTreeReaderValue<Double_t>    jet1phi  = {fReader, "jet1phi"};
   TTreeReaderValue<Double_t>    jet1phi_new  = {fReader, "jet1phi_new"};
   TTreeReaderValue<Double_t>    jet1phi_JEC_up  = {fReader, "jet1phi_JEC_up"};
   TTreeReaderValue<Double_t>    jet1phi_JEC_down  = {fReader, "jet1phi_JEC_down"};
   TTreeReaderValue<Double_t>    jet1phi_JER_up  = {fReader, "jet1phi_JER_up"};
   TTreeReaderValue<Double_t>    jet1phi_JER_down  = {fReader, "jet1phi_JER_down"};
   TTreeReaderValue<Double_t>    jet1phi_f  = {fReader, "jet1phi_f"};
   TTreeReaderValue<Double_t>    jet1phi_new_f  = {fReader, "jet1phi_new_f"};
   TTreeReaderValue<Double_t>    jet1phi_JEC_up_f  = {fReader, "jet1phi_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet1phi_JEC_down_f  = {fReader, "jet1phi_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet1phi_JER_up_f  = {fReader, "jet1phi_JER_up_f"};
   TTreeReaderValue<Double_t>    jet1phi_JER_down_f  = {fReader, "jet1phi_JER_down_f"};
   TTreeReaderValue<Double_t>    jet1e  = {fReader, "jet1e"};
   TTreeReaderValue<Double_t>    jet1e_new  = {fReader, "jet1e_new"};
   TTreeReaderValue<Double_t>    jet1e_JEC_up  = {fReader, "jet1e_JEC_up"};
   TTreeReaderValue<Double_t>    jet1e_JER_up  = {fReader, "jet1e_JER_up"};
   TTreeReaderValue<Double_t>    jet1e_JEC_down  = {fReader, "jet1e_JEC_down"};
   TTreeReaderValue<Double_t>    jet1e_JER_down  = {fReader, "jet1e_JER_down"};
   TTreeReaderValue<Double_t>    jet1e_f  = {fReader, "jet1e_f"};
   TTreeReaderValue<Double_t>    jet1e_new_f  = {fReader, "jet1e_new_f"};
   TTreeReaderValue<Double_t>    jet1e_JEC_up_f  = {fReader, "jet1e_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet1e_JER_up_f  = {fReader, "jet1e_JER_up_f"};
   TTreeReaderValue<Double_t>    jet1e_JEC_down_f  = {fReader, "jet1e_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet1e_JER_down_f  = {fReader, "jet1e_JER_down_f"};
   TTreeReaderValue<Double_t>    jet1csv  = {fReader, "jet1csv"};
   TTreeReaderValue<Double_t>    jet1csv_new  = {fReader, "jet1csv_new"};
   TTreeReaderValue<Double_t>    jet1csv_JEC_up  = {fReader, "jet1csv_JEC_up"};
   TTreeReaderValue<Double_t>    jet1csv_JER_up  = {fReader, "jet1csv_JER_up"};
   TTreeReaderValue<Double_t>    jet1csv_JEC_down  = {fReader, "jet1csv_JEC_down"};
   TTreeReaderValue<Double_t>    jet1csv_JER_down  = {fReader, "jet1csv_JER_down"};
   TTreeReaderValue<Double_t>    jet1csv_f  = {fReader, "jet1csv_f"};
   TTreeReaderValue<Double_t>    jet1csv_new_f  = {fReader, "jet1csv_new_f"};
   TTreeReaderValue<Double_t>    jet1csv_JEC_up_f  = {fReader, "jet1csv_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet1csv_JER_up_f  = {fReader, "jet1csv_JER_up_f"};
   TTreeReaderValue<Double_t>    jet1csv_JEC_down_f  = {fReader, "jet1csv_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet1csv_JER_down_f  = {fReader, "jet1csv_JER_down_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb  = {fReader, "jet1deepcsv_probb"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb  = {fReader, "jet1deepcsv_probbb"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc  = {fReader, "jet1deepcsv_probc"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc  = {fReader, "jet1deepcsv_probcc"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_new  = {fReader, "jet1deepcsv_probb_new"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_new  = {fReader, "jet1deepcsv_probbb_new"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_new  = {fReader, "jet1deepcsv_probc_new"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_new  = {fReader, "jet1deepcsv_probcc_new"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_JEC_up  = {fReader, "jet1deepcsv_probb_JEC_up"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_JEC_up  = {fReader, "jet1deepcsv_probbb_JEC_up"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_JEC_up  = {fReader, "jet1deepcsv_probc_JEC_up"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_JEC_up  = {fReader, "jet1deepcsv_probcc_JEC_up"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_JEC_down  = {fReader, "jet1deepcsv_probb_JEC_down"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_JEC_down  = {fReader, "jet1deepcsv_probbb_JEC_down"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_JEC_down  = {fReader, "jet1deepcsv_probc_JEC_down"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_JEC_down  = {fReader, "jet1deepcsv_probcc_JEC_down"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_JER_up  = {fReader, "jet1deepcsv_probb_JER_up"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_JER_up  = {fReader, "jet1deepcsv_probbb_JER_up"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_JER_up  = {fReader, "jet1deepcsv_probc_JER_up"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_JER_up  = {fReader, "jet1deepcsv_probcc_JER_up"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_JER_down  = {fReader, "jet1deepcsv_probb_JER_down"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_JER_down  = {fReader, "jet1deepcsv_probbb_JER_down"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_JER_down  = {fReader, "jet1deepcsv_probc_JER_down"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_JER_down  = {fReader, "jet1deepcsv_probcc_JER_down"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_f  = {fReader, "jet1deepcsv_probb_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_f  = {fReader, "jet1deepcsv_probbb_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_f  = {fReader, "jet1deepcsv_probc_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_f  = {fReader, "jet1deepcsv_probcc_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_new_f  = {fReader, "jet1deepcsv_probb_new_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_new_f  = {fReader, "jet1deepcsv_probbb_new_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_new_f  = {fReader, "jet1deepcsv_probc_new_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_new_f  = {fReader, "jet1deepcsv_probcc_new_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_JEC_up_f  = {fReader, "jet1deepcsv_probb_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_JEC_up_f  = {fReader, "jet1deepcsv_probbb_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_JEC_up_f  = {fReader, "jet1deepcsv_probc_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_JEC_up_f  = {fReader, "jet1deepcsv_probcc_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_JEC_down_f  = {fReader, "jet1deepcsv_probb_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_JEC_down_f  = {fReader, "jet1deepcsv_probbb_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_JEC_down_f  = {fReader, "jet1deepcsv_probc_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_JEC_down_f  = {fReader, "jet1deepcsv_probcc_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_JER_up_f  = {fReader, "jet1deepcsv_probb_JER_up_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_JER_up_f  = {fReader, "jet1deepcsv_probbb_JER_up_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_JER_up_f  = {fReader, "jet1deepcsv_probc_JER_up_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_JER_up_f  = {fReader, "jet1deepcsv_probcc_JER_up_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probb_JER_down_f  = {fReader, "jet1deepcsv_probb_JER_down_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probbb_JER_down_f  = {fReader, "jet1deepcsv_probbb_JER_down_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probc_JER_down_f  = {fReader, "jet1deepcsv_probc_JER_down_f"};
   TTreeReaderValue<Double_t>    jet1deepcsv_probcc_JER_down_f  = {fReader, "jet1deepcsv_probcc_JER_down_f"};
   TTreeReaderValue<Double_t>    jet1icsv  = {fReader, "jet1icsv"};
   TTreeReaderValue<Double_t>    jet1icsv_new  = {fReader, "jet1icsv_new"};
   TTreeReaderValue<Double_t>    jet1icsv_JEC_up  = {fReader, "jet1icsv_JEC_up"};
   TTreeReaderValue<Double_t>    jet1icsv_JER_up  = {fReader, "jet1icsv_JER_up"};
   TTreeReaderValue<Double_t>    jet1icsv_JEC_down  = {fReader, "jet1icsv_JEC_down"};
   TTreeReaderValue<Double_t>    jet1icsv_JER_down  = {fReader, "jet1icsv_JER_down"};
   TTreeReaderValue<Double_t>    jet1icsv_f  = {fReader, "jet1icsv_f"};
   TTreeReaderValue<Double_t>    jet1icsv_new_f  = {fReader, "jet1icsv_new_f"};
   TTreeReaderValue<Double_t>    jet1icsv_JEC_up_f  = {fReader, "jet1icsv_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet1icsv_JER_up_f  = {fReader, "jet1icsv_JER_up_f"};
   TTreeReaderValue<Double_t>    jet1icsv_JEC_down_f  = {fReader, "jet1icsv_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet1icsv_JER_down_f  = {fReader, "jet1icsv_JER_down_f"};
   TTreeReaderValue<Double_t>    jet2pt  = {fReader, "jet2pt"};
   TTreeReaderValue<Double_t>    jet2pt_new  = {fReader, "jet2pt_new"};
   TTreeReaderValue<Double_t>    jet2pt_JEC_up  = {fReader, "jet2pt_JEC_up"};
   TTreeReaderValue<Double_t>    jet2pt_JER_up  = {fReader, "jet2pt_JER_up"};
   TTreeReaderValue<Double_t>    jet2pt_JEC_down  = {fReader, "jet2pt_JEC_down"};
   TTreeReaderValue<Double_t>    jet2pt_JER_down  = {fReader, "jet2pt_JER_down"};
   TTreeReaderValue<Double_t>    jet2pt_f  = {fReader, "jet2pt_f"};
   TTreeReaderValue<Double_t>    jet2pt_new_f  = {fReader, "jet2pt_new_f"};
   TTreeReaderValue<Double_t>    jet2pt_JEC_up_f  = {fReader, "jet2pt_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet2pt_JER_up_f  = {fReader, "jet2pt_JER_up_f"};
   TTreeReaderValue<Double_t>    jet2pt_JEC_down_f  = {fReader, "jet2pt_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet2pt_JER_down_f  = {fReader, "jet2pt_JER_down_f"};
   TTreeReaderValue<Double_t>    jet2eta  = {fReader, "jet2eta"};
   TTreeReaderValue<Double_t>    jet2eta_new  = {fReader, "jet2eta_new"};
   TTreeReaderValue<Double_t>    jet2eta_JEC_up  = {fReader, "jet2eta_JEC_up"};
   TTreeReaderValue<Double_t>    jet2eta_JEC_down  = {fReader, "jet2eta_JEC_down"};
   TTreeReaderValue<Double_t>    jet2eta_JER_up  = {fReader, "jet2eta_JER_up"};
   TTreeReaderValue<Double_t>    jet2eta_JER_down  = {fReader, "jet2eta_JER_down"};
   TTreeReaderValue<Double_t>    jet2phi  = {fReader, "jet2phi"};
   TTreeReaderValue<Double_t>    jet2phi_new  = {fReader, "jet2phi_new"};
   TTreeReaderValue<Double_t>    jet2phi_JEC_up  = {fReader, "jet2phi_JEC_up"};
   TTreeReaderValue<Double_t>    jet2phi_JEC_down  = {fReader, "jet2phi_JEC_down"};
   TTreeReaderValue<Double_t>    jet2phi_JER_up  = {fReader, "jet2phi_JER_up"};
   TTreeReaderValue<Double_t>    jet2phi_JER_down  = {fReader, "jet2phi_JER_down"};
   TTreeReaderValue<Double_t>    jet2phi_f  = {fReader, "jet2phi_f"};
   TTreeReaderValue<Double_t>    jet2phi_new_f  = {fReader, "jet2phi_new_f"};
   TTreeReaderValue<Double_t>    jet2phi_JEC_up_f  = {fReader, "jet2phi_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet2phi_JEC_down_f  = {fReader, "jet2phi_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet2phi_JER_up_f  = {fReader, "jet2phi_JER_up_f"};
   TTreeReaderValue<Double_t>    jet2phi_JER_down_f  = {fReader, "jet2phi_JER_down_f"};
   TTreeReaderValue<Double_t>    jet2eta_f  = {fReader, "jet2eta_f"};
   TTreeReaderValue<Double_t>    jet2eta_new_f  = {fReader, "jet2eta_new_f"};
   TTreeReaderValue<Double_t>    jet2eta_JEC_up_f  = {fReader, "jet2eta_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet2eta_JEC_down_f  = {fReader, "jet2eta_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet2eta_JER_up_f  = {fReader, "jet2eta_JER_up_f"};
   TTreeReaderValue<Double_t>    jet2eta_JER_down_f  = {fReader, "jet2eta_JER_down_f"};
   TTreeReaderValue<Double_t>    jet2e  = {fReader, "jet2e"};
   TTreeReaderValue<Double_t>    jet2e_new  = {fReader, "jet2e_new"};
   TTreeReaderValue<Double_t>    jet2e_JEC_up  = {fReader, "jet2e_JEC_up"};
   TTreeReaderValue<Double_t>    jet2e_JER_up  = {fReader, "jet2e_JER_up"};
   TTreeReaderValue<Double_t>    jet2e_JEC_down  = {fReader, "jet2e_JEC_down"};
   TTreeReaderValue<Double_t>    jet2e_JER_down  = {fReader, "jet2e_JER_down"};
   TTreeReaderValue<Double_t>    jet2e_f  = {fReader, "jet2e_f"};
   TTreeReaderValue<Double_t>    jet2e_new_f  = {fReader, "jet2e_new_f"};
   TTreeReaderValue<Double_t>    jet2e_JEC_up_f  = {fReader, "jet2e_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet2e_JER_up_f  = {fReader, "jet2e_JER_up_f"};
   TTreeReaderValue<Double_t>    jet2e_JEC_down_f  = {fReader, "jet2e_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet2e_JER_down_f  = {fReader, "jet2e_JER_down_f"};
   TTreeReaderValue<Double_t>    jet2csv  = {fReader, "jet2csv"};
   TTreeReaderValue<Double_t>    jet2csv_new  = {fReader, "jet2csv_new"};
   TTreeReaderValue<Double_t>    jet2csv_JEC_up  = {fReader, "jet2csv_JEC_up"};
   TTreeReaderValue<Double_t>    jet2csv_JER_up  = {fReader, "jet2csv_JER_up"};
   TTreeReaderValue<Double_t>    jet2csv_JEC_down  = {fReader, "jet2csv_JEC_down"};
   TTreeReaderValue<Double_t>    jet2csv_JER_down  = {fReader, "jet2csv_JER_down"};
   TTreeReaderValue<Double_t>    jet2csv_f  = {fReader, "jet2csv_f"};
   TTreeReaderValue<Double_t>    jet2csv_new_f  = {fReader, "jet2csv_new_f"};
   TTreeReaderValue<Double_t>    jet2csv_JEC_up_f  = {fReader, "jet2csv_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet2csv_JER_up_f  = {fReader, "jet2csv_JER_up_f"};
   TTreeReaderValue<Double_t>    jet2csv_JEC_down_f  = {fReader, "jet2csv_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet2csv_JER_down_f  = {fReader, "jet2csv_JER_down_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb  = {fReader, "jet2deepcsv_probb"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb  = {fReader, "jet2deepcsv_probbb"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc  = {fReader, "jet2deepcsv_probc"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc  = {fReader, "jet2deepcsv_probcc"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_new  = {fReader, "jet2deepcsv_probb_new"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_new  = {fReader, "jet2deepcsv_probbb_new"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_new  = {fReader, "jet2deepcsv_probc_new"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_new  = {fReader, "jet2deepcsv_probcc_new"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_JEC_up  = {fReader, "jet2deepcsv_probb_JEC_up"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_JEC_up  = {fReader, "jet2deepcsv_probbb_JEC_up"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_JEC_up  = {fReader, "jet2deepcsv_probc_JEC_up"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_JEC_up  = {fReader, "jet2deepcsv_probcc_JEC_up"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_JEC_down  = {fReader, "jet2deepcsv_probb_JEC_down"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_JEC_down  = {fReader, "jet2deepcsv_probbb_JEC_down"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_JEC_down  = {fReader, "jet2deepcsv_probc_JEC_down"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_JEC_down  = {fReader, "jet2deepcsv_probcc_JEC_down"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_JER_up  = {fReader, "jet2deepcsv_probb_JER_up"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_JER_up  = {fReader, "jet2deepcsv_probbb_JER_up"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_JER_up  = {fReader, "jet2deepcsv_probc_JER_up"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_JER_up  = {fReader, "jet2deepcsv_probcc_JER_up"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_JER_down  = {fReader, "jet2deepcsv_probb_JER_down"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_JER_down  = {fReader, "jet2deepcsv_probbb_JER_down"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_JER_down  = {fReader, "jet2deepcsv_probc_JER_down"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_JER_down  = {fReader, "jet2deepcsv_probcc_JER_down"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_f  = {fReader, "jet2deepcsv_probb_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_f  = {fReader, "jet2deepcsv_probbb_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_f  = {fReader, "jet2deepcsv_probc_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_f  = {fReader, "jet2deepcsv_probcc_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_new_f  = {fReader, "jet2deepcsv_probb_new_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_new_f  = {fReader, "jet2deepcsv_probbb_new_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_new_f  = {fReader, "jet2deepcsv_probc_new_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_new_f  = {fReader, "jet2deepcsv_probcc_new_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_JEC_up_f  = {fReader, "jet2deepcsv_probb_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_JEC_up_f  = {fReader, "jet2deepcsv_probbb_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_JEC_up_f  = {fReader, "jet2deepcsv_probc_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_JEC_up_f  = {fReader, "jet2deepcsv_probcc_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_JEC_down_f  = {fReader, "jet2deepcsv_probb_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_JEC_down_f  = {fReader, "jet2deepcsv_probbb_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_JEC_down_f  = {fReader, "jet2deepcsv_probc_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_JEC_down_f  = {fReader, "jet2deepcsv_probcc_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_JER_up_f  = {fReader, "jet2deepcsv_probb_JER_up_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_JER_up_f  = {fReader, "jet2deepcsv_probbb_JER_up_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_JER_up_f  = {fReader, "jet2deepcsv_probc_JER_up_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_JER_up_f  = {fReader, "jet2deepcsv_probcc_JER_up_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probb_JER_down_f  = {fReader, "jet2deepcsv_probb_JER_down_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probbb_JER_down_f  = {fReader, "jet2deepcsv_probbb_JER_down_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probc_JER_down_f  = {fReader, "jet2deepcsv_probc_JER_down_f"};
   TTreeReaderValue<Double_t>    jet2deepcsv_probcc_JER_down_f  = {fReader, "jet2deepcsv_probcc_JER_down_f"};
   TTreeReaderValue<Double_t>    jet2icsv  = {fReader, "jet2icsv"};
   TTreeReaderValue<Double_t>    jet2icsv_new  = {fReader, "jet2icsv_new"};
   TTreeReaderValue<Double_t>    jet2icsv_JEC_up  = {fReader, "jet2icsv_JEC_up"};
   TTreeReaderValue<Double_t>    jet2icsv_JER_up  = {fReader, "jet2icsv_JER_up"};
   TTreeReaderValue<Double_t>    jet2icsv_JEC_down  = {fReader, "jet2icsv_JEC_down"};
   TTreeReaderValue<Double_t>    jet2icsv_JER_down  = {fReader, "jet2icsv_JER_down"};
   TTreeReaderValue<Double_t>    jet2icsv_f  = {fReader, "jet2icsv_f"};
   TTreeReaderValue<Double_t>    jet2icsv_new_f  = {fReader, "jet2icsv_new_f"};
   TTreeReaderValue<Double_t>    jet2icsv_JEC_up_f  = {fReader, "jet2icsv_JEC_up_f"};
   TTreeReaderValue<Double_t>    jet2icsv_JER_up_f  = {fReader, "jet2icsv_JER_up_f"};
   TTreeReaderValue<Double_t>    jet2icsv_JEC_down_f  = {fReader, "jet2icsv_JEC_down_f"};
   TTreeReaderValue<Double_t>    jet2icsv_JER_down_f  = {fReader, "jet2icsv_JER_down_f"};
   TTreeReaderValue<Double_t>    drj1a  = {fReader, "drj1a"};
   TTreeReaderValue<Double_t>    drj1a_new  = {fReader, "drj1a_new"};
   TTreeReaderValue<Double_t>    drj1a_JEC_up  = {fReader, "drj1a_JEC_up"};
   TTreeReaderValue<Double_t>    drj1a_JEC_down  = {fReader, "drj1a_JEC_down"};
   TTreeReaderValue<Double_t>    drj1a_JER_up  = {fReader, "drj1a_JER_up"};
   TTreeReaderValue<Double_t>    drj1a_JER_down  = {fReader, "drj1a_JER_down"};
   TTreeReaderValue<Double_t>    drj1a_f  = {fReader, "drj1a_f"};
   TTreeReaderValue<Double_t>    drj1a_new_f  = {fReader, "drj1a_new_f"};
   TTreeReaderValue<Double_t>    drj1a_JEC_up_f  = {fReader, "drj1a_JEC_up_f"};
   TTreeReaderValue<Double_t>    drj1a_JEC_down_f  = {fReader, "drj1a_JEC_down_f"};
   TTreeReaderValue<Double_t>    drj1a_JER_up_f  = {fReader, "drj1a_JER_up_f"};
   TTreeReaderValue<Double_t>    drj1a_JER_down_f  = {fReader, "drj1a_JER_down_f"};
   TTreeReaderValue<Double_t>    drj2a  = {fReader, "drj2a"};
   TTreeReaderValue<Double_t>    drj2a_new  = {fReader, "drj2a_new"};
   TTreeReaderValue<Double_t>    drj2a_JEC_up  = {fReader, "drj2a_JEC_up"};
   TTreeReaderValue<Double_t>    drj2a_JEC_down  = {fReader, "drj2a_JEC_down"};
   TTreeReaderValue<Double_t>    drj2a_JER_up  = {fReader, "drj2a_JER_up"};
   TTreeReaderValue<Double_t>    drj2a_JER_down  = {fReader, "drj2a_JER_down"};
   TTreeReaderValue<Double_t>    drj2a_f  = {fReader, "drj2a_f"};
   TTreeReaderValue<Double_t>    drj2a_new_f  = {fReader, "drj2a_new_f"};
   TTreeReaderValue<Double_t>    drj2a_JEC_up_f  = {fReader, "drj2a_JEC_up_f"};
   TTreeReaderValue<Double_t>    drj2a_JEC_down_f  = {fReader, "drj2a_JEC_down_f"};
   TTreeReaderValue<Double_t>    drj2a_JER_up_f  = {fReader, "drj2a_JER_up_f"};
   TTreeReaderValue<Double_t>    drj2a_JER_down_f  = {fReader, "drj2a_JER_down_f"};
   TTreeReaderValue<Double_t>    drj1l  = {fReader, "drj1l"};
   TTreeReaderValue<Double_t>    drj1l_new  = {fReader, "drj1l_new"};
   TTreeReaderValue<Double_t>    drj1l_JEC_up  = {fReader, "drj1l_JEC_up"};
   TTreeReaderValue<Double_t>    drj1l_JEC_down  = {fReader, "drj1l_JEC_down"};
   TTreeReaderValue<Double_t>    drj1l_JER_up  = {fReader, "drj1l_JER_up"};
   TTreeReaderValue<Double_t>    drj1l_JER_down  = {fReader, "drj1l_JER_down"};
   TTreeReaderValue<Double_t>    drj1l_f  = {fReader, "drj1l_f"};
   TTreeReaderValue<Double_t>    drj1l_new_f  = {fReader, "drj1l_new_f"};
   TTreeReaderValue<Double_t>    drj1l_JEC_up_f  = {fReader, "drj1l_JEC_up_f"};
   TTreeReaderValue<Double_t>    drj1l_JEC_down_f  = {fReader, "drj1l_JEC_down_f"};
   TTreeReaderValue<Double_t>    drj1l_JER_up_f  = {fReader, "drj1l_JER_up_f"};
   TTreeReaderValue<Double_t>    drj1l_JER_down_f  = {fReader, "drj1l_JER_down_f"};
   TTreeReaderValue<Double_t>    drj2l  = {fReader, "drj2l"};
   TTreeReaderValue<Double_t>    drj2l_new  = {fReader, "drj2l_new"};
   TTreeReaderValue<Double_t>    drj2l_JEC_up  = {fReader, "drj2l_JEC_up"};
   TTreeReaderValue<Double_t>    drj2l_JEC_down  = {fReader, "drj2l_JEC_down"};
   TTreeReaderValue<Double_t>    drj2l_JER_up  = {fReader, "drj2l_JER_up"};
   TTreeReaderValue<Double_t>    drj2l_JER_down  = {fReader, "drj2l_JER_down"};
   TTreeReaderValue<Double_t>    drj2l_f  = {fReader, "drj2l_f"};
   TTreeReaderValue<Double_t>    drj2l_new_f  = {fReader, "drj2l_new_f"};
   TTreeReaderValue<Double_t>    drj2l_JEC_up_f  = {fReader, "drj2l_JEC_up_f"};
   TTreeReaderValue<Double_t>    drj2l_JEC_down_f  = {fReader, "drj2l_JEC_down_f"};
   TTreeReaderValue<Double_t>    drj2l_JER_up_f  = {fReader, "drj2l_JER_up_f"};
   TTreeReaderValue<Double_t>    drj2l_JER_down_f  = {fReader, "drj2l_JER_down_f"};
   TTreeReaderValue<Double_t>    Mjj  = {fReader, "Mjj"};
   TTreeReaderValue<Double_t>    Mjj_new  = {fReader, "Mjj_new"};
   TTreeReaderValue<Double_t>    Mjj_JEC_up  = {fReader, "Mjj_JEC_up"};
   TTreeReaderValue<Double_t>    Mjj_JEC_down  = {fReader, "Mjj_JEC_down"};
   TTreeReaderValue<Double_t>    Mjj_JER_up  = {fReader, "Mjj_JER_up"};
   TTreeReaderValue<Double_t>    Mjj_JER_down  = {fReader, "Mjj_JER_down"};
   TTreeReaderValue<Double_t>    Mjj_f  = {fReader, "Mjj_f"};
   TTreeReaderValue<Double_t>    Mjj_new_f  = {fReader, "Mjj_new_f"};
   TTreeReaderValue<Double_t>    Mjj_JEC_up_f  = {fReader, "Mjj_JEC_up_f"};
   TTreeReaderValue<Double_t>    Mjj_JEC_down_f  = {fReader, "Mjj_JEC_down_f"};
   TTreeReaderValue<Double_t>    Mjj_JER_up_f  = {fReader, "Mjj_JER_up_f"};
   TTreeReaderValue<Double_t>    Mjj_JER_down_f  = {fReader, "Mjj_JER_down_f"};
   TTreeReaderValue<Double_t>    deltaeta  = {fReader, "deltaeta"};
   TTreeReaderValue<Double_t>    deltaeta_new  = {fReader, "deltaeta_new"};
   TTreeReaderValue<Double_t>    deltaeta_JEC_up  = {fReader, "deltaeta_JEC_up"};
   TTreeReaderValue<Double_t>    deltaeta_JEC_down  = {fReader, "deltaeta_JEC_down"};
   TTreeReaderValue<Double_t>    deltaeta_JER_up  = {fReader, "deltaeta_JER_up"};
   TTreeReaderValue<Double_t>    deltaeta_JER_down  = {fReader, "deltaeta_JER_down"};
   TTreeReaderValue<Double_t>    deltaeta_f  = {fReader, "deltaeta_f"};
   TTreeReaderValue<Double_t>    deltaeta_new_f  = {fReader, "deltaeta_new_f"};
   TTreeReaderValue<Double_t>    deltaeta_JEC_up_f  = {fReader, "deltaeta_JEC_up_f"};
   TTreeReaderValue<Double_t>    deltaeta_JEC_down_f  = {fReader, "deltaeta_JEC_down_f"};
   TTreeReaderValue<Double_t>    deltaeta_JER_up_f  = {fReader, "deltaeta_JER_up_f"};
   TTreeReaderValue<Double_t>    deltaeta_JER_down_f  = {fReader, "deltaeta_JER_down_f"};
   TTreeReaderValue<Double_t>    zepp  = {fReader, "zepp"};
   TTreeReaderValue<Double_t>    zepp_new  = {fReader, "zepp_new"};
   TTreeReaderValue<Double_t>    zepp_JEC_up  = {fReader, "zepp_JEC_up"};
   TTreeReaderValue<Double_t>    zepp_JEC_down  = {fReader, "zepp_JEC_down"};
   TTreeReaderValue<Double_t>    zepp_JER_up  = {fReader, "zepp_JER_up"};
   TTreeReaderValue<Double_t>    zepp_JER_down  = {fReader, "zepp_JER_down"};
   TTreeReaderValue<Double_t>    zepp_f  = {fReader, "zepp_f"};
   TTreeReaderValue<Double_t>    zepp_new_f  = {fReader, "zepp_new_f"};
   TTreeReaderValue<Double_t>    zepp_JEC_up_f  = {fReader, "zepp_JEC_up_f"};
   TTreeReaderValue<Double_t>    zepp_JEC_down_f  = {fReader, "zepp_JEC_down_f"};
   TTreeReaderValue<Double_t>    zepp_JER_up_f  = {fReader, "zepp_JER_up_f"};
   TTreeReaderValue<Double_t>    zepp_JER_down_f  = {fReader, "zepp_JER_down_f"};
   TTreeReaderValue<Double_t>    ptlep1  = {fReader, "ptlep1"};
   TTreeReaderValue<Double_t>    etalep1  = {fReader, "etalep1"};
   TTreeReaderValue<Double_t>    philep1  = {fReader, "philep1"};
   TTreeReaderValue<Double_t>    energylep1  = {fReader, "energylep1"};
   TTreeReaderValue<Double_t>    j1metPhi  = {fReader, "j1metPhi"};
   TTreeReaderValue<Double_t>    j1metPhi_new  = {fReader, "j1metPhi_new"};
   TTreeReaderValue<Double_t>    j1metPhi_JEC_up  = {fReader, "j1metPhi_JEC_up"};
   TTreeReaderValue<Double_t>    j1metPhi_JEC_down  = {fReader, "j1metPhi_JEC_down"};
   TTreeReaderValue<Double_t>    j1metPhi_JER_up  = {fReader, "j1metPhi_JER_up"};
   TTreeReaderValue<Double_t>    j1metPhi_JER_down  = {fReader, "j1metPhi_JER_down"};
   TTreeReaderValue<Double_t>    j1metPhi_f  = {fReader, "j1metPhi_f"};
   TTreeReaderValue<Double_t>    j1metPhi_new_f  = {fReader, "j1metPhi_new_f"};
   TTreeReaderValue<Double_t>    j1metPhi_JEC_up_f  = {fReader, "j1metPhi_JEC_up_f"};
   TTreeReaderValue<Double_t>    j1metPhi_JEC_down_f  = {fReader, "j1metPhi_JEC_down_f"};
   TTreeReaderValue<Double_t>    j1metPhi_JER_up_f  = {fReader, "j1metPhi_JER_up_f"};
   TTreeReaderValue<Double_t>    j1metPhi_JER_down_f  = {fReader, "j1metPhi_JER_down_f"};
   TTreeReaderValue<Double_t>    j2metPhi  = {fReader, "j2metPhi"};
   TTreeReaderValue<Double_t>    j2metPhi_new  = {fReader, "j2metPhi_new"};
   TTreeReaderValue<Double_t>    j2metPhi_JEC_up  = {fReader, "j2metPhi_JEC_up"};
   TTreeReaderValue<Double_t>    j2metPhi_JEC_down  = {fReader, "j2metPhi_JEC_down"};
   TTreeReaderValue<Double_t>    j2metPhi_JER_up  = {fReader, "j2metPhi_JER_up"};
   TTreeReaderValue<Double_t>    j2metPhi_JER_down  = {fReader, "j2metPhi_JER_down"};
   TTreeReaderValue<Double_t>    j2metPhi_f  = {fReader, "j2metPhi_f"};
   TTreeReaderValue<Double_t>    j2metPhi_new_f  = {fReader, "j2metPhi_new_f"};
   TTreeReaderValue<Double_t>    j2metPhi_JEC_up_f  = {fReader, "j2metPhi_JEC_up_f"};
   TTreeReaderValue<Double_t>    j2metPhi_JEC_down_f  = {fReader, "j2metPhi_JEC_down_f"};
   TTreeReaderValue<Double_t>    j2metPhi_JER_up_f  = {fReader, "j2metPhi_JER_up_f"};
   TTreeReaderValue<Double_t>    j2metPhi_JER_down_f  = {fReader, "j2metPhi_JER_down_f"};
   TTreeReaderValue<Double_t>    Dphiwajj  = {fReader, "Dphiwajj"};
   TTreeReaderValue<Double_t>    Dphiwajj_f  = {fReader, "Dphiwajj_f"};
   TTreeReaderValue<Double_t>    Dphiwajj_new  = {fReader, "Dphiwajj_new"};
   TTreeReaderValue<Double_t>    Dphiwajj_JEC_up  = {fReader, "Dphiwajj_JEC_up"};
   TTreeReaderValue<Double_t>    Dphiwajj_JEC_down  = {fReader, "Dphiwajj_JEC_down"};
   TTreeReaderValue<Double_t>    Dphiwajj_JER_up  = {fReader, "Dphiwajj_JER_up"};
   TTreeReaderValue<Double_t>    Dphiwajj_JER_down  = {fReader, "Dphiwajj_JER_down"};
   TTreeReaderValue<Double_t>    METraw_et  = {fReader, "METraw_et"};
   TTreeReaderValue<Double_t>    METraw_phi  = {fReader, "METraw_phi"};
   TTreeReaderValue<Double_t>    METraw_sumEt  = {fReader, "METraw_sumEt"};
   TTreeReaderValue<Double_t>    genMET  = {fReader, "genMET"};
   TTreeReaderValue<Double_t>    MET_et  = {fReader, "MET_et"};
   TTreeReaderValue<Double_t>    MET_et_new  = {fReader, "MET_et_new"};
   TTreeReaderValue<Double_t>    MET_et_JEC_up  = {fReader, "MET_et_JEC_up"};
   TTreeReaderValue<Double_t>    MET_et_JEC_down  = {fReader, "MET_et_JEC_down"};
   TTreeReaderValue<Double_t>    MET_et_JER_up  = {fReader, "MET_et_JER_up"};
   TTreeReaderValue<Double_t>    MET_et_JER_down  = {fReader, "MET_et_JER_down"};
   TTreeReaderValue<Double_t>    MET_phi  = {fReader, "MET_phi"};
   TTreeReaderValue<Double_t>    MET_phi_new  = {fReader, "MET_phi_new"};
   TTreeReaderValue<Double_t>    MET_phi_JEC_up  = {fReader, "MET_phi_JEC_up"};
   TTreeReaderValue<Double_t>    MET_phi_JEC_down  = {fReader, "MET_phi_JEC_down"};
   TTreeReaderValue<Double_t>    MET_phi_JER_up  = {fReader, "MET_phi_JER_up"};
   TTreeReaderValue<Double_t>    MET_phi_JER_down  = {fReader, "MET_phi_JER_down"};
   TTreeReaderValue<Int_t>    HLT_Ele1  = {fReader, "HLT_Ele1"};
   TTreeReaderValue<Int_t>    HLT_Ele2  = {fReader, "HLT_Ele2"};
   TTreeReaderValue<Int_t>    HLT_Mu1  = {fReader, "HLT_Mu1"};
   TTreeReaderValue<Int_t>    HLT_Mu2  = {fReader, "HLT_Mu2"};
   TTreeReaderValue<Int_t>    HLT_Mu3  = {fReader, "HLT_Mu3"};
   TTreeReaderValue<Double_t>    lumiWeight  = {fReader, "lumiWeight"};
   TTreeReaderValue<Double_t>    pileupWeight  = {fReader, "pileupWeight"};
   TTreeReaderValue<Bool_t>    _passecalBadCalibFilterUpdate  = {fReader, "_passecalBadCalibFilterUpdate"};
   Long64_t maxEntries = fReader.GetEntries(false);
   cout << "Number of events to be analyzed : " << maxEntries << std::endl;
   while (fReader.Next()) {

      if (jentry % 10000 == 0){ 
         int ks = floor(50.*jentry/maxEntries);
         string s1(ks,'>');
         string s2(50-ks,'-');
         cout<<"processing : ["<<"\033[32m"<<s1<<"\033[0m"<<s2<<"]  "<<"\033[33m"<<100.*jentry/maxEntries<<"%  "<<"p_event: "<<p_event<<" n_event: "<<n_event<<"\033[0m"<<endl;
         }

      jentry++;

      if(*theWeight>0) p_event++;
      if(*theWeight<0) n_event++;

      if (!(*hasphoton) == 1) continue;
      // apply selection
      if(m_type == "data" || m_type == "mc" || m_type == "fakelepton"){
         fill_Mjj                 = (*Mjj_new);
         fill_Mjj_JEC_up          = (*Mjj_JEC_up);
         fill_Mjj_JEC_down        = (*Mjj_JEC_down);
         fill_Mjj_JER_up          = (*Mjj_JER_up);
         fill_Mjj_JER_down        = (*Mjj_JER_down);

         fill_nVtx                = (*nVtx);
         fill_jet1pt              = (*jet1pt_new);
         fill_jet1eta             = (*jet1eta_new);
         fill_jet1pt_JEC_up       = (*jet1pt_JEC_up);
         fill_jet1eta_JEC_up      = (*jet1eta_JEC_up);
         fill_jet1pt_JEC_down     = (*jet1pt_JEC_down);
         fill_jet1eta_JEC_down    = (*jet1eta_JEC_down);
         fill_jet1pt_JER_up       = (*jet1pt_JER_up);
         fill_jet1eta_JER_up      = (*jet1eta_JER_up);
         fill_jet1pt_JER_down     = (*jet1pt_JER_down);
         fill_jet1eta_JER_down    = (*jet1eta_JER_down);

         fill_jet1pf              = (*jet1pf_new);
         fill_jet1pf_JEC_up       = (*jet1pf_JEC_up);
         fill_jet1pf_JEC_down     = (*jet1pf_JEC_down);
         fill_jet1pf_JER_up       = (*jet1pf_JER_up);
         fill_jet1pf_JER_down     = (*jet1pf_JER_down);

         fill_jet2pt              = (*jet2pt_new);
         fill_jet2eta             = (*jet2eta_new);
         fill_jet2pt_JEC_up       = (*jet2pt_JEC_up);
         fill_jet2eta_JEC_up      = (*jet2eta_JEC_up);
         fill_jet2pt_JEC_down     = (*jet2pt_JEC_down);
         fill_jet2eta_JEC_down    = (*jet2eta_JEC_down);
         fill_jet2pt_JER_up       = (*jet2pt_JER_up);
         fill_jet2eta_JER_up      = (*jet2eta_JER_up);
         fill_jet2pt_JER_down     = (*jet2pt_JER_down);
         fill_jet2eta_JER_down    = (*jet2eta_JER_down);

         fill_jet2pf              = (*jet2pf_new);
         fill_jet2pf_JEC_up       = (*jet2pf_JEC_up);
         fill_jet2pf_JEC_down     = (*jet2pf_JEC_down);
         fill_jet2pf_JER_up       = (*jet2pf_JER_up);
         fill_jet2pf_JER_down     = (*jet2pf_JER_down);

         fill_lep                 = (*lep);
         fill_HLT_muon            = (*HLT_Mu3);
         fill_HLT_electron        = (*HLT_Ele2);
         fill_ptlep1              = (*ptlep1);
         fill_etalep1             = (*etalep1);
         fill_ngoodmus            = (*ngoodmus);
         fill_ngoodeles           = (*ngoodeles);
         fill_nloosemus           = (*nloosemus);
         fill_nlooseeles          = (*nlooseeles);
         fill_photonhaspixelseed  = (*photonhaspixelseed);
         fill_photonet            = (*photonet);
         fill_MET_et              = (*MET_et_new);
         fill_MET_et_JEC_up       = (*MET_et_JEC_up);
         fill_MET_et_JEC_down     = (*MET_et_JEC_down);
         fill_MET_et_JER_up       = (*MET_et_JER_up);
         fill_MET_et_JER_down     = (*MET_et_JER_down);

         fill_mtVlepJECnew        = (*mtVlepJECnew_new);
         fill_mtVlepJECnew_JEC_up = (*mtVlepJECnew_JEC_up);
         fill_mtVlepJECnew_JEC_down = (*mtVlepJECnew_JEC_down);
         fill_mtVlepJECnew_JER_up = (*mtVlepJECnew_JER_up);
         fill_mtVlepJECnew_JER_down = (*mtVlepJECnew_JER_down);

         fill_drla                = (*drla);
         fill_drj1l               = (*drj1l_new);
         fill_drj2l               = (*drj2l_new);
         fill_drj1a               = (*drj1a_new);
         fill_drj2a               = (*drj2a_new);

         fill_drj1l_JEC_up        = (*drj1l_JEC_up);
         fill_drj1l_JEC_down      = (*drj1l_JEC_down);
         fill_drj1l_JER_up        = (*drj1l_JER_up);
         fill_drj1l_JER_down      = (*drj1l_JER_down);

         fill_drj2l_JEC_up        = (*drj2l_JEC_up);
         fill_drj2l_JEC_down      = (*drj2l_JEC_down);
         fill_drj2l_JER_up        = (*drj2l_JER_up);
         fill_drj2l_JER_down      = (*drj2l_JER_down);

         fill_drj1a_JEC_up        = (*drj1a_JEC_up);
         fill_drj1a_JEC_down      = (*drj1a_JEC_down);
         fill_drj1a_JER_up        = (*drj1a_JER_up);
         fill_drj1a_JER_down      = (*drj1a_JER_down);

         fill_drj2a_JEC_up        = (*drj2a_JEC_up);
         fill_drj2a_JEC_down      = (*drj2a_JEC_down);
         fill_drj2a_JER_up        = (*drj2a_JER_up);
         fill_drj2a_JER_down      = (*drj2a_JER_down);

         fill_j1metPhi            = (*j1metPhi_new);
         fill_j2metPhi            = (*j2metPhi_new);

         fill_j1metPhi_JEC_up     = (*j1metPhi_JEC_up);
         fill_j1metPhi_JEC_down   = (*j1metPhi_JEC_down);
         fill_j1metPhi_JER_up     = (*j1metPhi_JER_up);
         fill_j1metPhi_JER_down   = (*j1metPhi_JER_down);

         fill_j2metPhi_JEC_up     = (*j2metPhi_JEC_up);
         fill_j2metPhi_JEC_down   = (*j2metPhi_JEC_down);
         fill_j2metPhi_JER_up     = (*j2metPhi_JER_up);
         fill_j2metPhi_JER_down   = (*j2metPhi_JER_down);

         fill_jet1deepcsv         = (*jet1deepcsv_probb_new + *jet1deepcsv_probbb_new);
         fill_jet2deepcsv         = (*jet2deepcsv_probb_new + *jet2deepcsv_probbb_new);

         fill_jet1deepcsv_JEC_up  = (*jet1deepcsv_probb_JEC_up + *jet1deepcsv_probbb_JEC_up);
         fill_jet1deepcsv_JEC_down= (*jet1deepcsv_probb_JEC_down + *jet1deepcsv_probbb_JEC_down);
         fill_jet1deepcsv_JER_up  = (*jet1deepcsv_probb_JER_up + *jet1deepcsv_probbb_JER_up);
         fill_jet1deepcsv_JER_down= (*jet1deepcsv_probb_JER_down + *jet1deepcsv_probbb_JER_down);

         fill_jet2deepcsv_JEC_up  = (*jet2deepcsv_probb_JEC_up + *jet2deepcsv_probbb_JEC_up);
         fill_jet2deepcsv_JEC_down= (*jet2deepcsv_probb_JEC_down + *jet2deepcsv_probbb_JEC_down);
         fill_jet2deepcsv_JER_up  = (*jet2deepcsv_probb_JER_up + *jet2deepcsv_probbb_JER_up);
         fill_jet2deepcsv_JER_down= (*jet2deepcsv_probb_JER_down + *jet2deepcsv_probbb_JER_down);

         fill_photonsceta         = (*photonsceta);
         fill_ptVlepJEC           = (*ptVlepJEC_new);
         fill_ptVlepJEC_JEC_up    = (*ptVlepJEC_JEC_up);
         fill_ptVlepJEC_JEC_down  = (*ptVlepJEC_JEC_down);
         fill_ptVlepJEC_JER_up    = (*ptVlepJEC_JER_up);
         fill_ptVlepJEC_JER_down  = (*ptVlepJEC_JER_down);

         fill_photoneta           = (*photoneta);
         fill_zepp                = (*zepp_new);
         fill_zepp_JEC_up         = (*zepp_JEC_up);
         fill_zepp_JEC_down       = (*zepp_JEC_down);
         fill_zepp_JER_up         = (*zepp_JER_up);
         fill_zepp_JER_down       = (*zepp_JER_down);

         fill_deltaeta            = (*deltaeta_new);
         fill_deltaeta_JEC_up     = (*deltaeta_JEC_up);
         fill_deltaeta_JEC_down   = (*deltaeta_JEC_down);
         fill_deltaeta_JER_up     = (*deltaeta_JER_up);
         fill_deltaeta_JER_down   = (*deltaeta_JER_down);

         TLorentzVector vp4;
         vp4.SetPtEtaPhiM(*ptVlepJEC_new, *yVlepJEC_new, *phiVlepJEC_new, *massVlepJEC_new);
         TLorentzVector vp4_jec_up;
         vp4_jec_up.SetPtEtaPhiM(*ptVlepJEC_JEC_up, *yVlepJEC_JEC_up, *phiVlepJEC_JEC_up, *massVlepJEC_JEC_up);
         TLorentzVector vp4_jec_down;
         vp4_jec_down.SetPtEtaPhiM(*ptVlepJEC_JEC_down, *yVlepJEC_JEC_down, *phiVlepJEC_JEC_down, *massVlepJEC_JEC_down);
         TLorentzVector vp4_jer_up;
         vp4_jer_up.SetPtEtaPhiM(*ptVlepJEC_JER_up, *yVlepJEC_JER_up, *phiVlepJEC_JER_up, *massVlepJEC_JER_up);
         TLorentzVector vp4_jer_down;
         vp4_jer_down.SetPtEtaPhiM(*ptVlepJEC_JER_down, *yVlepJEC_JER_down, *phiVlepJEC_JER_down, *massVlepJEC_JER_down);

         TLorentzVector j1p4;
         j1p4.SetPtEtaPhiE(*jet1pt_new, *jet1eta_new, *jet1phi_new, *jet1e_new);
         TLorentzVector j1p4_jec_up;
         j1p4_jec_up.SetPtEtaPhiE(*jet1pt_JEC_up, *jet1eta_JEC_up, *jet1phi_JEC_up, *jet1e_JEC_up);
         TLorentzVector j1p4_jec_down;
         j1p4_jec_down.SetPtEtaPhiE(*jet1pt_JEC_down, *jet1eta_JEC_down, *jet1phi_JEC_down, *jet1e_JEC_down);
         TLorentzVector j1p4_jer_up;
         j1p4_jer_up.SetPtEtaPhiE(*jet1pt_JER_up, *jet1eta_JER_up, *jet1phi_JER_up, *jet1e_JER_up);
         TLorentzVector j1p4_jer_down;
         j1p4_jer_down.SetPtEtaPhiE(*jet1pt_JER_down, *jet1eta_JER_down, *jet1phi_JER_down, *jet1e_JER_down);

         TLorentzVector j2p4;
         j2p4.SetPtEtaPhiE(*jet2pt_new, *jet2eta_new, *jet2phi_new, *jet2e_new);
         TLorentzVector j2p4_jec_up;
         j2p4_jec_up.SetPtEtaPhiE(*jet2pt_JEC_up, *jet2eta_JEC_up, *jet2phi_JEC_up, *jet2e_JEC_up);
         TLorentzVector j2p4_jec_down;
         j2p4_jec_down.SetPtEtaPhiE(*jet2pt_JEC_down, *jet2eta_JEC_down, *jet2phi_JEC_down, *jet2e_JEC_down);
         TLorentzVector j2p4_jer_up;
         j2p4_jer_up.SetPtEtaPhiE(*jet2pt_JER_up, *jet2eta_JER_up, *jet2phi_JER_up, *jet2e_JER_up);
         TLorentzVector j2p4_jer_down;
         j2p4_jer_down.SetPtEtaPhiE(*jet2pt_JER_down, *jet2eta_JER_down, *jet2phi_JER_down, *jet2e_JER_down);

         TLorentzVector photonp42;
         photonp42.SetPtEtaPhiE(*photonet, *photoneta, *photonphi, *photone);

         fill_Dphiwajj            = (*Dphiwajj_new);

         fill_Dphiwajj_JEC_up = fabs((vp4_jec_up + photonp42).Phi() - (j1p4_jec_up + j2p4_jec_up).Phi());
         //double Pi =3.1415926;
         if (fill_Dphiwajj_JEC_up > Pi) {
            fill_Dphiwajj_JEC_up = 2.0 * Pi - fill_Dphiwajj_JEC_up;
         }

         fill_Dphiwajj_JEC_down = fabs((vp4_jec_down + photonp42).Phi() - (j1p4_jec_down + j2p4_jec_down).Phi());
         if (fill_Dphiwajj_JEC_down > Pi) {
            fill_Dphiwajj_JEC_down = 2.0 * Pi - fill_Dphiwajj_JEC_down;
         }

         fill_Dphiwajj_JER_up = fabs((vp4_jer_up + photonp42).Phi() - (j1p4_jer_up + j2p4_jer_up).Phi());
         if (fill_Dphiwajj_JER_up > Pi) {
            fill_Dphiwajj_JER_up = 2.0 * Pi - fill_Dphiwajj_JER_up;
         }

         fill_Dphiwajj_JER_down = fabs((vp4_jer_down + photonp42).Phi() - (j1p4_jer_down + j2p4_jer_down).Phi());
         if (fill_Dphiwajj_JER_down > Pi) {
            fill_Dphiwajj_JER_down = 2.0 * Pi - fill_Dphiwajj_JER_down;
         }

         fill_Mla                 = (*Mla);
         fill_Mva                 = (*Mva);
         fill_Mva_JEC_up          = (photonp42 + vp4_jec_up).M();
//cout<<"center: "<< *photonet<<" "<<*photoneta<<" "<<*photonphi<< " "<<*photone<<" "<<*ptVlepJEC_new<<" "<<*yVlepJEC_new<<" "<<*phiVlepJEC_new<<" "<<*massVlepJEC_new<< " "<<(vp4).M()<<" "<<fill_Mva<<endl;
//cout<<"JEC_up: "<< *photonet<<" "<<*photoneta<<" "<<*photonphi<< " "<<*photone<<" "<<*ptVlepJEC_JEC_up<<" "<<*yVlepJEC_JEC_up<<" "<<*phiVlepJEC_JEC_up<<" "<<*massVlepJEC_JEC_up<< " "<<(vp4_jec_up).M()<<" "<<fill_Mva_JEC_up<<endl;


         fill_Mva_JEC_down        = (photonp42 + vp4_jec_down).M();
         fill_Mva_JER_up          = (photonp42 + vp4_jer_up).M();
         fill_Mva_JER_down        = (photonp42 + vp4_jer_down).M();

      }

      else if(m_type == "fakephoton" || m_type == "doublefake"){
         fill_Mjj                 = (*Mjj_new_f);
         fill_Mjj_JEC_up          = (*Mjj_JEC_up_f);
         fill_Mjj_JEC_down        = (*Mjj_JEC_down_f);
         fill_Mjj_JER_up          = (*Mjj_JER_up_f);
         fill_Mjj_JER_down        = (*Mjj_JER_down_f);

         fill_nVtx                = (*nVtx);
         fill_jet1pt              = (*jet1pt_new_f);
         fill_jet1eta             = (*jet1eta_new_f);
         fill_jet1pt_JEC_up       = (*jet1pt_JEC_up_f);
         fill_jet1eta_JEC_up      = (*jet1eta_JEC_up_f);
         fill_jet1pt_JEC_down     = (*jet1pt_JEC_down_f);
         fill_jet1eta_JEC_down    = (*jet1eta_JEC_down_f);
         fill_jet1pt_JER_up       = (*jet1pt_JER_up_f);
         fill_jet1eta_JER_up      = (*jet1eta_JER_up_f);
         fill_jet1pt_JER_down     = (*jet1pt_JER_down_f);
         fill_jet1eta_JER_down    = (*jet1eta_JER_down_f);

         fill_jet1pf              = (*jet1pf_new_f);
         fill_jet1pf_JEC_up       = (*jet1pf_JEC_up_f);
         fill_jet1pf_JEC_down     = (*jet1pf_JEC_down_f);
         fill_jet1pf_JER_up       = (*jet1pf_JER_up_f);
         fill_jet1pf_JER_down     = (*jet1pf_JER_down_f);


         fill_jet2pt              = (*jet2pt_new_f);
         fill_jet2eta             = (*jet2eta_new_f);
         fill_jet2pt_JEC_up       = (*jet2pt_JEC_up_f);
         fill_jet2eta_JEC_up      = (*jet2eta_JEC_up_f);
         fill_jet2pt_JEC_down     = (*jet2pt_JEC_down_f);
         fill_jet2eta_JEC_down    = (*jet2eta_JEC_down_f);
         fill_jet2pt_JER_up       = (*jet2pt_JER_up_f);
         fill_jet2eta_JER_up      = (*jet2eta_JER_up_f);
         fill_jet2pt_JER_down     = (*jet2pt_JER_down_f);
         fill_jet2eta_JER_down    = (*jet2eta_JER_down_f);

         fill_jet2pf              = (*jet2pf_new_f);
         fill_jet2pf_JEC_up       = (*jet2pf_JEC_up_f);
         fill_jet2pf_JEC_down     = (*jet2pf_JEC_down_f);
         fill_jet2pf_JER_up       = (*jet2pf_JER_up_f);
         fill_jet2pf_JER_down     = (*jet2pf_JER_down_f);

         fill_lep                 = (*lep);
         fill_HLT_muon            = (*HLT_Mu3);
         fill_HLT_electron        = (*HLT_Ele2);
         fill_ptlep1              = (*ptlep1);
         fill_etalep1             = (*etalep1);
         fill_ngoodmus            = (*ngoodmus);
         fill_ngoodeles           = (*ngoodeles);
         fill_nloosemus           = (*nloosemus);
         fill_nlooseeles          = (*nlooseeles);
         fill_photonhaspixelseed  = (*photonhaspixelseed_f);
         fill_photonet            = (*photonet_f);
         fill_MET_et              = (*MET_et_new);
         fill_MET_et              = (*MET_et_new);
         fill_MET_et_JEC_up       = (*MET_et_JEC_up);
         fill_MET_et_JEC_down     = (*MET_et_JEC_down);
         fill_MET_et_JER_up       = (*MET_et_JER_up);
         fill_MET_et_JER_down     = (*MET_et_JER_down);

         fill_mtVlepJECnew        = (*mtVlepJECnew_new);
         fill_mtVlepJECnew_JEC_up = (*mtVlepJECnew_JEC_up);
         fill_mtVlepJECnew_JEC_down = (*mtVlepJECnew_JEC_down);
         fill_mtVlepJECnew_JER_up = (*mtVlepJECnew_JER_up);
         fill_mtVlepJECnew_JER_down = (*mtVlepJECnew_JER_down);

         fill_drla                = (*drla_f);
         fill_drj1l               = (*drj1l_new_f);
         fill_drj2l               = (*drj2l_new_f);
         fill_drj1a               = (*drj1a_new_f);
         fill_drj2a               = (*drj2a_new_f);

         fill_drj1l_JEC_up        = (*drj1l_JEC_up_f);
         fill_drj1l_JEC_down      = (*drj1l_JEC_down_f);
         fill_drj1l_JER_up        = (*drj1l_JER_up_f);
         fill_drj1l_JER_down      = (*drj1l_JER_down_f);

         fill_drj2l_JEC_up        = (*drj2l_JEC_up_f);
         fill_drj2l_JEC_down      = (*drj2l_JEC_down_f);
         fill_drj2l_JER_up        = (*drj2l_JER_up_f);
         fill_drj2l_JER_down      = (*drj2l_JER_down_f);

         fill_drj1a_JEC_up        = (*drj1a_JEC_up_f);
         fill_drj1a_JEC_down      = (*drj1a_JEC_down_f);
         fill_drj1a_JER_up        = (*drj1a_JER_up_f);
         fill_drj1a_JER_down      = (*drj1a_JER_down_f);

         fill_drj2a_JEC_up        = (*drj2a_JEC_up_f);
         fill_drj2a_JEC_down      = (*drj2a_JEC_down_f);
         fill_drj2a_JER_up        = (*drj2a_JER_up_f);
         fill_drj2a_JER_down      = (*drj2a_JER_down_f);


         fill_j1metPhi            = (*j1metPhi_new_f);
         fill_j2metPhi            = (*j2metPhi_new_f);

         fill_j1metPhi_JEC_up     = (*j1metPhi_JEC_up_f);
         fill_j1metPhi_JEC_down   = (*j1metPhi_JEC_down_f);
         fill_j1metPhi_JER_up     = (*j1metPhi_JER_up_f);
         fill_j1metPhi_JER_down   = (*j1metPhi_JER_down_f);

         fill_j2metPhi_JEC_up     = (*j2metPhi_JEC_up_f);
         fill_j2metPhi_JEC_down   = (*j2metPhi_JEC_down_f);
         fill_j2metPhi_JER_up     = (*j2metPhi_JER_up_f);
         fill_j2metPhi_JER_down   = (*j2metPhi_JER_down_f);


         fill_jet1deepcsv         = (*jet1deepcsv_probb_new_f + *jet1deepcsv_probbb_new_f);
         fill_jet2deepcsv         = (*jet2deepcsv_probb_new_f + *jet2deepcsv_probbb_new_f);

         fill_jet1deepcsv_JEC_up  = (*jet1deepcsv_probb_JEC_up_f + *jet1deepcsv_probbb_JEC_up_f);
         fill_jet1deepcsv_JEC_down= (*jet1deepcsv_probb_JEC_down_f + *jet1deepcsv_probbb_JEC_down_f);
         fill_jet1deepcsv_JER_up  = (*jet1deepcsv_probb_JER_up_f + *jet1deepcsv_probbb_JER_up_f);
         fill_jet1deepcsv_JER_down= (*jet1deepcsv_probb_JER_down_f + *jet1deepcsv_probbb_JER_down_f);

         fill_jet2deepcsv_JEC_up  = (*jet2deepcsv_probb_JEC_up_f + *jet2deepcsv_probbb_JEC_up_f);
         fill_jet2deepcsv_JEC_down= (*jet2deepcsv_probb_JEC_down_f + *jet2deepcsv_probbb_JEC_down_f);
         fill_jet2deepcsv_JER_up  = (*jet2deepcsv_probb_JER_up_f + *jet2deepcsv_probbb_JER_up_f);
         fill_jet2deepcsv_JER_down= (*jet2deepcsv_probb_JER_down_f + *jet2deepcsv_probbb_JER_down_f);


         fill_photonsceta         = (*photonsceta_f);
         fill_ptVlepJEC           = (*ptVlepJEC_new);
         fill_ptVlepJEC_JEC_up    = (*ptVlepJEC_JEC_up);
         fill_ptVlepJEC_JEC_down  = (*ptVlepJEC_JEC_down);
         fill_ptVlepJEC_JER_up    = (*ptVlepJEC_JER_up);
         fill_ptVlepJEC_JER_down  = (*ptVlepJEC_JER_down);

         fill_photoneta           = (*photoneta_f);
         fill_zepp                = (*zepp_new_f);
         fill_zepp_JEC_up         = (*zepp_JEC_up_f);
         fill_zepp_JEC_down       = (*zepp_JEC_down_f);
         fill_zepp_JER_up         = (*zepp_JER_up_f);
         fill_zepp_JER_down       = (*zepp_JER_down_f);


         fill_deltaeta            = (*deltaeta_new_f);
         fill_deltaeta_JEC_up     = (*deltaeta_JEC_up_f);
         fill_deltaeta_JEC_down   = (*deltaeta_JEC_down_f);
         fill_deltaeta_JER_up     = (*deltaeta_JER_up_f);
         fill_deltaeta_JER_down   = (*deltaeta_JER_down_f);

         TLorentzVector vp4;
         vp4.SetPtEtaPhiM(*ptVlepJEC_new, *yVlepJEC_new, *phiVlepJEC_new, *massVlepJEC_new);
         TLorentzVector vp4_jec_up;
         vp4_jec_up.SetPtEtaPhiM(*ptVlepJEC_JEC_up, *yVlepJEC_JEC_up, *phiVlepJEC_JEC_up, *massVlepJEC_JEC_up);
         TLorentzVector vp4_jec_down;
         vp4_jec_down.SetPtEtaPhiM(*ptVlepJEC_JEC_down, *yVlepJEC_JEC_down, *phiVlepJEC_JEC_down, *massVlepJEC_JEC_down);
         TLorentzVector vp4_jer_up;
         vp4_jer_up.SetPtEtaPhiM(*ptVlepJEC_JER_up, *yVlepJEC_JER_up, *phiVlepJEC_JER_up, *massVlepJEC_JER_up);
         TLorentzVector vp4_jer_down;    
         vp4_jer_down.SetPtEtaPhiM(*ptVlepJEC_JER_down, *yVlepJEC_JER_down, *phiVlepJEC_JER_down, *massVlepJEC_JER_down);

         TLorentzVector j1p4;
         j1p4.SetPtEtaPhiE(*jet1pt_new_f, *jet1eta_new_f, *jet1phi_new_f, *jet1e_new_f);
         TLorentzVector j1p4_jec_up;
         j1p4_jec_up.SetPtEtaPhiE(*jet1pt_JEC_up_f, *jet1eta_JEC_up_f, *jet1phi_JEC_up_f, *jet1e_JEC_up_f);
         TLorentzVector j1p4_jec_down;
         j1p4_jec_down.SetPtEtaPhiE(*jet1pt_JEC_down_f, *jet1eta_JEC_down_f, *jet1phi_JEC_down_f, *jet1e_JEC_down_f);
         TLorentzVector j1p4_jer_up;
         j1p4_jer_up.SetPtEtaPhiE(*jet1pt_JER_up_f, *jet1eta_JER_up_f, *jet1phi_JER_up_f, *jet1e_JER_up_f);
         TLorentzVector j1p4_jer_down;
         j1p4_jer_down.SetPtEtaPhiE(*jet1pt_JER_down_f, *jet1eta_JER_down_f, *jet1phi_JER_down_f, *jet1e_JER_down_f);


         TLorentzVector j2p4;
         j2p4.SetPtEtaPhiE(*jet2pt_new_f, *jet2eta_new_f, *jet2phi_new_f, *jet2e_new_f);
         TLorentzVector j2p4_jec_up;
         j2p4_jec_up.SetPtEtaPhiE(*jet2pt_JEC_up_f, *jet2eta_JEC_up_f, *jet2phi_JEC_up_f, *jet2e_JEC_up_f);
         TLorentzVector j2p4_jec_down;
         j2p4_jec_down.SetPtEtaPhiE(*jet2pt_JEC_down_f, *jet2eta_JEC_down_f, *jet2phi_JEC_down_f, *jet2e_JEC_down_f);
         TLorentzVector j2p4_jer_up;
         j2p4_jer_up.SetPtEtaPhiE(*jet2pt_JER_up_f, *jet2eta_JER_up_f, *jet2phi_JER_up_f, *jet2e_JER_up_f);
         TLorentzVector j2p4_jer_down;
         j2p4_jer_down.SetPtEtaPhiE(*jet2pt_JER_down_f, *jet2eta_JER_down_f, *jet2phi_JER_down_f, *jet2e_JER_down_f);



         TLorentzVector photonp42;
         photonp42.SetPtEtaPhiE(*photonet_f, *photoneta_f, *photonphi_f, *photone_f);

         fill_Dphiwajj = fabs((vp4 + photonp42).Phi() - (j1p4 + j2p4).Phi());
         double Pi =3.1415926;
         if (fill_Dphiwajj > Pi) {
            fill_Dphiwajj = 2.0 * Pi - fill_Dphiwajj;
         }

         fill_Dphiwajj_JEC_up = fabs((vp4_jec_up + photonp42).Phi() - (j1p4_jec_up + j2p4_jec_up).Phi());
         if (fill_Dphiwajj_JEC_up > Pi) {
            fill_Dphiwajj_JEC_up = 2.0 * Pi - fill_Dphiwajj_JEC_up;
         }

         fill_Dphiwajj_JEC_down = fabs((vp4_jec_down + photonp42).Phi() - (j1p4_jec_down + j2p4_jec_down).Phi());
         if (fill_Dphiwajj_JEC_down > Pi) {
            fill_Dphiwajj_JEC_down = 2.0 * Pi - fill_Dphiwajj_JEC_down;
         }

         fill_Dphiwajj_JER_up = fabs((vp4_jer_up + photonp42).Phi() - (j1p4_jer_up + j2p4_jer_up).Phi());
         if (fill_Dphiwajj_JER_up > Pi) {
            fill_Dphiwajj_JER_up = 2.0 * Pi - fill_Dphiwajj_JER_up;
         }

         fill_Dphiwajj_JER_down = fabs((vp4_jer_down + photonp42).Phi() - (j1p4_jer_down + j2p4_jer_down).Phi());
         if (fill_Dphiwajj_JER_down > Pi) {
            fill_Dphiwajj_JER_down = 2.0 * Pi - fill_Dphiwajj_JER_down;
         }

         fill_Mla                 = (*Mla_f);
         fill_Mva                 = (*Mva_f);
         fill_Mva_JEC_up          = (photonp42 + vp4_jec_up).M();
         fill_Mva_JEC_down        = (photonp42 + vp4_jec_down).M();
         fill_Mva_JER_up          = (photonp42 + vp4_jer_up).M();
         fill_Mva_JER_down        = (photonp42 + vp4_jer_down).M();
      }


      int jet_index[2];
      // gen information
      ResetValue();
	  int pho1_index=0,jet1_index=0,muon1_index=0,ele1_index=0;
      TLorentzVector for_gen_lep1p4;
	  TLorentzVector for_gen_photonp42;
	  TLorentzVector for_gen_vp4;

      for(int i=0;i<6;i++){
         genphoton[i] = genphoton_pt[i]>20 &&( (fabs(genphoton_eta[i])<1.4442) || ( fabs(genphoton_eta[i])<2.5 && fabs(genphoton_eta[i])>1.566 ) );
         genjet[i] = genjet_pt[i]>30 && fabs(genjet_eta[i])<4.7;
         genmuon[i] = genmuon_pt[i]>20 && fabs(genmuon_eta[i])<2.4;
         genele[i] = genelectron_pt[i]>25 && fabs(genelectron_eta[i])<2.5;

         if(genjet[i]) vector_jet.push_back(genjet_pt[i]);
         else vector_jet.push_back(0);

         if(genphoton[i]) vector_photon.push_back(genphoton_pt[i]);
         else vector_photon.push_back(0);

         if(genmuon[i]) vector_muon.push_back(genmuon_pt[i]);
         else vector_muon.push_back(0);

         if(genele[i]) vector_ele.push_back(genelectron_pt[i]);
         else vector_ele.push_back(0);
	
      }


      
      biggest_muon1=max_element(begin(vector_muon),end(vector_muon));
	  muon1_index = distance( begin(vector_muon), biggest_muon1);

      biggest_ele1=max_element(begin(vector_ele),end(vector_ele));
      ele1_index = distance( begin(vector_ele), biggest_ele1);
      if(genmuon_pt[muon1_index]>genelectron_pt[ele1_index]){
         genlep = 13;
         genlep1pt  = genmuon_pt[muon1_index];
         genlep1eta = genmuon_eta[muon1_index];
         genlep1phi = genmuon_phi[muon1_index];
         for_gen_lep1p4.SetPtEtaPhiM(genlep1pt, genlep1eta, genlep1phi, 0.105666);

         for(int for_gen_iphoton=0; for_gen_iphoton<6; for_gen_iphoton++){
            TLorentzVector for_gen_photon_temp;
            for_gen_photon_temp.SetPtEtaPhiM(genphoton_pt[for_gen_iphoton],genphoton_eta[for_gen_iphoton],genphoton_phi[for_gen_iphoton],0);
            if( for_gen_lep1p4.DeltaR(for_gen_photon_temp)<0.1) {for_gen_lep1p4+=for_gen_photon_temp;continue;}
         }
         genlep1pt  = for_gen_lep1p4.Pt();
         genlep1eta = for_gen_lep1p4.Eta();
         genlep1phi = for_gen_lep1p4.Phi();


      }
      else if(genmuon_pt[muon1_index]<=genelectron_pt[ele1_index]){
         genlep = 11;
         genlep1pt  = genelectron_pt[ele1_index];
         genlep1eta = genelectron_eta[ele1_index];
         genlep1phi = genelectron_phi[ele1_index];
         for_gen_lep1p4.SetPtEtaPhiM(genlep1pt, genlep1eta, genlep1phi, 0.00051);

         for(int for_gen_iphoton=0; for_gen_iphoton<6; for_gen_iphoton++){
            TLorentzVector for_gen_photon_temp;
            for_gen_photon_temp.SetPtEtaPhiM(genphoton_pt[for_gen_iphoton],genphoton_eta[for_gen_iphoton],genphoton_phi[for_gen_iphoton],0);
            if( for_gen_lep1p4.DeltaR(for_gen_photon_temp)<0.1) {for_gen_lep1p4+=for_gen_photon_temp;continue;}
         }
         genlep1pt  = for_gen_lep1p4.Pt();
         genlep1eta = for_gen_lep1p4.Eta();
         genlep1phi = for_gen_lep1p4.Phi();

     }

      genyVlep  =(for_gen_lep1p4).Eta();
	  genphiVlep=(for_gen_lep1p4).Phi();
	  genptVlep =(for_gen_lep1p4).Pt();
	  genmassVlep=(for_gen_lep1p4).M();
	  for_gen_vp4.SetPtEtaPhiM(genptVlep,genyVlep,genphiVlep,genmassVlep);

      for(int gen_photon_index = 0; gen_photon_index<6; gen_photon_index++){
         delta_R(genphoton_eta[gen_photon_index],genphoton_phi[gen_photon_index], genlep1eta,genlep1phi) < 0.5;
         //cout<<"drla:  "<<delta_R(genphoton_eta[gen_photon_index],genphoton_phi[gen_photon_index], genlep1eta,genlep1phi)<<endl;
         vector_photon[gen_photon_index] = 0;

      }

      biggest_photon=max_element(begin(vector_photon),end(vector_photon));
      cout<<"pho index:"<<*biggest_photon<<endl;
      if(*biggest_photon>=0){
         pho1_index = distance( begin(vector_photon), biggest_photon);
         //cout<<pho1_index<<" "<<genphoton_pt[pho1_index];
         genphotonet= genphoton_pt[pho1_index];
         genphotoneta= genphoton_eta[pho1_index];
         genphotonphi= genphoton_phi[pho1_index];
         for_gen_photonp42.SetPtEtaPhiM(genphotonet, genphotoneta, genphotonphi,0); 
         genWGmass=(for_gen_vp4+for_gen_photonp42).M();
         gendrla1 = delta_R(genphotoneta,genphotonphi,genlep1eta,genlep1phi);
	
         Int_t jetindexphoton12[2] = {-1,-1};
         for(Int_t i=0; i<6; i++)
         {
            if(genphotonet>0){
               double drtmp1=delta_R(genjet_eta[i], genjet_phi[i], genphotoneta,genphotonphi);
               double drjlep1 = delta_R(genjet_eta[i], genjet_phi[i],genlep1eta,genlep1phi);
               if(genjet_pt[i]>0 && drtmp1>0.5 &&drjlep1>0.5  && jetindexphoton12[0]==-1&&jetindexphoton12[1]==-1) {
                  jetindexphoton12[0] = i;
                  continue;
               }
               if(genjet_pt[i]>0 && drtmp1>0.5 &&drjlep1>0.5  && jetindexphoton12[0]!=-1&&jetindexphoton12[1]==-1) {
                  if(delta_R(genjet_eta[i], genjet_phi[i],genjet_eta[jetindexphoton12[0]], genjet_phi[jetindexphoton12[0]])>0.5){
                     jetindexphoton12[1] = i;
                     continue;
                  }
               }
            }
         }


         jet_index[0] = jetindexphoton12[0];
         jet_index[1] = jetindexphoton12[1];
         if(jetindexphoton12[0]>-1 && jetindexphoton12[1]>-1)
         {
            genjet1pt  = genjet_pt[jetindexphoton12[0]];
            genjet1eta = genjet_eta[jetindexphoton12[0]];
			genjet1phi = genjet_phi[jetindexphoton12[0]];
            genjet1e   = genjet_e[jetindexphoton12[0]];
            genjet2pt  = genjet_pt[jetindexphoton12[1]];
            genjet2eta = genjet_eta[jetindexphoton12[1]];
            genjet2phi = genjet_phi[jetindexphoton12[1]];
            genjet2e   = genjet_e[jetindexphoton12[1]];
            gendrj1a= delta_R(genjet1eta,genjet1phi,genphotoneta,genphotonphi);
            gendrj2a= delta_R(genjet2eta,genjet2phi,genphotoneta,genphotonphi);
            gendrj1l= delta_R(genjet1eta,genjet1phi,genlep1eta,genlep1phi);
            gendrj2l= delta_R(genjet2eta,genjet2phi,genlep1eta,genlep1phi);
			
            TLorentzVector for_gen_j1p4;
            for_gen_j1p4.SetPtEtaPhiE(genjet1pt, genjet1eta, genjet1phi, genjet1e);
			
            TLorentzVector for_gen_j2p4;
            for_gen_j2p4.SetPtEtaPhiE(genjet2pt, genjet2eta, genjet2phi, genjet2e);
			
            TLorentzVector photonp4;
            photonp4.SetPtEtaPhiM(genphotonet, genphotoneta, genphotonphi, 0);
			
			
            genMla = (photonp4+for_gen_vp4).M();
            genMjj=(for_gen_j1p4 + for_gen_j2p4).M();
            genzepp = fabs((for_gen_vp4+photonp4).Rapidity() - (for_gen_j1p4.Rapidity() + for_gen_j2p4.Rapidity())/ 2.0);
            gendetajj = fabs(genjet1eta - genjet2eta);
            gendelta_phi=fabs((for_gen_vp4+photonp4).Phi()-(for_gen_j1p4+for_gen_j2p4).Phi());
			
            if (gendelta_phi>Pi) gendelta_phi=2*Pi-gendelta_phi;
            if (fabs(genjet1phi-genjet2phi)>Pi) gendrjj = sqrt((genjet1eta-genjet2eta)*(genjet1eta-genjet2eta)+(2*Pi-fabs(genjet1phi-genjet2phi))*(2*Pi-fabs(genjet1phi-genjet2phi)));
            else gendrjj = sqrt((genjet1eta-genjet2eta)*(genjet1eta-genjet2eta)+(fabs(genjet1phi-genjet2phi))*(fabs(genjet1phi-genjet2phi)));
		
         }

      }
      
      vector_photon.clear();
      vector_jet.clear();
      vector_muon.clear();
      vector_ele.clear();



      if(m_channel == "muon" &&  !(fill_HLT_muon==1 && abs(fill_lep)==13 && fill_ptlep1>30. && fabs(fill_etalep1)<2.4 && fill_ngoodmus==1 && fill_ngoodeles==0 &&(fill_nloosemus+fill_nlooseeles)==1)) continue;
      if(m_channel == "electron" && !(fill_HLT_electron==1 && abs(fill_lep)==11 && fill_ptlep1>30. && fabs(fill_etalep1)<2.5 && fill_ngoodmus==0 && fill_ngoodeles==1 &&(fill_nloosemus+fill_nlooseeles)==1)) continue;

      // signal region cuts
      muon_cut_signal_region = fill_HLT_muon==1
                 && fill_Mjj>500. 
                 //&& fill_Mva > 100. 
                 && fill_Mla > 30.
                 && fill_deltaeta > 2.5
                 //&& fill_Dphiwajj >1.8
                 //&& fill_zepp < 0.9
                 && fill_jet1pt>40. && fabs(fill_jet1eta)<4.7 && fill_jet2pt>30. && fabs(fill_jet2eta)<4.7
                 && abs(fill_lep)==13 && fill_ptlep1>30. && fabs(fill_etalep1)<2.4
                 && fill_ngoodmus==1 && fill_ngoodeles==0 &&(fill_nloosemus+fill_nlooseeles)==1
                 && fill_photonhaspixelseed==0 && fill_photonet>25. 
                 //&& fill_photonet < 400.
                 && fill_MET_et>30. 
                 //&& fill_mtVlepJECnew>30
                 && fill_drla>0.5 && fill_drj1l>0.5 && fill_drj2l>0.5 && fill_drj1a>0.5 && fill_drj2a>0.5
                 //&& fabs(fill_j1metPhi)>0.5 && fabs(fill_j2metPhi)>0.5
                 && fill_jet1deepcsv < cut_value[1] && fill_jet2deepcsv < cut_value[1]
                 ;

     gen_muon_cut_signal_region = genlep==13 && genlep1pt>30 && fabs(genlep1eta)<2.4
                 && genphotonet>25 
                 //&& genphotonet<400 
                 && fabs(genphotoneta)<2.5 && (fabs(genphotoneta)>1.566 || fabs(genphotoneta)<1.4442)
                 && genjet1pt>40 && genjet2pt>30 
                 && fabs(genjet1eta)<4.7 && fabs(genjet2eta)<4.7
                 && gendrla1>0.5 
                 && gendrj1a>0.5 && gendrj2a>0.5 && gendrj1l>0.5 && gendrj2l>0.5
                 && genMjj >500 && gendetajj>2.5 
                 //&& genWGmass >100 
                 && genMla > 30 
                 //&& gendelta_phi >1.8
                 //&& genzepp <0.9 
                 && *genMET >30
                 ;

      electron_cut_signal_region = fill_HLT_electron==1
                 && fill_Mjj>500.
                 //&& fill_Mva > 100. 
                 && fill_Mla > 30.
                 && fill_deltaeta > 2.5
                 //&& fill_Dphiwajj >1.8
                 //&& fill_zepp < 0.9
                 && fill_jet1pt>40. && fabs(fill_jet1eta)<4.7 && fill_jet2pt>30. && fabs(fill_jet2eta)<4.7
                 && abs(fill_lep)==11 && fill_ptlep1>30. && fabs(fill_etalep1)<2.5
                 && fill_ngoodmus==0 && fill_ngoodeles==1 &&(fill_nloosemus+fill_nlooseeles)==1
                 && fill_photonhaspixelseed==0 && fill_photonet>25. 
                 //&& fill_photonet < 400.
                 && fill_MET_et>30. 
                 //&& fill_mtVlepJECnew>30
                 && fill_drla>0.5 && fill_drj1l>0.5 && fill_drj2l>0.5 && fill_drj1a>0.5 && fill_drj2a>0.5
                 //&& fabs(fill_j1metPhi)>0.5 && fabs(fill_j2metPhi)>0.5
                 && fill_jet1deepcsv < cut_value[1] && fill_jet2deepcsv < cut_value[1]
                 && fabs(fill_Mla - 91.2) > 10;

     gen_electron_cut_signal_region = genlep==11 && genlep1pt>30 && fabs(genlep1eta)<2.5
                 && genphotonet>25 
                 //&& genphotonet<400
                 && fabs(genphotoneta)<2.5 && (fabs(genphotoneta)>1.566 || fabs(genphotoneta)<1.4442)
                 && genjet1pt>40 && genjet2pt>30 
                 && fabs(genjet1eta)<4.7 && fabs(genjet2eta)<4.7
                 && gendrla1>0.5 
                 && gendrj1a>0.5 && gendrj2a>0.5 && gendrj1l>0.5 && gendrj2l>0.5
                 && genMjj >500 && gendetajj>2.5 
                 //&& genWGmass >100 
                 && genMla > 30 
                 //&& gendelta_phi >1.8
                 //&& genzepp <0.9 
                 && *genMET >30
                 && fabs(genMla - 91.2) > 10
                 ;


      // control region cuts
      muon_cut_control_region = fill_HLT_muon==1
                 && fill_Mjj>200. && fill_Mjj<400.
                 && fill_jet1pt>40. && fabs(fill_jet1eta)<4.7 && fill_jet2pt>30. && fabs(fill_jet2eta)<4.7
                 && abs(fill_lep)==13 && fill_ptlep1>30. && fabs(fill_etalep1)<2.4
                 && fill_ngoodmus==1 && fill_ngoodeles==0 &&(fill_nloosemus+fill_nlooseeles)==1
                 && fill_photonhaspixelseed==0 && fill_photonet>25. //&& fill_photonet < 400.
                 && fill_MET_et>30. 
                 //&& fill_mtVlepJECnew>30
                 && fill_drla>0.5 && fill_drj1l>0.5 && fill_drj2l>0.5 && fill_drj1a>0.5 && fill_drj2a>0.5
                 //&& fabs(fill_j1metPhi)>0.5 && fabs(fill_j2metPhi)>0.5
                 && fill_jet1deepcsv < cut_value[1] && fill_jet2deepcsv < cut_value[1];

     gen_muon_cut_control_region = genlep==13 && genlep1pt>30 && fabs(genlep1eta)<2.4
                 && genphotonet>25 //&& genphotonet<400 
                 && fabs(genphotoneta)<2.5 && (fabs(genphotoneta)>1.566 || fabs(genphotoneta)<1.4442)
                 && genjet1pt>40 && genjet2pt>30 
                 && fabs(genjet1eta)<4.7 && fabs(genjet2eta)<4.7
                 && gendrla1>0.5 
                 && gendrj1a>0.5 && gendrj2a>0.5 && gendrj1l>0.5 && gendrj2l>0.5
                 && genMjj>200 && genMjj<400
                 && *genMET >30;

      electron_cut_control_region = fill_HLT_electron==1
                 && fill_Mjj>200. && fill_Mjj<400.
                 && fill_jet1pt>40. && fabs(fill_jet1eta)<4.7 && fill_jet2pt>30. && fabs(fill_jet2eta)<4.7
                 && abs(fill_lep)==11 && fill_ptlep1>30. && fabs(fill_etalep1)<2.5
                 && fill_ngoodmus==0 && fill_ngoodeles==1 &&(fill_nloosemus+fill_nlooseeles)==1
                 && fill_photonhaspixelseed==0 && fill_photonet>25. //&& fill_photonet < 400.
                 && fill_MET_et>30. //&& fill_mtVlepJECnew>30
                 && fill_drla>0.5 && fill_drj1l>0.5 && fill_drj2l>0.5 && fill_drj1a>0.5 && fill_drj2a>0.5
                 //&& fabs(fill_j1metPhi)>0.5 && fabs(fill_j2metPhi)>0.5
                 && fill_jet1deepcsv < cut_value[1] && fill_jet2deepcsv < cut_value[1]
                 && fabs(fill_Mla - 91.2) > 10;

     gen_electron_cut_control_region = genlep==11 && genlep1pt>30 && fabs(genlep1eta)<2.5
                 && genphotonet>25 //&& genphotonet<400 
                 && fabs(genphotoneta)<2.5 && (fabs(genphotoneta)>1.566 || fabs(genphotoneta)<1.4442)
                 && genjet1pt>40 && genjet2pt>30 
                 && fabs(genjet1eta)<4.7 && fabs(genjet2eta)<4.7
                 && gendrla1>0.5 
                 && gendrj1a>0.5 && gendrj2a>0.5 && gendrj1l>0.5 && gendrj2l>0.5
                 && genMjj >200 && genMjj<400
                 && *genMET >30
                 && fabs(genMla - 91.2) > 10;

      bool cut1, cut2, cut3, cut4, cut5;

      if(m_channel == "muon"){
         if (m_region == "signal"){
            cut1 = muon_cut_signal_region;
            cut2 = gen_muon_cut_signal_region;
         }
         else if (m_region == "control"){
            cut1 = muon_cut_control_region;
            cut2 = gen_muon_cut_control_region;

         }
         else if (m_region == "aqgc"){
            cut1 = muon_cut_aqgc_region;
            cut2 = gen_muon_cut_aqgc_region;

         }
         else continue;
      }


      if(m_channel == "electron"){
         if (m_region == "signal"){
            cut1 = electron_cut_signal_region;
            cut2 = gen_electron_cut_signal_region;

         }
         else if (m_region == "control"){
            cut1 = electron_cut_control_region;
            cut2 = gen_electron_cut_control_region;

         }
         else if (m_region == "aqgc"){
            cut1 = electron_cut_aqgc_region;
            cut2 = gen_electron_cut_aqgc_region;

         }
         else continue;
      }


n++;
if(cut1){
n1=n1+1;
if(genlep1pt>30 ) s1 = s1+1;
if(genlep1pt>30 &&fabs(genlep1eta)<2.4) s2 = s2+1;

if(genlep1pt>30 &&fabs(genlep1eta)<2.4 && genphotonet>25 && genphotonet<400 ) s3 = s3+1;
if(genlep1pt>30 &&fabs(genlep1eta)<2.4 && genphotonet>25 && genphotonet<400 && ((fabs(genphotoneta)<2.5&&fabs(genphotoneta)>1.566) || (fabs(genphotoneta)<1.4442)) ) s4 = s4+1;

if(genlep1pt>30 &&fabs(genlep1eta)<2.4 && genphotonet>25 && genphotonet<400 && ((fabs(genphotoneta)<2.5&&fabs(genphotoneta)>1.566) || (fabs(genphotoneta)<1.4442)) && genjet1pt>40 && genjet2pt>30 ) s5 = s5+1;
if(genlep1pt>30 &&fabs(genlep1eta)<2.4 && genphotonet>25 && genphotonet<400 && ((fabs(genphotoneta)<2.5&&fabs(genphotoneta)>1.566) || (fabs(genphotoneta)<1.4442)) && genjet1pt>40 && genjet2pt>30 && fabs(genjet1eta)<4.7 && fabs(genjet2eta)<4.7) s6 = s6+1;

if(genlep1pt>30 &&fabs(genlep1eta)<2.4 && genphotonet>25 && genphotonet<400 && ((fabs(genphotoneta)<2.5&&fabs(genphotoneta)>1.566) || (fabs(genphotoneta)<1.4442)) && genjet1pt>40 && genjet2pt>30 && fabs(genjet1eta)<4.7 && fabs(genjet2eta)<4.7 && gendrla1>0.5) s7 = s7+1;

if(genlep1pt>30 &&fabs(genlep1eta)<2.4 && genphotonet>25 && genphotonet<400 && ((fabs(genphotoneta)<2.5&&fabs(genphotoneta)>1.566) || (fabs(genphotoneta)<1.4442)) && genjet1pt>40 && genjet2pt>30 && fabs(genjet1eta)<4.7 && fabs(genjet2eta)<4.7 && gendrla1>0.5 && gendrj1a>0.5 ) s8 = s8+1;

if(genlep1pt>30 &&fabs(genlep1eta)<2.4 && genphotonet>25 && genphotonet<400 && ((fabs(genphotoneta)<2.5&&fabs(genphotoneta)>1.566) || (fabs(genphotoneta)<1.4442)) && genjet1pt>40 && genjet2pt>30 && fabs(genjet1eta)<4.7 && fabs(genjet2eta)<4.7 && gendrla1>0.5 && gendrj1a>0.5 && gendrj2a>0.5 ) s9 = s9+1;

if(genlep1pt>30 &&fabs(genlep1eta)<2.4 && genphotonet>25 && genphotonet<400 && ((fabs(genphotoneta)<2.5&&fabs(genphotoneta)>1.566) || (fabs(genphotoneta)<1.4442)) && genjet1pt>40 && genjet2pt>30 && fabs(genjet1eta)<4.7 && fabs(genjet2eta)<4.7 && gendrla1>0.5 && gendrj1a>0.5 && gendrj2a>0.5 && gendrj1l>0.5) s10 = s10+1;

if(genlep1pt>30 &&fabs(genlep1eta)<2.4 && genphotonet>25 && genphotonet<400 && ((fabs(genphotoneta)<2.5&&fabs(genphotoneta)>1.566) || (fabs(genphotoneta)<1.4442)) && genjet1pt>40 && genjet2pt>30 && fabs(genjet1eta)<4.7 && fabs(genjet2eta)<4.7 && gendrla1>0.5 && gendrj1a>0.5 && gendrj2a>0.5 && gendrj1l>0.5 && gendrj2l>0.5) s11 = s11+1;




if(cut2)n2=n2+1;
if(!cut2){
/*
cout<<n1<<"  reco: "<<cut1<<"   gen: "<<cut2<<endl;
cout<<"reco lep: "<<fill_lep<<"   gen lep: "<<genlep<<endl;
//cout<<"reco Mjj: "<<fill_Mjj<<"   gen Mjj: "<<genMjj<<endl;
//cout<<"reco Mva: "<<fill_Mva<<"   gen Mva: "<<genWGmass<<endl;
cout<<"reco ptlep: "<<fill_ptlep1<<"   gen ptlep: "<<genlep1pt<<endl;
cout<<"reco Met: "<<fill_MET_et<<"   gen Met: "<<*genMET<<endl;
cout<<"reco photonpt: "<<fill_photonet<<"   gen photonpt: "<<genphotonet<<endl;

cout<<"genjetptlist: "<<genjet_pt[0]<<" "<<genjet_pt[1]<<" "<<genjet_pt[2]<<" "<<genjet_pt[3]<<" "<<genjet_pt[4]<<" "<<genjet_pt[5]<<endl;

cout<<"reco jet1pt: "<<fill_jet1pt<<"   gen jet1pt: "<<genjet1pt<<" "<<jet_index[0]<<endl;
cout<<"reco jet2pt: "<<fill_jet2pt<<"   gen jet2pt: "<<genjet2pt<<" "<<jet_index[1]<<endl;
cout<<"reco jet1eta: "<<fill_jet1eta<<"   gen jet1eta: "<<genjet1eta<<"   genjetetalist: "<<genjet_eta[0]<<" "<<genjet_eta[1]<<" "<<genjet_eta[2]<<" "<<genjet_eta[3]<<" "<<genjet_eta[4]<<" "<<genjet_eta[5]<<endl;
cout<<"reco jet2eta: "<<fill_jet2eta<<"   gen jet2eta: "<<genjet2eta<<endl;
cout<<"reco drla: "<<fill_drla<<"   gen drla: "<<gendrla1<<endl;
cout<<"reco drj1l: "<<fill_drj1l<<"   gen drj1l: "<<gendrj1l<<endl;
cout<<"reco drj2l: "<<fill_drj2l<<"   gen drj2l: "<<gendrj2l<<endl;
cout<<"reco drj1a: "<<fill_drj1a<<"   gen drj1a: "<<gendrj1a<<endl;
cout<<"reco drj2a: "<<fill_drj2a<<"   gen dj2a: "<<gendrj2a<<endl;
//cout<<"reco zepp: "<<fill_zepp<<"   gen zepp: "<<genzepp<<endl;
//cout<<"reco detajj: "<<fill_deltaeta<<"   gen detajj: "<<gendetajj<<endl;
//cout<<"reco deta_phi: "<<fill_Dphiwajj<<"   gen deta_phi: "<<gendelta_phi<<endl;
*/
}
}
cout<<n<<" "<<n1<<"   "<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<" "<<s5<<" "<< s6<<" "<<s7<<" "<<s8<<" "<<s9<<" "<<s10<<" "<<s11<<" "<<n2<<endl;



      if(!cut1) continue;

//cout<<"pass"<<endl;
      // init all SF
      init_sf();
      // cross section SF
      if(m_sample == "WGJJ")          { cross_section_SF=1000.*0.5439   *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "WGJets")        { cross_section_SF=1000.*192.3    *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "W0Jets")        { cross_section_SF=1000.*55971.0  *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "W1Jets")        { cross_section_SF=1000.*6942.0   *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "W2Jets")        { cross_section_SF=1000.*1459.0   *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "ZJets")         { cross_section_SF=1000.*5765.4   *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "ZG")            { cross_section_SF=1000.*47.46    *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "TTG")       { cross_section_SF=1000.*4.078    *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "TTJets")        { cross_section_SF=1000.*831.76   *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "ST_s")          { cross_section_SF=1000.*3.74     *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "ST_tbarW")      { cross_section_SF=1000.*34.97    *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "ST_tW")         { cross_section_SF=1000.*34.91    *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "ST_t")          { cross_section_SF=1000.*113.3    *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "ST_tbar")       { cross_section_SF=1000.*67.91    *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "WW")            { cross_section_SF=1000.*75.8     *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "WZ")            { cross_section_SF=1000.*27.6     *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "ZZ")            { cross_section_SF=1000.*12.14    *fabs(*theWeight)/(*theWeight); }
      if(m_sample == "DY")            { cross_section_SF=1000.*6077.22  *fabs(*theWeight)/(*theWeight); }


      // add scalef for mc
      if(m_type == "mc") {
         // pu weight
         pu_weight_SF = h_pu_weight->GetBinContent(h_pu_weight->GetXaxis()->FindBin(*npT));
         
         // photon medium ID scalefactor
         if(fabs(*photonsceta)<2.5){
            photon_ID_SF = get_photon_ID(*photonsceta, *photonet, h_photon_ID_weight, " ");
            photon_ID_up_SF = get_photon_ID(*photonsceta, *photonet, h_photon_ID_weight, "up");
            photon_ID_low_SF = get_photon_ID(*photonsceta, *photonet, h_photon_ID_weight, "low");
         }
         // add factor for muon
         if(abs(*lep)==13)
         {
            //------muon trigger scalefactor
            muon_HLT_SF = get_muon_HLT(*etalep1, *ptlep1, h_muon_HLT_weight, " ");
            muon_HLT_up_SF = get_muon_HLT(*etalep1, *ptlep1, h_muon_HLT_weight, "up");
            muon_HLT_low_SF = get_muon_HLT(*etalep1, *ptlep1, h_muon_HLT_weight, "low");
            //------muon tight ID  scalefactor
            muon_ID_SF = get_muon_ID(*etalep1, *ptlep1, h_muon_ID_weight, " ");
            muon_ID_up_SF = get_muon_ID(*etalep1, *ptlep1, h_muon_ID_weight, "up");
            muon_ID_low_SF = get_muon_ID(*etalep1, *ptlep1, h_muon_ID_weight, "low");
            //------muon tight ISO scalefactor
            muon_iso_SF = get_muon_iso(*etalep1, *ptlep1, h_muon_iso_weight, " ");
            muon_iso_up_SF = get_muon_iso(*etalep1, *ptlep1, h_muon_iso_weight, "up");
            muon_iso_low_SF = get_muon_iso(*etalep1, *ptlep1, h_muon_iso_weight, "low");
         }
         // add factor for electron
         if(abs(*lep)==11)
         {
            //------electron reco scalefactor
            electron_Reco_SF = get_ele_Reco(*etalep1, *ptlep1, h_electron_reco_weight, " ");
            electron_Reco_up_SF = get_ele_Reco(*etalep1, *ptlep1, h_electron_reco_weight, "up");
            electron_Reco_low_SF = get_ele_Reco(*etalep1, *ptlep1, h_electron_reco_weight, "low");
            //------electron tight ID scalefactor
            electron_ID_SF = get_ele_ID(*etalep1, *ptlep1, h_electron_ID_weight, " ");
            electron_ID_up_SF = get_ele_ID(*etalep1, *ptlep1, h_electron_ID_weight, "up");
            electron_ID_low_SF = get_ele_ID(*etalep1, *ptlep1, h_electron_ID_weight, "low");
            //------electron trigger scalefactor
            electron_HLT_SF = get_ele_HLT(*etalep1, *ptlep1, h_electron_HLT_weight, " ");
            electron_HLT_up_SF = get_ele_HLT(*etalep1, *ptlep1, h_electron_HLT_weight, "up");
            electron_HLT_low_SF = get_ele_HLT(*etalep1, *ptlep1, h_electron_HLT_weight, "low");
         }
         // add factor for jets b, c
         // jet1 : center, jec_up, jec_down, jer_up, jer_down
         // jet1 : center
         double JET1DEEPCSV      = (*jet1deepcsv_probb_new) + (*jet1deepcsv_probbb_new);
         double JET2DEEPCSV      = (*jet2deepcsv_probb_new) + (*jet2deepcsv_probbb_new);

         //test
         btag_jet1_SF     = btag_SF(*jet1pt_new, *jet1eta_new, *jet1pf, JET1DEEPCSV, btag_cut_value, m_btag_workpoint, "central");
         btag_jet1_up_SF  = btag_SF(*jet1pt_new, *jet1eta_new, *jet1pf, JET1DEEPCSV, btag_cut_value, m_btag_workpoint, "up");
         btag_jet1_low_SF = btag_SF(*jet1pt_new, *jet1eta_new, *jet1pf, JET1DEEPCSV, btag_cut_value, m_btag_workpoint, "low");

         btag_jet2_SF     = btag_SF(*jet2pt_new, *jet2eta_new, *jet2pf, JET1DEEPCSV, btag_cut_value, m_btag_workpoint, "central");
         btag_jet2_up_SF  = btag_SF(*jet2pt_new, *jet2eta_new, *jet2pf, JET1DEEPCSV, btag_cut_value, m_btag_workpoint, "up");
         btag_jet2_low_SF = btag_SF(*jet2pt_new, *jet2eta_new, *jet2pf, JET1DEEPCSV, btag_cut_value, m_btag_workpoint, "low");



      } //add scalef for mc

      double ptl1 = fill_ptlep1;
      if (ptl1 >= 50) ptl1 = 45;

      // data driven weight
      double fake_lepton_weight, barrel_fake_photon_weight, endcap_fake_photon_weight, barrel_fake_photon_weight_up, barrel_fake_photon_weight_down, endcap_fake_photon_weight_up, endcap_fake_photon_weight_down;
      fake_lepton_weight = hist_fake_lepton_weight->GetBinContent(hist_fake_lepton_weight->GetXaxis()->FindBin(fabs(fill_etalep1)),hist_fake_lepton_weight->GetYaxis()->FindBin(ptl1)); //fake lepton weight
      barrel_fake_photon_weight = hist_barrel_fake_photon_weight->GetBinContent(hist_barrel_fake_photon_weight->GetXaxis()->FindBin(fill_photonet)); //fake photon weight

      endcap_fake_photon_weight = hist_endcap_fake_photon_weight->GetBinContent(hist_endcap_fake_photon_weight->GetXaxis()->FindBin(fill_photonet)); //fake photon weight

      double weight = 1;

      if(fill_Mva>2000) fill_Mva =1999;

//cout<<fill_Mva<<fill_Mva_JEC_up<<endl;
      // fill histogram
      // barrel
      if (fabs(fill_photonsceta) < 1.4442){
         if(m_type == "data") { 
            weight = 1; //weight_jec_up = 1; weight_jec_down = 1; weight_jer_up = 1; weight_jer_down = 1;
         }
         else if(m_type == "fakelepton") { 
            weight = fake_lepton_weight; //weight_jec_up = weight; weight_jec_down = weight; weight_jer_up = weight; weight_jer_down = weight;
         }
         else if(m_type == "fakephoton") { 
            weight = barrel_fake_photon_weight; //weight_jec_up = weight; weight_jec_down = weight; weight_jer_up = weight; weight_jer_down = weight;

         }
         else if(m_type == "doublefake") { 
            weight = fake_lepton_weight * barrel_fake_photon_weight; //weight_jec_up = weight; weight_jec_down = weight; weight_jer_up = weight; weight_jer_down = weight;

         }
         else if(m_type == "mc") {
            weight = cross_section_SF * pu_weight_SF * photon_ID_SF * electron_ID_SF * electron_Reco_SF * electron_HLT_SF *muon_ID_SF * muon_iso_SF * muon_HLT_SF*btag_jet1_SF * btag_jet2_SF;

         }


         
         hist_ptlep->Fill(fill_ptlep1,weight);
         hist_photonEt->Fill(fill_photonet,weight);
         hist_jet1pt->Fill(fill_jet1pt,weight);
         hist_Mva->Fill(fill_Mva,weight);
         hist2D_Mjj_detajj->Fill(fill_Mjj,fill_deltaeta,weight);
         hist_Mjj_Signal->Fill(fill_Mjj,weight);
         hist_Mjj_Control->Fill(fill_Mjj,weight);

         if(cut2){
            hist_gen_ptlep->Fill(genlep1pt,weight);
            hist_gen_photonEt->Fill(genphotonet,weight);
            hist_gen_jet1pt->Fill(genjet1pt,weight);
            hist_gen_Mva->Fill(fill_Mva,weight);
            hist_gen_Mjj_Signal->Fill(genMjj,weight);
            hist_gen_Mjj_Control->Fill(genMjj,weight);
            hist2D_gen_Mjj_detajj->Fill(genMjj,gendetajj,weight);

         }
         else{
            hist_outgen_ptlep->Fill(genlep1pt,weight);
            hist_outgen_photonEt->Fill(genphotonet,weight);
            hist_outgen_jet1pt->Fill(genjet1pt,weight);
            hist_outgen_Mva->Fill(fill_Mva,weight);
            hist_outgen_Mjj_Signal->Fill(genMjj,weight);
            hist_outgen_Mjj_Control->Fill(genMjj,weight);
            hist2D_outgen_Mjj_detajj->Fill(genMjj,gendetajj,weight);

         }

      }

      // endcap
      if (fabs(fill_photonsceta) > 1.566 && fabs(fill_photonsceta) < 2.5){
         if(m_type == "data") { 
            weight = 1; //weight_jec_up = 1; weight_jec_down = 1; weight_jer_up = 1; weight_jer_down = 1;

         }
         else if(m_type == "fakelepton") { 
            weight = fake_lepton_weight; //weight_jec_up = weight; weight_jec_down = weight; weight_jer_up = weight; weight_jer_down = weight;

         }
         else if(m_type == "fakephoton") { 
            weight = endcap_fake_photon_weight; //weight_jec_up = weight; weight_jec_down = weight; weight_jer_up = weight; weight_jer_down = weight;
         }
         else if(m_type == "doublefake") { 
            weight = fake_lepton_weight * barrel_fake_photon_weight; //weight_jec_up = weight; weight_jec_down = weight; weight_jer_up = weight; weight_jer_down = weight;

         }
         else if(m_type == "mc") {
            weight = cross_section_SF * pu_weight_SF * photon_ID_SF * electron_ID_SF * electron_Reco_SF * electron_HLT_SF *muon_ID_SF * muon_iso_SF * muon_HLT_SF*btag_jet1_SF * btag_jet2_SF;            

         }

         hist_ptlep->Fill(fill_ptlep1,weight);
         hist_photonEt->Fill(fill_photonet,weight);
         hist_jet1pt->Fill(fill_jet1pt,weight);
         hist_Mva->Fill(fill_Mva,weight);
         hist_Mjj_Signal->Fill(fill_Mjj,weight);
         hist_Mjj_Control->Fill(fill_Mjj,weight);
         hist2D_Mjj_detajj->Fill(fill_Mjj,fill_deltaeta,weight);

         if(cut2){
            hist_gen_ptlep->Fill(genlep1pt,weight);
            hist_gen_photonEt->Fill(genphotonet,weight);
            hist_gen_jet1pt->Fill(genjet1pt,weight);
            hist_gen_Mva->Fill(fill_Mva,weight);
            hist_gen_Mjj_Signal->Fill(genMjj,weight);
            hist_gen_Mjj_Control->Fill(genMjj,weight);
            hist2D_gen_Mjj_detajj->Fill(genMjj,gendetajj,weight);

         }
         else{
            hist_outgen_ptlep->Fill(genlep1pt,weight);
            hist_outgen_photonEt->Fill(genphotonet,weight);
            hist_outgen_jet1pt->Fill(genjet1pt,weight);
            hist_outgen_Mva->Fill(fill_Mva,weight);
            hist_outgen_Mjj_Signal->Fill(genMjj,weight);
            hist_outgen_Mjj_Control->Fill(genMjj,weight);
            hist2D_outgen_Mjj_detajj->Fill(genMjj,gendetajj,weight);

         }
      }
      //jentry++;
   }
}
