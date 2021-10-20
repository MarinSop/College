#include <iostream>
#include <time.h>

int& findIndexRef(int* arr,int n)
{
	std::cout << "Pozicija elementa" << std::endl;
	int i = 0;
	std::cin >> i;
	if (i <= n)
		return arr[i];
	else
	{
		return arr[0];
	}
}

int main()
{
	srand(time(NULL));
	int n = 0;
	std::cout << "Unesite velicinu niza" << std::endl;
	std::cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	int& index = findIndexRef(arr, n);
	std::cout << "Your number: " << index << std::endl;
	index++;
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
}