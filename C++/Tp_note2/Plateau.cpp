#include "Plateau.h"



Plateau::Plateau(int nbl, int nbc) {
	if (nbl < 0) {
		throw ExceptionTailleNeg("Erreur : le nombre de lignes ne peut pas etre negatif");
	}
	else if (nbc < 0) {
		throw ExceptionTailleNeg("Erreur : le nombre de colonnes ne peut pas etre negatif");
	}
	else {
		m_nbl = nbl;
		m_nbc = nbc;
		Couloir* couloir;

		m_plateau = new ObjetGraphiqueFixe * *[nbl]; /*Définition de la matrice de pointeurs vers des obtets graphiques fixes
													   C'est un tableau de tableau de pointeurs*/
		for (int i = 0; i < nbl; i++) {
			m_plateau[i] = new ObjetGraphiqueFixe * [nbc];
			for (int j = 0; j < m_nbc; j++) {
				couloir = new Couloir(i, j); /*Déclaration d'un nouveau pointeur vers un couloir à chaque itération*/
				m_plateau[i][j] = couloir;
			}
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
	if (i >= 0 and j >= 0) {
		delete m_plateau[i][j];
		m_plateau[i][j] = o;
	}
	else {
		throw ExceptionPbCoord("Erreur de saisie des coordonnees : coordonnees negatives");
	}
}

ObjetGraphiqueFixe* Plateau::getCase(int i, int j) {
	if (i >= 0 and j >= 0) {
		return m_plateau[i][j];
	}
	else {
		throw ExceptionPbCoord("Erreur de saisie des coordonnees : coordonnees negatives");
	}
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
			if (i == p.getI() and j == p.getJ()) { /*Cas ou on la case itérée contient le personnage*/
				p.afficher();
			}
			else { /*Cas ou on la case itérée contient un objet graphique fixe*/
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