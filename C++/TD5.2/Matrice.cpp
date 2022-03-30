#include "Matrice.h"
#include "iostream"
Matrice::Matrice() :m_mat(new int* [1]),m_nbLigne(1),m_nbColonne(1) {
	this->m_mat[0] = new int[1];
	this->m_mat[0][0] = 0;
}

Matrice::Matrice(const Matrice &mat): m_nbLigne(mat.m_nbLigne), m_nbColonne(mat.m_nbColonne) {
	this->m_mat = new int* [this->m_nbLigne];
	for (int i = 0; i < this->m_nbLigne; ++i) { this->m_mat[i] = new int[this->m_nbColonne]; }
	for (int i = 0; i < this->m_nbLigne; ++i) {
		for (int j = 0; j < this->m_nbColonne; ++j) {
			this->m_mat[i][j] = mat.m_mat[i][j];
		}
	}
}

Matrice::Matrice(const int &nbLigne, const int &nbColonne):m_nbLigne(nbLigne),m_nbColonne(nbColonne) {
	this->m_mat = new int* [nbLigne];
	for (int i = 0; i < nbLigne; ++i) {this->m_mat[i] = new int[nbColonne];}
	for (int i = 0; i < nbLigne; ++i) {
		for (int j = 0; j < nbColonne; ++j) {
			m_mat[i][j] = 0;
		}
	}

}

Matrice::Matrice(const int &nbLigne, const int &nbColonne, const int tab[]):m_nbLigne(nbLigne), m_nbColonne(nbColonne) {
	this->m_mat = new int* [nbLigne];
	int cpt = 0;
	for (int i = 0; i < nbLigne; ++i) { this->m_mat[i] = new int[nbColonne]; }
	for (int i = 0; i < nbLigne; ++i) {
		for (int j = 0; j < nbColonne; ++j) {
			this->m_mat[i][j] = tab[cpt++];
		}
	}
}

