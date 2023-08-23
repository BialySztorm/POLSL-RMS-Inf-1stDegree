#include "Spruce.h"
#include <iostream>
#include <string>

Spruce::Spruce()
{
	Margin = 5;
	std::cout<<"Type height of first block of the tree: ";
	std::cin>>Height;
	
	if (Height <= 1)
	{
		std::cout << "Wrong data, minimum height is 2!";
		Height = 2;
	}

	Width = (3*Height)-3+Margin;
}

void Spruce::Build()
{
	std::cout<<std::endl;
	// Build 1 block
	int tmp = 1;
	tmp = Branch(Height, Width, tmp);
	// Build 2 block
	tmp = Branch(Height+2, Width, tmp-4); // -2 for reduce and -2 after the loop
	// Build 3 block
	tmp = Branch(Height+2, Width, tmp-8);
	// Build trunk
	Trunk(Height, Width);
	
	std::cout << std::endl;
}

int Spruce::Branch(int x, int y, int tmp)
{
	for (int i = 0; i < x; i++, tmp += 2)
	{
		std::cout << std::string((y - (tmp / 2)), ' ') << std::string(tmp, '*') << std::endl;
	}
	return tmp;
}

void Spruce::Trunk(int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		std::cout << std::string(y, ' ') << '*' << std::endl;
	}
}
