#include "vecteurs.hpp"

int* allocVecteur(int t) {
int* point = new int[t] ;
return point ;
}

void allocVecteur(int **V, int t){
*V = new int[t] ;
}

void libereVecteur(int **V){
delete[] *V ;
}

void lireVecteur(int *V, int t){
for (int i = 0; i < t; i++){
    cout << "Valeur " << i + 1 << " : " ;
    cin >> *(V + i);
}
}

void afficherVecteur(int *V, int t){
for (int i = 0; i < t; i++){
    cout << "Valeur " << i + 1 << " : " << *(V + i) << endl ;
}
}
