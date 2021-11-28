#include <iostream>
#include "Board.h"

int main()
{
	Point p(10, 10);
	Point pUp(10, 9);
	Point pA(1, 1);
	Point pB(8, 6);
	Board b = Board(30,15,'0');
	b.draw_char(p, '*');
	b.draw_up_line(pUp, 'U');
	b.draw_line(pA, pB, 'L');
	b.display();



	return 0;
}