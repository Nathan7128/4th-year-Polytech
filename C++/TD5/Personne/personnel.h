#ifndef _PERSONNEL_H_
#define _PERSONNEL_H_



#include "personne.h"



class Personnel : public Personne {
private :
	string m_numeroBureau;
public :
	Personnel(string nom = "Henri Dupont", string adresse = "10 Rue de la Paix, 75002 Paris", string numeroBureau = "0");
	string getNumeroBureau();
	void setNumeroBureau(string nBureau);
	virtual float calculerSalaire() = 0;
};



#endif _PERSONNEL_H_