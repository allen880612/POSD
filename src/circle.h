#pragma once
#include "shape.h"
#include <math.h>

class Circle : public Shape
{
public:
    Circle(double radius)
    {
        if (radius <= 0)
            throw std::string("Circle created by positive double radius.");
        _radius = radius;
    }
    double area() const { return _radius * _radius * M_PI; }
    double perimeter() const { return 2 * _radius * M_PI; }
    std::string info() const 
    { 
        char buffer[100];
        sprintf(buffer, "Circle (%.2lf)", _radius);
        return buffer;
    }

private:
    double _radius;
};