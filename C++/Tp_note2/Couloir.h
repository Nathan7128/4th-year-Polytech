#ifndef _COULOIR_H_
#define _COULOIR_H_



#include "ObjetGraphiqueFixe.h"



class Couloir : public ObjetGraphiqueFixe { /*Classe permettant d'implémenter les couloirs du labyrinthe*/
//Définition des méthodes publiques
public:
	Couloir(int i = 0, int j = 0); /*Constructeur par défaut*/
	void afficher(); /*Affichage du couloir*/
};



#endif _COULOIR_H_