import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            System.out.print("Podaj promień podstawy stożka: ");
            double r = scanner.nextDouble();

            System.out.print("Podaj tworzącą stożka: ");
            double l = scanner.nextDouble();

            if (r <= 0 || l <= 0) {
                System.out.println("Podano niepoprawne dane. Promień i tworząca muszą być dodatnie.");
            } else {
                // Obliczenia
                double surfaceArea = Math.PI * r * (r + Math.sqrt(r * r + l * l));
                double velocity = (1.0 / 3.0) * Math.PI * r * r * l;

                // Wyświetlenie wyników
                System.out.println("Pole powierzchni stożka: " + surfaceArea);
                System.out.println("Objętość stożka: " + velocity);
            }
        } catch (Exception e) {
            System.out.println("Wprowadzono niepoprawne dane. Upewnij się, że podano liczby.");
        } finally {
            scanner.close();
        }
    }
}