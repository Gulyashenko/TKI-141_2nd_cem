#pragma once
#include <iostream>
#include <cmath>

class Points
{
private:

public:
	void DoesThePointBelongToTheLine(const double x1, const double y1, const double z1, 
		const double x2, const double y2, const double z2,
		const double x0, const double y0, const double z0);
	double DistanceFromPointToLine(const double x1, const double y1, const double z1,
		const double x2, const double y2, const double z2,
		const double x0, const double y0, const double z0);
};