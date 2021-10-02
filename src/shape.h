#pragma once

class Shape {
   public:
    virtual double area() const =0;
    virtual double perimeter() const =0;
    virtual std::string info() const =0;
};