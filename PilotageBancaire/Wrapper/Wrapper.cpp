// This is the main DLL file.

#include "stdafx.h"
#include <msclr\marshal.h>
#include "Wrapper.h"

using namespace Computations;

namespace Wrapper {
	void WrapperClass::getBounds(double S0, double sigma, double rate, 
			double LSup, double nbLitres, double valeurLoan, int M) {
		double l, t;
		estimateMaturity(S0, sigma, rate, LSup, nbLitres, valeurLoan, M, t, l);
		this->LInf = l;
		this->EspT = t;
	}

	void WrapperClass::getTaux(double S0, double sigma, double rate, double LSup, double LInf, double nbLitres, double valeurLoan, double T, int M, array<double> ^refund, double addedMaturity){
		double taux, returns;
		double gain=0;
		double tra;
		double* refunds = new double[(int)T*12];
		for (int k = 0; k<(int)T*12; k++){
			refunds[k] = 0;
		}
		estimateRate(S0, sigma, rate, LSup, LInf, nbLitres, valeurLoan, T, M,taux, refunds, addedMaturity, gain, returns, tra);
		for (int i = 0; i < (int)T*12; i++)
			refund[i] = (double)refunds[i];
		this->Rate = taux;
		this->Gain = gain;
		this->Tra = tra;
		this->Returns = returns;
	}

}