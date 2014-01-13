using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Wrapper;

namespace ConsoleApplication1
{
    public class Program
    {
        static void Main(string[] args)
        {
            //basé sur le http://michel.mugnier.pagesperso-orange.fr/Pourquoi_isole.htm

            WrapperClass wc = new WrapperClass();
            double S0 = 0.9;
            double rate = 0.02;
            double sigma = 0.24;
            double valeurLoan = 21500;
            double nbLitres = 163;
            double LSup = 120;
            int M = 10000;

            wc.getBounds(S0, sigma, rate, LSup, nbLitres, valeurLoan, M);
            double T = wc.getEspT();
            double LInf = wc.getLInf();
            Console.WriteLine("T : " + T);
            Console.WriteLine("LInf : " + LInf);

            double[] refundArray = new double[(int)T*12];

            wc.getTaux(S0, sigma, rate, LSup, LInf, nbLitres, valeurLoan, T, M, refundArray);
            double taux = wc.getRate();
            Console.WriteLine("Taux : " + taux);

            for (int i = 0; i < (int)T * 12; i++)
            {
                Console.Write(" " + refundArray[i]);
            }
            Console.ReadKey();
        }
    }
}
