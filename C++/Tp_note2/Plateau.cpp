#include "Plateau.h"



Plateau::Plateau(int nbl, int nbc) {
	m_nbl = nbl;
	m_nbc = nbc;
	Couloir* couloir;

	m_plateau = new ObjetGraphiqueFixe**[nbl];
	for (int i = 0; i < nbl; i++) {
		m_plateau[i] = new ObjetGraphiqueFixe*[nbc];
		for (int j = 0; j < m_nbc; j++) {
			couloir = new Couloir;
			*couloir = Couloir(i, j);
			m_plateau[i][j] = couloir;
		}
	}
}

Plateau::Plateau(const Plateau& plat) {
	m_nbl = plat.m_nbl;
	m_nbc = plat.m_nbc;
	m_plateau = new ObjetGraphiqueFixe**[m_nbl];
	for (int i = 0; i < m_nbl; i++) {
		m_plateau[i] = new ObjetGraphiqueFixe * [m_nbc];
		for (int j = 0; j < m_nbc; j++) {
			*(m_plateau[i][j]) = *(plat.m_plateau[i][j]);
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

Plateau& Plateau::operator=(const Plateau& plat) {
	if (this != &plat) {
		//Destruction de la mémoire du plateau actuel
		for (int i = 0; i < this->m_nbl; i++) {
			for (int j = 0; j < this->m_nbc; j++) {
				delete this->m_plateau[i][j];
			}
			delete[] this->m_plateau[i];
		}
		delete[] this->m_plateau;

		//Recopie du plateau à assigner dans le nouveau plateau
		this->m_nbl = plat.m_nbl;
		this->m_nbc = plat.m_nbc;
		this->m_plateau = new ObjetGraphiqueFixe * *[this->m_nbl];
		for (int i = 0; i < this->m_nbl; i++) {
			this->m_plateau[i] = new ObjetGraphiqueFixe * [this->m_nbc];
			for (int j = 0; j < this->m_nbc; j++) {
				this->m_plateau[i][j] = new Couloir;
				*(this->m_plateau[i][j]) = *(plat.m_plateau[i][j]);
			}
		}
	}
	return *this;
}