import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
        String date1 = "2024-12-29";
        String date2 = "11/19/2023";
        String date3 = "2023/11/19";
        String date4 = "19.11.2023";

        System.out.println("Date 1 is valid: " + isValidDate(date1));
        System.out.println("Date 2 is valid: " + isValidDate(date2));
        System.out.println("Date 3 is valid: " + isValidDate(date3));
        System.out.println("Date 4 is valid: " + isValidDate(date4));
    }

    private static boolean isValidDate(String date) {
        // Wyrażenie regularne do sprawdzenia poprawności daty w formacie YYYY-MM-DD
        String dateRegex = "\\d{4}-(0[1-9]|1[0-2])-([0-2][0-9]|3[0-1])";

        // Kompiluj wyrażenie regularne
        Pattern pattern = Pattern.compile(dateRegex);

        // Utwórz obiekt Matcher
        Matcher matcher = pattern.matcher(date);

        // Sprawdź, czy łańcuch pasuje do wyrażenia regularnego
        if (matcher.matches()) {
            int year = Integer.parseInt(date.substring(0, 4));
            int month = Integer.parseInt(date.substring(5, 7));
            int day = Integer.parseInt(date.substring(8, 10));

            // Sprawdź poprawność miesiąca (1-12)
            if (month < 1 || month > 12) {
                return false;
            }

            // Sprawdź poprawność dnia w zależności od miesiąca
            if (day < 1 || day > daysInMonth(year, month)) {
                return false;
            }

            return true;
        }

        return false;
    }

    private static int daysInMonth(int year, int month) {
        if (month == 2) {
            // Luty - sprawdź, czy rok przestępny
            return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            // Kwiecień, Czerwiec, Wrzesień, Listopad
            return 30;
        } else {
            // Pozostałe miesiące
            return 31;
        }
    }
}