using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            double[] xvalues = new double[12];
            for (int i = 0; i < xvalues.Length; i++)
            {
                xvalues[i] = i + 1;
            }
            Chart1.Series["Series1"].Points.DataBindXY(xvalues, xvalues);
        }
    }
}