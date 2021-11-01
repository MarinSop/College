#include <iostream>
#include <string>

int stringOccurrences(std::string& a, std::string& b)
{
	int num = 0;
	size_t pos = a.find(b);
	while (pos != std::string::npos)
	{
		++num;
		pos = a.find(b,b.size() + pos);
	}
	return num;
}


int main()
{
	std::string sA = "ovo je ovo string ovo je string ovo";
	std::string sB = "ovo";
	std::cout << "String se ponavlja " << stringOccurrences(sA, sB) << " puta." << std::endl;


	return 0;
}