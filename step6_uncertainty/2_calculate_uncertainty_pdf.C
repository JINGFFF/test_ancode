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
   //TString which_channel = argv[4]; // muon, electron
   TString which_type = argv[4]; //data, fakelepton, fakephoton, doublefake, mc
   TString which_region = argv[5]; // aqgc, signal, control
   TString which_sample = argv[6]; // SingleMuon, ...
   TString which_btag_workpoint = argv[7]; // tight, medium, loose ...

   system("mkdir -p " + outdir);
   system("mkdir -p " + outdir+"/graph");

   int k=1;
   int n = 0;
  
   TString infilename= inputdir + "/" + which_year + "_" + which_type + "_" + which_region + "_" +  which_btag_workpoint + "_btag_" + which_sample + "_uncertainty.root";
 
   TString outname= outdir + "/" + which_year + "_" + which_type + "_" + which_region + "_" +  which_btag_workpoint + "_btag_" + which_sample + "_uncertainty_plot";
TFile* output = new TFile(outname+".root","RECREATE");

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

   TString var[7] = {"ptlep", "photonEt", "jet1pt", "Mva", "Mjj_Signal", "Mjj_Control", "Mjj_detajj"};

   if(which_type !="mc") lumi = 1.;
    double WGbin[6] = {150,400,600,800, 1000, 2000};
    ofstream outFile;  
    outFile.open(outname+".txt", ios::out);

   //TFile*input = new TFile (infilename);
   //cout<<"ok"<<endl;
if(!(which_sample == "WGJJ"||which_sample == "WGJets")) return 0;
   // pdf and scale uncertainty
   TFile*input2 = new TFile (infilename);
   input2->ls();
   int num = 400;
   TH1D*h_pdf[num];
cout<<"ok1"<<endl;


   for(int i_p = 0; i_p<400; i_p++){
      cout<<"ok1 "<<i_p<<endl;

      h_pdf[i_p]=(TH1D*)input2->Get(Form("hist_Mva_pdf_scale_%i",i_p));
      h_pdf[i_p]->Scale(lumi);
 
   }
cout<<"ok1"<<endl;
   int Nbins = h_pdf[2]->GetNbinsX();
cout<<"ok2 "<<Nbins<<endl;

   Double_t central_scale_value[Nbins],nlo_scale_value[2][Nbins];
   Double_t central_pdf_value[Nbins],nlo_pdf_value[102][Nbins];

   int scale_weight_index_1, scale_weight_index_2, scale_weight_index_3;
   int pdf_weight_index;
   if(which_sample == "WGJJ"){
      scale_weight_index_1 = 225;
      scale_weight_index_2 = 240;
      scale_weight_index_3 = 255;
      pdf_weight_index = 270;
   }
   else if(which_sample == "WGJets"){
      scale_weight_index_1 = 0;
      scale_weight_index_2 = 3;
      scale_weight_index_3 = 6;
      pdf_weight_index = 9;

   }

   for(int k_pdf = 0; k_pdf<Nbins; k_pdf++){
      central_scale_value[k_pdf]=h_pdf[scale_weight_index_1]->GetBinContent(k_pdf+1);

      nlo_scale_value[0][k_pdf]=h_pdf[scale_weight_index_2]->GetBinContent(k_pdf+1);

      nlo_scale_value[1][k_pdf]=h_pdf[scale_weight_index_3]->GetBinContent(k_pdf+1);

      central_pdf_value[k_pdf]=h_pdf[pdf_weight_index]->GetBinContent(k_pdf+1);
   }
cout<<"cenntral pdf = "<<central_pdf_value[0]<<" "<<central_pdf_value[1]<<" "<<central_pdf_value[2]<<" "<<central_pdf_value[3]<<" "<<central_pdf_value[4]<<endl;
cout<<"okokokokokokok"<<endl;
   for(int j1=0; j1<102;j1++){
      for(int k_pdf2 = 0; k_pdf2<Nbins; k_pdf2++){
         nlo_pdf_value[j1][k_pdf2]=h_pdf[j1+1+pdf_weight_index]->GetBinContent(k_pdf2+1);
         cout<<j1<<" pdf = "<<nlo_pdf_value[j1][0]<<" "<<nlo_pdf_value[j1][1]<<" "<<nlo_pdf_value[j1][2]<<" "<<nlo_pdf_value[j1][3]<<" "<<nlo_pdf_value[j1][4]<<endl;
      }
   }
