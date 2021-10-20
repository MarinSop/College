#include <iostream>
#include "circle.h"
#include "Rectangle.h"

int intersection(circle c, Rectangle* r,int n)
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if ((((r[i].xA - c.x) * (r[i].xA - c.x)) + ((r[i].yA - c.y) * (r[i].yA - c.y))) <= (c.r * c.r))
			res++;
		else if ((((r[i].xB - c.x) * (r[i].xB - c.x)) + ((r[i].yB - c.y) * (r[i].yB - c.y))) <= (c.r * c.r))
			res++;
	}
	return res;
}

int main()
{
	circle c;
	c.create();
	Rectangle* r;
	int n = 0;
	std::cout << "Enter the length of the array" << std::endl;
	std::cin >> n;
	r = new Rectangle[n];
	for (int i = 0; i < n; i++)
	{
		r[i].create();
	}

	std::cout << "Number of interescting rectangles: " << intersection(c, r, n) << std::endl;

	return 0;
}