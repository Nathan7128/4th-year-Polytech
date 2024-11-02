//definition des methodes de la classe fraction



//import libraries
#include "liste_chainee.h"



liste_chainee::liste_chainee() {
	m_debut = NULL;
}

int liste_chainee::front() {
	if (m_debut != NULL) {
		return m_debut->valeur;
	}
	else {
		throw ExceptionListeVide("Erreur methode front : liste vide");
	}
}

int liste_chainee::back() {
	noeud* temp = m_debut;
	if (m_debut != NULL) {
		while (temp->suivant != NULL) {
			temp = temp->suivant;
		}
		return temp->valeur;
	}
	else {
		throw ExceptionListeVide("Erreur methode back : liste vide");
	}
}

void liste_chainee::push_front(int elt) {
	noeud* new_noeud = new noeud;
	new_noeud->suivant = m_debut;
	new_noeud->valeur = elt;
	m_debut = new_noeud;
}

void liste_chainee::push_back(int elt) {
	noeud* new_noeud = new noeud, * temp = m_debut;
	new_noeud->suivant = NULL;
	new_noeud->valeur = elt;
	if (m_debut == NULL) {
		m_debut = new_noeud;
	}
	else {
		while (temp->suivant != NULL) {
			temp = temp->suivant;
		}
		temp->suivant = new_noeud;
	}
}

void liste_chainee::pop_front() {
	noeud* temp;
	if (m_debut != NULL) {
		temp = m_debut->suivant;
		delete m_debut;
		m_debut = temp;
	}
	else {
		throw ExceptionListeVide("Erreur methode pop_front : liste vide");
	}
}

void liste_chainee::pop_back() {
	noeud* temp = m_debut;
	if (m_debut == NULL) {
		throw ExceptionListeVide("Erreur methode pop_back : liste vide");
	}
	else if (m_debut->suivant == NULL) {
		m_debut = NULL;
	}
	else {
		while (temp->suivant->suivant != NULL) {
			temp = temp->suivant;
		}
		delete temp->suivant;
		temp->suivant = NULL;
	}
}

int liste_chainee::size() {
	int l_size = 0;
	noeud* temp = m_debut;
	while (temp != NULL) {
		temp = temp->suivant;
		l_size++;
	}
	return l_size;
}

void liste_chainee::insert(int i, int elt) {
	int l_size = size();
	if (i <= l_size) {
		noeud * temp = m_debut, *new_noeud = new noeud;
		new_noeud->valeur = elt;
		int j = 1;
		while (j < i and temp != NULL) {
			temp = temp->suivant;
			j++;
		}
		new_noeud->suivant = temp->suivant;
		temp->suivant = new_noeud;
	}
	else {
		throw ExceptionIndex("Erreur methode insert : la liste contient moins de "
			+ to_string(i) + " elements", i);
	}
}

void liste_chainee::erase(int i) {
	int l_size = size();
	if (i <= l_size) {
		noeud* temp1 = m_debut->suivant, * temp2 = m_debut;
		int j = 2;
		if (i == 1) {
			pop_front();
		}
		else {
			while (j < i and temp1 != NULL) {
				temp2 = temp1;
				temp1 = temp1->suivant;
				j++;
			}
			if (temp1 != NULL) {
				temp2->suivant = temp1->suivant;
				delete temp1;
			}
		}
	}
	else {
		throw ExceptionIndex("Erreur methode erase : la liste contient moins de "
			+ to_string(i) + " elements", i);
	}
}

bool liste_chainee::empty() {
	return (size() == 0);
}

void liste_chainee::clear() {
	int l_size = size();
	for (int i = 0; i < l_size; i++) {
		pop_front();
	}
}

void liste_chainee::remove(int elt) {
	noeud* temp = m_debut;
	int i = 1;
	while (temp != NULL) {
		if (temp->valeur == elt) {
			erase(i);
		}
		else {
			i++;
			temp = temp->suivant;
		}
	}
}

noeud* liste_chainee::sep_list() {
	noeud* lent = m_debut, * rapide = m_debut->suivant->suivant, * temp;
	while (rapide != NULL and rapide->suivant != NULL) {
		lent = lent->suivant;
		rapide = rapide->suivant->suivant;
	}
	temp = lent->suivant;
	lent->suivant = NULL;
	return temp;
}

