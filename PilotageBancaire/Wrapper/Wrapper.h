// Wrapper.h

#pragma once
#include "Computations.h"
using namespace System;

namespace Wrapper {

	public ref class WrapperClass
	{
	private:
		double EspT;
		double LInf;
		double Rate;

	public :
		WrapperClass() {EspT = LInf = Rate= 0;};
		void getBounds(double S0, double sigma, double rate, 
		double LSup, double nbLitres, double valeurLoan, int M);
		void getTaux(double S0, double sigma, double rate, double LSup, double LInf, double nbLitres, double valeurLoan, double T, int M);
		double getEspT() {return EspT;};
		double getLInf() {return LInf;};
		double getRate() {return Rate;};
	};
}
