#signal
./make_hist filelist_dir/tight_for_analysis_muon2.txt 1_out_1 2018 muon data signal SingleMuon medium
./make_hist filelist_dir/loose_for_analysis_muon2.txt 1_out_1 2018 muon doublefake signal SingleMuon medium
./make_hist filelist_dir/tight_for_analysis_muon2.txt 1_out_1 2018 muon fakephoton signal SingleMuon medium
./make_hist filelist_dir/loose_for_analysis_muon2.txt 1_out_1 2018 muon fakelepton signal SingleMuon medium
#control
./make_hist filelist_dir/tight_for_analysis_muon2.txt 1_out_1 2018 muon data control SingleMuon medium
./make_hist filelist_dir/loose_for_analysis_muon2.txt 1_out_1 2018 muon doublefake control SingleMuon medium
./make_hist filelist_dir/tight_for_analysis_muon2.txt 1_out_1 2018 muon fakephoton control SingleMuon medium
./make_hist filelist_dir/loose_for_analysis_muon2.txt 1_out_1 2018 muon fakelepton control SingleMuon medium
