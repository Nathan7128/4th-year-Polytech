#include "permanent.h"



Permanent::Permanent(string nom, string adresse, string numeroBureau, int numCasier, float salaireMensuel, float montantHeuresSup,
	float primes) : Enseignant(nom, adresse, numeroBureau, numCasier) {
	m_salaireMensuel = salaireMensuel;
	m_montantHeuresSup = montantHeuresSup;
	m_primes = primes;
}

float Permanent::getSalaireMensuel() {
	return m_salaireMensuel;
}

void Permanent::setSalaireMensuel(float nSalaire) {
	m_salaireMensuel = nSalaire;
}

float Permanent::getMontantHeuresSup() {
	return m_montantHeuresSup;
}

void Permanent::setMontantHeuresSup(float nMontantHeuresSup) {
	m_montantHeuresSup = nMontantHeuresSup;
}

float Permanent::getPrimes() {
	return m_primes;
}

void Permanent::setPrimes(float nPrimes) {
	m_primes = nPrimes;
}

float Permanent::calculerSalaire() {
	return m_salaireMensuel + m_montantHeuresSup + m_primes;
}

void Permanent::afficher() {
	cout << "Nom : " << getNom() << endl << "Adresse : " << getAdresse() << endl << "Numero casier : " << getNumCasier << endl;
	cout << "Salaire mensuel : " << m_salaireMensuel << endl << "Montant heures sup. : " << m_montantHeuresSup << endl;
	cout << "Primes : " << m_primes << endl;
}