#!/usr/bin/env python
import sys
import os
import re

import ROOT
from ROOT import gROOT, TH1D, TFile

year = sys.argv[1]
channel = sys.argv[2]
indir = sys.argv[3]
outdir = sys.argv[4]
if not os.path.exists(outdir):
    os.makedirs(outdir)

print '-----begin to transfer TH2D to txt for Higgs-combine tool----- \n'

#indir = "./test_scale_2/"
#outdir = "./datacards_2/"
#channel = "muon"
if channel == "muon" :
    sample = "SingleMuon"
else :
    sample = "SingleElectron"
f_in_ST_s     = TFile.Open(indir + "/scaled_" + year + "_aqgc_WG_mc_" + channel + "_ST_s_medium.root")
f_in_ST_t     = TFile.Open(indir + "/scaled_" + year + "_aqgc_WG_mc_" + channel + "_ST_t_medium.root")
f_in_ST_tbar  = TFile.Open(indir + "/scaled_" + year + "_aqgc_WG_mc_" + channel + "_ST_tbar_medium.root")
f_in_ST_tW    = TFile.Open(indir + "/scaled_" + year + "_aqgc_WG_mc_" + channel + "_ST_tW_medium.root")
f_in_ST_tbarW = TFile.Open(indir + "/scaled_" + year + "_aqgc_WG_mc_" + channel + "_ST_tbarW_medium.root")
f_in_TTG      = TFile.Open(indir + "/scaled_" + year + "_aqgc_WG_mc_" + channel + "_TTG_medium.root")
f_in_WGJJ     = TFile.Open(indir + "/scaled_" + year + "_aqgc_WG_mc_" + channel + "_WGJJ_medium.root")
f_in_WGJets   = TFile.Open(indir + "/scaled_" + year + "_aqgc_WG_mc_" + channel + "_WGJets_medium.root")
f_in_WW       = TFile.Open(indir + "/scaled_" + year + "_aqgc_WG_mc_" + channel + "_WW_medium.root")
f_in_WZ       = TFile.Open(indir + "/scaled_" + year + "_aqgc_WG_mc_" + channel + "_WZ_medium.root")
f_in_ZZ       = TFile.Open(indir + "/scaled_" + year + "_aqgc_WG_mc_" + channel + "_ZZ_medium.root")
f_in_ZG       = TFile.Open(indir + "/scaled_" + year + "_aqgc_WG_mc_" + channel + "_ZG_medium.root")

#f_in_data       = TFile.Open(indir + "2018_aqgc_WG_data_" + channel + "_" + sample + "_medium.root")
f_in_fakephoton = TFile.Open(indir + "/" + year + "_aqgc_WG_fakephoton_" + channel + "_" + sample + "_medium.root")
f_in_fakelepton = TFile.Open(indir + "/" + year + "_aqgc_WG_fakelepton_" + channel + "_" + sample + "_medium.root")
f_in_doublefake = TFile.Open(indir + "/" + year + "_aqgc_WG_doublefake_" + channel + "_" + sample + "_medium.root")

#th1_data       =ROOT.TH1D()
th1_fakephoton =ROOT.TH1D()
th1_fakelepton =ROOT.TH1D()
th1_doublefake =ROOT.TH1D()

th1_ST_s     =ROOT.TH1D()
th1_ST_t     =ROOT.TH1D()
th1_ST_tbar  =ROOT.TH1D()
th1_ST_tW    =ROOT.TH1D()
th1_ST_tbarW =ROOT.TH1D()
th1_TTG      =ROOT.TH1D()
th1_WGJJ     =ROOT.TH1D()
th1_WGJets   =ROOT.TH1D()
th1_WW       =ROOT.TH1D()
th1_WZ       =ROOT.TH1D()
th1_ZZ       =ROOT.TH1D()
th1_ZG       =ROOT.TH1D()

f_in_ST_s.GetObject("nominal",th1_ST_s)
f_in_ST_t.GetObject("nominal",th1_ST_t)
f_in_ST_tbar.GetObject("nominal",th1_ST_tbar)
f_in_ST_tW.GetObject("nominal",th1_ST_tW)
f_in_ST_tbarW.GetObject("nominal",th1_ST_tbarW)
f_in_TTG.GetObject("nominal",th1_TTG)
f_in_WGJJ.GetObject("nominal",th1_WGJJ)
f_in_WGJets.GetObject("nominal",th1_WGJets)
f_in_WW.GetObject("nominal",th1_WW)
f_in_WZ.GetObject("nominal",th1_WZ)
f_in_ZZ.GetObject("nominal",th1_ZZ)
f_in_ZG.GetObject("nominal",th1_ZG)

