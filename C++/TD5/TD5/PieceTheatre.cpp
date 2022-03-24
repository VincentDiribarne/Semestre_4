#include "PieceTheatre.h";
using namespace std;

PieceTheatre::PieceTheatre() {
	this->p_style = "Indefinie";
	this->p_duree = 0.0f;
	this->s_nom = "Indefinie";
	this->s_lieu = "Indefinie";
	this->s_tarif = 0;
	this->s_type = "Piece de Theatre";
	this->s_nbDate = 0;
}

PieceTheatre::PieceTheatre(string nom, string style, float duree) {
	this->p_style = style;
	this->p_duree = duree;
	this->s_nom = nom;
	this->s_lieu = "Indefinie";
	this->s_tarif = 0;
	this->s_type = "Piece de Theatre";
	this->s_nbDate = 0;
}

string PieceTheatre::style() {
	return this->p_style;
}

float PieceTheatre::duree() {
	return this->p_duree;
}


string PieceTheatre::type() {
	return this->s_type;
}


void PieceTheatre::synthese() {
	cout << "Style : " << this->p_style << ", duree : " << p_duree << endl;
	Spectacle::synthese();
}

PieceTheatre::~PieceTheatre() {}