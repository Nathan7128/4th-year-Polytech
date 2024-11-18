#ifndef _OBJET_GRAPHIQUE_MOBILE_H_
#define _OBJET_GRAPHIQUE_MOBILE_H_



#include "ObjetGraphique.h"



class ObjetGraphiqueMobile : public ObjetGraphique {
//D�finition des m�thodes publiques
public :
	ObjetGraphiqueMobile(int i = 0, int j = 0, int type = 0);
	void deplacerDroite(); /*D�placer vers la droite et modifier les coordonn�es d'un objet mobile*/
	void deplacerGauche(); /*D�placer vers la gauche et modifier les coordonn�es d'un objet mobile*/
	void deplacerBas(); /*D�placer vers le bas et modifier les coordonn�es d'un objet mobile*/
	void deplacerHaut(); /*D�placer vers le haut et modifier les coordonn�es d'un objet mobile*/
};



#endif _OBJET_GRAPHIQUE_MOBILE_H_