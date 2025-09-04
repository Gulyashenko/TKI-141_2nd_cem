#pragma once

#include <iostream>
#include <string>
#include "LineStyle.h"
#include "Color.h"

/**
 * @brief Abstract class Shape
 */
class Shape {
private:
    /**
     * @brief Line style
     */
    LineStyle lineStyle;
    /**
     * @brief Color that using for fill Shape
     */
    Color fillColor;
public:
    /**
     * @brief Default constructor
     */
    Shape();
    /**
     * @brief constructor
     * @param lineStyle - line style
     * @param fillColor - color that using for fill Shape
     */
    Shape(LineStyle& lineStyle, Color& fillColor);
    /**
     * @brief function for output Shape
     * @param os - output stream
     * @return string
     */
	virtual std::string toString (std::ostream& os) const = 0;
    /**
     * @brief function for draw Shape
     */
    void draw(std::ostream& os);
};
