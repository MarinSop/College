#include <iostream>
#include "Temps.h"

int main()
{
	int arrInt[] = { 1,5,2,7,6,5,4,8,7,4,12,32,21,4,99 };
	char arrChar[] = { 'a','c','d','e','f','g','C','D'};
	int nInt = sizeof(arrInt) / sizeof(int);
	int nChar = sizeof(arrChar) / sizeof(char);
	sort<int>(arrInt, nInt);
	PrintArray(arrInt, nInt);
	sort<char>(arrChar, nChar);
	PrintArray(arrChar, nChar);



}