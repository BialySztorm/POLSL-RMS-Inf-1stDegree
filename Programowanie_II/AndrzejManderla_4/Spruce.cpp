#include "Spruce.h"
#include <iostream>
#include <string>

Spruce::Spruce()
{
	Margin = 5;
	std::cout<<"Type height of first block of the tree: ";
	std::cin>>Height;
	Width = (3*Height)-3+Margin;
}

void Spruce::Build()
{
	std::cout<<std::endl;
	// Build 1 block
	int tmp = 1;
	for (int i = 0; i < Height; i++, tmp+=2)
	{
		std::cout<<std::string((Width-(tmp/2)),' ')<<std::string(tmp,'*')<<std::endl;
	}
	// Build 2 block
	tmp-=4; // -2 for reduce and -2 after the loop
	for (int i = 0; i < Height+2; i++, tmp += 2)
	{
		std::cout << std::string((Width - (tmp / 2)), ' ') << std::string(tmp, '*') << std::endl;
	}
	// Build 3 block
	tmp -=8; // -6 for reduce and -2 after the loop
	for (int i = 0; i < Height+2; i++, tmp += 2)
	{
		std::cout << std::string((Width - (tmp / 2)), ' ') << std::string(tmp, '*') << std::endl;
	}
	// Build root
	for (int i = 0; i < Height ; i++, tmp += 2)
	{
		std::cout << std::string(Width, ' ') << '*' << std::endl;
	}
	std::cout << std::endl;
}
