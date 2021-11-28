#include "Board.h"

Board::Board()
{
	rows = 12;
	cols = 12;
	ch = '0';
	matrix = new char* [cols];
	for (int i = 0; i < cols; i++)
	{
		matrix[i] = new char[rows];
		if (i == 0)
			std::fill_n(matrix[i], rows, ch);
		else if (i == cols - 1)
			std::fill_n(matrix[i], rows, ch);
		else
		{
			matrix[i][0] = ch;
			matrix[i][rows - 1] = ch;
		}
	}
}

Board::Board(int _rows,int _cols, char _ch)
{
	rows = _rows + 2;
	cols = _cols + 2;
	ch = _ch;
	matrix = new char* [cols];
	for (int i = 0; i < cols; i++)
	{
		matrix[i] = new char[rows];
		if (i == 0)
			std::fill_n(matrix[i], rows, ch);
		else if (i == cols - 1)
			std::fill_n(matrix[i], rows, ch);
		else
		{
			matrix[i][0] = ch;
			matrix[i][rows - 1] = ch;
		}
	}
}

Board::Board(const Board& b)
{
	rows = b.rows;
	cols = b.cols;
	ch = b.ch;
	matrix = b.matrix;
}

Board::Board(Board&& b)
{
	rows = b.rows;
	cols = b.cols;
	ch = b.ch;
	matrix = b.matrix;
	b.rows = 0;
	cols = 0;
	ch = '0';
	b.matrix = nullptr;
}

Board::~Board()
{
	delete matrix;
}

void Board::draw_char(Point p, char c)
{
	if ((p.x > 0 && p.x < rows - 1) && (p.y < cols - 1 && p.y > 0))
	{
		matrix[int(p.y)][int(p.x)] = c;
	}
}

void Board::draw_up_line(Point p, char c)
{
	if ((p.x > 0 && p.x < rows - 1) && (p.y < cols - 1 && p.y > 0))
	{
		for (int i = 1; i < cols; i++)
		{
			if (i > p.y)
			{
				break;
			}
			matrix[i][int(p.x)] = c;
		}
	}
}

void Board::draw_line(Point pA, Point pB, char c)
{
	if (((pA.x > 0 && pA.x < rows - 1) && (pA.y < cols - 1 && pA.y > 0)) &&
		((pB.x > 0 && pB.x < rows - 1) && (pB.y < cols - 1 && pB.y > 0)))
	{
		int x0 = pA.x < pB.x ? pA.x : pB.x;
		int x1 = pA.x > pB.x ? pA.x : pB.x;
		int y0 = pA.y < pB.y ? pA.y : pB.y;
		int y1 = pA.y > pB.y ? pA.y : pB.y;
		int dx = x1 - x0;
		int	dy = y1 - y0;
		int	D = 2 * dy - dx;
		int	y = y0;
		for (int x = x0; x <= x1; x++)
		{
			matrix[y][x] = c;
			if (D > 0)
			{
				y++;
				D = D - 2 * dx;
			}
			D = D + 2 * dy;
		}
	}
}


void Board::display()
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}

}
