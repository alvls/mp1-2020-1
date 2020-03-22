#include <stdlib.h>
#include <iostream>
#include <vector>
#include "windows.h"
#include "stdio.h"
#include "memory.h"
using namespace std;
void gotoxy(int x, int y)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console)
		return;
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(Console, pos);
}
class MenuItem
{
private:
	char name[80];
public:
	MenuItem()
	{
		char empty[80] = "empty";
		for (int k = 0; k < 6; k++)
		{
			name[k] = empty[k];
		}
	}
	friend class Menu;
};
class Menu
{
private:
	int number;
	MenuItem* items;
	int choice;
	int lastchoice = 0;
public:
	Menu()
	{
		number = 1;
		items = new MenuItem[1];
	}

	void setNumber(int n)
	{
		delete[] items;
		number = n;
		items = new MenuItem[n];
	}
	int getNumber()
	{
		return number;
	}
	void SetName(int n, char a[80])
	{
		for (int k = 0; k < 80; k++)
		{
			items[n - 1].name[k] = a[k];
		}
	}
	void outxy(int x, int y)
	{
		gotoxy(x, y);
		for (int k = 1; k <= getNumber(); k++)
		{
			cout << k << ".   " << items[k - 1].name;
			gotoxy(x, y + k);
			if (k == getNumber())
			{
				gotoxy(0, y + k);
			}
		}
	}
	void use(int n)
	{
		if (n == 0)
		{
			cout << "you did not choose anything" << endl;
		}
		else
		{
			lastchoice = n;
			cout << "you have chosen " << n << endl;
		}
	}
	int getlastchoice()
	{
		return lastchoice;
	}
	~Menu()
	{
		delete[] items;
	}
};
void main()
{
	Menu www;
	www.setNumber(5);
	cout << www.getNumber();
	www.SetName(1, "hja1");
	www.SetName(2, "hja2");
	www.SetName(3, "hja3");
	www.outxy(35, 10);
	www.use(1);
	www.use(4);
	cout << endl << www.getlastchoice();
	system("pause");
}