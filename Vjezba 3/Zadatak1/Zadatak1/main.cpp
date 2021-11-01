#include <iostream>
#include <vector>
#include "inputAndOutput.hpp"

int main()
{
    std::vector<int> vecA;
    std::vector<int> vecB;
    int n;
    std::cout << "Unesite broj brojeva" << std::endl;
    std::cin >> n;
    vectorInput(vecA, n);
    std::cout << "Unesite intervale" << std::endl;;
    int a;
    int b;
    std::cin >> a >> b;

    vectorInputInterval(vecB, a, b);
    vectorPrint(vecA);
    vectorPrint(vecB);


    return 0;
}