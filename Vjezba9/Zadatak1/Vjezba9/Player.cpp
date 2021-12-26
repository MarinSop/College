#include "Player.h"

Player::Player()
{
    std::cout << "Unesite naziv igraèa: " << std::endl;
    std::cin >> name;

}

int Player::getHandSum()
{
    int sum = 0;
    int size = hand.size();
    for (int i = 0; i < size; i++)
    {
        sum += hand[i];
    }
    return sum;
}

void Player::printHand()
{
    std::cout << name << " had: ";
    int size = hand.size();
    for (int i = 0; i < size; i++)
    {
        std::cout << hand[i] << " ";
    }
    std::cout << std::endl;
}

