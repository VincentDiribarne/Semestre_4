<%@ page pageEncoding="UTF-8" %>
<%
    if (session.getAttribute("panier") == null) {
        response.sendRedirect("./index.jsp");
    } else {
        String commande = request.getParameter("commande");

        if(commande != null) {
            if(commande.equals("effectuerCommander")) {
                response.sendRedirect(response.encodeURL("afficheCommande.jsp"));
            }
        } else {
            response.sendRedirect(response.encodeURL("./afficheRecherche.jsp"));
        }
    }
%>