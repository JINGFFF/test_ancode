#include "plugin/test2.h"
#include "plugin/test2.C"
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
   TString outdir = argv[2];
   TString which_year = argv[3]; // 2016,2017,2018
   TString which_channel = argv[4]; // muon, electron
   TString which_type = argv[5]; //data, fakelepton, fakephoton, doublefake, mc
   TString which_sample = argv[6]; // SingleMuon, ...
   TString which_btag_workpoint = argv[7]; // tight, medium, loose ...

   ifstream infile(filetxt);
   string buffer;
   TString infilename;
   system("mkdir -p " + outdir);
   int k=1;
   int n = 0;
   
   TString outname= outdir + "/" + which_year + "_" + which_channel + "_" + which_type + "_" + which_btag_workpoint + "_btag_" + which_sample + ".root";

   cout<<"\033[34myear            : "<<which_year<<"\033[0m"<<endl;
   cout<<"\033[34mchannel         : "<<which_channel<<" channel"<<"\033[0m"<<endl;
   cout<<"\033[34mtype            : "<<which_type<<"\033[0m"<<endl;
   cout<<"\033[34msample          : "<<which_sample<<"\033[0m"<<endl;
   cout<<"\033[34mbtag workpoint  : "<<which_btag_workpoint<<"\033[0m"<<endl;

   cout<<"\033[34minput file list : "<<filetxt<<"\033[0m"<<endl;
   cout<<"\033[34moutput dir     : "<<outdir<<"\033[0m"<<endl<<endl;

   clock_t startTime,endTime;
   startTime = clock();

   test m;
   m.m_dataset = outdir;
   m.m_year = which_year;
   m.m_channel = which_channel;
   m.m_sample = which_sample;
   m.m_type = which_type;
   m.m_btag_workpoint = which_btag_workpoint;
   m.Init();
   while (k>0){
      getline (infile, buffer) ;
      n++;
      infilename = buffer;
      if(infilename.Contains(".root")==0) {k=-2; continue;}

      //if(infilename.Contains("#")==0) continue;
      cout<<"file "<<n<<" : "<<infilename<<endl;
      if(infilename.Contains("#")) {
         cout<<"Do not run this file !!!"<<endl; 
         continue;
      }

      TFile *file1 =new TFile(infilename);

      //TTree *tree1 = (TTree*) file1->Get("PKUCandidates");
      //m.Init();
      TDirectory * dir1 = (TDirectory*)file1->Get("treeDumper");
      m.Loop(dir1);
      endTime = clock();
      file1->Close();
      cout<<"The run time is: "<<(double)(endTime - startTime)/CLOCKS_PER_SEC<<"s"<<endl<<endl;
   }
   m.hist_Scale();
   m.endJob();
   endTime = clock();

   cout<<"The total run time is: "<<(double)(endTime - startTime)/CLOCKS_PER_SEC<<"s"<<endl<<endl;
   return 0;
}