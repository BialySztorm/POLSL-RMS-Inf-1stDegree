#include "Vector.h"
// skipcq: CXX-W2030
#include <string.h>

Vector::Vector(double x, double y, double z) : x(x), y(y), z(z) {}

Vector Vector::operator-(const Vector& v) const
{
    // skipcq: CXX-W2033
    return Vector(x - v.x, y - v.y, z - v.z);
}

Vector Vector::operator+(const Vector& v) const
{
    // skipcq: CXX-W2033
    return Vector(x + v.x, y + v.y, z + v.z);
}

Vector Vector::operator--()
{
    // skipcq: CXX-W2033
    return Vector(x--, y--, z--);
}

Vector Vector::operator++()
{
    // skipcq: CXX-W2033
    return Vector(x++, y++, z++);
}

std::string Vector::GetVector()
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
}
