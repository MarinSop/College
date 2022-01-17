#pragma once
#include <iostream>
template<typename T>
class Stack
{
public:
	void push(T el);
	
	void pop();
	bool is_empty();
	void print();
private:
	T* arr;
	int size = 0;
};

template<typename T>
inline void Stack<T>::push(T el)
{
	size += 1;
	T* tmp = new T[size];
	for (int i = 0; i < size - 1; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[size-1] = el;
	delete arr;
	arr = tmp;
}

template<typename T>
inline void Stack<T>::pop()
{
	if (size > 0)
	{
		size -= 1;
		T* tmp = new T[size];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = arr[i];
		}
		delete arr;
		arr = tmp;
	}
}

template<typename T>
inline bool Stack<T>::is_empty()
{
	if (size > 0)
		return true;
	else
		return false;
}

template<typename T>
inline void Stack<T>::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "[" << arr[i] << "] ";
	}
		std::cout << std::endl;
}
