//implémentation de la classe Liste chainée générique



//chiens de garde
#ifndef _LISTE_CHAINEE_GEN_
#define _LISTE_CHAINEE_GEN_



//importation des bibliothèques
#include <iostream>
#include <string>
using namespace std;



//définition du type noeud de la liste chainée
template <typename T>
struct noeud {
	T valeur;
	noeud* suivant;
};



//classe Liste Chainée : permet de stocker des entiers dans une liste chainée
template <typename T>
class liste_chainee {
private:
	noeud<T>* m_debut; /*tête de la liste*/

public:
	liste_chainee(); /*constructeur par défaut*/
	liste_chainee(const liste_chainee& l); /*constructeur de recopie*/
	~liste_chainee(); /*destructeur*/
	T front(); /*retourne le premier élément de la liste*/
	T back(); /*retourne le dernier élément de la liste*/
	void push_front(T elt); /*ajoute un élément au début de la liste*/
	void push_back(T elt); /*ajoute un élément à la fin de la liste*/
	void pop_front(); /*supprime le premier élément de la liste*/
	void pop_back(); /*supprimer le dernier élement de la liste*/
	int size(); /*renvoie le nombre d’éléments stockés dans la liste*/
	void insert(int i, T elt); /*Le 1er élément de la liste (s'il existe) est à la position i = 1
								  Si la liste contient par exemple 3 éléments, il n'est pas possible d'ajouter un élément en position 4 :
								  il faut effectuer un push_back*/
	void erase(int i); /*supprime le ième élement de la liste*/
	bool empty(); /*renvoie vrai si la liste est vide, faux sinon*/
	void clear(); /*vide la liste*/
	void remove(T elt); /*supprime de la liste tous les éléments égaux à elt*/
	void sort(); /*trie la liste par ordre croissant*/
	liste_chainee<T>& operator=(const liste_chainee<T>& l); /*attribrue les valeurs d'une liste à une autre liste*/

	template <typename T> friend noeud<T>* sep_list(noeud<T>* debut); /*permet de séparer la liste chainée en 2 pour le merge sort :
															   renvoie un pointeur vers la deuxième moitié de la liste*/
	template <typename T> friend noeud<T>* merge(noeud<T>* debut, noeud<T>* fin); /*fusionne 2 listes chainées passées en paramètre*/
	template <typename T> friend noeud<T>* merge_sort(noeud<T>* debut); /*permet de trier récursivement des sous parties de la liste,
																 puis de fusionner ces sous parties*/
	template <typename T> friend ostream& operator<<(ostream& f, const liste_chainee<T>& l); /*affiche la liste*/
	template <typename T> friend liste_chainee<T> operator+(const liste_chainee<T>& l1, const liste_chainee<T>& l2); /*concatène 2 listes*/
};



//classe exception liste vide
class ExceptionListeVide {
public:
	string m_message;
	ExceptionListeVide(string m = "Erreur : liste vide") { m_message = m; };
};



//classe exception index de liste
class ExceptionIndex {
public:
	string m_message;
	int m_index;
	ExceptionIndex(string m = "Erreur d'index", int index = 0) {
		m_message = m;
		m_index = index;
	};
};



//definition des methodes de la classe fraction



template <typename T>
liste_chainee<T>::liste_chainee() {
	m_debut = NULL;
}

template <typename T>
liste_chainee<T>::liste_chainee(const liste_chainee& l) {
	noeud<T>* temp_old = l.m_debut, * temp_new = new noeud<T>;
	m_debut = temp_new;
	while (temp_old != NULL) {
		temp_new->suivant = new noeud<T>;
		temp_new->valeur = temp_old->valeur;
		temp_new = temp_new->suivant;
		temp_old = temp_old->suivant;
	}
}

template <typename T>
liste_chainee<T>::~liste_chainee() {
	noeud<T>* temp;
	while (m_debut != NULL) {
		temp = m_debut->suivant;
		delete m_debut;
		m_debut = temp;
	}
}

template <typename T>
T liste_chainee<T>::front() {
	if (m_debut != NULL) {
		return m_debut->valeur;
	}
	else {
		throw ExceptionListeVide("Erreur methode front : liste vide");
	}
}

