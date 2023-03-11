#include "car.h"
#include <iostream>

int Car::ID = 0;

Car::Car()
{
    make = "";
    model = "";
    year = 0;
    id = ID++;
    std::cout << id <<" Default constructor called" << std::endl;
}

Car::Car(std::string m, std::string mo, int y)
{
    make = m;
    model = mo;
    year = y;
    id = ID++;
    std::cout << id << " Parametric constructor called" << std::endl;
}

Car::~Car()
{
    std::cout << id << " Destructor called for: "<< model <<" "<< year << std::endl;
}

void Car::displayInfo()
{
    std::cout << "Make: " << make << ", ";
    std::cout << "Model: " << model << ", ";
    std::cout << "Year: " << year << ", ";
    std::cout << "Id: " << id << std::endl;
}
