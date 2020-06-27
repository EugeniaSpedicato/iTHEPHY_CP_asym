#export dir='../../MC'
#g++ -pthread -fopenmp -ftree-vectorize -msse -ffast-math -o eff eff.cc `root-config --cflags --libs`
#./eff "/home/smjoblan/iTHEPHY/MC" "minisample_Dst2D0pi_D02Kpi_2016_Dw_GEN" "down" #> log/log1.txt 2> log/err1.txt
#./eff "/home/smjoblan/iTHEPHY/MC" "minisample_Dst2D0pi_D02Kpi_2016_Up_GEN" "up" #> log/log2.txt 2> log/err2.txt
#./eff "/home/smjoblan/iTHEPHY/MC" "all" "up_down" #> log/log3.txt 2> log/err3.txt
#root -l -b -q up_plus_down_dev.cc

export dir='../../Data'
root -l -b -q -pthreads -fopenmp -ftree-vectorize -msse -ffast-math 'data.cc++("$dir", "D02Kmpip_15_Up", "up")' #> log/log_1.txt 2> log/err_1.txt
#root -l -b -q -pthreads -fopenmp -ftree-vectorize -msse -ffast-math 'data.cc++("$dir", "D02Kmpip_15_Dw", "down")' > log/log_2.txt 2> log/err_2.txt
#root -l -b -q -pthreads -fopenmp -ftree-vectorize -msse -ffast-math 'data.cc++("$dir", "all_data_test", "up_down")' > log/log_3.txt 2> log/err_3.txt
