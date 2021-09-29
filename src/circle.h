#pragma once
#include "shape.h"
#include <math.h>

class Circle : public Shape
{
public:
    Circle(double radius) : _radius(radius) {}
    double area() const { return _radius * _radius * M_PI; }
    double perimeter() const { return 2 * _radius * M_PI; }

private:
    double _radius;
};