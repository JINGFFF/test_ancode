#### step 1 : fake lepton estimation
*    g++ -o make_hist `root-config --cflags --glibs` 1_preprocess_fake_lepton.C
    ./make_hist filelist_dir/loose_DY.txt out 2018 muon mc DY loose

*    g++ -o cal_fakerate `root-config --cflags --glibs` 2_calculate_fake_lepton_rate.C

#### step 2 : fake photom estimation
    g++ -o make_hist `root-config --cflags --glibs` 1_make_fake_photon_template.C

    ./make_hist filelist_dir/tight_lepton.txt 1_out_1 2018 data all data singlelepton medium 4 10
#### step 3 : make plot for signal/control region
	g++ -o make_hist `root-config --cflags --glibs` 1_make_histogram.C

    ./make_hist filelist_dir/tight_muon.txt 1_out_1 2018 muon data SingleMuon medium
#### step 4 : aQGC study
    g++ -o fit_ratio `root-config --cflags --glibs` 1_fit_ratio.C

    ./fit_ratio filelist_dir/tight_WGJJ_aqgc.txt 1_out_1 2018 muon mc wgaqgc medium 1

    g++ -o limit_hist `root-config --cflags --glibs` 2_limit.C

	./limit_hist filelist_dir/tight_muon.txt 2_out_1 2018 muon data SingleMuon mediumi
#### step 5 : unfolding study
    g++ -o make_hist `root-config --cflags --glibs` 1_unfold_histgram.C

	./make_hist filelist_dir/tight_muon.txt 1_out_1 2018 muon data signal SingleMuon medium
