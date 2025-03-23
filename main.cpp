#include <string>
#include "Line.h"

/**
* @brief Function for get point.
* @return point
*/
Point getPoint();

/**
* @brief Function for get line.
* @return line
*/
Line getLine();

/**
* @brief Function for get coordinate.
* @return coordinate
*/
double getCoordinate(std::string message);

/**
* @brief Function for calculate distance from point to line.
* @paran line - line.
* @paran point3 - point.
* @return distance
*/
double DistanceFromPoint(Line& line, Point& point3);

/**
* @brief Function for check point in line.
* @paran line - line.
* @paran point3 - point.
* @return true if point in line.
* @return false if point not in line.
*/
bool IsPointInLine(Line& line, Point& point3);

/**
* @brief Main function, point of program start
* @return 0.
*/
int main()
{
    Point point= getPoint();

    Line line = getLine();

    if (IsPointInLine(line, point)) {
        std::cout << "point3 belongs to line" << std::endl << "Distance to line is zero";
    }
    else
    {
        std::cout << "point3  don`t belong to line" << std::endl << "distance from point to line is:" << DistanceFromPoint(line, point);
    }
    
    return 0;
}

Line getLine(){
    Point point1 = getPoint();
    Point point2 = getPoint();
    double k = (point2.getY() - point1.getY()) / (point2.getX() - point1.getX());
    double b = point1.getY() - point1.getX() * k;
    return Line(point1, point2, k, b);
}

Point getPoint(){
    auto x = getCoordinate("Input coordinate x: ");
    auto y = getCoordinate("Input coordinate y: ");
    return Point(x, y);
}

double getCoordinate(std::string message)
{
    std::cout << message << std::endl;
    double coordinate = 0.0;
    std::cin >> coordinate;
    if (std::cin.fail())
    {
        throw std::invalid_argument("Your input not a number");
    }
    return coordinate;
}

bool IsPointInLine(Line& line, Point& point3)
{
    return (point3.getY() == line.getk()*point3.getX() + line.getb());
}

double DistanceFromPoint(Line& line, Point& point3) 
{
    return fabs(line.getk()*point3.getX() - point3.getY() + line.getb()) / sqrt(1 + line.getk()*line.getk());
}
