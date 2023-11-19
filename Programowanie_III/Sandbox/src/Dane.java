import java.text.Collator;
import java.util.Locale;

class Dane implements Comparable<Dane> {
    private String nazwisko;
    private String numerTelefonu;

    public Dane(String nazwisko, String numerTelefonu) {
        this.nazwisko = nazwisko;
        this.numerTelefonu = numerTelefonu;
    }

    @Override
    public String toString() {
        return "Nazwisko: " + nazwisko + ", Numer telefonu: " + numerTelefonu;
    }

    @Override
    public int compareTo(Dane o) {
        Locale locale = new Locale("pl","PL");
        Collator col = Collator.getInstance(locale);
        col.setStrength(Collator.PRIMARY);
        return col.compare(this.nazwisko, o.nazwisko);
    }

    public String getNazwisko() {
        return nazwisko;
    }
}
