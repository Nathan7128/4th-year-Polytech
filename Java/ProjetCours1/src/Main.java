import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner lectureClavier = new Scanner(System.in);
        System.out.print("Saisir le nombre de lignes : ");
        int nbLignes = lectureClavier.nextInt();
        System.out.print("Saisir le nombre de colonnes : ");
        int nbColonnes = lectureClavier.nextInt();
        int[][] matrice = new int[nbLignes][nbColonnes];
        for (int i = 0; i < nbLignes; i++) {
            for (int j = 0; j < nbColonnes; j++) {
                System.out.print("Saisir l'entier situé à la ligne " + (i + 1) +
                        " et à la colonne " + (j + 1) + " : ");
                matrice[i][j] = lectureClavier.nextInt();
            }
        }
        for (int i = 0; i < nbLignes; i++) {
            for (int j = 0; j < nbColonnes; j++) {
                System.out.println("Entier situé à la ligne " + (i + 1) +  " et à la colonne " + (j + 1) +
                        " : " + matrice[i][j]);
            }
        }
    }
}