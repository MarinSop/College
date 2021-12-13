#pragma once
#include "Timer.h"
class Penalty
{
	int penalty;
public:
	Penalty(int p);
	void operator()(Timer& t);

};
