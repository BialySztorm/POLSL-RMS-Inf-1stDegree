#pragma once
#include "Figure.h"

class Square : public Figure
{
protected:
    double a;
public:
    Square(double a, std::string name);
    virtual double CalculateArea() const;

    ~Square();
};

