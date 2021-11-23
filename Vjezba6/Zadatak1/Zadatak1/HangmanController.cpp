#include "HangmanController.h"

HangmanController::HangmanController(HangmanModel* _model)
{
	model = _model;
}

HangmanController::~HangmanController()
{
}

void HangmanController::input()
{
	std::cout << "Enter a letter" << std::endl;
	std::cin >> checkLetter;
}

void HangmanController::checkAndReplace()
{
	int n = model->guessName.length();
	std::string name = model->movieName;
	bool found = false;
	for (int i = 0; i < n; i++)
	{
		if (isalpha(model->movieName[i]))
		{
			if (std::tolower(model->movieName[i]) == std::tolower(checkLetter))
			{
				model->guessName[i] = model->movieName[i];
				found = true;
			}
		}
	}
	if (!found)
	{
		model->lifeMinus();
	}
	
}

bool HangmanController::checkIfGameOver()
{
	if (model->livesCheck() <= 0)
		return true;
	else
		return false;
}

bool HangmanController::checkIfWon()
{
	if (model->guessName == model->movieName)
		return true;
	else
		return false;
}
