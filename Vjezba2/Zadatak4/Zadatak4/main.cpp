#include "MyVector.h"
#include <iostream>

int main()
{
	MyVector v;
	v.vector_new();
	int i;
	while (std::cin >> i)
		v.vector_push_back(i);
	v.vector_print();
	v.vector_pop_back();
	v.vector_print();
	v.vector_pop_back();
	v.vector_print();
	v.vector_push_back(100);
	v.vector_print();
	std::cout << "First element: " << v.vector_front() << std::endl;
	std::cout << "Last element: " << v.vector_back() << std::endl;
	v.vector_delete();


}