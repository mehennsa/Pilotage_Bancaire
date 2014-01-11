// This is the main DLL file.

#include "stdafx.h"

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
}