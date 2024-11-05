#include "vacataire.h"



Vacataire::Vacataire(string nom, string adresse, string numeroBureau, int numCasier, float tarifHoraire, float nbHeures) :
	Enseignant(nom, adresse, numeroBureau, numCasier) {
	m_tarifHoraire = tarifHoraire;
	m_nbHeures = nbHeures;
}

float Vacataire::getTarifHoraire() {
	return m_tarifHoraire;
}

void Vacataire::setTarifHoraire(float nTarif) {
	m_tarifHoraire = nTarif;
}

float Vacataire::getNbHeures() {
	return m_nbHeures;
}

void Vacataire::setNbHeures(float nNbHeures) {
	m_nbHeures = nNbHeures;
}

float Vacataire::calculerSalaire() {
	return m_nbHeures * m_tarifHoraire;
}

void Vacataire::afficher() {
	cout << "Nom : " << getNom() << endl << "Adresse : " << getAdresse() << endl << "Numero casier : " << getNumCasier << endl;
	cout << "Tarif horaire : " << m_tarifHoraire << endl << "Nombre d'heures : " << m_nbHeures << endl;
}