#include "Derived.h"
#include <iostream>

void A::methodA()
{
	std::cout << "Start of method A\n";
	a1 = 1;
	a2 = 2;
	a3 = 3;
	std::cout << "End of method A\n";
}

void B::methodB()
{
	std::cout << "Start of method B\n";
	a1 = 1;
	//a2 = 2;
	a3 = 3;
	b1 = 4;
	b2 = 5;
	b3 = 6;
	std::cout << "End of method B\n";
}

void C::methodC()
{
	std::cout << "Start of method C\n";
	a1 = 1;
	//a2 = 2;
	a3 = 3;
	b1 = 4;
	//b2 = 5;
	b3 = 6;
	c1 = 7;
	c2 = 8;
	c3 = 9;
	std::cout << "End of method C\n";
}