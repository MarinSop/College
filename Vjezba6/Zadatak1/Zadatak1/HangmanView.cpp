#include "HangmanView.h"
#include "HangmanModel.h"

HangmanView::HangmanView(HangmanController* _controller, HangmanModel* _model)
{
	controller = _controller;
	model = _model;

}

HangmanView::~HangmanView()
{
}

void HangmanView::displayCurrentProgress()
{
	std::cout << model->guessName << std::endl;
}

void HangmanView::displayHangman()
{
	modelNumber = abs(model->livesCheck() - 6);
	switch (modelNumber)
	{
	case 0:
		std::cout << " + -- - + " << std::endl;
		std::cout << "  |   |   " << std::endl;
		std::cout << "      |   " << std::endl;
		std::cout << "      |   " << std::endl;
		std::cout << "      |   " << std::endl;
		std::cout << "      |   " << std::endl;
		std::cout << "========= " << std::endl;
		std::cout << "---------------------------------" << std::endl;
		break;
	case 1:
		std::cout << " + -- - + " << std::endl;
		std::cout << "  |   |   " << std::endl;
		std::cout << "  O   |   " << std::endl;
		std::cout << "      |   " << std::endl;
		std::cout << "      |   " << std::endl;
		std::cout << "      |   " << std::endl;
		std::cout << "========= " << std::endl;
		std::cout << "---------------------------------" << std::endl;
		break;
	case 2:
		std::cout << "  +---+   " << std::endl;
		std::cout << "  |   |   " << std::endl;
		std::cout << "  O   |   " << std::endl;
		std::cout << "  |   |   " << std::endl;
		std::cout << "      |   " << std::endl;
		std::cout << "      |   " << std::endl;
		std::cout << "========= " << std::endl;
		std::cout << "---------------------------------" << std::endl;
		break;
	case 3:
		std::cout << "	+---+   " << std::endl;
		std::cout << "  |   |   " << std::endl;
		std::cout << "  O   |   " << std::endl;
		std::cout << " /|   |   " << std::endl;
		std::cout << "      |   " << std::endl;
		std::cout << "      |   " << std::endl;
		std::cout << "========= " << std::endl;
		std::cout << "---------------------------------" << std::endl;
		break;
	case 4:
		std::cout << "	+---+   " << std::endl;
		std::cout << "  |   |   " << std::endl;
		std::cout << "  O   |   " << std::endl;
		std::cout << " /|\  |   " << std::endl;
		std::cout << "      |   " << std::endl;
		std::cout << "      |   " << std::endl;
		std::cout << "========= " << std::endl;
		std::cout << "---------------------------------" << std::endl;
		break;
	case 5:
		std::cout << "	+---+   " << std::endl;
		std::cout << "  |   |   " << std::endl;
		std::cout << "  O   |   " << std::endl;
		std::cout << " /|\  |   " << std::endl;
		std::cout << " /    |   " << std::endl;
		std::cout << "      |   " << std::endl;
		std::cout << "========= " << std::endl;
		std::cout << "---------------------------------" << std::endl;
		break;
	case 6:
		std::cout << "  +---+   " << std::endl;
		std::cout << "  |   |   " << std::endl;
		std::cout << "  O   |   " << std::endl;
		std::cout << " /|\  |   " << std::endl;
		std::cout << " / \  |   " << std::endl;
		std::cout << "      |   " << std::endl;
		std::cout << "========= " << std::endl;
		std::cout << "---------------------------------" << std::endl;
		break;
	default:
		break;
	}
}

void HangmanView::displayLives()
{
	std::cout << "Lives left: " << model->livesCheck() << std::endl;
}
