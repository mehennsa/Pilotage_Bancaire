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
		double Gain;
		double Tra;
		double Returns;


	public :
		WrapperClass() {EspT = LInf = Rate= Gain = Tra = Returns= 0;};
		void getBounds(double S0, double sigma, double rate, 
		double LSup, double nbLitres, double valeurLoan, int M);
		void getTaux(double S0, double sigma, double rate, double LSup, double LInf, double nbLitres, double valeurLoan, double T, int M, array<double> ^refund, double addedMaturity);
		double getEspT() {return EspT;};
		double getLInf() {return LInf;};
		double getRate() {return Rate;};
		double getGain() {return Gain;};
		double getTra() {return Tra;};
		double getReturns() {return Returns;};
	};
}
