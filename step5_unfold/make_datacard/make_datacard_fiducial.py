#!/usr/bin/env python
import sys
import os
import re
from uncertainty_fid import *
import ROOT
from ROOT import gROOT, THStack, TH1D, TList, TFile, TH2D

indir = sys.argv[1]
outdir = sys.argv[2]
if not os.path.exists(outdir):
    os.makedirs(outdir)
#print(ST_s_photon_ID_[(i-1)*NbinsY + j - 1])
print ('-----begin to transfer TH2D to txt for Higgs-combine tool----- \n')

f_in_WGJJ = TFile.Open(indir + "/scaled_2018_mc_signal_medium_btag_WGJJ_unfold.root")
VBS = f_in_WGJJ.Get("hist2D_gen_Mjj_detajj")
VBS_out = f_in_WGJJ.Get("hist2D_outgen_Mjj_detajj")

f_in_ST_s = TFile.Open(indir + "/scaled_2018_mc_signal_medium_btag_ST_s_unfold.root")
#ST_s     =ROOT.TH2D()
#f_in_ST_s.GetObject("hist2D_Mjj_detajj",ST_s)
ST_s = f_in_ST_s.Get("hist2D_Mjj_detajj")

f_in_ST_t = TFile.Open(indir + "/scaled_2018_mc_signal_medium_btag_ST_t_unfold.root")
ST_t = f_in_ST_t.Get("hist2D_Mjj_detajj")

f_in_ST_tbar = TFile.Open(indir + "/scaled_2018_mc_signal_medium_btag_ST_tbar_unfold.root")
ST_tbar = f_in_ST_tbar.Get("hist2D_Mjj_detajj")

f_in_ST_tW = TFile.Open(indir + "/scaled_2018_mc_signal_medium_btag_ST_tW_unfold.root")
ST_tW = f_in_ST_tW.Get("hist2D_Mjj_detajj")

f_in_ST_tbarW = TFile.Open(indir + "/scaled_2018_mc_signal_medium_btag_ST_tbarW_unfold.root")
ST_tbarW = f_in_ST_tbarW.Get("hist2D_Mjj_detajj")

f_in_TTG = TFile.Open(indir + "/scaled_2018_mc_signal_medium_btag_TTG_unfold.root")
TTG = f_in_TTG.Get("hist2D_Mjj_detajj")

f_in_WGJets = TFile.Open(indir + "/scaled_2018_mc_signal_medium_btag_WGJets_unfold.root")
WGJets = f_in_WGJets.Get("hist2D_Mjj_detajj")

f_in_WW = TFile.Open(indir + "/scaled_2018_mc_signal_medium_btag_WW_unfold.root")
WW = f_in_WW.Get("hist2D_Mjj_detajj")

f_in_WZ = TFile.Open(indir + "/scaled_2018_mc_signal_medium_btag_WZ_unfold.root")
WZ = f_in_WZ.Get("hist2D_Mjj_detajj")

f_in_ZZ = TFile.Open(indir + "/scaled_2018_mc_signal_medium_btag_ZZ_unfold.root")
ZZ = f_in_ZZ.Get("hist2D_Mjj_detajj")

f_in_ZG = TFile.Open(indir + "/scaled_2018_mc_signal_medium_btag_ZG_unfold.root")
ZG = f_in_ZG.Get("hist2D_Mjj_detajj")

f_in_data = TFile.Open(indir + "/2018_data_signal_medium_btag_unfold.root")
data = f_in_data.Get("hist2D_Mjj_detajj")

f_in_doublefake = TFile.Open(indir + "/2018_doublefake_signal_medium_btag_unfold.root")
doublefake = f_in_doublefake.Get("hist2D_Mjj_detajj")

f_in_fakephoton = TFile.Open(indir + "/2018_fakephoton_signal_medium_btag_unfold.root")
fakephoton = f_in_fakephoton.Get("hist2D_Mjj_detajj")

f_in_fakelepton = TFile.Open(indir + "/2018_fakelepton_signal_medium_btag_unfold.root")
fakelepton = f_in_fakelepton.Get("hist2D_Mjj_detajj")


print ('>>>>begin to read bin content to the txt file>>>>')

NbinsX = VBS.GetNbinsX()
NbinsY = VBS.GetNbinsY()

