#pragma once
#include <string>
class Point
{
public:
	Point();
	Point(std::string name);
	~Point();
protected:
	std::string name;
};

