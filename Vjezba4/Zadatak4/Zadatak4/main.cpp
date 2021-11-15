#include <iostream>
#include <vector>
#include "Target.h"
#include "Gun.h"
#include "Position.h"

int main()
{
	std::vector<Target> targets;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		Target t(-40,40);
		targets.push_back(t);
	}
	Gun g(-10,10);
	int hitTarget = 0;
	for (int i = 0; i < n; i++)
	{
		if (targets[i].getPosA().getX() < g.getPos().getX() && targets[i].getPosA().getY() < g.getPos().getY() &&
			targets[i].getPosB().getX() > g.getPos().getX() && targets[i].getPosB().getY() > g.getPos().getY())
		{
			hitTarget++;
		}
	}
	std::cout << hitTarget << std::endl;
	return 0;
}