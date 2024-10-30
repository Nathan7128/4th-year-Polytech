// main_liste_chainee.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "liste_chainee.h"

int main()
{
	int choix_menu = 1;
	liste_chainee l1;
	while (choix_menu > 0 and choix_menu < 14) {
		affichage_menu();
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
				cin << 
			}
		}
		cout << l1 << endl;
	}
}