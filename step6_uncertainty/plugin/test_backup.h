//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Jul 12 17:08:56 2020 by ROOT version 6.10/05
// from TTree PKUCandidates/PKU Candidates
// found on file: treePKU_69.root
//////////////////////////////////////////////////////////

#ifndef test_h
#define test_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <TH1D.h>
#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include <TTreeReaderArray.h>
#include <TH2.h>
#include "TF1.h"
#include <algorithm>
#include <cmath>
#include <ctime>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Header file for the classes stored in the TTree if any.

class test {
public :
   // some thing important
   TString m_year;
   TString m_sample;
   TString m_type;
   TString m_channel;
   TString m_region;
   TString m_btag_workpoint;

   // fake lepton weight
   TFile * file_fake_muon_weight;
   TFile * file_fake_electron_weight;
   TH2D* hist_fake_lepton_weight;
   // fake photon weight
   TFile * file_fake_photon_weight;
   TH1F* hist_barrel_fake_photon_weight;
   TH1F* hist_endcap_fake_photon_weight;

   // pile up weight
   TFile * pu_weight_input;
   TH1D* h_pu_weight;

   // photon medium ID weight
   TFile * photon_ID_weight_input;
   TH2D* h_photon_ID_weight;

   // muon HLT weight
   TFile * muon_HLT_weight_input;
   TDirectory * muon_HLT_weight_dir;
   TH2D* h_muon_HLT_weight;

   // muon ID weight
   TFile * muon_ID_weight_input;
   TH2D* h_muon_ID_weight;

   // muon iso scale
   TFile * muon_iso_weight_input;
   TH2D* h_muon_iso_weight;

   // electron reco scale
   TFile * electron_reco_weight_input;
   TH2D* h_electron_reco_weight;

   // electron ID scale
   TFile * electron_ID_weight_input;
   TH2D* h_electron_ID_weight;

   // electron HLT scale
   TFile * electron_HLT_weight_input;
   TH2D* h_electron_HLT_weight;

   // value to fill histogram or use for cut
   double fill_Mjj;
   double fill_Mjj_JEC_up;
   double fill_Mjj_JEC_down;
   double fill_Mjj_JER_up;
   double fill_Mjj_JER_down;

   double fill_nVtx;
   double fill_jet1pt;
   double fill_jet1eta;

   double fill_jet1pt_JEC_up;
   double fill_jet1eta_JEC_up;
   double fill_jet1pt_JEC_down;
   double fill_jet1eta_JEC_down;

   double fill_jet1pt_JER_up;
   double fill_jet1eta_JER_up;
   double fill_jet1pt_JER_down;
   double fill_jet1eta_JER_down;

   double fill_jet1pf;
   double fill_jet1pf_JEC_up;
   double fill_jet1pf_JEC_down;
   double fill_jet1pf_JER_up;
   double fill_jet1pf_JER_down;


   double fill_jet2pt;
   double fill_jet2eta;

   double fill_jet2pt_JEC_up;
   double fill_jet2eta_JEC_up;
   double fill_jet2pt_JEC_down;
   double fill_jet2eta_JEC_down;

   double fill_jet2pt_JER_up;
   double fill_jet2eta_JER_up;
   double fill_jet2pt_JER_down;
   double fill_jet2eta_JER_down;

   double fill_jet2pf;
   double fill_jet2pf_JEC_up;
   double fill_jet2pf_JEC_down;
   double fill_jet2pf_JER_up;
   double fill_jet2pf_JER_down;

   double fill_lep;
   double fill_HLT_muon;
   double fill_HLT_electron;

   double fill_ptlep1;
   double fill_etalep1;
   double fill_ngoodmus;
   double fill_ngoodeles;
   double fill_nloosemus;
   double fill_nlooseeles;
   double fill_photonhaspixelseed;
   double fill_photonet;

   double fill_MET_et;
   double fill_MET_et_JEC_up;
   double fill_MET_et_JEC_down;
   double fill_MET_et_JER_up;
   double fill_MET_et_JER_down;

   double fill_mtVlepJECnew;
   double fill_mtVlepJECnew_JEC_up;
   double fill_mtVlepJECnew_JEC_down;
   double fill_mtVlepJECnew_JER_up;
   double fill_mtVlepJECnew_JER_down;


   double fill_drla;

   double fill_drj1l;
   double fill_drj2l;
   double fill_drj1a;
   double fill_drj2a;

   double fill_drj1l_JEC_up;
   double fill_drj2l_JEC_up;
   double fill_drj1a_JEC_up;
   double fill_drj2a_JEC_up;

   double fill_drj1l_JEC_down;
   double fill_drj2l_JEC_down;
   double fill_drj1a_JEC_down;
   double fill_drj2a_JEC_down;

   double fill_drj1l_JER_up;
   double fill_drj2l_JER_up;
   double fill_drj1a_JER_up;
   double fill_drj2a_JER_up;

   double fill_drj1l_JER_down;
   double fill_drj2l_JER_down;
   double fill_drj1a_JER_down;
   double fill_drj2a_JER_down;

   double fill_j1metPhi;
   double fill_j2metPhi;
   double fill_jet1deepcsv;
   double fill_jet2deepcsv;

   double fill_j1metPhi_JEC_up;
   double fill_j2metPhi_JEC_up;
   double fill_jet1deepcsv_JEC_up;
   double fill_jet2deepcsv_JEC_up;

   double fill_j1metPhi_JEC_down;
   double fill_j2metPhi_JEC_down;
   double fill_jet1deepcsv_JEC_down;
   double fill_jet2deepcsv_JEC_down;

   double fill_j1metPhi_JER_up;
   double fill_j2metPhi_JER_up;
   double fill_jet1deepcsv_JER_up;
   double fill_jet2deepcsv_JER_up;

   double fill_j1metPhi_JER_down;
   double fill_j2metPhi_JER_down;
   double fill_jet1deepcsv_JER_down;
   double fill_jet2deepcsv_JER_down;


   double fill_photonsceta;

   double fill_ptVlepJEC;

   double fill_ptVlepJEC_JEC_up;
   double fill_ptVlepJEC_JEC_down;
   double fill_ptVlepJEC_JER_up;
   double fill_ptVlepJEC_JER_down;

   double fill_photoneta;

   double fill_zepp;
   double fill_deltaeta;
   double fill_Dphiwajj;

   double fill_zepp_JEC_up;
   double fill_deltaeta_JEC_up;
   double fill_Dphiwajj_JEC_up;

   double fill_zepp_JEC_down;
   double fill_deltaeta_JEC_down;
   double fill_Dphiwajj_JEC_down;

   double fill_zepp_JER_up;
   double fill_deltaeta_JER_up;
   double fill_Dphiwajj_JER_up;

   double fill_zepp_JER_down;
   double fill_deltaeta_JER_down;
   double fill_Dphiwajj_JER_down;

   double fill_Mla;
   double fill_Mva;
   double fill_Mva_JEC_up;
   double fill_Mva_JEC_down;
   double fill_Mva_JER_up;
   double fill_Mva_JER_down;

   // cut for muon and electron channel
   Bool_t muon_cut, electron_cut, cut;
   Bool_t muon_cut_signal_region, muon_cut_signal_region_jec_up, muon_cut_signal_region_jec_down, muon_cut_signal_region_jer_up, muon_cut_signal_region_jer_down;
   Bool_t muon_cut_control_region, muon_cut_control_region_jec_up, muon_cut_control_region_jec_down, muon_cut_control_region_jer_up, muon_cut_control_region_jer_down;
   Bool_t muon_cut_aqgc_region, muon_cut_aqgc_region_jec_up, muon_cut_aqgc_region_jec_down, muon_cut_aqgc_region_jer_up, muon_cut_aqgc_region_jer_down;
   Bool_t electron_cut_signal_region, electron_cut_signal_region_jec_up, electron_cut_signal_region_jec_down, electron_cut_signal_region_jer_up, electron_cut_signal_region_jer_down;
   Bool_t electron_cut_control_region, electron_cut_control_region_jec_up, electron_cut_control_region_jec_down, electron_cut_control_region_jer_up, electron_cut_control_region_jer_down;
   Bool_t electron_cut_aqgc_region, electron_cut_aqgc_region_jec_up, electron_cut_aqgc_region_jec_down, electron_cut_aqgc_region_jer_up, electron_cut_aqgc_region_jer_down;

   // define all scalef
   Double_t        photon_ID_SF;
   Double_t        electron_ID_SF;
   Double_t        electron_Reco_SF;
   Double_t        electron_HLT_SF;
   Double_t        muon_ID_SF;
   Double_t        muon_iso_SF;
   Double_t        muon_HLT_SF;

