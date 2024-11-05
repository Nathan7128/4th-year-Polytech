#ifndef _ADMINISTRATIF_H_
#define _ADMINISTRATIF_H_



#include "personnel.h"



class Administratif : public Personnel {
private:
	float m_salaireMensuel;
	float m_primes;
public:
	Administratif(string nom = "Henri Dupont", string adresse = "10 Rue de la Paix, 75002 Paris", string numeroBureau = "0",
		float salaireMensuel = 0, float primes = 0);
	float getSalaireMensuel();
	void setSalaireMensuel(float nSalaire);
	float getPrimes();
	void setPrimes(float nPrimes);
	float calculerSalaire();
	void afficher();
};



#endif _ADMINISTRATIF_H_