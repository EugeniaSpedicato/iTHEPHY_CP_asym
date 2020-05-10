/*****************************************************************************
 * Project: RooFit                                                           *
 *                                                                           *
  * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/

#ifndef ROOARG_NEGPDF
#define ROOARG_NEGPDF

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
 
class RooArg_negPdf : public RooAbsPdf {
public:
  RooArg_negPdf() {} ; 
  RooArg_negPdf(const char *name, const char *title,
	      RooAbsReal& _dtf_neg,
	      RooAbsReal& _N,
	      RooAbsReal& _a,
	      RooAbsReal& _b);
  RooArg_negPdf(const RooArg_negPdf& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooArg_negPdf(*this,newname); }
  inline virtual ~RooArg_negPdf() { }

protected:

  RooRealProxy dtf_neg ;
  RooRealProxy N ;
  RooRealProxy a ;
  RooRealProxy b ;
  
  Double_t evaluate() const ;

private:

  ClassDef(RooArg_negPdf,1) // Your description goes here...
};
 
#endif
