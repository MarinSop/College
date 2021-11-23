#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <time.h>
class HangmanModel
{
public:
	HangmanModel(std::string fileName);
	~HangmanModel();

	void lifeMinus();
	int livesCheck();

	std::string guessName;
	std::string movieName;

private:
	int lives = 6;
	bool inGame = true;
};

