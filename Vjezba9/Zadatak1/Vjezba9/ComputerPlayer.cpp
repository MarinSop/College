#include "ComputerPlayer.h"

void ComputerPlayer::setHand()
{
	hand.clear();
	int i = 0;
	while(i < 3)
	{
		int randNum = rand() % (3 + 1);
		if (randNum == 0)
			break;
		else if (randNum == 1 && !(std::find(hand.begin(), hand.end(), 1) != hand.end()))
		{
			hand.push_back(1);
			i++;
		}
		else if (randNum == 2 && !(std::find(hand.begin(), hand.end(), 2) != hand.end()))
		{
			hand.push_back(2);
			i++;
		}
		else if (randNum == 3 && !(std::find(hand.begin(), hand.end(), 5) != hand.end()))
		{
			hand.push_back(5);
			i++;
		}
	}
}

void ComputerPlayer::guess(int maxGuessValue)
{
	playerGuess = rand() % (maxGuessValue + 1);
}
