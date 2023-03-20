#include "Square.h"

Square::Square(double a, std::string name) : a(a), Figure(name) {} // konstruktor

double Square::CalculateArea() const
{ // implementacja metody wirtualnej z klasy Figura
    return a * a;
}
