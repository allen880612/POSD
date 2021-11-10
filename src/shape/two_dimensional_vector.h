#pragma once
#include <math.h>

class TwoDimensionalVector
{
public:
    TwoDimensionalVector() : _x(0), _y(0) {}
    TwoDimensionalVector(double x, double y) : _x(x), _y(y)
    {
        _length = sqrt(x * x + y * y);
    }

    double x() const { return _x; }
    double y() const { return _y; }
    double length() const { return _length; }
    std::string info() const
    {
        char buffer[100];
        sprintf(buffer, "[%.2lf,%.2lf]", _x, _y);
        return buffer;
    }

    double dot(const TwoDimensionalVector &other) const { return _x * other._x + _y * other._y; }
    double cross(const TwoDimensionalVector &other) const { return _x * other._y - _y * other._x; }
    TwoDimensionalVector subtract(TwoDimensionalVector other) const { return TwoDimensionalVector(_x - other._x, _y - other._y); }
    double euclideanDistance(const TwoDimensionalVector &other) const {return sqrt(powf(_x - other._x, 2) + pow(_y - other._y, 2));}

private:
    double _x;
    double _y;
    double _length;
};