#pragma once
#include "CorrectNumber.h"

class BullsAndCows
{
private:
	int bull;
	int cow;
	int length;
	vector<int> digits;
public:
	void Guessing(int num)
	{
		bull = 0;
		cow = 0;
		vector<int> correct_digits(length);
		for (int i = length - 1; i >= 0; i--)
		{
			correct_digits[i] = num % 10;
			num /= 10;
		}
		for (int i = 0; i < length; i++)
		{
			if (digits[i] == correct_digits[length - i - 1])
				bull++;
			else for (int j = 0; j < length; j++)
			{
				if (digits[i] == correct_digits[length - j - 1])
					cow++;
			}
		}
	}

	void Set_length(int new_length)
	{
		length = new_length;
	}

	void Set_number()
	{
		vector<int> new_digits = CorrectNumber::Generate(length);
		digits = new_digits;
	}

	bool Win_check()
	{
		bool check = false;
		if (cow >= 0 && bull != length)
			cout << "Коров: " << cow << endl;
		if (bull >= 0 && bull != length)
			cout << "Быков: " << bull << endl;
		if (bull == length)
		{
			cout << "Вы выиграли!" << endl;
			check = true;
		}
		return check;
	}
};