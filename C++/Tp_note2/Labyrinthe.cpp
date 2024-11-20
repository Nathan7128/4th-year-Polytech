#include "Labyrinthe.h"



Labyrinthe::Labyrinthe(int nbl, int nbc, Plateau* plateau, Personnage* personnage) {
	m_nbl = nbl;
	m_nbc = nbc;
	m_plateau = plateau;
	m_personnage = personnage;
}

Labyrinthe::~Labyrinthe(){
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