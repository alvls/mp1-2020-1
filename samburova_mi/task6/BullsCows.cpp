#include "BullsCows.h"


int* Game::setRandomNumber()
{
	int* Digits = new int[n];
	srand(time(0));
	Digits[0] = 1 + rand() % 9;
	for (int i = 1; i < n; i++)
	{
		Digits[i] = rand() % 10;
		for (int j = 0; j < i; j++)
			if (Digits[i] == Digits[j])
			{
				i--; break;
			}
	}
	return Digits;
}


int* Game::setUserNumber(int number)
{
	int* Digits = new int[n];
	for (int i = n - 1; i >= 0; i--)
	{
		Digits[i] = number % 10;
		number = number / 10;
		for (int j = i + 1; j < n; j++)
			if (Digits[i] == Digits[j] || Digits[0] == 0)
			{
				return nullptr;
			}
	}
	return Digits;
};

Game::Game(int _n)
{
	n = _n;
};
Game::~Game()
{};


pair<int, int> Game::getBullsCows(int* _machine, int* _human)
{
	int* machine = _machine;
	int* human = _human;
	pair<int, int> BullsCows;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((machine[i] == human[j]) && (i == j))
				BullsCows.first++;
			if ((machine[i] == human[j]) && (i != j))
				BullsCows.second++;
		}
	}
	return BullsCows;
};

unsigned int Game::run()
{
	int number;
	int* human;
	int* machine = setRandomNumber();
	unsigned int k = 0;
	while (true)
	{
		do
		{
			cout << "Enter number" << endl;
			cin >> number;
			if (setUserNumber(number)==nullptr)
			cout << "The number contains repeating digits or\n the first digit of the number is zero. Try again." << endl;
		} while ((human = setUserNumber(number)) == nullptr);
		k++;
		if (getBullsCows(machine, human).first == n) break;
		cout << "Bulls are " << getBullsCows(machine, human).first << ", Cows are " << getBullsCows(machine, human).second << ". You are almost there!" << endl;
	}
	return k;
};


