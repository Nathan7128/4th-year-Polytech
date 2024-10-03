#include "vecteurs.hpp"
#include "fonctions.cpp"

int main() {
int t ;
int** ptr_t ;
cout << "Taille : " ;
cin >> t ;

//int* ptr_t = allocVecteur(t) ;
//lireVecteur(ptr_t, t) ;
//afficherVecteur(ptr_t, t) ;

allocVecteur(ptr_t, t) ;
cout << "ok" ;
lireVecteur(*ptr_t, t) ;
afficherVecteur(*ptr_t, t) ;
libereVecteur(ptr_t) ;
afficherVecteur(*ptr_t, t) ;

return 0 ;
}
