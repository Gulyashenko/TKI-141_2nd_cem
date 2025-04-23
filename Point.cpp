#include <cmath>
#include <limits>
#include "Point.h"

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

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

// Оператор ввода
std::istream& operator>>(std::istream& is, Point& point) {
    is >> point.x >> point.y;
    return is;
}
