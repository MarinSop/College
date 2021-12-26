#pragma once
#include <vector>
#include <iostream>
class Player
{
public:
	Player();

	int getHandSum();
	void printHand();

	std::string name;
	std::vector<int> hand;
	int score = 0;
	int playerGuess;
};

