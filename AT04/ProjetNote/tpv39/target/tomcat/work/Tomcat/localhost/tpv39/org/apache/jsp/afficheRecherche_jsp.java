/*
 * Generated by the Jasper component of Apache Tomcat
 * Version: Apache Tomcat/7.0.47
 * Generated at: 2022-03-30 10:09:32 UTC
 * Note: The last modified time of this file was set to
 *       the last modified time of the source file after
 *       generation to assist with modification tracking.
 */
package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import commerce.catalogue.service.CatalogueManager;
import commerce.catalogue.domaine.modele.Article;
import commerce.catalogue.domaine.modele.Livre;
import commerce.catalogue.domaine.modele.Musique;
import commerce.catalogue.domaine.modele.Piste;
import java.util.Iterator;
import java.util.List;

public final class afficheRecherche_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent {

  private static final javax.servlet.jsp.JspFactory _jspxFactory =
          javax.servlet.jsp.JspFactory.getDefaultFactory();

  private static java.util.Map<java.lang.String,java.lang.Long> _jspx_dependants;

  static {
    _jspx_dependants = new java.util.HashMap<java.lang.String,java.lang.Long>(2);
    _jspx_dependants.put("/piedDePage.html", Long.valueOf(1648634967626L));
    _jspx_dependants.put("/enTetePage.html", Long.valueOf(1648634967605L));
  }

  private javax.el.ExpressionFactory _el_expressionfactory;
  private org.apache.tomcat.InstanceManager _jsp_instancemanager;

  public java.util.Map<java.lang.String,java.lang.Long> getDependants() {
    return _jspx_dependants;
  }

  public void _jspInit() {
    _el_expressionfactory = _jspxFactory.getJspApplicationContext(getServletConfig().getServletContext()).getExpressionFactory();
    _jsp_instancemanager = org.apache.jasper.runtime.InstanceManagerFactory.getInstanceManager(getServletConfig());
  }

  public void _jspDestroy() {
  }

