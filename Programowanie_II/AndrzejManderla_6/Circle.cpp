#include "Circle.h"
#define M_PI 3.14159265358979323846
#include <iostream>

Circle::Circle(double r, std::string name) : r(r), Figure(name) 
{
    std::cout << "Constructing Circle with r = " << r << std::endl;
}

double Circle::CalculateArea() const
{ // implementacja metody wirtualnej z klasy Figura
    return M_PI * r * r;
}

Circle::~Circle()
{
    std::cout << "Destructing Circle with r = " << r << std::endl;
}
