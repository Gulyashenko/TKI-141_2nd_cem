#pragma once

#include "Color.h"

/**
 * @brief enum for variants of line type
 */
enum class LineType {
	SOLID, DASH, DOT, DASH_DOT, DASH_DOT_DOT
};

/**
 * @brief Class LineStyle - line style
 */
class LineStyle {
private:
    /**
     * @brief color of line
     */
	Color color;
    /**
     * @brief type of line
     */
	LineType type;
    /**
     * @brief thickness of line
     */
	int thickness;

    /**
     * @brief function for check if thickness of line is valid
     * @param thickness - thickness of line
     * @return true if thickness is valid
     */
	bool isThicknessValid(int thickness);
public:
    /**
     * @brief default constructor
     */
	LineStyle();
    /**
     * @brief constructor
     * @param c - color of line
     * @param type - type of line
     * @param thikness - thickness of line
     */
	LineStyle(Color& c, LineType type, int thikness);

    /**
     * @brief function for output LineStyle
     * @param os - output stream
     * @param line - object of class LineStyle to be output
     * @return output stream
     */
	friend std::ostream& operator<<(std::ostream& os, const LineStyle& line);
};
