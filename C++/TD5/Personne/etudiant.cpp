#include "etudiant.h"

Etudiant::Etudiant(string nom, string adresse, float moyenne):Personne(nom, adresse) {
	m_moyenne = moyenne;
}

float Etudiant::getMoyenne() {
	return m_moyenne;
}

void Etudiant::setMoyenne(float nMoyenne) {
	m_moyenne = nMoyenne;
}

void Etudiant::afficher() {
	cout << "Nom : " << getNom() << endl << "Adresse : " << getAdresse() << endl << "Moyenne : " << m_moyenne << endl;
}