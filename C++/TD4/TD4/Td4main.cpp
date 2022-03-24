#include <iostream>
#include "MatriceAnto.h"

int main() {
	std::cout << "***********Ensemble d'instructions A****************" << std::endl;
	int tab1[20] = { 1, 4, 7, 8, 5, 2, 9, 6, 3, 1, 4, 7, 8, 5, 2, 9, 6, 3, 1, 4 };
	Matrice m1(4, 5, tab1);
	int tab2[15] = { 5,7,9,6,4,1,8,7,6,4,7,8,4,5,6};
	Matrice m2(5, 3,tab2);
	Matrice m3;
	Matrice m4(4,5);
	m1.affiche();
	m2.affiche();
	m3.affiche();
	m4.affiche();
	std::cout << std::endl;
	

	std::cout << "***********Ensemble d'instructions B****************" << std::endl;
	std::cout << "Value : " << m1.getValue(2, 1) << std::endl;
	m2.setValue(4, 2, 7);
	m2.affiche();
	std::cout << "Nb colonnes : " << m1.getNbColonne() << std::endl;
	std::cout << "Nb lignes : " << m2.getNbLigne() << std::endl;
	std::cout << std::endl;

	std::cout << "***********Ensemble d'instructions C****************" << std::endl;
	m3.affectation(m1);
	m3.affiche();
	std::cout << "Egalite : " << m1.egal(m3) << std::endl;
	m3.value(2, 3) = 10;
	std::cout << "Value : " << m1.value(2, 3) << std::endl;
	m3.affiche();
	std::cout << "Different : " << m3.different(m1) << std::endl;
	std::cout << "Egalite : " << m1.egal(m2) << std::endl;
	std::cout << "Different : " << m2.different(m1) << std::endl;
	std::cout << std::endl;


	std::cout << "***********Ensemble d'instructions D****************" << std::endl;
	m3.affiche();
	m3.multiplication(2);
	m3.affiche();
	m4.addition(m1,m3);
	m4.affiche();
	m4.soustraction(m3, m1);
	m4.affiche();
	m4.multiplication(m1, m2);
	m4.affiche();

	return 0;
}