#include <iostream>

void minMax(int* arr,int a)
{
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < a; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	std::cout << "Max: " << max << " | Min: "<< min << std::endl;
}


int main()
{
	srand(time(NULL));
	std::cout << "Unesite velicinu niza" << std::endl;
	int a = 0;
	std::cin >> a;
	int* arr = new int[a];
	for (int i = 0; i < a; i++)
	{
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < a; i++)
	{
		std::cout << "[ " << arr[i] << " ]  ";
	}
	std::cout << std::endl;
	minMax(arr, a);




}