   Double_t        photon_ID_up_SF;
   Double_t        electron_ID_up_SF;
   Double_t        electron_Reco_up_SF;
   Double_t        electron_HLT_up_SF;
   Double_t        muon_ID_up_SF;
   Double_t        muon_iso_up_SF;
   Double_t        muon_HLT_up_SF;

   Double_t        photon_ID_low_SF;
   Double_t        electron_ID_low_SF;
   Double_t        electron_Reco_low_SF;
   Double_t        electron_HLT_low_SF;
   Double_t        muon_ID_low_SF;
   Double_t        muon_iso_low_SF;
   Double_t        muon_HLT_low_SF;

   Double_t        btag_jet1_SF;
   Double_t        btag_jet1_up_SF;
   Double_t        btag_jet1_low_SF;

   Double_t        btag_jet1_SF_JEC_up;
   Double_t        btag_jet1_up_SF_JEC_up;
   Double_t        btag_jet1_low_SF_JEC_up;
   Double_t        btag_jet1_SF_JEC_down;
   Double_t        btag_jet1_up_SF_JEC_down;
   Double_t        btag_jet1_low_SF_JEC_down;
   Double_t        btag_jet1_SF_JER_up;
   Double_t        btag_jet1_up_SF_JER_up;
   Double_t        btag_jet1_low_SF_JER_up;
   Double_t        btag_jet1_SF_JER_down;
   Double_t        btag_jet1_up_SF_JER_down;
   Double_t        btag_jet1_low_SF_JER_down;

   Double_t        btag_jet2_SF;
   Double_t        btag_jet2_up_SF;
   Double_t        btag_jet2_low_SF;

   Double_t        btag_jet2_SF_JEC_up;
   Double_t        btag_jet2_up_SF_JEC_up;
   Double_t        btag_jet2_low_SF_JEC_up;
   Double_t        btag_jet2_SF_JEC_down;
   Double_t        btag_jet2_up_SF_JEC_down;
   Double_t        btag_jet2_low_SF_JEC_down;
   Double_t        btag_jet2_SF_JER_up;
   Double_t        btag_jet2_up_SF_JER_up;
   Double_t        btag_jet2_low_SF_JER_up;
   Double_t        btag_jet2_SF_JER_down;
   Double_t        btag_jet2_up_SF_JER_down;
   Double_t        btag_jet2_low_SF_JER_down;


   Double_t        pu_weight_SF;
   Double_t        cross_section_SF;

   Double_t        p_event = 0, n_event = 0;

   int num = 400;
   TH1D*th2[400];
   TH1D*th2_barrel[400];
   TH1D*th2_endcap[400];

   char th2name[400];
   char th2_barrel_name[400];
   char th2_endcap_name[400];

   // aqgc histgrams
   double WGbin[6] = {150,400,600,800, 1000, 2000};
   TH1D * hist_WGmass_barrel_center = new TH1D("WGmass_barrel_center","WGmass_barrel_center", 5, WGbin);
   TH1D * hist_WGmass_barrel_jec_up = new TH1D("WGmass_barrel_jec_up","WGmass_barrel_jec_up", 5, WGbin);
   TH1D * hist_WGmass_barrel_jec_down = new TH1D("WGmass_barrel_jec_down","WGmass_barrel_jec_down", 5, WGbin);
   TH1D * hist_WGmass_barrel_jer_up = new TH1D("WGmass_barrel_jer_up","WGmass_barrel_jer_up", 5, WGbin);
   TH1D * hist_WGmass_barrel_jer_down = new TH1D("WGmass_barrel_jer_down","WGmass_barrel_jer_down", 5, WGbin);
   TH1D * hist_WGmass_endcap_center = new TH1D("WGmass_endcap_center","WGmass_endcap_center", 5, WGbin);
   TH1D * hist_WGmass_endcap_jec_up = new TH1D("WGmass_endcap_jec_up","WGmass_endcap_jec_up", 5, WGbin);
   TH1D * hist_WGmass_endcap_jec_down = new TH1D("WGmass_endcap_jec_down","WGmass_endcap_jec_down", 5, WGbin);
   TH1D * hist_WGmass_endcap_jer_up = new TH1D("WGmass_endcap_jer_up","WGmass_endcap_jer_up", 5, WGbin);
   TH1D * hist_WGmass_endcap_jer_down = new TH1D("WGmass_endcap_jer_down","WGmass_endcap_jer_down", 5, WGbin);
   TH1D * hist_WGmass_center = new TH1D("WGmass_center","WGmass_center", 5, WGbin);
   TH1D * hist_WGmass_jec_up = new TH1D("WGmass_jec_up","WGmass_jec_up", 5, WGbin);
   TH1D * hist_WGmass_jec_down = new TH1D("WGmass_jec_down","WGmass_jec_down", 5, WGbin);
   TH1D * hist_WGmass_jer_up = new TH1D("WGmass_jer_up","WGmass_jer_up", 5, WGbin);
   TH1D * hist_WGmass_jer_down = new TH1D("WGmass_jer_down","WGmass_jer_down", 5, WGbin);

   TH1D * hist_WGmass_barrel_photon_ID_up = new TH1D("WGmass_barrel_photon_ID_up","WGmass_barrel_photon_ID_up", 5, WGbin);
   TH1D * hist_WGmass_barrel_photon_ID_down = new TH1D("WGmass_barrel_photon_ID_down","WGmass_barrel_photon_ID_down", 5, WGbin);

   TH1D * hist_WGmass_barrel_electron_ID_up = new TH1D("WGmass_barrel_electron_ID_up","WGmass_barrel_electron_ID_up", 5, WGbin);
   TH1D * hist_WGmass_barrel_electron_ID_down = new TH1D("WGmass_barrel_electron_ID_down","WGmass_barrel_electron_ID_down", 5, WGbin);

   TH1D * hist_WGmass_barrel_electron_Reco_up = new TH1D("WGmass_barrel_electron_Reco_up","WGmass_barrel_electron_Reco_up", 5, WGbin);
   TH1D * hist_WGmass_barrel_electron_Reco_down = new TH1D("WGmass_barrel_electron_Reco_down","WGmass_barrel_electron_Reco_down", 5, WGbin);

   TH1D * hist_WGmass_barrel_electron_HLT_up = new TH1D("WGmass_barrel_electron_HLT_up","WGmass_barrel_electron_HLT_up", 5, WGbin);
   TH1D * hist_WGmass_barrel_electron_HLT_down = new TH1D("WGmass_barrel_electron_HLT_down","WGmass_barrel_electron_HLT_down", 5, WGbin);

   TH1D * hist_WGmass_barrel_electron_up = new TH1D("WGmass_barrel_electron_up","WGmass_barrel_electron_up", 5, WGbin);
   TH1D * hist_WGmass_barrel_electron_down = new TH1D("WGmass_barrel_electron_down","WGmass_barrel_electron_down", 5, WGbin);

   TH1D * hist_WGmass_barrel_muon_ID_up = new TH1D("WGmass_barrel_muon_ID_up","WGmass_barrel_muon_ID_up", 5, WGbin);
   TH1D * hist_WGmass_barrel_muon_ID_down = new TH1D("WGmass_barrel_muon_ID_down","WGmass_barrel_muon_ID_down", 5, WGbin);

   TH1D * hist_WGmass_barrel_muon_iso_up = new TH1D("WGmass_barrel_muon_iso_up","WGmass_barrel_muon_iso_up", 5, WGbin);
   TH1D * hist_WGmass_barrel_muon_iso_down = new TH1D("WGmass_barrel_muon_iso_down","WGmass_barrel_muon_iso_down", 5, WGbin);

   TH1D * hist_WGmass_barrel_muon_HLT_up = new TH1D("WGmass_barrel_muon_HLT_up","WGmass_barrel_muon_HLT_up", 5, WGbin);
   TH1D * hist_WGmass_barrel_muon_HLT_down = new TH1D("WGmass_barrel_muon_HLT_down","WGmass_barrel_muon_HLT_down", 5, WGbin);

   TH1D * hist_WGmass_barrel_muon_up = new TH1D("WGmass_barrel_muon_up","WGmass_barrel_muon_up", 5, WGbin);
   TH1D * hist_WGmass_barrel_muon_down = new TH1D("WGmass_barrel_muon_down","WGmass_barrel_muon_down", 5, WGbin);

   TH1D * hist_WGmass_endcap_photon_ID_up = new TH1D("WGmass_endcap_photon_ID_up","WGmass_endcap_photon_ID_up", 5, WGbin);
   TH1D * hist_WGmass_endcap_photon_ID_down = new TH1D("WGmass_endcap_photon_ID_down","WGmass_endcap_photon_ID_down", 5, WGbin);

