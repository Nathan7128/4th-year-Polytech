#include "fraction.h"

Fraction::Fraction(int num, int deno) {
	m_numerateur = num;
	m_denominateur = deno;
	//exception si dénominateur est nul
}

int Fraction::getNum() {
	return m_numerateur;
}

int Fraction::getDeno() {
	return m_denominateur;
}

void Fraction::inverse() {
	int temp = m_numerateur;
	m_numerateur = m_denominateur;
	m_denominateur = temp;
	//exception si numérateur est nul
}

int pgcd(int a, int b) {
	int r = b;
	while (a % b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return r;
}

void Fraction::simplifier() {
	int vpgcd = pgcd(m_numerateur, m_denominateur);
	m_numerateur /= vpgcd;
	m_denominateur /= vpgcd;
	if (m_denominateur < 0) {
		m_denominateur *= -1;
		m_numerateur *= -1;
	}
}

Fraction operator+(const Fraction& f1, const Fraction& f2) {
	int deno_commun, somme_num;
	deno_commun = f1.m_denominateur * f2.m_denominateur;
	somme_num = f1.m_numerateur * f2.m_denominateur + f2.m_numerateur * f1.m_denominateur;
	Fraction f(somme_num, deno_commun);
	f.simplifier();
	return f;
}

Fraction operator-(const Fraction& f1, const Fraction& f2) {
	int deno_commun, soustr_num;
	deno_commun = f1.m_denominateur * f2.m_denominateur;
	soustr_num = f1.m_numerateur * f2.m_denominateur - f2.m_numerateur * f1.m_denominateur;
	Fraction f(soustr_num, deno_commun);
	f.simplifier();
	return f;
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {
	Fraction f(f1.m_numerateur * f2.m_numerateur, f1.m_denominateur * f2.m_denominateur);
	f.simplifier();
	return f;
}

Fraction operator/(const Fraction& f1, const Fraction& f2) {
	Fraction f(f1.m_numerateur * f2.m_denominateur, f2.m_numerateur * f1.m_denominateur);
	f.simplifier();
	return f;
}

bool operator==(const Fraction& f1, const Fraction& f2) {
	Fraction f1_simp = f1, f2_simp = f2;
	f1_simp.simplifier();
	f2_simp.simplifier();
	return (f1_simp.m_numerateur == f2_simp.m_numerateur and f1_simp.m_denominateur == f2_simp.m_denominateur);
}

bool operator!=(const Fraction& f1, const Fraction& f2) {
	return !(f1 == f2);
}

bool operator<(const Fraction& f1, const Fraction& f2) {
	return (f1.m_numerateur * f2.m_denominateur < f2.m_numerateur * f1.m_denominateur);
}

bool operator>(const Fraction& f1, const Fraction& f2) {
	return (f1.m_numerateur * f2.m_denominateur > f2.m_numerateur * f1.m_denominateur);
}

bool operator<=(const Fraction& f1, const Fraction& f2) {
	return (f1 == f2 or f1 < f2);
}

bool operator>=(const Fraction& f1, const Fraction& f2) {
	return (f1 == f2 or f1 > f2);
}

ostream& operator<<(ostream& f, const Fraction& frac) {
	if (frac.m_numerateur == 0 or frac.m_denominateur == 1) {
		f << frac.m_numerateur;
	}
	else {
		f << frac.m_numerateur << " / " << frac.m_denominateur;
	}
	return f;
}

istream& operator>>(istream& f, Fraction& frac) {
	cout << "Numerateur : ";
	f >> frac.m_numerateur;
	cout << "Denominateur : ";
	f >> frac.m_denominateur;
	return f;
}