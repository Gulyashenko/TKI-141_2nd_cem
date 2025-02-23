#include "Header.h"

int main(void) {
	double x1, y1, z1, x2, y2, z2, x0, y0, z0;
	std::cout << "Enter the coordinates of two points (A and B) that will define the equation of the line (AB)" << std::endl;
	std::cout << "Enter the coordinates of the first point (A)" << std::endl;
	std::cin >> x1;
	std::cin >> y1;
	std::cin >> z1;
	std::cout << "Enter the coordinates of the second point (B)" << std::endl;
	std::cin >> x2;
	std::cin >> y2;
	std::cin >> z2;
	std::cout << "Enter the coordinates of the third point (P)" << std::endl;
	std::cin >> x0;
	std::cin >> y0;
	std::cin >> z0;

	Points answer;
	answer.DoesThePointBelongToTheLine(x1, y1, z1, x2, y2, z2, x0, y0, z0);
}