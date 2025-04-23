#pragma once

#include <iostream>
#include <cstdint>

class Color {
private:
	uint8_t red, green, blue;
	bool isColorValid(int color);
public:
	Color(int r = 0, int g = 0, int b = 0);

	friend std::ostream& operator<<(std::ostream& os, const Color& color);
	friend std::istream& operator>>(std::istream& is, Color& color);
};