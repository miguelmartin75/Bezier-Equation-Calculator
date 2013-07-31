#include "CubicBezier2d.h"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const CubicBezier2d& bezier)
{
	os << "x(t) = ";
	os << bezier.getAx() << "t^3 + " << bezier.getBx() << "t^2 + " << bezier.getCx() << "t + " << bezier.getDx() ;
	
	os << "\n";
	
	os << "y(t) = ";
	os << bezier.getAy() << "t^3 + " << bezier.getBy() << "t^2 + " << bezier.getCy() << "t + " << bezier.getDy();

	return os;
}

std::istream& operator>>(std::istream& is, CubicBezier2d& bezier)
{
	std::cout << "Starting Point:\n";
	is >> bezier.getStart();
	
	std::cout << "Control Point 1:\n";
	is >> bezier.getControlPoint1();
	
	std::cout << "Control Point 2:\n";
	is >> bezier.getControlPoint2();
	
	std::cout << "Ending Point:\n";
	is >> bezier.getEnd();
	
	return is;
}