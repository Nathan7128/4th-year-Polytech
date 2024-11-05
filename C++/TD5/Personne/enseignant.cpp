#include "enseignant.h"



Enseignant::Enseignant(string nom, string adresse, string numeroBureau, int numCasier) :
	Personnel(nom, adresse, numeroBureau) {
	m_numCasier = numCasier;
}

int Enseignant::getNumCasier() {
	return m_numCasier;
}

void Enseignant::setNumCasier(int nCasier) {
	m_numCasier = nCasier;
}