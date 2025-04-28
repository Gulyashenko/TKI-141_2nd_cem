#include "Shape.h"

Shape::Shape() : lineStyle(), fillColor(0,0,0) {}

Shape::Shape(LineStyle& lineStyle, Color& fillColor) : 
    lineStyle(lineStyle), fillColor(fillColor) {}

void Shape::draw(std::ostream& os)
{
    os << "Shape: ";
    toString(os);
    os << ", Fill color: " << fillColor << ", Line style: " << lineStyle;
}
