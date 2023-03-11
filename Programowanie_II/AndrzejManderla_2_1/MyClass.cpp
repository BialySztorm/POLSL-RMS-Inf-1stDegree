#include "MyClass.h"
#include <iostream>

void friendFunction(MyClass obj) {
    std::cout << "Friend function called" << std::endl;
}

MyClass::MyClass()
{
    std::cout << "Constructor called" << std::endl;
}

MyClass::MyClass(const MyClass& other)
{
    std::cout << "Copy constructor called" << std::endl;
}

MyClass::~MyClass()
{
    std::cout << "Destructor called" << std::endl;
}
