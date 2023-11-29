class Pracownik implements Comparable<Pracownik> {
    private int idPracownika;
    private String nazwisko;
    private String stanowisko;

    public Pracownik(int idPracownika, String nazwisko, String stanowisko) {
        this.idPracownika = idPracownika;
        this.nazwisko = nazwisko;
        this.stanowisko = stanowisko;
    }

    @Override
    public int compareTo(Pracownik o) {
        int result = this.stanowisko.compareTo(o.stanowisko);
        if (result == 0) {
            return this.nazwisko.compareTo(o.nazwisko);
        }
        return result;
    }

    @Override
    public String toString() {
        return "ID: " + idPracownika + ", Nazwisko: " + nazwisko + ", Stanowisko: " + stanowisko;
    }
}
