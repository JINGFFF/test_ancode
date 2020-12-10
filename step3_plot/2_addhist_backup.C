#include "TCanvas.h"
#include "TFile.h"
#include "TH1.h"
#include "TF1.h"
#include "TLatex.h"
#include "TMath.h"
#include "TROOT.h"
#include "TTree.h"
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TTreeReaderValue.h>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <TString.h>
#include <TLegend.h>
#include <THStack.h>
using namespace std;

void addhist(TString year, TString channel, TString indir, TString outdir, int addZA, int addWW, int addWZ, int addZZ, int addTTA, int addST_s, int addST_t, int addST_tbar, int addST_tw_anti_top, int addST_tw_top, int addWGJJ, int addWGJets, int addDATA, int addFakePhoton, int addFakeLepton, int addDoubleFake){

   TString xtitle;
   TString string[36] = {
   "barrel_nVtx","barrel_ptlep1","barrel_etalep1","barrel_mtVlepJECnew","barrel_ptVlepJEC",
   "barrel_photonet","barrel_photoneta","barrel_photonsceta","barrel_jet1pt","barrel_jet1eta",
   "barrel_jet2pt","barrel_jet2eta","barrel_Mjj","barrel_zepp","barrel_deltaeta","barrel_MET_et","barrel_Dphiwajj","barrel_Mla",
   "endcap_nVtx","endcap_ptlep1","endcap_etalep1","endcap_mtVlepJECnew","endcap_ptVlepJEC",
   "endcap_photonet","endcap_photoneta","endcap_photonsceta","endcap_jet1pt","endcap_jet1eta",
   "endcap_jet2pt","endcap_jet2eta","endcap_Mjj","endcap_zepp","endcap_deltaeta","endcap_MET_et","endcap_Dphiwajj","endcap_Mla"
   };
 
   TString LUMI;
   double lumi;
   if(year == "2016") { 
      lumi = 35.92; 
      LUMI = "35.92"; 
   }
   if(year == "2017") { 
      lumi = 4.794;//41.50;
      LUMI = "4.794"; 
   }
   if(year == "2018") {
      lumi = 59.74;
      LUMI = "59.74"; 
   }

   TString dataset_name;
   if(channel == "muon") dataset_name = "SingleMuon";
   if(channel == "electron") dataset_name = "SingleElectron";

   //file prepare
   //MC: ZA
   TFile * za1 = TFile::Open(indir + "/" + year + "_" + channel + "_mc_medium_btag_ZG.root");
   //MC: VV
   TFile * ww1 = TFile::Open(indir + "/" + year + "_" + channel + "_mc_medium_btag_WW.root");
   TFile * wz1 = TFile::Open(indir + "/" + year + "_" + channel + "_mc_medium_btag_WZ.root");
   TFile * zz1 = TFile::Open(indir + "/" + year + "_" + channel + "_mc_medium_btag_ZZ.root");

   //MC: TTA
   TFile * tta1 = TFile::Open(indir + "/" + year + "_" + channel + "_mc_medium_btag_TTG.root");
   //MC: STop
   TFile * st_s1 = TFile::Open(indir + "/" + year + "_" + channel + "_mc_medium_btag_ST_s.root");
   TFile * st_t1 = TFile::Open(indir + "/" + year + "_" + channel + "_mc_medium_btag_ST_t.root");
   TFile * st_tbar1 = TFile::Open(indir + "/" + year + "_" + channel + "_mc_medium_btag_ST_tbar.root");
   TFile * st_tw_anti_top1 = TFile::Open(indir + "/" + year + "_" + channel + "_mc_medium_btag_ST_tbarW.root");
   TFile * st_tw_top1 = TFile::Open(indir + "/" + year + "_" + channel + "_mc_medium_btag_ST_tW.root");

   //MC: WGJJ (signal)
   TFile * wgjj1 = TFile::Open(indir + "/" + year + "_" + channel + "_mc_medium_btag_WGJJ.root");
   //MC: WGJets
   TFile * wgjets1 = TFile::Open(indir + "/" + year + "_" + channel + "_mc_medium_btag_WGJets.root");

   //DATA
   TFile * data1 = TFile::Open(indir + "/" + year + "_" + channel + "_data_medium_btag_" + dataset_name + ".root");
   //fake photon data 
   TFile * data2 = TFile::Open(indir + "/" + year + "_" + channel + "_fakephoton_medium_btag_" + dataset_name + ".root");
   //fake lepton data
   TFile * data3 = TFile::Open(indir + "/" + year + "_" + channel + "_fakelepton_medium_btag_" + dataset_name + ".root");
   //double fake data
   TFile * data4 = TFile::Open(indir + "/" + year + "_" + channel + "_doublefake_medium_btag_" + dataset_name + ".root");

   //output file to save result (a lot of canvas)
   TFile* output = new TFile(outdir + "/result.root","RECREATE");

   cout<<"fine1"<<endl;

   //Draw Hist
   for(int i = 1; i<=36; i++){
      //set hist x title
cout<<i<<endl;
	  if(string[i-1].Contains("nVtx"))                xtitle = "nVtx";
      if(string[i-1].Contains("ptlep1"))              xtitle = "lepton1 p_{T} [GeV]";
      if(string[i-1].Contains("etalep1"))             xtitle = "lepton1 #eta";
      if(string[i-1].Contains("mtVlepJECnew"))        xtitle = "m_{T}(W) [GeV]";
      if(string[i-1].Contains("ptVlepJEC"))           xtitle = "ptVlepJEC [GeV]";
      if(string[i-1].Contains("photonet"))            xtitle = "photon p_{T} [GeV]";
      if(string[i-1].Contains("photoneta"))           xtitle = "photon #eta";
      if(string[i-1].Contains("photonsceta"))         xtitle = "super cluster photon #eta";
      if(string[i-1].Contains("jet1pt"))              xtitle = "jet1 p_{T} [GeV]";
      if(string[i-1].Contains("jet1eta"))             xtitle = "jet1 #eta";
      if(string[i-1].Contains("jet2pt"))              xtitle = "jet2 p_{T} [GeV]";
      if(string[i-1].Contains("jet2eta"))             xtitle = "jet2 #eta";
      if(string[i-1].Contains("Mjj"))                 xtitle = "M_{jj} [GeV]";
      if(string[i-1].Contains("zepp"))                xtitle = "zepp";
      if(string[i-1].Contains("MET_et"))              xtitle = "MET [GeV]";
      if(string[i-1].Contains("deltaeta"))            xtitle = "#Delta#eta_{jj}";
      if(string[i-1].Contains("Dphiwajj"))            xtitle = "|#phi_{W#gamma}-#phi_{j1,j2}|";
      if(string[i-1].Contains("Mla"))                 xtitle = "M_{l#gamma} [GeV]";
	  
      //set canvas
      TCanvas* cv = new TCanvas("cv_" + string[i-1], "cv_" + string[i-1], 900, 900);
      TPad* fPads1 = new TPad("pad1", "", 0.00, 0.25, 1.00, 1.00);
      TPad* fPads2 = new TPad("pad2", "", 0.00, 0.00, 1.00, 0.23);
      fPads1->SetFillColor(0);
      fPads1->SetLineColor(0);
      fPads2->SetFillColor(0);
      fPads2->SetLineColor(0);
      fPads1->SetBottomMargin(0.02);
      fPads1->SetTicks(1,1);
      fPads1->SetTicks(1,1);
      fPads2->SetTopMargin(0);
      fPads2->SetBottomMargin(0.4);
      fPads1->Draw();
      fPads2->Draw();

	  //set stack
	  THStack* hs = new THStack(string[i-1], "");


	  //setting for hist
	  //MC: ZA
	  TH1F* ZA1 = (TH1F*)za1->Get(string[i-1]);
      TH1F* ZA = (TH1F*)ZA1->Clone();
      ZA->SetFillColor(kSpring);
      ZA->SetLineColor(kBlack);
      ZA->SetLineWidth(1);
      ZA->Scale(lumi);

      //MC: VV
      TH1F* WW1 = (TH1F*)ww1->Get(string[i-1]);
      TH1F* WW = (TH1F*)WW1->Clone();
      WW->SetFillColor(kOrange + 6);
      WW->SetLineColor(kBlack);
      WW->SetLineWidth(1);
      WW->Scale(lumi);

      TH1F* WZ1 = (TH1F*)wz1->Get(string[i-1]);
      TH1F* WZ = (TH1F*)WZ1->Clone();
      WZ->SetFillColor(kOrange + 7);
      WZ->SetLineColor(kBlack);
      WZ->SetLineWidth(1);
      WZ->Scale(lumi);

      TH1F* ZZ1 = (TH1F*)zz1->Get(string[i-1]);
      TH1F* ZZ = (TH1F*)WZ1->Clone();
      ZZ->SetFillColor(kOrange + 8);
      ZZ->SetLineColor(kBlack);
      ZZ->SetLineWidth(1);
      ZZ->Scale(lumi);

	  //MC: TTA
	  TH1F* TTA1 = (TH1F*)tta1->Get(string[i-1]);
	  TH1F* TTA = (TH1F*)TTA1->Clone();
      TTA->SetFillColor(kMagenta);
      TTA->SetLineColor(kBlack);
      TTA->SetLineWidth(1);
      TTA->Scale(lumi);

      //MC: STop
      TH1F* ST_s1 = (TH1F*)st_s1->Get(string[i-1]);
      TH1F* ST_s = (TH1F*)ST_s1->Clone();
      ST_s->SetFillColor(kBlue - 1);
      ST_s->SetLineColor(kBlack);
      ST_s->SetLineWidth(1);
      ST_s->Scale(lumi);

      TH1F* ST_t1 = (TH1F*)st_t1->Get(string[i-1]);
      TH1F* ST_t = (TH1F*)ST_t1->Clone();
      ST_t->SetFillColor(kBlue - 2);
      ST_t->SetLineColor(kBlack);
      ST_t->SetLineWidth(1);
      ST_t->Scale(lumi);

      TH1F* ST_tbar1 = (TH1F*)st_tbar1->Get(string[i-1]);
      TH1F* ST_tbar = (TH1F*)ST_tbar1->Clone();
      ST_tbar->SetFillColor(kBlue - 3);
      ST_tbar->SetLineColor(kBlack);
      ST_tbar->SetLineWidth(1);
      ST_tbar->Scale(lumi);

      TH1F* ST_tw_anti_top1 = (TH1F*)st_tw_anti_top1->Get(string[i-1]);
      TH1F* ST_tw_anti_top = (TH1F*)ST_tw_anti_top1->Clone();
      ST_tw_anti_top->SetFillColor(kBlue + 1);
      ST_tw_anti_top->SetLineColor(kBlack);
      ST_tw_anti_top->SetLineWidth(1);
      ST_tw_anti_top->Scale(lumi);

      TH1F* ST_tw_top1 = (TH1F*)st_tw_top1->Get(string[i-1]);
      TH1F* ST_tw_top = (TH1F*)ST_tw_top1->Clone();
      ST_tw_top->SetFillColor(kBlue + 2);
      ST_tw_top->SetLineColor(kBlack);
      ST_tw_top->SetLineWidth(1);
      ST_tw_top->Scale(lumi);
	  

      //MC: WGJJ (signal)
      TH1F* WGJJ1 = (TH1F*)wgjj1->Get(string[i-1]);
      TH1F* WGJJ = (TH1F*)WGJJ1->Clone();
      WGJJ->SetFillColor(kRed);
      WGJJ->SetLineColor(kBlack);
      WGJJ->SetLineWidth(1);
      WGJJ->Scale(lumi);
	

      //MC: WGJets
      TH1F* WGJETS1 = (TH1F*)wgjets1->Get(string[i-1]);
      TH1F* WGJETS = (TH1F*)WGJETS1->Clone();       
      WGJETS->SetFillColor(kAzure + 10);
      WGJETS->SetLineColor(kBlack);
      WGJETS->SetLineWidth(1);
      WGJETS->Scale(lumi);

      //DATA: fake photon
      TH1F* DATA2 = (TH1F*)data2->Get(string[i-1]);
      TH1F* fp = (TH1F*)DATA2->Clone();
      fp->SetFillColor(kGray + 2);
      fp->SetLineColor(kBlack);
      fp->SetLineWidth(1);
	
      //DATA: fake lepton
      TH1F* DATA3 = (TH1F*)data3->Get(string[i-1]);
      TH1F* fl = (TH1F*)DATA3->Clone();
      fl->SetFillColor(kYellow - 7);
      fl->SetLineColor(kBlack);
      fl->SetLineWidth(1);
        
      //DATA: double fake
      TH1F* DATA4 = (TH1F*)data4->Get(string[i-1]);
      TH1F* df = (TH1F*)DATA4->Clone();
      df->SetFillColor(kCyan + 2);
      df->SetLineColor(kBlack);
      df->SetLineWidth(1);

	  fp->Add(df,-1);
	  fl->Add(df,-1);	
      //cout<<"fine3"<<endl;

      //DATA
      TH1F* DATA1 = (TH1F*)data1->Get(string[i-1]);
      TH1F* DATA = (TH1F*)DATA1->Clone();
      DATA->SetLineColor(kBlack);
      DATA->SetLineWidth(1);
      DATA->GetXaxis()->SetTitle(xtitle);
      DATA->GetYaxis()->SetTitle("Events/bin");
      DATA->SetMarkerStyle(20);
      DATA->SetMarkerSize(1.2);
      DATA->SetStats(kFALSE);

      TH1F* hmc = (TH1F*)ZA->Clone();
      hmc->Reset();
      if( addZA==1)               hmc->Add(ZA,1);
      if( addWW==1)               hmc->Add(WW,1);
      if( addWZ==1)               hmc->Add(WZ,1);
      if( addZZ==1)               hmc->Add(ZZ,1);
      if( addTTA==1)              hmc->Add(TTA,1);
      if( addST_s==1) 	          hmc->Add(ST_s,1);
      if( addST_t==1)             hmc->Add(ST_t,1);
      if( addST_tbar==1)          hmc->Add(ST_tbar,1);
      if( addST_tw_anti_top==1)   hmc->Add(ST_tw_anti_top,1);
      if( addST_tw_top==1)        hmc->Add(ST_tw_top,1);
      if( addWGJJ==1)             hmc->Add(WGJJ,1);
      if( addWGJets==1)           hmc->Add(WGJETS,1);
      if( addFakePhoton==1)       hmc->Add(fp,1);
      if( addFakeLepton==1)       hmc->Add(fl,1);
      if( addDoubleFake==1)       hmc->Add(df,1);

      //stack the hist
      TH1F* h = (TH1F*)ZA->Clone();
      h->Reset();
      hs->Add(h);
      if( addWGJJ==1)             hs->Add(WGJJ);
      if( addZA==1)               hs->Add(ZA);
      if( addTTA==1)              hs->Add(TTA);
      if( addST_s==1)             hs->Add(ST_s);
      if( addST_t==1)             hs->Add(ST_t);
      if( addST_tbar==1)          hs->Add(ST_tbar);
      if( addST_tw_anti_top==1)   hs->Add(ST_tw_anti_top);
      if( addST_tw_top==1)        hs->Add(ST_tw_top);
      if( addWW==1)               hs->Add(WW);
      if( addWZ==1)               hs->Add(ZZ);
      if( addZZ==1)               hs->Add(ZZ);
      if( addDoubleFake==1)       hs->Add(df);
      if( addFakeLepton==1)       hs->Add(fl);
      if( addFakePhoton==1)       hs->Add(fp);
      if( addWGJets==1)           hs->Add(WGJETS);
 
      //set legend
      TLegend* leg1 = new TLegend(0.35,0.6,0.53,0.89);

      leg1->SetBorderSize(0);

      if( addDATA==1)             leg1->AddEntry(DATA,  "DATA","lp");
      if( addWGJJ==1)             leg1->AddEntry(WGJJ,  "WGJJ","f");
      if( addWGJets==1)           leg1->AddEntry(WGJETS,"WGJets","f");
      if( addDoubleFake==1)       leg1->AddEntry(df,    "Double Fake","f");
      if( addFakePhoton==1)       leg1->AddEntry(fp,    "Fake Photon","f");
      if( addFakeLepton==1)       leg1->AddEntry(fl,    "Fake Lepton","f");

      TLegend* leg2 = new TLegend(0.55,0.6,0.68,0.89);
      leg2->SetBorderSize(0);
      if( addZA==1)               leg2->AddEntry(ZA,    "ZA","f");
      if( addWW==1)               leg2->AddEntry(WW,    "WW","f");
      if( addWZ==1)               leg2->AddEntry(WZ,    "WZ","f");
      if( addZZ==1)               leg2->AddEntry(ZZ,    "ZZ","f");
      if( addTTA==1)              leg2->AddEntry(TTA,   "TTA","f");


      TLegend* leg3 = new TLegend(0.7,0.6,0.88,0.89);
      leg3->SetBorderSize(0);
      if( addST_s==1)             leg3->AddEntry(ST_s,    "STop_s","f");
      if( addST_t==1)             leg3->AddEntry(ST_t,    "STop_t","f");
      if( addST_tbar==1)          leg3->AddEntry(ST_tbar,    "STop_tbar","f");
      if( addST_tw_anti_top==1)   leg3->AddEntry(ST_tw_anti_top,    "STop_tbarW","f");
      if( addST_tw_top==1)        leg3->AddEntry(ST_tw_top,    "STop_tW","f");

      //DATA and MC pad
	  fPads1->cd();

      hs->Draw("HIST");
      hs->GetYaxis()->SetTitle("Events/bin");
      hs->GetYaxis()->SetTitleSize(0.04);
      hs->GetYaxis()->SetTickLength(0.02);
      hs->GetYaxis()->SetTitleOffset(1.3);
      hs->GetXaxis()->SetLabelSize(0.0);

      double maximumMC       = 1.6 * hmc->GetMaximum();
      double maximumDATA     = 1.6 * DATA->GetMaximum();
      double maximumForStack = (maximumMC > maximumDATA ? maximumMC : maximumDATA);

      hs->SetMaximum(maximumForStack);

      float H = fPads1->GetWh();
      float W = fPads1->GetWw();
      float l = fPads1->GetLeftMargin();
      float t = fPads1->GetTopMargin();
      float r = fPads1->GetRightMargin();
      float b = fPads1->GetBottomMargin();

      TString  lumiText = LUMI + " fb^{-1} (13 TeV)";
      float lumiTextSize     = 0.5;
      float lumiTextOffset   = 0.2;

      TString cmsText     = "CMS";
      float cmsTextFont   = 61; 
      float cmsTextSize      = 0.75;
      float cmsTextOffset    = 0.1; 

      TString extraText   = "Preliminary";
      float extraTextFont = 52;
      float extraOverCmsTextSize  = 0.76;

      float relPosX    = 0.045;
      float relPosY    = 0.035;
      float relExtraDY = 1.2;

      int alignY_ =3, alignX_ = 1;
      int align_ = 10*alignX_ + alignY_;

      TLatex latex;
      latex.SetNDC();
      latex.SetTextAngle(0);
      latex.SetTextColor(kBlack);


      latex.SetTextFont(42);
      latex.SetTextAlign(31);
      latex.SetTextSize(lumiTextSize*t);
      latex.DrawLatex(1-r,1-t+lumiTextOffset*t,lumiText);

      float posX_=0;
      float posY_ = 1-t - relPosY*(1-t-b);
      latex.SetTextFont(cmsTextFont);
      latex.SetTextSize(0.8*cmsTextSize*t);
      latex.SetTextAlign(align_);
      latex.DrawLatex(1.3*l, posY_, cmsText);

      float extraTextSize = extraOverCmsTextSize*cmsTextSize;

      latex.SetTextFont(extraTextFont);
      latex.SetTextAlign(align_);
      latex.SetTextSize(0.8*extraTextSize*t);
      latex.DrawLatex(1.3*l, posY_- relExtraDY*cmsTextSize*t, extraText);

cout<<i<<"2"<<endl;

      if( addDATA==1) DATA->Draw("SAME p");
      leg1->Draw();
      leg2->Draw();
      leg3->Draw();
//cout<<i<<"3"<<endl;

      //DATA DIVIDE MC
      fPads2->cd();
      fPads2->SetGridy();
      TH1F* divide = (TH1F*)DATA->Clone();
      divide->Divide(hmc);
      divide->SetTitle("");
      divide->SetStats(kFALSE);
      divide->SetLineColor(kBlue);
      divide->SetLineWidth(1);
      divide->GetYaxis()->SetTitle("Data/MC");
      divide->GetYaxis()->CenterTitle();
      divide->GetYaxis()->SetTitleSize(0.1);
      divide->GetYaxis()->SetTitleOffset(0.3);
      divide->GetYaxis()->SetLabelSize(0.07);
      divide->GetYaxis()->SetRangeUser(0,2);
      divide->GetYaxis()->SetNdivisions(-5);
      divide->GetYaxis()->SetTickLength(0.02);

      divide->GetXaxis()->SetTitle(xtitle);
      divide->GetXaxis()->SetLabelSize(0.12);
      divide->GetXaxis()->SetTitleSize(0.13);
      divide->SetMarkerSize(0.8);
//cout<<i<<"3"<<endl;

      //divide->GetXaxis()->CenterTitle();
      divide->Draw("p ");
      double xlow = divide->GetXaxis()->GetXmin();
      double xhigh = divide->GetXaxis()->GetXmax();
      TF1*f1 = new TF1("f1","1",-500,500);
      f1->SetLineStyle(2);
      f1->Draw("same");
//cout<<i<<"3"<<endl;

      cv->SaveAs(outdir + "/"+ year + "_" + channel + "_" + string[i-1]+".png");
cout<<i<<"3"<<endl;

      output->cd();
      cv->Write();
cout<<i<<"3"<<endl;	
   }

   output->Close();
}   

