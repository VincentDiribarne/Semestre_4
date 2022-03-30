#include "Fraction.h"

Fraction::Fraction(int num, int den) {
	if (den) {
		m_num = num;
		m_den = den;
	}
	else {
		std::cout << "Erreur le denominateur est/deviendra nul" << std::endl;
		m_num = 1;
		m_den = 1;
	}
}

Fraction::Fraction(const Fraction& frac) {
	if (!frac.verifDenominaTeurNonNUl()) {
		m_num = frac.m_num;
		m_den = frac.m_den;
	}
	else {
		m_num = 1;
		m_den = 1;
	}
}

void Fraction::addition(Fraction frac) {
	if (!frac.verifDenominaTeurNonNUl()) {
		m_num = (m_num * frac.m_den) + (frac.m_num * m_den);
		m_den *= frac.m_den;
	}
}

void Fraction::multiplication(int facteur) {
	m_num *= facteur;
}

void Fraction::multiplication(Fraction frac) {
	if (!frac.verifDenominaTeurNonNUl()) {
		m_num *= frac.m_num;
		m_den *= frac.m_den;
	}
}

float Fraction::calculFraction() {
	return (static_cast<float>(m_num) / static_cast<float>(m_den));
}

void Fraction::afficherFraction() {
	std::cout << m_num << "/" << m_den << std::endl;
}

bool Fraction::verifDenominaTeurNonNUl() const {
	if (!m_den) {
		std::cout << "Erreur le denominateur est / deviendra nul" << std::endl;
		return true;
	}
	else {
		return false;
	}
}