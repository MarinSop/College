#include "MyVector.h"
#include <iostream>

void MyVector::vector_new()
{
	current = 0;
	capacity = 1;
	arr = new int[capacity];
}

void MyVector::vector_delete()
{
	delete arr;
}

void MyVector::vector_push_back(int a)
{
	if (current == capacity)
	{
		int* temp = new int[2*capacity];
		for (int i = 0; i < capacity; i++)
		{
			temp[i] = arr[i];
		}
		delete arr;
		capacity *= 2;
		arr = temp;
	}
	arr[current] = a;
	++current;
}

void MyVector::vector_pop_back()
{
	--current;
	int* temp = new int[capacity];
	for (int i = 0; i < current; i++)
	{
		temp[i] = arr[i];
	}
	delete arr;
	arr = temp;
}

int& MyVector::vector_front()
{
	return arr[0];
}


int& MyVector::vector_back()
{
	return arr[current - 1];
}

int MyVector::vector_size()
{
	return current;
}

void MyVector::vector_print()
{
	for (int i = 0; i < current; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

