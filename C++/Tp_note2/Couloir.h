#ifndef _COULOIR_H_
#define _COULOIR_H_



#include "ObjetGraphiqueFixe.h"



class Couloir : public ObjetGraphiqueFixe {
	//D�finition des m�thodes publiques
public:
	Couloir(int i = 0, int j = 0, int type = 0);
	void afficher();
};



#endif _COULOIR_H_