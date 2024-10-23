//include gards
#ifndef _FRACTION_HPP_
#define _FRACTION_HPP_

//import libraries
#include <iostream>
#include <string>
using namespace std;


//class Fraction : permet de manipuler des fractions
class Fraction {
private :
	int m_numerateur; /*num�rateur de la fraction*/
	int m_denominateur; /*d�nominateur de la fraction*/

public :
	Fraction(int num = 0, int deno = 1); /*constructeur de la fraction*/
	int getNum(); /*renvoie le num�rateur de la fraction*/
	int getDeno(); /*renvoie le d�nominateur de la fraction*/
	void inverse(); /*renvoie l'inverse de la fraction*/
	void simplifier(); /*simplifie la fraction*/

	//fonctions amies
	friend int pgcd(int a, int b); /*renvoie le pgcd entre 2 nombres gr�ce � l'algorithme d'Euclide*/
	friend Fraction operator+(const Fraction& f1, const Fraction& f2); /*surcharge de l'op�rateur +*/
	friend bool operator==(const Fraction& f1, const Fraction& f2); /*surcharge de l'op�rateur ==*/
	friend bool operator!=(const Fraction& f1, const Fraction& f2); /*surcharge de l'op�rateur !=*/
};


#endif // _FRACTION_HPP_
 
