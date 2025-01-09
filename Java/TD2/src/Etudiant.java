class Etudiant extends Personne {
    float m_moyenne = 0;

    public Etudiant() {
        super();
    }

    public Etudiant(String m_nom, String m_adresse, float m_moyenne) {
        super(m_nom, m_adresse);
        this.m_moyenne = m_moyenne;
    }

    public float getMoyenne() {
        return m_moyenne;
    }

    public void setMoyenne(float m_moyenne) {
        this.m_moyenne = m_moyenne;
    }

    @Override
    public String afficher() {
        String affichage;
        affichage = "Élève : " + m_nom + "\n" + "Adresse : " + m_adresse + "\n";
        affichage += "Moyenne : " + m_moyenne;
        return affichage;
    }
}
