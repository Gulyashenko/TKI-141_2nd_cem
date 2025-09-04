#include <cmath>
#include <limits>
#include "Point.h"

std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "(" << point.x << ";" << point.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, const Point& point)
{
    is >> point.x >> point.y;
    return is;
}

bool operator==(const Point& point1, const Point& point2)
{
    return std::abs(point1.getX() - point2.getX()) <= std::numeric_limits<double>::epsilon()
        && std::abs(point1.getY() - point2.getY()) <= std::numeric_limits<double>::epsilon();
}

bool operator!=(const Point& point1, const Point& point2)
{
    return !(point1 == point2);
}

Point::Point(const double x, const double y) :
    x{ x }, y{ y }
{

}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

std::string ToString(const Point& p) {
    return "(" + std::to_string(p.getX()) + ";" + std::to_string(p.getY()) + ")";
}
