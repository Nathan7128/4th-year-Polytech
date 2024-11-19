#ifndef _OBJET_GRAPHIQUE_FIXE_H_
#define _OBJET_GRAPHIQUE_FIXE_H_



#include "ObjetGraphique.h"



class ObjetGraphiqueFixe : public ObjetGraphique {/*Classe dérivée de ObjetGraphique permettant de manipuler des objets graphiques non déplaçables*/
	//Définition des méthodes publiques
public:
	ObjetGraphiqueFixe(int i = 0, int j = 0, int type = 0);
};



#endif _OBJET_GRAPHIQUE_FIXE_H_