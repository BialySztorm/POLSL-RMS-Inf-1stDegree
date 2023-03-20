#pragma once
#include <string>

class Vector {
private:
    double x, y, z;
public:

    Vector(double x = 0, double y = 0, double z = 0);

    // Przeci¹¿enie operatora dwuargumentowego (-)
    Vector operator-(const Vector& v) const;

    // Przeci¹¿enie operatora dwuargumentowego (+)
    Vector operator+(const Vector& v) const;

    // Przeci¹¿enie operatora jednoargumentowego (--)
    Vector operator--();

    // Przeci¹¿enie operatora jednoargumentowego (++)
    Vector operator++();

    std::string GetVector();

};