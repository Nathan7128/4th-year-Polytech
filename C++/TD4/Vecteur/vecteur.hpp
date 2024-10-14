#ifndef _VECTEUR_HPP_
#define _VECTEUR_HPP_

#include <iostream>
#include <string>
using namespace std;

class Vecteur
{
private :
	float* m_listeValeurs;
	int m_nbValeursMax;

public :
	Vecteur(int nbValeursMax = 3);
	Vecteur(const Vecteur& v);
	~Vecteur();

	Vecteur& operator=(const Vecteur& e);
	float& operator[](int i);
	friend bool operator==(const Vecteur& v1, const Vecteur& v2);
	friend bool operator!=(const Vecteur& v1, const Vecteur& v2);
	friend ostream& operator<<(ostream& f, const Vecteur& v);
	friend istream& operator>>(istream& f, Vecteur& v);
	friend Vecteur operator+(const Vecteur& v1, const Vecteur& v2);
	friend Vecteur operator-(const Vecteur& v1, const Vecteur& v2);
	friend float operator*(const Vecteur& v1, const Vecteur& v2);
}


#endif