/***************************************************************************** 
 * Project: RooFit                                                           * 
 *                                                                           * 
 * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/ 

// Your description goes here... 

#include "Riostream.h" 

#include "RooArg_pos_sidePdf.h" 
#include "RooAbsReal.h" 
#include "RooAbsCategory.h" 
#include <math.h> 
#include "TMath.h" 

ClassImp(RooArg_pos_sidePdf); 

 RooArg_pos_sidePdf::RooArg_pos_sidePdf(const char *name, const char *title, 
                        RooAbsReal& _dtf_pos_low,
                        RooAbsReal& _N,
                        RooAbsReal& _a,
                        RooAbsReal& _b) :
   RooAbsPdf(name,title), 
   dtf_pos_low("dtf_pos_low","dtf_pos_low",this,_dtf_pos_low),
   N("N","N",this,_N),
   a("a","a",this,_a),
   b("b","b",this,_b)
 { 
 } 


 RooArg_pos_sidePdf::RooArg_pos_sidePdf(const RooArg_pos_sidePdf& other, const char* name) :  
   RooAbsPdf(other,name), 
   dtf_pos_low("dtf_pos_low",this,other.dtf_pos_low),
   N("N",this,other.N),
   a("a",this,other.a),
   b("b",this,other.b)
 { 
 } 



 Double_t RooArg_pos_sidePdf::evaluate() const 
 { 
   // ENTER EXPRESSION IN TERMS OF VARIABLE ARGUMENTS HERE 
   return 1/N*pow(dtf_pos_low-a,b) ; 
 } 


