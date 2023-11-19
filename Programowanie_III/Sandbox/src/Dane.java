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
        return this.nazwisko.compareTo(o.nazwisko);
    }

    public String getNazwisko() {
        return nazwisko;
    }
}
