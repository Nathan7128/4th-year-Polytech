// prog.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "fraction.h"

int main()
{
    Fraction f1(-5, -11), f2(-1, 2);
    Fraction f3;
    cout << f1 << "\n\n";
    f1.simplifier();
    cout << f1 << "\n\n";
    f3 = f1 * f2;
    cout << f3 << "\n\n";
    cin >> f3;
    cout << f3 << "\n\n";
}