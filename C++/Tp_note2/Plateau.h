#ifndef _PLATEAU_H_
#define _PLATEAU_H_



#include "ObjetGraphiqueFixe.h"
#include "ObjetGraphiqueMobile.h"
#include "Couloir.h"



//Classe exception si le nombre de lignes ou de colonnes est n�gatif
class ExceptionTailleNeg {
public :
	string m_message; /*Message d�crivant l'erreur*/
	ExceptionTailleNeg(string m = "Erreur de saisie de taille du plateau") { m_message = m; };
};



class Plateau { /*Classe permettant de d�finir le plateau du jeu : il est compos� d'objet fixe : mur, couloir et sortie
				  A l'�tat initial, le plateau ne comprend que des couloirs*/
//D�finition des attributs prot�g�s
protected:
	int m_nbl; /*nombre de lignes du plateau*/
	int m_nbc; /*nombre de colonnes du plateau*/
	ObjetGraphiqueFixe*** m_plateau; /*Tableau � 2 dimensions de pointeurs vers des objets graphiques fixes : ce tableau correspond au plateau*/

//D�finition des m�thodes publiques
public:
	Plateau(int nbl = 0, int nbc = 0); /*Constructeur par d�faut*/
	Plateau(const Plateau& plat); /*Constructeur de recopie*/
	~Plateau(); /*Destructeur*/
	void setCase(int i, int j, ObjetGraphiqueFixe* o); /*D�finir le contenu d'une case du plateau*/
	ObjetGraphiqueFixe* getCase(int i, int j); /*Obtenir le contenu d'une case du plateau*/
	void afficher(); /*Affichage du plateau*/
	void afficher(ObjetGraphiqueMobile& p); /*Affichage du plateau en prenant en compte l'objet graphique mobile*/
	Plateau& operator=(const Plateau& plat); /*Surcharge de l'op�rateur =*/
};



#endif _PLATEAU_H_