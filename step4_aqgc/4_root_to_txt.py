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
if channel == "muon" :
    h=0
    ST_s_WGmass_jec = [ 1, 1.00144, 1, 1.00002, 1]
    ST_s_WGmass_jer = [ 1, 16.4907, 1, 1, 1]
    ST_s_WGmass_photon_ID = [ 1, 1.00765, 1, 1.05421, 1]
    ST_s_WGmass_electron_ID = [ 1, 1, 1, 1, 1]
    ST_s_WGmass_electron_Reco = [ 1, 1, 1, 1, 1]
    ST_s_WGmass_electron_HLT = [ 1, 1, 1, 1, 1]
    ST_s_WGmass_electron = [ 1, 1, 1, 1, 1]
    ST_s_WGmass_muon_ID = [ 1, 1.00969, 1, 1.00086, 1]
    ST_s_WGmass_muon_iso = [ 1, 1.00565, 1, 1.0008, 1]
    ST_s_WGmass_muon_HLT = [ 1, 1.11853, 1, 1.00096, 1]
    ST_s_WGmass_muon = [ 1, 1.1341, 1, 1.00263, 1]
    ST_s_WGmass_fakephoton = [ 1, 104738, 1, 2897.68, 1]
    ST_tW_WGmass_jec = [ 1.00157, 1.00001, 1.00047, 2, 1]
    ST_tW_WGmass_jer = [ 1.00055, 1, 1.00001, 2, 1]
    ST_tW_WGmass_photon_ID = [ 1.07298, 1.02827, 1.0282, 1.05421, 1]
    ST_tW_WGmass_electron_ID = [ 1, 1, 1, 1, 1]
    ST_tW_WGmass_electron_Reco = [ 1, 1, 1, 1, 1]
    ST_tW_WGmass_electron_HLT = [ 1, 1, 1, 1, 1]
    ST_tW_WGmass_electron = [ 1, 1, 1, 1, 1]
    ST_tW_WGmass_muon_ID = [ 1.00077, 1.00077, 1.00077, 1.00642, 1]
    ST_tW_WGmass_muon_iso = [ 1.00052, 1.00052, 1.00052, 1.00116, 1]
    ST_tW_WGmass_muon_HLT = [ 1.0052, 1.00054, 1.0052, 1.00086, 1]
    ST_tW_WGmass_muon = [ 1.0065, 1.00183, 1.0065, 1.00845, 1]
    ST_tW_WGmass_fakephoton = [ 220.314, 278.08, 244.019, 267.74, 1]
    ST_t_WGmass_jec = [ 1.0913, 1.20377, 1.53838, 1, 1.00002]
    ST_t_WGmass_jer = [ 1.39202, 1.4023, 1.53842, 1, 2]
    ST_t_WGmass_photon_ID = [ 1.024, 1.04599, 1.0506, 1, 1.07298]
    ST_t_WGmass_electron_ID = [ 1, 1, 1, 1, 1]
    ST_t_WGmass_electron_Reco = [ 1, 1, 1, 1, 1]
    ST_t_WGmass_electron_HLT = [ 1, 1, 1, 1, 1]
    ST_t_WGmass_electron = [ 1, 1, 1, 1, 1]
    ST_t_WGmass_muon_ID = [ 1.00135, 1.0019, 1.00082, 1, 1.00086]
    ST_t_WGmass_muon_iso = [ 1.00064, 1.00064, 1.00067, 1, 1.0008]
    ST_t_WGmass_muon_HLT = [ 1.00143, 1.00338, 1.00077, 1, 1.00361]
    ST_t_WGmass_muon = [ 1.00342, 1.00594, 1.00226, 1, 1.00529]
    ST_t_WGmass_fakephoton = [ 1441.98, 1109.75, 1354.83, 1, 1056.46]
    ST_tbarW_WGmass_jec = [ 1.012, 1.00005, 1, 1, 1]
    ST_tbarW_WGmass_jer = [ 1.01187, 1.00004, 1, 1, 1]
    ST_tbarW_WGmass_photon_ID = [ 1.02911, 1.04348, 1, 1, 1]
    ST_tbarW_WGmass_electron_ID = [ 1, 1, 1, 1, 1]
    ST_tbarW_WGmass_electron_Reco = [ 1, 1, 1, 1, 1]
    ST_tbarW_WGmass_electron_HLT = [ 1, 1, 1, 1, 1]
    ST_tbarW_WGmass_electron = [ 1, 1, 1, 1, 1]
    ST_tbarW_WGmass_muon_ID = [ 1.00239, 1.0039, 1, 1, 1]
    ST_tbarW_WGmass_muon_iso = [ 1.00068, 1.00071, 1, 1, 1]
    ST_tbarW_WGmass_muon_HLT = [ 1.00322, 1.00258, 1, 1, 1]
    ST_tbarW_WGmass_muon = [ 1.0063, 1.0072, 1, 1, 1]
    ST_tbarW_WGmass_fakephoton = [ 213.862, 208.834, 1, 1, 1]
    ST_tbar_WGmass_jec = [ 1.38806, 1, 1, 1, 1]
    ST_tbar_WGmass_jer = [ 1.04542, 1, 1, 1, 1]
    ST_tbar_WGmass_photon_ID = [ 1.0235, 1.0135, 1, 1, 1]
    ST_tbar_WGmass_electron_ID = [ 1, 1, 1, 1, 1]
    ST_tbar_WGmass_electron_Reco = [ 1, 1, 1, 1, 1]
    ST_tbar_WGmass_electron_HLT = [ 1, 1, 1, 1, 1]
    ST_tbar_WGmass_electron = [ 1, 1, 1, 1, 1]
    ST_tbar_WGmass_muon_ID = [ 1.0005, 1.00054, 1, 1, 1]
    ST_tbar_WGmass_muon_iso = [ 1.00045, 1.00042, 1, 1, 1]
    ST_tbar_WGmass_muon_HLT = [ 1.00038, 1.0002, 1, 1, 1]
    ST_tbar_WGmass_muon = [ 1.00133, 1.00115, 1, 1, 1]
    ST_tbar_WGmass_fakephoton = [ 1124.19, 1075.97, 1, 1, 1]
    TTG_WGmass_jec = [ 1.15973, 1.12307, 1.29727, 1.46333, 1.00022]
    TTG_WGmass_jer = [ 1.09677, 1.20826, 1.04756, 1.40684, 1.42007]
    TTG_WGmass_photon_ID = [ 1.03341, 1.02683, 1.05085, 1.05293, 1.03085]
    TTG_WGmass_electron_ID = [ 1, 1, 1, 1, 1]
    TTG_WGmass_electron_Reco = [ 1, 1, 1, 1, 1]
    TTG_WGmass_electron_HLT = [ 1, 1, 1, 1, 1]
    TTG_WGmass_electron = [ 1, 1, 1, 1, 1]
    TTG_WGmass_muon_ID = [ 1.00127, 1.00144, 1.00271, 1.0029, 1.00238]
    TTG_WGmass_muon_iso = [ 1.00053, 1.00052, 1.00079, 1.00073, 1.00102]
    TTG_WGmass_muon_HLT = [ 1.00078, 1.00182, 1.003, 1.00096, 1.02117]
    TTG_WGmass_muon = [ 1.00258, 1.00378, 1.00652, 1.0046, 1.02464]
    TTG_WGmass_fakephoton = [ 1073.48, 1209.33, 1179.94, 792.269, 1282.98]
    WGJJ_WGmass_jec = [ 1.0436, 1.05614, 1.09057, 1.06458, 1.10101]
    WGJJ_WGmass_jer = [ 1.03499, 1.01784, 1.02308, 1.02354, 1.02194]
    WGJJ_WGmass_photon_ID = [ 1.03483, 1.03989, 1.04425, 1.04837, 1.05655]
    WGJJ_WGmass_electron_ID = [ 1, 1, 1, 1, 1]
    WGJJ_WGmass_electron_Reco = [ 1, 1, 1, 1, 1]
    WGJJ_WGmass_electron_HLT = [ 1, 1, 1, 1, 1]
    WGJJ_WGmass_electron = [ 1, 1, 1, 1, 1]
    WGJJ_WGmass_muon_ID = [ 1.00167, 1.00196, 1.00203, 1.00197, 1.00187]
    WGJJ_WGmass_muon_iso = [ 1.00059, 1.00068, 1.00073, 1.00072, 1.00081]
    WGJJ_WGmass_muon_HLT = [ 1.00133, 1.00276, 1.00388, 1.00431, 1.00868]
    WGJJ_WGmass_muon = [ 1.0036, 1.00541, 1.00666, 1.00701, 1.01139]
    WGJJ_WGmass_fakephoton = [ 1236.85, 1208.85, 1195.46, 1197.98, 1223.76]
    WGJJ_scale = [1.06518, 1.04666, 1.0431, 1.06526, 1.00256]
    WGJJ_pdf = [1.0087, 1.00232, 1.00295, 1.01165, 1.01688]
    WGJets_WGmass_jec = [ 1.07432, 1.13946, 1.59114, 1.00003, 1.00002]
    WGJets_WGmass_jer = [ 1.10714, 1.46496, 2.30982, 1.55407, 1.00001]
    WGJets_WGmass_photon_ID = [ 1.02993, 1.04401, 1.00881, 1.06553, 1.07298]
    WGJets_WGmass_electron_ID = [ 1, 1, 1, 1, 1]
    WGJets_WGmass_electron_Reco = [ 1, 1, 1, 1, 1]
    WGJets_WGmass_electron_HLT = [ 1, 1, 1, 1, 1]
    WGJets_WGmass_electron = [ 1, 1, 1, 1, 1]
    WGJets_WGmass_muon_ID = [ 1.00201, 1.00164, 1.00219, 1.0007, 1.00077]
    WGJets_WGmass_muon_iso = [ 1.00064, 1.00078, 1.00105, 1.00061, 1.00052]
    WGJets_WGmass_muon_HLT = [ 1.00134, 1.00737, 1.00367, 1.00068, 1.01111]
    WGJets_WGmass_muon = [ 1.00401, 1.00981, 1.00692, 1.002, 1.01241]
    WGJets_WGmass_fakephoton = [ 36.4345, 34.4604, 60.7105, 25.9719, 25.5222]
    WGJets_scale = [1.00073, 1.00197, 1.00354, 1.00499, 1.00244]
    WGJets_pdf = [1.01859, 1.02589, 1.01224, 1.01781, 1.01566]
    WW_WGmass_jec = [ 1.00004, 1.00006, 1, 1, 1]
    WW_WGmass_jer = [ 1.00001, 2, 1, 1, 1]
    WW_WGmass_photon_ID = [ 1.0522, 1.04387, 1, 1, 1]
    WW_WGmass_electron_ID = [ 1, 1, 1, 1, 1]
    WW_WGmass_electron_Reco = [ 1, 1, 1, 1, 1]
    WW_WGmass_electron_HLT = [ 1, 1, 1, 1, 1]
    WW_WGmass_electron = [ 1, 1, 1, 1, 1]
    WW_WGmass_muon_ID = [ 1.00163, 1.00581, 1, 1, 1]
    WW_WGmass_muon_iso = [ 1.00037, 1.00096, 1, 1, 1]
    WW_WGmass_muon_HLT = [ 1.00047, 1.00075, 1, 1, 1]
    WW_WGmass_muon = [ 1.00247, 1.00753, 1, 1, 1]
    WW_WGmass_fakephoton = [ 105.525, 98.5834, 1, 1, 1]
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
    ZG_WGmass_jec = [ 1.33353, 1.0001, 1, 1, 1.00003]
    ZG_WGmass_jer = [ 1.25324, 2.01626, 1, 1, 1.00001]
    ZG_WGmass_photon_ID = [ 1.0308, 1.05548, 1, 1, 1.05759]
    ZG_WGmass_electron_ID = [ 1, 1, 1, 1, 1]
    ZG_WGmass_electron_Reco = [ 1, 1, 1, 1, 1]
    ZG_WGmass_electron_HLT = [ 1, 1, 1, 1, 1]
    ZG_WGmass_electron = [ 1, 1, 1, 1, 1]
    ZG_WGmass_muon_ID = [ 1.00183, 1.0027, 1, 1, 1.00086]
    ZG_WGmass_muon_iso = [ 1.00066, 1.00066, 1, 1, 1.0008]
    ZG_WGmass_muon_HLT = [ 1.00081, 1.00268, 1, 1, 1.00806]
    ZG_WGmass_muon = [ 1.0033, 1.00605, 1, 1, 1.00974]
    ZG_WGmass_fakephoton = [ 264.06, 516.631, 1, 1, 187.564]
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
else :
    h=0
    ST_s_WGmass_jec = [ 1.00149, 1, 1, 1, 1]
    ST_s_WGmass_jer = [ 1.00013, 1, 1, 1, 1]
    ST_s_WGmass_photon_ID = [ 1.0282, 1, 1, 1, 1]
    ST_s_WGmass_electron_ID = [ 2, 1, 1, 1, 1]
    ST_s_WGmass_electron_Reco = [ 1.00337, 1, 1, 1, 1]
    ST_s_WGmass_electron_HLT = [ 1.01035, 1, 1, 1, 1]
    ST_s_WGmass_electron = [ 2.02752, 1, 1, 1, 1]
    ST_s_WGmass_muon_ID = [ 1, 1, 1, 1, 1]
    ST_s_WGmass_muon_iso = [ 1, 1, 1, 1, 1]
    ST_s_WGmass_muon_HLT = [ 1, 1, 1, 1, 1]
    ST_s_WGmass_muon = [ 1, 1, 1, 1, 1]
    ST_s_WGmass_fakephoton = [ 2695.89, 1, 1, 1, 1]
    ST_tW_WGmass_jec = [ 1.34285, 1.00003, 1, 1, 1]
    ST_tW_WGmass_jer = [ 1.00009, 1, 1, 1, 1]
    ST_tW_WGmass_photon_ID = [ 1.02937, 1.07298, 1, 1, 1]
    ST_tW_WGmass_electron_ID = [ 1.01347, 1.01685, 1, 1, 1]
    ST_tW_WGmass_electron_Reco = [ 1.00476, 1.00452, 1, 1, 1]
    ST_tW_WGmass_electron_HLT = [ 1.0022, 1.00289, 1, 1, 1]
    ST_tW_WGmass_electron = [ 1.02054, 1.0244, 1, 1, 1]
    ST_tW_WGmass_muon_ID = [ 1, 1, 1, 1, 1]
    ST_tW_WGmass_muon_iso = [ 1, 1, 1, 1, 1]
    ST_tW_WGmass_muon_HLT = [ 1, 1, 1, 1, 1]
    ST_tW_WGmass_muon = [ 1, 1, 1, 1, 1]
    ST_tW_WGmass_fakephoton = [ 340.896, 253.539, 1, 1, 1]
    ST_t_WGmass_jec = [ 1.00436, 1.00015, 1.00118, 1, 1]
    ST_t_WGmass_jer = [ 1.16417, 1.18712, 2.01923, 1, 1]
    ST_t_WGmass_photon_ID = [ 1.03232, 1.0253, 1.01371, 1, 1]
    ST_t_WGmass_electron_ID = [ 1.01395, 1.01153, 1.02978, 1, 1]
    ST_t_WGmass_electron_Reco = [ 1.00365, 1.00356, 1.00452, 1, 1]
    ST_t_WGmass_electron_HLT = [ 1.00442, 1.00244, 1.00855, 1, 1]
    ST_t_WGmass_electron = [ 1.02225, 1.01761, 1.04328, 1, 1]
    ST_t_WGmass_muon_ID = [ 1, 1, 1, 1, 1]
    ST_t_WGmass_muon_iso = [ 1, 1, 1, 1, 1]
    ST_t_WGmass_muon_HLT = [ 1, 1, 1, 1, 1]
    ST_t_WGmass_muon = [ 1, 1, 1, 1, 1]
    ST_t_WGmass_fakephoton = [ 1488.72, 1257.89, 1190.94, 1, 1]
    ST_tbarW_WGmass_jec = [ 1.00148, 1, 1, 1, 1]
    ST_tbarW_WGmass_jer = [ 1.00094, 1, 1, 1, 1]
    ST_tbarW_WGmass_photon_ID = [ 1.02142, 1, 1, 1, 1]
    ST_tbarW_WGmass_electron_ID = [ 1.01429, 1, 1, 1, 1]
    ST_tbarW_WGmass_electron_Reco = [ 1.0045, 1, 1, 1, 1]
    ST_tbarW_WGmass_electron_HLT = [ 1.00232, 1, 1, 1, 1]
    ST_tbarW_WGmass_electron = [ 1.02121, 1, 1, 1, 1]
    ST_tbarW_WGmass_muon_ID = [ 1, 1, 1, 1, 1]
    ST_tbarW_WGmass_muon_iso = [ 1, 1, 1, 1, 1]
    ST_tbarW_WGmass_muon_HLT = [ 1, 1, 1, 1, 1]
    ST_tbarW_WGmass_muon = [ 1, 1, 1, 1, 1]
    ST_tbarW_WGmass_fakephoton = [ 207.18, 1, 1, 1, 1]
    ST_tbar_WGmass_jec = [ 1.0002, 1, 1, 1, 1.00009]
    ST_tbar_WGmass_jer = [ 1.00012, 1, 1, 1, 1.00003]
    ST_tbar_WGmass_photon_ID = [ 1.02917, 1, 1, 1, 1.07512]
    ST_tbar_WGmass_electron_ID = [ 1.00937, 1, 1, 1, 1.01636]
    ST_tbar_WGmass_electron_Reco = [ 1.00148, 1, 1, 1, 1.00452]
    ST_tbar_WGmass_electron_HLT = [ 1.00178, 1, 1, 1, 1.00305]
    ST_tbar_WGmass_electron = [ 1.01266, 1, 1, 1, 1.02407]
    ST_tbar_WGmass_muon_ID = [ 1, 1, 1, 1, 1]
    ST_tbar_WGmass_muon_iso = [ 1, 1, 1, 1, 1]
    ST_tbar_WGmass_muon_HLT = [ 1, 1, 1, 1, 1]
    ST_tbar_WGmass_muon = [ 1, 1, 1, 1, 1]
    ST_tbar_WGmass_fakephoton = [ 1119.59, 1, 1, 1, 1157.62]
    TTG_WGmass_jec = [ 1.13055, 1.40639, 1.7781, 1.37429, 1.00632]
    TTG_WGmass_jer = [ 1.12303, 1.24577, 1.42546, 1.31809, 1.28893]
    TTG_WGmass_photon_ID = [ 1.03209, 1.0461, 1.05185, 1.04109, 1.06247]
    TTG_WGmass_electron_ID = [ 1.01101, 1.15791, 1.02848, 1.32475, 1.01563]
    TTG_WGmass_electron_Reco = [ 1.00276, 1.00548, 1.00746, 1.00864, 1.00612]
    TTG_WGmass_electron_HLT = [ 1.00298, 1.01308, 1.00821, 1.01106, 1.00355]
    TTG_WGmass_electron = [ 1.01717, 1.18931, 1.0447, 1.34771, 1.02546]
    TTG_WGmass_muon_ID = [ 1, 1, 1, 1, 1]
    TTG_WGmass_muon_iso = [ 1, 1, 1, 1, 1]
    TTG_WGmass_muon_HLT = [ 1, 1, 1, 1, 1]
    TTG_WGmass_muon = [ 1, 1, 1, 1, 1]
    TTG_WGmass_fakephoton = [ 1345.74, 2275.35, 1587.88, 1293.02, 913.72]
    WGJJ_WGmass_jec = [ 1.04424, 1.07615, 1.0425, 1.0818, 1.0868]
    WGJJ_WGmass_jer = [ 1.04051, 1.07601, 1.11806, 1.03571, 1.27065]
    WGJJ_WGmass_photon_ID = [ 1.03387, 1.03801, 1.04252, 1.04399, 1.05614]
    WGJJ_WGmass_electron_ID = [ 1.02417, 1.02872, 1.05228, 1.09331, 1.02697]
    WGJJ_WGmass_electron_Reco = [ 1.00358, 1.00467, 1.00663, 1.00757, 1.00756]
    WGJJ_WGmass_electron_HLT = [ 1.00384, 1.00559, 1.00667, 1.01368, 1.00945]
    WGJJ_WGmass_electron = [ 1.03207, 1.03971, 1.06728, 1.12159, 1.04461]
    WGJJ_WGmass_muon_ID = [ 1, 1, 1, 1, 1]
    WGJJ_WGmass_muon_iso = [ 1, 1, 1, 1, 1]
    WGJJ_WGmass_muon_HLT = [ 1, 1, 1, 1, 1]
    WGJJ_WGmass_muon = [ 1, 1, 1, 1, 1]
    WGJJ_WGmass_fakephoton = [ 1328.9, 1268.07, 1286.57, 1237.22, 1234.26]
    WGJJ_scale = [1.06605, 1.06036, 1.04057, 1.02391, 1.04981]
    WGJJ_pdf = [1.01812, 1.00926, 1.00308, 1.04791, 1.01785]
    WGJets_WGmass_jec = [ 1.20373, 1.14067, 2.03972, 2.13369, 1]
    WGJets_WGmass_jer = [ 1.15988, 1.33756, 2.11608, 2.13361, 1]
    WGJets_WGmass_photon_ID = [ 1.03235, 1.02676, 1.06517, 1.05841, 1]
    WGJets_WGmass_electron_ID = [ 1.06648, 1.03628, 1.01034, 1.04339, 1]
    WGJets_WGmass_electron_Reco = [ 1.00502, 1.00708, 1.00259, 1.01205, 1]
    WGJets_WGmass_electron_HLT = [ 1.00406, 1.016, 1.01359, 1.03147, 1]
    WGJets_WGmass_electron = [ 1.07718, 1.06069, 1.02765, 1.08884, 1]
    WGJets_WGmass_muon_ID = [ 1, 1, 1, 1, 1]
    WGJets_WGmass_muon_iso = [ 1, 1, 1, 1, 1]
    WGJets_WGmass_muon_HLT = [ 1, 1, 1, 1, 1]
    WGJets_WGmass_muon = [ 1, 1, 1, 1, 1]
    WGJets_WGmass_fakephoton = [ 31.7842, 46.2636, 87.1863, 89.6845, 1]
    WGJets_scale = [1.00022, 1.00177, 1.00404, 1.0077, 1]
    WGJets_pdf = [1.01795, 1.01134, 1.02954, 1.05798, 1]
    WW_WGmass_jec = [ 1.00004, 2, 1.00002, 1, 1]
    WW_WGmass_jer = [ 1.52953, 2, 2, 1, 1]
    WW_WGmass_photon_ID = [ 1.02104, 1.02255, 1.05658, 1, 1]
    WW_WGmass_electron_ID = [ 1.01575, 1.01685, 1.00699, 1, 1]
    WW_WGmass_electron_Reco = [ 1.00675, 1.00452, 1.00682, 1, 1]
    WW_WGmass_electron_HLT = [ 1.00482, 1.00289, 1.00243, 1, 1]
    WW_WGmass_electron = [ 1.02755, 1.0244, 1.01633, 1, 1]
    WW_WGmass_muon_ID = [ 1, 1, 1, 1, 1]
    WW_WGmass_muon_iso = [ 1, 1, 1, 1, 1]
    WW_WGmass_muon_HLT = [ 1, 1, 1, 1, 1]
    WW_WGmass_muon = [ 1, 1, 1, 1, 1]
    WW_WGmass_fakephoton = [ 107.837, 103.623, 91.7806, 1, 1]
    WZ_WGmass_jec = [ 1, 1, 1, 1, 1]
    WZ_WGmass_jer = [ 1, 1, 1, 1, 1]
    WZ_WGmass_photon_ID = [ 1, 1, 1, 1, 1]
    WZ_WGmass_electron_ID = [ 1, 1, 1, 1, 1]
    WZ_WGmass_electron_Reco = [ 1, 1, 1, 1, 1]
    WZ_WGmass_electron_HLT = [ 1, 1, 1, 1, 1]
    WZ_WGmass_electron = [ 1, 1, 1, 1, 1]
    WZ_WGmass_muon_ID = [ 1, 1, 1, 1, 1]
    WZ_WGmass_muon_iso = [ 1, 1, 1, 1, 1]
    WZ_WGmass_muon_HLT = [ 1, 1, 1, 1, 1]
    WZ_WGmass_muon = [ 1, 1, 1, 1, 1]
    WZ_WGmass_fakephoton = [ 1, 1, 1, 1, 1]
    ZG_WGmass_jec = [ 1.17759, 4.0479, 2.25779, 1, 1]
    ZG_WGmass_jer = [ 1.50717, 3.38235, 3.60597, 1, 1]
    ZG_WGmass_photon_ID = [ 1.0322, 1.01525, 1.02265, 1, 1]
    ZG_WGmass_electron_ID = [ 1.01368, 1.00374, 1.00803, 1, 1]
    ZG_WGmass_electron_Reco = [ 1.00453, 1.00641, 1.01542, 1, 1]
    ZG_WGmass_electron_HLT = [ 1.00372, 1.00666, 1.01801, 1, 1]
    ZG_WGmass_electron = [ 1.0221, 1.00392, 1.01178, 1, 1]
    ZG_WGmass_muon_ID = [ 1, 1, 1, 1, 1]
    ZG_WGmass_muon_iso = [ 1, 1, 1, 1, 1]
    ZG_WGmass_muon_HLT = [ 1, 1, 1, 1, 1]
    ZG_WGmass_muon = [ 1, 1, 1, 1, 1]
    ZG_WGmass_fakephoton = [ 327.2, 743.71, 727.599, 1, 1]
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
    WGmass_fakephoton = [ 1.2253, 1.23011, 1.22176, 1.18791, 1.14787]

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
   fakephoton_bincontent = th1_fakephoton.GetBinContent(i) if th1_fakephoton.GetBinContent(i)>0 else 0
   fakelepton_bincontent = th1_fakelepton.GetBinContent(i) if th1_fakelepton.GetBinContent(i)>0 else 0
   doublefake_bincontent = th1_doublefake.GetBinContent(i) if th1_doublefake.GetBinContent(i)>0 else 0

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
