#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;

class TRandomGenerator
{
protected:
	vector <int> number;
	int n;
public:
	TRandomGenerator()
	{
		n = 0;
	}
	void RandomNumber(int n)
	{
		vector<int> ar(11);
		int l = 1;
		srand(time(NULL));
		while (l == 1)
		{
			ar[0] = 1 + rand() % 9;
			l = 0;
			int i = 1;
			while (i < n)
			{
				ar[i] = rand() % 10;
				i++;
			}
			for (i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++)
				{
					if (ar[i] == ar[j])
					{
						l = 1;
						break;
					}
				}
		}
		for (int i = 0; i <= n; i++)
			number.push_back(ar[i]);
	}
	vector<int> GetRandNumber()
	{
		return number;
	}

	void ClearComp()
	{
		number.clear();
	}
};
class Game :public TRandomGenerator
{
	int cows;
	int bulls;
	vector <int> player;
public:
	Game()
	{
		cows = 0;
		bulls = 0;
	}
	void SetSize(int _n)
	{
		n = _n;
	}
	bool GetNumber(string _player)
	{
		if (n == _player.size())
		{
			for (int i = 0; i < _player.size(); i++)
			{
				char tmp[2];
				tmp[0] = _player[i];
				tmp[1] = '\0';
				player.push_back(atoi(tmp));
			}
			return true;
		}
		else
			return false;
	}
	int CountCows()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if ((number[i] == player[j]) && (i != j))
					cows++;
			}
		}
		return cows;
	}
	int CountBulls()
	{
		for (int i = 0; i < n; i++)
		{
			if (number[i] == player[i])
				bulls++;
		}
		return bulls;
	}
	bool WinOrLose()
	{
		if (bulls == n)
			return true;
		return false;
	}

	void ClearCowsBulls()
	{
		cows = 0;
		bulls = 0;
		player.clear();
	}
};

void main()
{
	Game game;
	int n, b = 0, a, steps;
	string num;
	setlocale(LC_ALL, "Rus");
	cout << "Добро пожаловать в игру Быки и Коровы!" << endl;
	while (b == 0)
	{
		cout << "   ~МЕНЮ~ \n" << "1 - Play\n" << "2 - Узнать правила игры \n" << "3 - Exit \n" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
		{
			steps = 0;
			system("cls");
			cout << "Введите длину загадываемого числа (max 10):" << endl;;
			cin >> n;
			game.SetSize(n);
			game.RandomNumber(n);
			system("cls");
			cout << "Если захотите сдаться - введите 0." << endl;
		metka1:	cout << "Введите предполагаемое число:" << endl;;
			cin >> num;
			if (num == "0")
			{
				cout << endl << "ВЫ СДАЛИСЬ!:(" << endl;
				cout << "Загаданное число : ";
				for (int i = 0; i < n; i++)
					cout << game.GetRandNumber()[i];
				cout << endl << endl;
				game.ClearCowsBulls();
				game.ClearComp();
				system("pause");
				system("cls");
				break;
			}
			if (game.GetNumber(num) == 0)
			{
				cout << "Неверная длина числа. Попробуйте ещё раз.\n";
				goto metka1;
			}
			if (game.GetNumber(num) == 1)
			{
				steps++;
				cout << "Быков:" << game.CountBulls() << endl;
				cout << "Коров:" << game.CountCows() << endl;
				if (game.WinOrLose() == true)
				{
					if (steps == 1)
					{
						cout << endl << "ПОЗДРАВЛЯЮ!\nВЫ ВЫИГРАЛИ!\nВы угадали число с первой попытки\n";
					}
					else {
						cout << endl << "УРА!\nПОЗДРАВЛЯЮ!" << endl;
						cout << "Вы угадали число за " << steps << " попыток!\n" << endl;
					}
					game.ClearCowsBulls();
					game.ClearComp();
					system("pause");
					system("cls");
					break;
				}
				if (game.WinOrLose() == false)
				{
					cout << "Не угадали. Попробуйте еще раз!" << endl;
					game.ClearCowsBulls();
					goto metka1;
				}
			}
		}

		case 2:
		{
			system("cls");
			cout << "Правила игры." << endl;
			cout << "Играют два игрока(человек и компьютер)." << endl;
			cout << "Игрок выбирает длину загадываемого числа – n." << endl;
			cout << "Компьютер «задумывает» n - значное число с неповторяющимися цифрами." << endl;
			cout << "Игорк делает попытку отгадать число – вводит n - значное число с неповторяющимися цифрами." << endl;
			cout << "Компьютер сообщает, сколько цифр угадано без совпадения с их позициями в загаданном числе(то есть количество коров)" << endl << "и сколько угадано вплоть до позиции в загаданном числе(то есть количество быков)." << endl;
			cout << "Игрок делает попытки, пока не отгадает всю последовательность." << endl;
			cout << "Пример." << endl;
			cout << "Пусть n = 4." << endl;
			cout << "Пусть задумано тайное число «3219»." << endl;
			cout << "Игрок ввел число «2310»." << endl;
			cout << "Результат: две «коровы»(две цифры : «2» и «3» — угаданы на неверных позициях) и один «бык»(одна цифра «1» угадана вплоть до позиции).\n" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			b = 1;
		}
		}
	}
}