#pragma once
#include "Figure.h"

class Square : public Figure
{
private:
    double a;
public:
    Square(double a, std::string name);
    virtual double CalculateArea() const;

};

