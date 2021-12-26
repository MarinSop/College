#include "HumanPLayer.h"


void HumanPLayer::setHand()
{
    hand.clear();
    int handSize = 0;
    while (handSize < 3)
    {
        std::cout << name << " odaberi kovanice, 0 za prekid" << std::endl;
        int coin;
        std::cin >> coin;
        if (coin == 0)
            break;
        else if (std::find(hand.begin(), hand.end(), coin) != hand.end() || (coin != 1 && coin != 2 && coin != 5))
            std::cout << "Uzmite drugu kovanicu" << std::endl;
        else
        {
            hand.push_back(coin);
            handSize++;
        }
    }
}

void HumanPLayer::guess()
{
    std::cout << name << " pogaða broj kovanica " << std::endl;
    std::cin >> playerGuess;
}
