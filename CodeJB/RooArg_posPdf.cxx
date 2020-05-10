/***************************************************************************** 
 * Project: RooFit                                                           * 
 *                                                                           * 
 * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/ 

// Your description goes here... 

#include "Riostream.h" 

#include "RooArg_posPdf.h" 
#include "RooAbsReal.h" 
#include "RooAbsCategory.h" 
#include <math.h> 
#include "TMath.h" 

ClassImp(RooArg_posPdf); 

 RooArg_posPdf::RooArg_posPdf(const char *name, const char *title, 
                        RooAbsReal& _dtf_pos,
                        RooAbsReal& _N,
                        RooAbsReal& _a,
                        RooAbsReal& _b) :
   RooAbsPdf(name,title), 
   dtf_pos("dtf_pos","dtf_pos",this,_dtf_pos),
   N("N","N",this,_N),
   a("a","a",this,_a),
   b("b","b",this,_b)
 { 
 } 


 RooArg_posPdf::RooArg_posPdf(const RooArg_posPdf& other, const char* name) :  
   RooAbsPdf(other,name), 
   dtf_pos("dtf_pos",this,other.dtf_pos),
   N("N",this,other.N),
   a("a",this,other.a),
   b("b",this,other.b)
 { 
 } 



 Double_t RooArg_posPdf::evaluate() const 
 { 
   // ENTER EXPRESSION IN TERMS OF VARIABLE ARGUMENTS HERE 
   return 1./N*pow(dtf_pos-a,b) ; 
 } 



