public class Personnel extends Personne {
    String m_numeroBureau;

    public Personnel(String m_nom, String m_adresse, String m_numeroBureau) {
        super(m_nom, m_adresse);
        this.m_numeroBureau = m_numeroBureau;
    }

    public String getM_numeroBureau() {
        return m_numeroBureau;
    }

    public void setM_numeroBureau(String m_numeroBureau) {
        this.m_numeroBureau = m_numeroBureau;
    }
}
