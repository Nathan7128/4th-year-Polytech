// main_td5.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "personne.h"
#include "personnel.h"
#include "etudiant.h"
#include "administratif.h"

int main()
{
    //Personne p1("Nathan Talbot", "2 Place du Champgil");
    //p1.afficher();
    //cout << p1.getAdresse() << endl;
    //cout << p1.getNom() << endl;
    //p1.setNom("Talbot Nathan");
    //p1.setAdresse("7 Les bruyeres");
    //p1.afficher();

    //Etudiant e1("Nathan Talbot", "2 Place du Champgil", 15);
    //e1.afficher();
    //cout << e1.getAdresse() << endl;
    //cout << e1.getNom() << endl;
    //cout << e1.getMoyenne() << endl;
    //e1.setNom("Talbot Nathan");
    //e1.setAdresse("7 Les bruyeres");
    //e1.setMoyenne(20);
    //e1.afficher();

    Administratif a1("Nathan Talbot", "2 Place du Champgil", "A207", 1500.3, 300.5);
    a1.afficher();
    cout << a1.getNom() << endl;
    cout << a1.getAdresse() << endl;
    cout << a1.getNumeroBureau() << endl;
    cout << a1.getSalaireMensuel() << endl;
    cout << a1.getPrimes() << endl;
    cout << a1.calculerSalaire() << endl;
    a1.setNom("Talbot Nathan");
    a1.setAdresse("7 Les bruyeres");
    a1.setNumeroBureau("A208");
    a1.setSalaireMensuel(1800);
    a1.setPrimes(1000);
    a1.afficher();
}
