#ifndef _OBJET_GRAPHIQUE_MOBILE_H_
#define _OBJET_GRAPHIQUE_MOBILE_H_



#include "ObjetGraphique.h"



class ObjetGraphiqueMobile : public ObjetGraphique {
//Définition des méthodes publiques
public :
	ObjetGraphiqueMobile(int i = 0, int j = 0, int type = 0);
	void deplacerDroite(); /*Déplacer vers la droite et modifier les coordonnées d'un objet mobile*/
	void deplacerGauche(); /*Déplacer vers la gauche et modifier les coordonnées d'un objet mobile*/
	void deplacerBas(); /*Déplacer vers le bas et modifier les coordonnées d'un objet mobile*/
	void deplacerHaut(); /*Déplacer vers le haut et modifier les coordonnées d'un objet mobile*/
};



#endif _OBJET_GRAPHIQUE_MOBILE_H_