#include "administratif.h"



Administratif::Administratif(string nom, string adresse, string numeroBureau, float salaireMensuel, float primes):
	Personnel(nom, adresse, numeroBureau) {
	m_salaireMensuel = salaireMensuel;
	m_primes = primes;
}

float Administratif::getSalaireMensuel() {
	return m_salaireMensuel;
}

void Administratif::setSalaireMensuel(float nSalaire) {
	m_salaireMensuel = nSalaire;
}

float Administratif::getPrimes() {
	return m_primes;
}

void Administratif::setPrimes(float nPrimes) {
	m_primes = nPrimes;
}

float Administratif::calculerSalaire() {
	return m_primes + m_salaireMensuel;
}

void Administratif::afficher() {
	cout << "Nom : " << getNom() << endl << "Adresse : " << getAdresse() << endl << "Numero de bureau : " << getNumeroBureau() << endl;
	cout << "Salaire Mensuel : " << m_salaireMensuel << endl << "Primes : " << m_primes << endl;
}