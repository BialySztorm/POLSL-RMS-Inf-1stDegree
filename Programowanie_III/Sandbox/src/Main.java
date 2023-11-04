import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Wprowadź tekst (aby zakończyć, wpisz 'koniec'):");
        StringBuilder textBuilder = new StringBuilder();
        String line;

        while (true) {
            line = scanner.nextLine();
            if (line.equals("koniec")) {
                break;
            }
            textBuilder.append(line).append("\n");
        }

        String modifiedText = removeLeadingSpacesAndTabs(textBuilder.toString());
        System.out.println("Tekst po usunięciu początkowych spacji i tabulacji:");
        System.out.println(modifiedText);
    }

    public static String removeLeadingSpacesAndTabs(String text) {
        String[] lines = text.split("\n");
        StringBuilder resultBuilder = new StringBuilder();

        for (String line : lines) {
            String trimmedLine = line.replaceAll("^[ \t]+", ""); // Usuwanie początkowych spacji i tabulacji
            resultBuilder.append(trimmedLine).append("\n");
        }

        return resultBuilder.toString().trim(); // Usunięcie nadmiarowych znaków nowego wiersza na końcu
    }
}