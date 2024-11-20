#include "Labyrinthe.h"



Labyrinthe::Labyrinthe(int nbl, int nbc, Plateau* plateau, Personnage* personnage) {
	m_nbl = nbl;
	m_nbc = nbc;
	m_plateau = plateau;
	m_personnage = personnage;
}

Labyrinthe::Labyrinthe(const Labyrinthe& lab) {
	m_nbl = lab.m_nbl;
	m_nbc = lab.m_nbc;
	m_plateau = new Plateau;
	m_personnage = new Personnage;
	*m_plateau = *lab.m_plateau;
	*m_personnage = *lab.m_personnage;
}

Labyrinthe::~Labyrinthe() {
	delete m_plateau;
	delete m_personnage;
}

void Labyrinthe::afficher() {
	m_plateau->afficher(*m_personnage);
}

void Labyrinthe::deplacerPersoDroite() {
	int i = m_personnage->getI(), j = m_personnage->getJ();
	if ((m_plateau->getCase(i, j + 1))->getType() == 1) {
		cout << "Deplacement impossible : il y'a un mur a droite" << endl;
	}
	else {
		m_personnage->deplacerDroite();
	}
}

void Labyrinthe::deplacerPersoGauche() {
	int i = m_personnage->getI(), j = m_personnage->getJ();
	if ((m_plateau->getCase(i, j - 1))->getType() == 1) {
		cout << "Deplacement impossible : il y'a un mur a gauche" << endl;
	}
	else {
		m_personnage->deplacerGauche();
	}
}

void Labyrinthe::deplacerPersoHaut() {
	int i = m_personnage->getI(), j = m_personnage->getJ();
	if ((m_plateau->getCase(i - 1, j))->getType() == 1) {
		cout << "Deplacement impossible : il y'a un mur en haut" << endl;
	}
	else {
		m_personnage->deplacerHaut();
	}
}

void Labyrinthe::deplacerPersoBas() {
	int i = m_personnage->getI(), j = m_personnage->getJ();
	if ((m_plateau->getCase(i + 1, j))->getType() == 1) {
		cout << "Deplacement impossible : il y'a un mur en bas" << endl;
	}
	else {
		m_personnage->deplacerBas();
	}
}

bool Labyrinthe::fini() {
	if (m_plateau->getCase(m_personnage->getI(), m_personnage->getJ())->getType() == 3) {
		return true;
	}
	else {
		return false;
	}
}

Labyrinthe& Labyrinthe::operator=(const Labyrinthe& lab) {
	if (this != &lab) {
		//Destruction de la mémoire du labyrinthe actuel
		delete this->m_plateau;
		delete this->m_personnage;

		//Recopie du labyrinthe à assigner dans le nouveau labyrinthe
		this->m_nbl = lab.m_nbl;
		this->m_nbc = lab.m_nbc;
		this->m_plateau = new Plateau;
		this->m_personnage = new Personnage;
		*this->m_plateau = *lab.m_plateau;
		*this->m_personnage = *lab.m_personnage;
	}
	return *this;
}