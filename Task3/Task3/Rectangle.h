#pragma once

#include "Shape.h"
#include "Point.h"
#include "Color.h"
#include "LineStyle.h"

class Rectangle : public Shape {
private:
	Point topLeft, bottomRight;
	Color fillColor;
	int width, height;
	LineStyle lineStyle;

	bool areRectAnglesValid(Point& topLeft, Point& bottomRight);
	bool areRectWidthAndHeightValid(int width, int height);

public:
	Rectangle(Point& topLeft, Point& bottomRight, Color& fillColor, LineStyle& lineStyle);
	Rectangle(Point& topLeft, Color& fillColor,int width, int height, LineStyle& lineStyle);

	void draw(std::ostream& os) const override;
};