#include "Personnage.h"



Personnage::Personnage(int i, int j, int type):ObjetGraphiqueMobile(i, j, type) {

}

void Personnage::afficher() {
	cout << "P";
}