void liste_chainee::merge(const liste_chainee& l_fin) {
	noeud* temp = m_debut, * l1 = m_debut, * l2 = l_fin.m_debut;
	if (l2->valeur < l1->valeur) {
		m_debut = l2;
		l2 = l2->suivant;
	}
	else {
		l1 = l1->suivant;
	}
	while (l1 != NULL and l2 != NULL) {
		if (l2->valeur < l1->valeur) {
			temp->suivant = l2;
			l2 = l2->suivant;
		}
		else {
			temp->suivant = l1;
			l1 = l1->suivant;
		}
	}
	if (l1 != NULL) {
		temp->suivant = l1;
	}
	else {
		temp->suivant = l2;
	}
}

void liste_chainee::merge_sort() {
	liste_chainee l_fin;
	if (m_debut != NULL and m_debut->suivant != NULL) {
		l_fin.m_debut = sep_list();
		merge_sort();
		l_fin.merge_sort();
		merge(l_fin);
	}
}

void liste_chainee::sort() {
	if (m_debut != NULL) {
		merge_sort();
	}
}

ostream& operator<<(ostream& f, const liste_chainee& l) {
	noeud* temp = l.m_debut;
	if (temp != NULL) {
		while (temp->suivant != NULL) {
			f << temp->valeur << " -> ";
			temp = temp->suivant;
		}
		f << temp->valeur;
	}
	return f;
}

liste_chainee operator+(const liste_chainee& l1, const liste_chainee& l2) {
	liste_chainee l_new;
	noeud* temp_l1 = l1.m_debut, * temp_l2 = l2.m_debut, * temp_lnew, * new_noeud;
	if (l1.m_debut != NULL) {
		l_new.push_front(l1.m_debut->valeur);
		temp_lnew = l_new.m_debut;
		temp_l1 = l1.m_debut->suivant;
	}
	else if (l2.m_debut != NULL) {
		l_new.push_front(l2.m_debut->valeur);
		temp_lnew = l_new.m_debut;
		temp_l2 = l2.m_debut->suivant;
	}
	else {
		return l_new;
	}
	while (temp_l1 != NULL) {
		new_noeud = new noeud;
		new_noeud->suivant = NULL;
		new_noeud->valeur = temp_l1->valeur;
		temp_lnew->suivant = new_noeud;
		temp_lnew = new_noeud;
		temp_l1 = temp_l1->suivant;
	}
	while (temp_l2 != NULL) {
		new_noeud = new noeud;
		new_noeud->suivant = NULL;
		new_noeud->valeur = temp_l2->valeur;
		temp_lnew->suivant = new_noeud;
		temp_lnew = new_noeud;
		temp_l2 = temp_l2->suivant;
	}
	return l_new;
}

void affichage_menu() {
	cout << "0) arreter la saisie" << "\n\n";
	cout << "1) front : retourne le premier element de la liste" << "\n\n";
	cout << "2) back : retourne le dernier element de la liste" << "\n\n";
	cout << "3) push_front(elt) : ajoute un element au debut de la liste" << "\n\n";
	cout << "4) push_back(elt) : ajoute un element a la fin de la liste" << "\n\n";
	cout << "5) pop_front : supprime le premier element de la liste" << "\n\n";
	cout << "6) pop_back : supprimer le dernier element de la liste" << "\n\n";
	cout << "7) insert(i, elt) : ajoute un element a la ieme position dans la liste" << "\n\n";
	cout << "8) erase(i) : supprime le ieme element de la liste" << "\n\n";
	cout << "9) size : renvoie le nombre d�elements stockes dans la liste" << "\n\n";
	cout << "10) empty : renvoie vrai si la liste est vide, faux sinon" << "\n\n";
	cout << "11) clear : vide la liste" << "\n\n";
	cout << "12) remove(elt) : supprime de la liste tous les elements egaux a elt" << "\n\n";
	cout << "13) sort : trie la liste par ordre croissant" << "\n\n";
}