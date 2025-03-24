#include "Line.h"
#include "Point.h"

Line::Line(const Point& point1, const Point& point2)
{
	if (point1 == point2)
	{
		throw("error");
	}
	this -> point1 = point1;
	this -> point2 = point2;
    k = (point2.getY() - point1.getY())/(point2.getX() - point1.getX());
    b = point1.getY()-point1.getX()*k;
}

Point Line::getPoint1() const
{
	return point1;
}

Point Line::getPoint2() const
{
	return point2;
}

double Line::getk() const
{
    return k;
}

double Line::getb() const 
{
    return b;
}
