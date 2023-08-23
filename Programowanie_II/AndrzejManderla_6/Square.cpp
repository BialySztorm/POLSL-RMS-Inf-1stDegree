#include "Square.h"
#include <iostream>

// skipcq: CXX-P2009
Square::Square(double a, std::string name) : a(a), Figure(name) 
{
    std::cout << "Constructing Square with a = " << a << std::endl;
} // konstruktor

double Square::CalculateArea() const
{ // implementacja metody wirtualnej z klasy Figura
    return a * a;
}

Square::~Square()
{
    std::cout << "Destructing Square with a = " << a << std::endl;
}
