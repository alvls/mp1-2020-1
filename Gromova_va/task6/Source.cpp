#include <iostream>
#include <vector>
#include <iomanip>
#include <clocale>
#include <cstdlib>
#include <ctime>
using namespace std;
class SetNumber
{
public:
	static vector<int> Number(int lenght)//функция,загадывающая число
	{
		vector<int>Num;
		int n = 0;
		int numer = 0;
		n = rand() % 9 + 1;
		Num.push_back(n);
		for (int i = 1; i < lenght; i++)
		{
			numer = rand() % 10;
			for (int j = 0; j < i; j++)
			{
				while (numer == Num[j])
				{
					j = 0;
					numer = rand() % 10;
				}
			}
			Num.push_back(numer);
		}
		return Num;
	}
};
class BullsAndCows
{
	int lenght;
	int bull;
	int cow;
public:
	vector<int>Num;
	BullsAndCows()
	{
		lenght = 0;
		bull = 0;
		cow = 0;
	}
	BullsAndCows(int n)
	{
		lenght = n;
		bull = 0;
		cow = 0;
	}
	BullsAndCows(const BullsAndCows &object)
	{
		lenght = object.lenght;
		bull = object.bull;
		cow = object.cow;
	}
	BullsAndCows& operator=(const BullsAndCows &object)
	{
		cow = object.cow;
		bull = object.bull;
		lenght = object.lenght;
		return *this;
	}
	void SetNum()
	{
		Num = SetNumber::Number(lenght);
	}
	void NumberSplitting(int number)
	{
		vector<int>TrueDigits(lenght);
		for (int i = 0; i < lenght; i++)
		{
			TrueDigits[i] = (number) % 10;
			number /= 10;
		}
		bull = 0;
		for (int i = 0; i < lenght; i++)
		{
			for (int j = 0; j < lenght; j++)
			{
				if ((TrueDigits[i] == Num[j]) && (i == j))
				{
					bull++;
				}
			}
		}
		cow = 0;
		for (int i = 0; i < lenght; i++)
		{
			for (int j = 0; j < lenght; j++)
			{
				if ((TrueDigits[i] == Num[j]) && (i != j))
				{
					cow++;
				}
			}
		}
	}
	int FindBull()
	{
		return bull;
	}
	int FindCow()
	{
		return cow;
	}
};
int main()
{
	setlocale(0, "");
	srand(time(NULL));
	int bull = 0, n = 0;
	int cow = 0;
	int count = 0, coun = 0;
	cout << "Добро пожаловать в обновлённую версию игры 'Bulls and Cows'!" << endl;
	do
	{
		cout << "Введите размер загадываемого числа:" << endl;
		cin >> n;
	} while (n < 2);
	BullsAndCows num(n);
	num.SetNum();
	while (n != num.FindBull())
	{
		do
		{
			cout << "Введите число с неповторяющимися цифрами:" << endl;
			cin >> coun;
		} while (coun < 10);
		num.NumberSplitting(coun);
		cout << "Вы отгадали:" << endl << num.FindCow() << " - коров" << endl << num.FindBull() << " - быков." << endl;
		count++;
	}
	cout << "Вы отгадали! Количество попыток составило: " << count << " раз" << endl;
	system("pause");
	return 0;
}