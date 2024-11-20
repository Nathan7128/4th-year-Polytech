#ifndef _SORTIE_H_
#define _SORTIE_H_



#include "ObjetGraphiqueFixe.h"



class Sortie : public ObjetGraphiqueFixe {
//Définition des méthodes publiques
public:
	Sortie(int i = 0, int j = 0); /*Constructeur par défaut*/
	void afficher(); /*Affichage de la sortie*/
};



#endif _SORTIE_H_