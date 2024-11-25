#ifndef _OBJET_GRAPHIQUE_H_
#define _OBJET_GRAPHIQUE_H_



#include <iostream>

using namespace std;



//Classe exception pour saisie de coordonnées incohérentes pour un objet graphique
class ExceptionPbCoord {
public :
	string m_message; /*Message décrivant l'erreur*/
	ExceptionPbCoord(string m = "Erreur de saisie des coordonnees") { m_message = m; };
};



//Classe exception pour saisie de type inexistant pour un objet graphique (pas compris dans {0, 1, 2, 3, 4})
class ExceptionTypeInexistant {
public:
	string m_message; /*Message décrivant l'erreur*/
	ExceptionTypeInexistant(string m = "Erreur : saisie de type inexistant") { m_message = m; };
};



class ObjetGraphique { /*Classe permettant de définir des objets graphiques à afficher lors du jeu*/
//Définition des attributs protégés
protected :
	int m_i; /*Coordonnée (ligne) de l'objet*/
	int m_j; /*coordonnée (colonne) de l'objet*/
	int m_type; /*type de l'objet : 0 = Valeur par défaut, 1 = Mur, 2 = Couloir, 3 = Sortie, 4 = Personnage*/

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