   TH1D * hist_WGmass_endcap_electron_ID_up = new TH1D("WGmass_endcap_electron_ID_up","WGmass_endcap_electron_ID_up", 5, WGbin);
   TH1D * hist_WGmass_endcap_electron_ID_down = new TH1D("WGmass_endcap_electron_ID_down","WGmass_endcap_electron_ID_down", 5, WGbin);

   TH1D * hist_WGmass_endcap_electron_Reco_up = new TH1D("WGmass_endcap_electron_Reco_up","WGmass_endcap_electron_Reco_up", 5, WGbin);
   TH1D * hist_WGmass_endcap_electron_Reco_down = new TH1D("WGmass_endcap_electron_Reco_down","WGmass_endcap_electron_Reco_down", 5, WGbin);

   TH1D * hist_WGmass_endcap_electron_HLT_up = new TH1D("WGmass_endcap_electron_HLT_up","WGmass_endcap_electron_HLT_up", 5, WGbin);
   TH1D * hist_WGmass_endcap_electron_HLT_down = new TH1D("WGmass_endcap_electron_HLT_down","WGmass_endcap_electron_HLT_down", 5, WGbin);

   TH1D * hist_WGmass_endcap_electron_up = new TH1D("WGmass_endcap_electron_up","WGmass_endcap_electron_up", 5, WGbin);
   TH1D * hist_WGmass_endcap_electron_down = new TH1D("WGmass_endcap_electron_down","WGmass_endcap_electron_down", 5, WGbin);

   TH1D * hist_WGmass_endcap_muon_ID_up = new TH1D("WGmass_endcap_muon_ID_up","WGmass_endcap_muon_ID_up", 5, WGbin);
   TH1D * hist_WGmass_endcap_muon_ID_down = new TH1D("WGmass_endcap_muon_ID_down","WGmass_endcap_muon_ID_down", 5, WGbin);

   TH1D * hist_WGmass_endcap_muon_iso_up = new TH1D("WGmass_endcap_muon_iso_up","WGmass_endcap_muon_iso_up", 5, WGbin);
   TH1D * hist_WGmass_endcap_muon_iso_down = new TH1D("WGmass_endcap_muon_iso_down","WGmass_endcap_muon_iso_down", 5, WGbin);

   TH1D * hist_WGmass_endcap_muon_HLT_up = new TH1D("WGmass_endcap_muon_HLT_up","WGmass_endcap_muon_HLT_up", 5, WGbin);
   TH1D * hist_WGmass_endcap_muon_HLT_down = new TH1D("WGmass_endcap_muon_HLT_down","WGmass_endcap_muon_HLT_down", 5, WGbin);

   TH1D * hist_WGmass_endcap_muon_up = new TH1D("WGmass_endcap_muon_up","WGmass_endcap_muon_up", 5, WGbin);
   TH1D * hist_WGmass_endcap_muon_down = new TH1D("WGmass_endcap_muon_down","WGmass_endcap_muon_down", 5, WGbin);


   TH1D * hist_WGmass_photon_ID_up = new TH1D("WGmass_photon_ID_up","WGmass_photon_ID_up", 5, WGbin);
   TH1D * hist_WGmass_photon_ID_down = new TH1D("WGmass_photon_ID_down","WGmass_photon_ID_down", 5, WGbin);

   TH1D * hist_WGmass_electron_ID_up = new TH1D("WGmass_electron_ID_up","WGmass_electron_ID_up", 5, WGbin);
   TH1D * hist_WGmass_electron_ID_down = new TH1D("WGmass_electron_ID_down","WGmass_electron_ID_down", 5, WGbin);

   TH1D * hist_WGmass_electron_Reco_up = new TH1D("WGmass_electron_Reco_up","WGmass_electron_Reco_up", 5, WGbin);
   TH1D * hist_WGmass_electron_Reco_down = new TH1D("WGmass_electron_Reco_down","WGmass_electron_Reco_down", 5, WGbin);

   TH1D * hist_WGmass_electron_HLT_up = new TH1D("WGmass_electron_HLT_up","WGmass_electron_HLT_up", 5, WGbin);
   TH1D * hist_WGmass_electron_HLT_down = new TH1D("WGmass_electron_HLT_down","WGmass_electron_HLT_down", 5, WGbin);

   TH1D * hist_WGmass_muon_ID_up = new TH1D("WGmass_muon_ID_up","WGmass_muon_ID_up", 5, WGbin);
   TH1D * hist_WGmass_muon_ID_down = new TH1D("WGmass_muon_ID_down","WGmass_muon_ID_down", 5, WGbin);

   TH1D * hist_WGmass_muon_iso_up = new TH1D("WGmass_muon_iso_up","WGmass_muon_iso_up", 5, WGbin);
   TH1D * hist_WGmass_muon_iso_down = new TH1D("WGmass_muon_iso_down","WGmass_muon_iso_down", 5, WGbin);

   TH1D * hist_WGmass_muon_HLT_up = new TH1D("WGmass_muon_HLT_up","WGmass_muon_HLT_up", 5, WGbin);
   TH1D * hist_WGmass_muon_HLT_down = new TH1D("WGmass_muon_HLT_down","WGmass_muon_HLT_down", 5, WGbin);


   TH1D * hist_WGmass_muon_up = new TH1D("WGmass_muon_up","WGmass_muon_up", 5, WGbin);
   TH1D * hist_WGmass_muon_down = new TH1D("WGmass_muon_down","WGmass_muon_down", 5, WGbin);

   TH1D * hist_WGmass_electron_up = new TH1D("WGmass_electron_up","WGmass_electron_up", 5, WGbin);
   TH1D * hist_WGmass_electron_down = new TH1D("WGmass_electron_down","WGmass_electron_down", 5, WGbin);

   // btag eff and scale function
   Double_t eff_b_jet_tight[10]  =  {0.375338, 0.493779, 0.553314, 0.575056, 0.579706, 0.563553, 0.491523, 0.327807, 0.105522, 0.0292929};
   Double_t eff_b_jet_medium[10] = {0.565127, 0.663282, 0.714194, 0.737916, 0.750325, 0.745599, 0.701239, 0.590619, 0.390365, 0.216667};
   Double_t eff_b_jet_loose[10] =  {0.753404, 0.813243, 0.850107, 0.87129, 0.88806, 0.89424, 0.881965, 0.846197, 0.798682, 0.70404};
   TString fuction_b_jet_tight[19] = {
   "0.766992+(0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18))))))" ,
   "(0.766992+(0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18)))))))+0.072564356029033661" ,
   "(0.766992+(0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18)))))))+0.01551971398293972" ,
   "(0.766992+(0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18)))))))+0.013589443638920784" ,
   "(0.766992+(0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18)))))))+0.013067093677818775" ,
   "(0.766992+(0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18)))))))+0.012084255926311016" ,
   "(0.766992+(0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18)))))))+0.013244811445474625" ,
   "(0.766992+(0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18)))))))+0.020085016265511513" ,
   "(0.766992+(0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18)))))))+0.044389884918928146" ,
   "(0.766992+(0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18)))))))+0.082598939538002014" ,
   "0.766992+((0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18))))))-0.072564356029033661)" ,
   "0.766992+((0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18))))))-0.01551971398293972)" ,
   "0.766992+((0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18))))))-0.013589443638920784)" ,
   "0.766992+((0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18))))))-0.013067093677818775)" ,
   "0.766992+((0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18))))))-0.012084255926311016)" ,
   "0.766992+((0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18))))))-0.013244811445474625)" ,
   "0.766992+((0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18))))))-0.020085016265511513)" ,
   "0.766992+((0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18))))))-0.044389884918928146)" ,
   "0.766992+((0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18))))))-0.082598939538002014)"
   };

   TString fuction_b_jet_medium[19] = {
   "0.909339+(0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18))))))" ,
   "(0.909339+(0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18)))))))+0.065904870629310608" ,
   "(0.909339+(0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18)))))))+0.015055687166750431" ,
   "(0.909339+(0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18)))))))+0.013506759889423847" ,
   "(0.909339+(0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18)))))))+0.015106724575161934" ,
   "(0.909339+(0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18)))))))+0.014620178379118443" ,
   "(0.909339+(0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18)))))))+0.012161554768681526" ,
   "(0.909339+(0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18)))))))+0.016239689663052559" ,
   "(0.909339+(0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18)))))))+0.039990410208702087" ,
   "(0.909339+(0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18)))))))+0.068454340100288391" ,
   "0.909339+((0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18))))))-0.065904870629310608)" ,
   "0.909339+((0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18))))))-0.015055687166750431)" ,
   "0.909339+((0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18))))))-0.013506759889423847)" ,
   "0.909339+((0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18))))))-0.015106724575161934)" ,
   "0.909339+((0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18))))))-0.014620178379118443)" ,
   "0.909339+((0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18))))))-0.012161554768681526)" ,
   "0.909339+((0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18))))))-0.016239689663052559)" ,
   "0.909339+((0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18))))))-0.039990410208702087)" ,
   "0.909339+((0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18))))))-0.068454340100288391)" 
   };

