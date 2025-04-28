#include "Color.h"

bool Color::isColorValid(int color)
{
    return (color >= 0 and color <= 255);
}

Color::Color(int r, int g, int b)
{
    if (!isColorValid(r) or !isColorValid(g) or !isColorValid(b)) {
        throw;
    }
    red = static_cast<uint8_t>(r);
    green = static_cast<uint8_t>(g);
    blue = static_cast<uint8_t>(b);
}

std::ostream& operator<<(std::ostream& os, const Color& color)
{
    os << "Color(R: " << color.red << ", G: " << color.green << ", B: " << color.blue << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Color& color)
{
    is >> color.red >> color.green >> color.blue;
    return is;
}
