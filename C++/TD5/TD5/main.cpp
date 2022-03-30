
#include <iostream>
#include "Spectacle.h"
#include "Concert.h"
#include "Match.h"
#include "PieceTheatre.h"


void affiche(Spectacle** tab, int nbSpectacle) {
	for (int i = 0; i < nbSpectacle; ++i) {
		if (tab[i]) {
			std::cout << "Spectacle " << i << std::endl;
			tab[i]->synthese();
			std::cout << std::endl;
		}
	}
}


int main() {
	/*std::cout << "***********Ensemble d'instructions A****************" << std::endl;
	Spectacle s("Exposition Marvel");
	s.tarif() = 70;
	s.ajoutDate("Marseille", "10/04/2012");
	s.ajoutDate("Laval", "20/07/2013");

	std::cout << "Nom :" << s.nom() << std::endl;
	std::cout << "Type :" << s.type() << std::endl;
	std::cout << "Lieu pour le 20/07/2013: " << s.lieu("20/07/2013") << std::endl;
	std::cout << "Nombre de dates :" << s.nbDate() << std::endl;
	std::cout << "Tarif :" << s.tarif() << std::endl << std::endl;

	cout << endl;
	std::cout << "Synthese:" << std::endl;
	s.synthese();*/
	

	std::cout << "***********Ensemble d'instructions B****************" << std::endl;
	Concert c("Garbage", "Rock", "Version 2.0 Tour");
	c.tarif() = 40;
	c.ajoutDate("Paris", "12/06/2014");
	c.ajoutDate("Nantes", "24/08/2014");
	c.ajoutDate("Rennes", "02/10/2014");
	c.ajoutDate("Lille", "13/11/2014");

	std::cout << "Nom :" << c.nom() << std::endl;
	std::cout << "Type :" << c.type() << std::endl;
	std::cout << "Lieu :" << c.lieu("02/10/2014") << std::endl;
	std::cout << "Nombre de dates :" << c.nbDate() << std::endl;
	std::cout << "Tarif :" << c.tarif() << std::endl;
	std::cout << "Genre :" << c.genre() << std::endl;
	std::cout << "Nom tournee :" << c.nomTournee() << std::endl << std::endl;

	std::cout << "Synthese:" << std::endl;
	c.synthese();

	
	std::cout << std::endl;
	std::cout << "***********Ensemble d'instructions C****************" << std::endl;
	Match m("France", "Espagne", "Football", "Championnat du monde");
	m.tarif() = 110;
	m.ajoutDate("Paris", "24/04/2017");
	m.ajoutDate("Nantes", "26/08/2017");

	std::cout << "Nom :" << m.nom() << std::endl;
	std::cout << "Type :" << m.type() << std::endl;
	std::cout << "Lieu :" << m.lieu("26/08/2017") << std::endl;
	std::cout << "Nombre de dates :" << m.nbDate() << std::endl;
	std::cout << "Tarif :" << m.tarif() << std::endl;
	std::cout << "Equipe1 :" << m.equipe1() << std::endl;
	std::cout << "Equipe2 :" << m.equipe2() << std::endl;
	std::cout << "Sport :" << m.sport() << std::endl;
	std::cout << "Type de competition :" << m.typeCompetition() << std::endl << std::endl;

	std::cout << "Synthese:" << std::endl;
	m.synthese();

	cout << endl;
	std::cout << "***********Ensemble d'instructions D****************" << std::endl;
	PieceTheatre p("Diner de cons", "Comedie", 120.0f);
	p.tarif() = 60;
	p.ajoutDate("Lille", "20/01/2015");
	p.ajoutDate("Poitier", "27/03/2015");
	p.ajoutDate("Brest", "14/10/2015");
	p.ajoutDate("Nancy", "02/09/2015");
	p.ajoutDate("Paris", "18/10/2015");
	p.ajoutDate("Toulouse", "07/12/2015");

	std::cout << "Nom :" << p.nom() << std::endl;
	std::cout << "Type :" << p.type() << std::endl;
	std::cout << "Lieu :" << p.lieu("07/12/2015") << std::endl;
	std::cout << "Nombre de dates :" << p.nbDate() << std::endl;
	std::cout << "Tarif :" << p.tarif() << std::endl;
	std::cout << "Style :" << p.style() << std::endl;
	std::cout << "Duree :" << p.duree() << std::endl;

	std::cout << std::endl;
	std::cout << "Synthese:" << std::endl;
	p.synthese();

	cout << endl;
	std::cout << "***********Ensemble d'instructions E****************" << std::endl;
	Spectacle* specTab[3];
	specTab[0] = dynamic_cast<Spectacle*>(&c);
	specTab[1] = dynamic_cast<Spectacle*>(&m);
	specTab[2] = dynamic_cast<Spectacle*>(&p);
	affiche(specTab, 3);

	return 0;
}