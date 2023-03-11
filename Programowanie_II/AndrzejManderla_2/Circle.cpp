#include "Circle.h"
#include <cmath>

Circle::Circle(double _x0, double _y0, double _r) : x0(_x0), y0(_y0), r(_r) {}

bool Circle::PointInCircle(Point p)
{
    double odleglosc = sqrt((p.x - x0) * (p.x - x0) + (p.y - y0) * (p.y - y0));
    return odleglosc <= r;
}

Point::Point(double _x, double _y) : x(_x), y(_y) {}
