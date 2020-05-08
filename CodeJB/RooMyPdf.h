/*****************************************************************************
 * Project: RooFit                                                           *
 *                                                                           *
  * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/

#ifndef ROOMYPDF
#define ROOMYPDF

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
 
class RooMyPdf : public RooAbsPdf {
public:
  RooMyPdf() {} ; 
  RooMyPdf(const char *name, const char *title,
	      RooAbsReal& _x,
	      RooAbsReal& _N,
	      RooAbsReal& _a,
	      RooAbsReal& _b,
	      RooAbsReal& _c);
  RooMyPdf(const RooMyPdf& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooMyPdf(*this,newname); }
  inline virtual ~RooMyPdf() { }

protected:

  RooRealProxy x ;
  RooRealProxy N ;
  RooRealProxy a ;
  RooRealProxy b ;
  RooRealProxy c ;
  
  Double_t evaluate() const ;

private:

  ClassDef(RooMyPdf,1) // Your description goes here...
};
 
#endif