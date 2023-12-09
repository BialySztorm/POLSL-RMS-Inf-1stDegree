public class Punkt2D {
    double x,y;
    Punkt2D()
    {
        System.out.println("The default constructor of the class Punkt2D");
        x = y = 0.0;
    }
    Punkt2D(double x,double y)
    {
        System.out.println("Parametric class constructor Punkt2D");
        this.x = x;
        this.y = y;
    }
    @Override
    public String toString() {
        return "Punkt2D(" + "x: " + x + ", y: " + y+")";
    }
}
