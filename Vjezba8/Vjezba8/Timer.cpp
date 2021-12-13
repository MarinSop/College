#include "Timer.h"
int Timer::getH()
{
	return h;
}
int Timer::getM()
{
	return m;
}
double Timer::getS()
{
	return s;
}
void Timer::setH(int hrs)
{
	h = hrs;
}
void Timer::setM(int min)
{
	m = min;
}
void Timer::setS(double sec)
{
	s = sec;
}
Timer::Timer(int hrs, int min, double sec)
{
	h = hrs;
	m = min;
	s = sec;
}

Timer::Timer()
{
	h = 0;
	m = 0;
	s = 0;
}

Timer& Timer::operator+=(Timer& t)
{
	double timeInSecs = (h * 3600) + (m * 60) + s;
	double timeInSecsPar = (t.h * 3600) + (t.m * 60) + t.s;
	timeInSecs += timeInSecsPar;
	h = timeInSecs / 3600;
	m = (timeInSecs / 60) - h*60;
	s = timeInSecs - m * 60 - h * 3600;
	return *this;
}

Timer& Timer::operator/=(int n)
{
	double timeInSecs = ((h * 3600) + (m * 60) + s) / n;
	h = timeInSecs / 3600;
	m = (timeInSecs / 60) - h * 60;
	s = timeInSecs - m * 60 - h * 3600;
	return *this;
}

Timer& Timer::operator-(const Timer& t)
{
	double timeInSecA = h * 3600 + m * 60 + s;
	double timeInSecB = t.h * 3600 + t.m * 60 + t.s;
	timeInSecA = timeInSecA - timeInSecB;
	h = timeInSecA / 3600;
	m = (timeInSecA / 60) - h * 60;
	s = timeInSecA - m * 60 - h * 3600;
	return *this;
}

Timer::operator double() const
{
	double timeInSec = h * 3600 + m * 60 + s;
	return timeInSec;
}

std::ostream& operator<<(std::ostream& os, const Timer& t)
{
	os << t.h << ":" << t.m << ":" << t.s;
	return os;
}

bool operator<(const Timer& a, const Timer& b)
{
	double timeInSecA = a.h * 3600 + a.m * 60 + a.s;
	double timeInSecB = b.h * 3600 + b.m * 60 + b.s;
	return timeInSecA < timeInSecB;
}