cout<<"okokokokokokok"<<endl;

//if(which_sample == "WGJJ"){
   // Scale
   outFile <<which_sample << "_scale = [";
   double sum_scale, mean_scale, single_scale, average_scale,uncertainty_scale[5];
   for(Int_t j_scale=0;j_scale<Nbins;j_scale++){
      sum_scale=0;
      mean_scale=0;
      for(Int_t i_scale=0;i_scale<3;i_scale++){
         single_scale = pow(nlo_scale_value[i_scale][j_scale]-central_scale_value[j_scale],2);
         sum_scale = sum_scale + single_scale;
         mean_scale = (mean_scale + nlo_scale_value[i_scale][j_scale]);
         if(i_scale==(3-1)){
            mean_scale = (mean_scale + central_scale_value[j_scale])/(3+1);
            average_scale = sum_scale/3;
            uncertainty_scale[j_scale]=sqrt(average_scale)/mean_scale;
         }
         if(!(which_sample == "WGJJ"||which_sample == "WGJets")) uncertainty_scale[j_scale] = 0;

      }
      if(j_scale<(Nbins-1)) outFile<<1+uncertainty_scale[j_scale]<<", ";
      else outFile<<1+uncertainty_scale[j_scale]<<"] "<<endl;
   }
//cout<<"okokokokokokok"<<endl;

   //outFile <<which_sample << "_scale = ["<<1+uncertainty_scale[0]<<", "<<1+uncertainty_scale[1]<<", "<<1+uncertainty_scale[2]<<", "<<1+uncertainty_scale[3]<<", "<<1+uncertainty_scale[4]<<"]"<<endl;
//cout<<"okokokokokokok4"<<endl;


//cout<<"ok scale"<<endl;
   // pdf
   outFile <<which_sample << "_pdf = [";
   double sum_pdf, mean_pdf, single_pdf, average_pdf,uncertainty_pdf[5];
   for(Int_t j_pdf=0;j_pdf<Nbins;j_pdf++){
      sum_pdf=0;
      mean_pdf=0;
      for(Int_t i_pdf=0;i_pdf<102;i_pdf++){
cout<<j_pdf<<" nlo: "<<nlo_pdf_value[i_pdf][j_pdf]<<" cen: "<<central_pdf_value[j_pdf]<<endl;
         single_pdf = pow(nlo_pdf_value[i_pdf][j_pdf]-central_pdf_value[j_pdf],2);
         sum_pdf = sum_pdf + single_pdf;
         mean_pdf = mean_pdf + nlo_pdf_value[i_pdf][j_pdf];
cout<<i_pdf<<" : "<<single_pdf<<" "<<sum_pdf<<" "<<mean_pdf<<endl;
         if(i_pdf==(102-1)){
            mean_pdf = (mean_pdf + central_pdf_value[j_pdf])/(103+1);
            average_pdf = sum_pdf/103;
            uncertainty_pdf[j_pdf]=sqrt(average_pdf)/mean_pdf;
         }
         if(!(which_sample == "WGJJ"||which_sample == "WGJets")) uncertainty_pdf[j_pdf] = 0;

      }
      if(j_pdf<(Nbins-1)) outFile<<1+uncertainty_pdf[j_pdf]<<", ";
      else outFile<<1+uncertainty_pdf[j_pdf]<<"] "<<endl;

   }
   //outFile <<which_sample << "_pdf = ["<<1+uncertainty_pdf[0]<<", "<<1+uncertainty_pdf[1]<<", "<<1+uncertainty_pdf[2]<<", "<<1+uncertainty_pdf[3]<<", "<<1+uncertainty_pdf[4]<<"]"<<endl;


   output->Close();
   return 0;
}
