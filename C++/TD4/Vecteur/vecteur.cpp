#include "vecteur.hpp"

Vecteur::Vecteur(int nbValeursMax) {
	m_listeValeurs = new float[nbValeursMax];
	m_nbValeursMax = nbValeursMax;
}

Vecteur::Vecteur(const Vecteur& v) {
	m_listeValeurs = new float(v.m_nbValeursMax);
	m_nbValeursMax = v.m_nbValeursMax;
}

Vecteur::~Vecteur() {
	delete[] m_listeValeurs;
}

Vecteur& Vecteur::operator=(const Vecteur& v) {
	if (this != &v) {
		m_listeValeurs = new float[v.m_nbValeursMax];
		m_nbValeursMax = v.m_nbValeursMax;
		for (int i = 0; i < v.m_nbValeursMax; i++) {
			m_listeValeurs[i] = v.m_listeValeurs[i];
		}
	}
	return *this;
}

float& Vecteur::operator[](int i) {
	return m_listeValeurs[i];
}

bool operator==(const Vecteur& v1, const Vecteur& v2) {
	bool egal = true;
	int i = 0;
	if (v1.m_nbValeursMax != v2.m_nbValeursMax) {
		egal = false;
	}
	while (i < v1.m_nbValeursMax && egal == true) {
		if (v1.m_listeValeurs[i] != v2.m_listeValeurs[i]) {
			egal = false;
		}
		i++;
	}
	return egal;
}

bool operator!=(const Vecteur& v1, const Vecteur& v2) {
	return !(v1 == v2);
}

ostream& operator<<(ostream& f, const Vecteur& v) {
	f << "(";
	for (int i = 0; i < v.m_nbValeursMax - 1; i++) {
		f << v.m_listeValeurs[i] << ", ";
	}
	f << v.m_listeValeurs[v.m_nbValeursMax - 1] << ")";
	return f;
}

istream& operator>>(istream& f, Vecteur& v) {
	for (int i = 0; i < v.m_nbValeursMax; i++) {
		cout << "Coord. " << i + 1 << " : ";
		f >> v.m_listeValeurs[i];
		cout << endl;
	}
	return f;
}

Vecteur operator+(const Vecteur& v1, const Vecteur& v2) {
	Vecteur v(v1.m_nbValeursMax);
	if (v1.m_nbValeursMax != v2.m_nbValeursMax) {
		v = v1;
	}
	else {
		for (int i = 0; i < v.m_nbValeursMax; i++) {
			v.m_listeValeurs[i] = v1.m_listeValeurs[i] + v2.m_listeValeurs[i];
		}
	}
	return v;
}

Vecteur operator-(const Vecteur& v1, const Vecteur& v2) {
	Vecteur v(v1.m_nbValeursMax);
	if (v1.m_nbValeursMax != v2.m_nbValeursMax) {
		v = v1;
	}
	else {
		for (int i = 0; i < v.m_nbValeursMax; i++) {
			v.m_listeValeurs[i] = v1.m_listeValeurs[i] - v2.m_listeValeurs[i];
		}
	}
	return v;
}

float operator*(const Vecteur& v1, const Vecteur& v2) {
	float produit = 0;
	if (v1.m_nbValeursMax != v2.m_nbValeursMax) {
		produit = 0;
	}
	else {
		for (int i = 0; i < v1.m_nbValeursMax; i++) {
			produit += v1.m_listeValeurs[i] * v2.m_listeValeurs[i];
		}
	}
	return produit;
}