   TString fuction_b_jet_loose[19] = {
   "0.917829+(0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18))))))" ,
   "(0.917829+(0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18)))))))+0.15505774319171906" ,
   "(0.917829+(0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18)))))))+0.03490530326962471" ,
   "(0.917829+(0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18)))))))+0.034701071679592133" ,
   "(0.917829+(0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18)))))))+0.034096170216798782" ,
   "(0.917829+(0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18)))))))+0.027626650407910347" ,
   "(0.917829+(0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18)))))))+0.02841717004776001" ,
   "(0.917829+(0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18)))))))+0.027526171877980232" ,
   "(0.917829+(0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18)))))))+0.094343781471252441" ,
   "(0.917829+(0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18)))))))+0.17287716269493103" ,
   "0.917829+((0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18))))))-0.062023099511861801)" ,
   "0.917829+((0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18))))))-0.013962121680378914)" ,
   "0.917829+((0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18))))))-0.013880428858101368)" ,
   "0.917829+((0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18))))))-0.013638468459248543)" ,
   "0.917829+((0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18))))))-0.011050660163164139)" ,
   "0.917829+((0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18))))))-0.011366868391633034)" ,
   "0.917829+((0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18))))))-0.011010468937456608)" ,
   "0.917829+((0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18))))))-0.037737511098384857)" ,
   "0.917829+((0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18))))))-0.069150865077972412)" 
   };

   Double_t eff_c_jet_tight[10]  =  {0.0178263, 0.0219464, 0.0242307, 0.0269731, 0.0299322, 0.0316588, 0.0287384, 0.0180558, 0.00498598, 0.00366972};
   Double_t eff_c_jet_medium[10] = {0.120439, 0.128175, 0.130494, 0.13781, 0.14765, 0.154195, 0.146221, 0.120963, 0.0666874, 0.0311927};
   Double_t eff_c_jet_loose[10] =  {0.392685, 0.415126, 0.42917, 0.445494, 0.462387, 0.473021, 0.461477, 0.451609, 0.421237, 0.348624};
   TString fuction_c_jet_tight[19] = {
   "0.766992+(0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18))))))" ,
   "(0.766992+(0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18)))))))+0.25397524237632751" ,
   "(0.766992+(0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18)))))))+0.054318998008966446" ,
   "(0.766992+(0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18)))))))+0.047563053667545319" ,
   "(0.766992+(0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18)))))))+0.045734826475381851" ,
   "(0.766992+(0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18)))))))+0.042294897139072418" ,
   "(0.766992+(0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18)))))))+0.046356841921806335" ,
   "(0.766992+(0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18)))))))+0.070297554135322571" ,
   "(0.766992+(0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18)))))))+0.15536460280418396" ,
   "(0.766992+(0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18)))))))+0.28909629583358765" ,
   "0.766992+((0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18))))))-0.25397524237632751)" ,
   "0.766992+((0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18))))))-0.054318998008966446)" ,
   "0.766992+((0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18))))))-0.047563053667545319)" ,
   "0.766992+((0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18))))))-0.045734826475381851)" ,
   "0.766992+((0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18))))))-0.042294897139072418)" ,
   "0.766992+((0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18))))))-0.046356841921806335)" ,
   "0.766992+((0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18))))))-0.070297554135322571)" ,
   "0.766992+((0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18))))))-0.15536460280418396)" ,
   "0.766992+((0.00894732*(log(x+19)*(log(x+18)*(3-(0.423381*log(x+18))))))-0.28909629583358765)" 
   };
   TString fuction_c_jet_medium[19] = {
   "0.909339+(0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18))))))" ,
   "(0.909339+(0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18)))))))+0.19771461188793182" ,
   "(0.909339+(0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18)))))))+0.045167062431573868" ,
   "(0.909339+(0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18)))))))+0.040520280599594116" ,
   "(0.909339+(0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18)))))))+0.045320175588130951" ,
   "(0.909339+(0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18)))))))+0.043860536068677902" ,
   "(0.909339+(0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18)))))))+0.036484666168689728" ,
   "(0.909339+(0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18)))))))+0.048719070851802826" ,
   "(0.909339+(0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18)))))))+0.11997123062610626" ,
   "(0.909339+(0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18)))))))+0.20536302030086517" ,
   "0.909339+((0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18))))))-0.19771461188793182)" ,
   "0.909339+((0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18))))))-0.045167062431573868)" ,
   "0.909339+((0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18))))))-0.040520280599594116)" ,
   "0.909339+((0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18))))))-0.045320175588130951)" ,
   "0.909339+((0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18))))))-0.043860536068677902)" ,
   "0.909339+((0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18))))))-0.036484666168689728)" ,
   "0.909339+((0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18))))))-0.048719070851802826)" ,
   "0.909339+((0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18))))))-0.11997123062610626)" ,
   "0.909339+((0.00354*(log(x+19)*(log(x+18)*(3-(0.471623*log(x+18))))))-0.20536302030086517)"
   };

   TString fuction_c_jet_loose[19] = {
   "0.917829+(0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18))))))" ,
   "(0.917829+(0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18)))))))+0.15505774319171906" ,
   "(0.917829+(0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18)))))))+0.03490530326962471" ,
   "(0.917829+(0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18)))))))+0.034701071679592133" ,
   "(0.917829+(0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18)))))))+0.034096170216798782" ,
   "(0.917829+(0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18)))))))+0.027626650407910347" ,
   "(0.917829+(0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18)))))))+0.02841717004776001" ,
   "(0.917829+(0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18)))))))+0.027526171877980232" ,
   "(0.917829+(0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18)))))))+0.094343781471252441" ,
   "(0.917829+(0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18)))))))+0.17287716269493103" ,
   "0.917829+((0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18))))))-0.15505774319171906)" ,
   "0.917829+((0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18))))))-0.03490530326962471)" ,
   "0.917829+((0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18))))))-0.034701071679592133)" ,
   "0.917829+((0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18))))))-0.034096170216798782)" ,
   "0.917829+((0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18))))))-0.027626650407910347)" ,
   "0.917829+((0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18))))))-0.02841717004776001)" ,
   "0.917829+((0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18))))))-0.027526171877980232)" ,
   "0.917829+((0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18))))))-0.094343781471252441)" ,
   "0.917829+((0.00298278*(log(x+19)*(log(x+18)*(3-(0.422392*log(x+18))))))-0.17287716269493103)" 
   };

   Double_t eff_l_jet_tight[10]  =  {0.00115722, 0.000821689, 0.000900955, 0.00110315, 0.0014241, 0.00181297, 0.0020553, 0.00198708, 0.000801618, 0};
   Double_t eff_l_jet_medium[10] = {0.00904002, 0.00806116, 0.00810405, 0.00924306, 0.0113922, 0.0137251, 0.0159489, 0.0189461, 0.0130992, 0.004265};
   Double_t eff_l_jet_loose[10] =  {0.125149, 0.0924003, 0.0847756, 0.0946918, 0.113998, 0.134914, 0.15921, 0.19733, 0.229773, 0.206426};
   TString fuction_l_jet_tight[3] = {
   "0.870921+5.90958/sqrt(x)" ,
   "(0.870921+5.90958/sqrt(x))*(1+(0.207667+0.000165081*x+-1.45307e-07*x*x))" ,
   "(0.870921+5.90958/sqrt(x))*(1-(0.207667+0.000165081*x+-1.45307e-07*x*x))" 
   };

   TString fuction_l_jet_medium[3] = {
   "1.6329+-0.00160255*x+1.9899e-06*x*x+-6.72613e-10*x*x*x" ,
   "(1.6329+-0.00160255*x+1.9899e-06*x*x+-6.72613e-10*x*x*x)*(1+(0.122811+0.000162564*x+-1.66422e-07*x*x))" ,
   "(1.6329+-0.00160255*x+1.9899e-06*x*x+-6.72613e-10*x*x*x)*(1-(0.122811+0.000162564*x+-1.66422e-07*x*x))"
   };

   TString fuction_l_jet_loose[3] = {
   "1.41852+-0.00040383*x+2.89389e-07*x*x+-3.55101e-11*x*x*x" ,
   "(1.41852+-0.00040383*x+2.89389e-07*x*x+-3.55101e-11*x*x*x)*(1+(0.0559259+1.96455e-05*x+-3.60571e-08*x*x))" ,
   "(1.41852+-0.00040383*x+2.89389e-07*x*x+-3.55101e-11*x*x*x)*(1-(0.0559259+1.96455e-05*x+-3.60571e-08*x*x))"
   };

