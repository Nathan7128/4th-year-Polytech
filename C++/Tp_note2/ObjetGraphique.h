#ifndef _OBJET_GRAPHIQUE_H_
#define _OBJET_GRAPHIQUE_H_



#include <iostream>

using namespace std;



class ObjetGraphique { /*Classe permettant de d�finir des objets graphiques � afficher lors du jeu*/
//D�finition des attributs prot�g�s
protected :
	int m_i; /*Coordonn�es (ligne) de l'objet*/
	int m_j; /*coordonn�es (colonne) de l'objet*/
	int m_type; /*type de l'objet : 1 = Mur, 2 = Couloir, 3 = Sortie, 4 = Personnage*/

//D�finition des m�thodes publiques
public :
	ObjetGraphique(int i = 0, int j = 0, int type = 0);
	int getType();
	int getI();
	int getJ();

	//M�thodes abstraites
	virtual void afficher() = 0;
};



#endif _OBJET_GRAPHIQUE_H_