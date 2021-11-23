#include "HangmanModel.h"

HangmanModel::HangmanModel(std::string fileName)
{
	srand(time(NULL));
	std::ifstream f(fileName);
	int n = 0;
	std::string str;
	while (getline(f, str))
	{
		n++;
	}
	int i = 0;
	int randomNum = rand() % n;
	f.clear();
	f.seekg(0);
	while (i != randomNum)
	{
		getline(f, str);
		i++;
	}
	movieName = str;
	guessName = movieName;
	int strLen = guessName.length();
	for (int i = 0; i < strLen ; i++)
	{
		if (isalpha(guessName[i]))
		{
			guessName[i] = '_';
		}
	}
}

HangmanModel::~HangmanModel()
{
}

void HangmanModel::lifeMinus()
{
	lives--;
}

int HangmanModel::livesCheck()
{
	return lives;
}

