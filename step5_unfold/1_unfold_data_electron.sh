#signal
./make_hist filelist_dir/tight_for_analysis_electron2.txt 1_out_1 2018 electron data signal SingleElectron medium
./make_hist filelist_dir/loose_for_analysis_electron2.txt 1_out_1 2018 electron doublefake signal SingleElectron medium
./make_hist filelist_dir/tight_for_analysis_electron2.txt 1_out_1 2018 electron fakephoton signal SingleElectron medium
./make_hist filelist_dir/loose_for_analysis_electron2.txt 1_out_1 2018 electron fakelepton signal SingleElectron medium
#control
./make_hist filelist_dir/tight_for_analysis_electron2.txt 1_out_1 2018 electron data control SingleElectron medium
./make_hist filelist_dir/loose_for_analysis_electron2.txt 1_out_1 2018 electron doublefake control SingleElectron medium
./make_hist filelist_dir/tight_for_analysis_electron2.txt 1_out_1 2018 electron fakephoton control SingleElectron medium
./make_hist filelist_dir/loose_for_analysis_electron2.txt 1_out_1 2018 electron fakelepton control SingleElectron medium
