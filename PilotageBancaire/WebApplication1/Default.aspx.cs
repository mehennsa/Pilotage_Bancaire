using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using Wrapper;

namespace WebApplication1
{
    public partial class _Default : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {


        }

        public void start(object sender, EventArgs e)
        {
            // Récupérer les valeurs des paramètres dans les différentes TextBox
            //WrapperClass wc = new WrapperClass();
            //double ValEmp = double.Parse(Ve.Text);
            //double RembMax = double.Parse(Rmax.Text);
            //double S0 = double.Parse(Pfuel.Text);
            //double rate = 0.02;
            //double sigma = 0.24;
            //double nbLitres = double.Parse(Véco.Text);
            //int M = 10000;
            //wc.getBounds(S0,sigma,rate,RembMax,nbLitres,ValEmp,M);
            //maturity.Text = wc.getEspT().ToString();
            //minrate.Text = wc.getLInf().ToString();



            WrapperClass wc = new WrapperClass();
            double S0 = 0.9;
            double rate = 0.04;
            double sigma = 0.1;
            double valeurLoan = 21500;
            double nbLitres = 200;
            double LSup = 500;
            double addedMaturity = 2;
            int M = 10000;

            wc.getBounds(S0, sigma, rate, LSup, nbLitres, valeurLoan, M);
            double T = wc.getEspT();
            double LInf = wc.getLInf();
            //maturity.Text = T.ToString();
            //minrate.Text = LInf.ToString();
            double[] coeff = new double[(int)T * 12];
            double[] xvalues = new double[(int)T * 12];
            for(int i=0; i<xvalues.Length; i++){
                xvalues[i] = i+1;
            }
            wc.getTaux(S0, sigma, rate, LSup, LInf, nbLitres, valeurLoan, T, M, coeff, addedMaturity);

          //  double value = wc.getReturns() - valeurLoan;
            double equityReturns = valeurLoan * 0.08 * 0.1 * T + valeurLoan * 0.08;

            Chart1.Series["Series1"].Points.DataBindXY(xvalues, coeff);
            Chart1.ChartAreas["ChartArea1"].AxisY.IsStartedFromZero = false;

            string nbr = Math.Round(T, 2).ToString();
            string nbr2 = Math.Round(LInf, 2).ToString();
            nbr = nbr.Replace(',', '.');
            nbr2 = nbr2.Replace(',', '.');
            string script = "<script type=\"text/javascript\">myLoop_tracking(" + nbr + ");</script>";
            ClientScript.RegisterStartupScript(typeof(Page), "script", script);
            string script2 = "<script type=\"text/javascript\">myLoop_ratio(" + nbr2 + ");</script>";
            ClientScript.RegisterStartupScript(typeof(Page), "script2", script2);
        }
    }
}
