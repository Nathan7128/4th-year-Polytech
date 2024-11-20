#ifndef _LABYRINTHE_H_
#define _LABYRINTHE_H_



#include "Plateau.h"
#include "Personnage.h"



class Labyrinthe { /*Classe permettant de définir le jeu labyrinthe : il possède un pointeur vers un plateau et un autre vers le personnage*/
//Définition des attributs protégés
protected:
	int m_nbl; /*nombre de lignes du plateau du labyrinthe*/
	int m_nbc; /*nombre de colonnes du plateau du labyrinthe*/
	Plateau* m_plateau; /*TPointeur vers le plateau du labyrinthe*/
	Personnage* m_personnage; /*TPointeur vers le personnage du labyrinthe*/

//Définition des méthodes publiques
public:
	Labyrinthe(int nbl, int nbc, Plateau* plateau, Personnage* personnage); /*Constructeur par défaut*/
	Labyrinthe(const Labyrinthe& lab); /*Constructeur de recopie*/
	~Labyrinthe(); /*Destructeur*/
	void afficher(); /*Affichage du labyrinthe*/
	void deplacerPersoDroite(); /*Déplacer le personnage vers la droite sur le plateau*/
	void deplacerPersoGauche(); /*Déplacer le personnage vers la gauche sur le plateau*/
	void deplacerPersoHaut(); /*Déplacer le personnage vers le haut sur le plateau*/
	void deplacerPersoBas(); /*Déplacer le personnage vers le bas sur le plateau*/
	bool fini(); /*Permet de savoir si le jeu est terminé*/
	Labyrinthe& operator=(const Labyrinthe& lab); /*Surcharge de l'opérateur =*/
};



#endif _LABYRINTHE_H_