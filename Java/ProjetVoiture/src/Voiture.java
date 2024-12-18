public class Voiture {
//    Attributs
    private String numImmatriculation = "CL-328-TB";
    private String couleur = "Noir";
    private String modele = "Peugeot 207";
    private int nbPortes = 3;
    private int puissance = 90;
    private int anneeMiseEnCirculation = 2004;
    private String nomClient = "Nathan Talbot";
    private String dateDebutLocation = "01/01/2024";
    private String dateFinLocation = "En cours";

//    Méthodes
    public Voiture() {
    }

    public Voiture(String numImmatriculation, String couleur, String modele, int nbPortes, int puissance,
                   int anneeMiseEnCirculation) {
        this.numImmatriculation = numImmatriculation;
        this.couleur = couleur;
        this.modele = modele;
        this.nbPortes = nbPortes;
        this.puissance = puissance;
        this.anneeMiseEnCirculation = anneeMiseEnCirculation;
    }

    public String getNumImmatriculation() {
        return numImmatriculation;
    }

    public String getCouleur() {
        return couleur;
    }

    public String getModele() {
        return modele;
    }

    public int getNbPortes() {
        return nbPortes;
    }

    public int getPuissance() {
        return puissance;
    }

    public int getAnneeMiseEnCirculation() {
        return anneeMiseEnCirculation;
    }

    public String getNomClient() {
        return nomClient;
    }

    public String getDateDebutLocation() {
        return dateDebutLocation;
    }

    public String getDateFinLocation() {
        return dateFinLocation;
    }

    public void setNumImmatriculation(String numImmatriculation) {
        this.numImmatriculation = numImmatriculation;
    }

    public void setCouleur(String couleur) {
        this.couleur = couleur;
    }

    public void setModele(String modele) {
        this.modele = modele;
    }

    public void setNbPortes(int nbPortes) {
        this.nbPortes = nbPortes;
    }

    public void setPuissance(int puissance) {
        this.puissance = puissance;
    }

    public void setAnneeMiseEnCirculation(int anneeMiseEnCirculation) {
        this.anneeMiseEnCirculation = anneeMiseEnCirculation;
    }

    public void setNomClient(String nomClient) {
        this.nomClient = nomClient;
    }

    public void setDateDebutLocation(String dateDebutLocation) {
        this.dateDebutLocation = dateDebutLocation;
    }

    public void setDateFinLocation(String dateFinLocation) {
        this.dateFinLocation = dateFinLocation;
    }

    public void affiche() {
        System.out.println("Numéro d'immatriculation : " + getNumImmatriculation());
        System.out.println("Couleur : " + getCouleur());
        System.out.println("Modèle : " + getModele());
        System.out.println("Nombre de portes : " + getNbPortes());
        System.out.println("Puissance : " + getPuissance());
        System.out.println("Année de mise en circulation : " + getAnneeMiseEnCirculation());
        System.out.println("Nom du client : " + getNomClient());
        System.out.println("Date du début de la location : " + getDateDebutLocation());
        System.out.println("Date de la fin de la location : " + getDateFinLocation());
    }
}
