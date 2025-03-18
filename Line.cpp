#include "Line.h"
#include "Point.h"

Line::Line(const Point& point1, const Point& point2, double k, double b)
{
	if (point1 == point2)
	{
		throw("error");
	}
	this -> point1 = point1;
	this -> point2 = point2;
    k = findk(point1, point2);
    b = findb(point1, point2);
}

Point Line::getPoint1() const
{
	return point1;
}

Point Line::getPoint2() const
{
	return point2;
}

double Line::findk(Point& point1, Point& point2){
    double k = (line.getPoint2().getY() - line.getPoint1().getY())/(line.getPoint2().getX()-line.getPoint1().getX());
    return k;
}

double Line::findb(Point& point1, Point& point2){
    double b = point1.getY() - point1().getX() * findk(point1, point2);
    return b;
}

double getk(){
    return k;
}

double getb(){
    return b;
}

