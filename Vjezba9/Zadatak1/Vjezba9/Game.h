#pragma once
#include "HumanPLayer.h"
#include "ComputerPlayer.h"
class Game
{
public:
	Game();

	void game();
	int allHandSum();
	void guess();
	void endOfRound();
	bool isGameOver();
private:
	int maxScore;
	std::vector<HumanPLayer> _players;
	std::vector<ComputerPlayer> _computerPlayers;
	bool _gameRunning = true;
	int numOfPlayers;
	int numToGuess = 0;
};

