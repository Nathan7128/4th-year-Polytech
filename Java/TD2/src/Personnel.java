abstract class Personnel extends Personne {
    String m_numeroBureau = "A207";

    public Personnel() {
        super();
    }

    public Personnel(String m_nom, String m_adresse, String m_numeroBureau) {
        super(m_nom, m_adresse);
        this.m_numeroBureau = m_numeroBureau;
    }

    public String getNumeroBureau() {
        return m_numeroBureau;
    }

    public void setNumeroBureau(String m_numeroBureau) {
        this.m_numeroBureau = m_numeroBureau;
    }

    public abstract float calculerSalaire();
}
