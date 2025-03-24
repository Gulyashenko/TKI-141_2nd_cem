#pragma once
#include "Point.h"
/**
    * @brief Class Line - line.
*/
class Line {
private:
    /**
    * @brief point1 and point2 - points of line .
    */
	Point point1;
	Point point2;
    /**
    * @brief k and b - equation of line.
    */
    double k;
    double b;
public:
    /**
    * @brief constructor of line.
    * @param point1 - first point of line.
    * @param point2 - second point of line.
    */
	Line(const Point& point1, const Point& point2);

    /**
    * @brief Function for return point1
    * @return point1
    */
	Point getPoint1() const;

    /**
    * @brief Function for return point2
    * @return point2
    */
	Point getPoint2() const;

    /**
    * @brief Function for return k
    * @return k
    */
    double getk() const;

    /**
    * @brief Function for return b
    * @return b
    */
    double getb() const;
};
