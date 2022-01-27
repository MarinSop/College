#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


class X {
public:
	std::string err;
	X(const char* s) : err(s) {}
};


void load(std::vector<int>* v)
{
	std::ifstream fin("numbers.txt");
	if (!fin)
		throw X("File not found");
	std::istream_iterator<int> it(fin);
	std::istream_iterator<int> eos; // end of stream (default ctor)
	std::copy(it, eos, back_inserter(*v));
}


int main()
{
	std::vector<int> v;
	try
	{
		load(&v);
	}
	catch (X x)
	{
		std::cout << x.err<< std::endl;
	}
	int t = 500;
	int num = std::count_if(v.begin(), v.end(), [t](int x) {return x > t; });
	auto max = std::max_element(v.begin(), v.end());
	auto min = std::min_element(v.begin(), v.end());
	std::cout << "Greater than 500: " << num << " | " << " Min : " << *min << " | " << " Max: " << *max << std::endl;
	v.erase(std::remove_if(v.begin(), v.end(), [](const int& x) {return x < 300; }),v.end());
	std::sort(v.begin(), v.end(),std::greater<int>());
	std::ostream_iterator<int> it(std::cout, "\n");
	copy(v.begin(), v.end(), it);

	

}