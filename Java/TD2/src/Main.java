public class Main {
    public static void main(String[] args) {
        Permanent RandomObject = new Permanent();
        Permanent Nathan = new Permanent("Nathan Talbot", "2 Place du champgil",
                "A208", 15, 5000.12f, 533.3f,
                320.66f);
        System.out.println(RandomObject.afficher() + "\n");
        System.out.println(Nathan.afficher());
    }
}