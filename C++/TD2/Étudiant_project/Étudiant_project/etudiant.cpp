#include "etudiant.hpp"


Etudiant::Etudiant() {
    m_nom = "Dupont";
    m_prenom = "Henri";
    m_age = 20;
    m_nbMatieresMax = 8;
    m_nbMatieres = 0;
    m_listeMatieres = new Matiere[m_nbMatieresMax];
}


Etudiant::Etudiant(const Etudiant& e) {
    m_nom = e.m_nom;
    m_prenom = e.m_prenom;
    m_age = e.m_age;
    m_nbMatieresMax = e.m_nbMatieresMax;
    m_nbMatieres = e.m_nbMatieres;
    m_listeMatieres = new Matiere[m_nbMatieresMax];
}


Etudiant::Etudiant(string nom, string prenom, int age, int nbMatieresMax) {
    m_nom = nom;
    m_prenom = prenom;
    m_age = age;
    m_nbMatieresMax = nbMatieresMax;
    m_nbMatieres = 0;
    m_listeMatieres = new Matiere[m_nbMatieresMax];
}


void Etudiant::ajouterMatiere(string nom) {
    if (m_nbMatieres >= m_nbMatieresMax) {
        cout << "Erreur : Nombre de matieres maximal atteint" << endl;
    }
    else if (existeMatiere(nom) != -1) {
        cout << "Erreur : Matiere deja ajoutee" << endl;
    }
    else {
        Matiere new_matiere = { nom, 0, 0 };
        m_listeMatieres[m_nbMatieres] = new_matiere;
        m_nbMatieres++;
    }
}


void Etudiant::supprimerMatiere(string nom) {
    int pos = existeMatiere(nom);
    if (pos != -1) {
        for (int j = pos; j < m_nbMatieres - 1; j++) {
            m_listeMatieres[j] = m_listeMatieres[j + 1];
        }
        m_nbMatieres--;
    }
}


void Etudiant::modifierNoteMatiere(string nom, float note) {
    int pos = existeMatiere(nom);
    if (pos != -1) {
        m_listeMatieres[pos].note = note;
    }
}


void Etudiant::modifierCoeffMatiere(string nom, int coeff) {
    int pos = existeMatiere(nom);
    if (pos != -1) {
        m_listeMatieres[pos].coeff = coeff;
    }
}


float Etudiant::calculMoyenneGenerale(void) const {
    float moy = 0;
    int coef = 0;
    if (m_nbMatieres == 0) {
        cout << "Erreur : 0 matiere pour cet etudiant" << endl;
        return 0;
    }
    else {
        for (int i = 0; i < m_nbMatieres; i++) {
            moy += m_listeMatieres[i].coeff * m_listeMatieres[i].note;
            coef += m_listeMatieres[i].coeff;
        }
        moy /= coef;
        return moy;
    }
}


void Etudiant::afficher(void) const {
    Matiere matiere;
    for (int i = 0; i < m_nbMatieres; i++) {
        matiere = m_listeMatieres[i];
        cout << matiere.nom << "\tNote : " << matiere.note << "\tCoeff : " << matiere.coeff << endl;
    }
}


int Etudiant::existeMatiere(string nom) const {
    int pos = -1, i = 0;
    while (i < m_nbMatieres && pos == -1) {
        if (m_listeMatieres[i].nom == nom) {
            pos = i;
        }
        i++;
    }
    return pos;
}