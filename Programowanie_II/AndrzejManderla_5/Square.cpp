#include "Square.h"
#include <iostream>

Square::Square()
{
	std::cout << "Constructor Square\n";
	name = "";
}

Square::Square(std::string name):Point(name)
{
	std::cout << "Constructor Square " << name << std::endl;
	this->name = name;
}

Square::~Square()
{
	std::cout << "Destructor Square " << name << std::endl;
}
