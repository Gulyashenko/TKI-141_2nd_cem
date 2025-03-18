#pragma once
#include "Point.h"

class Line {
private:
	Point point1;
	Point point2;
    double k;
    double b;
public:
	Line(const Point& point1, const Point& point2, const double k, const double b);
	Point getPoint1() const;
	Point getPoint2() const;
    double getk() const;
    double getb() const;
    double findk(Point& point1, Point& point2);
    double findb(Point& point1, Point& point2);
};
