#ifndef _PERSONNAGE_H_
#define _PERSONNAGE_H_



#include "ObjetGraphiqueMobile.h"



class Personnage : public ObjetGraphiqueMobile {
	//D�finition des m�thodes publiques
public:
	Personnage(int i = 0, int j = 0, int type = 0);
	void afficher();
};



#endif _PERSONNAGE_H_