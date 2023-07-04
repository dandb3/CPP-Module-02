#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    float x, y;
    while (true)
    {
        std::cin >> x >> y;
        if (!std::cin.good())
            break;
        Point a(x, y);
        std::cin >> x >> y;
        if (!std::cin.good())
            break;
        Point b(x, y);
        std::cin >> x >> y;
        if (!std::cin.good())
            break;
        Point c(x, y);
        std::cin >> x >> y;
        if (!std::cin.good())
            break;
        Point point(x, y);
        std::cout << "a = (" << a.getX() << ", " << a.getY() << ")\n";
        std::cout << "b = (" << b.getX() << ", " << b.getY() << ")\n";
        std::cout << "c = (" << c.getX() << ", " << c.getY() << ")\n";
        std::cout << "p = (" << point.getX() << ", " << point.getY() << ")\n";
        if (bsp(a, b, c, point))
            std::cout << "p is in the triangle!" << std::endl;
        else
            std::cout << "p is out of the triangle!" << std::endl;
    }
    return 0;
}