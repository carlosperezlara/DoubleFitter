#include <string.h>
#include "Model3.h"

using std::string;

//=======================================================
Model3::Model3() {
}

//============================================================
// Default Parametrisation
// FSGN[0] + FBGR[1,2] + SGN[3,4,5,6,7] + BGR[8,9,10]
void Model3::Init() {
  SetNPars( 10 );
  SetParameter( 0, "v2sgn"  , +0.10, -0.20, +0.40);
  SetParameter( 1, "vsbgr_a", +0.10, -5.00, +5.00);
  SetParameter( 2, "v2bgr_b", +0.10, -1.00, +1.00);
  SetParameter( 3, "sgn_raw", +1e+1, +0.10, +1e+2);
  SetParameter( 4, "sgn_mu" , +1.87, +1.84, +1.89);
  SetParameter( 5, "sgn_sg" , +0.01, +0.001,+0.10);
  SetParameter( 6, "bgr_sl" , -1.00, -100., +0.01);
  SetParameter( 7, "bgr_th" ,  0.00, -100., +100.);
  SetParameter( 8, "bgr_a"  , +100., +0.10, +1e+4);
  SetParameter( 9, "v2bgr_c",  0.00, -10.0, +10.0);
  SetFitRangeFromMassHistogram();
  for(int i=0; i!=fNPar; ++i)
    fParFix[i] = false;
}
double Model3::FBgr(double x, double *p) {
  return double( p[1]*(x-p[4]) + p[2] + p[9]*(x-p[4])*(x-p[4]) );
}
double Model3::Sgn(double x, double *p) {
  return double( p[3]*TMath::Gaus(x,p[4],p[5])/p[5]/TMath::Sqrt(2*TMath::Pi()) );
}
double Model3::Bgr(double x, double *p) {
  return double( p[8]*( TMath::Exp(+p[6]*(x-p[4])) + p[7] ) );
}
