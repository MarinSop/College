#include <iostream>
#include "Stack.h"

int main()
{
	Stack<char> s;
	std::cout << "Stack is empty = " << s.is_empty() << std::endl;
	s.push('a');
	s.push('b');
	s.push('c');
	s.print();
	s.pop();
	s.print();
	std::cout << "Stack is empty = " << s.is_empty() << std::endl;





}