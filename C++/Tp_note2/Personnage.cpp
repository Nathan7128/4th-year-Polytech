#include "Personnage.h"



Personnage::Personnage(int i, int j):ObjetGraphiqueMobile(i, j, 4) {
}

void Personnage::afficher() {
	cout << "P";
}