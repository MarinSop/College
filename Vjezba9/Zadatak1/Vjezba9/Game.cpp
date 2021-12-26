#include "Game.h"

Game::Game()
{
	std::cout << "Unesite broj bodova do koliko se igra:" << std::endl;
	std::cin >> maxScore;
	std::cout << "Unesite broj pravih igraca: " << std::endl;
	int realPlayers;
	std::cin >> realPlayers;
	numOfPlayers += realPlayers;
	for (int i = 0; i < realPlayers; i++)
	{
		HumanPLayer p;
		_players.push_back(p);
	}
	std::cout << "Unesite broj kompjuterskih igraca: " << std::endl;
	int compPlayers;
	std::cin >> compPlayers;
	numOfPlayers += compPlayers;
	for (int i = 0; i < compPlayers; i++)
	{
		ComputerPlayer p;
		_computerPlayers.push_back(p);
	}
	if(maxScore == 0 || (realPlayers == 0 && compPlayers == 0))
		_gameRunning = false;
}

void Game::game()
{
	while (_gameRunning)
	{
		int realPlayerSize = _players.size();
		for (int i = 0; i < realPlayerSize; i++)
		{
			_players[i].setHand();
		}
		int compPlayerSize = _computerPlayers.size();
		for (int i = 0; i < compPlayerSize; i++)
		{
			_computerPlayers[i].setHand();
		}
		guess();
		endOfRound();
		_gameRunning = isGameOver() ? false : true;
	}
}

int Game::allHandSum()
{
	int sum = 0;
	int pS = _players.size();
	for (int i = 0; i < pS; i++)
	{
		sum += _players[i].getHandSum();
	}
	int cS = _computerPlayers.size();
	for (int i = 0; i < cS; i++)
	{
		sum += _computerPlayers[i].getHandSum();
	}
	
	return sum;
}

void Game::guess()
{

	numToGuess = allHandSum();
	int pS = _players.size();
	for (int i = 0; i < pS; i++)
	{
		_players[i].guess();
	}
	int cS = _computerPlayers.size();
	for (int i = 0; i < cS; i++)
	{
		_computerPlayers[i].guess(numOfPlayers);
	}
}

void Game::endOfRound()
{
	std::vector<Player*> winners;
	int pS = _players.size();
	for (int i = 0; i < pS; i++)
	{
		_players[i].printHand();
		if (_players[i].playerGuess == numToGuess)
			winners.push_back(&_players[i]);
	}
	int cS = _computerPlayers.size();
	for (int i = 0; i < cS; i++)
	{
		_computerPlayers[i].printHand();
		if (_computerPlayers[i].playerGuess == numToGuess)
			winners.push_back(&_computerPlayers[i]);
	}
	int wS = winners.size();
	std::cout << "Player that won a point: " << std::endl;
	for (int i = 0; i < wS; i++)
	{
		std::cout << winners[i]->name << std::endl;
		winners[i]->score += 1;
	}
}

bool Game::isGameOver()
{
	std::vector<Player*> winners;
	int pS = _players.size();
	for (int i = 0; i < pS; i++)
	{
		std::cout << "-------------------------" << _players[i].score << "-------------------------" << std::endl;
		if (_players[i].score >= maxScore)
			winners.push_back(&_players[i]);
	}
	int cS = _computerPlayers.size();
	for (int i = 0; i < cS; i++)
	{
		if (_computerPlayers[i].score >= maxScore)
			winners.push_back(&_computerPlayers[i]);
	}
	if (!winners.empty())
	{
		std::cout << "These players won the game: " << std::endl;
		int wS = winners.size();
			for (int i = 0; i < wS; i++)
			{
				std::cout << winners[i]->name << std::endl;
			}
			std::cout << "Thanks for playing" << std::endl;
			return true;
	}
	return false;


}
