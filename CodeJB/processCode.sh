#export dir='../../MC'
#root -l -b -q 'eff.cc++("$dir", "minisample_Dst2D0pi_D02Kpi_2016_Dw_GEN", "DOWN")' 2> log/err1.txt
#root -l -b -q 'eff.cc++("$dir", "minisample_Dst2D0pi_D02Kpi_2016_Up_GEN", "UP")' 2> log/err2.txt
#root -l -b -q up_plus_down_dev.cc

export dir='../../Data'
#root -l -b -q -ftree-vectorize -msse -ffast-math 'data.cc++("$dir", "D02Kmpip_15_Up", "UP")' #> log/log.txt 2> log/err.txt
root -l -b -q -ftree-vectorize -msse -ffast-math 'data.cc++("$dir", "D02Kmpip_15_Dw", "DOWN")' #> log/log_2.txt 2> log/err_2.txt
