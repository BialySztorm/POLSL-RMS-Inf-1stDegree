class Ksiazka implements Comparable<Ksiazka> {
    private String tytul;

    public Ksiazka(String tytul) {
        this.tytul = tytul;
    }

    @Override
    public int compareTo(Ksiazka o) {
        return this.tytul.compareTo(o.tytul);
    }

    @Override
    public String toString() {
        return "Tytuł: " + tytul;
    }
}