#include <iostream>
#include "Target.h"

int main()
{
	Target t(1, 11);
	std::cout << "Pos A: X:" << t.getPosA().getX() << " Y: " << t.getPosA().getY() << " Z: " << t.getPosA().getZ() << std::endl;
	std::cout << "Pos B: X:" << t.getPosB().getX() << " Y: " << t.getPosB().getY() << " Z: " << t.getPosB().getZ() << std::endl;
	std::cout << "Did target get hit? " << t.isHit() << std::endl;
	return 0;
}