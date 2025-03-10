#include <string>
#include "Line.h"

Point getPoint();
Line getLine();
double getCoordinate(std::string message);
void DistanceFromPoint(Line& line, Point& point3);
bool IsPointInLine(Line& line, Point& point3);


int main()
{
    Point point= getPoint();

    Line line = getLine();

    if (IsPointInLine(line, point) == 1) {
        std::cout << "point3 belongs to line" << std::endl << "Distance to line is zero";
    }
    else
    {
        std::cout << "point3  don`t belong to line" << std::endl;
        DistanceFromPoint(line, point);
    }
    
    return 0;
}

Line getLine(){
    Point point1 = getPoint();
    Point point2 = getPoint();
    Line line(point1, point2);
    return line;
}

Point getPoint(){
    auto x = getCoordinate("Input coordinate x: ");
    auto y = getCoordinate("Input coordinate y: ");
    Point point(x, y);
    return point;
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
    Point point1 = line.getPoint1();
    Point point2 = line.getPoint2();
    double x1 = point1.getX();
    double x2 = point2.getX();
    double x3 = point3.getX();
    double y1 = point1.getY();
    double y2 = point2.getY();
    double y3 = point3.getY();

    if ((y3 - y1) / (y2 - y1) == (x3 - x1) / (x2 - x1)) {
        return 1;
    }
    else {
        return 0;
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