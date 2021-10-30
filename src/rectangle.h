#pragma once
#include "shape.h"
#include <stdexcept>

class Rectangle : public Shape
{
public:
    Rectangle(double length, double width)
    {
        if (length <= 0 || width <= 0)
            throw std::invalid_argument(std::string("Rectangle created by positive double length and width."));
        _length = length;
        _width = width;
    }
    double perimeter() const { return 2 * _length + 2 * _width; }
    double area() const { return _length * _width; }
    std::string info() const 
    { 
        char buffer[100];
        sprintf(buffer, "Rectangle (%.2lf %.2lf)", _length, _width);
        return buffer;
    }

private:
    double _length;
    double _width;
};