for i in range(1,NbinsX + 1):
    for j in range(1,NbinsY + 1):
       f = open('%s/%s_%s_bin_%d.txt'%(outdir,'18', 'mubarrel', (i-1)*NbinsY + j - 1),'w')
       f.write('imax 1   number of channels\n')
       f.write('jmax 15   number of processes-1\n')
       f.write('kmax 1  number of nuisance parameters (sources of systematical uncertainties)\n')
       f.write('------------\n')
       f.write('# we have just one channel, in which we observe 0 events\n')
       f.write('bin mubarrel\n')
       bin_content = data.GetBinContent(i,j)
       #bin_content = ST_s.GetBinContent(i,j) + ST_t.GetBinContent(i,j) + ST_tbar.GetBinContent(i,j) + ST_tW.GetBinContent(i,j) + ST_tbarW.GetBinContent(i,j) + TTG.GetBinContent(i,j) + WW.GetBinContent(i,j) + WZ.GetBinContent(i,j) + ZZ.GetBinContent(i,j) + WGJets.GetBinContent(i,j) + ZG.GetBinContent(i,j)  + VBS.GetBinContent(i,j) + VBS_out.GetBinContent(i,j) + fakephoton.GetBinContent(i,j) + fakelepton.GetBinContent(i,j) - doublefake.GetBinContent(i,j)
       # bincontent of each precess
       ST_s_bincontent = ST_s.GetBinContent(i,j) if ST_s.GetBinContent(i,j)>0 else 0
       ST_t_bincontent = ST_t.GetBinContent(i,j) if ST_t.GetBinContent(i,j)>0 else 0
       ST_tbar_bincontent = ST_tbar.GetBinContent(i,j) if ST_tbar.GetBinContent(i,j)>0 else 0
       ST_tW_bincontent = ST_tW.GetBinContent(i,j) if ST_tW.GetBinContent(i,j)>0 else 0
       ST_tbarW_bincontent = ST_tbarW.GetBinContent(i,j) if ST_tbarW.GetBinContent(i,j)>0 else 0

       TTG_bincontent = TTG.GetBinContent(i,j) if TTG.GetBinContent(i,j)>0 else 0
       WW_bincontent = WW.GetBinContent(i,j) if WW.GetBinContent(i,j)>0 else 0
       WZ_bincontent = WZ.GetBinContent(i,j) if WZ.GetBinContent(i,j)>0 else 0
       ZZ_bincontent = ZZ.GetBinContent(i,j) if ZZ.GetBinContent(i,j)>0 else 0
       ZG_bincontent = ZG.GetBinContent(i,j) if ZG.GetBinContent(i,j)>0 else 0
       WGJets_bincontent = WGJets.GetBinContent(i,j) if WGJets.GetBinContent(i,j)>0 else 0
       VBS_bincontent = VBS.GetBinContent(i,j) if VBS.GetBinContent(i,j)>0 else 0
       VBS_out_bincontent = VBS_out.GetBinContent(i,j) if VBS_out.GetBinContent(i,j)>0 else 0

       doublefake_bincontent = doublefake.GetBinContent(i,j) if doublefake.GetBinContent(i,j)>0 else 0
       fakephoton_bincontent = fakephoton.GetBinContent(i,j) - doublefake_bincontent if fakephoton.GetBinContent(i,j)>0 else 0
       fakelepton_bincontent = fakelepton.GetBinContent(i,j) - doublefake_bincontent if fakelepton.GetBinContent(i,j)>0 else 0
       #doublefake_bincontent = doublefake.GetBinContent(i,j) if doublefake.GetBinContent(i,j)>0 else 0

       # bin error
       ST_s_binerror = ST_s.GetBinError(i,j)/ST_s_bincontent if ST_s_bincontent>0 else 0
       ST_s_binerror = ST_s_binerror if ST_s_binerror<1 else 1
       ST_s_binerror = ST_s_binerror+1

       ST_t_binerror = ST_t.GetBinError(i,j)/ST_t_bincontent if ST_t_bincontent>0 else 0
       ST_t_binerror = ST_t_binerror if ST_t_binerror<1 else 1
       ST_t_binerror = ST_t_binerror+1

       ST_tbar_binerror = ST_tbar.GetBinError(i,j)/ST_tbar_bincontent if ST_tbar_bincontent>0 else 0
       ST_tbar_binerror = ST_tbar_binerror if ST_tbar_binerror<1 else 1
       ST_tbar_binerror = ST_tbar_binerror+1

       ST_tW_binerror = ST_tW.GetBinError(i,j)/ST_tW_bincontent if ST_tW_bincontent>0 else 0
       ST_tW_binerror = ST_tW_binerror if ST_tW_binerror<1 else 1
       ST_tW_binerror = ST_tW_binerror+1

       ST_tbarW_binerror = ST_tbarW.GetBinError(i,j)/ST_tbarW_bincontent if ST_tbarW_bincontent>0 else 0
       ST_tbarW_binerror = ST_tbarW_binerror if ST_tbarW_binerror<1 else 1
       ST_tbarW_binerror = ST_tbarW_binerror+1

       TTG_binerror = TTG.GetBinError(i,j)/TTG_bincontent if TTG_bincontent>0 else 0
       TTG_binerror = TTG_binerror if TTG_binerror<1 else 1
       TTG_binerror = TTG_binerror+1

       WGJets_binerror = WGJets.GetBinError(i,j)/WGJets_bincontent if WGJets_bincontent>0 else 0
       WGJets_binerror = WGJets_binerror if WGJets_binerror<1 else 1
       WGJets_binerror = WGJets_binerror+1

       WW_binerror = WW.GetBinError(i,j)/WW_bincontent if WW_bincontent>0 else 0
       WW_binerror = WW_binerror if WW_binerror<1 else 1
       WW_binerror = WW_binerror+1

       WZ_binerror = WZ.GetBinError(i,j)/WZ_bincontent if WZ_bincontent>0 else 0
       WZ_binerror = WZ_binerror if WZ_binerror<1 else 1
       WZ_binerror = WZ_binerror+1

       ZZ_binerror = ZZ.GetBinError(i,j)/ZZ_bincontent if ZZ_bincontent>0 else 0
       ZZ_binerror = ZZ_binerror if ZZ_binerror<1 else 1
       ZZ_binerror = ZZ_binerror+1

       ZG_binerror = ZG.GetBinError(i,j)/ZG_bincontent if ZG_bincontent>0 else 0
       ZG_binerror = ZG_binerror if ZG_binerror<1 else 1
       ZG_binerror = ZG_binerror+1

       VBS_binerror = VBS.GetBinError(i,j)/VBS_bincontent if VBS_bincontent>0 else 0
       VBS_binerror = VBS_binerror if VBS_binerror<1 else 1
       VBS_binerror = VBS_binerror+1

       VBS_out_binerror = VBS_out.GetBinError(i,j)/VBS_out_bincontent if VBS_out_bincontent>0 else 0
       VBS_out_binerror = VBS_out_binerror if VBS_out_binerror<1 else 1
       VBS_out_binerror = VBS_out_binerror+1

       f.write('observation %.2f\n'%bin_content)
       f.write('------------\n')
       f.write('# now we list the expected events for signal and all backgrounds in that bin\n')
       f.write('# the second process line must have a positive number for backgrounds, and 0 for signal\n')
       f.write('# then we list the independent sources of uncertainties, and give their effect (syst. error)\n')
       f.write('# on each process and bin\n')
       f.write('bin\tmubarrel\tmubarrel\tmubarrel\tmubarrel\tmubarrel\tmubarrel\tmubarrel\tmubarrel\tmubarrel\tmubarrel\tmubarrel\tmubarrel\tmubarrel\tmubarrel\tmubarrel\tmubarrel\n')
       f.write('process\tVBS\tVBSout\tWGJets\tST_s\tST_t\tST_tbar\tST_tW\tST_tbarW\tTTG\tWW\tWZ\tZZ\tZG\tfakephoton\tfakelepton\tdoublefake\n')
       f.write('process\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\t13\t14\t15\n')
       f.write('rate\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\n'%(VBS_bincontent,VBS_out_bincontent, WGJets_bincontent, ST_s_bincontent, ST_t_bincontent, ST_tbar_bincontent, ST_tW_bincontent, ST_tbarW_bincontent, TTG_bincontent, WW_bincontent, WZ_bincontent, ZZ_bincontent, ZG_bincontent, fakephoton_bincontent, fakelepton_bincontent, doublefake_bincontent))
       f.write('------------\n')
       f.write('lumi\tlnN\t1.025\t1.025\t1.025\t1.025\t1.025\t1.025\t1.025\t1.025\t1.025\t1.025\t1.025\t1.025\t1.025\t-\t-\t-\t#lumi\n')
       f.write('stat\tlnN\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t-\t-\t-\n'%(VBS_binerror,VBS_out_binerror, WGJets_binerror, ST_s_binerror, ST_t_binerror, ST_tbar_binerror, ST_tW_binerror, ST_tbarW_binerror, TTG_binerror, WW_binerror, WZ_binerror, ZZ_binerror, ZG_binerror))
       f.write('photon_ID\tlnN\t-\t-\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t-\t-\t-\n'%(WGJets_photon_ID_[(i-1)*NbinsY + j - 1], ST_s_photon_ID_[(i-1)*NbinsY + j - 1], ST_t_photon_ID_[(i-1)*NbinsY + j - 1], ST_tbar_photon_ID_[(i-1)*NbinsY + j - 1], ST_tW_photon_ID_[(i-1)*NbinsY + j - 1], ST_tbarW_photon_ID_[(i-1)*NbinsY + j - 1], TTG_photon_ID_[(i-1)*NbinsY + j - 1], WW_photon_ID_[(i-1)*NbinsY + j - 1], WZ_photon_ID_[(i-1)*NbinsY + j - 1], ZZ_photon_ID_[(i-1)*NbinsY + j - 1] ,ZG_photon_ID_[(i-1)*NbinsY + j - 1]))
       f.write('electron_ID\tlnN\t-\t-\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t-\t-\t-\n'%(WGJets_electron_ID_[(i-1)*NbinsY + j - 1], ST_s_electron_ID_[(i-1)*NbinsY + j - 1], ST_t_electron_ID_[(i-1)*NbinsY + j - 1], ST_tbar_electron_ID_[(i-1)*NbinsY + j - 1], ST_tW_electron_ID_[(i-1)*NbinsY + j - 1], ST_tbarW_electron_ID_[(i-1)*NbinsY + j - 1], TTG_electron_ID_[(i-1)*NbinsY + j - 1], WW_electron_ID_[(i-1)*NbinsY + j - 1], WZ_electron_ID_[(i-1)*NbinsY + j - 1], ZZ_electron_ID_[(i-1)*NbinsY + j - 1], ZG_electron_ID_[(i-1)*NbinsY + j - 1]))
       f.write('electron_Reco\tlnN\t-\t-\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t-\t-\t-\n'%(WGJets_electron_Reco_[(i-1)*NbinsY + j - 1], ST_s_electron_Reco_[(i-1)*NbinsY + j - 1], ST_t_electron_Reco_[(i-1)*NbinsY + j - 1], ST_tbar_electron_Reco_[(i-1)*NbinsY + j - 1], ST_tW_electron_Reco_[(i-1)*NbinsY + j - 1], ST_tbarW_electron_Reco_[(i-1)*NbinsY + j - 1], TTG_electron_Reco_[(i-1)*NbinsY + j - 1], WW_electron_Reco_[(i-1)*NbinsY + j - 1], WZ_electron_Reco_[(i-1)*NbinsY + j - 1], ZZ_electron_Reco_[(i-1)*NbinsY + j - 1], ZG_electron_Reco_[(i-1)*NbinsY + j - 1]))       
       f.write('electron_HLT\tlnN\t-\t-\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t-\t-\t-\n'%(WGJets_electron_HLT_[(i-1)*NbinsY + j - 1], ST_s_electron_HLT_[(i-1)*NbinsY + j - 1], ST_t_electron_HLT_[(i-1)*NbinsY + j - 1], ST_tbar_electron_HLT_[(i-1)*NbinsY + j - 1], ST_tW_electron_HLT_[(i-1)*NbinsY + j - 1], ST_tbarW_electron_HLT_[(i-1)*NbinsY + j - 1], TTG_electron_HLT_[(i-1)*NbinsY + j - 1], WW_electron_HLT_[(i-1)*NbinsY + j - 1], WZ_electron_HLT_[(i-1)*NbinsY + j - 1], ZZ_electron_HLT_[(i-1)*NbinsY + j - 1], ZG_electron_HLT_[(i-1)*NbinsY + j - 1]))
       f.write('muon_ID\tlnN\t-\t-\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t-\t-\t-\n'%(WGJets_muon_ID_[(i-1)*NbinsY + j - 1], ST_s_muon_ID_[(i-1)*NbinsY + j - 1], ST_t_muon_ID_[(i-1)*NbinsY + j - 1], ST_tbar_muon_ID_[(i-1)*NbinsY + j - 1], ST_tW_muon_ID_[(i-1)*NbinsY + j - 1], ST_tbarW_muon_ID_[(i-1)*NbinsY + j - 1], TTG_muon_ID_[(i-1)*NbinsY + j - 1], WW_muon_ID_[(i-1)*NbinsY + j - 1], WZ_muon_ID_[(i-1)*NbinsY + j - 1], ZZ_muon_ID_[(i-1)*NbinsY + j - 1], ZG_muon_ID_[(i-1)*NbinsY + j - 1]))
       f.write('muon_iso\tlnN\t-\t-\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t-\t-\t-\n'%(WGJets_muon_iso_[(i-1)*NbinsY + j - 1], ST_s_muon_iso_[(i-1)*NbinsY + j - 1], ST_t_muon_iso_[(i-1)*NbinsY + j - 1], ST_tbar_muon_iso_[(i-1)*NbinsY + j - 1], ST_tW_muon_iso_[(i-1)*NbinsY + j - 1], ST_tbarW_muon_iso_[(i-1)*NbinsY + j - 1], TTG_muon_iso_[(i-1)*NbinsY + j - 1], WW_muon_iso_[(i-1)*NbinsY + j - 1], WZ_muon_iso_[(i-1)*NbinsY + j - 1], ZZ_muon_iso_[(i-1)*NbinsY + j - 1], ZG_muon_iso_[(i-1)*NbinsY + j - 1]))
       f.write('muon_HLT\tlnN\t-\t-\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t-\t-\t-\n'%(WGJets_muon_HLT_[(i-1)*NbinsY + j - 1], ST_s_muon_HLT_[(i-1)*NbinsY + j - 1], ST_t_muon_HLT_[(i-1)*NbinsY + j - 1], ST_tbar_muon_HLT_[(i-1)*NbinsY + j - 1], ST_tW_muon_HLT_[(i-1)*NbinsY + j - 1], ST_tbarW_muon_HLT_[(i-1)*NbinsY + j - 1], TTG_muon_HLT_[(i-1)*NbinsY + j - 1], WW_muon_HLT_[(i-1)*NbinsY + j - 1], WZ_muon_HLT_[(i-1)*NbinsY + j - 1], ZZ_muon_HLT_[(i-1)*NbinsY + j - 1], ZG_muon_HLT_[(i-1)*NbinsY + j - 1]))
       #f.write('JEC\tlnN\t-\t-\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t-\t-\t-\n'%(WGJets_JEC_[(i-1)*NbinsY + j - 1], ST_s_JEC_[(i-1)*NbinsY + j - 1], ST_t_JEC_[(i-1)*NbinsY + j - 1], ST_tbar_JEC_[(i-1)*NbinsY + j - 1], ST_tW_JEC_[(i-1)*NbinsY + j - 1], ST_tbarW_JEC_[(i-1)*NbinsY + j - 1], TTG_JEC_[(i-1)*NbinsY + j - 1], WW_JEC_[(i-1)*NbinsY + j - 1], WZ_JEC_[(i-1)*NbinsY + j - 1], ZZ_JEC_[(i-1)*NbinsY + j - 1], ZG_JEC_[(i-1)*NbinsY + j - 1]))
       #f.write('JER\tlnN\t-\t-\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t-\t-\t-\n'%(WGJets_JER_[(i-1)*NbinsY + j - 1], ST_s_JER_[(i-1)*NbinsY + j - 1], ST_t_JER_[(i-1)*NbinsY + j - 1], ST_tbar_JER_[(i-1)*NbinsY + j - 1], ST_tW_JER_[(i-1)*NbinsY + j - 1], ST_tbarW_JER_[(i-1)*NbinsY + j - 1], TTG_JER_[(i-1)*NbinsY + j - 1], WW_JER_[(i-1)*NbinsY + j - 1], WZ_JER_[(i-1)*NbinsY + j - 1], ZZ_JER_[(i-1)*NbinsY + j - 1], ZG_JER_[(i-1)*NbinsY + j - 1]))
       #if non_prompt_bincontent==0:
       #   f.write('fake_%s_%s\tlnN\t-\t-\t-\t-\t-\t-\t-\t-\t#0. uncertainty on 18_mubarrel\n'%('18','mubarrel'))
       #else: 
       #   f.write('fake_%s_%s\tlnN\t-\t-\t-\t%0.2f\t-\t-\t-\t-\t#0. uncertainty on 18_mubarrel\n'%('18','mubarrel',fakephoton[i-1]))
       #print 'bin ',i,' ',ZA_sig_binerror,' ',ZA_sig_binerror,' ',ZA_binerror,' ',non_prompt_binerror,' ',TTA_binerror,' ',VV_binerror,' ',ST_binerror,' ',WA_binerror
