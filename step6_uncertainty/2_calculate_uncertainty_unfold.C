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
#include "TCanvas.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2D.h"
#include "TF1.h"
#include "TLatex.h"
#include "TMath.h"
#include "TROOT.h"
#include "TTree.h"
#include <TString.h>
#include <TLegend.h>
#include <THStack.h>
using namespace std;

using namespace std;
/*
 * input file list
 * type data: fake, true
 * channel: muon or electron
 */
int main(int argc, char** argv){
   TString inputdir = argv[1];
   TString outdir = argv[2];
   TString which_year = argv[3]; // 2016,2017,2018
   TString which_type = argv[4]; //data, fakelepton, fakephoton, doublefake, mc
   TString which_region = argv[5]; // aqgc, signal, control
   TString which_sample = argv[6]; // SingleMuon, ...
   TString which_btag_workpoint = argv[7]; // tight, medium, loose ...

   system("mkdir -p " + outdir);
   system("mkdir -p " + outdir+"/graph");

//   int k=1;
   int n = 0;
 
   TString infilename= inputdir + "/" + which_year + "_" + which_type + "_" + which_region + "_" +  which_btag_workpoint + "_btag_" + which_sample + "_uncertainty.root";
   TString outname= outdir + "/" + which_year + "_" + which_type + "_" + which_region + "_" +  which_btag_workpoint + "_btag_" + which_sample + "_uncertainty_plot";

   TFile* output = new TFile(outname+".root","RECREATE");

   TString var[7] = {"ptlep", "photonEt", "jet1pt", "Mva", "Mjj_Signal", "Mjj_Control", "Mjj_detajj"};

   TString uncertainty_hist_name[9] = {"photon_ID_", "electron_ID_", "electron_Reco_", "electron_HLT_", "muon_ID_", "muon_iso_", "muon_HLT_", "JEC_", "JER_"};

   double lumi;
   if(which_year == "2016") {
      lumi = 35.92;
      //LUMI = "35.92";
   }
   if(which_year == "2017") {
      lumi = 4.794;//41.50;
      //LUMI = "4.794";
   }
   if(which_year == "2018") {
      lumi = 59.74;
      //LUMI = "59.74";
   }

   if(which_type !="mc") lumi = 1.;
    double WGbin[6] = {150,400,600,800, 1000, 2000};
    ofstream outFile;  
    outFile.open(outname+".txt", ios::out);
   
   TString var_name = var[0];
   for(int i=0; i<9; i++){
      TFile*input = new TFile (infilename);
      TH1D * h_uncertainty = new TH1D("hist_"+var_name+"_"+uncertainty_hist_name[i]+"_uncertainty","hist_"+var_name+"_"+uncertainty_hist_name[i]+"_uncertainty", 9, 0, 9);

      TH1D * h_center   = (TH1D*)input->Get("hist_"+var_name+"_");
      TH1D * h_up       = (TH1D*)input->Get("hist_"+var_name+"_"+uncertainty_hist_name[i]+"up");
      TH1D * h_down     = (TH1D*)input->Get("hist_"+var_name+"_"+uncertainty_hist_name[i]+"down");

      h_center->Scale(lumi);
      h_up->Scale(lumi);
      h_down->Scale(lumi);

      h_center->SetLineColor(kBlack);
      h_up->SetLineColor(kBlue);
      h_down->SetLineColor(kRed);

      h_center->SetStats(kFALSE);
      h_up->SetStats(kFALSE);
      h_down->SetStats(kFALSE);
  
      outFile << which_sample<< "_"<<uncertainty_hist_name[i] <<" = [ ";
      int Nbins = h_center->GetNbinsX();
      double uncertainty[Nbins];
	  double bincontent[Nbins],bincontent_up[Nbins],bincontent_down[Nbins];
      for(int j=0;j<Nbins;j++){
            bincontent[j] = h_center->GetBinContent(j+1);
            bincontent_up[j] = h_up->GetBinContent(j+1);
            bincontent_down[j] = h_down->GetBinContent(j+1);
            double max;
            if(fabs(bincontent_up[j]-bincontent[j])>fabs(bincontent[j]-bincontent_down[j])){ 
               max = fabs(bincontent_up[j]-bincontent[j]);
            }
            else {
               max = fabs(bincontent[j]-bincontent_down[j]); 
            }
    
            if(bincontent[j]>0) uncertainty[j] = max/bincontent[j];
            else uncertainty[j] =0;
            h_uncertainty->SetBinContent(j+1,uncertainty[j]);           
            
            if(j<(Nbins-1)) outFile<<1+uncertainty[j]<<", ";
            else outFile<<1+uncertainty[j]<<"] "<<endl;
      }
      //outFile << which_sample << "_"<<uncertainty_hist_name[i] <<" = [ "
      //outFile<<1+uncertainty[0]<<", "<<1+uncertainty[1]<<", "<<1+uncertainty[2]<<", "<<1+uncertainty[3]<<", "<<1+uncertainty[4]<<", "<<1+uncertainty[5]<<", "<<1+uncertainty[6]<<", "<<1+uncertainty[7]<<", "<<1+uncertainty[8]<<"]"<<endl;
      TCanvas * c1 = new TCanvas(uncertainty_hist_name[i],uncertainty_hist_name[i],900,900);
     
      output->cd();
      h_uncertainty->Write();
      c1->cd();
      h_uncertainty->Draw("hist");

      c1->SaveAs(outdir+"/graph/test_"+which_sample+"_"+which_region+"_"+uncertainty_hist_name[i]+".png");
      c1->SaveAs(outdir+"/graph/test_"+which_sample+"_"+which_region+"_"+uncertainty_hist_name[i]+".pdf");

      input->Close();
   }

   output->Close();
   return 0;
}
