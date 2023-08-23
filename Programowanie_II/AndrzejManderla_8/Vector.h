#pragma once
#include <string>

class Vector1 {
public:
    double x, y, z;

    Vector1(double x = 0, double y = 0, double z = 0);

    // Przeci¹¿enie operatora dwuargumentowego (-)
    Vector1 operator-(const Vector1& v) const;

    // Przeci¹¿enie operatora dwuargumentowego (+)
    friend Vector1 operator+(const Vector1& v, const Vector1& v1);

    // Przeci¹¿enie operatora jednoargumentowego (--)
    Vector1 operator--();

    // Przeci¹¿enie operatora jednoargumentowego (++)
    friend Vector1 operator++(const Vector1& v);

    std::string GetVector();


};
