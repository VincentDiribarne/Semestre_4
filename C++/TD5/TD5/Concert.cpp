#include "Concert.h";
using namespace std;

Concert::Concert() {
	this->c_genre = "Indefinie";
	this->c_nomTournee = "Indefinie";
	this->s_nom = "Indefinie";
	this->s_lieu = "Indefinie";
	this->s_tarif = 0;
	this->s_type = "Concert";
	this->s_nbDate = 0;
}

Concert::Concert(string nom, string genre, string nomTournee) {
	this->c_genre = genre;
	this->c_nomTournee = nomTournee;
	this->s_nom = nom;
	this->s_lieu = "Indefinie";
	this->s_tarif = 0;
	this->s_type = "Concert";
	this->s_nbDate = 0;
}

string Concert::genre() {
	return this->c_genre;
}

string Concert::nomTournee() {
	return this->c_nomTournee;
}

string Concert::type() {
	return this->s_type;
}

void Concert::synthese() {
	cout << "Nom tournee : " << this->c_nomTournee << ", genre : " << c_genre << endl;
	Spectacle::synthese();
}

Concert::~Concert() {}