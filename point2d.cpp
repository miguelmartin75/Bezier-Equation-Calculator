#include "point2d.h"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const point2d& pt)
{
	os << "(" << pt.x << ", " << pt.y << ")";
	return os;
}

std::istream& operator>>(std::istream& is, point2d& pt)
{
	std::cout << "X: ";
	is >> pt.x;
	std::cout << "Y: ";
	is >> pt.y;
	return is;
}