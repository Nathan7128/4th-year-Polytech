class Administratif extends Personnel {
    float m_salaireMensuel = 0;
    float m_primes = 0;

    public Administratif() {
        super();
    };

    public Administratif(String m_nom, String m_adresse, String m_numeroBureau, float m_salaireMensuel,
                         float m_primes) {
        super(m_nom, m_adresse, m_numeroBureau);
        this.m_salaireMensuel = m_salaireMensuel;
        this.m_primes = m_primes;
    }

    public float getSalaireMensuel() {
        return m_salaireMensuel;
    }

    public void setSalaireMensuel(float nSalaire) {
        m_salaireMensuel = nSalaire;
    }

    public float getPrimes() {
        return m_primes;
    }

    public void setPrimes(float nPrimes) {
        this.m_primes = nPrimes;
    }

    @Override
    public float calculerSalaire() {
        return m_salaireMensuel + m_primes;
    }

    @Override
    public String afficher() {
        String affichage;
        affichage = "Personnel : " + m_nom + "\n" + "Adresse : " + m_adresse + "\n";
        affichage += "Numéro de bureau : " + m_numeroBureau + "\n";
        affichage += "Salaire mensuel : " + m_salaireMensuel + " €/mois\n";
        affichage += "Primes : " + m_primes + " €\n";
        affichage += "Salaire total : " + calculerSalaire() + " €";
        return affichage;
    }
}
