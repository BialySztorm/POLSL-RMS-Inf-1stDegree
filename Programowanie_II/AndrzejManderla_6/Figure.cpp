#include "Figure.h"

Figure::Figure(std::string name): name(name){}

std::string Figure::GetName()
{
	return name;
}
