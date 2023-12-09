public class Punkt2DKolor extends Punkt2D{
    int r, g, b;
    Punkt2DKolor()
    {
        System.out.println("The default constructor of the class Punkt2DKolor");
        r = g = b = 0;
    }
    Punkt2DKolor(double x,double y, int r, int g, int b)
    {
        super(x,y);
        System.out.println("Parametric class constructor Punkt2DKolor");
        //wywołanie konstruktora klasy nadrzędnej konieczne w przypadku konstruktora parametrycznego
        this.r = r;
        this.g = g;
        this.b = b;
    }
    @Override
    public String toString() {
        String positon = "x: " + x + ", y: " + y;
        String color = "R: " + r + ", G: " + g + ", B: " + b;
        return "Punkt2DKolor("+ positon + ", "+ color + ")";
    }
}
