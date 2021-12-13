#pragma once
#include <iostream>
class Timer
{
	int h;
	int m;
	double s;
public:
	int getH();
	int getM();
	double getS();
	void setH(int hrs);
	void setM(int min);
	void setS(double sec);
	Timer(int hrs, int min, double sec);
	Timer();
	Timer& operator+=(Timer& t);
	Timer& operator/=(int n);
	Timer& operator-(const Timer& a);
	operator double() const;
	friend std::ostream& operator<<(std::ostream& os, const Timer& t);
	friend bool operator<(const Timer& a, const Timer& b);

};

