#include <iostream>

void minMax(int* arr, int a, int* min, int* max)
{
	if (a < 0)
		return;
	if (arr[a] < *min)
		*min = arr[a];
	if (arr[a] > *max)
		*max = arr[a];
	return minMax(arr, --a, min, max);
}

int main()
{
	srand(time(NULL));
	int a = 0;
	std::cout << "Unesite velicinu niza" << std::endl;
	std::cin >> a;
	int* arr = new int[a];
	
	for (int i = 0; i < a; i++)
	{
		arr[i] = rand() % 100;
		std::cout << "[ " << arr[i] << " ]  ";
	}
	std::cout << std::endl;
	int min = arr[0];
	int max = arr[0];
	minMax(arr, a-1, &min, &max);
	std::cout << "Max: " << max << " | Min: " << min << std::endl;
}