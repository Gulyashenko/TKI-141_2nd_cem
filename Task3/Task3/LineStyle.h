#pragma once

#include "Color.h"

enum class LineType {
	SOLID, DASH, DOT, DASH_DOT, DASH_DOT_DOT
};

class LineStyle {
private:
	Color color;
	LineType type;
	int thickness;

	bool isThicknessValid(int thickness);
public:
	LineStyle();
	LineStyle(Color& c, LineType type, int thikness);

	friend std::ostream& operator<<(std::ostream os, LineStyle& line);
};