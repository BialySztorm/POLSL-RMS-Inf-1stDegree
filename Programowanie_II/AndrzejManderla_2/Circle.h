
class Point {
    friend class Circle; // deklaracja przyja�ni z klas� Kolo
private:
    double x, y;
public:
    Point(double _x, double _y);
};

// Klasa Kolo - reprezentuje ko�o o �rodku (x0, y0) i promieniu r
class Circle {
private:
    double x0, y0, r;
public:
    Circle(double _x0, double _y0, double _r);
    bool PointInCircle(Point p);
};