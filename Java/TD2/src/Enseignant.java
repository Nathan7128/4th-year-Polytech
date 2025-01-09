abstract class Enseignant extends Personnel {
    int m_numCasier = 0;

    public Enseignant() {
        super();
    }

    public Enseignant(String m_nom, String m_adresse, String m_numeroBureau, int m_numCasier) {
        super(m_nom, m_adresse, m_numeroBureau);
        this.m_numCasier = m_numCasier;
    }

    public int getNumCasier() {
        return m_numCasier;
    }

    public void setNumCasier(int m_numCasier) {
        this.m_numCasier = m_numCasier;
    }
}
