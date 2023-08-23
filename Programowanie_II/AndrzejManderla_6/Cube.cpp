#include "Cube.h"
#include <iostream>

Cube::Cube(double a, std::string name) : Square(a, name) 
{
    std::cout << "Constructing Cube with a = " << a << std::endl;
} // konstruktor

double Cube::CalculateArea() const
{ // implementacja metody wirtualnej z klasy Figura
    return 6 * Square::CalculateArea();
}

Cube::~Cube()
{
    std::cout << "Destructing Cube with a = " << a << std::endl;
}
