import java.util.Scanner;

public class Matrix {
    private double[][] tab;
    private double[] answers;
    private int a;
    public Matrix(double[][] tab){
        this.tab = tab;
    }

    public void indication(){
        double W = 0;
    }


    // 2 oznaczony, 1 sprzeczny, 0 nieoznaczony

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        double[][] array = {{1,2}};
        Matrix obj = new Matrix(array);


        scanner.close();
    }
}
