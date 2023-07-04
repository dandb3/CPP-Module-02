#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
    Fixed _x;
    Fixed _y;

public:
    Point();
    Point(const float x, const float y);
    Point(const Fixed& x, const Fixed& y);
    Point(const Point& point);
    ~Point();

    Point& operator=(const Point& point);

    Point operator-(const Point& point) const;
    Fixed operator*(const Point& vec) const;

    const Fixed& getX() const;
    const Fixed& getY() const;

};

/* vector pointing from a to b */
# define vec(a, b) ((b) - (a))

#endif
