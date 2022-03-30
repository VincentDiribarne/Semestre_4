#include "MatriceC.h"
#include <iostream>

MatriceC::MatriceC() : Matrice() {
	this->m_nbLigne = 2;
	this->m_nbColonne = m_nbLigne;
	for (unsigned int i = 0; i < m_nbLigne; i++)
		this->m_mat[i] = new int[m_nbColonne];
	this->m_mat[0][0] = 0;
}

MatriceC::MatriceC(const MatriceC& mat) {
	this->m_mat = new int* [this->m_nbLigne];
	this->m_nbColonne = m_nbLigne;
	for (int i = 0; i < this->m_nbLigne; ++i) { this->m_mat[i] = new int[this->m_nbColonne]; }
	for (int i = 0; i < this->m_nbLigne; ++i) {
		for (int j = 0; j < this->m_nbColonne; ++j) {
			this->m_mat[i][j] = mat.m_mat[i][j];
		}
	}
}

MatriceC::MatriceC(const int& nbLigne, const int tab[]) {
	this->m_mat = new int* [nbLigne];
	this->m_nbColonne = m_nbLigne;
	int cpt = 0;
	for (int i = 0; i < nbLigne; ++i) { this->m_mat[i] = new int[m_nbColonne]; }
	for (int i = 0; i < nbLigne; ++i) {
		for (int j = 0; j < m_nbColonne; ++j) {
			this->m_mat[i][j] = tab[cpt++];
		}
	}
}