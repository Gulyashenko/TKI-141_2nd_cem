#include "Rectangle.h"

bool Rectangle::areRectAnglesValid(Point& topLeft, Point& bottomRight)
{
    return (topLeft.getX() < bottomRight.getX() and topLeft.getY() > bottomRight.getY());
}

bool Rectangle::areRectWidthAndHeightValid(int width, int height)
{
    return (width > 0 and height > 0);
}

Rectangle::Rectangle(Point& topLeft, Point& bottomRight) : Shape(), width(bottomRight.getX()-topLeft.getX()), height(topLeft.getY()-bottomRight.getY())
{
    if (!areRectAnglesValid(topLeft, bottomRight)){throw;}
    this->topLeft = topLeft;
    this->bottomRight = bottomRight;
}

Rectangle::Rectangle(Point& topLeft, int width, int height) : Shape(), bottomRight(topLeft.getX()+width, topLeft.getY()-height)
{
    if (!areRectWidthAndHeightValid
            (width, height))
        {throw;}
    this->topLeft = topLeft;
    this->width = width;
    this->height = height;
}

std::string Rectangle::toString(std::ostream& os) const
{
    std::string str = "Rectangle: Top left angle: " + ToString(topLeft) +
        ", Bottom right angle: " + ToString(bottomRight) + ", Width of rect: "
        + std::to_string(width) + ", Height of rect: " + std::to_string(height);
    return (str);
}

std::istream& operator>>(std::istream& is, Rectangle& rect){
    is >> rect.topLeft >> rect.bottomRight;
    return is;
}

Rectangle::Rectangle() : Shape(), width(0), height(0), topLeft(0,0), bottomRight(0,0) {}
