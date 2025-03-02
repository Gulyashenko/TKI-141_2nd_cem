#pragma once
#include "Point.h"

class Line {
private:
	Point point1;
	Point point2;
public:
	Line(const Point& point1, const Point& point2);
	Point getPoint1() const;
	Point getPoint2() const;
};