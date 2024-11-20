#ifndef _OBJET_GRAPHIQUE_H_
#define _OBJET_GRAPHIQUE_H_



#include <iostream>

using namespace std;



class ObjetGraphique { /*Classe permettant de définir des objets graphiques à afficher lors du jeu*/
//Définition des attributs protégés
protected :
	int m_i; /*Coordonnées (ligne) de l'objet*/
	int m_j; /*coordonnées (colonne) de l'objet*/
	int m_type; /*type de l'objet : 1 = Mur, 2 = Couloir, 3 = Sortie, 4 = Personnage*/

//Définition des méthodes publiques
public :
	ObjetGraphique(int i = 0, int j = 0, int type = 0); /*Constructeur par défaut*/
	int getType(); /*Obtenir le type de l'objet graphique*/
	int getI(); /*Obtenir la position (ligne) de l'objet graphique*/
	int getJ(); /*Obtenir la position (colonne) de l'objet graphique*/

	//Méthodes abstraites
	virtual void afficher() = 0; /*Affichage de l'objet graphique*/
};



#endif _OBJET_GRAPHIQUE_H_