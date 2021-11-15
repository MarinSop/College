#include <iostream>
#include "Position.h"

int main()
{
	Position p1;
	int x;
	int z;
	int y;
	std::cin >> x >> y >> z;
	std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;
	p1.init(x, y, z);
	Position p2;
	p2.pseudoInit(1, 10);
	std::cout << "x: " << p2.getX() << " y: " << p2.getY() << " z: " << p2.getZ() << std::endl;
	std::cout << "2D length: " << p1.lenght2D(p2) << std::endl;
	std::cout << "3D length: " << p1.lenght3D(p2) << std::endl;
	return 0;
}