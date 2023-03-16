#include "Cube.h"
#include <iostream>

Cube::Cube()
{
	std::cout << "Constructor Cube\n";
	name = "";
}

Cube::Cube(std::string name):Square(name)
{
	std::cout<<"Constructor Cube "<<name<<std::endl;
	this->name = name;
}

Cube::~Cube()
{
	std::cout << "Destructor Cube " << name << std::endl;
}
