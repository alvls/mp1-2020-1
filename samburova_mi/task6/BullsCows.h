#pragma once
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

class Game
{
private:
	int n;
public:
	Game(int _n);
	~Game();
	unsigned int run();
	int* setRandomNumber();
	int* setUserNumber(int number);
	pair<int, int> getBullsCows(int* _machine, int* _human);
};

