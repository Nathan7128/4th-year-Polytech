class Permanent extends Enseignant {
    float m_salaireMensuel = 0;
    float m_montantHeuresSup = 0;
    float m_primes = 0;

    public Permanent() {
        super();
    }

    public Permanent(String m_nom, String m_adresse, String m_numeroBureau, int m_numCasier,
                      float m_salaireMensuel, float m_montantHeuresSup, float m_primes) {
        super(m_nom, m_adresse, m_numeroBureau, m_numCasier);
        this.m_salaireMensuel = m_salaireMensuel;
        this.m_montantHeuresSup = m_montantHeuresSup;
    }

    public float getSalaireMensuel() {
        return m_salaireMensuel;
    }

    public void setSalaireMensuel(float m_salaireMensuel) {
        this.m_salaireMensuel = m_salaireMensuel;
    }

    public float getMontantHeuresSup() {
        return m_montantHeuresSup;
    }

    public void setMontantHeuresSup(float m_montantHeuresSup) {
        this.m_montantHeuresSup = m_montantHeuresSup;
    }

    public float getPrimes() {
        return m_primes;
    }

    public void setPrimes(float m_primes) {
        this.m_primes = m_primes;
    }

    @Override
    public float calculerSalaire() {
        return m_salaireMensuel + m_montantHeuresSup + m_primes;
    }

    @Override
    public String afficher() {
        String affichage;
        affichage = "Enseignant permanent : " + m_nom + "\n" + "Adresse : " + m_adresse + "\n";
        affichage += "Numéro de bureau : " + m_numeroBureau + "\n";
        affichage += "Numéro de casier : " + m_numCasier + "\n";
        affichage += "Salaire mensuel : " + m_salaireMensuel + " €/mois\n";
        affichage += "Montant des heures supplémentaires : " + m_montantHeuresSup + " €\n";
        affichage += "Primes : " + m_primes + " €\n";
        affichage += "Salaire total : " + calculerSalaire() + " €";
        return affichage;
    }
}
