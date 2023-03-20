#pragma once
#include <string>

class Vector {
private:
    double x, y, z;
public:

    Vector(double x = 0, double y = 0, double z = 0);

    // Przeci��enie operatora dwuargumentowego (-)
    Vector operator-(const Vector& v) const;

    // Przeci��enie operatora dwuargumentowego (+)
    Vector operator+(const Vector& v) const;

    // Przeci��enie operatora jednoargumentowego (--)
    Vector operator--();

    // Przeci��enie operatora jednoargumentowego (++)
    Vector operator++();

    std::string GetVector();

};