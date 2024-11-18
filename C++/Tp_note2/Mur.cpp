#include "Mur.h"



Mur::Mur(int i, int j, int type) :ObjetGraphiqueFixe(i, j, type) {

}

void Mur::afficher() {
	cout << "*";
}