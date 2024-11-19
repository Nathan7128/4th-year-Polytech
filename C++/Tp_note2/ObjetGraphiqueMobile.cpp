#include "ObjetGraphiqueMobile.h"



ObjetGraphiqueMobile::ObjetGraphiqueMobile(int i, int j, int type):ObjetGraphique(i, j, type) {

}

void ObjetGraphiqueMobile::deplacerDroite() {
	m_j++;
}

void ObjetGraphiqueMobile::deplacerGauche() {
	m_j--;
}

void ObjetGraphiqueMobile::deplacerBas() {
	m_i--;
}

void ObjetGraphiqueMobile::deplacerHaut() {
	m_i++;
}