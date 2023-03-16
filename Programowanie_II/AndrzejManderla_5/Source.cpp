#include "Cube.h"
#include "Cylinder.h"
#include <iostream>

int main()
{
	std::cout << "*** Cube without param ***\n";
	Cube *obj1 = new Cube();
	delete obj1;
	std::cout<<"*** Cube with param ***\n";
	Cube* obj2 = new Cube("Cube");
	delete obj2;
	std::cout << "*** Cylinder with param ***\n";
	Cylinder* obj3 = new Cylinder();
	delete obj3;
	std::cout << "*** Cylinder without param ***\n";
	Cylinder* obj4 = new Cylinder("Cylinder");
	delete obj4;

	return 0;
}