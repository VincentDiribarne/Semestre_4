#include <iostream>

class Fraction {

public:
	Fraction(int num, int den);
	Fraction(const Fraction& frac);

	void addition(Fraction frac);
	void multiplication(int facteur);
	void multiplication(Fraction frac);
	float calculFraction();
	void afficherFraction();

private:
	bool verifDenominaTeurNonNUl() const;

	int m_num;
	int m_den;

};
