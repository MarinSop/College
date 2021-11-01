#include <vector>
#include <iostream>
#include "inputAndOutput.hpp"


std::vector<int> vectorFilter(std::vector<int>& vA, std::vector<int>& vB)
{
	std::vector<int> temp;
	for (int i = 0; i < vA.size(); i++)
	{
		bool b = true;
		for (int j = 0;j < vB.size(); j++)
		{
			if (vA[i] == vB[j])
			{
				b = false;
				break;
			}
		}
		if (b)
			temp.push_back(vA[i]);
	}
	return temp;

}

int main()
{
	std::vector<int> vecA;
	std::vector<int> vecB;
	int n;
	std::cout << "Unesite broj brojeva" << std::endl;
	std::cin >> n;
	vectorInput(vecA,n);
	int a, b;
	std::cout << "Unesite interval" << std::endl;
	std::cin >> a >> b;
	vectorInputInterval(vecB, a, b);
	vectorPrint(vecA);
	vectorPrint(vecB);
	std::vector<int> vecC = vectorFilter(vecA, vecB);
	vectorPrint(vecC);






	return 0;
}