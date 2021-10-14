#include <iostream>
#include <time.h>

void minMax(int* arr,int& max, int& min, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
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
	int max = arr[0];
	int min = arr[0];
	std::cout << std::endl;

	minMax(arr, max, min, n);
	std::cout << "Max: " << max << " | Min: " << min << std::endl;
	return 0;
}