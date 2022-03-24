#ifndef __Match_H__
#define __Match_H__
#include "Spectacle.h"
#include <iostream>
using namespace std;

class Match : public Spectacle {
public:
	Match();
	Match(string equipe1, string equipe2, string sport, string nomTournoi);
	Match(const Match& spec);
	~Match();

	string equipe1();
	string equipe2();
	string sport();
	string typeCompetition();
	string type();
	void synthese();
	void ajoutDate(string nom, string date);

private:
	string m_equipe1;
	string m_equipe2;
	string m_sport;
	string m_nomTournoi;
};

#endif __Match_H__