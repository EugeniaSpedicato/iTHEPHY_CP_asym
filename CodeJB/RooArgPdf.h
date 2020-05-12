/*****************************************************************************
 * Project: RooFit                                                           *
 *                                                                           *
  * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/

#ifndef ROOARGPDF
#define ROOARGPDF

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
 
class RooArgPdf : public RooAbsPdf {
public:
  RooArgPdf() {} ; 
  RooArgPdf(const char *name, const char *title,
	      RooAbsReal& _DTF_Mass,
	      RooAbsReal& _N,
	      RooAbsReal& _a,
	      RooAbsReal& _b,
	      RooAbsReal& _c);
  RooArgPdf(const RooArgPdf& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooArgPdf(*this,newname); }
  inline virtual ~RooArgPdf() { }

protected:

  RooRealProxy DTF_Mass ;
  RooRealProxy N ;
  RooRealProxy a ;
  RooRealProxy b ;
  RooRealProxy c ;
  
  Double_t evaluate() const ;

private:

  ClassDef(RooArgPdf,1) // Your description goes here...
};
 
#endif