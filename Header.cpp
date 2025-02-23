#include "Header.h"

void Points::DoesThePointBelongToTheLine(const double x1, const double y1, const double z1,
    const double x2, const double y2, const double z2,
    const double x0, const double y0, const double z0)
{
	if ((x0 - x1) / (x2 - x1) == (y0 - y1) / (y2 - y1) and (x0 - x1) / (x2 - x1) == (z0 - z1) / (z2 - z1)) {
		std::cout << "Point P belongs to the line" << std::endl << "The distance from the point to the line is: 0";
	}
	else {
        double distance = Points::DistanceFromPointToLine(x1, y1, z1, x2, y2, z2, x0, y0, z0);
            std::cout << "Point P doesn`t belong to the line" << std::endl << "The distance from a point to the line is: " << distance;
	}
}

double Points::DistanceFromPointToLine(const double x1, const double y1, const double z1,
    const double x2, const double y2, const double z2,
    const double x0, const double y0, const double z0)
{
    // Вычисляем разности координат
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dz = z2 - z1;

    // Вычисляем квадрат длины вектора AB
    double AB_squared = dx * dx + dy * dy + dz * dz;

    // Вычисляем вектор AP
    double APx = x0 - x1;
    double APy = y0 - y1;
    double APz = z0 - z1;

    // Вычисляем скалярное произведение AP и AB
    double dotProduct = APx * dx + APy * dy + APz * dz;

    // Вычисляем параметр t проекции точки P на прямую AB
    double t = dotProduct / AB_squared;

    // Вычисляем координаты проекции точки P на прямую AB
    double projectionX = x1 + t * dx;
    double projectionY = y1 + t * dy;
    double projectionZ = z1 + t * dz;

    // Вычисляем расстояние между точкой P и её проекцией на прямую AB
    double distance = std::sqrt((x0 - projectionX) * (x0 - projectionX) +
        (y0 - projectionY) * (y0 - projectionY) +
        (z0 - projectionZ) * (z0 - projectionZ));

    return distance;
}