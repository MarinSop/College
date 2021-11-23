#pragma once
#include <random>
class Position
{
public:
	void init(double _x = 0, double _y = 0, double _z = 0);
	void pseudoInit(int a,int b);
	int getX();
	int getY();
	int getZ();
	float lenght2D(Position b);
	float lenght3D(Position b);
private:
	double x = 0;
	double y = 0;
	double z = 0;
};

