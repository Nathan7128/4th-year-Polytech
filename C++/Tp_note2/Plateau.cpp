#include "Plateau.h"



Plateau::Plateau(int nbl, int nbc) {
	m_nbl = nbl;
	m_nbc = nbc;

	m_plateau = new ObjetGraphiqueFixe**[nbl];
	for (int i = 0; i < nbl; i++) {
		m_plateau[i] = new ObjetGraphiqueFixe*[nbc];
	}
}

Plateau::Plateau(const Plateau& plat) {
	m_nbl = plat.m_nbl;
	m_nbc = plat.m_nbc;
	m_plateau = new ObjetGraphiqueFixe**[m_nbl];
	for (int i = 0; i < m_nbl; i++) {
		m_plateau[i] = new ObjetGraphiqueFixe * [m_nbc];
		for (int j = 0; j < m_nbl; j++) {
			*(m_plateau[i][j]) = *(m_plateau[i][j]);
		}
	}
}

Plateau::~Plateau() {
	for (int i = 0; i < m_nbl; i++) {
		for (int j = 0; j < m_nbc; j++) {
			delete m_plateau[i][j];
		}
		delete[] m_plateau[i];
	}
	delete[] m_plateau;
}

void Plateau::setCase(int i, int j, ObjetGraphiqueFixe* o) {
	m_plateau[i][j] = o;
}

ObjetGraphiqueFixe* Plateau::getCase(int i, int j) {
	return m_plateau[i][j];
}

void Plateau::afficher() {
	for (int i = 0; i < m_nbl; i++) {
		for (int j = 0; j < m_nbc; j++) {
			m_plateau[i][j]->afficher();
		}
		cout << endl;
	}
}

void Plateau::afficher(ObjetGraphiqueMobile& p) {
	for (int i = 0; i < m_nbl; i++) {
		for (int j = 0; j < m_nbc; j++) {
			if (i == p.getI() and j == p.getJ()) {
				p.afficher();
			}
			else {
				m_plateau[i][j]->afficher();
			}
		}
		cout << endl;
	}
}