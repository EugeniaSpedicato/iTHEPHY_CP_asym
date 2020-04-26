#include "eff.h"
#include <chrono>


void data(string dir, string sample)
{
  uint64_t start_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
  string input_name = dir+"/"+sample+".root";
  TChain *ntp = new TChain("ntp");
  ntp->Add(input_name.c_str());

  TChain *ntp = new TChain("ntp");


  int nEvents = ntp->GetEntries();

  cout << "Number of events: " << nEvents << endl;






  uint64_t end_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
  float elapsed = (end_time - start_time)*0.000001;
  std::cout << "computation time/s: " << elapsed << std::endl;
  std::cout << "computation time/min: " << elapsed/60. << std::endl;
}
