#ifndef _SORTIE_H_
#define _SORTIE_H_



#include "ObjetGraphiqueFixe.h"



class Sortie : public ObjetGraphiqueFixe { /*Classe permettant d'impl�menter la sortie du labyrinthe*/
//D�finition des m�thodes publiques
public:
	Sortie(int i = 0, int j = 0); /*Constructeur par d�faut*/
	void afficher(); /*Affichage de la sortie*/
};



#endif _SORTIE_H_