#f_in_data.GetObject("nominal",th1_data)
f_in_fakephoton.GetObject("nominal",th1_fakephoton)
f_in_fakelepton.GetObject("nominal",th1_fakelepton)
f_in_doublefake.GetObject("nominal",th1_doublefake)

print '>>>>begin to read bin content to the txt file>>>>'
#ST_s_WGmass_jer=[]
ST_s_WGmass_jec = [ 1.00149, 1.00144, 1, 1.00002, 1]
ST_s_WGmass_jer = [ 1.00013, 16.4907, 1, 1, 1]
ST_s_WGmass_photon_ID = [ 1.0282, 1.00765, 1, 1.05421, 1]
ST_s_WGmass_electron_ID = [ 2, 1, 1, 1, 1]
ST_s_WGmass_electron_Reco = [ 1.00337, 1, 1, 1, 1]
ST_s_WGmass_electron_HLT = [ 1.01035, 1, 1, 1, 1]
ST_s_WGmass_electron = [ 2.02752, 1, 1, 1, 1]
ST_s_WGmass_muon_ID = [ 1, 1.00969, 1, 1.00086, 1]
ST_s_WGmass_muon_iso = [ 1, 1.00565, 1, 1.0008, 1]
ST_s_WGmass_muon_HLT = [ 1, 1.11853, 1, 1.00096, 1]
ST_s_WGmass_muon = [ 1, 1.1341, 1, 1.00263, 1]
ST_s_WGmass_fakephoton = [ 2695.89, 104738, 1, 2897.68, 1]
ST_tW_WGmass_jec = [ 1.24765, 1.00002, 1.00047, 2, 1]
ST_tW_WGmass_jer = [ 1.00022, 1, 1.00001, 2, 1]
ST_tW_WGmass_photon_ID = [ 1.04153, 1.05166, 1.0282, 1.05421, 1]
ST_tW_WGmass_electron_ID = [ 1.00971, 1.00882, 1, 1, 1]
ST_tW_WGmass_electron_Reco = [ 1.00344, 1.00237, 1, 1, 1]
ST_tW_WGmass_electron_HLT = [ 1.00159, 1.00151, 1, 1, 1]
ST_tW_WGmass_electron = [ 1.01481, 1.01276, 1, 1, 1]
ST_tW_WGmass_muon_ID = [ 1.00022, 1.00037, 1.00077, 1.00642, 1]
ST_tW_WGmass_muon_iso = [ 1.00014, 1.00025, 1.00052, 1.00116, 1]
ST_tW_WGmass_muon_HLT = [ 1.00145, 1.00026, 1.0052, 1.00086, 1]
ST_tW_WGmass_muon = [ 1.00181, 1.00087, 1.0065, 1.00845, 1]
ST_tW_WGmass_fakephoton = [ 307.262, 265.243, 244.019, 267.74, 1]
ST_t_WGmass_jec = [ 1.04232, 1.09896, 1.34276, 1, 1.00002]
ST_t_WGmass_jer = [ 1.27535, 1.29165, 1.34317, 1, 2]
ST_t_WGmass_photon_ID = [ 1.02826, 1.03535, 1.03723, 1, 1.07298]
ST_t_WGmass_electron_ID = [ 1.00714, 1.00593, 1.0108, 1, 1]
ST_t_WGmass_electron_Reco = [ 1.00187, 1.00183, 1.00164, 1, 1]
ST_t_WGmass_electron_HLT = [ 1.00227, 1.00125, 1.0031, 1, 1]
ST_t_WGmass_electron = [ 1.01139, 1.00906, 1.01569, 1, 1]
ST_t_WGmass_muon_ID = [ 1.00066, 1.00092, 1.00052, 1, 1.00086]
ST_t_WGmass_muon_iso = [ 1.00031, 1.00031, 1.00043, 1, 1.0008]
ST_t_WGmass_muon_HLT = [ 1.0007, 1.00164, 1.00049, 1, 1.00361]
ST_t_WGmass_muon = [ 1.00167, 1.00288, 1.00144, 1, 1.00529]
ST_t_WGmass_fakephoton = [ 1465.91, 1185.93, 1295.41, 1, 1056.46]
ST_tbarW_WGmass_jec = [ 1.00906, 1.00005, 1, 1, 1]
ST_tbarW_WGmass_jer = [ 1.00884, 1.00004, 1, 1, 1]
ST_tbarW_WGmass_photon_ID = [ 1.02714, 1.04348, 1, 1, 1]
ST_tbarW_WGmass_electron_ID = [ 1.00366, 1, 1, 1, 1]
ST_tbarW_WGmass_electron_Reco = [ 1.00115, 1, 1, 1, 1]
ST_tbarW_WGmass_electron_HLT = [ 1.00059, 1, 1, 1, 1]
ST_tbarW_WGmass_electron = [ 1.00543, 1, 1, 1, 1]
ST_tbarW_WGmass_muon_ID = [ 1.00178, 1.0039, 1, 1, 1]
ST_tbarW_WGmass_muon_iso = [ 1.00051, 1.00071, 1, 1, 1]
ST_tbarW_WGmass_muon_HLT = [ 1.00239, 1.00258, 1, 1, 1]
ST_tbarW_WGmass_muon = [ 1.00469, 1.0072, 1, 1, 1]
ST_tbarW_WGmass_fakephoton = [ 212.151, 208.834, 1, 1, 1]
ST_tbar_WGmass_jec = [ 1.23253, 2.00262, 1, 1, 1.00009]
ST_tbar_WGmass_jer = [ 1.02725, 2.00344, 1, 1, 1.00003]
ST_tbar_WGmass_photon_ID = [ 1.02578, 1.0135, 1, 1, 1.07512]
ST_tbar_WGmass_electron_ID = [ 1.00376, 1, 1, 1, 1.01636]
ST_tbar_WGmass_electron_Reco = [ 1.00059, 1, 1, 1, 1.00452]
ST_tbar_WGmass_electron_HLT = [ 1.00072, 1, 1, 1, 1.00305]
ST_tbar_WGmass_electron = [ 1.00508, 1, 1, 1, 1.02407]
ST_tbar_WGmass_muon_ID = [ 1.0003, 1.00054, 1, 1, 1]
ST_tbar_WGmass_muon_iso = [ 1.00027, 1.00042, 1, 1, 1]
ST_tbar_WGmass_muon_HLT = [ 1.00023, 1.0002, 1, 1, 1]
ST_tbar_WGmass_muon = [ 1.0008, 1.00115, 1, 1, 1]
ST_tbar_WGmass_fakephoton = [ 1122.34, 1075.97, 1, 1, 1157.62]
TTG_WGmass_jec = [ 1.14844, 1.0777, 1.27518, 1.4295, 1.00379]
TTG_WGmass_jer = [ 1.10693, 1.21914, 1.1438, 1.27007, 1.34348]
TTG_WGmass_photon_ID = [ 1.0329, 1.03242, 1.05125, 1.04843, 1.04932]
TTG_WGmass_electron_ID = [ 1.00426, 1.04582, 1.01152, 1.12338, 1.00913]
TTG_WGmass_electron_Reco = [ 1.00107, 1.00159, 1.00302, 1.00328, 1.00358]
TTG_WGmass_electron_HLT = [ 1.00115, 1.00379, 1.00332, 1.0042, 1.00208]
TTG_WGmass_electron = [ 1.00664, 1.05494, 1.01808, 1.13211, 1.01487]
TTG_WGmass_muon_ID = [ 1.00078, 1.00102, 1.00162, 1.0018, 1.00099]
TTG_WGmass_muon_iso = [ 1.00032, 1.00037, 1.00047, 1.00045, 1.00042]
TTG_WGmass_muon_HLT = [ 1.00048, 1.00129, 1.00179, 1.0006, 1.00881]
TTG_WGmass_muon = [ 1.00158, 1.00268, 1.00388, 1.00285, 1.01025]
TTG_WGmass_fakephoton = [ 1178.82, 1518.68, 1344.97, 982.521, 1067.31]
WGJJ_WGmass_jec = [ 1.04385, 1.06458, 1.07079, 1.00867, 1.09491]
WGJJ_WGmass_jer = [ 1.03715, 1.04237, 1.05807, 1.02171, 1.12871]
WGJJ_WGmass_photon_ID = [ 1.03445, 1.0391, 1.04354, 1.0467, 1.05637]
WGJJ_WGmass_electron_ID = [ 1.00943, 1.01211, 1.02152, 1.03564, 1.01158]
WGJJ_WGmass_electron_Reco = [ 1.0014, 1.00197, 1.00273, 1.00289, 1.00324]
WGJJ_WGmass_electron_HLT = [ 1.0015, 1.00236, 1.00275, 1.00523, 1.00406]
WGJJ_WGmass_electron = [ 1.01251, 1.01675, 1.02769, 1.04645, 1.01915]
WGJJ_WGmass_muon_ID = [ 1.00102, 1.00113, 1.0012, 1.00122, 1.00107]
WGJJ_WGmass_muon_iso = [ 1.00036, 1.00039, 1.00043, 1.00044, 1.00046]
WGJJ_WGmass_muon_HLT = [ 1.00081, 1.0016, 1.00228, 1.00266, 1.00495]
WGJJ_WGmass_muon = [ 1.00219, 1.00313, 1.00392, 1.00433, 1.0065]
WGJJ_WGmass_fakephoton = [ 1272.77, 1233.83, 1232.96, 1212.97, 1228.26]
WGJJ_scale = [1.06552, 1.05239, 1.04204, 1.04877, 1.02085]
WGJJ_pdf = [1.01235, 1.00399, 1.00276, 1.01167, 1.0046]
WGJets_WGmass_jec = [ 1.11414, 1.09676, 1.52372, 1.34335, 1.96788]
WGJets_WGmass_jer = [ 1.12756, 1.20038, 2.21084, 1.04298, 1.96778]
WGJets_WGmass_photon_ID = [ 1.03087, 1.03806, 1.0376, 1.06337, 1.07298]
WGJets_WGmass_electron_ID = [ 1.02574, 1.0125, 1.00528, 1.01314, 1]
WGJets_WGmass_electron_Reco = [ 1.00194, 1.00244, 1.00132, 1.00365, 1]
WGJets_WGmass_electron_HLT = [ 1.00157, 1.00551, 1.00694, 1.00953, 1]
WGJets_WGmass_electron = [ 1.02989, 1.02091, 1.01412, 1.0269, 1]
WGJets_WGmass_muon_ID = [ 1.00123, 1.00107, 1.00107, 1.00049, 1.00077]
WGJets_WGmass_muon_iso = [ 1.00039, 1.00051, 1.00051, 1.00043, 1.00052]
WGJets_WGmass_muon_HLT = [ 1.00082, 1.00483, 1.00179, 1.00048, 1.01111]
WGJets_WGmass_muon = [ 1.00245, 1.00643, 1.00339, 1.00139, 1.01241]
WGJets_WGmass_fakephoton = [ 34.6338, 38.5278, 74.2365, 45.2665, 25.5222]
WGJets_scale = [1.00038, 1.0019, 1.00033, 1.00352, 1.00244]
WGJets_pdf = [1.01811, 1.02071, 1.01919, 1.02621, 1.01566]
WW_WGmass_jec = [ 1.00004, 1.32231, 1.00002, 1, 1]
WW_WGmass_jer = [ 1.26189, 1.67765, 1.87505, 1, 1]
WW_WGmass_photon_ID = [ 1.03679, 1.037, 1.05658, 1, 1]
WW_WGmass_electron_ID = [ 1.00779, 1.00543, 1.00699, 1, 1]
WW_WGmass_electron_Reco = [ 1.00334, 1.00146, 1.00682, 1, 1]
WW_WGmass_electron_HLT = [ 1.00238, 1.00093, 1.00243, 1, 1]
WW_WGmass_electron = [ 1.01363, 1.00786, 1.01633, 1, 1]
WW_WGmass_muon_ID = [ 1.00082, 1.00394, 1, 1, 1]
WW_WGmass_muon_iso = [ 1.00018, 1.00065, 1, 1, 1]
WW_WGmass_muon_HLT = [ 1.00024, 1.00051, 1, 1, 1]
WW_WGmass_muon = [ 1.00125, 1.0051, 1, 1, 1]
WW_WGmass_fakephoton = [ 106.669, 100.208, 91.7806, 1, 1]
WZ_WGmass_jec = [ 1.00002, 1, 1, 1, 1]
WZ_WGmass_jer = [ 1, 1, 1, 1, 1]
WZ_WGmass_photon_ID = [ 1.02993, 1, 1, 1, 1]
WZ_WGmass_electron_ID = [ 1, 1, 1, 1, 1]
WZ_WGmass_electron_Reco = [ 1, 1, 1, 1, 1]
WZ_WGmass_electron_HLT = [ 1, 1, 1, 1, 1]
WZ_WGmass_electron = [ 1, 1, 1, 1, 1]
WZ_WGmass_muon_ID = [ 1.00077, 1, 1, 1, 1]
WZ_WGmass_muon_iso = [ 1.00052, 1, 1, 1, 1]
WZ_WGmass_muon_HLT = [ 1.0052, 1, 1, 1, 1]
WZ_WGmass_muon = [ 1.0065, 1, 1, 1, 1]
WZ_WGmass_fakephoton = [ 147.928, 1, 1, 1, 1]
ZG_WGmass_jec = [ 1.1203, 2.63543, 2.57791, 1, 1]
ZG_WGmass_jer = [ 1.38131, 2.74925, 3.60597, 1, 1]
ZG_WGmass_photon_ID = [ 1.03151, 1.03389, 1.02265, 1, 1]
ZG_WGmass_electron_ID = [ 1.0069, 1.002, 1.00803, 1, 1]
ZG_WGmass_electron_Reco = [ 1.00229, 1.00344, 1.01542, 1, 1]
ZG_WGmass_electron_HLT = [ 1.00188, 1.00357, 1.01801, 1, 1]
ZG_WGmass_electron = [ 1.01114, 1.0021, 1.01178, 1, 1]
ZG_WGmass_muon_ID = [ 1.00091, 1.00125, 1, 1, 1]
ZG_WGmass_muon_iso = [ 1.00033, 1.0003, 1, 1, 1]
ZG_WGmass_muon_HLT = [ 1.0004, 1.00124, 1, 1, 1]
ZG_WGmass_muon = [ 1.00164, 1.0028, 1, 1, 1]
ZG_WGmass_fakephoton = [ 295.904, 638.473, 727.599, 1, 1]
ZZ_WGmass_jec = [ 1, 1, 1, 1, 1]
ZZ_WGmass_jer = [ 1, 1, 1, 1, 1]
ZZ_WGmass_photon_ID = [ 1, 1, 1, 1, 1]
ZZ_WGmass_electron_ID = [ 1, 1, 1, 1, 1]
ZZ_WGmass_electron_Reco = [ 1, 1, 1, 1, 1]
ZZ_WGmass_electron_HLT = [ 1, 1, 1, 1, 1]
ZZ_WGmass_electron = [ 1, 1, 1, 1, 1]
ZZ_WGmass_muon_ID = [ 1, 1, 1, 1, 1]
ZZ_WGmass_muon_iso = [ 1, 1, 1, 1, 1]
ZZ_WGmass_muon_HLT = [ 1, 1, 1, 1, 1]
ZZ_WGmass_muon = [ 1, 1, 1, 1, 1]
ZZ_WGmass_fakephoton = [ 1, 1, 1, 1, 1]
WGmass_fakephoton = [ 1.22403, 1.23541, 1.20907, 1.17986, 1.15152]
h=0
#jes=[1.024, 1.012, 1.025, 1.024, 1.022]
#jer=[1.004, 1.012, 1.032, 1.076, 1.019]
#jet=[1.029, 1.064, 1.062, 1.000, 1.000]
#pdf=[1.037, 1.039,1.038,1.039,1.047]
#scale=[1.10,1.08,1.06,1.03,1.01]
#l1_signal=[1.021,1.020,1.021,1.022,1.023]
#l1_others=[1.006,1.004,1.013,1.012,1.027]
for i in range(1,6):
   f = open(outdir + '/%s_bin_%d.txt'%(channel, i),'w')
   f.write('imax 1   number of channels\n')
   f.write('jmax 14   number of processes-1\n')
   f.write('kmax 14  number of nuisance parameters (sources of systematical uncertainties)\n')
   f.write('------------\n')
   f.write('# we have just one channel, in which we observe 0 events\n')
   f.write('bin ch%d\n'%(i))
