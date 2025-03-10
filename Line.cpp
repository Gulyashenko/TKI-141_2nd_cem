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
}

Point Line::getPoint1() const
{
	return point1;
}

Point Line::getPoint2() const
{
	return point2;
}