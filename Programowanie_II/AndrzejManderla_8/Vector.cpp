#include "Vector.h"
#include <string.h>

Vector1::Vector1(double x, double y, double z) : x(x), y(y), z(z) {}

Vector1 Vector1::operator-(const Vector1& v) const
{
    return Vector1(x - v.x, y - v.y, z - v.z);
}

Vector1 Vector1::operator--()
{
    return Vector1(x-1, y-1, z-1);
}

std::string Vector1::GetVector()
{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
}


Vector1 operator+(const Vector1& v, const Vector1& v1)
{
    return Vector1(v1.x + v.x, v1.y + v.y, v1.z + v.z);
}

Vector1 operator++(const Vector1& v)
{
    return Vector1(v.x + 1, v.y + 1, v.z + 1);
}