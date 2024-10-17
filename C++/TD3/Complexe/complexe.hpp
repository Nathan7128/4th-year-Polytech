#ifndef _COMPLEXE_HPP_
#define _COMPLEXE_HPP_

#include <iostream>
#include <string>
#include <cmath>


using namespace std;

class Complexe
{
private :
	float m_pReelle, m_pImaginaire;

public :
	Complexe(float re = 0.0, float im = 0.0);
	float module() const;
	Complexe conjugue() const;

	friend bool operator==(const Complexe& c1, const Complexe& c2);
	friend bool operator!=(const Complexe& c1, const Complexe& c2);
	friend ostream& operator<<(ostream& f, const Complexe& c);
	friend istream& operator>>(istream& f, Complexe& c);
	friend Complexe operator+(const Complexe& c1, const Complexe& c2);
	friend Complexe operator-(const Complexe& c1, const Complexe& c2);
	friend Complexe operator*(const Complexe& c1, const Complexe& c2);
};

#endif _COMPLEXE_HPP_