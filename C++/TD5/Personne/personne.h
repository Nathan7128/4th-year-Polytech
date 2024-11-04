#ifndef _PERSONNE_HPP_
#define _PERSONNE_HPP_



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
	void setNom(string nom);
	void setAdresse(string adresse);
	void afficher();
};



#endif _PERSONNE_HPP_