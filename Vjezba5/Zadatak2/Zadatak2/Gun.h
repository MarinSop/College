#pragma once
#include "Position.h"
#include <iostream>

class Gun
{
public:
	Gun(int a,int b);
	~Gun();
	void shoot(char c);
	void reload(char c);
private:
	Position pos;
	const int maxAmmo = 30;
	int currentAmmo = maxAmmo;

};