# bincontent of each precess
   ST_s_bincontent = th1_ST_s.GetBinContent(i) if th1_ST_s.GetBinContent(i)>0 else 0
   ST_t_bincontent = th1_ST_t.GetBinContent(i) if th1_ST_t.GetBinContent(i)>0 else 0
   ST_tbar_bincontent = th1_ST_tbar.GetBinContent(i) if th1_ST_tbar.GetBinContent(i)>0 else 0
   ST_tW_bincontent = th1_ST_tW.GetBinContent(i) if th1_ST_tW.GetBinContent(i)>0 else 0
   ST_tbarW_bincontent = th1_ST_tbarW.GetBinContent(i) if th1_ST_tbarW.GetBinContent(i)>0 else 0
   TTG_bincontent = th1_TTG.GetBinContent(i) if th1_TTG.GetBinContent(i)>0 else 0
   WGJJ_bincontent = th1_WGJJ.GetBinContent(i) if th1_WGJJ.GetBinContent(i)>0 else 0
   WGJets_bincontent = th1_WGJets.GetBinContent(i) if th1_WGJets.GetBinContent(i)>0 else 0
   WW_bincontent = th1_WW.GetBinContent(i) if th1_WW.GetBinContent(i)>0 else 0   
   WZ_bincontent = th1_WZ.GetBinContent(i) if th1_WZ.GetBinContent(i)>0 else 0   
   ZZ_bincontent = th1_ZZ.GetBinContent(i) if th1_ZZ.GetBinContent(i)>0 else 0
   ZG_bincontent = th1_ZG.GetBinContent(i) if th1_ZG.GetBinContent(i)>0 else 0

