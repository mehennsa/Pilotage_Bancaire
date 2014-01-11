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

	public :
		WrapperClass() {EspT = LInf = 0;};
		void getBounds(double S0, double sigma, double rate, 
			double LSup, double nbLitres, double valeurLoan, int M);
		double getEspT() {return EspT;};
		double getLInf() {return LInf;};
	};
}
