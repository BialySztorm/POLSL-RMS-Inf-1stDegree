#include "Circle.h"
#define M_PI 3.14159265358979323846

// skipcq: CXX-P2009
Circle::Circle(double r, std::string name) : r(r), Figure(name) {}

double Circle::CalculateArea() const
{ // implementacja metody wirtualnej z klasy Figura
    return M_PI * r * r;
}
