#ifndef _VACATAIRE_H_
#define _VACATAIRE_H_



#include "enseignant.h"



class Vacataire : public Enseignant {
private:
	float m_tarifHoraire;
	float m_nbHeures;
public:
	Vacataire(string nom = "Henri Dupont", string adresse = "10 Rue de la Paix, 75002 Paris", string numeroBureau = "0",
		int numCasier = 0, float tarifHoraire = 0, float nbHeures = 0);
	float getTarifHoraire();
	void setTarifHoraire(float nTarif);
	float getNbHeures();
	void setNbHeures(float nNbHeures);
	float calculerSalaire();
	void afficher();
};



#endif _VACATAIRE_H_