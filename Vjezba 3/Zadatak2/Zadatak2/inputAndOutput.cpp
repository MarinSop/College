#include "inputAndOutput.hpp"

void vectorPrint(std::vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << "[" << v[i] << "] ";
    }
    std::cout << std::endl;

}

void vectorInput(std::vector<int>& v, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        v.push_back(rand() % 10);
    }

}
void vectorInputInterval(std::vector<int>& v, int a, int b)
{
    int min = a < b ? a : b;
    int max = a > b ? a : b;
    int x;
    std::cout << "Unesite broj izmedu " << min << " i " << max << std::endl;
    std::cin >> x;
    while (x > min && x < max)
    {
        v.push_back(x);
        std::cout << "Unesite broj izmedu " << min << " i " << max << std::endl;
        std::cin >> x;
    }

}