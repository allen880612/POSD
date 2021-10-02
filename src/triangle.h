#pragma once
#include "shape.h"
#include <iostream>
#include "two_dimensional_vector.h"

class Triangle : public Shape
{
public:
    Triangle(TwoDimensionalVector v1, TwoDimensionalVector v2)
    {
        _vectors[0] = TwoDimensionalVector(0.0, 0.0);
        _vectors[1] = v1;
        _vectors[2] = v2;

        if (!isTriangle())
            throw std::string("Triangle created by two non-parallel two dimensional _vectors.");
        
        _sides[0] = _vectors[0].euclideanDistance(_vectors[1]);
        _sides[1] = _vectors[1].euclideanDistance(_vectors[2]);
        _sides[2] = _vectors[2].euclideanDistance(_vectors[0]);
    }
    double perimeter() const { return _sides[0] + _sides[1] + _sides[2]; }
    double area() const 
    {
         double s = perimeter() / 2;
         return sqrt(s * (s - _sides[0]) * (s - _sides[1]) * (s - _sides[2]));
    }
    std::string info() const 
    { 
        char buffer[100];
        sprintf(buffer, "Triangle (%s %s)", _vectors[1].info().c_str(), _vectors[2].info().c_str());
        return buffer;
    }

private:
    TwoDimensionalVector _vectors[3];
    double _sides[3];
    bool isTriangle() { return !(_vectors[1].cross(_vectors[2]) == 0); }
};