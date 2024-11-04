#include "personnel.h"



Personnel::Personnel(string numeroBureau, string nom, string adresse):Personne(nom, adresse) {
	m_numeroBureau = numeroBureau;
}

