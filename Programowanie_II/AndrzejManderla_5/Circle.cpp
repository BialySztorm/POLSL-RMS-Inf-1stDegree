#include "Circle.h"
#include <iostream>

Circle::Circle()
{
	std::cout << "Constructor Circle\n";
	name = "";
}

// skipcq: CXX-P2009
Circle::Circle(std::string name):Point(name)
{
	std::cout << "Constructor Circle " << name << std::endl;
	this->name = name;
}

Circle::~Circle()
{
	std::cout << "Destructor Circle " << name << std::endl;
}
