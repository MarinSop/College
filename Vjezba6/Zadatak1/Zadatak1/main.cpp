#include <iostream>
#include "HangmanController.h"
#include "HangmanModel.h"
#include "HangmanView.h"


int main()
{
	HangmanModel* model = new HangmanModel("movies.txt");
	HangmanController* controller = new HangmanController(model);
	HangmanView* view = new HangmanView(controller,model);
	while (true)
	{
		if (controller->checkIfGameOver())
		{
			std::cout << "YOU LOSE!" << std::endl;
			break;
		}
		else if (controller->checkIfWon())
		{
			std::cout << "YOU WON!" << std::endl;
			break;
		}
		view->displayLives();
		view->displayCurrentProgress();
		view->displayHangman();
		controller->input();
		controller->checkAndReplace();
	}
	delete model;
	delete controller;
	delete view;

}