#ifndef __PieceTheatre_H__
#define __PieceTheatre_H__
#include "Spectacle.h"
#include <iostream>
using namespace std;

class PieceTheatre : public Spectacle {
public:
	PieceTheatre();
	PieceTheatre(string nom, string style, float duree);
	PieceTheatre(const PieceTheatre& spec);
	~PieceTheatre();

	string style();
	float duree();
	string type();
	void synthese();

private:
	string p_style;
	float p_duree;
};

#endif __PieceTheatre_H__
