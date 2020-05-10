/*****************************************************************************
 * Project: RooFit                                                           *
 *                                                                           *
  * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/

#ifndef ROOARG_POSPDF
#define ROOARG_POSPDF

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
 
class RooArg_posPdf : public RooAbsPdf {
public:
  RooArg_posPdf() {} ; 
  RooArg_posPdf(const char *name, const char *title,
	      RooAbsReal& _dtf_pos,
	      RooAbsReal& _N,
	      RooAbsReal& _a,
	      RooAbsReal& _b);
  RooArg_posPdf(const RooArg_posPdf& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooArg_posPdf(*this,newname); }
  inline virtual ~RooArg_posPdf() { }

protected:

  RooRealProxy dtf_pos ;
  RooRealProxy N ;
  RooRealProxy a ;
  RooRealProxy b ;
  
  Double_t evaluate() const ;

private:

  ClassDef(RooArg_posPdf,1) // Your description goes here...
};
 
#endif
