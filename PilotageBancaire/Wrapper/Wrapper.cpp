// This is the main DLL file.

#include "stdafx.h"
#include <msclr\marshal.h>
#include "Wrapper.h"

using namespace Computations;
using namespace msclr::interop;

namespace Wrapper {
	void WrapperClass::getBounds(double S0, double sigma, double rate, 
			double LSup, double nbLitres, double valeurLoan, int M) {
		double l, t;
		estimateMaturity(S0, sigma, rate, LSup, nbLitres, valeurLoan, M, t, l);
		this->LInf = l;
		this->EspT = t;
	}

	void WrapperClass::getTaux(double S0, double sigma, double rate, double LSup, double LInf, double nbLitres, double valeurLoan, double T, int M, array<double> ^refundArray_sharp){
		double taux;
		double *refundArray = new double[(int)T*12];

		estimateRate(S0, sigma, rate, LSup, LInf, nbLitres, valeurLoan, T, M,taux, refundArray);

		this->Rate = taux;
	}

}