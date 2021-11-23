#pragma once
#include <iostream>
#include "HangmanController.h"
#include <vector>
class HangmanView
{
public:

	HangmanView(HangmanController* _controller,HangmanModel* _model);
	~HangmanView();

	void displayCurrentProgress();
	void displayHangman();
	void displayLives();


private:
	HangmanController* controller;
	HangmanModel* model;
	int modelNumber = 0;
};

