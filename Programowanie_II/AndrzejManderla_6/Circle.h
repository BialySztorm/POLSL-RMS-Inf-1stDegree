#pragma once
#include "Figure.h"

class Circle : public Figure
{
protected:
    double r;
public:
    Circle(double r, std::string name); // konstruktor
    virtual double CalculateArea() const;
};

