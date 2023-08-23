#include "Figure.h"

// skipcq: CXX-P2009
Figure::Figure(std::string name): name(name){}

std::string Figure::GetName()
{
	return name;
}
