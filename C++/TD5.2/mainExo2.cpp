#include "Matrice.h"
#include <iostream>
#include "MatriceC.h"
//#include "Vecteur.h"

int main() {

	std::cout << "***********Ensemble d'instructions A****************" << std::endl;
	int tab1[16] = { 1, 5, 7, 8, 9, 4, 7, 5, 8, 4, 6, 2, 7, 8, 9, 1 };
	MatriceC mc1(4, tab1);
	int tab2[9] = { 1, 4, 7, 6, 9, 8, 5, 7, 2 };
	MatriceC mc2(3, tab2);
	MatriceC mc3;
	MatriceC mc4(mc1);
	std::cout << mc1 << std::endl;
	std::cout << mc2 << std::endl;
	std::cout << mc3 << std::endl;
	std::cout << mc4 << std::endl;
	std::cout << "Value :" << mc1[2][3] << std::endl;
	std::cout << "Egalite :" << (mc4 == mc1) << std::endl;
	//mc4[3][3] = 12;
	//std::cout << "Different :" << (mc4 != mc1) << std::endl;

	/*
	std::cout << "***********Ensemble d'instructions B****************" << std::endl;
	mc3 = mc1;
	mc3 = mc3 * mc2[1][1];
	std::cout << mc3 << std::endl;
	mc4 = mc1 + mc3;
	std::cout << mc4 << std::endl;
	mc4 = mc3 - mc1;
	std::cout << mc4 << std::endl;
	mc4 = mc3* mc1;
	std::cout << mc4 << std::endl;
	*/

	/*
	std::cout << "***********Ensemble d'instructions C****************" << std::endl;
	int tab3[10] = { 7, 8, 4, 12, 5, 7, 8, 8, 45, 112 };
	Vecteur v1(10, tab3);
	int tab4[5] = { 7, 4, 6, 2, 10 };
	Vecteur v2(5, tab4);
	Vecteur v3;
	Vecteur v4(10);
	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
	std::cout << v3 << std::endl;
	std::cout << v4 << std::endl;
	std::cout << std::endl;
	*/

	/*
	std::cout << "***********Ensemble d'instructions D****************" << std::endl;
	std::cout << "Value :" << v2[2] << std::endl;
	v2[4] = 7;
	std::cout << v2 << std::endl;
	std::cout << "Nb Value: " << v1.getNbValue() << std::endl;
	std::cout << std::endl;
	*/

	/*
	std::cout << "***********Ensemble d'instructions E****************" << std::endl;
	v3 = v1;
	std::cout << v3 << std::endl;
	std::cout << "Egalite: " << (v1 == v3) << std::endl;
	v3[2] = 10;
	std::cout << v3 << std::endl;
	std::cout << "Different: " << (v3 != v1) << std::endl;
	std::cout << "Egalite: " << (v1 == v2) << std::endl;
	std::cout << "Different: " << (v2 != v1) << std::endl;
	std::cout << std::endl;
	*/

	/*
	std::cout << "***********Ensemble d'instructions F****************" << std::endl;
	v3 = v3 * 2;
	std::cout << v3 << std::endl;
	v4 = v1 + v3;
	std::cout << v4 << std::endl;
	v4 = v3 - v1;
	std::cout << v4 << std::endl;
	std::cout << v1* v4 << std::endl;
	*/

	return 0;
}