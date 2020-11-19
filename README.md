## test_ancode
#### step 1 : fake lepton estimation
    g++ -o make_hist `root-config --cflags --glibs` 1_preprocess_fake_lepton.C

    ./make_hist filelist_dir/loose_DY.txt out 2018 muon mc DY loose
#### step 2 : fake photom estimation
    g++ -o make_hist `root-config --cflags --glibs` 1_make_fake_photon_template.C

    ./make_hist filelist_dir/tight_lepton.txt 1_out_1 2018 data all data singlelepton medium 4 10
