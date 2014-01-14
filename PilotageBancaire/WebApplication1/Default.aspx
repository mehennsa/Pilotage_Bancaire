<%@ Page Title="Page d'accueil" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true"
    CodeBehind="Default.aspx.cs" Inherits="WebApplication1._Default" %>

<%@ Register Assembly="System.Web.DataVisualization, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35"
    Namespace="System.Web.UI.DataVisualization.Charting" TagPrefix="asp" %>

<asp:Content ID="HeaderContent" runat="server" ContentPlaceHolderID="HeadContent">
</asp:Content>
<asp:Content ID="BodyContent" runat="server" ContentPlaceHolderID="MainContent">
    <h2>
        Simulation d'un Emprunt financant l'éco-citoyenneté
    </h2>
    <h3>
        Etablissement d'un nouveau prêt
    </h3>
    <div id="parameter">
        <p class="parameters">
            Valeur empruntée
            <asp:TextBox ID="Ve" runat="server" Width="50" />
        </p>
        <p class="parameters">
            Remboursement maximum
            <asp:TextBox ID="Rmax" runat="server" Width="50" />
        </p>
        <p class="parameters">
            Volume économisé
            <asp:TextBox ID="Véco" runat="server" Width="50" />
        </p>
        <p class="parameters">
            Prix du fuel
            <asp:TextBox ID="Pfuel" runat="server" Width="50" />
        </p>
        <p class="parameters">
            Maturité supplémentaire
            <asp:TextBox ID="MaturityAdded" runat="server" Width="50" />
        </p>
    </div>
        <asp:Chart ID="Chart1" runat="server" Height="165px"
        Width="474px">
            <Series>
                <asp:Series Name="Series1" ChartType="Spline">
                </asp:Series>
            </Series>
            <ChartAreas>
                <asp:ChartArea Name="ChartArea1">
                    <AxisY Title="Montant">
                    </AxisY>
                    <AxisX Title="Mois">
                        <MajorGrid Enabled="False" />
                    </AxisX>
                </asp:ChartArea>
            </ChartAreas>
        </asp:Chart>
    <div id="result" align="center">
        <p>
            <asp:Button ID="gebtn1" Text="Calcul" OnClick='start' runat="server" />
        </p>
               <div id="loop2"></div>

               <div style="text-align:right;width:50%;font-size:1.4em;margin-top:10px;float:left;">Maturité:&nbsp 
            </div> 
            <div id="tracking_error" style="text-align:left;float:left;width:50%;font-size:1.4em;font-weight:bold;margin-top:10px;">0</div>   
            <div style="text-align:right;width:50%;font-size:1.4em;margin-top:10px;float:left;">Remboursement minimum:&nbsp 
            </div>        
            <div id="ratio_label" style="text-align:left;float:left;width:50%;font-size:1.4em;font-weight:bold;margin-top:10px;">0</div>
    </div>

    <script type="text/javascript">
            function myLoop_tracking(nbr) {
                setTimeout(function () {

                    if (parseFloat(document.getElementById("tracking_error").innerHTML) > nbr - 1) {
                        var i = parseFloat(document.getElementById("tracking_error").innerHTML) + 0.05;
                    } else {
                        var i = parseFloat(document.getElementById("tracking_error").innerHTML) + 0.2;
                    }
                    //alert(nbr);
                    document.getElementById("tracking_error").innerHTML = i.toFixed(2);
                    if (i < nbr) {
                        myLoop_tracking(nbr);
                    } else {
                        document.getElementById("tracking_error").style.color = "#00FF00";
                    }
                }, 50)
        }

        function myLoop_ratio(nbr) {
            setTimeout(function () {

                if (parseFloat(document.getElementById("ratio_label").innerHTML) > nbr - 1) {
                    var i = parseFloat(document.getElementById("ratio_label").innerHTML) + 0.01;
                } else {
                    var i = parseFloat(document.getElementById("ratio_label").innerHTML) + 0.5;
                }
                //alert(nbr);
                document.getElementById("ratio_label").innerHTML = i.toFixed(2);
                if (i < nbr) {
                    myLoop_ratio(nbr);
                } else {
                    document.getElementById("ratio_label").style.color = "#00FF00";
                }
            }, 5)
        }
    </script>
</asp:Content>
