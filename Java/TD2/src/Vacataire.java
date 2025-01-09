class Vacataire extends Enseignant {
    float m_tarifHoraire = 0;
    float m_nbHeures = 0;

    public Vacataire() {
        super();
    }

    public Vacataire(String m_nom, String m_adresse, String m_numeroBureau, int m_numCasier, float m_tarifHoraire,
                     float m_nbHeures) {
        super(m_nom, m_adresse, m_numeroBureau, m_numCasier);
        this.m_tarifHoraire = m_tarifHoraire;
        this.m_nbHeures = m_nbHeures;
    }

    public float getTarifHoraire() {
        return m_tarifHoraire;
    }

    public void setTarifHoraire(float m_tarifHoraire) {
        this.m_tarifHoraire = m_tarifHoraire;
    }

    public float getNbHeures() {
        return m_nbHeures;
    }

    public void setNbHeures(float m_nbHeures) {
        this.m_nbHeures = m_nbHeures;
    }

    @Override
    public float calculerSalaire() {
        return m_nbHeures*m_tarifHoraire;
    }

    @Override
    public String afficher() {
        String affichage;
        affichage = "Enseignant vacataire : " + m_nom + "\n" + "Adresse : " + m_adresse + "\n";
        affichage += "Numéro de bureau : " + m_numeroBureau + "\n";
        affichage += "Numéro de casier : " + m_numCasier + "\n";
        affichage += "Tarif horaire : " + m_tarifHoraire + " €/heure\n";
        affichage += "Nombre d'heures : " + m_nbHeures + "\n";
        affichage += "Salaire : " + calculerSalaire() + " €";
        return affichage;
    }
}
