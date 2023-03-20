#include <iostream>
#include "Cube.h"
#include "Cylinder.h"

int main()
{
    double r1 = 5, r2 = 2, a1 = 4, h = 5, a2 = 3;

    std::cout<<"Creating Circle with r = "<<r1<<std::endl;
    Circle circle(r1, "Circle");
    std::cout << "Creating Square with a = " << a1 << std::endl;
    Square square(a1, "Square");
    std::cout << "Creating Cyllinder with r = " << r2 << " and h = " << h << std::endl;
    Cylinder cylinder(r2, h, "Cylinder");
    std::cout << "Creating Cube with a = " << a2 << std::endl;
    Cube cube(a2, "Cube");

    Figure* figures[] = { &circle, &square, &cylinder, &cube }; // tablica wskaŸników na figury

    for (int i = 0; i < 4; i++) {
        std::cout << "Area of "<< figures[i]->GetName()<<": " << figures[i]->CalculateArea() << std::endl;
    }


    return 0;
}