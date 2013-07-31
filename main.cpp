#include <iostream>

#include "CubicBezier2d.h"

int main(int argc, const char * argv[])
{
	if(argc > 1)
	{
		std::cout << "Arguments are not suppoted! (yet)\n";
		return 1;
	}
	
	CubicBezier2d bezier;
	
	std::cout << "Welcome to the Bezier Equation Calculator!\n";
	std::cout << "Created by Miguel Martin. Copyright (C) 2013.\n";
	std::cout << "\nPress [CTRL]+C to exit.";
	
	while((std::cout << "\n\nEnter your bezier curve:\n"), std::cin >> bezier)
	{
		std::cout << "Equations of Bezier Curve:\n";
		std::cout << bezier;
	}
	
    return 0;
}