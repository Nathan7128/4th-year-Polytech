//definition des methodes de la classe fraction



//import libraries
#include "liste_chainee.h"



liste_chainee::liste_chainee() {
	m_debut = NULL;
}

liste_chainee::liste_chainee(const liste_chainee& l) {
	noeud* temp_old = l.m_debut, * temp_new = new noeud;
	m_debut = temp_new;
	while (temp_old != NULL) {
		temp_new->suivant = new noeud;
		temp_new->valeur = temp_old->valeur;
		temp_new = temp_new->suivant;
		temp_old = temp_old->suivant;
	}
}

liste_chainee::~liste_chainee() {
	noeud* temp;
	while (m_debut != NULL) {
		temp = m_debut->suivant;
		delete m_debut;
		m_debut = temp;
	}
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
		pop_front();
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
	noeud* temp = m_debut, * new_noeud = new noeud;
	new_noeud->valeur = elt;
	if (i > l_size) {
		throw ExceptionIndex("Erreur methode insert : la liste contient moins de "
			+ to_string(i) + " elements", i);
	}
	else if (i < 1) {
		throw ExceptionIndex("Erreur methode insert : saisir index superieur a 0", i);
	}
	else if (i == 1) {
		new_noeud->suivant = m_debut->suivant;
		m_debut = new_noeud;
	}
	else {
		for (int j = 1; j < i - 1; j++) {
			temp = temp->suivant;
		}
		new_noeud->suivant = temp->suivant->suivant;
		temp->suivant = new_noeud;
	}
}

void liste_chainee::erase(int i) {
	int l_size = size();
	noeud* temp1, * temp2;
	if (i > l_size) {
		throw ExceptionIndex("Erreur methode erase : la liste contient moins de "
			+ to_string(i) + " elements", i);
	}
	else if (i < 1) {
		throw ExceptionIndex("Erreur methode insert : saisir index superieur a 0", i);
	}
	else if (i == 1) {
		pop_front();
	}
	else {
		temp1 = m_debut;
		for (int j = 2; j < i; j++) {
			temp1 = temp1->suivant;
		}
		temp2 = temp1->suivant;
		temp1->suivant = temp1->suivant->suivant;
		delete temp2;
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
	noeud* temp1, * temp2;
	if (m_debut->valeur == elt) {
		pop_front();
	}
	temp1 = m_debut;
	while (temp1->suivant != NULL) {
		if (temp1->suivant->valeur == elt) {
			temp2 = temp1->suivant;
			temp1->suivant = temp1->suivant->suivant;
			delete temp2;
		}
		else {
			temp1 = temp1->suivant;
		}
	}
}

noeud* sep_list(noeud* debut) {
	noeud* lent = debut, * rapide = debut->suivant;
	while (rapide != NULL and rapide->suivant != NULL) {
		rapide = rapide->suivant->suivant;
		lent = lent->suivant;
	}
	return lent;
}

noeud* merge(noeud* debut, noeud* fin) {
	noeud* nouveau = new noeud, * temp = nouveau;
	while (debut != NULL and fin != NULL) {
		if (debut->valeur <= fin->valeur) {
			temp->suivant = debut;
			debut = debut->suivant;
		}
		else {
			temp->suivant = fin;
			fin = fin->suivant;
		}
		temp = temp->suivant;
	}
	if (debut != NULL) {
		temp->suivant = debut;
	}
	else {
		temp->suivant = fin;
	}
	return nouveau->suivant;
}

noeud* merge_sort(noeud* debut) {
	noeud* fin, * sep, * gauche, * droite, * nouveau;
	if (debut == NULL or debut->suivant == NULL) {
		return debut;
	}
	sep = sep_list(debut);
	fin = sep->suivant;
	sep->suivant = NULL;

	gauche = merge_sort(debut);
	droite = merge_sort(fin);

	nouveau = merge(gauche, droite);

	return nouveau;
}

void liste_chainee::sort() {
	if (m_debut != NULL) {
		m_debut = merge_sort(m_debut);
	}
}

liste_chainee& liste_chainee::operator=(const liste_chainee& l) {
	noeud* temp_old = l.m_debut, * temp_new = new noeud;
	if (this != &l) {
		this->clear();
		if (temp_old != NULL) {
			m_debut = temp_new;
			while (temp_old->suivant != NULL) {
				temp_new->suivant = new noeud;
				temp_new->valeur = temp_old->valeur;
				temp_new = temp_new->suivant;
				temp_old = temp_old->suivant;
			}
			temp_new->suivant = NULL;
			temp_new->valeur = temp_old->valeur;
		}
	}
	return *this;
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
	cout << "Vous avez a votre disposition 10 listes vides numerotees de 1 a 10" << "\n\n";
	cout << "0) arreter la saisie" << endl;
	cout << "1) front : retourne le premier element de la liste" << endl;
	cout << "2) back : retourne le dernier element de la liste" << endl;
	cout << "3) push_front(elt) : ajoute un element au debut de la liste" << endl;
	cout << "4) push_back(elt) : ajoute un element a la fin de la liste" << endl;
	cout << "5) pop_front : supprime le premier element de la liste" << endl;
	cout << "6) pop_back : supprimer le dernier element de la liste" << endl;
	cout << "7) insert(i, elt) : ajoute un element a la ieme position dans la liste" << endl;
	cout << "8) erase(i) : supprime le ieme element de la liste" << endl;
	cout << "9) size : renvoie la taille de la liste" << endl;
	cout << "10) empty : renvoie vrai si la liste est vide, faux sinon" << endl;
	cout << "11) clear : vide la liste" << endl;
	cout << "12) remove(elt) : supprime de la liste tous les elements egaux a elt" << endl;
	cout << "13) sort : trie la liste par ordre croissant" << endl;
	cout << "14) = : attribuer les valeurs d une autre liste a cette liste" << endl;
	cout << "15) + : concatener deux listes" << endl;
}