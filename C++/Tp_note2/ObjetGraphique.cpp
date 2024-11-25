#include "ObjetGraphique.h"



ObjetGraphique::ObjetGraphique(int i, int j, int type) {
	if (i >= 0 and j >= 0 and type >= 0 and type <= 4) {
		m_i = i;
		m_j = j;
		m_type = type;
	}
	else if (type < 0 or type > 4) {
		throw ExceptionTypeInexistant("Erreur : le type saisie ne correspond à aucun objet graphique");
	}
	else {
		throw ExceptionPbCoord("Erreur de saisie des coordonnees : coordonnees negatives");
	}
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