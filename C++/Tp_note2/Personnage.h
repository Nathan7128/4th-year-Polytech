#ifndef _PERSONNAGE_H_
#define _PERSONNAGE_H_



#include "ObjetGraphiqueMobile.h"



class Personnage : public ObjetGraphiqueMobile {
	//Définition des méthodes publiques
public:
	Personnage(int i = 0, int j = 0); /*Constructeur par défaut*/
	void afficher(); /*Affichage du personnage*/
};



#endif _PERSONNAGE_H_