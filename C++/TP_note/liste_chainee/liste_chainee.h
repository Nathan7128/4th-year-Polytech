//impl�mentation de la classe Liste chain�e



//chiens de garde
#ifndef _LISTE_CHAINEE_
#define _LISTE_CHAINEE_



//importation des biblioth�ques
#include <iostream>
#include <string>
using namespace std;



//d�finition du type noeud de la liste chain�e
struct noeud {
	int valeur;
	noeud* suivant;
};



//classe Liste Chain�e : permet de stocker des entiers dans une liste chain�e
class liste_chainee {
private:
	noeud* m_debut; /*t�te de la liste*/

public:
	liste_chainee(); /*constructeur par d�faut*/
	liste_chainee(const liste_chainee& l); /*constructeur de recopie*/
	~liste_chainee(); /*destructeur*/
	int front(); /*retourne le premier �l�ment de la liste*/
	int back(); /*retourne le dernier �l�ment de la liste*/
	void push_front(int elt); /*ajoute un �l�ment au d�but de la liste*/
	void push_back(int elt); /*ajoute un �l�ment � la fin de la liste*/
	void pop_front(); /*supprime le premier �l�ment de la liste*/
	void pop_back(); /*supprimer le dernier �lement de la liste*/
	int size(); /*renvoie le nombre d��l�ments stock�s dans la liste*/
	void insert(int i, int elt); /*Le 1er �l�ment de la liste (s'il existe) est � la position i = 1
								  Si la liste contient par exemple 3 �l�ments, il n'est pas possible d'ajouter un �l�ment en position 4 :
								  il faut effectuer un push_back*/
	void erase(int i); /*supprime le i�me �lement de la liste*/
	bool empty(); /*renvoie vrai si la liste est vide, faux sinon*/
	void clear(); /*vide la liste*/
	void remove(int elt); /*supprime de la liste tous les �l�ments �gaux � elt*/
	void sort(); /*trie la liste par ordre croissant*/
	liste_chainee& operator=(const liste_chainee& l); /*attribrue les valeurs d'une liste � une autre liste*/

	friend noeud* sep_list(noeud* debut); /*permet de s�parer la liste chain�e en 2 pour le merge sort : renvoie un pointeur
											vers la deuxi�me moiti� de la liste*/
	friend noeud* merge(noeud* debut, noeud* fin); /*fusionne 2 listes chain�es pass�es en param�tre*/
	friend noeud* merge_sort(noeud* debut); /*permet de trier r�cursivement des sous parties de la liste, puis de fusionner ces sous parties*/
	friend ostream& operator<<(ostream& f, const liste_chainee& l); /*affiche la liste*/
	friend liste_chainee operator+(const liste_chainee& l1, const liste_chainee& l2); /*concat�ne 2 listes*/
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



//m�thode permettant d'afficher le menu dans la fonction main
void affichage_menu();



#endif // _LISTE_CHAINEE_
