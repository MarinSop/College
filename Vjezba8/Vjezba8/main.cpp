#include <iostream>
#include <vector>
#include "Timer.h"
#include "Penalty.h"
#include <algorithm>

int main() {
    std::vector<Timer> v{ {2, 6, 9.118}, {2, 6, 15.251}, {2, 6, 9.925}, {2, 7, 15.222}, {2, 7, 10.775} };
    std::cout << 15 % 2 << std::endl;
    //prosjecno vrijeme
    Timer avg;
    for (auto t : v)
        avg += t;
    avg /= v.size();
    std::cout << "avg " << avg << std::endl;

    // vrijeme najbrzeg (operator<)
    Timer tmax = *min_element(v.begin(), v.end());
    std::cout << "min " << tmax << std::endl;

    // zaostajanje za vodecim u sekundama
    for (auto& tm : v)
        std::cout << double(tm - tmax) << std::endl;

    // penaliziranje vozaca s m sekundi (funkcijski objekt)
    Penalty p(5);
    for (auto& tm : v)
        p(tm);
}