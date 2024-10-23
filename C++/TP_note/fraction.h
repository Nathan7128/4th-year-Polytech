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
	int m_numerateur; /*numérateur de la fraction*/
	int m_denominateur; /*dénominateur de la fraction*/

public :
	Fraction(int num = 0, int deno = 1); /*constructeur de la fraction*/
	int getNum(); /*renvoie le numérateur de la fraction*/
	int getDeno(); /*renvoie le dénominateur de la fraction*/
	void inverse(); /*renvoie l'inverse de la fraction*/
	void simplifier(); /*simplifie la fraction*/

	//fonctions amies
	friend int pgcd(int a, int b); /*renvoie le pgcd entre 2 nombres grâce à l'algorithme d'Euclide*/
	friend Fraction operator+(const Fraction& f1, const Fraction& f2); /*surcharge de l'opérateur +*/
	friend bool operator==(const Fraction& f1, const Fraction& f2); /*surcharge de l'opérateur ==*/
	friend bool operator!=(const Fraction& f1, const Fraction& f2); /*surcharge de l'opérateur !=*/
};


#endif // _FRACTION_HPP_
 
