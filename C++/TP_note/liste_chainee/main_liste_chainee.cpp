// main_liste_chainee.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "liste_chainee.h"

int main()
{
	int choix_menu = 1, elt, index_elt;
	liste_chainee l1, tab_liste[15];
	tab_liste[0] = l1;
	bool continuer = true;
	affichage_menu();
	while (continuer) {
		cout << "Choisir option : ";
		cin >> choix_menu;
		switch (choix_menu) {
			case 1 :
				cout << l1.front() << endl;
				break;
			case 2:
				cout << l1.back() << endl;
				break;
			case 3:
				cout << "Saisir element : ";
				cin >> elt;
				l1.push_front(elt);
				break;
			case 4:
				cout << "Saisir element : ";
				cin >> elt;
				l1.push_back(elt);
				break;
			case 5:
				l1.pop_front();
				break;
			case 6:
				l1.pop_back();
				break;
			case 7:
				cout << "Saisir element : ";
				cin >> elt;
				cout << "Saisir index : ";
				cin >> index_elt;
				l1.insert(index_elt, elt);
				break;
			case 8:
				cout << "Saisir index : ";
				cin >> index_elt;
				l1.erase(index_elt);
				break;
			case 9:
				cout << "Taille de la liste : " << l1.size() << endl;
				break;
			case 10:
				cout << l1.empty() << endl;
				break;
			case 11:
				l1.clear();
				break;
			case 12:
				cout << "Saisir element : ";
				cin >> elt;
				l1.remove(elt);
				break;
			case 13:
				l1.sort();
				break;
			default :
				continuer = false;
				break;
			}
		cout << "Liste : " << l1 << endl;
		}
	}