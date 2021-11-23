#include "Target.h"


Target::Target(int a, int b)
{
	srand(time(NULL));
	pA.pseudoInit(a, b);
	double _x;
	double _y;
	double _z;
	_x = pA.getX() + rand() % ((pA.getX() * 3 + 1) - pA.getX());
	_y = pA.getY() + rand() % ((pA.getY() * 3 + 1) - pA.getY());
	_z = pA.getZ() + rand() % ((pA.getZ() * 3 + 1) - pA.getZ());
	pB.init(_x, _x, _z);
}

Target::~Target()
{
}

Position Target::getPosA()
{
	return pA;
}

Position Target::getPosB()
{
	return pB;
}

bool Target::isHit()
{
	return hit;
}

void Target::change(bool b)
{
	hit = b;
}
