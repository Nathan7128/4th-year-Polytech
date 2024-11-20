#ifndef _FONCTIONS_H_
#define _FONCTIONS_H_



#include "Labyrinthe.h"
#include "Mur.h"
#include "Couloir.h"
#include "Sortie.h"



Plateau* initPlateauV1(); /*Initialisation du plateau version 1*/

Personnage* initPersoV1(); /*Initialisation du personnage version 1*/

Labyrinthe initLabyrintheV1(Plateau* plat, Personnage* perso); /*Initialisation du labyrinthe version 1*/



#endif _FONCTIONS_H_