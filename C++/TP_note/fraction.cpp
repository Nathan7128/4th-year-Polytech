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
}

Fraction operator+(const Fraction& f1, const Fraction& f2) {
	int deno_commun, somme_num;
	deno_commun = f1.m_denominateur * f2.m_denominateur;
	somme_num = f1.m_numerateur * f2.m_denominateur + f2.m_numerateur * f1.m_denominateur;
	Fraction f(somme_num, deno_commun);
	f.simplifier();
	return f;
}

bool operator==(const Fraction& f1, const Fraction& f2) {
	Fraction f1_simp = f1, f2_simp = f2;
	f1_simp.simplifier();
	f2_simp.simplifier();
	if (f1_simp.m_numerateur == f2_simp.m_numerateur && f1_simp.m_denominateur == f2_simp.m_denominateur) {
		return true;
	}
	else {
		return false;
	}
}

bool operator!=(const Fraction& f1, const Fraction& f2) {
	return !(f1 == f2);
}

