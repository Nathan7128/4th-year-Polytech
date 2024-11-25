#include <string>
#include "Fonctions.h"



int main()
{
    /*Initialisation du plateau*/
    Plateau* plateau = initPlateau();

    /*Initialisation du personnage*/
    Personnage* perso = initPerso();

    /*Initialisation du labyrinthe*/
    Labyrinthe labyrinthe = initLabyrinthe(plateau, perso);

    /*Variable permettant de stocker le choix effectuer par l'utilisateur pour le déplacement*/
    char choixDepl;
    
    /*Boucle qui s'arrête dès que la partie est terminée*/
    while (!labyrinthe.fini()) {
        /*Affichage du labyrinthe*/
        labyrinthe.afficher();

        /*Choix du déplacement par l'utilisateur*/
        cout << endl << "Quel deplacement ? Bas(B), Haut(H), Gauche(G), Droite(D) :" << endl;
        cin >> choixDepl;
        cout << endl;

        /*Déplacement du personnage en fonction de la direction choisie*/
        switch (choixDepl) {
        /*Déplacement vers le bas*/
        case 'B' :
            labyrinthe.deplacerPersoBas();
            break;

        /*Déplacement vers le haut*/
        case 'H' :
            labyrinthe.deplacerPersoHaut();
            break;

        /*Déplacement vers la gauche*/
        case 'G' :
            labyrinthe.deplacerPersoGauche();
            break;

        /*Déplacement vers la droite*/
        case 'D':
            labyrinthe.deplacerPersoDroite();
            break;

        /*Saisie de déplacement invalide*/
        default :
            cout << "Saisie invalide";
        }
    }

    /*Message de fin de la partie*/
    cout << "FELICITATIONS !";
}