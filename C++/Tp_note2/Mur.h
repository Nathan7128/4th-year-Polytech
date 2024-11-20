#ifndef _MUR_H_
#define _MUR_H_



#include "ObjetGraphiqueFixe.h"



class Mur : public ObjetGraphiqueFixe {
//Définition des méthodes publiques
public:
	Mur(int i = 0, int j = 0); /*Constructeur par défaut*/
	void afficher(); /*Affichage du mur*/
};



#endif _MUR_H_