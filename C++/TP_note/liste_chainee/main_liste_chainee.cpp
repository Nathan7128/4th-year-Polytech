// main_liste_chainee.cpp : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.
//

#include "liste_chainee.h"

int main()
{
	//d�claration des variables
	int choix_menu = 1, elt, index_elt, choix_liste1 = -1, choix_liste2 = -1, choix_liste_add = -1;
	liste_chainee tab_liste[11] = {liste_chainee()};
	bool continuer = true;

	//affichage du menu
	affichage_menu();

	//gestion des exceptions
	try {
		//choix de du menu et �x�cution du choix
		while (continuer) {
			//affichage d�marquation
			cout << "----------------------------------------------------------------------------------------------------------------------\n\n";

			//choix de l'option
			cout << "Choisir option : ";
			cin >> choix_menu;

			//choix de la liste � manipuler
			if (choix_menu != 0) {
				while (choix_liste1 < 1 or choix_liste1 > 10) {
					cout << "Choisir liste a manipuler (entre 1 et 10) : ";
					cin >> choix_liste1;
				}
			}

			//�x�cution du choix
			switch (choix_menu) {
			//m�thode front
			case 1:
				cout << tab_liste[choix_liste1 - 1].front() << endl;
				break;

			//m�thode back
			case 2:
				cout << tab_liste[choix_liste1 - 1].back() << endl;
				break;

			//m�thode push_front
			case 3:
				cout << "Saisir element : ";
				cin >> elt;
				tab_liste[choix_liste1 - 1].push_front(elt);
				break;

			//m�thode push_back
			case 4:
				cout << "Saisir element : ";
				cin >> elt;
				tab_liste[choix_liste1 - 1].push_back(elt);
				break;

			//m�thode pop_front
			case 5:
				tab_liste[choix_liste1 - 1].pop_front();
				break;

			//m�thode pop_back
			case 6:
				tab_liste[choix_liste1 - 1].pop_back();
				break;

			//m�thode insert
			case 7:
				cout << "Saisir element : ";
				cin >> elt;
				cout << "Saisir index : ";
				cin >> index_elt;
				tab_liste[choix_liste1 - 1].insert(index_elt, elt);
				break;

			//m�thode erase
			case 8:
				cout << "Saisir index : ";
				cin >> index_elt;
				tab_liste[choix_liste1 - 1].erase(index_elt);
				break;

			//m�thode size
			case 9:
				cout << "Taille de la liste : " << tab_liste[choix_liste1 - 1].size() << endl;
				break;

			//m�thode empty
			case 10:
				cout << tab_liste[choix_liste1 - 1].empty() << endl;
				break;

			//m�thode clear
			case 11:
				tab_liste[choix_liste1 - 1].clear();
				break;

			//m�thode remove
			case 12:
				cout << "Saisir element : ";
				cin >> elt;
				tab_liste[choix_liste1 - 1].remove(elt);
				break;

			//m�thode sort
			case 13:
				tab_liste[choix_liste1 - 1].sort();
				break;

			//m�thode =
			case 14:
				while (choix_liste2 < 1 or choix_liste2 > 10) {
					cout << "Choisir liste a attribuer a la liste actuelle (entre 1 et 10) : ";
					cin >> choix_liste2;
				}
				tab_liste[choix_liste1 - 1] = tab_liste[choix_liste2 - 1];
				break;

			//m�thode +
			case 15:
				while (choix_liste2 < 1 or choix_liste2 > 10) {
					cout << "Choisir liste a additionner (entre 1 et 10) : ";
					cin >> choix_liste2;
				}
				while (choix_liste_add < 1 or choix_liste_add > 11) {
					cout << "A quelle liste attribuer le resultat ? (entre 1 et 10, saisir 11 pour ne pas attribuer la concatenation a une liste) : ";
					cin >> choix_liste_add;
				}
				tab_liste[choix_liste_add - 1] = tab_liste[choix_liste1 - 1] + tab_liste[choix_liste2 - 1];
				choix_liste1 = choix_liste_add;
				break;

			//arr�t du programme
			default:
				continuer = false;
				break;
			}

			//affichage de la liste
			cout << "Liste : " << tab_liste[choix_liste1 - 1] << endl;

			//r�initialisation des choix de liste
			choix_liste1 = -1;
			choix_liste2 = -1;
			choix_liste_add = -1;
		}
	}
	catch (ExceptionListeVide& ex) {
		cout << endl << ex.m_message << endl;
	}
	catch (ExceptionIndex& ex) {
		cout << endl << ex.m_message << endl;
		cout << "index plantage : " << ex.m_index << endl;
	}
}