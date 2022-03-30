
#include "Spectacle.h"
#include <iostream>
using namespace std;

Spectacle::Spectacle() {
	this->s_nom = "Indefinie";
	this->s_lieu = "Indefinie";
	this->s_tarif = 0;
	this->s_type = "Indefinie";
	this->s_nbDate = 0;
}

Spectacle::Spectacle(std::string nom) {
	this->s_nom = nom;
	this->s_lieu = "Indefinie";
	this->s_tarif = 0;
	this->s_type = "Indefinie";
	this->s_nbDate = 0;
}

int& Spectacle::tarif() {
	return this->s_tarif;
}

string Spectacle::nom(){
	return this->s_nom;
}

string Spectacle::lieu(std::string date) {
	for (size_t i = 0; i < s_nbDate; ++i) {
		if (s_dates[i].date == date)
			return s_dates[i].nom;
	}
	return "Il n'y a pas de dates associée";
}

string Spectacle::type() {
	return this->s_type;
}

int Spectacle::nbDate() {
	return this->s_nbDate;
}

void Spectacle::ajoutDate(std::string nom, std::string date) {
	s_dates[s_nbDate].nom = nom;
	s_dates[s_nbDate].date = date;
	++s_nbDate;
}


void Spectacle::synthese() {
	cout << "Nom : " << this->s_nom << ", type : " << this->s_type << ", nbDates : " << this->s_nbDate << endl;
	for (int i = 0; i < s_nbDate; i++) {
		cout << s_dates[i].date << " " << s_dates[i].nom << endl;
	}
}

Spectacle::~Spectacle() {}
