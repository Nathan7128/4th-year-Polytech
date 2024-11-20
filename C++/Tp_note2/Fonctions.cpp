#include "Fonctions.h"



Plateau* initPlateauV1() {
	//Création du plateau
	Plateau* plateau = new Plateau;
	int nbl = 11, nbc = 12, l, c;
	Mur* mur1, * mur2;
	Sortie* sortie = new Sortie;
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

	//Construction des autres murs ligne par ligne
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

	for (int j = 2; j < 10; j++) {
		mur1 = new Mur;
		*mur1 = Mur(4, j);
		plateau->setCase(4, j, mur1);
	}

	mur1 = new Mur;
	l = 5;
	c = 8;
	*mur1 = Mur(l, c);
	plateau->setCase(l, c, mur1);

	for (int j = 1; j < 7; j++) {
		mur1 = new Mur;
		*mur1 = Mur(6, j);
		plateau->setCase(6, j, mur1);
	}

	mur1 = new Mur;
	l = 6;
	c = 8;
	*mur1 = Mur(l, c);
	plateau->setCase(l, c, mur1);

	mur1 = new Mur;
	l = 6;
	c = 10;
	*mur1 = Mur(l, c);
	plateau->setCase(l, c, mur1);

	mur1 = new Mur;
	l = 7;
	c = 8;
	*mur1 = Mur(l, c);
	plateau->setCase(l, c, mur1);

	mur1 = new Mur;
	l = 7;
	c = 10;
	*mur1 = Mur(l, c);
	plateau->setCase(l, c, mur1);

	for (int j = 2; j < 9; j++) {
		mur1 = new Mur;
		*mur1 = Mur(8, j);
		plateau->setCase(8, j, mur1);
	}

	mur1 = new Mur;
	l = 8;
	c = 10;
	*mur1 = Mur(l, c);
	plateau->setCase(l, c, mur1);

	mur1 = new Mur;
	l = 9;
	c = 8;
	*mur1 = Mur(l, c);
	plateau->setCase(l, c, mur1);

	mur1 = new Mur;
	l = 9;
	c = 10;
	*mur1 = Mur(l, c);
	plateau->setCase(l, c, mur1);

	l = 10;
	c = 7;
	*sortie = Sortie(l, c);
	plateau->setCase(l, c, sortie);

	return plateau;
}

Personnage* initPersoV1() {
	Personnage* perso = new Personnage;
	*perso = Personnage(1, 6);
	return perso;
}

Labyrinthe initLabyrintheV1(Plateau* plat, Personnage* perso) {
	Labyrinthe lab(11, 12, plat, perso);
	return lab;
}