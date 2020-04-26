#export dir='../../MC'
#root -l -b -q 'eff.cc++("$dir", "minisample_Dst2D0pi_D02Kpi_2016_Dw_GEN", "DOWN")' > log/log1.txt 2> log/err1.txt
#root -l -b -q 'eff.cc++("$dir", "minisample_Dst2D0pi_D02Kpi_2016_Up_GEN", "UP")' > log/log2.txt 2> log/err2.txt
#root -l -b -q up_plus_down_dev.cc

export dir='../../Data'
root -l -b -q 'eff.cc++("$dir", "D02Kmpip_15_Up")' > log/log.txt 2> log/err.txt
