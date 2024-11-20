#include "Fonctions.h"



Plateau* initPlateau_V1() {
	//Création du plateau
	Plateau* plateau = new Plateau;
	int nbl = 11, nbc = 12, l, c;
	Mur* mur1 = new Mur, * mur2 = new Mur;
	*plateau = Plateau(nbl, nbc);
	
	//Construction des murs en haut et en bas
	for (int j = 0; j < nbc; j++) {
		mur1 = new Mur;
		mur2 = new Mur;
		*mur1 = Mur(0, j);
		*mur2 = Mur(nbl - 1, j);
		plateau->setCase(0, j, mur1);
		plateau->setCase(nbl - 1, j, mur2);
	}

	//Construction des murs à gauche et à droite
	for (int i = 0; i < nbl; i++) {
		mur1 = new Mur;
		mur2 = new Mur;
		*mur1 = Mur(i, 0);
		*mur2 = Mur(i, nbc - 1);
		plateau->setCase(i, 0, mur1);
		plateau->setCase(i, nbc - 1, mur2);
	}

	//Construction des autres murs
	mur1 = new Mur;
	l = 1;
	c = 5;
	*mur1 = Mur(l, c);
	plateau->setCase(l, c, mur1);

	mur1 = new Mur;
	l = 1;
	c = 7;
	*mur1 = Mur(l, c);
	plateau->setCase(l, c, mur1);

	mur1 = new Mur;
	l = 2;
	c = 2;
	*mur1 = Mur(l, c);
	plateau->setCase(l, c, mur1);

	mur1 = new Mur;
	l = 2;
	c = 4;
	*mur1 = Mur(l, c);
	plateau->setCase(l, c, mur1);

	mur1 = new Mur;
	l = 2;
	c = 5;
	*mur1 = Mur(l, c);
	plateau->setCase(l, c, mur1);

	mur1 = new Mur;
	l = 2;
	c = 7;
	*mur1 = Mur(l, c);
	plateau->setCase(l, c, mur1);

	mur1 = new Mur;
	l = 2;
	c = 9;
	*mur1 = Mur(l, c);
	plateau->setCase(l, c, mur1);

	mur1 = new Mur;
	l = 3;
	c = 2;
	*mur1 = Mur(l, c);
	plateau->setCase(l, c, mur1);

	mur1 = new Mur;
	l = 3;
	c = 9;
	*mur1 = Mur(l, c);
	plateau->setCase(l, c, mur1);

	return plateau;
}