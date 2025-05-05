#pragma once
#include <iostream>
#include <cmath>

/**
    * @brief Class Point - point.
*/
class Point
{
private:
    /**
    * @brief x and y - coordinates of point.
    */
    double x;
    double y;
public:
    /**
    * @brief constructor of point.
    * @param x - coordinate of point.
    * @param y - coordinate of point.
    */
    Point(const double x = 0, const double y = 0);

    /**
    * @brief Function for return x
    * @return x
    */
    double getX() const;

    /**
    * @brief Function for return y
    * @return y
    */
    double getY() const;

    /**
    * @brief Overloaded output operator for class Point
    * @param os Output stream
    * @param point Object of class Point to be output
    * @return Reference to output stream
    */
    friend std::ostream& operator<<(std::ostream& os, const Point& point);

    /**
    * @brief Overloaded input operator for class Point
    * @param is Input stream
    * @param point Object of class Point to write data to
    * @return Reference to input stream
    */
    friend std::istream& operator>>(std::istream& is, const Point& point);

    /**
     * @brief function for make string from point
     * @param p - point
     * @return string
     */
    friend std::string ToString(const Point& p);
};

/**
* @brief Operator for compare points.
* @param point1 - first point.
* @param point2 - second point.
* @return true if points are equal.
* @return false if points are not equal.
*/
bool operator==(const Point& point1, const Point& point2);

/**
* @brief Operator for compare points.
* @param point1 - first point.
* @param point2 - second point.
* @return true if points are not equal.
* @return false if points are equal.
*/
bool operator!=(const Point& point1, const Point& point2);
