// main_fraction.cpp : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.
//

#include "fraction.h"

int main()
{
	//d�claration des variables
	int choix_menu = 1, choix_fraction1 = -1, choix_fraction2 = -1, choix_fraction_res = -1;
	Fraction tab_fraction[11] = {Fraction()};
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

			//choix de la fraction � manipuler
			if (choix_menu != 0) {
				while (choix_fraction1 < 1 or choix_fraction1 > 10) {
					cout << "Choisir fraction a manipuler (entre 1 et 10) : ";
					cin >> choix_fraction1;
				}
			}

			//�x�cution du choix
			switch (choix_menu) {
			//modication fraction
			case 1:
				cin >> tab_fraction[choix_fraction1 - 1];
				break;

			//m�thode getNum
			case 2:
				cout << tab_fraction[choix_fraction1 - 1].getNum() << endl;
				break;

			//m�thode getDeno
			case 3:
				tab_fraction[choix_fraction1 - 1].getDeno();
				break;

			//m�thode inverse
			case 4:
				tab_fraction[choix_fraction1 - 1].inverse();
				break;

			//m�thode simplifier
			case 5:
				tab_fraction[choix_fraction1 - 1].simplifier();
				break;

			//m�thode +
			case 6:
				while (choix_fraction2 < 1 or choix_fraction2 > 10) {
					cout << "Choisir fraction a additionner (entre 1 et 10) : ";
					cin >> choix_fraction2;
				}
				while (choix_fraction_res < 1 or choix_fraction_res > 11) {
					cout << "A quelle fraction attribuer le resultat ? (entre 1 et 10, saisir 11 pour ne pas attribuer la concatenation a une fraction) : ";
					cin >> choix_fraction_res;
				}
				tab_fraction[choix_fraction_res - 1] = tab_fraction[choix_fraction1 - 1] + tab_fraction[choix_fraction2 - 1];
				choix_fraction1 = choix_fraction_res;
				break;

			//m�thode -
			case 7:
				while (choix_fraction2 < 1 or choix_fraction2 > 10) {
					cout << "Choisir fraction a soustraire (entre 1 et 10) : ";
					cin >> choix_fraction2;
				}
				while (choix_fraction_res < 1 or choix_fraction_res > 11) {
					cout << "A quelle fraction attribuer le resultat ? (entre 1 et 10, saisir 11 pour ne pas attribuer la concatenation a une fraction) : ";
					cin >> choix_fraction_res;
				}
				tab_fraction[choix_fraction_res - 1] = tab_fraction[choix_fraction1 - 1] - tab_fraction[choix_fraction2 - 1];
				choix_fraction1 = choix_fraction_res;
				break;

			//m�thode *
			case 8:
				while (choix_fraction2 < 1 or choix_fraction2 > 10) {
					cout << "Choisir fraction a mutliplier (entre 1 et 10) : ";
					cin >> choix_fraction2;
				}
				while (choix_fraction_res < 1 or choix_fraction_res > 11) {
					cout << "A quelle fraction attribuer le resultat ? (entre 1 et 10, saisir 11 pour ne pas attribuer la concatenation a une fraction) : ";
					cin >> choix_fraction_res;
				}
				tab_fraction[choix_fraction_res - 1] = tab_fraction[choix_fraction1 - 1] * tab_fraction[choix_fraction2 - 1];
				choix_fraction1 = choix_fraction_res;
				break;

			//m�thode /
			case 9:
				while (choix_fraction2 < 1 or choix_fraction2 > 10) {
					cout << "Choisir fraction a diviser (entre 1 et 10) : ";
					cin >> choix_fraction2;
				}
				while (choix_fraction_res < 1 or choix_fraction_res > 11) {
					cout << "A quelle fraction attribuer le resultat ? (entre 1 et 10, saisir 11 pour ne pas attribuer la concatenation a une fraction) : ";
					cin >> choix_fraction_res;
				}
				tab_fraction[choix_fraction_res - 1] = tab_fraction[choix_fraction1 - 1] / tab_fraction[choix_fraction2 - 1];
				choix_fraction1 = choix_fraction_res;
				break;

			//m�thode ==
			case 10:
				while (choix_fraction2 < 1 or choix_fraction2 > 10) {
					cout << "Choisir fraction a comparer (entre 1 et 10) : ";
					cin >> choix_fraction2;
				}
				cout << (tab_fraction[choix_fraction1 - 1] == tab_fraction[choix_fraction1 - 2]) << endl;
				break;

			//m�thode !=
			case 11:
				while (choix_fraction2 < 1 or choix_fraction2 > 10) {
					cout << "Choisir fraction a comparer (entre 1 et 10) : ";
					cin >> choix_fraction2;
				}
				cout << (tab_fraction[choix_fraction1 - 1] != tab_fraction[choix_fraction1 - 2]) << endl;
				break;

			//m�thode <
			case 12:
				while (choix_fraction2 < 1 or choix_fraction2 > 10) {
					cout << "Choisir fraction a comparer (entre 1 et 10) : ";
					cin >> choix_fraction2;
				}
				cout << (tab_fraction[choix_fraction1 - 1] < tab_fraction[choix_fraction1 - 2]) << endl;
				break;

			//m�thode >
			case 13:
				while (choix_fraction2 < 1 or choix_fraction2 > 10) {
					cout << "Choisir fraction a comparer (entre 1 et 10) : ";
					cin >> choix_fraction2;
				}
				cout << (tab_fraction[choix_fraction1 - 1] > tab_fraction[choix_fraction1 - 2]) << endl;
				break;

			//m�thode <=
			case 14:
				while (choix_fraction2 < 1 or choix_fraction2 > 10) {
					cout << "Choisir fraction a comparer (entre 1 et 10) : ";
					cin >> choix_fraction2;
				}
				cout << (tab_fraction[choix_fraction1 - 1] <= tab_fraction[choix_fraction1 - 2]) << endl;
				break;

			//m�thode >=
			case 15:
				while (choix_fraction2 < 1 or choix_fraction2 > 10) {
					cout << "Choisir fraction a comparer (entre 1 et 10) : ";
					cin >> choix_fraction2;
				}
				cout << (tab_fraction[choix_fraction1 - 1] >= tab_fraction[choix_fraction1 - 2]) << endl;
				break;

			//arr�t du programme
			default:
				continuer = false;
				break;
			}

			//affichage de la fraction
			cout << "fraction : " << tab_fraction[choix_fraction1 - 1] << endl;

			//r�initialisation des choix de fraction
			choix_fraction1 = -1;
			choix_fraction2 = -1;
			choix_fraction_res = -1;
		}
	}
	catch (ExceptionDenoNul& ex) {
		cerr << ex.m_message << endl;
	}
	catch (ExceptionDivZero& ex) {
		cerr << ex.m_message << endl;
	}
}