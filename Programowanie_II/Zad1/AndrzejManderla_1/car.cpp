#include "car.h"
#include <iostream>

Car::Car()
{
    make = "";
    model = "";
    year = 0;
    std::cout << "Default constructor called" << std::endl;
}

Car::Car(std::string m, std::string mo, int y)
{
    make = m;
    model = mo;
    year = y;
    std::cout << "Parametric constructor called" << std::endl;
}

Car::~Car()
{
    std::cout << "Destructor called" << std::endl;
}

void Car::displayInfo()
{
    std::cout << "Make: " << make << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Year: " << year << std::endl;
}
