#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

class CorrectNumber
{
public:
	static vector<int> Generate(int length)
	{
		srand(time(NULL));
		vector<int> digits(length);
		int numeral;
		digits[0] = 1 + rand() % 9;
		for (int i = 1; i < length; i++)
		{
			numeral = rand() % 10;
			for (int j = 0; j < i; j++)
			{
				while (numeral == digits[j])
				{
					j = 0;
					numeral = rand() % 10;
				}
				digits[i] = numeral;
			}
		}
		return digits;
	}
};