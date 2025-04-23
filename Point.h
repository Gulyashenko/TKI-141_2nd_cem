#include <iostream>

class Point{
    private:
        double x, y;
    public:
        Point(const double x = 0,const double y = 0);
        double getX() const;
        double getY() const;

    friend std::ostream& operator<<(std::ostream& os, const Point& point);
    friend std::istream& operator>>(std::istream& is, Point& point);
};

bool operator==(Point& p1, Point& p2);
bool operator!=(Point& p1, Point& p2);
