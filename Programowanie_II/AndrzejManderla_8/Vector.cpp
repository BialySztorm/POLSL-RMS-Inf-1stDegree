#include "Vector.h"
#include <string.h>

Vector::Vector(double x, double y, double z) : x(x), y(y), z(z) {}

Vector Vector::operator-(const Vector& v) const
{
    return Vector(x - v.x, y - v.y, z - v.z);
}

Vector Vector::operator+(const Vector& v) const
{
    return Vector(x + v.x, y + v.y, z + v.z);
}

Vector Vector::operator--()
{
    return Vector(x--, y--, z--);
}

Vector Vector::operator++()
{
    return Vector(x++, y++, z++);
}

std::string Vector::GetVector()
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
}
