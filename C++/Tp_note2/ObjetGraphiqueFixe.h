#ifndef _OBJET_GRAPHIQUE_FIXE_H_
#define _OBJET_GRAPHIQUE_FIXE_H_



#include "ObjetGraphique.h"



class ObjetGraphiqueFixe : public ObjetGraphique {/*Classe d�riv�e de ObjetGraphique permettant de manipuler des objets graphiques non d�pla�ables*/
	//D�finition des m�thodes publiques
public:
	ObjetGraphiqueFixe(int i = 0, int j = 0, int type = 0);
};



#endif _OBJET_GRAPHIQUE_FIXE_H_