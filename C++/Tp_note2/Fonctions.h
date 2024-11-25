#ifndef _FONCTIONS_H_
#define _FONCTIONS_H_



#include "Labyrinthe.h"
#include "Mur.h"
#include "Couloir.h"
#include "Sortie.h"



Plateau* initPlateau(); /*Initialisation du plateau*/

Personnage* initPerso(); /*Initialisation du personnage*/

Labyrinthe initLabyrinthe(Plateau* plat, Personnage* perso); /*Initialisation du labyrinthe*/



#endif _FONCTIONS_H_