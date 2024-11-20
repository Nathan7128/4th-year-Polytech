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
	int m_nbc; /*nombre de colonnes du plateau*/
	ObjetGraphiqueFixe*** m_plateau; /*Tableau à 2 dimensions de pointeurs vers des objets graphiques fixes : ce tableau correspond au plateau*/

//Définition des méthodes publiques
public:
	Plateau(int nbl = 0, int nbc = 0); /*Constructeur par défaut*/
	Plateau(const Plateau& plat); /*Constructeur de recopie*/
	~Plateau(); /*Destructeur*/
	void setCase(int i, int j, ObjetGraphiqueFixe* o); /*Définir le contenu d'une case du plateau*/
	ObjetGraphiqueFixe* getCase(int i, int j); /*Obtenir le contenu d'une case du plateau*/
	void afficher(); /*Affichage du plateau*/
	void afficher(ObjetGraphiqueMobile& p); /*Affichage du plateau en prenant en compte l'objet graphique mobile*/
	Plateau& operator=(const Plateau& plat); /*Surcharge de l'opérateur =*/
};



#endif _PLATEAU_H_