<%@ page contentType="text/plain;charset=UTF-8" language="java" %>
<%@ page import="java.util.Date" %>
<%@ page import="java.text.SimpleDateFormat" %>

<%
    Date date = new Date();
    SimpleDateFormat formatter = new SimpleDateFormat("dd MMMMM yyyy : hh:mm:ss Z");
    String strDate= formatter.format(date);
    out.print(request.getRemoteAddr() + " -> [" +strDate+ "]");
%>