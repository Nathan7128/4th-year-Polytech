// prog.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "fraction.h"

int main()
{
    Fraction f1(2, 3), f2(5, 11);
    Fraction f3;
    f3 = f1 + f2;
    cout << f3.getNum() << "/" << f3.getDeno() << "\n\n";
}