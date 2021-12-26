#pragma once
#include "Player.h"
class ComputerPlayer : public Player
{
public:
	void setHand();
	void guess(int maxGuessValue);
};