   /// define histogram for fake lepton

   /// define histogram for fake photon
   //

   Int_t           fCurrent; //!current Tree number in a TChain
   TString m_dataset;

   Double_t lumi;
   Double_t cut_value[3];

   test();
   virtual ~test();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init();
   virtual void     Loop(TDirectory * dir);
   //virtual void     Loop_fake_lepton(TDirectory * dir);

   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   virtual Double_t beff(TString workpoint, Double_t x);
   virtual Double_t ceff(TString workpoint, Double_t x);
   virtual Double_t leff(TString workpoint, Double_t x);
   virtual Double_t b_scale(TString type, TString workpoint, Double_t x);
   virtual Double_t c_scale(TString type, TString workpoint, Double_t x);
   virtual Double_t l_scale(TString type, TString workpoint, Double_t x);
   virtual Double_t btag_SF(Double_t pt, Double_t eta, Int_t pf, Double_t CSV, Double_t cut_value, TString workpoint, TString up_and_low);

   void set_cut_value(TString year = "2018");
   void hist_Sumw2();
   void hist_Scale();

   void init_sf();
   void endJob();
   TFile *fout;
};

#endif

#ifdef test_cxx
test::test()  
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   //if (tree == 0) {
   //   TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("treePKU_69.root");
   //   if (!f || !f->IsOpen()) {
   //      f = new TFile("treePKU_69.root");
   //   }
      //TDirectory * dir = (TDirectory*)f->Get("treePKU_69.root:/treeDumper");
      //dir->GetObject("PKUCandidates",tree);

   //}
   //m_dataset = outname;
   //m_year = year;
   //Init(f);
   hist_Sumw2();
}

test::~test()
{
   //if (!fReader) return;
   //delete fReader.GetCurrentEntry();
}

Int_t test::GetEntry(Long64_t entry)
{
// Read contents of entry.
   //if (!fReader) return 0;
   //return fReader->GetEntry(entry);
}
Long64_t test::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   //if (!fChain) return -5;
   //Long64_t centry = fChain->LoadTree(entry);
   //if (centry < 0) return centry;
   //if (fChain->GetTreeNumber() != fCurrent) {
   //   fCurrent = fChain->GetTreeNumber();
   //   Notify();
   //}
   //return centry;
}

void test::Init()
{
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   //if (!f) return;
   //fCurrent = -1;

   // fake lepton weight
   file_fake_muon_weight = TFile::Open("filelist_dir/data_driven_weight/muon_fakerate.root");
   file_fake_electron_weight = TFile::Open("filelist_dir/data_driven_weight/electron_fakerate.root");
   if(m_channel == "muon")     hist_fake_lepton_weight = (TH2D*)file_fake_muon_weight->Get("weight");
   if(m_channel == "electron") hist_fake_lepton_weight = (TH2D*)file_fake_electron_weight->Get("weight");

   // fake photon weight
   file_fake_photon_weight = TFile::Open("filelist_dir/data_driven_weight/fake_photon_weight.root");
   hist_barrel_fake_photon_weight = (TH1F*)file_fake_photon_weight->Get("barrel_fake_photon_weight");
   hist_endcap_fake_photon_weight = (TH1F*)file_fake_photon_weight->Get("endcap_fake_photon_weight");

   // pile up weight
   pu_weight_input = new TFile ("./scalef/puweight_2018.root");
   h_pu_weight = (TH1D*)pu_weight_input->Get("h2");

   // photon medium ID weight
   photon_ID_weight_input = new TFile ("./scalef/photon/2018_PhotonsMedium.root");
   h_photon_ID_weight = (TH2D*)photon_ID_weight_input->Get("EGamma_SF2D");

   // muon HLT weight
   muon_HLT_weight_input = new TFile ("./scalef/muon/EfficienciesAndSF_2018Data_AfterMuonHLTUpdate.root");
   muon_HLT_weight_dir  = (TDirectory*)muon_HLT_weight_input->Get("IsoMu24_PtEtaBins");
   h_muon_HLT_weight = (TH2D*)muon_HLT_weight_dir->Get("abseta_pt_ratio");

   // muon ID weight
   muon_ID_weight_input = new TFile ("./scalef/muon/RunABCD_SF_ID.root");
   h_muon_ID_weight = (TH2D*)muon_ID_weight_input->Get("NUM_TightID_DEN_TrackerMuons_pt_abseta");

   // muon iso weight
   muon_iso_weight_input = new TFile ("./scalef/muon/RunABCD_SF_ISO.root");
   h_muon_iso_weight = (TH2D*)muon_iso_weight_input->Get("NUM_TightRelIso_DEN_TightIDandIPCut_pt_abseta");

   // electron reco weight
   electron_reco_weight_input = new TFile ("./scalef/electron/EGM2D_electron_Reco.root");
   h_electron_reco_weight = (TH2D*)electron_reco_weight_input->Get("EGamma_SF2D");

   // electron ID weight
   electron_ID_weight_input = new TFile ("./scalef/electron/2018_ElectronTight.root");
   h_electron_ID_weight = (TH2D*)electron_ID_weight_input->Get("EGamma_SF2D");

   // electron HLT weight
   electron_HLT_weight_input = new TFile ("./scalef/electron/2018_egamma_hlt_sf.root");
   h_electron_HLT_weight = (TH2D*)electron_HLT_weight_input->Get("EGamma_SF2D");

//cout<<"ok1"<<endl;
   //int num = 148;
   for(Int_t i=0;i<num;i++){
       sprintf(th2name,"th2_%d",i);
           th2[i] = new TH1D(th2name,th2name,5,WGbin);
           th2[i]->Sumw2();

       sprintf(th2_barrel_name,"th2_barrel_%d",i);
           th2_barrel[i] = new TH1D(th2_barrel_name,th2_barrel_name,5,WGbin);
           th2_barrel[i]->Sumw2();


       sprintf(th2_endcap_name,"th2_endcap_%d",i);
           th2_endcap[i] = new TH1D(th2_endcap_name,th2_endcap_name,5,WGbin);
           th2_endcap[i]->Sumw2();
   }   

//cout<<"ok2"<<endl;
/*
   for (int k =0; k<=9; k++){
      cout<<eff_b_jet_tight[k]<<" "<<eff_b_jet_medium[k]<<" "<<eff_b_jet_loose[k]<<endl;

   }
*/
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

void test::read_csv_info()
{



}


void test::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
}
void test::endJob() {
   fout = new TFile(m_dataset, "RECREATE");
   fout->cd();
   if (m_region == "aqgc") {
      hist_WGmass_barrel_center->Write();
      hist_WGmass_barrel_jec_up->Write();
      hist_WGmass_barrel_jec_down->Write();
      hist_WGmass_barrel_jer_up->Write();
      hist_WGmass_barrel_jer_down->Write();
      hist_WGmass_endcap_center->Write();
      hist_WGmass_endcap_jec_up->Write();
      hist_WGmass_endcap_jec_down->Write();
      hist_WGmass_endcap_jer_up->Write();
      hist_WGmass_endcap_jer_down->Write();
      hist_WGmass_center->Write();
      hist_WGmass_jec_up->Write();
      hist_WGmass_jec_down->Write();
      hist_WGmass_jer_up->Write();
      hist_WGmass_jer_down->Write();

      hist_WGmass_barrel_photon_ID_up->Write();
      hist_WGmass_barrel_photon_ID_down->Write();
      hist_WGmass_barrel_electron_ID_up->Write();
      hist_WGmass_barrel_electron_ID_down->Write();
      hist_WGmass_barrel_electron_Reco_up->Write();
      hist_WGmass_barrel_electron_Reco_down->Write();
      hist_WGmass_barrel_electron_HLT_up->Write();
      hist_WGmass_barrel_electron_HLT_down->Write();
      hist_WGmass_barrel_electron_up->Write();
      hist_WGmass_barrel_electron_down->Write();
      hist_WGmass_barrel_muon_ID_up->Write();
      hist_WGmass_barrel_muon_ID_down->Write();
      hist_WGmass_barrel_muon_iso_up->Write();
      hist_WGmass_barrel_muon_iso_down->Write();
      hist_WGmass_barrel_muon_HLT_up->Write();
      hist_WGmass_barrel_muon_HLT_down->Write();
      hist_WGmass_barrel_muon_up->Write();
      hist_WGmass_barrel_muon_down->Write();

      hist_WGmass_endcap_photon_ID_up->Write();
      hist_WGmass_endcap_photon_ID_down->Write();
      hist_WGmass_endcap_electron_ID_up->Write();
      hist_WGmass_endcap_electron_ID_down->Write();
      hist_WGmass_endcap_electron_Reco_up->Write();
      hist_WGmass_endcap_electron_Reco_down->Write();
      hist_WGmass_endcap_electron_HLT_up->Write();
      hist_WGmass_endcap_electron_HLT_down->Write();
      hist_WGmass_endcap_electron_up->Write();
      hist_WGmass_endcap_electron_down->Write();
      hist_WGmass_endcap_muon_ID_up->Write();
      hist_WGmass_endcap_muon_ID_down->Write();
      hist_WGmass_endcap_muon_iso_up->Write();
      hist_WGmass_endcap_muon_iso_down->Write();
      hist_WGmass_endcap_muon_HLT_up->Write();
      hist_WGmass_endcap_muon_HLT_down->Write();
      hist_WGmass_endcap_muon_up->Write();
      hist_WGmass_endcap_muon_down->Write();

      hist_WGmass_photon_ID_up->Write();
      hist_WGmass_photon_ID_down->Write();
      hist_WGmass_electron_ID_up->Write();
      hist_WGmass_electron_ID_down->Write();
      hist_WGmass_electron_Reco_up->Write();
      hist_WGmass_electron_Reco_down->Write();
      hist_WGmass_electron_HLT_up->Write();
      hist_WGmass_electron_HLT_down->Write();
      hist_WGmass_electron_up->Write();
      hist_WGmass_electron_down->Write();
      hist_WGmass_muon_ID_up->Write();
      hist_WGmass_muon_ID_down->Write();
      hist_WGmass_muon_iso_up->Write();
      hist_WGmass_muon_iso_down->Write();
      hist_WGmass_muon_HLT_up->Write();
      hist_WGmass_muon_HLT_down->Write();
      hist_WGmass_muon_up->Write();
      hist_WGmass_muon_down->Write();

      for(int ii=0;ii<num;ii++){
         th2[ii]->Write();
         th2_barrel[ii]->Write();
         th2_endcap[ii]->Write();

      }


   }
   fout->Close();
   delete fout;
}

