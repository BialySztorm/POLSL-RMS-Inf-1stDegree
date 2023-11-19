import java.util.Arrays;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        Dane[] spisTelefonow = {
                new Dane("Nowak", "987-654-321"),
                new Dane("Kowalski", "123-456-789"),
                new Dane("Smith", "555-123-456")
        };

        Arrays.sort(spisTelefonow, Comparator.reverseOrder());

        for (Dane d : spisTelefonow) {
            System.out.println(d);
        }
    }
}