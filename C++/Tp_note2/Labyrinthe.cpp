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
	m_personnage->deplacerDroite();
}

void Labyrinthe::deplacerPersoGauche() {
	m_personnage->deplacerGauche();
}

void Labyrinthe::deplacerPersoHaut() {
	m_personnage->deplacerHaut();
}

void Labyrinthe::deplacerPersoBas() {
	m_personnage->deplacerBas();
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
		//destruction de la mémoire du labyrinthe actuel
		delete this->m_plateau;
		delete this->m_personnage;

		//recopie du labyrinthe à assigner dans le nouveau labyrinthe
		this->m_nbl = lab.m_nbl;
		this->m_nbc = lab.m_nbc;
		this->m_plateau = new Plateau;
		this->m_personnage = new Personnage;
		*this->m_plateau = *lab.m_plateau;
		*this->m_personnage = *lab.m_personnage;
	}
}