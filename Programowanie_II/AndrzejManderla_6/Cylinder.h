#pragma once
#include "Circle.h"
class Cylinder :public Circle
{
private:
    double h;
public:
    Cylinder(double r, double h, std::string name);
    virtual double CalculateArea() const;
};

