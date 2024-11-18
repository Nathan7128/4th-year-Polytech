#ifndef _PLATEAU_H_
#define _PLATEAU_H_



#include <iostream>
#include "ObjetGraphiqueFixe.h"
#include "ObjetGraphiqueMobile.h"

using namespace std;



class Plateau { /*Classe permettant de définir le plateau du jeu : il est composé d'objet fixe : mur, couloir et sortie*/
	//Définition des attributs protégés
protected:
	int m_nbl; /*nombre de lignes du plateau*/
	int nbc; /*nombre de colonnes du plateau*/
	ObjetGraphiqueFixe*** m_plateau; /*Tableau à 2 dimensions de pointeurs vers des objets graphiques fixes : ce tableau correspond au plateau*/

	//Définition des méthodes publiques
public:
	Plateau();
	void setCase(int i, int j, ObjetGraphiqueFixe* o);
	ObjetGraphiqueFixe* getCase(int i, int j);
	void afficher();
	void afficher(ObjetGraphiqueMobile& p);
};



#endif _PLATEAU_H_