#   data_bincontent = th1_data.GetBinContent(i) if th1_data.GetBinContent(i)>0 else 0
   doublefake_bincontent = th1_doublefake.GetBinContent(i) if th1_doublefake.GetBinContent(i)>0 else 0
   fakephoton_bincontent = th1_fakephoton.GetBinContent(i) - doublefake_bincontent if (th1_fakephoton.GetBinContent(i)-doublefake_bincontent)>0 else 0
   fakelepton_bincontent = th1_fakelepton.GetBinContent(i) - doublefake_bincontent if (th1_fakelepton.GetBinContent(i)-doublefake_bincontent)>0 else 0
   #doublefake_bincontent = th1_doublefake.GetBinContent(i) if th1_doublefake.GetBinContent(i)>0 else 0

# bin error
   ST_s_binerror = th1_ST_s.GetBinError(i)/ST_s_bincontent if ST_s_bincontent>0 else 0
   ST_s_binerror = ST_s_binerror if ST_s_binerror<1 else 1
   ST_s_binerror = ST_s_binerror+1

   ST_t_binerror = th1_ST_t.GetBinError(i)/ST_t_bincontent if ST_t_bincontent>0 else 0
   ST_t_binerror = ST_t_binerror if ST_t_binerror<1 else 1
   ST_t_binerror = ST_t_binerror+1

   ST_tbar_binerror = th1_ST_tbar.GetBinError(i)/ST_tbar_bincontent if ST_tbar_bincontent>0 else 0
   ST_tbar_binerror = ST_tbar_binerror if ST_tbar_binerror<1 else 1
   ST_tbar_binerror = ST_tbar_binerror+1

   ST_tW_binerror = th1_ST_tW.GetBinError(i)/ST_tW_bincontent if ST_tW_bincontent>0 else 0
   ST_tW_binerror = ST_tW_binerror if ST_tW_binerror<1 else 1
   ST_tW_binerror = ST_tW_binerror+1

   ST_tbarW_binerror = th1_ST_tbarW.GetBinError(i)/ST_tbarW_bincontent if ST_tbarW_bincontent>0 else 0
   ST_tbarW_binerror = ST_tbarW_binerror if ST_tbarW_binerror<1 else 1
   ST_tbarW_binerror = ST_tbarW_binerror+1

   TTG_binerror = th1_TTG.GetBinError(i)/TTG_bincontent if TTG_bincontent>0 else 0
   TTG_binerror = TTG_binerror if TTG_binerror<1 else 1
   TTG_binerror = TTG_binerror+1

   WGJJ_binerror = th1_WGJJ.GetBinError(i)/WGJJ_bincontent if WGJJ_bincontent>0 else 0
   WGJJ_binerror = WGJJ_binerror if WGJJ_binerror<1 else 1
   WGJJ_binerror = WGJJ_binerror+1

   WGJets_binerror = th1_WGJets.GetBinError(i)/WGJets_bincontent if WGJets_bincontent>0 else 0
   WGJets_binerror = WGJets_binerror if WGJets_binerror<1 else 1
   WGJets_binerror = WGJets_binerror+1

   WW_binerror = th1_WW.GetBinError(i)/WW_bincontent if WW_bincontent>0 else 0
   WW_binerror = WW_binerror if WW_binerror<1 else 1
   WW_binerror = WW_binerror+1

   WZ_binerror = th1_WZ.GetBinError(i)/WZ_bincontent if WZ_bincontent>0 else 0
   WZ_binerror = WZ_binerror if WZ_binerror<1 else 1
   WZ_binerror = WZ_binerror+1

   ZZ_binerror = th1_ZZ.GetBinError(i)/ZZ_bincontent if ZZ_bincontent>0 else 0
   ZZ_binerror = ZZ_binerror if ZZ_binerror<1 else 1
   ZZ_binerror = ZZ_binerror+1

   ZG_binerror = th1_ZG.GetBinError(i)/ZG_bincontent if ZG_bincontent>0 else 0
   ZG_binerror = ZG_binerror if ZG_binerror<1 else 1
   ZG_binerror = ZG_binerror+1

   f.write('observation %.2f\n'%0)
   f.write('------------\n')
   f.write('# now we list the expected events for signal and all backgrounds in that bin\n')
   f.write('# the second process line must have a positive number for backgrounds, and 0 for signal\n')
   f.write('# then we list the independent sources of uncertainties, and give their effect (syst. error)\n')
   f.write('# on each process and bin\n')
   f.write('bin\tch%d\tch%d\tch%d\tch%d\tch%d\tch%d\tch%d\tch%d\tch%d\tch%d\tch%d\tch%d\tch%d\tch%d\tch%d\n'%(i+h,i+h,i+h,i+h,i+h,i+h,i+h,i+h,i+h,i+h,i+h,i+h,i+h,i+h,i+h))
   f.write('process\tWGJJ\tWGJets\tST_s\tST_t\tST_tbar\tST_tW\tST_tbarW\tTTG\tWW\tWZ\tZZ\tZG\tfakephoton\tfakelepton\tdoublefake\n')
   f.write('process\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\t13\t14\n')
   f.write('rate\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\n'%(WGJJ_bincontent, WGJets_bincontent, ST_s_bincontent, ST_t_bincontent, ST_tbar_bincontent, ST_tW_bincontent, ST_tbarW_bincontent, TTG_bincontent, WW_bincontent, WZ_bincontent, ZZ_bincontent, ZG_bincontent, fakephoton_bincontent, fakelepton_bincontent, doublefake_bincontent))
   f.write('------------\n')
   f.write('stat\tlnN\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t-\t-\t-\n'%(WGJJ_binerror, WGJets_binerror, ST_s_binerror, ST_t_binerror, ST_tbar_binerror, ST_tW_binerror, ST_tbarW_binerror, TTG_binerror, WW_binerror, WZ_binerror, ZZ_binerror, ZG_binerror))
   f.write('lumi\tlnN\t1.025\t1.025\t1.025\t1.025\t1.025\t1.025\t1.025\t1.025\t1.025\t1.025\t1.025\t1.025\t-\t-\t-\t#lumi\n')
