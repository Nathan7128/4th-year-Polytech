#include "ObjetGraphique.h"



ObjetGraphique::ObjetGraphique(int i, int j, int type) {
	m_i = i;
	m_j = j;
	m_type = type;
}

int ObjetGraphique::getType() {
	return m_type;
}

int ObjetGraphique::getI() {
	return m_i;
}

int ObjetGraphique::getJ() {
	return m_j;
}