#include "Brojac.h"

Brojac::Brojac(std::vector<Zivotinja> z)
{
	int size = z.size();
	int sumLegs = 0;
	for (int i = 0; i < size; i++)
	{
		std::cout << "Dodan: " << z[i].getSpecie() << std::endl;
		sumLegs += z[i].getNumOfLegs();
	}
	std::cout << "Ukupno nogu: " << sumLegs << std::endl;
}
