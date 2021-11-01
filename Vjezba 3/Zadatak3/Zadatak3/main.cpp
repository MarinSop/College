#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

int main()
{
	srand(time(NULL));
	int n;
	std::cin >> n;
	std::vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		vec.push_back(rand() % 100);
		std::cout << "[" << vec[i] << "] ";
	}
	std::cout << std::endl;
	std::sort(vec.begin(), vec.end());
	std::cout << "--------------------SORTED VECTOR--------------------" << std::endl;
	int lwIndex = 0;
	int hgIndex = 0;
	int sum = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << "[" << vec[i] << "] ";
		if (vec[i] < vec[lwIndex])
			lwIndex = i;
	}
	std::cout << std::endl;
	vec.insert(vec.begin() + lwIndex, 0);
	std::cout << "--------------------0 IN FRONT LOWEST--------------------" << std::endl;
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << "[" << vec[i] << "] ";
		if (vec[i] > vec[hgIndex])
			hgIndex = i;
		sum += vec[i];
	}
	std::cout << std::endl;
	vec.insert(vec.begin() + hgIndex, sum);
	std::cout << "--------------------SUM IN FRONT HIGHEST--------------------" << std::endl;
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << "[" << vec[i] << "] ";
	}
	std::cout << std::endl;
	return 0;
}