#include <math.h>

class TwoDimensionalVector
{
public:
    TwoDimensionalVector(double x, double y) : _x(x), _y(y)
    {
        _length = sqrt(x * x + y * y);
    }
    double length() const { return _length; }
    std::string info() const 
    { 
        char buffer[100];
        sprintf(buffer, "[%.2lf,%.2lf]", _x, _y);
        return buffer;
    }
    double dot(const TwoDimensionalVector& other) const { return _x * other._x + _y * other._y; }
    double cross(const TwoDimensionalVector& other) const { return _x * other._y - _y * other._x; }

private:
    double _x;
    double _y;
    double _length;
};