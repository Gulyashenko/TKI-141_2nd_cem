#pragma once

#include <iostream>
#include "Shape.h"
#include "Point.h"

/**
 * @brief Class Rectangle - rectangle. Inherited from Shape
 */
class Rectangle : public Shape {
private:
    /**
     * @brief Top left and bottom right angles of rectangle
     */
	Point topLeft, bottomRight;
    /**
     * @brief Width and height of rectangle
     */
	int width, height;

    /**
     * @brief function for check if angles of rectangle are valid
     * @param topLeft - top left angle of rectangle
     * @param bottomRight - bottom right angle of rectangle
     * @return true if angles are valid
     */
	bool areRectAnglesValid(Point& topLeft, Point& bottomRight);
    /**
     * @brief function for check if width and height of rectangle are valid
     * @param width - width of rectangle
     * @param height - height of rectangle
     * @return true if width and height are valid
     */
	bool areRectWidthAndHeightValid(int width, int height);

public:
    /**
     * @brief default constructor
     */
    Rectangle();
    /**
     * @brief constructor
     * @param topLeft - top left angle of rectangle
     * @param bottomRight - bottom right angle of rectangle
     */
    Rectangle(Point& topLeft, Point& bottomRigh);
    /**
     * @brief constructor
     * @param topLeft - top left angle of rectangle
     * @param width - width of rectangle
     * @param height - height of rectangle
     */
	Rectangle(Point& topLeft, int width, int height);

    /**
     * @brief function for output rectangle
     * @param os - output stream
     */
	void toString(std::ostream& os) const override;
    /**
     * @brief operator for input rectangle
     * @param is - input stream
     * @param rect - rectangle
     * @return input stream
     */
    friend std::istream& operator>>(std::istream& is, Rectangle& rect);
};
