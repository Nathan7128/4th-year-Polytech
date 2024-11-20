#include <string>
#include "Fonctions.h"



int main()
{
    Plateau* plateau = initPlateauV1();
    Personnage* perso = initPersoV1();
    Labyrinthe labyrinthe = initLabyrintheV1(plateau, perso);
    char choixDepl;
    
    while (!labyrinthe.fini()) {
        labyrinthe.afficher();
        cout << endl << "Quel deplacement ? Bas(B), Haut(H), Gauche(G), Droite(D) :" << endl;
        cin >> choixDepl;
        cout << endl;
        switch (choixDepl) {
        case 'B' :
            labyrinthe.deplacerPersoBas();
            break;
        case 'H' :
            labyrinthe.deplacerPersoHaut();
            break;
        case 'G' :
            labyrinthe.deplacerPersoGauche();
            break;
        case 'D':
            labyrinthe.deplacerPersoDroite();
            break;
        default :
            cout << "Saisie invalide";
        }
        cout << endl;
    }
    cout << "Felicitations !";
}