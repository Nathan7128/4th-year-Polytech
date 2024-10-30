// main_fraction.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "fraction.h"

int main()
{
	try {
		Fraction f1(0, 5), f2(3, 0), f3;
		f3 = f2 / f1;
		cout << f3 << endl;
	}
	catch (ExceptionDenoNul& ex) {
		cerr << ex.m_message << endl;
	}
	catch (ExceptionDivZero& ex) {
		cerr << ex.m_message << endl;
	}
}