void Matrice::affiche() {
	std::cout << "Matrice:" << std::endl;
	for (int i = 0; i < this->m_nbLigne; ++i) {
		for (int j = 0; j < this->m_nbColonne; ++j) {
			std::cout << this->m_mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

const int& Matrice::getValue(const int& ligne, const int& colonne) {
	return this->m_mat[ligne][colonne];
}

void Matrice::setValue(const int& ligne, const int& colonne, const int& value) {
	this->m_mat[ligne][colonne] = value;
}

const int& Matrice::getNbColonne() const{
	return this->m_nbColonne;
}

const int& Matrice::getNbLigne() const{
	return this->m_nbLigne;
}

void Matrice::affectation(const Matrice& mat) {
	this->m_nbColonne = mat.m_nbColonne;
	this->m_nbLigne = mat.m_nbLigne;
	this->m_mat = new int* [this->m_nbLigne];
	for (int i = 0; i < this->m_nbLigne; ++i) { this->m_mat[i] = new int[this->m_nbColonne]; }
	for (int i = 0; i < this->m_nbLigne; ++i) {
		for (int j = 0; j < this->m_nbColonne; ++j) {
			this->m_mat[i][j] = mat.m_mat[i][j];
		}
	}
}

bool Matrice::egal(const Matrice& mat) const{
	for (int i = 0; i < this->m_nbLigne; ++i) {
		for (int j = 0; j < this->m_nbColonne; ++j){
			if ((this->m_mat[i][j] - mat.m_mat[i][j] != 0) && (mat.m_mat[i][j] - this->m_mat[i][j] != 0)) return false;
		}
	}
	return true;
}

int& Matrice::value(const int& ligne, const int& colonne) {
	return this->m_mat[ligne][colonne];
}

bool Matrice::different(const Matrice& mat) const{
	return !egal(mat);
}

void Matrice::multiplication(const int& facteur) {
	Matrice result = Matrice(this->m_nbLigne, this->m_nbColonne);
	for (int i = 0; i < this->m_nbLigne; ++i) {
		for (int j = 0; j < this->m_nbColonne; ++j) {
			result.setValue(i, j, this->m_mat[i][j] * facteur);
		}
	}
	this->affectation(result);
}

void Matrice::addition(const Matrice& m, const Matrice& m2) {
	Matrice result = Matrice(m.m_nbLigne, m.m_nbColonne);
	for (int i = 0; i < m.m_nbLigne; ++i) {
		for (int j = 0; j < m.m_nbColonne; ++j) {
			result.setValue(i, j, m.m_mat[i][j] + m2.m_mat[i][j]);
		}
	}
	this->affectation(result);
}

void Matrice::soustraction(const Matrice& m, const Matrice& m2) {
	Matrice result = Matrice(m.m_nbLigne, m.m_nbColonne);
	for (int i = 0; i < m.m_nbLigne; ++i) {
		for (int j = 0; j < m.m_nbColonne; ++j) {
			result.setValue(i, j, m.m_mat[i][j] - m2.m_mat[i][j]);
		}
	}
	this->affectation(result);
}

void Matrice::multiplication(const Matrice& m, const Matrice& m2) {
	//First multiple
	Matrice result = Matrice(m.m_nbLigne, m2.m_nbColonne);
	for (int i = 0; i < m.m_nbLigne; ++i) {
		for (int j = 0; j < m2.m_nbColonne; ++j) {
			for (int k = 0; k < m.m_nbColonne; ++k)
			{
				result.m_mat[i][j] += m.m_mat[i][k] * m2.m_mat[k][j];
			}
		}
	}
	this->affectation(result);
}

int* Matrice::operator[](const int& nb) const{
	return this->m_mat[nb];
}

std::ostream& operator<<(std::ostream& os, const Matrice& m) {
	os << "Matrice:" << std::endl;
	for (int i = 0; i < m.getNbLigne(); ++i) {
		for (int j = 0; j < m.getNbColonne(); ++j) {
			os << m[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
}

bool Matrice::operator==(const Matrice& mat) const {
	for (int i = 0; i < this->m_nbLigne; ++i) {
		for (int j = 0; j < this->m_nbColonne; ++j) {
			if ((this->m_mat[i][j] - mat.m_mat[i][j] != 0) && (mat.m_mat[i][j] - this->m_mat[i][j] != 0)) return false;
		}
	}
	return true;
}

bool Matrice::operator!=(const Matrice& mat) const {
	return !egal(mat);
}

Matrice& Matrice::operator=(const Matrice& mat) {
	this->m_nbColonne = mat.m_nbColonne;
	this->m_nbLigne = mat.m_nbLigne;
	this->m_mat = new int* [this->m_nbLigne];
	for (int i = 0; i < this->m_nbLigne; ++i) { this->m_mat[i] = new int[this->m_nbColonne]; }
	for (int i = 0; i < this->m_nbLigne; ++i) {
		for (int j = 0; j < this->m_nbColonne; ++j) {
			this->m_mat[i][j] = mat.m_mat[i][j];
		}
	}
	return *this;
}

Matrice Matrice::operator*(const int& facteur) {
	Matrice result = Matrice(this->m_nbLigne, this->m_nbColonne);
	for (int i = 0; i < this->m_nbLigne; ++i) {
		for (int j = 0; j < this->m_nbColonne; ++j) {
			result.setValue(i, j, this->m_mat[i][j] * facteur);
		}
	}
	return result;
}
Matrice Matrice::operator+(const Matrice& m) {
	Matrice result = Matrice(this->m_nbLigne, this->m_nbColonne);
	for (int i = 0; i < this->m_nbLigne; ++i) {
		for (int j = 0; j < this->m_nbColonne; ++j) {
			result.setValue(i, j, this->m_mat[i][j] + m.m_mat[i][j]);
		}
	}
	return result;
}
Matrice Matrice::operator-(const Matrice& m) {
	Matrice result = Matrice(this->m_nbLigne, this->m_nbColonne);
	for (int i = 0; i < this->m_nbLigne; ++i) {
		for (int j = 0; j < this->m_nbColonne; ++j) {
			result.setValue(i, j, this->m_mat[i][j] - m.m_mat[i][j]);
		}
	}
	return result;
}
Matrice Matrice::operator*(const Matrice& m) {
	//First multiple
	Matrice result = Matrice(this->m_nbLigne, m.m_nbColonne);
	for (int i = 0; i < this->m_nbLigne; ++i) {
		for (int j = 0; j < m.m_nbColonne; ++j) {
			for (int k = 0; k < this->m_nbColonne; ++k)
			{
				result.m_mat[i][j] += this->m_mat[i][k] * m.m_mat[k][j];
			}
		}
	}
	return result;
}

Matrice::~Matrice() {

	for (int i = 0; i < this->m_nbLigne; i++) {
		delete[] m_mat[i];
	}
	delete[] m_mat;
	this->m_mat = NULL;
}

