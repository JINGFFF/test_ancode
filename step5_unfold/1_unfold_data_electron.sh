#signal
./unfold_histgram filelist_dir/tight_electron.txt test_unfold_hist_v10 2018 electron data signal SingleElectron medium
./unfold_histgram filelist_dir/loose_electron.txt test_unfold_hist_v10 2018 electron doublefake signal SingleElectron medium
./unfold_histgram filelist_dir/tight_electron.txt test_unfold_hist_v10 2018 electron fakephoton signal SingleElectron medium
./unfold_histgram filelist_dir/loose_electron.txt test_unfold_hist_v10 2018 electron fakelepton signal SingleElectron medium
#control
./unfold_histgram filelist_dir/tight_electron.txt test_unfold_hist_v10 2018 electron data control SingleElectron medium
./unfold_histgram filelist_dir/loose_electron.txt test_unfold_hist_v10 2018 electron doublefake control SingleElectron medium
./unfold_histgram filelist_dir/tight_electron.txt test_unfold_hist_v10 2018 electron fakephoton control SingleElectron medium
./unfold_histgram filelist_dir/loose_electron.txt test_unfold_hist_v10 2018 electron fakelepton control SingleElectron medium
