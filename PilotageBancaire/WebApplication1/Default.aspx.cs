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
            WrapperClass wc = new WrapperClass();
            double ValEmp = double.Parse(Ve.Text);
            double RembMax = double.Parse(Rmax.Text);
            double S0 = double.Parse(Pfuel.Text);
            double rate = 0.02;
            double sigma = 0.24;
            double nbLitres = double.Parse(Véco.Text);
            int M = 10000;
            wc.getBounds(S0,sigma,rate,RembMax,nbLitres,ValEmp,M);
            Mat.Text = wc.getEspT().ToString();
            Rmin.Text = wc.getLInf().ToString();
        }
    }
}
