#pragma once

#include <iostream>
#include <cstdint>

/**
 * @brief Class Color - color.
 */
class Color {
private:
    /**
     * @brief Red, green and blue components of color.
     */
	uint8_t red, green, blue;

    /**
     * @brief Function for check if color is valid.
     * @param color - color
     * @return true if color is valid
     */
	bool isColorValid(int color);
public:
    /**
     * @brief constructor.
     */
	Color(int r = 0, int g = 0, int b = 0);

    /**
     * @brief operator for output color.
     * @param os Output stream
     * @param color Object of class Color to be output
     * @return Output stream
     */
	friend std::ostream& operator<<(std::ostream& os, const Color& color);
    /**
     * @brief operator for input color.
     * @param is Input stream
     * @param color Object of class Color to be input
     * @return Input stream
     */
	friend std::istream& operator>>(std::istream& is, Color& color);
};
