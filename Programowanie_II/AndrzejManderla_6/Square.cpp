#include "Square.h"

// skipcq: CXX-P2009
Square::Square(double a, std::string name) : a(a), Figure(name) {} // konstruktor

double Square::CalculateArea() const
{ // implementacja metody wirtualnej z klasy Figura
    return a * a;
}
