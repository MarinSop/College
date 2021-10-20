#include "Rectangle.h"
#include <iostream>;
void Rectangle::create()
{
	std::cout << "Enter the value of x, y for the first point" << std::endl;
	std::cin >> xA;
	std::cin >> yA;
	std::cout << "Enter the value of x, y for the second point" << std::endl;
	std::cin >> xB;
	std::cin >> yB;
}