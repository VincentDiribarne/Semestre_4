package commerce.gestion;

import java.util.ArrayList;
import java.util.List;

import commerce.catalogue.domaine.modele.Livre;

public class Panier {
	private double total;
	private ArrayList<LignePanier> lignesPanier;

	public Panier() {
	}
	public void setTotal() {
		recalculer();
	}
	public double getTotal() {
		recalculer();
		return total;
	}
	public List<LignePanier> getLignesPanier() {
		return lignesPanier;
	}
	public void recalculer() {
	}
	public void ajouterLigne(Livre inLivre) {
	}
	public LignePanier chercherLignePanier(Livre inLivre) {
		return null ;
	}
	public void supprimerLigne(String inRefLivre) {
	}
	public void viderPanier() {
	}
	public boolean equals(Object o){
		return true;
	}
}
