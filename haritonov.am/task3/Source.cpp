#include "console.cpp"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class TextChanger
{
	string line;
	int len;
	int x, y;
public:

	void SetLen(int _len = 0)
	{
		len = _len;
	}

	int CheckLen()
	{
		return len;
	}

	void SetPos(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}

	void CheckPos(int *xx, int *yy)
	{
		*xx = x;
		*yy = y;
	}

	void ReadArray()
	{
		char symb;
		int i = 0;
		while (i < len)
		{
			symb = _getch();
			if (symb == 13)
				return;
			if (symb == 8)
			{
				if (i > 0)
				{
					cout << "\b \b";
					i--;
				}
			}
			else
			{
				cout << symb;
				line += symb;
				i++;
			}
		}	
	}

	void SetArray()
	{
		gotoxy(x, y);
		textbackground(GREEN);
		for(int i = x; i < (x+ len + 2); i++)
			cout << "~";
		cout << endl;
		gotoxy(x, y+1);
		cout << "|";
		for (int i = x; i < (x + len); i++)
			cout << " ";
		cout << "|";
		cout << endl;
		gotoxy(x, y + 2);
		for (int i = x; i < (x + len + 2); i++)
			cout << "~";
		cout << endl;
		gotoxy(x + 1, y + 1);
		ReadArray();
		textbackground(BLACK);
		clrscr();
	}

	string GetLine()
	{
		return line;
	}
};

int main()
{
	TextChanger t1;
	t1.SetPos(20, 20);
	t1.SetLen(30);
	t1.SetArray();
	cout << t1.GetLine() << endl;
	system("pause");
	return(0);
}