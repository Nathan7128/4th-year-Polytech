#include "personnel.h"



Personnel::Personnel(string numeroBureau, string nom, string adresse):Personne(nom, adresse) {
	m_numeroBureau = numeroBureau;
}

string Personnel::getNumeroBureau() {
	return m_numeroBureau;
}

void Personnel::setNumeroBureau(string nBureau) {
	m_numeroBureau = nBureau;
}