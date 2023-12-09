import java.text.Collator;
import java.util.Locale;
import java.io.Serializable;

public class Ksiazka implements Comparable<Ksiazka>, Serializable {
    String title;
    Ksiazka(String title)
    {
        this.title = title;
    }

    @Override
    public String toString() {
        return title;
    }

    @Override
    public int compareTo(Ksiazka o) {
        Collator cl = Collator.getInstance(new Locale("pl", "PL"));
        return cl.compare(this.title, o.title);
    }
}