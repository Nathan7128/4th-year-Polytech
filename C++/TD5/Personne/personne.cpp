#include "personne.h"



Personne::Personne(string nom, string adresse) {
	m_nom = nom;
	m_adresse = adresse;
}

string Personne::getNom() {
	return m_nom;
}

string Personne::getAdresse() {
	return m_adresse;
}

void Personne::setNom(string nom) {
	m_nom = nom;
}

void Personne::setAdresse(string adresse) {
	m_adresse = adresse;
}

void Personne::afficher() {
	cout << "Nom : " << m_nom << endl << "Adresse : " << m_adresse << endl;
}