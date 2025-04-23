#include "Rectangle.h"

bool Rectangle::areRectAnglesValid(Point& topLeft, Point& bottomRight)
{
    return (topLeft.getX() < bottomRight.getX() and topLeft.getY() > bottomRight.getY());
}

bool Rectangle::areRectWidthAndHeightValid(int width, int height)
{
    return (width > 0 and height > 0);
}

Rectangle::Rectangle(Point& topLeft, Point& bottomRight, Color& fillColor, LineStyle& lineStyle) : width(bottomRight.getX()-topLeft.getX()), height(topLeft.getY()-bottomRight.getY())
{
    if (!areRectAnglesValid(topLeft, bottomRight)){throw;}
    this->topLeft = topLeft;
    this->bottomRight = bottomRight;
    this->fillColor = fillColor;
    this->lineStyle = lineStyle;
}

Rectangle::Rectangle(Point& topLeft, Color& fillColor, int width, int height, LineStyle& lineStyle) : bottomRight(topLeft.getX()+width, topLeft.getY()-height)
{
    if (!areRectWidthAndHeightValid(width, height)) { throw; }
    this->topLeft = topLeft;
    this->fillColor = fillColor;
    this->width = width;
    this->height = height;
    this->lineStyle = lineStyle;
}

void Rectangle::draw(std::ostream& os) const
{
    os << "Rectangle: Top left angle: " << topLeft << ", Bottom right angle: " << bottomRight << ", Color what using for fill rectangle: " << fillColor << ", Width of rect: " << width << ", Height of rect: " << height << ", Style of lines that using for width and Height: ";
}
