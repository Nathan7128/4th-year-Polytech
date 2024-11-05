#ifndef _PERMANENT_H_
#define _PERMANENT_H_



#include "enseignant.h"



class Permanent : public Enseignant {
private:
	float m_salaireMensuel;
	float m_montantHeuresSup;
	float m_primes;
public:
	Permanent(string nom = "Henri Dupont", string adresse = "10 Rue de la Paix, 75002 Paris", string numeroBureau = "0",
		int numCasier = 0, float salaireMensuel = 0, float montantHeuresSup = 0, float primes = 0);
	float getSalaireMensuel();
	void setSalaireMensuel(float nSalaire);
	float getMontantHeuresSup();
	void setMontantHeuresSup(float nMontantHeuresSup);
	float getPrimes();
	void setPrimes(float nPrimes);
	float calculerSalaire();
	void afficher();
};



#endif _PERMANENT_H_