void test::hist_Sumw2()
{
   hist_WGmass_barrel_center->Sumw2();
   hist_WGmass_barrel_jec_up->Sumw2();
   hist_WGmass_barrel_jec_down->Sumw2();
   hist_WGmass_barrel_jer_up->Sumw2();
   hist_WGmass_barrel_jer_down->Sumw2();
   hist_WGmass_endcap_center->Sumw2();
   hist_WGmass_endcap_jec_up->Sumw2();
   hist_WGmass_endcap_jec_down->Sumw2();
   hist_WGmass_endcap_jer_up->Sumw2();
   hist_WGmass_endcap_jer_down->Sumw2();
   hist_WGmass_center->Sumw2();
   hist_WGmass_jec_up->Sumw2();
   hist_WGmass_jec_down->Sumw2();
   hist_WGmass_jer_up->Sumw2();
   hist_WGmass_jer_down->Sumw2(); 

      hist_WGmass_barrel_photon_ID_up->Sumw2();
      hist_WGmass_barrel_photon_ID_down->Sumw2();
      hist_WGmass_barrel_electron_ID_up->Sumw2();
      hist_WGmass_barrel_electron_ID_down->Sumw2();
      hist_WGmass_barrel_electron_Reco_up->Sumw2();
      hist_WGmass_barrel_electron_Reco_down->Sumw2();
      hist_WGmass_barrel_electron_HLT_up->Sumw2();
      hist_WGmass_barrel_electron_HLT_down->Sumw2();
      hist_WGmass_barrel_electron_up->Sumw2();
      hist_WGmass_barrel_electron_down->Sumw2();
      hist_WGmass_barrel_muon_ID_up->Sumw2();
      hist_WGmass_barrel_muon_ID_down->Sumw2();
      hist_WGmass_barrel_muon_iso_up->Sumw2();
      hist_WGmass_barrel_muon_iso_down->Sumw2();
      hist_WGmass_barrel_muon_HLT_up->Sumw2();
      hist_WGmass_barrel_muon_HLT_down->Sumw2();
      hist_WGmass_barrel_muon_up->Sumw2();
      hist_WGmass_barrel_muon_down->Sumw2();

      hist_WGmass_endcap_photon_ID_up->Sumw2();
      hist_WGmass_endcap_photon_ID_down->Sumw2();
      hist_WGmass_endcap_electron_ID_up->Sumw2();
      hist_WGmass_endcap_electron_ID_down->Sumw2();
      hist_WGmass_endcap_electron_Reco_up->Sumw2();
      hist_WGmass_endcap_electron_Reco_down->Sumw2();
      hist_WGmass_endcap_electron_HLT_up->Sumw2();
      hist_WGmass_endcap_electron_HLT_down->Sumw2();
      hist_WGmass_endcap_electron_up->Sumw2();
      hist_WGmass_endcap_electron_down->Sumw2();
      hist_WGmass_endcap_muon_ID_up->Sumw2();
      hist_WGmass_endcap_muon_ID_down->Sumw2();
      hist_WGmass_endcap_muon_iso_up->Sumw2();
      hist_WGmass_endcap_muon_iso_down->Sumw2();
      hist_WGmass_endcap_muon_HLT_up->Sumw2();
      hist_WGmass_endcap_muon_HLT_down->Sumw2();
      hist_WGmass_endcap_muon_up->Sumw2();
      hist_WGmass_endcap_muon_down->Sumw2();

      hist_WGmass_photon_ID_up->Sumw2();
      hist_WGmass_photon_ID_down->Sumw2();
      hist_WGmass_electron_ID_up->Sumw2();
      hist_WGmass_electron_ID_down->Sumw2();
      hist_WGmass_electron_Reco_up->Sumw2();
      hist_WGmass_electron_Reco_down->Sumw2();
      hist_WGmass_electron_HLT_up->Sumw2();
      hist_WGmass_electron_HLT_down->Sumw2();
      hist_WGmass_electron_up->Sumw2();
      hist_WGmass_electron_down->Sumw2();
      hist_WGmass_muon_ID_up->Sumw2();
      hist_WGmass_muon_ID_down->Sumw2();
      hist_WGmass_muon_iso_up->Sumw2();
      hist_WGmass_muon_iso_down->Sumw2();
      hist_WGmass_muon_HLT_up->Sumw2();
      hist_WGmass_muon_HLT_down->Sumw2();
      hist_WGmass_muon_up->Sumw2();
      hist_WGmass_muon_down->Sumw2();


   ///// fake lepton
   //h_fake_lepton->Sumw2();

}

