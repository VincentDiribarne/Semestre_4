#ifndef __Concert_H__
#define __Concert_H__
#include "Spectacle.h"
#include <iostream>
using namespace std;

class Concert: public Spectacle {
public: 
	Concert();
	Concert(string nom, string genre, string nomTournee);
	Concert(const Concert& spec);
	~Concert();

	string genre();
	string nomTournee();
	string type();
	void synthese();

private:
	string c_genre;
	string c_nomTournee;
};

#endif __Concert_H__