  public void _jspService(final javax.servlet.http.HttpServletRequest request, final javax.servlet.http.HttpServletResponse response)
        throws java.io.IOException, javax.servlet.ServletException {

    final javax.servlet.jsp.PageContext pageContext;
    javax.servlet.http.HttpSession session = null;
    final javax.servlet.ServletContext application;
    final javax.servlet.ServletConfig config;
    javax.servlet.jsp.JspWriter out = null;
    final java.lang.Object page = this;
    javax.servlet.jsp.JspWriter _jspx_out = null;
    javax.servlet.jsp.PageContext _jspx_page_context = null;


    try {
      response.setContentType("text/html;charset=UTF-8");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;

      out.write('\r');
      out.write('\n');
      out.write("<!DOCTYPE html>\r\n");
      out.write("<html>\r\n");
      out.write("<head>\r\n");
      out.write("<title>Site web marchand</title>\r\n");
      out.write("<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\" />\r\n");
      out.write("<link rel=\"stylesheet\" id=\"storefront-style-css\" href=\"./css/themes/storefront/style.css\" type=\"text/css\" />\r\n");
      out.write("<link rel=\"stylesheet\" id=\"storefront-woocommerce-style-css\" href=\"./css/themes/storefront/assets/css/woocommerce/woocommerce.css\" type=\"text/css\" />\r\n");
      out.write("<link rel=\"stylesheet\" id=\"storefront-icons-css\" href=\"./css/themes/storefront/assets/css/base/icons.css\" type=\"text/css\" />\r\n");
      out.write("<link rel=\"stylesheet\" href=\"./js/jplayer-2.9.2/skin/blue.monday/css/jplayer.blue.monday.css\" type=\"text/css\" />\r\n");
      out.write("<style id=\"storefront-style-inline-css\" type=\"text/css\">\r\n");
      out.write("button.menu-toggle,\r\n");
      out.write("button.menu-toggle:hover,\r\n");
      out.write(".handheld-navigation .dropdown-toggle {\r\n");
      out.write("\tcolor: #333333;\r\n");
      out.write("}\r\n");
      out.write("\r\n");
      out.write("button.menu-toggle,\r\n");
      out.write("button.menu-toggle:hover {\r\n");
      out.write("\tborder-color: #333333;\r\n");
      out.write("}\r\n");
      out.write("\r\n");
      out.write("button.menu-toggle,\r\n");
      out.write("button.menu-toggle:hover {\r\n");
      out.write("\tbackground-color: #ffffff;\r\n");
      out.write("}\r\n");
      out.write("\r\n");
      out.write("button.menu-toggle:after,\r\n");
      out.write("button.menu-toggle:before,\r\n");
      out.write("button.menu-toggle span:before {\r\n");
      out.write("\tbackground-color: #333333;\r\n");
      out.write("}\r\n");
      out.write("\r\n");
      out.write("table.cart td.product-remove,\r\n");
      out.write("table.cart td.actions {\r\n");
      out.write("\tborder-top-color: #ffffff;\r\n");
      out.write("}\r\n");
      out.write("</style>\r\n");
      out.write("<style id=\"admin-style-css\" type=\"text/css\">\r\n");
      out.write("div#form label {\r\n");
      out.write("\tmargin-top:20px;\r\n");
      out.write("\tdisplay:block;\r\n");
      out.write("}\r\n");
      out.write("div#form input {\r\n");
      out.write("   width: 100%;\r\n");
      out.write("}\r\n");
      out.write("</style>\r\n");
      out.write("<script type=\"text/javascript\" src=\"./js/themes/storefront/assets/js/navigation.min.js\"></script>\r\n");
      out.write("<script type=\"text/javascript\" src=\"./js/jquery-1.11.1.min.js\"></script>\r\n");
      out.write("<script type=\"text/javascript\" src=\"./js/jplayer-2.9.2/jplayer/jquery.jplayer.min.js\"></script>\r\n");
      out.write("<script type=\"text/javascript\" src=\"./js/jplayer-2.9.2/add-on/jplayer.playlist.min.js\"></script>\r\n");
      out.write("</head>\r\n");
      out.write("<body>\r\n");
      out.write("\t<div id=\"wrapper\">\r\n");
      out.write("\t\t<div id=\"inner-wrapper\">");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");

    if (session.getAttribute("panier") == null) {
        response.sendRedirect("./index.jsp");
    } else {
        CatalogueManager catalogueManager = (CatalogueManager) application
                .getAttribute("catalogueManager");
        List<Article> articles = catalogueManager.getArticles();
        Iterator<Article> listeDesArticles;
        Livre livre = null;
        Musique musique = null;
        Article article;

      out.write("\r\n");
      out.write("<header id=\"header\" class=\"col-full\">\r\n");
      out.write("    <div id=\"logo\">\r\n");
      out.write("        <h1 class=\"site-title\">Amazon du pauvre</h1>\r\n");
      out.write("    </div>\r\n");
      out.write("    <nav id=\"site-navigation\" class=\"main-navigation\" role=\"navigation\">\r\n");
      out.write("        <button class=\"menu-toggle\" aria-controls=\"site-navigation\" aria-expanded=\"false\">\r\n");
      out.write("            <span>Menu</span>\r\n");
      out.write("        </button>\r\n");
      out.write("        <div class=\"menu\">\r\n");
      out.write("            <ul id=\"nav-menu\">\r\n");
      out.write("                <li class=\"page_item page-item-1 current_page_item focus\">\r\n");
      out.write("                    <a href=\"");
      out.print(response.encodeURL("./afficheRecherche.jsp"));
      out.write("\">Rechercher\r\n");
      out.write("                        un article</a>\r\n");
      out.write("                </li>\r\n");
      out.write("                <li class=\"page_item page-item-2\">\r\n");
      out.write("                    <a href=\"");
      out.print(response.encodeURL("./controlePanier.jsp"));
      out.write("\">Panier</a>\r\n");
      out.write("                </li>\r\n");
      out.write("            </ul>\r\n");
      out.write("        </div>\r\n");
      out.write("    </nav>\r\n");
      out.write("</header>\r\n");
      out.write("<script>\r\n");
      out.write("    ");

    if(request.getParameter("affichePopup") != null) {
        
      out.write("\r\n");
      out.write("    language = \"javascript\";\r\n");
      out.write("    alert(\"Un article a été ajouté à votre panier\");\r\n");
      out.write("    ");

    }
    
      out.write("\r\n");
      out.write("</script>\r\n");
      out.write("<div id=\"content\" class=\"site-content\" tabindex=\"-1\">\r\n");
      out.write("    <div class=\"col-full\">\r\n");
      out.write("        <div id=\"primary\" class=\"content-area\">\r\n");
      out.write("            <main id=\"main\" class=\"site-main\" role=\"main\">\r\n");
      out.write("                <header class=\"woocommerce-products-header\">\r\n");
      out.write("                    <h1 class=\"woocommerce-products-header__title page-title\">Les différents articles : </h1>\r\n");
      out.write("                </header>\r\n");
      out.write("                <ul class=\"products columns-3\">\r\n");
      out.write("                    ");

                        listeDesArticles = articles.iterator();
                        int index = 0;
                        while (listeDesArticles.hasNext()) {
                            article = (Article) listeDesArticles.next();
                            if ((index % 3) == 0) {
                    
      out.write("\r\n");
      out.write("                    <li\r\n");
      out.write("\r\n");
      out.write("                            class\r\n");
      out.write("\r\n");
      out.write("                                    =\"product type-product first\">\r\n");
      out.write("                            ");

                        } else {
                        
      out.write("\r\n");
      out.write("                    <li\r\n");
      out.write("\r\n");
      out.write("                            class\r\n");
      out.write("\r\n");
      out.write("                                    =\"product type-product\">\r\n");
      out.write("                        ");

                            }
                            index++;
                        
      out.write("\r\n");
      out.write("                        <a\r\n");
      out.write("                                href=\"");
      out.print(response.encodeURL("./controlePanier.jsp?refArticle="
                            + article.getRefArticle()
                            + "&amp;commande=ajouterLigne"));
      out.write("\"> <img\r\n");
      out.write("                                src=\"");
 if (article.getImage().startsWith("http"))
                        out.print(article.getImage());
                    else
                        out.print("./images/" + article.getImage()); 
      out.write("\"\r\n");
      out.write("\r\n");
      out.write("                                class\r\n");
      out.write("\r\n");
      out.write("                                        =\"attachment-shop_catalog wp-post-image\"\r\n");
      out.write("                                alt=\"poster_2_up\"\r\n");
      out.write("                                height=\"300\"/>\r\n");
      out.write("                            <h3>");
      out.print(article.getTitre());
      out.write("\r\n");
      out.write("                            </h3> <span class=\"price\"><ins>\r\n");
      out.write("    <span class=\"amount\">");
      out.print(article.getPrix());
      out.write(" €</span>\r\n");
      out.write("    </ins></span>\r\n");
      out.write("\r\n");
      out.write("                        </a>\r\n");
      out.write("                        <a href=\"");
      out.print(response.encodeURL("./controlePanier.jsp?refArticle="
                            + article.getRefArticle()
                            + "&amp;commande=ajouterLigne"));
      out.write("\"\r\n");
      out.write("                           class=\"button add_to_cart_button product_type_simple\">Ajouter</a>\r\n");
      out.write("                        ");

                            if (article instanceof Musique) {
                                musique = (Musique) article;
                                if (musique.getPistes().size() > 0) {
                        
      out.write("\r\n");
      out.write("                        <div id=\"jquery_jplayer_");
      out.print(article.getRefArticle());
      out.write("\" class=\"jp-jplayer\"></div>\r\n");
      out.write("                        <div id=\"jp_container_");
      out.print(article.getRefArticle());
      out.write("\" class=\"jp-audio\" role=\"application\">\r\n");
      out.write("                            <div class=\"jp-type-playlist\">\r\n");
      out.write("                                <div class=\"jp-gui jp-interface\">\r\n");
      out.write("                                    <div class=\"jp-controls-holder\">\r\n");
      out.write("                                        <div class=\"jp-controls\">\r\n");
      out.write("                                            <button class=\"jp-previous\" role=\"button\" tabindex=\"0\">previous</button>\r\n");
      out.write("                                            <button class=\"jp-play\" role=\"button\" tabindex=\"0\">play</button>\r\n");
      out.write("                                            <button class=\"jp-stop\" role=\"button\" tabindex=\"0\">stop</button>\r\n");
      out.write("                                            <button class=\"jp-next\" role=\"button\" tabindex=\"0\">next</button>\r\n");
      out.write("                                        </div>\r\n");
      out.write("                                    </div>\r\n");
      out.write("                                </div>\r\n");
      out.write("                                <div class=\"jp-playlist\">\r\n");
      out.write("                                    <ul>\r\n");
      out.write("                                        <li>&nbsp;</li>\r\n");
      out.write("                                    </ul>\r\n");
      out.write("                                </div>\r\n");
      out.write("                                <div class=\"jp-no-solution\">\r\n");
      out.write("                                    <span>Update Required</span> To play the media you will need to\r\n");
      out.write("                                    either update your browser to a recent version or update your <a\r\n");
      out.write("                                        href=\"http://get.adobe.com/flashplayer/\" target=\"_blank\">Flash\r\n");
      out.write("                                    plugin</a>.\r\n");
      out.write("                                </div>\r\n");
      out.write("                            </div>\r\n");
      out.write("                        </div>\r\n");
      out.write("                        ");

                                } // if
                            } // if
                        
      out.write("\r\n");
      out.write("                    </li>\r\n");
      out.write("                    ");

                        } // while
                    
      out.write("\r\n");
      out.write("                </ul>\r\n");
      out.write("            </main>\r\n");
      out.write("        </div>\r\n");
      out.write("    </div><!-- .col-full -->\r\n");
      out.write("</div>\r\n");
      out.write("<!-- #content -->\r\n");
      out.write("<script type=\"text/javascript\">\r\n");
      out.write("    window.addEventListener(\"load\", myFunction, false\r\n");
      out.write("    )\r\n");
      out.write("    ;\r\n");
      out.write("\r\n");
      out.write("    function myFunction(event) {\r\n");
      out.write("        ");

                            listeDesArticles = articles.iterator() ;
                            while (listeDesArticles.hasNext()) {
                                article = (Article) listeDesArticles.next();
                                if (article instanceof Musique) {
        
      out.write("\r\n");
      out.write("        var myPlaylist_");
      out.print(article.getRefArticle());
      out.write(" = new jPlayerPlaylist({\r\n");
      out.write("            cssSelectorAncestor: \"#jp_container_");
      out.print(article.getRefArticle());
      out.write("\",\r\n");
      out.write("            jPlayer: \"#jquery_jplayer_");
      out.print(article.getRefArticle());
      out.write("\"\r\n");
      out.write("        }, [");

				musique = (Musique) article;
							if (musique.getPistes().size() > 0) {
								Iterator<Piste> itPistes = musique.getPistes()
										.iterator();
								Piste unePiste;
								while (itPistes.hasNext()) {
									unePiste = itPistes.next();

      out.write("\r\n");
      out.write("            {title: \"");
      out.print(unePiste.getTitre().replace("\"", "\\\"" ));
      out.write("\", mp3: \"");
      out.print(unePiste.getUrl());
      out.write("\"}, ");


								}
							}

      out.write("\r\n");
      out.write("        ], {\r\n");
      out.write("            swfPath: \"/js/jplayer-2.9.2/jplayer\", supplied: \"mp3\", wmode:\r\n");
      out.write("                \"window\", useStateClassSkin: true, autoBlur: false, smoothPlayBar: true,\r\n");
      out.write("            keyEnabled: true\r\n");
      out.write("        });\r\n");
      out.write("        ");


                                }
                            }
        
      out.write("\r\n");
      out.write("        var jp_playlist_tab = document.getElementsByClassName(\"jp-playlist\");\r\n");
      out.write("        for (i = 0; i < jp_playlist_tab.length; i++) {\r\n");
      out.write("            jp_playlist_tab[i].style.display = \"none\";\r\n");
      out.write("        }\r\n");
      out.write("    }\r\n");
      out.write("</script>\r\n");

    }

      out.write('\r');
      out.write('\n');
      out.write("\t\t\t<footer id=\"footer\" class=\"col-full\">\r\n");
      out.write("\t\t\t\t<div id=\"credit\" class=\"col-right\">\r\n");
      out.write("\t\t\t\t\t<p>\r\n");
      out.write("\t\t\t\t\t\t<object type=\"image/svg+xml\" data=\"./images/deezer.svg\" width=\"152\" height=\"34\"></object>\r\n");
      out.write("\t\t\t\t\t</p>\r\n");
      out.write("\t\t\t\t\t<p>\r\n");
      out.write("\t\t\t\t\t\tDesigned by\r\n");
      out.write("\t\t\t\t\t\t<a title=\"Premium WordPress Themes & Plugins by WooThemes\" alt=\"Premium WordPress Themes & Plugins by WooThemes\" href=\"http://www.woothemes.com/\">\r\n");
      out.write("\t\t\t\t\t\t\t<img width=\"74\" height=\"19\" alt=\"WooThemes\" src=\"./images/woothemes.png\">\r\n");
      out.write("\t\t\t\t\t\t</a>\r\n");
      out.write("\t\t\t\t\t</p>\r\n");
      out.write("\t\t\t\t</div>\r\n");
      out.write("\t\t\t</footer>\r\n");
      out.write("\t\t</div>\r\n");
      out.write("\t</div>\r\n");
      out.write("</body>\r\n");
      out.write("</html>");
    } catch (java.lang.Throwable t) {
      if (!(t instanceof javax.servlet.jsp.SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          try { out.clearBuffer(); } catch (java.io.IOException e) {}
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
        else throw new ServletException(t);
      }
    } finally {
      _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}
