#include <iostream>
#include "Cube.h"
#include "Cylinder.h"

int main()
{
    // skipcq: CXX-C2013
    double r1 = 5, r2 = 2, a1 = 4, h = 5, a2 = 3;

    // Creating Circle
    Circle circle(r1, "Circle");
    //Creating Square
    Square square(a1, "Square");
    // Creating Cyllinder
    Cylinder cylinder(r2, h, "Cylinder");
    // Creating Cube
    Cube cube(a2, "Cube");

    std::cout << "\n-------------------\n\n";

    // skipcq: CXX-W2066
    Figure* figures[] = { &circle, &square, &cylinder, &cube }; // tablica wska�nik�w na figury

    for (int i = 0; i < 4; i++) {
        std::cout << "Method   | Area of "<< figures[i]->GetName()<<": " << figures[i]->CalculateArea() << std::endl;
        std::cout << "Function | Area of " << figures[i]->GetName() << ": " << Calculate(figures[i]) << std::endl;
    }

    std::cout << "\n-------------------\n\n";

    return 0;
}