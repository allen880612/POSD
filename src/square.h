#pragma once
#include "shape.h"

class Square : public Shape
{
public:
    Square(double sideLength) : _sideLength(sideLength) {}
    double sideLength() const { return _sideLength; }
    double perimeter() const { return 4 * _sideLength; }
    double area() const { return _sideLength * _sideLength; }

private:
    double _sideLength;
};