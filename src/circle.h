#pragma once
#include <math.h>

class Circle {
   public:
    Circle(double radius) : _radius(radius) {}
    double area() const { return _radius * _radius * M_PI; }

   private:
    double _radius;
    
};