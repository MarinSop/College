#include <iostream>
#include <vector>
#include <time.h>

void eraseElement(std::vector<int>& v, int i)
{
	v.erase(v.begin() + i);
}


int main()
{
	srand(time(NULL));
	std::vector<int> vec;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		vec.push_back(rand() % 100);
		std::cout << "[" << vec[i] << "]";
	}
	std::cout << std::endl;
	int ind;
	std::cout << "Enter index you wish to erase (must be higher or equal to 0 and lower than " << vec.size() << ")" << std::endl;
	std::cin >> ind;
	if (ind >= 0 && ind < vec.size())
		eraseElement(vec, ind);
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << "[" << vec[i] << "]";
	}
	std::cout << std::endl;


	return 0;
}