int main(int argc, char** argv) {
   TString indir = argv[1];
   TString outdir = argv[2];
   TString year = argv[3];
   TString channel = argv[4];
   system("mkdir -p " + outdir);
   int addZA, addWW, addWZ, addZZ, addTTA, addST_s, addST_t, addST_tbar, addST_tw_anti_top, addST_tw_top, addWGJJ, addWGJets;
   int addDATA, addFakePhoton, addFakeLepton, addDoubleFake;
   //code help
   cout<<"***********************************************************"<<endl;
   cout<<"*                                                         *"<<endl;
   cout<<"*  This program is used to add hist, you should tell it   *"<<endl;
   cout<<"*  which hist should be add.                              *"<<endl;
   cout<<"*                                                         *"<<endl;
   cout<<"*  The hist sets to 1, means to add.                      *"<<endl;
   cout<<"*  There are two kinds of hist.                           *"<<endl;
   cout<<"*                                                         *"<<endl;
   cout<<"*  The hists of MC are   :                                *"<<endl;
   cout<<"*  addZA, addVV, addTTA, addSTop, addWGJJ, addWGJets      *"<<endl;
   cout<<"*  The hists of DATA are :                                *"<<endl;
   cout<<"*  addDATA, addFakeLepton, addFakePhoton, addDoubleFake   *"<<endl;
   cout<<"*                                                         *"<<endl;
   cout<<"***********************************************************"<<endl<<endl;
    
   cout<<">>>>>>>>>>>>>>>>>>>> Starting adding hists  <<<<<<<<<<<<<<<"<<endl<<endl;
    
   //for MC
   cout<<"Prepare hists of MC:"<<endl;
   cout<<"addZA              = ";
   cin>>addZA;

   cout<<"addWW              = ";
   cin>>addWW;

   cout<<"addWZ              = ";
   cin>>addWZ;

   cout<<"addZZ              = ";
   cin>>addZZ;

   cout<<"addTTA             = ";
   cin>>addTTA;

   cout<<"addST_s            = ";
   cin>>addST_s;

   cout<<"addST_t            = ";
   cin>>addST_t;

   cout<<"addST_tbar         = ";
   cin>>addST_tbar;

   cout<<"addST_tw_anti_top  = ";
   cin>>addST_tw_anti_top;

   cout<<"addST_tw_top       = ";
   cin>>addST_tw_top;

   cout<<"addWGJJ            = ";
   cin>>addWGJJ;

   cout<<"addWGJets          = ";
   cin>>addWGJets;
   cout<<endl;

   //for DATA
   cout<<"Prepare hists of DATA:"<<endl;
   cout<<"addDATA         = ";
   cin>>addDATA;

   cout<<"addFakePhoton   = ";
   cin>>addFakePhoton;

   cout<<"addFakeLepton   = ";
   cin>>addFakeLepton;

   cout<<"addDoubleFake   = ";
   cin>>addDoubleFake;

   cout<<endl;
   addhist(year, channel, indir, outdir, addZA, addWW, addWZ, addZZ, addTTA, addST_s, addST_t, addST_tbar, addST_tw_anti_top, addST_tw_top, addWGJJ, addWGJets, addDATA, addFakePhoton, addFakeLepton, addDoubleFake);

   cout<<endl;
   cout<<"Ending everything, thanks for your using."<<endl;
   cout<<"See you next time!"<<endl;

   return 0;
}

