#include "Point.h"
#include <iostream>

Point::Point()
{
	std::cout << "Constructor Point\n";
	name = "";
}

Point::Point(std::string name)
{
	std::cout << "Constructor Point " << name << std::endl;
	this->name = name;
}

Point::~Point()
{
	std::cout << "Destructor Point " << name << std::endl;
}
