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

void Personne::setNom(string nNom) {
	m_nom = nNom;
}

void Personne::setAdresse(string nAdresse) {
	m_adresse = nAdresse;
}

void Personne::afficher() {
	cout << "Nom : " << m_nom << endl << "Adresse : " << m_adresse << endl;
}