#   f.write('QCD_%s\tlnN\t-\t1.05\t-\t-\t#0.1 uncertainty on QCD WA cross section in muon\n'%('muon'))#combine barrel and endcap, WA scale 0.97+-0.05
#   f.write('VBS_stat_%s\tlnN\t%0.2f\t-\t-\t-\n'%(channel,sig_binerror))
#   f.write('QCD_stat_%s\tlnN\t-\t%0.2f\t-\t-\n'%(channel,WA_binerror))
#   f.write('non_prompt_stat_%s\tlnN\t-\t-\t%0.2f\t-\n'%(channel,non_prompt_binerror))
#   f.write('others_stat_%s\tlnN\t-\t-\t-\t%0.2f\n'%(channel,others_binerror))
#   f.write('mu_trigger\tlnN\t1.02\t1.02\t-\t1.02\n')
#   f.write('mu_efficiency\tlnN\t1.005\t1.005\t-\t1.005\n')
#   f.write('pileup\tlnN\t1.001\t1.001\t-\t1.001\n')
#   f.write('photon_id\tlnN\t1.03\t1.03\t-\t1.03\n')
#   f.write('others_xs\tlnN\t-\t-\t-\t1.1\n')
#   f.write('interference\tlnN\t1.04\t-\t-\t-\n')   
#   f.write('JES_%s\tlnN\t%0.2f\t%0.2f\t-\t%0.2f\n'%(channel,jes[i-1],jes[i-1],jes[i-1]))i
   f.write('jec\tlnN\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t-\t-\t-\n'%(WGJJ_WGmass_jec[i-1], WGJets_WGmass_jec[i-1], ST_s_WGmass_jec[i-1], ST_t_WGmass_jec[i-1], ST_tbar_WGmass_jec[i-1], ST_tW_WGmass_jec[i-1], ST_tbarW_WGmass_jec[i-1], TTG_WGmass_jec[i-1], WW_WGmass_jec[i-1], WZ_WGmass_jec[i-1], ZZ_WGmass_jec[i-1], ZG_WGmass_jec[i-1]))
   f.write('jer\tlnN\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t-\t-\t-\n'%(WGJJ_WGmass_jer[i-1], WGJets_WGmass_jer[i-1], ST_s_WGmass_jer[i-1], ST_t_WGmass_jer[i-1], ST_tbar_WGmass_jer[i-1], ST_tW_WGmass_jer[i-1], ST_tbarW_WGmass_jer[i-1], TTG_WGmass_jer[i-1], WW_WGmass_jer[i-1], WZ_WGmass_jer[i-1], ZZ_WGmass_jer[i-1], ZG_WGmass_jer[i-1]))
   f.write('photon_ID\tlnN\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t-\t-\t-\n'%(WGJJ_WGmass_photon_ID[i-1], WGJets_WGmass_photon_ID[i-1], ST_s_WGmass_photon_ID[i-1], ST_t_WGmass_photon_ID[i-1], ST_tbar_WGmass_photon_ID[i-1], ST_tW_WGmass_photon_ID[i-1], ST_tbarW_WGmass_photon_ID[i-1], TTG_WGmass_photon_ID[i-1], WW_WGmass_photon_ID[i-1], WZ_WGmass_photon_ID[i-1], ZZ_WGmass_photon_ID[i-1], ZG_WGmass_photon_ID[i-1]))
   f.write('electron_ID\tlnN\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t-\t-\t-\n'%(WGJJ_WGmass_electron_ID[i-1], WGJets_WGmass_electron_ID[i-1], ST_s_WGmass_electron_ID[i-1], ST_t_WGmass_electron_ID[i-1], ST_tbar_WGmass_electron_ID[i-1], ST_tW_WGmass_electron_ID[i-1], ST_tbarW_WGmass_electron_ID[i-1], TTG_WGmass_electron_ID[i-1], WW_WGmass_electron_ID[i-1], WZ_WGmass_electron_ID[i-1], ZZ_WGmass_electron_ID[i-1], ZG_WGmass_electron_ID[i-1]))
   f.write('electron_Reco\tlnN\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t-\t-\t-\n'%(WGJJ_WGmass_electron_Reco[i-1], WGJets_WGmass_electron_Reco[i-1], ST_s_WGmass_electron_Reco[i-1], ST_t_WGmass_electron_Reco[i-1], ST_tbar_WGmass_electron_Reco[i-1], ST_tW_WGmass_electron_Reco[i-1], ST_tbarW_WGmass_electron_Reco[i-1], TTG_WGmass_electron_Reco[i-1], WW_WGmass_electron_Reco[i-1], WZ_WGmass_electron_Reco[i-1], ZZ_WGmass_electron_Reco[i-1], ZG_WGmass_electron_Reco[i-1]))
   f.write('electron_HLT\tlnN\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t-\t-\t-\n'%(WGJJ_WGmass_electron_HLT[i-1], WGJets_WGmass_electron_HLT[i-1], ST_s_WGmass_electron_HLT[i-1], ST_t_WGmass_electron_HLT[i-1], ST_tbar_WGmass_electron_HLT[i-1], ST_tW_WGmass_electron_HLT[i-1], ST_tbarW_WGmass_electron_HLT[i-1], TTG_WGmass_electron_HLT[i-1], WW_WGmass_electron_HLT[i-1], WZ_WGmass_electron_HLT[i-1], ZZ_WGmass_electron_HLT[i-1], ZG_WGmass_electron_HLT[i-1]))
   f.write('muon_ID\tlnN\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t-\t-\t-\n'%(WGJJ_WGmass_muon_ID[i-1], WGJets_WGmass_muon_ID[i-1], ST_s_WGmass_muon_ID[i-1], ST_t_WGmass_muon_ID[i-1], ST_tbar_WGmass_muon_ID[i-1], ST_tW_WGmass_muon_ID[i-1], ST_tbarW_WGmass_muon_ID[i-1], TTG_WGmass_muon_ID[i-1], WW_WGmass_muon_ID[i-1], WZ_WGmass_muon_ID[i-1], ZZ_WGmass_muon_ID[i-1], ZG_WGmass_muon_ID[i-1]))
   f.write('muon_iso\tlnN\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t-\t-\t-\n'%(WGJJ_WGmass_muon_iso[i-1], WGJets_WGmass_muon_iso[i-1], ST_s_WGmass_muon_iso[i-1], ST_t_WGmass_muon_iso[i-1], ST_tbar_WGmass_muon_iso[i-1], ST_tW_WGmass_muon_iso[i-1], ST_tbarW_WGmass_muon_iso[i-1], TTG_WGmass_muon_iso[i-1], WW_WGmass_muon_iso[i-1], WZ_WGmass_muon_iso[i-1], ZZ_WGmass_muon_iso[i-1], ZG_WGmass_muon_iso[i-1]))
   f.write('muon_HLT\tlnN\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t-\t-\t-\n'%(WGJJ_WGmass_muon_HLT[i-1], WGJets_WGmass_muon_HLT[i-1], ST_s_WGmass_muon_HLT[i-1], ST_t_WGmass_muon_HLT[i-1], ST_tbar_WGmass_muon_HLT[i-1], ST_tW_WGmass_muon_HLT[i-1], ST_tbarW_WGmass_muon_HLT[i-1], TTG_WGmass_muon_HLT[i-1], WW_WGmass_muon_HLT[i-1], WZ_WGmass_muon_HLT[i-1], ZZ_WGmass_muon_HLT[i-1], ZG_WGmass_muon_HLT[i-1]))
   f.write('scale\tlnN\t%0.2f\t%0.2f\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n'%(WGJJ_scale[i-1], WGJets_scale[i-1]))
   f.write('pdf\tlnN\t%0.2f\t%0.2f\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n'%(WGJJ_pdf[i-1], WGJets_pdf[i-1]))
   f.write('fakephoton\tlnN\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t-\t%0.2f\t-\t-\n'%(WGmass_fakephoton[i-1]))
#   f.write('JER_%s\tlnN\t%0.2f\t%0.2f\t-\t%0.2f\n'%(channel,jer[i-1],jer[i-1],jer[i-1]))
#   f.write('fakephoton_%s\tlnN\t-\t-\t%0.2f\t-\n'%(channel,jet[i-1]))
#   f.write('pdf_%s\tlnN\t%0.2f\t%0.2f\t-\t-\n'%(channel,pdf[i-1],pdf[i-1]))
#   f.write('scale_%s\tlnN\t%0.2f\t%0.2f\t-\t-\n'%(channel,scale[i-1],scale[i-1]))
#   f.write('l1_signal_%s\tlnN\t%0.2f\t-\t-\t-\n'%('muon',scale[i-1]))
#   f.write('l1_others_%s\tlnN\t-\t%0.2f\t-\t%0.2f\n'%('muon',scale[i-1],scale[i-1]))
