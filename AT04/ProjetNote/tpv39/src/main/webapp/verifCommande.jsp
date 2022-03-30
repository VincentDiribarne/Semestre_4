<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    if (session.getAttribute("panier") == null) {
        response.sendRedirect("./index.jsp");
    } else {
        session.setAttribute("panier", null);
        response.sendRedirect("./afficheRecherche.jsp?message=Commande effectuée");
    }
%>

