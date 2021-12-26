#pragma once
#include <string>
class Zivotinja
{
public:
	int getNumOfLegs();
	std::string getSpecie();

protected:
	std::string species;
	int numberLegs;
};

