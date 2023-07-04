#include <iostream>
#include "Point.hpp"

Point::Point(): _x(), _y() {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(const Fixed& x, const Fixed& y): _x(x), _y(y) {}

Point::Point(const Point& point): _x(point._x), _y(point._y) {}

Point::~Point() {}

Point& Point::operator=(const Point& point)
{
    this->_x = point._x;
    this->_y = point._y;
    return *this;
}

Point Point::operator-(const Point& point) const
{
    return Point(this->_x - point._x, this->_y - point._y);
}

Fixed Point::operator*(const Point& vec) const
{
    return (this->_x * vec._y - this->_y * vec._x);
}

const Fixed& Point::getX() const
{
    return this->_x;
}

const Fixed& Point::getY() const
{
    return this->_y;
}
