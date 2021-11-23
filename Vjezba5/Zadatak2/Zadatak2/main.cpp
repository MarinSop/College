#include <iostream>
#include "Position.h"
#include "Gun.h"

int main()
{
	Gun g;
	std::cout << "Type s to shoot, r to reload and e to exit program" << std::endl;
	char c = 'a';
	while (c != 'e')
	{
		std::cin >> c;
		g.shoot(c);
		g.reload(c);
	}

	return 0;
}