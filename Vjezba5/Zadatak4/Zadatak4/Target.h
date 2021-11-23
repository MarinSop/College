#pragma once
#include "Position.h"
#include <time.h>
class Target
{
public:
	Target(int a, int b);
	~Target();
	Position getPosA();
	Position getPosB();
	bool isHit();
	void change(bool b);

private:
	Position pA;
	Position pB;
	bool hit = false;
};

