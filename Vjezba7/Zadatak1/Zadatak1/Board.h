#pragma once
#include <iostream>
#include "Point.h"
class Board
{
	char** matrix;
	int rows;
	int cols;
	char ch;
public:
	Board();
	Board(int _rows, int _cols, char _ch);
	Board(const Board& b);
	Board(Board&& b);
	~Board();

	void draw_char(Point p, char c);
	void draw_up_line(Point p, char c);
	void draw_line(Point pA, Point pB, char c);
	void display();
};

