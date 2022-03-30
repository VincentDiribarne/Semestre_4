#ifndef __Spectacle_H__
#define __Spectacle_H__
#include <iostream>
using namespace std;
 
struct Date {
	string nom;
	string date;

	Date() {

	}

	Date(string nom, string date) {
		this->nom = nom;
		this->date = date;
	}
};

class Spectacle {
public:
	Spectacle();
	Spectacle(string nom);
	Spectacle(const Spectacle& spec);

	int& tarif();
	void ajoutDate(string nom, string date);
	string nom();
	string lieu(string date);
	virtual string type() = 0;
	int nbDate();
	virtual void synthese();
	~Spectacle();

protected:
	string s_nom = "Indefinie";
	int s_tarif = 0;
	string s_type = "Indefinie";
	int s_nbDate = 0;
	string s_lieu = "Indefinie";
	Date s_dates[100];
};

#endif __Spectacle_H_
