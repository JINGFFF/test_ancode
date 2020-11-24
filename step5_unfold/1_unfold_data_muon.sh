#signal
./unfold_histgram filelist_dir/tight_muon.txt test_unfold_hist_v10 2018 muon data signal SingleMuon medium
./unfold_histgram filelist_dir/loose_muon.txt test_unfold_hist_v10 2018 muon doublefake signal SingleMuon medium
./unfold_histgram filelist_dir/tight_muon.txt test_unfold_hist_v10 2018 muon fakephoton signal SingleMuon medium
./unfold_histgram filelist_dir/loose_muon.txt test_unfold_hist_v10 2018 muon fakelepton signal SingleMuon medium
#control
./unfold_histgram filelist_dir/tight_muon.txt test_unfold_hist_v10 2018 muon data control SingleMuon medium
./unfold_histgram filelist_dir/loose_muon.txt test_unfold_hist_v10 2018 muon doublefake control SingleMuon medium
./unfold_histgram filelist_dir/tight_muon.txt test_unfold_hist_v10 2018 muon fakephoton control SingleMuon medium
./unfold_histgram filelist_dir/loose_muon.txt test_unfold_hist_v10 2018 muon fakelepton control SingleMuon medium
