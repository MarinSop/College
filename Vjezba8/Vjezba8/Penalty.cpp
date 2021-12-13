#include "Penalty.h"

Penalty::Penalty(int p)
{
	penalty = p;
}

void Penalty::operator()(Timer& t)
{
	double timeInSec = t.getH() * 3600 + t.getM() * 60 + t.getS();
	timeInSec += penalty;
	t.setH(timeInSec / 3600);
	t.setM((timeInSec / 60) - t.getH() * 60);
	t.setS(timeInSec - t.getM() * 60 - t.getH() * 3600);
}
