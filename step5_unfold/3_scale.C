#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TString.h"
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

using namespace std;
/*
 * input file list
 * type data: fake, true
 * channel: muon or electron
 */
int main(int argc, char** argv){
   TString filetxt = argv[1];
   TString indir = argv[2];
   TString outdir = argv[3];
   TString which_year = argv[4]; // 2016,2017,2018

   ifstream infile(filetxt);
   string buffer;
   TString infilename;
   system("mkdir -p " + outdir);
   int k=1;
   int n = 0;

   double lumi;
   if(which_year == "2016") {
      lumi = 35.92;
   }
   if(which_year == "2017") {
      lumi = 41.50;
   }
   if(which_year == "2018") {
      lumi = 59.74;
   }
 
cout<<"ok "<<lumi<<endl;
   //TString outname= outdir + "/scaled" + which_year + "_" + which_channel + "_" + which_type + "_" + which_btag_workpoint + "_btag_" + which_sample + ".root";
   while (k>0){
      getline (infile, buffer) ;
      n++;
      infilename = indir + "/" + buffer;
cout<<infilename<<endl;
      if(infilename.Contains(".root")==0) {k=-2; continue;}
      TString outname= outdir + "/scaled_"+ buffer; 
      //if(infilename.Contains("#")==0) continue;
      cout<<"file "<<n<<" : "<<infilename<<endl;
      cout<<"lumi : "<<lumi<<endl;
      if(infilename.Contains("#")) {
         cout<<"Do not run this file !!!"<<endl; 
         continue;
      }

      TFile *file1 =new TFile(infilename);
      TFile *fout = new TFile(outname, "RECREATE");
      TH1D	*hist_ptlep = (TH1D*)file1->Get("hist_ptlep");
      TH1D  *hist_photonEt = (TH1D*)file1->Get("hist_photonEt");
      TH1D  *hist_jet1pt = (TH1D*)file1->Get("hist_jet1pt");
      TH1D  *hist_Mva = (TH1D*)file1->Get("hist_Mva");
      TH2D  *hist2D_Mjj_detajj = (TH2D*)file1->Get("hist2D_Mjj_detajj");

      TH1D  *hist_gen_ptlep = (TH1D*)file1->Get("hist_gen_ptlep");
      TH1D  *hist_gen_photonEt = (TH1D*)file1->Get("hist_gen_photonEt");
      TH1D  *hist_gen_jet1pt = (TH1D*)file1->Get("hist_gen_jet1pt");
      TH1D  *hist_gen_Mva = (TH1D*)file1->Get("hist_gen_Mva");
      TH2D  *hist2D_gen_Mjj_detajj = (TH2D*)file1->Get("hist2D_gen_Mjj_detajj");

      TH1D  *hist_outgen_ptlep = (TH1D*)file1->Get("hist_outgen_ptlep");
      TH1D  *hist_outgen_photonEt = (TH1D*)file1->Get("hist_outgen_photonEt");
      TH1D  *hist_outgen_jet1pt = (TH1D*)file1->Get("hist_outgen_jet1pt");
      TH1D  *hist_outgen_Mva = (TH1D*)file1->Get("hist_outgen_Mva");
      TH2D  *hist2D_outgen_Mjj_detajj = (TH2D*)file1->Get("hist2D_outgen_Mjj_detajj");


   hist_ptlep->Scale(lumi);
   hist_photonEt->Scale(lumi);
   hist_jet1pt->Scale(lumi);
   hist_Mva->Scale(lumi);
   hist2D_Mjj_detajj->Scale(lumi);

   hist_gen_ptlep->Scale(lumi);
   hist_gen_photonEt->Scale(lumi);
   hist_gen_jet1pt->Scale(lumi);
   hist_gen_Mva->Scale(lumi);
   hist2D_gen_Mjj_detajj->Scale(lumi);

   hist_outgen_ptlep->Scale(lumi);
   hist_outgen_photonEt->Scale(lumi);
   hist_outgen_jet1pt->Scale(lumi);
   hist_outgen_Mva->Scale(lumi);
   hist2D_outgen_Mjj_detajj->Scale(lumi);


      fout->cd();

   hist_ptlep->Write();
   hist_photonEt->Write();
   hist_jet1pt->Write();
   hist_Mva->Write();
   hist2D_Mjj_detajj->Write();

   hist_gen_ptlep->Write();
   hist_gen_photonEt->Write();
   hist_gen_jet1pt->Write();
   hist_gen_Mva->Write();
   hist2D_gen_Mjj_detajj->Write();

   hist_outgen_ptlep->Write();
   hist_outgen_photonEt->Write();
   hist_outgen_jet1pt->Write();
   hist_outgen_Mva->Write();
   hist2D_outgen_Mjj_detajj->Write();

      fout->Close();
      file1->Close();
   }

   return 0;
}
