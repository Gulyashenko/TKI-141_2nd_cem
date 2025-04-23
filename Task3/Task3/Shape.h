#pragma once

#include <iostream>

class Shape {
public:
	virtual void draw(std::ostream& os) const = 0;
	friend std::ostream& operator<<(std::ostream os, Shape& shape) { shape.draw(os); return os; }
};