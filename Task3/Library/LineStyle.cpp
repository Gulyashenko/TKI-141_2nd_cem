#include "LineStyle.h"

bool LineStyle::isThicknessValid(int thickness)
{
    return thickness >= 1;
}

LineStyle::LineStyle() : color(0, 0, 0), type(LineType::SOLID), thickness(1){}

LineStyle::LineStyle(Color& c, LineType type, int thikness)
{
    if (!isThicknessValid(thickness)) { throw; }
    color = c;
    this->type = type;
    this->thickness = thikness;
}

std::ostream& operator<<(std::ostream& os, const LineStyle& line)
{
    os << "Line style (Color: " << line.color 
       << ", Thickness: " << line.thickness 
       << ", Type: ";
    switch (line.type)
    {
    case LineType::SOLID: os << "SOLID)"; break;
    case LineType::DASH: os << "DASH)"; break;
    case LineType::DOT: os << "DOT)"; break;
    case LineType::DASH_DOT: os << "DASH_DOT)"; break;
    case LineType::DASH_DOT_DOT: os << "DASH_DOT_DOT)"; break;
    }
    return os;
}
