#ifndef _ETUDIANT_HPP_
#define _ETUDIANT_HPP_

#include <iostream>
using namespace std;

struct Matiere {
    string nom;
    int coeff;
    float note;
};

class Etudiant // Classe permettant de manipuler des informations sur des étudiants
{
    private:
        string m_nom, m_prenom;
        int m_age, m_nbMatieres, m_nbMatieresMax;
        Matiere* m_listeMatieres;

    public:
        Etudiant();
        Etudiant(const Etudiant& e);
        Etudiant(string nom, string prenom, int age, int nbMatieresMax);
        void ajouterMatiere(string nom);
        void supprimerMatiere(string nom);
        void modifierNoteMatiere(string nom, float note);
        void modifierCoeffMatiere(string nom, int coeff);
        float calculMoyenneGenerale(void) const;
        void afficher(void) const;
        // accesseurs et mutateurs
        int existeMatiere(string nom) const;
};

#endif // _ETUDIANT_HPP_
