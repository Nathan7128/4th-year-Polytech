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

    /*Variable permettant de stocker le choix effectuer par l'utilisateur pour le d�placement*/
    char choixDepl;
    
    /*Boucle qui s'arr�te d�s que la partie est termin�e*/
    while (!labyrinthe.fini()) {
        /*Affichage du labyrinthe*/
        labyrinthe.afficher();

        /*Choix du d�placement par l'utilisateur*/
        cout << endl << "Quel deplacement ? Bas(B), Haut(H), Gauche(G), Droite(D) :" << endl;
        cin >> choixDepl;
        cout << endl;

        /*D�placement du personnage en fonction de la direction choisie*/
        switch (choixDepl) {
        /*D�placement vers le bas*/
        case 'B' :
            labyrinthe.deplacerPersoBas();
            break;

        /*D�placement vers le haut*/
        case 'H' :
            labyrinthe.deplacerPersoHaut();
            break;

        /*D�placement vers la gauche*/
        case 'G' :
            labyrinthe.deplacerPersoGauche();
            break;

        /*D�placement vers la droite*/
        case 'D':
            labyrinthe.deplacerPersoDroite();
            break;

        /*Saisie de d�placement invalide*/
        default :
            cout << "Saisie invalide";
        }
    }

    /*Message de fin de la partie*/
    cout << "FELICITATIONS !";
}