void test::hist_Scale()
{
   if(m_type == "mc"){
      if(m_region == "aqgc"){
         hist_WGmass_barrel_center->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_jec_up->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_jec_down->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_jer_up->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_jer_down->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_center->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_jec_up->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_jec_down->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_jer_up->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_jer_down->Scale(1/(p_event - n_event));
         hist_WGmass_center->Scale(1/(p_event - n_event));
         hist_WGmass_jec_up->Scale(1/(p_event - n_event));
         hist_WGmass_jec_down->Scale(1/(p_event - n_event));
         hist_WGmass_jer_up->Scale(1/(p_event - n_event));
         hist_WGmass_jer_down->Scale(1/(p_event - n_event));

         hist_WGmass_barrel_photon_ID_up->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_photon_ID_down->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_electron_ID_up->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_electron_ID_down->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_electron_Reco_up->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_electron_Reco_down->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_electron_HLT_up->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_electron_HLT_down->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_electron_up->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_electron_down->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_muon_ID_up->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_muon_ID_down->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_muon_iso_up->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_muon_iso_down->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_muon_HLT_up->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_muon_HLT_down->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_muon_up->Scale(1/(p_event - n_event));
         hist_WGmass_barrel_muon_down->Scale(1/(p_event - n_event));

         hist_WGmass_endcap_photon_ID_up->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_photon_ID_down->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_electron_ID_up->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_electron_ID_down->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_electron_Reco_up->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_electron_Reco_down->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_electron_HLT_up->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_electron_HLT_down->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_electron_up->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_electron_down->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_muon_ID_up->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_muon_ID_down->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_muon_iso_up->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_muon_iso_down->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_muon_HLT_up->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_muon_HLT_down->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_muon_up->Scale(1/(p_event - n_event));
         hist_WGmass_endcap_muon_down->Scale(1/(p_event - n_event));

         hist_WGmass_photon_ID_up->Scale(1/(p_event - n_event));
         hist_WGmass_photon_ID_down->Scale(1/(p_event - n_event));
         hist_WGmass_electron_ID_up->Scale(1/(p_event - n_event));
         hist_WGmass_electron_ID_down->Scale(1/(p_event - n_event));
         hist_WGmass_electron_Reco_up->Scale(1/(p_event - n_event));
         hist_WGmass_electron_Reco_down->Scale(1/(p_event - n_event));
         hist_WGmass_electron_HLT_up->Scale(1/(p_event - n_event));
         hist_WGmass_electron_HLT_down->Scale(1/(p_event - n_event));
         hist_WGmass_electron_up->Scale(1/(p_event - n_event));
         hist_WGmass_electron_down->Scale(1/(p_event - n_event));
         hist_WGmass_muon_ID_up->Scale(1/(p_event - n_event));
         hist_WGmass_muon_ID_down->Scale(1/(p_event - n_event));
         hist_WGmass_muon_iso_up->Scale(1/(p_event - n_event));
         hist_WGmass_muon_iso_down->Scale(1/(p_event - n_event));
         hist_WGmass_muon_HLT_up->Scale(1/(p_event - n_event));
         hist_WGmass_muon_HLT_down->Scale(1/(p_event - n_event));
         hist_WGmass_muon_up->Scale(1/(p_event - n_event));
         hist_WGmass_muon_down->Scale(1/(p_event - n_event));


      }

      for(int ii=0;ii<num;ii++){
         th2[ii]->Scale(1/(p_event - n_event));
         th2_endcap[ii]->Scale(1/(p_event - n_event));
         th2_endcap[ii]->Scale(1/(p_event - n_event));

      }
   }
}
void test::init_sf()
{
      photon_ID_SF = 1;
      electron_ID_SF = 1;
      electron_Reco_SF = 1;
      electron_HLT_SF = 1;
      muon_ID_SF = 1;
      muon_iso_SF = 1;
      muon_HLT_SF = 1;

      photon_ID_up_SF = 1;
      electron_ID_up_SF = 1;
      electron_Reco_up_SF = 1;
      electron_HLT_up_SF = 1;
      muon_ID_up_SF = 1;
      muon_iso_up_SF = 1;
      muon_HLT_up_SF = 1;

      photon_ID_low_SF = 1;
      electron_ID_low_SF = 1;
      electron_Reco_low_SF = 1;
      electron_HLT_low_SF = 1;
      muon_ID_low_SF = 1;
      muon_iso_low_SF = 1;
      muon_HLT_low_SF = 1;

      btag_jet1_SF = 1;
      btag_jet1_up_SF = 1;
      btag_jet1_low_SF = 1;

      btag_jet2_SF = 1;
      btag_jet2_up_SF = 1;
      btag_jet2_low_SF = 1;

      pu_weight_SF = 1;
      cross_section_SF = 1;
}

void test::set_cut_value(TString year)
{ 
   if(year == "2016"){ //cut_value[3] = {0.8953, 0.6321, 0.2217}
      cut_value[0] = 0.8953;
      cut_value[1] = 0.6321;
      cut_value[2] = 0.2217;
      lumi = 35.92;
   }
   if(year == "2017"){ //cut_value[3] = {0.8001, 0.4941, 0.1522};
      cut_value[0] = 0.8001;
      cut_value[1] = 0.4941;
      cut_value[2] = 0.1522;
      lumi = 41.50;
   }
   if(year == "2018"){ //cut_value[3] = {0.7527, 0.4184, 0.1241};
      cut_value[0] = 0.7527;
      cut_value[1] = 0.4184;
      cut_value[2] = 0.1241;
      lumi = 59.74;
   }
}


Int_t test::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

Double_t test::btag_SF(Double_t pt, Double_t eta, Int_t pf, Double_t CSV, Double_t cut_value, TString workpoint, TString up_and_low){
   double tmp_SF = 1;
   if(fabs(eta)<2.5){
      if(fabs(pf)==5){
         if(CSV>cut_value){
            tmp_SF     = b_scale(up_and_low,workpoint,pt);
         }
         if(CSV<cut_value){
            tmp_SF     = (1-beff(workpoint,pt)*b_scale(up_and_low,workpoint,pt))/(1-beff(workpoint,pt));
         }
      }

      if(fabs(pf)==4){
         if(CSV>cut_value){
            tmp_SF     = c_scale(up_and_low,workpoint,pt);
         }
         if(CSV<cut_value){
            tmp_SF     = (1-ceff(workpoint,pt)*c_scale(up_and_low,workpoint,pt))/(1-ceff(workpoint,pt));
         }
      }

      if(fabs(pf)!=4 && fabs(pf)!=5){
         if(CSV>cut_value){
            tmp_SF     = l_scale(up_and_low,workpoint,pt);
         }
         if(CSV<cut_value){
            tmp_SF     = (1-leff(workpoint,pt)*l_scale(up_and_low,workpoint,pt))/(1-leff(workpoint,pt));
         }
      }
   }

   else{
      tmp_SF     = 1;
   }

   return tmp_SF;

}

// ----------------------------- b eff and scalef ----------------------------------------------
Double_t test::beff(TString workpoint, Double_t x)  //befficiency   x=pt
{
   if(workpoint == "tight"){
      if(x>=20 && x<30)return eff_b_jet_tight[0];
      if(x>=30 && x<50)return eff_b_jet_tight[1];
      if(x>=50 && x<70)return eff_b_jet_tight[2];
      if(x>=70 && x<100)return eff_b_jet_tight[3];
      if(x>=100 && x<140)return eff_b_jet_tight[4];
      if(x>=140 && x<200)return eff_b_jet_tight[5];
      if(x>=200 && x<300)return eff_b_jet_tight[6];
      if(x>=300 && x<600)return eff_b_jet_tight[7];
      if(x>=600 && x<1000)return eff_b_jet_tight[8];
      else return eff_b_jet_tight[9];
   }
   if(workpoint == "medium"){
      if(x>=20 && x<30)return eff_b_jet_medium[0];
      if(x>=30 && x<50)return eff_b_jet_medium[1];
      if(x>=50 && x<70)return eff_b_jet_medium[2];
      if(x>=70 && x<100)return eff_b_jet_medium[3];
      if(x>=100 && x<140)return eff_b_jet_medium[4];
      if(x>=140 && x<200)return eff_b_jet_medium[5];
      if(x>=200 && x<300)return eff_b_jet_medium[6];
      if(x>=300 && x<600)return eff_b_jet_medium[7];
      if(x>=600 && x<1000)return eff_b_jet_medium[8];
      else return eff_b_jet_medium[9];
   }
   if(workpoint == "loose"){
      if(x>=20 && x<30)return eff_b_jet_loose[0];
      if(x>=30 && x<50)return eff_b_jet_loose[1];
      if(x>=50 && x<70)return eff_b_jet_loose[2];
      if(x>=70 && x<100)return eff_b_jet_loose[3];
      if(x>=100 && x<140)return eff_b_jet_loose[4];
      if(x>=140 && x<200)return eff_b_jet_loose[5];
      if(x>=200 && x<300)return eff_b_jet_loose[6];
      if(x>=300 && x<600)return eff_b_jet_loose[7];
      if(x>=600 && x<1000)return eff_b_jet_loose[8];
      else return eff_b_jet_loose[9];
   }
}

Double_t test::b_scale(TString type, TString workpoint, Double_t x) //central scale   x=pt partonflavour b=5  c=4 
{
   TF1 * f1;

   if(workpoint == "loose"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_b_jet_loose[0],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "up"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_b_jet_loose[1],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_b_jet_loose[2],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_b_jet_loose[3],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_b_jet_loose[4],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_b_jet_loose[5],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_b_jet_loose[6],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_b_jet_loose[7],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_b_jet_loose[8],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_b_jet_loose[9],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "low"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_b_jet_loose[10],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_b_jet_loose[11],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_b_jet_loose[12],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_b_jet_loose[13],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_b_jet_loose[14],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_b_jet_loose[15],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_b_jet_loose[16],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_b_jet_loose[17],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_b_jet_loose[18],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

   }

   if(workpoint == "medium"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_b_jet_medium[0],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "up"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_b_jet_medium[1],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_b_jet_medium[2],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_b_jet_medium[3],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_b_jet_medium[4],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_b_jet_medium[5],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_b_jet_medium[6],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_b_jet_medium[7],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_b_jet_medium[8],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_b_jet_medium[9],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "low"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_b_jet_medium[10],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_b_jet_medium[11],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_b_jet_medium[12],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_b_jet_medium[13],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_b_jet_medium[14],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_b_jet_medium[15],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_b_jet_medium[16],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_b_jet_medium[17],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_b_jet_medium[18],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

   }

   if(workpoint == "tight"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_b_jet_tight[0],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "up"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_b_jet_tight[1],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_b_jet_tight[2],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_b_jet_tight[3],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_b_jet_tight[4],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_b_jet_tight[5],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_b_jet_tight[6],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_b_jet_tight[7],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_b_jet_tight[8],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_b_jet_tight[9],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "low"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_b_jet_tight[10],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_b_jet_tight[11],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_b_jet_tight[12],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_b_jet_tight[13],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_b_jet_tight[14],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_b_jet_tight[15],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_b_jet_tight[16],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_b_jet_tight[17],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_b_jet_tight[18],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

   }


}

