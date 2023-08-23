#include "Cube.h"

// skipcq: CXX-P2009
Cube::Cube(double a, std::string name) : Square(a, name) {} // konstruktor

double Cube::CalculateArea() const
{ // implementacja metody wirtualnej z klasy Figura
    return 6 * Square::CalculateArea();
}
