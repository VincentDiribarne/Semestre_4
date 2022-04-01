<%@ page import="commerce.gestion.Panier" %>
<%@ page contentType="text/html;charset=UTF-8"%>
<%
    Panier panier = (Panier) session.getAttribute("panier");
    panier.supprimerAllLigne();
    session.setAttribute("panier", panier);
    response.sendRedirect(response.encodeURL("./afficheRecherche.jsp?message"));
%>

