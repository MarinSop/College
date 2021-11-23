#pragma once
#include "HangmanModel.h"
#include <iostream>
class HangmanController
{
public:
	HangmanController(HangmanModel* _model);
	~HangmanController();

	void input();
	void checkAndReplace();
	bool checkIfGameOver();
	bool checkIfWon();

private:
	HangmanModel* model;
	char checkLetter;

};

