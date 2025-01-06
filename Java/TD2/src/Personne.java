public class Personne {
    String m_nom;
    String m_adresse;

    public Personne(String m_nom, String m_adresse) {
        this.m_nom = m_nom;
        this.m_adresse = m_adresse;
    }

    public String getM_nom() {
        return m_nom;
    }

    public String getM_adresse() {
        return m_adresse;
    }

    public void setM_nom(String m_nom) {
        this.m_nom = m_nom;
    }

    public void setM_adresse(String m_adresse) {
        this.m_adresse = m_adresse;
    }

    public void afficher() {
        System.out.println("Nom : " + m_nom + "\nAdresse : " + m_adresse);
    }
}
