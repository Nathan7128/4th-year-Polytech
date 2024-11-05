#ifndef _ENSEIGNANT_H_
#define _ENSEIGNANT_H_



#include "personnel.h"



class Enseignant : public Personnel {
private:
	int m_numCasier;
public:
	Enseignant(string nom = "Henri Dupont", string adresse = "10 Rue de la Paix, 75002 Paris", string numeroBureau = "0",
		int numCasier);
	int getNumCasier();
	void setNumCasier(int nCasier);
};



#endif _ENSEIGNANT_H_