#include "Position.h"

void Position::init(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void Position::pseudoInit(int a, int b)
{
	int max = a > b ? a : b;
	int min = a < b ? a : b;
	std::random_device rd;   
	std::mt19937 rng(rd());   
	std::uniform_int_distribution<int> uni(min, max);
	x = uni(rng);
	y = uni(rng);
	z = uni(rng);
}

int Position::getX()
{
	return x;
}

int Position::getY()
{
	return y;
}

int Position::getZ()
{
	return z;
}

float Position::lenght2D(Position b)
{
	float len = sqrt((b.getX() - x) * (b.getX() - x) + (b.getY() - y) * (b.getY() - y));
	return len;
}

float Position::lenght3D(Position b)
{
	float len = sqrt((b.getX() - x) * (b.getX() - x) + (b.getY() - y) * (b.getY() - y) + (b.getZ() - z) * (b.getZ() - z));
	return len;
}