template <typename T>
T liste_chainee<T>::back() {
	noeud<T>* temp = m_debut;
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

template <typename T>
void liste_chainee<T>::push_front(T elt) {
	noeud<T>* new_noeud = new noeud<T>;
	new_noeud->suivant = m_debut;
	new_noeud->valeur = elt;
	m_debut = new_noeud;
}

template <typename T>
void liste_chainee<T>::push_back(T elt) {
	noeud<T>* new_noeud = new noeud<T>, * temp = m_debut;
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

template <typename T>
void liste_chainee<T>::pop_front() {
	noeud<T>* temp;
	if (m_debut != NULL) {
		temp = m_debut->suivant;
		delete m_debut;
		m_debut = temp;
	}
	else {
		throw ExceptionListeVide("Erreur methode pop_front : liste vide");
	}
}

template <typename T>
void liste_chainee<T>::pop_back() {
	noeud<T>* temp = m_debut;
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

template <typename T>
int liste_chainee<T>::size() {
	int l_size = 0;
	noeud<T>* temp = m_debut;
	while (temp != NULL) {
		temp = temp->suivant;
		l_size++;
	}
	return l_size;
}

template <typename T>
void liste_chainee<T>::insert(int i, T elt) {
	int l_size = size();
	noeud<T>* temp = m_debut, * new_noeud = new noeud<T>;
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

template <typename T>
void liste_chainee<T>::erase(int i) {
	int l_size = size();
	noeud<T>* temp1, * temp2;
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

template <typename T>
bool liste_chainee<T>::empty() {
	return (size() == 0);
}

template <typename T>
void liste_chainee<T>::clear() {
	int l_size = size();
	for (int i = 0; i < l_size; i++) {
		pop_front();
	}
}

template <typename T>
void liste_chainee<T>::remove(T elt) {
	noeud<T>* temp1, * temp2;
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

template <typename T>
noeud<T>* sep_list(noeud<T>* debut) {
	noeud<T>* lent = debut, * rapide = debut->suivant;
	while (rapide != NULL and rapide->suivant != NULL) {
		rapide = rapide->suivant->suivant;
		lent = lent->suivant;
	}
	return lent;
}

template <typename T>
noeud<T>* merge(noeud<T>* debut, noeud<T>* fin) {
	noeud<T>* nouveau = new noeud<T>, * temp = nouveau;
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

template <typename T>
noeud<T>* merge_sort(noeud<T>* debut) {
	noeud<T>* fin, * sep, * gauche, * droite, * nouveau;
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

template <typename T>
void liste_chainee<T>::sort() {
	if (m_debut != NULL) {
		m_debut = merge_sort(m_debut);
	}
}

template <typename T>
liste_chainee<T>& liste_chainee<T>::operator=(const liste_chainee<T>& l) {
	noeud<T>* temp_old = l.m_debut, * temp_new = new noeud<T>;
	if (this != &l) {
		this->clear();
		if (temp_old != NULL) {
			m_debut = temp_new;
			while (temp_old->suivant != NULL) {
				temp_new->suivant = new noeud<T>;
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

template <typename T>
ostream& operator<<(ostream& f, const liste_chainee<T>& l) {
	noeud<T>* temp = l.m_debut;
	if (temp != NULL) {
		while (temp->suivant != NULL) {
			f << temp->valeur << " -> ";
			temp = temp->suivant;
		}
		f << temp->valeur;
	}
	return f;
}

template <typename T>
liste_chainee<T> operator+(const liste_chainee<T>& l1, const liste_chainee<T>& l2) {
	liste_chainee<T> l_new;
	noeud<T>* temp_l1 = l1.m_debut, * temp_l2 = l2.m_debut, * temp_lnew, * new_noeud;
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
		new_noeud = new noeud<T>;
		new_noeud->suivant = NULL;
		new_noeud->valeur = temp_l1->valeur;
		temp_lnew->suivant = new_noeud;
		temp_lnew = new_noeud;
		temp_l1 = temp_l1->suivant;
	}
	while (temp_l2 != NULL) {
		new_noeud = new noeud<T>;
		new_noeud->suivant = NULL;
		new_noeud->valeur = temp_l2->valeur;
		temp_lnew->suivant = new_noeud;
		temp_lnew = new_noeud;
		temp_l2 = temp_l2->suivant;
	}
	return l_new;
}

//méthode permettant d'afficher le menu dans la fonction main
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



#endif // _LISTE_CHAINEE_