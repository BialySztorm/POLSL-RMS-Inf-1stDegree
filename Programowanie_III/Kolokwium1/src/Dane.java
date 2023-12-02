public class Dane implements Comparable<Dane> {
    private int id;
    private String lastName;
    private double salary;

    public Dane(int id, String lastName, double salary) {
        this.id = id;
        this.lastName = lastName;
        this.salary = salary;
    }

    @Override
    public int compareTo(Dane other) {
        // Porównanie wg. pola salary
        if (this.salary < other.salary) {
            return -1;
        } else if (this.salary > other.salary) {
            return 1;
        } else {
            // W przypadku równego wynagrodzenia sortujemy wg. pola lastName
            return this.lastName.compareTo(other.lastName);
        }
    }

    @Override
    public String toString() {
        return "Dane{" +
                "id=" + id +
                ", lastName='" + lastName + '\'' +
                ", salary=" + salary +
                '}';
    }
}