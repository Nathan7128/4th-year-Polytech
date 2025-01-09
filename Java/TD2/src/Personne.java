abstract class Personne {
    String m_nom = "Henri Dupont";
    String m_adresse = "2 rue de la Paix, Paris";

    public Personne() {}

    public Personne(String m_nom, String m_adresse) {
        this.m_nom = m_nom;
        this.m_adresse = m_adresse;
    }

    public String getNom() {
        return m_nom;
    }

    public String getAdresse() {
        return m_adresse;
    }

    public void setNom(String m_nom) {
        this.m_nom = m_nom;
    }

    public void setAdresse(String m_adresse) {
        this.m_adresse = m_adresse;
    }

    public abstract String afficher();
}
