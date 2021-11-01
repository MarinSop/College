#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	std::vector<std::string> vec;
	std::cout << "Koliko stringova? " << std::endl;
	int n;
	std::cin >> n;
	std::string str;
	std::cout << "Unesite string" << std::endl;
	std::cin >> str;
	vec.push_back(str);
	for (int i = 1; i < n; i++)
	{
		std::cout << "Unesite string" << std::endl;
		std::cin >> str;
		vec.push_back(str);
	}
	std::cout << "----------------ORIGINAL----------------" << std::endl;
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << i << ": " << vec[i] << std::endl;
	}
	std::cout << "----------------REVERSED----------------" << std::endl;
	for (int i = 0; i < vec.size(); i++)
	{
		std::reverse(vec[i].begin(), vec[i].end());
		std::cout << i << ": " << vec[i] << std::endl;
	}
	std::cout << "----------------SORTED----------------" << std::endl;
	std::sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << i << ": " << vec[i] << std::endl;
	}




	return 0;
}