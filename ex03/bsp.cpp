#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    const Fixed resultA = vec(a, b) * vec(a, point);
    const Fixed resultB = vec(b, c) * vec(b, point);
    const Fixed resultC = vec(c, a) * vec(c, point);

    if (resultA > 0 && resultB > 0 && resultC > 0)
        return true;
    else if (resultA < 0 && resultB < 0 && resultC < 0)
        return true;
    return false;
}
