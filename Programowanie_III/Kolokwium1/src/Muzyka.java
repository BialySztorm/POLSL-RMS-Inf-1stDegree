import java.text.Collator;
import java.util.Locale;

public class Muzyka implements Comparable<Muzyka> {
    private String title;
    private double prize;

    public Muzyka(String tytul, double cena) {
        this.title = tytul;
        this.prize = cena;
    }

    @Override
    public int compareTo(Muzyka other) {
        Locale locale = new Locale("pl","PL");
        Collator col = Collator.getInstance(locale);
        col.setStrength(Collator.PRIMARY);
        return col.compare(this.title, other.title);
    }

    @Override
    public String toString() {
        return "Muzyka{" +
                "tytul='" + title + '\'' +
                ", cena=" + prize +
                '}';
    }
}