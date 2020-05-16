#include <iostream>
#include <string>
#include <locale>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class NumberGenerator
{
private:
	int Digit;
public:
	NumberGenerator(int digit)
	{
		Digit = digit;
	}
	void CreateNumber(char* Arr)
	{
		srand(time(0));
		for (int i = 0; i < Digit; i++)
		{
			Arr[i] = rand() % 9;

			for (int j = 0; j < i; j++)
			{
				while ((Arr[j] == Arr[i]) || (Arr[0] == 0))
				{
					Arr[i]++;
					break;
				}
			}
		}

	}
};

class Counter
{
private:
	int Digit;
	char* Correct_Number;
public:
	Counter(int digit, char* correct_number)
	{
		Digit = digit;
		Correct_Number = correct_number;
	}

	void CountBullsAndCows(char* player_number, int* bulls, int* cows)
	{
		for (int i = 0; i < Digit; i++)
		{
			if (Correct_Number[i] == player_number[i] - '0')
			{
				(*bulls)++;
			}

			for (int j = 0; j < Digit; j++)
			{
				if (Correct_Number[i] == player_number[j] - '0')
					(*cows)++;
			}
		}
	}
};

class Game
{
private:
	int Digit;
public:
	Game(int digit)
	{
		Digit = digit;
	}

	void Start()
	{
		int yes = 0;
		NumberGenerator NG(Digit);
		char* Arr = new char[Digit];
		NG.CreateNumber(Arr);
		Counter counter(Digit, Arr);
		char* My = new char[Digit];
		while (yes != 1)
		{
			int bulls = 0;
			int cows = 0;
			cout << "Ваш вариант:\n";
			cin >> My;
			counter.CountBullsAndCows(My, &bulls, &cows);
			if (bulls == Digit)
			{
				cout << endl;
				cout << "Поздравляю, вы выиграли!";
				cout << endl;
				yes = 1;
			}
			else {
				cout << bulls << " бык, " << cows - bulls << " корова!" << endl;
				bulls = 0;
				cows = 0;
			}
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	int k = 1;
	int choice;
	int rules;
	int n;
	while (k == 1)
	{
		cout << "Добро пожаловать в игру \"Быки и коровы!\"" << endl;
		cout << "Выберите дальнейшие действия:" << endl;
		cout << "1 - Играть" << endl;
		cout << "2 - Выйти из программы" << endl;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
		{
			cout << "1 - Узнать правила игры" << endl;
			cout << "2 - Я знаю правила игры" << endl;
			cout << "Ваш выбор:" << endl;
			cin >> rules;
			system("cls");
			switch (rules)
			{
			case 1:
			{
				cout << "Играют два игрока (человек и компьютер)" << endl;
				cout << "Игрок выбирает длину загадываемого числа – n." << endl;
				cout << "Компьютер «задумывает» n - значное число с неповторяющимися цифрами." << endl;
				cout << "Игрок делает попытку отгадать число – вводит n - значное число с неповторяющимися цифрами." << endl;
				cout << "Компьютер сообщает, сколько цифр угадано без совпадения с их позициями в загаданном числе(то есть количество коров) и сколько угадано вплоть до позиции в загаданном числе(то есть количество быков)." << endl;
				cout << "Игрок делает попытки, пока не отгадает всю последовательность." << endl;
				cout << "Желаем Вам удачи!" << endl << endl;
				cout << "Введите длину загадываемого числа: ";
				cin >> n;
				Game game(n);
				game.Start();
				cout << "Спасибо за игру!";
				_getch();
				system("cls");
				break;
			}
			case 2:
			{
				int n;
				cout << "Введите длину загадываемого числа: ";
				cin >> n;
				Game game(n);
				game.Start();
				cout << "Спасибо за игру!";
				_getch();
				system("cls");
				break;
			}
			}
		}
		case 2:
		{
			cout << "До свидания!";
			exit(0);
			system("cls");
		}
		}
	}
}