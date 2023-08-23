#include "Figure.h"
#include <iostream>

// skipcq: CXX-P2009
Figure::Figure(std::string name): name(name){}

std::string Figure::GetName()
{
	return name;
}

Figure::~Figure()
{
	std::cout << "Destructing " << name << " Abstract class\n";
}

double Calculate(Figure* wsk)
{
	return wsk->CalculateArea();;
}
