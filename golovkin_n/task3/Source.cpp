#include <iostream>
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <conio.h>
using namespace std;
class TextEditor 
{
private:
	string line;
	COORD pos;
	int len;
public:
	TextEditor(int l = 0, int _x = 1, int _y = 1) 
	{
		len = l;
		pos.X = _x;
		pos.Y = _y;
	}
	TextEditor(COORD _p) 
	{
		pos = _p;
		len = 0;
	}
	TextEditor(TextEditor& m) 
	{
		len = m.len;
		line = m.line;
		pos = m.pos;
	}
	string getLine() 
	{
		if (line.size())
			return line;
		return "*empty line*";
	}
	int getLen() 
	{
		return len;
	}
	COORD getPos() 
	{
		return pos;
	}
	int getXcoord() 
	{
		return pos.X;
	}
	int getYcoord() 
	{
		return pos.Y;
	}
	void setPos(int x, int y) 
	{
		pos.X = x;
		pos.Y = y;
	}
	void setPos(COORD p) 
	{
		pos = p;
	}
	void setCursor() 
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
	void setLen(int l) 
	{
		if (!l) {
			line = "";
			return;
		}
		if (l < len) {
			line.erase(line.begin() + l, line.end());
			len = l;
			return;
		}
		len = l;
	}
	void go() 
	{
		char count;
		line = "";
		int curLen = 0;
		while (curLen != -1) {
			count = _getch();
			switch (count) {
			case '\b': {
				if (curLen) {
					curLen--;
					line.pop_back();
					cout << '\b' << '\0' << '\b';
				}
				break;
			}
			case '\r': {
				curLen = -1;
				break;
			}
			default: {
				if (!len) {
					cout << "ERROR : Length of the line is zero";
					system("pause");
					return;
				}
				if (curLen == len) break;
				curLen++;
				line += count;
				cout << count;
				break;
			}
			}

		}
	}
};
int main() {
	int cur = 1;
	string buf;
	COORD pos;
	int len = 0;
	cout << "Vvedite poziciy kyrsora" << endl;
	cin >> pos.X >> pos.Y;
	system("cls");
	cout << "Poziciya kyrsora : ";
	cout << pos.X << ':' << pos.Y;
	cout << endl;
	cout << "Vvedite dliny stroki " << endl;
	cin >> len;
	TextEditor m(pos);
	m.setLen(len);
	system("cls");
	cout << "Koordinati kyrsora : ";
	cout << pos.X << ':' << pos.Y;
	cout << endl;
	cout << "Dlina stroki" << m.getLen() << " simvolov" << endl;
	m.setCursor();
	m.go();
	system("pause");
}