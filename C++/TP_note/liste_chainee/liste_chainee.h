//implémentation de la classe Liste chainée



//chiens de garde
#ifndef _LISTE_CHAINEE_
#define _LISTE_CHAINEE_



//importation des bibliothèques
#include <iostream>
#include <string>
using namespace std;



//définition du type noeud de la liste chainée
struct noeud {
	int valeur;
	noeud* suivant;
};



//classe Liste Chainée : permet de stocker des entiers dans une liste chainée
class liste_chainee {
private:
	noeud* m_debut; /*tête de la liste*/

public:
	liste_chainee(); /*constructeur par défaut*/
	liste_chainee(const liste_chainee& l); /*constructeur de recopie*/
	~liste_chainee(); /*destructeur*/
	int front(); /*retourne le premier élément de la liste*/
	int back(); /*retourne le dernier élément de la liste*/
	void push_front(int elt); /*ajoute un élément au début de la liste*/
	void push_back(int elt); /*ajoute un élément à la fin de la liste*/
	void pop_front(); /*supprime le premier élément de la liste*/
	void pop_back(); /*supprimer le dernier élement de la liste*/
	int size(); /*renvoie le nombre d’éléments stockés dans la liste*/
	void insert(int i, int elt); /*Le 1er élément de la liste (s'il existe) est à la position i = 1
								  Si la liste contient par exemple 3 éléments, il n'est pas possible d'ajouter un élément en position 4 :
								  il faut effectuer un push_back*/
	void erase(int i); /*supprime le ième élement de la liste*/
	bool empty(); /*renvoie vrai si la liste est vide, faux sinon*/
	void clear(); /*vide la liste*/
	void remove(int elt); /*supprime de la liste tous les éléments égaux à elt*/
	void sort(); /*trie la liste par ordre croissant*/
	liste_chainee& operator=(const liste_chainee& l); /*attribrue les valeurs d'une liste à une autre liste*/

	friend noeud* sep_list(noeud* debut); /*permet de séparer la liste chainée en 2 pour le merge sort : renvoie un pointeur
											vers la deuxième moitié de la liste*/
	friend noeud* merge(noeud* debut, noeud* fin); /*fusionne 2 listes chainées passées en paramètre*/
	friend noeud* merge_sort(noeud* debut); /*permet de trier récursivement des sous parties de la liste, puis de fusionner ces sous parties*/
	friend ostream& operator<<(ostream& f, const liste_chainee& l); /*affiche la liste*/
	friend liste_chainee operator+(const liste_chainee& l1, const liste_chainee& l2); /*concatène 2 listes*/
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
