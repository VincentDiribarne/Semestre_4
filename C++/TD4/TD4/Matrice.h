#ifndef __Matrice_H__
#define __Matrice_H__
#include <iostream>

class Matrice {
	public:
		Matrice();
		Matrice(const Matrice& mat);
		Matrice(const int &nb_ligne, const int &nb_colonne,const int tab[]);
		Matrice(const int &nb_ligne, const int &nb_colonne);

		void affiche();
		const int& getValue(const int& ligne, const int& colonne);
		void setValue(const int& ligne, const int& colonne, const int& value);
		const int& getNbColonne() const;
		const int& getNbLigne() const;
		void affectation(const Matrice& mat);
		bool egal(const Matrice& mat) const;
		int& value(const int& ligne, const int& colonne);
		bool different(const Matrice& mat) const;
		void multiplication(const int& facteur);
		void addition(const Matrice& m, const Matrice& m2);
		void soustraction(const Matrice& m, const Matrice& m2);
		void multiplication(const Matrice& m, const Matrice& m2);


		int* operator[](const int& nb) const;
		friend std::ostream& operator<<(std::ostream& os, const Matrice& m);
		bool operator==(const Matrice& mat) const;
		bool operator!=(const Matrice& mat) const;
		Matrice& operator=(const Matrice& mat);
		Matrice operator*(const int& facteur);
		Matrice operator+(const Matrice& m);
		Matrice operator-(const Matrice& m);
		Matrice operator*(const Matrice& m);

		~Matrice();

	protected:
		int** m_mat;
		int m_nbLigne;
		int m_nbColonne;
};
#endif