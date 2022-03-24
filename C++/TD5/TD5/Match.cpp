#include "Match.h";
using namespace std;

Match::Match() {
	this->m_equipe1 = "Indefinie";
	this->m_equipe2 = "Indefinie";
	this->m_sport = "Indefinie";
	this->m_nomTournoi = "Indefinie";
	this->s_nom = "Indefinie";
	this->s_lieu = "Indefinie";
	this->s_tarif = 0;
	this->s_type = "Match";
	this->s_nbDate = 0;
}

Match::Match(string equipe1, string equipe2, string sport, string nomTournoi) {
	this->m_equipe1 = equipe1;
	this->m_equipe2 = equipe2;
	this->m_sport = sport;
	this->m_nomTournoi = nomTournoi;
	this->s_nom = equipe1 + " VS " + equipe2;
	this->s_lieu = "Indefinie";
	this->s_tarif = 0;
	this->s_type = "Match";
	this->s_nbDate = 0;
}

string Match::equipe1() {
	return this->m_equipe1;
}

string Match::equipe2() {
	return this->m_equipe2;
}

string Match::sport() {
	return this->m_sport;
}

string Match::typeCompetition() {
	return this->m_nomTournoi;
}

string Match:: type() {
	return this->s_type;
}

void Match::ajoutDate(std::string nom, std::string date) {
	if (s_nbDate > 0) {
		cout << "Impossible le match ne peut avoir lieu qu'a une date" << endl;
		return;
	}
	s_dates[s_nbDate].nom = nom;
	s_dates[s_nbDate].date = date;
	++s_nbDate;
}

void Match::synthese() {
	cout << "Sport : " << this->m_sport << ", type du tournoi : " << m_nomTournoi << endl;
	Spectacle::synthese();
}

Match::~Match() {}