// Étudiant_project.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "etudiant.hpp"

int main()
{
    Etudiant etu1("Nathan", "Talbot", 20, 10);
    etu1.ajouterMatiere("Francais");
    etu1.modifierCoeffMatiere("Francais", 1);
    etu1.modifierNoteMatiere("Francais", 15);
    etu1.ajouterMatiere("Maths");
    etu1.modifierCoeffMatiere("Maths", 2);
    etu1.modifierNoteMatiere("Maths", 18);
    etu1.supprimerMatiere("Maths");
    etu1.afficher();
    etu1.supprimerMatiere("Maths");
    etu1.supprimerMatiere("Francais");
    etu1.afficher();
    cout << "Moyenne : " << etu1.calculMoyenneGenerale() << endl;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