// ----------------------------- c eff and scalef ------------------------------------
Double_t test::ceff(TString workpoint, Double_t x)  //befficiency   x=pt
{
   if(workpoint == "tight"){
      if(x>=20 && x<30)return eff_c_jet_tight[0];
      if(x>=30 && x<50)return eff_c_jet_tight[1];
      if(x>=50 && x<70)return eff_c_jet_tight[2];
      if(x>=70 && x<100)return eff_c_jet_tight[3];
      if(x>=100 && x<140)return eff_c_jet_tight[4];
      if(x>=140 && x<200)return eff_c_jet_tight[5];
      if(x>=200 && x<300)return eff_c_jet_tight[6];
      if(x>=300 && x<600)return eff_c_jet_tight[7];
      if(x>=600 && x<1000)return eff_c_jet_tight[8];
      else return eff_c_jet_tight[9];
   }
   if(workpoint == "medium"){
      if(x>=20 && x<30)return eff_c_jet_medium[0];
      if(x>=30 && x<50)return eff_c_jet_medium[1];
      if(x>=50 && x<70)return eff_c_jet_medium[2];
      if(x>=70 && x<100)return eff_c_jet_medium[3];
      if(x>=100 && x<140)return eff_c_jet_medium[4];
      if(x>=140 && x<200)return eff_c_jet_medium[5];
      if(x>=200 && x<300)return eff_c_jet_medium[6];
      if(x>=300 && x<600)return eff_c_jet_medium[7];
      if(x>=600 && x<1000)return eff_c_jet_medium[8];
      else return eff_c_jet_medium[9];
   }
   if(workpoint == "loose"){
      if(x>=20 && x<30)return eff_c_jet_loose[0];
      if(x>=30 && x<50)return eff_c_jet_loose[1];
      if(x>=50 && x<70)return eff_c_jet_loose[2];
      if(x>=70 && x<100)return eff_c_jet_loose[3];
      if(x>=100 && x<140)return eff_c_jet_loose[4];
      if(x>=140 && x<200)return eff_c_jet_loose[5];
      if(x>=200 && x<300)return eff_c_jet_loose[6];
      if(x>=300 && x<600)return eff_c_jet_loose[7];
      if(x>=600 && x<1000)return eff_c_jet_loose[8];
      else return eff_c_jet_loose[9];
   }


}

Double_t test::c_scale(TString type, TString workpoint, Double_t x) //central scale   x=pt partonflavour b=5  c=4 
{
   TF1 * f1;

   if(workpoint == "loose"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_b_jet_loose[0],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "up"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_c_jet_loose[1],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_c_jet_loose[2],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_c_jet_loose[3],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_c_jet_loose[4],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_c_jet_loose[5],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_c_jet_loose[6],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_c_jet_loose[7],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_c_jet_loose[8],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_c_jet_loose[9],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "low"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_c_jet_loose[10],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_c_jet_loose[11],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_c_jet_loose[12],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_c_jet_loose[13],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_c_jet_loose[14],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_c_jet_loose[15],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_c_jet_loose[16],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_c_jet_loose[17],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_c_jet_loose[18],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

   }

   if(workpoint == "medium"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_c_jet_medium[0],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "up"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_c_jet_medium[1],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_c_jet_medium[2],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_c_jet_medium[3],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_c_jet_medium[4],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_c_jet_medium[5],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_c_jet_medium[6],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_c_jet_medium[7],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_c_jet_medium[8],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_c_jet_medium[9],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "low"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_c_jet_medium[10],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_c_jet_medium[11],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_c_jet_medium[12],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_c_jet_medium[13],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_c_jet_medium[14],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_c_jet_medium[15],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_c_jet_medium[16],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_c_jet_medium[17],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_c_jet_medium[18],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

   }

   if(workpoint == "tight"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_c_jet_tight[0],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "up"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_c_jet_tight[1],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_c_jet_tight[2],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_c_jet_tight[3],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_c_jet_tight[4],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_c_jet_tight[5],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_c_jet_tight[6],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_c_jet_tight[7],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_c_jet_tight[8],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_c_jet_tight[9],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "low"){
         if(x>=20 && x<30)    {f1 = new TF1("f1",fuction_c_jet_tight[10],19.0,1001.);return  f1->Eval(x);}
         if(x>=30 && x<50)    {f1 = new TF1("f1",fuction_c_jet_tight[11],19.0,1001.);return  f1->Eval(x);}
         if(x>=50 && x<70)    {f1 = new TF1("f1",fuction_c_jet_tight[12],19.0,1001.);return  f1->Eval(x);}
         if(x>=70 && x<100)   {f1 = new TF1("f1",fuction_c_jet_tight[13],19.0,1001.);return  f1->Eval(x);}
         if(x>=100 && x<140)  {f1 = new TF1("f1",fuction_c_jet_tight[14],19.0,1001.);return  f1->Eval(x);}
         if(x>=140 && x<200)  {f1 = new TF1("f1",fuction_c_jet_tight[15],19.0,1001.);return  f1->Eval(x);}
         if(x>=200 && x<300)  {f1 = new TF1("f1",fuction_c_jet_tight[16],19.0,1001.);return  f1->Eval(x);}
         if(x>=300 && x<600)  {f1 = new TF1("f1",fuction_c_jet_tight[17],19.0,1001.);return  f1->Eval(x);}
         if(x>=600 && x<1000) {f1 = new TF1("f1",fuction_c_jet_tight[18],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

   }
}

// ----------------------------- l eff and scalef ---------------------
Double_t test::leff(TString workpoint, Double_t x)  //befficiency   x=pt
{
   if(workpoint == "tight"){
      if(x>=20 && x<30)return eff_l_jet_tight[0];
      if(x>=30 && x<50)return eff_l_jet_tight[1];
      if(x>=50 && x<70)return eff_l_jet_tight[2];
      if(x>=70 && x<100)return eff_l_jet_tight[3];
      if(x>=100 && x<140)return eff_l_jet_tight[4];
      if(x>=140 && x<200)return eff_l_jet_tight[5];
      if(x>=200 && x<300)return eff_l_jet_tight[6];
      if(x>=300 && x<600)return eff_l_jet_tight[7];
      if(x>=600 && x<1000)return eff_l_jet_tight[8];
      else return eff_l_jet_tight[9];
   }
   if(workpoint == "medium"){
      if(x>=20 && x<30)return eff_l_jet_medium[0];
      if(x>=30 && x<50)return eff_l_jet_medium[1];
      if(x>=50 && x<70)return eff_l_jet_medium[2];
      if(x>=70 && x<100)return eff_l_jet_medium[3];
      if(x>=100 && x<140)return eff_l_jet_medium[4];
      if(x>=140 && x<200)return eff_l_jet_medium[5];
      if(x>=200 && x<300)return eff_l_jet_medium[6];
      if(x>=300 && x<600)return eff_l_jet_medium[7];
      if(x>=600 && x<1000)return eff_l_jet_medium[8];
      else return eff_l_jet_medium[9];
   }
   if(workpoint == "loose"){
      if(x>=20 && x<30)return eff_l_jet_loose[0];
      if(x>=30 && x<50)return eff_l_jet_loose[1];
      if(x>=50 && x<70)return eff_l_jet_loose[2];
      if(x>=70 && x<100)return eff_l_jet_loose[3];
      if(x>=100 && x<140)return eff_l_jet_loose[4];
      if(x>=140 && x<200)return eff_l_jet_loose[5];
      if(x>=200 && x<300)return eff_l_jet_loose[6];
      if(x>=300 && x<600)return eff_l_jet_loose[7];
      if(x>=600 && x<1000)return eff_l_jet_loose[8];
      else return eff_l_jet_loose[9];
   }

}

Double_t test::l_scale(TString type, TString workpoint, Double_t x) //central scale   x=pt partonflavour b=5  c=4 
{
   TF1 * f1;

   if(workpoint == "loose"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_loose[0],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "up"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_loose[1],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "low"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_loose[2],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

   }

   if(workpoint == "medium"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_medium[0],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "up"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_medium[1],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "low"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_medium[2],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

   }

   if(workpoint == "tight"){
      if(type == "central"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_tight[0],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "up"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_tight[1],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

      if(type == "low"){
         if(x>20 && x<1000) {f1 = new TF1("f1",fuction_l_jet_tight[2],19.0,1001.);return  f1->Eval(x);}
         else return 1;
      }

   }

}






#endif // #ifdef test_cxx
