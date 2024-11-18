#include "Couloir.h"



Couloir::Couloir(int i, int j, int type) :ObjetGraphiqueFixe(i, j, type) {

}

void Couloir::afficher() {
	cout << "*";
}