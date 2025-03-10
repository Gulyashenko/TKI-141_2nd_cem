#include <string>
#include "Line.h"

double getCoordinate(std::string message);
void DistanceFromPoint(Line& line, Point& point3);
void PointInLine(Line& line, Point& point3);


int main()
{
    auto x = getCoordinate("Input coordinate x: ");
    auto y = getCoordinate("Input coordinate y: ");
    Point point1(x, y);

    x = getCoordinate("Input coordinate x: ");
    y = getCoordinate("Input coordinate y: ");
    Point point2(x, y);

    x = getCoordinate("Input coordinate x: ");
    y = getCoordinate("Input coordinate y: ");
    Point point3(x, y);

    Line line(point1, point2);

    PointInLine(line, point3);


    return 0;
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

void PointInLine(Line& line, Point& point3)
{
    Point point1 = line.getPoint1();
    Point point2 = line.getPoint2();
    double x1 = point1.getX();
    double x2 = point2.getX();
    double x3 = point3.getX();
    double y1 = point1.getY();
    double y2 = point2.getY();
    double y3 = point3.getY();

    if ((y3 - y1) / (y2 - y1) == (x3 - x1) / (x2 - x1)) {
        std::cout << "point3 belongs to line" << std::endl << "Distance to line is zero";
    }
    else {
        std::cout << "point3  don`t belong to line" << std::endl;
        DistanceFromPoint(line, point3);
    }
}

void DistanceFromPoint(Line& line, Point& point3) 
{
    Point point1 = line.getPoint1();
    Point point2 = line.getPoint2();
    double x1 = point1.getX();
    double x2 = point2.getX();
    double x3 = point3.getX();
    double y1 = point1.getY();
    double y2 = point2.getY();
    double y3 = point3.getY();

    double distance = fabs((y2 - y1) * x3 - (x2 - x1) * y3 + x2 * y1 - y2 * x1) /
        sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
    std::cout << "Distance to line is: " << distance << std::endl;
}