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
            WrapperClass wc = new WrapperClass();
            double S0 = 0.5;
            double rate = 0.02;
            double sigma = 0.24;
            double valeurLoan = 10000;
            double nbLitres = 27;
            double LSup = 500;
            int M = 10000;
            wc.getBounds(S0, sigma, rate, LSup, nbLitres, valeurLoan, M);
            double T = wc.getEspT();
            double LInf = wc.getLInf();
            Console.WriteLine("T : " + T);
            Console.WriteLine("LInf : " + LInf);
            Console.ReadKey();
        }
    }
}
