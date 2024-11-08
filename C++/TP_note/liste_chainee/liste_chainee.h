//implémentation de la classe Liste chainée



//include gards
#ifndef _LISTE_CHAINEE_
#define _LISTE_CHAINEE_



//import libraries
#include <iostream>
#include <string>
using namespace std;



//définition du type noeud de la liste chainée
struct noeud {
	int valeur;
	noeud* suivant;
};



//classe Liste Chainée : permet de stocker des entiers
class liste_chainee {
private:
	noeud* m_debut;
	noeud* sep_list();
	void merge(const liste_chainee& l_fin);
	void merge_sort();

public:
	liste_chainee();
	liste_chainee(const liste_chainee& l);
	~liste_chainee();
	int front();
	int back();
	void push_front(int elt);
	void push_back(int elt);
	void pop_front();
	void pop_back();
	int size();
	void insert(int i, int elt); /*exception si i négatif ou si moins de i élément dans la liste
								  Le 1er élément de la liste (s'il existe) est à la position i = 1
								  Si la liste contient 3 éléments, il n'est pas possible d'ajouter un élément en position 4 :
								  il faut effectuer un push_back*/
	void erase(int i);
	bool empty();
	void clear();
	void remove(int elt);
	void sort();
	liste_chainee& operator=(const liste_chainee& l);

	friend ostream& operator<<(ostream& f, const liste_chainee& l);
	friend liste_chainee operator+(const liste_chainee& l1, const liste_chainee& l2);
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



//méthode permettant d'afficher le menu dans la fonction main
void affichage_menu();



#endif // _LISTE_CHAINEE_
