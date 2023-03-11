// AndrzejManderla_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "car.h"
#include <iostream>

Car car0;

int main()
{
    std::cout << "Entered Main\n";
    // Creating object using default constructor
    Car car1;
    std::cout << "Object car1 created using default constructor" << std::endl;
    car1.displayInfo();

    {
        // Creating object using parametric constructor
        Car car2("Honda", "Civic", 2011);
        std::cout << "\nObject car2 created using parametric constructor in scope" << std::endl;
        car2.displayInfo();
    }

    // Creating object using operator new
    Car* car3 = new Car("Ford", "Mustang", 2007);
    std::cout << "\nObject car3 created using new operator" << std::endl;
    car3->displayInfo();
    delete car3;

    // Creating object using parametric constructor with dot operator
    Car car4("Tesla", "Model S", 2022);
    std::cout << "\nObject car4 created using parametric constructor with dot operator" << std::endl;
    car4.displayInfo();

    std::cout << "Exiting Main\n";

    return 0;
}

Car car5;
