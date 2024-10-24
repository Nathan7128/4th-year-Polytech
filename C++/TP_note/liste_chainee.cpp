//définition des méthodes de la classe fraction



//import libraries
#include "liste_chainee.h"



liste_chainee::liste_chainee() {
	m_debut = NULL;
}

int liste_chainee::front() {
	return m_debut->valeur;
	//exception si liste vide
}

int liste_chainee::back() {
	noeud* temp = m_debut;
	while (temp->suivant != NULL) {
		temp = temp->suivant;
	}
	return temp->valeur;
	//exception si liste vide
}

void liste_chainee::push_front(int elt) {
	noeud* new_node = new noeud;
	new_node->suivant = m_debut->suivant;
	new_node->valeur = elt;
	m_debut = new_node;
}

void liste_chainee::push_back(int elt) {
	noeud* new_node = new noeud;
	noeud* temp = m_debut;
	new_node->suivant = NULL;
	new_node->valeur = elt;
	while (temp->suivant != NULL) {
		temp = temp->suivant;
	}
	temp->suivant = new_node;
}

void liste_chainee::pop_front() {
	delete m_debut;
	m_debut = m_debut->suivant;
	//exception si liste vide
}

void liste_chainee::pop_back() {
	noeud* temp = m_debut;
	noeud* courant = temp;
	while (temp->suivant != NULL) {
		courant = temp;
		temp = temp->suivant;
	}
	delete temp;
	courant->suivant = NULL;
	//exception si liste vide
}

