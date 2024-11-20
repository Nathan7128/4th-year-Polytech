#ifndef _LABYRINTHE_H_
#define _LABYRINTHE_H_



#include "Plateau.h"
#include "Personnage.h"



class Labyrinthe { /*Classe permettant de d�finir le jeu labyrinthe : il poss�de un pointeur vers un plateau et un autre vers le personnage*/
//D�finition des attributs prot�g�s
protected:
	int m_nbl; /*nombre de lignes du plateau du labyrinthe*/
	int m_nbc; /*nombre de colonnes du plateau du labyrinthe*/
	Plateau* m_plateau; /*TPointeur vers le plateau du labyrinthe*/
	Personnage* m_personnage; /*TPointeur vers le personnage du labyrinthe*/

//D�finition des m�thodes publiques
public:
	Labyrinthe(int nbl, int nbc, Plateau* plateau, Personnage* personnage); /*Constructeur par d�faut*/
	Labyrinthe(const Labyrinthe& lab); /*Constructeur de recopie*/
	~Labyrinthe(); /*Destructeur*/
	void afficher(); /*Affichage du labyrinthe*/
	void deplacerPersoDroite(); /*D�placer le personnage vers la droite sur le plateau*/
	void deplacerPersoGauche(); /*D�placer le personnage vers la gauche sur le plateau*/
	void deplacerPersoHaut(); /*D�placer le personnage vers le haut sur le plateau*/
	void deplacerPersoBas(); /*D�placer le personnage vers le bas sur le plateau*/
	bool fini(); /*Permet de savoir si le jeu est termin�*/
	Labyrinthe& operator=(const Labyrinthe& lab); /*Surcharge de l'op�rateur =*/
};



#endif _LABYRINTHE_H_