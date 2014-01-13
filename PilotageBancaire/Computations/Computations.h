#pragma once
#define DLLEXP   __declspec( dllexport )
namespace Computations{
  DLLEXP void estimateMaturity(double S0, double sigma, double rate, double LSup, 
	  double nbLitres, double valeurLoan, int M, double &EspT, double &LInf);
  DLLEXP void evolution(double S0, double sigma, double rate, double T, 
	  double LSup, double LInf, int J, int M, double &value);
  DLLEXP void estimateRate(double S0, double sigma, double rate, double LSup, double LInf, double nbLitres, double valeurLoan, double T, int M, double &taux, double* refundArray);
}