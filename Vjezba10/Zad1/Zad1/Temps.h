#pragma once
#include <iostream>

template<typename T>
void sort(T arr[], int n)
{
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				T temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

template<>
void sort<char>(char arr[], int n)
{
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (tolower(arr[j]) > tolower(arr[j + 1])) {
				char temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}



template<typename T>
void PrintArray(T arr[], int n)
{
	for (int i = 0; i < n; ++i)
		std::cout << arr[i] << " ";
		std::cout << "\n\n";
}



