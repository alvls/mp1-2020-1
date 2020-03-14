#define _CRT_SECURE_NO_WARNINGS
#include<cstring> 
#include <iostream>
#include <cstdio>
using namespace std;

class String
{
	char* str;
	int len;
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

	void Setstring(char* _str)
	{
		len = strlen(_str);
		delete[] str;
		str = new char[len + 1];
		strcpy(str, _str);
	}

	~String()
	{
		delete[] str;
	}

	String& operator=(const String& a)
	{
		if (this == &a)
			return *this;
		len = a.len;
		delete[] str;
		str = new char[len + 1];
		strcpy(str, a.str);
		return *this;
	}

	int Lenghtlen()
	{
		return len;
	}

	char& operator[](int index)
	{
		if (str != 0 && index >= 0 && index <= len)
			return str[index];
		else
			throw "Error: this index isn't exist\n";
	}
	void Changesymbol(int index, char symbol)
	{
		str[index] = symbol;
	}
	
	char* Substring(char* str, int m, int n)
	{
		char* newstr;
		int newlen = 0;
		int p, len = 0;
		int i, j = 0;

		for (i = 0; str[0] == '\0'; i++)
		{
			len++;
		}
		if (n > 0)
		{
			if (m + n <= len + 1)
				p = m + n - 1;
			else
				cout << "Error: substring is out of string\n";
		}
		else
			cout << "Wrong n\n";
		newlen = n;
		newstr = new char[n];

		for (i = m; i <= p; i++)
		{
			newstr[j] = str[i];
			j++;
		}
		return(newstr);
	}

	bool Palindrome()
	{
		char* flag1, * flag2;
		int number = 0;
		flag1 = str;
		flag2 = str + strlen(str) - 1;
		for (flag1, flag2; flag1 < flag2; flag1++, flag2--)
		{
			if (*flag1 == *flag2)
				number++;
		}
		return number == len / 2;
	}

	int NumberOfDiffSimbols()
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
	String s;
	char* s1;
	s1 = new char[41];
	int mainchoice;
	int i;
	int p, l;
	int h = 1;
	int index2;
	char change;
	while (h = 1)
	{
		do
		{
			cout << "Please select an action\n 1) Set a new string\n 2) find out the current length\n 3) Get a string character by its index\n 4) Change the string character at the specified index\n 5) Select a substring from a string\n 6) Check whether the string is a palindrome\n 7) find how many different Latin characters are contained in a string\n 8) Exit\n";
			cin >> mainchoice;
			if (mainchoice < 1 || mainchoice > 8) cout << "You entered the wrong answer.\nPlease try again:\n\n";
		} while (mainchoice < 1 || mainchoice > 8);

		switch (mainchoice)
		{
		case 1:
			cout << "Please enter the string:" << endl;
			cin >> s1;
			s.Setstring(s1);
			system("pause");
			system("cls");
			break;
		case 2:
			cout << s.Lenghtlen();
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "Please enter the index of the character you want to find out:\n" << endl;
			cin >> i;
			cout << s.operator[](i);
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "\n" << "Enter index: ";
			cin >> index2;
			cout << "\n" << "Enter text: ";
			cin >> change;
			s.Changesymbol(index2, change);
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "Please enter the starting position of the substring:\n" << endl;
			cin >> p;
			cout << "Please enter the length of the substring:\n" << endl;
			cin >> l;
			cout << "Your substring\n:" << s.Substring(s1, p, l) << endl;
			system("pause");
			system("cls");
			break;
		case 6:
			if (s.Palindrome() == 0)
				cout << "string isn't a palindrome" << endl;
			else
				cout << "string is a palindrome" << endl;
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "\n" << s.NumberOfDiffSimbols() << endl;
			system("pause");
			system("cls");
			break;
		case 8:
			h = 0;
			break;
		}
	}
}