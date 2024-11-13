//définition des méthodes de la classe fraction



//importation des bibliothèques
#include "fraction.h"



Fraction::Fraction(int num, int deno) {
	if (deno != 0) {
		m_numerateur = num;
		m_denominateur = deno;
	}
	else {
		throw ExceptionDenoNul("Erreur d'initialisation : denominateur nul");
	}
}

int Fraction::getNum() {
	return m_numerateur;
}

int Fraction::getDeno() {
	return m_denominateur;
}

void Fraction::inverse() {
	if (m_numerateur != 0) {
		int temp = m_numerateur;
		m_numerateur = m_denominateur;
		m_denominateur = temp;
	}
	else {
		throw ExceptionDenoNul("Erreur d'inversion : impossible d'inverser une fraction nulle");
	}
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
	if (f2.m_numerateur != 0) {
		Fraction f(f1.m_numerateur * f2.m_denominateur, f2.m_numerateur * f1.m_denominateur);
		f.simplifier();
		return f;
	}
	else {
		throw ExceptionDivZero("Erreur de division : impossible de diviser par une fraction nulle");
	}
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

void affichage_menu() {
	cout << "Vous avez a votre disposition 10 fractions numerotees de 1 a 10" << "\n\n";
	cout << "0) arreter la saisie" << endl;
	cout << "1) Modifier une fraction" << endl;
	cout << "2) getNum : retourne le numerateur de la fraction" << endl;
	cout << "3) getDeno : retourne le denominateur de la fraction" << endl;
	cout << "4) inverse : inverse la fraction" << endl;
	cout << "5) simplifier : simplifie la fraction" << endl;
	cout << "6) + : additionne deux fractions" << endl;
	cout << "7) - : soustrait une fraction a une autre" << endl;
	cout << "8) * : mutliplie deux fractions" << endl;
	cout << "9) / : divise deux fractions" << endl;
	cout << "10) == : renvoie vrai si les deux fractions sont egales, faux sinon" << endl;
	cout << "11) != : renvoie vrai si les deux fractions sont differentes, faux sinon" << endl;
	cout << "12) < : renvoie vrai si la premiere fraction est strictement inferieure a la deuxieme, faux sinon" << endl;
	cout << "13) > : renvoie vrai si la premiere fraction est strictement superieure a la deuxieme, faux sinon" << endl;
	cout << "14) <= : renvoie vrai si la premiere fraction est inferieure a la deuxieme, faux sinon" << endl;
	cout << "15) >= : renvoie vrai si la premiere fraction est superieure a la deuxieme, faux sinon" << endl;
}