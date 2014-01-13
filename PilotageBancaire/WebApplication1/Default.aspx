<%@ Page Title="Page d'accueil" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true"
    CodeBehind="Default.aspx.cs" Inherits="WebApplication1._Default" %>

<asp:Content ID="HeaderContent" runat="server" ContentPlaceHolderID="HeadContent">
</asp:Content>
<asp:Content ID="BodyContent" runat="server" ContentPlaceHolderID="MainContent">
    <h2>
        Simulation d'un Emprunt financant l'éco-citoyenneté
    </h2>
    <p>
        Etablissement d'un nouveau prêt
    </p>
    <p>
        <asp:Label id="label1" text="Valeur empruntée" runat="server"/>
        <asp:TextBox id="Ve" runat="server"/>
    </p>
    <p>
        <asp:Label id="label2" text="Remboursement maximum" runat="server"/>
        <asp:TextBox id="Rmax" runat="server"/>
    </p>
     <p>
        <asp:Label id="label5" text="Volume économisé" runat="server"/>
        <asp:TextBox id="Véco" runat="server"/>
    </p>
    <p>
        <asp:Label id="label6" text="Prix du fuel" runat="server"/>
        <asp:TextBox id="Pfuel" runat="server"/>
    </p>
    <p>
    <asp:Button id="gebtn1" text="Calcul" OnClick='start' runat="server"/>
    </p>
     <p>
        <asp:Label id="label3" text="Maturité" runat="server"/>
        <asp:TextBox id="Mat" runat="server"/>
    </p>
    <p>
        <asp:Label id="label4" text="Remboursement minimum" runat="server"/>
        <asp:TextBox id="Rmin" runat="server"/>
    </p>
</asp:Content>
