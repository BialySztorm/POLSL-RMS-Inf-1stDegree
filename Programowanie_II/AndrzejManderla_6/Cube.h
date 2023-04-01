#pragma once
#include "Square.h"
class Cube :public Square
{
public:
    Cube(double a, std::string name);
    virtual double CalculateArea() const;

    ~Cube();
};

