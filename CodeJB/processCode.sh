#export dir='../../MC'
#root -l -b -q -ftree-vectorize -msse -ffast-math 'eff.cc++("$dir", "minisample_Dst2D0pi_D02Kpi_2016_Dw_GEN", "down")' 2> log/err1.txt
#root -l -b -q -ftree-vectorize -msse -ffast-math 'eff.cc++("$dir", "minisample_Dst2D0pi_D02Kpi_2016_Up_GEN", "up")' 2> log/err2.txt
#root -l -b -q -ftree-vectorize -msse -ffast-math 'eff.cc++("$dir", "all", "up_down")' 2> log/err3.txt
#root -l -b -q up_plus_down_dev.cc

export dir='../../Data'
root -l -b -q -ftree-vectorize -msse -ffast-math 'data.cc++("$dir", "D02Kmpip_15_Up", "up")' #> log/log.txt 2> log/err.txt
root -l -b -q -ftree-vectorize -msse -ffast-math 'data.cc++("$dir", "D02Kmpip_15_Dw", "down")' #> log/log_2.txt 2> log/err_2.txt
root -l -b -q -ftree-vectorize -msse -ffast-math 'data.cc++("$dir", "all", "up_down")'
