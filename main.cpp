#include <string>
#include "Line.h"

Point getPoint();
Line getLine();
double getCoordinate(std::string message);
double DistanceFromPoint(Line& line, Point& point3);
bool IsPointInLine(Line& line, Point& point3);


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
    double k = findk(point1, point2);
    double b = findb(point1, point2);
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
    return (point3.getY() == line.getk()*point3.getX() + line.getb)
}

double DistanceFromPoint(Line& line, Point& point3) 
{
    return fabs(line.getk()*point3.getX() - point3.getY() + line.getb()) / sqrt(1 + line.getk()*line.getk());
}
