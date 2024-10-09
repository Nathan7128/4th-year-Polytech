#include "complexe.hpp"

Complexe::Complexe() {
	m_pImaginaire = 0;
	m_pReelle = 0;
}

Complexe::Complexe(float re, float im) {
	m_pImaginaire = re;
	m_pReelle = im;
}

float Complexe::module() const {
	return sqrt(m_pImaginaire*m_pImaginaire + m_pReelle*m_pReelle);
}

Complexe Complexe::conjugue() const {
	Complexe c(m_pReelle,-m_pImaginaire);
	return c;
}

bool operator==(const Complexe& c1, const Complexe& c2) {
	if (c1.m_pImaginaire != c2.m_pImaginaire || c1.m_pReelle != c2.m_pReelle) {
		return false;
	}
	else {
		return true;
	}
}