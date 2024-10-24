//impl�mentation de la classe Liste chain�e



//include gards
#ifndef _LISTE_CHAINEE_
#define _LISTE_CHAINEE_



//import libraries
#include <iostream>
#include <string>
using namespace std;



//d�finition du type noeud de la liste chain�e
struct noeud {
	int valeur;
	noeud* suivant;
};



//classe Liste Chain�e : permet de stocker des entiers
class liste_chainee {
private :
	noeud* m_debut;

public:
	liste_chainee();
	int front();
	int back();
	void push_front(int elt);
	void push_back(int elt);
	void pop_front();
	void pop_back();
	void insert(int i, int elt); /*exception si i n�gatif ou si moins de i �l�ment dans la liste*/
};



#endif // _LISTE_CHAINEE_
