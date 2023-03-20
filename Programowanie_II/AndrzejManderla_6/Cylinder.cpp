#include "Cylinder.h"
#define M_PI 3.14159265358979323846

Cylinder::Cylinder(double r, double h, std::string name) : Circle(r, name), h(h) {} // konstruktor

double Cylinder::CalculateArea() const
{ // implementacja metody wirtualnej z klasy Figura
    return 2 * Circle::CalculateArea() + 2 * M_PI * r * h;
}
