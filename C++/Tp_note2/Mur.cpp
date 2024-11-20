#include "Mur.h"



Mur::Mur(int i, int j):ObjetGraphiqueFixe(i, j, 1) {
}

void Mur::afficher() {
	cout << "*";
}