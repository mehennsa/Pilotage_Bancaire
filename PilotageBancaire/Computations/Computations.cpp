#include "Computations.h"
#include "iostream"
#include "ctime"
#include "pnl/pnl_random.h"
 
using namespace std;

double compute_maturity(double S0, double sigma, double rate, double LSup, 
	double nbLitres, double valeurLoan, PnlRng *rng) {
		double T = 0;
		double drift  = (rate-sigma*sigma/2)*(1/12);
		double refund = 0;
		double s = S0;
		while (refund < valeurLoan) {
			T += 1;
			s = s*exp(drift+sigma*SQR(1/12)*pnl_rng_normal(rng));
			if ( s * nbLitres <= LSup) {
				refund += s*nbLitres;
			} else {
				refund += LSup;
			}
		}

		return T/12 + 1;
}

void Computations::estimateMaturity(double S0, double sigma, double rate, double LSup, 
	  double nbLitres, double valeurLoan, int M, double &EspT, double &LInf) {
	
		double t = 0;
		double sum = 0;
		double var = 0;
		PnlRng *rng = pnl_rng_create(PNL_RNG_MERSENNE);
		pnl_rng_sseed(rng, time(NULL));
		for (int i = 0; i < M; i++) {
			t = compute_maturity(S0, sigma, rate, LSup, nbLitres, valeurLoan, rng);
			sum += t;
			var += t * t;
		}
		 EspT = sum / M;
		 var = var / M - EspT * EspT;
		 double ic = 2.58 * sqrt (var / M); 
		 EspT = ic + EspT;
		 LInf = valeurLoan/(EspT*12);
}


void computeRefund(double S0, double sigma, double rate, double LSup, double LInf, double nbLitres, PnlRng *rng, double T, double &refund, double *refunds, double addedMaturity, double &gain) {
		double drift  = (rate-(double)(sigma*sigma)/2)*(1.0/12.0);
		double s = S0;
		double tmp;
		for (double i=0; i <(T+addedMaturity)*12; ++i) {
			s = s*exp(drift+sigma*SQR(1/12)*pnl_rng_normal(rng));
			tmp = pnl_rng_normal(rng);
			if (i>=T*12){
				if ( s * nbLitres <= LSup && s * nbLitres >= LInf) {
					gain += s*nbLitres;
					refunds[(int)i] += s*nbLitres;
				} else if (s * nbLitres > LSup) {
					gain += LSup;
					refunds[(int)i] += LSup;
				} else {
					gain += LInf;
					refunds[(int)i] += LInf;
				}
			}else{
				if ( s * nbLitres <= LSup && s * nbLitres >= LInf) {
					refund += s*nbLitres;
					refunds[(int)i] += s*nbLitres;
				} else if (s * nbLitres > LSup) {
					refund += LSup;
					refunds[(int)i] += LSup;
				} else {
					refund += LInf;
					refunds[(int)i] += LInf;
				}
			}
		}
}

void estimateRefund(double S0, double sigma, double rate, double LSup, double LInf,
	  double nbLitres, double T, int M, double &EspRefund, double *refunds, double addedMaturity, double &gain, double &returns) {
		returns = 0;
		double t = 0;
		double sum = 0;
		double var = 0;
		PnlRng *rng = pnl_rng_create(PNL_RNG_MERSENNE);
		pnl_rng_sseed(rng, time(NULL));
		double refund;

		for (int i = 0; i < M; i++) {
			refund = 0;
			computeRefund(S0, sigma, rate, LSup, LInf, nbLitres, rng, T, refund, refunds, addedMaturity, gain);
			EspRefund += refund;
		}
		for (int k=0; k<(int)(T+addedMaturity)*12; k++){
			refunds[k]/=M;
			returns += refunds[k]/pow((1+rate*(1.0/12.0)),k);
		}
		gain /= M;
		EspRefund = EspRefund / M;
}


void Computations::estimateRate(double S0, double sigma, double rate, double LSup, double LInf, 
	double nbLitres, double valeurLoan, double T, int M, double &taux, double *refunds, double addedMaturity, double &gain, double &returns, double &tra){

	double EspRefund = 1;
	double returnTRA = 0;
	double tramin = 0;
	double tramax =1.0;
	tra=0.5;
	estimateRefund(S0,sigma,rate,LSup, LInf, nbLitres,T,M,EspRefund,refunds,addedMaturity,gain, returns);
	while(abs(returnTRA-valeurLoan)>10){
		returnTRA = 0;
		for (int k=0; k<(int)(T+addedMaturity)*12; k++){
			returnTRA += refunds[k]/pow((1+tra*(1.0/12.0)),k);
		}
		if (returnTRA-valeurLoan>0){
			tramin = tra;
			tra = (tra+tramax)/2;
		}else{
			tramax = tra;
			tra = (tra+tramin)/2;
		}
	}
	//taux = (EspRefund - valeurLoan)/valeurLoan ;
	taux = (returns - valeurLoan)/valeurLoan ;
}

