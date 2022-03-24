#ifndef __MatriceC_H__
#define __MatriceC_H__
#include "Matrice.h"
#include <iostream>

class MatriceC: public Matrice {

public:
	MatriceC();
	MatriceC(const MatriceC& mat);
	MatriceC(const int& nb_ligne, const int tab[]);

};
#endif