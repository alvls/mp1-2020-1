#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class String
{
private:
	int   len;
	char* str;
public:
	String()
	{
		len = 0;
		str = new char[1];
		str[0] = '\0';
	}

	String(const String& s)
	{
		len = s.len;
		str = new char[len + 1];
		strcpy(str, s.str);
	}
	~String()
	{
		delete[]str;
	}
	void SetString(char* word)
	{
		int len = strlen(word);
		delete[]str;
		str = new char[len + 1];
		strcpy(str, word);
	}
	int GetLength()
	{
		return len;
	}
	bool Palindrom()
	{
		for (int i = 0; i < len / 2; i++)
			if (str[i] != str[len - 1 - i])
				return -1;
		return 1;
	}
	String& operator=(String& obj1)
	{
		if (this == &obj1)
			return *this;
		else
			if (len != obj1.len)
			{
				delete[] str;
				str = new char[obj1.len + 1];
			}
		strcpy(str, obj1.str);
		len = obj1.len;
		return *this;
	}

	char GetSymbol(int index)
	{
		return str[index];
	}
	void ChangeSymbol(int index2, char change)
	{
		str[index2] = change;
	}
	char* GetPartOfString(int _start, int _length)
	{
		char * newstr = new char[_length];
		int j = 0;
		for (int i = _start; i < (_length - _start); i++)
		{
			newstr[j] = str[i];
			j++;
		}
		return(newstr);
	}

	int DifferentSymbols()
	{
		int counter = 0;
		int indicator;
		for (int i = 0; i < len; i++)
		{
			indicator = 0;
			for (int j = 0; j < i; j++)
			{
				if (str[i] != str[j])
					if (isalpha(str[i]))
						indicator++;
			}
			if (indicator == i)
				counter++;
		}
		return counter;
	}
};
int main()
{

	char* word;
	word = new char[41];
	int _start = 0;
	int _length = 0;
	int index = 0;
	int h = 2;
	int index2 = 0;
	char change = 0;
	int j = 0;
	String S1;
	cout << "Enter the string: ";
	cin >> word;
	S1.SetString(word);
	cout << word;
	while (h == 2)
	{
		cout << "Set string - 1" << endl
			<< "Get lenght of string - 2" << endl
			<< "Get symbol - 3" << endl
			<< "Change symbol - 4" << endl
			<< "Get part of string - 5" << endl
			<< "Check on palindrom - 6" << endl
			<< "Different symbols - 7" << endl
			<< "Exit - 0" << endl;
		cin >> j;
		switch (j)
		{
		case 1:
		{
			cout << "Enter the string: ";
			cin >> word;
			S1.SetString(word);
			break;
		}
		case 2:
		{
			cout << "\n" << S1.GetLength() << endl;
			break;
		}
		case 3:
		{
			cout << "Enter index: ";
			cin >> index;
			cout << S1.GetSymbol(index) << endl;

			break;
		}
		case 4:
		{
			cout << "\nEnter index: ";
			cin >> index2;
			cout << "\nEnter text: ";
			cin >> change;
			S1.ChangeSymbol(index2, change);
			break;
		}
		case 5:
		{
			cout << "\n" << "Enter index: ";
			cin >> _start;
			cout << "\n" << "Enter length: ";
			cin >> _length;
			//for (int i = start; i < (start + _length); i++)
			//{
				cout << S1.GetPartOfString(_start, _length);
			//}
			//cout << "\n";
			break;
		}
		case 6:
		{
			if (S1.Palindrom() == 1)
				cout << "String is a Palindrom" << endl;
			else
			{
				cout << "String is not a Palindrom" << endl;
			}
			break;
		}
		case 7:
		{
			cout << "\n" << S1.DifferentSymbols() << endl;
			break;
		}
		case 0:
		{
			h = 0;
			break;
		}
		}
	}
};