#ifndef _PERSONNE_H_
#define _PERSONNE_H_



#include <iostream>
#include <string>
using namespace std;



class Personne {
private :
	string m_nom;
	string m_adresse;

public:
	Personne(string nom = "Henri Dupont", string adresse = "10 Rue de la Paix, 75002 Paris");
	string getNom();
	string getAdresse();
	void setNom(string nNom);
	void setAdresse(string nAdresse);
	void afficher();
};



#endif _PERSONNE_H_