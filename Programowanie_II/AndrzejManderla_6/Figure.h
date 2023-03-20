#pragma once
#include <string>

class Figure
{
protected:
    std::string name;
public:
    Figure(std::string name);
    std::string GetName();
    virtual double CalculateArea() const = 0;
};

