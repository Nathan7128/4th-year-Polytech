// main_fraction.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "fraction.h"

int main()
{
	//déclaration des variables
	int choix_menu = 1, choix_fraction1 = -1, choix_fraction2 = -1, choix_fraction_res = -1;
	Fraction tab_fraction[11] = {Fraction()};
	bool continuer = true;

	//affichage du menu
	affichage_menu();

	//gestion des exceptions
	try {
		//choix de du menu et éxécution du choix
		while (continuer) {
			//affichage démarquation
			cout << "----------------------------------------------------------------------------------------------------------------------\n\n";

			//choix de l'option
			cout << "Choisir option : ";
			cin >> choix_menu;

			//choix de la fraction à manipuler
			if (choix_menu != 0) {
				while (choix_fraction1 < 1 or choix_fraction1 > 10) {
					cout << "Choisir fraction a manipuler (entre 1 et 10) : ";
					cin >> choix_fraction1;
				}
			}

			//éxécution du choix
			switch (choix_menu) {
			//modication fraction
			case 1:
				cin >> tab_fraction[choix_fraction1 - 1];
				break;

			//méthode getNum
			case 2:
				cout << tab_fraction[choix_fraction1 - 1].getNum() << endl;
				break;

			//méthode getDeno
			case 3:
				tab_fraction[choix_fraction1 - 1].getDeno();
				break;

			//méthode inverse
			case 4:
				tab_fraction[choix_fraction1 - 1].inverse();
				break;

			//méthode simplifier
			case 5:
				tab_fraction[choix_fraction1 - 1].simplifier();
				break;

			//méthode +
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

			//méthode -
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

			//méthode *
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

			//méthode /
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

			//méthode ==
			case 10:
				while (choix_fraction2 < 1 or choix_fraction2 > 10) {
					cout << "Choisir fraction a comparer (entre 1 et 10) : ";
					cin >> choix_fraction2;
				}
				cout << (tab_fraction[choix_fraction1 - 1] == tab_fraction[choix_fraction1 - 2]) << endl;
				break;

			//méthode !=
			case 11:
				while (choix_fraction2 < 1 or choix_fraction2 > 10) {
					cout << "Choisir fraction a comparer (entre 1 et 10) : ";
					cin >> choix_fraction2;
				}
				cout << (tab_fraction[choix_fraction1 - 1] != tab_fraction[choix_fraction1 - 2]) << endl;
				break;

			//méthode <
			case 12:
				while (choix_fraction2 < 1 or choix_fraction2 > 10) {
					cout << "Choisir fraction a comparer (entre 1 et 10) : ";
					cin >> choix_fraction2;
				}
				cout << (tab_fraction[choix_fraction1 - 1] < tab_fraction[choix_fraction1 - 2]) << endl;
				break;

			//méthode >
			case 13:
				while (choix_fraction2 < 1 or choix_fraction2 > 10) {
					cout << "Choisir fraction a comparer (entre 1 et 10) : ";
					cin >> choix_fraction2;
				}
				cout << (tab_fraction[choix_fraction1 - 1] > tab_fraction[choix_fraction1 - 2]) << endl;
				break;

			//méthode <=
			case 14:
				while (choix_fraction2 < 1 or choix_fraction2 > 10) {
					cout << "Choisir fraction a comparer (entre 1 et 10) : ";
					cin >> choix_fraction2;
				}
				cout << (tab_fraction[choix_fraction1 - 1] <= tab_fraction[choix_fraction1 - 2]) << endl;
				break;

			//méthode >=
			case 15:
				while (choix_fraction2 < 1 or choix_fraction2 > 10) {
					cout << "Choisir fraction a comparer (entre 1 et 10) : ";
					cin >> choix_fraction2;
				}
				cout << (tab_fraction[choix_fraction1 - 1] >= tab_fraction[choix_fraction1 - 2]) << endl;
				break;

			//arrêt du programme
			default:
				continuer = false;
				break;
			}

			//affichage de la fraction
			cout << "fraction : " << tab_fraction[choix_fraction1 - 1] << endl;

			//réinitialisation des choix de fraction
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