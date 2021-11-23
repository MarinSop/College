#include "Gun.h"

Gun::Gun(int a, int b)
{
	pos.pseudoInit(a, b);
}

Gun::~Gun()
{
}

void Gun::shoot(char c)
{
	if (c == 's' && currentAmmo > 0)
	{
		std::cout << "Pew!" << std::endl;
		currentAmmo--;
		std::cout << "Current ammo: " << currentAmmo << std::endl;
	}
	else if (c == 's' && currentAmmo <= 0)
	{
		std::cout << "No ammo! RELOAD" << std::endl;
	}
}

void Gun::reload(char c)
{
	if (c == 'r')
	{
		std::cout << "Reloading!" << std::endl;
		currentAmmo = maxAmmo;
		std::cout << "Current ammo: " << currentAmmo << std::endl;
	}
}

Position Gun::getPos()
{
	return pos;
}
