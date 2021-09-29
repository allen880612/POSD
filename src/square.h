#pragma once

class Square {
   public:
    Square(double sideLength) : _sideLength(sideLength) {}
    double sideLength() const { return _sideLength; }
    double area() const { return _sideLength * _sideLength; }

   private:
    double _sideLength;
    
};