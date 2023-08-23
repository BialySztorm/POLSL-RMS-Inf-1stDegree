#include "Cylinder.h"
#define M_PI 3.14159265358979323846
#include <iostream>

// skipcq: CXX-P2009
Cylinder::Cylinder(double r, double h, std::string name) : Circle(r, name), h(h) 
{
    std::cout << "Constructing Cylinder with r = " << r << " and h = "<< h << std::endl;
} // konstruktor

double Cylinder::CalculateArea() const
{ // implementacja metody wirtualnej z klasy Figura
    return 2 * Circle::CalculateArea() + 2 * M_PI * r * h;
}

Cylinder::~Cylinder()
{
    std::cout << "Destructing Cylinder with r = " << r << " and h = " << h << std::endl;
}
