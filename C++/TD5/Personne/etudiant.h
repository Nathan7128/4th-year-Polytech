#ifndef _ETUDIANT_H_
#define _ETUDIANT_H_



#include "personne.h"



class Etudiant : public Personne {
private:
	float m_moyenne;
public:
	Etudiant(string nom = "Henri Dupont", string adresse = "10 Rue de la Paix, 75002 Paris", float moyenne = 0);
	float getMoyenne();
	void setMoyenne(float nMoyenne);
	void afficher();
};



#endif _ETUDIANT_H_