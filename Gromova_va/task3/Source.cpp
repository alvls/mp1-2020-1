#include <iostream>
#include <clocale> 
#include <string>
#include <windows.h>
#include <fstream>
#include <sstream>
const int MAX_SIZE = 1000;

using namespace std;
class Translator_dictionary
{
private:
	string eng_word[MAX_SIZE];
	string rus_word[MAX_SIZE];
	int wordCount;
public:
	class Translator_dictionary()
	{
		rus_word[MAX_SIZE] = { "" };
		eng_word[MAX_SIZE] = { "" };
		wordCount = 0;
	}
	Translator_dictionary(string english_word, string russian_word)
	{
		rus_word[wordCount] = russian_word;
		eng_word[wordCount] = english_word;
		wordCount++;
	}
	Translator_dictionary(const Translator_dictionary  &str)
	{
		rus_word[wordCount] = str.rus_word[wordCount];
		eng_word[wordCount] = str.eng_word[wordCount];
	}
	Translator_dictionary& operator=(const Translator_dictionary &str)//�������� ������������
	{
		if (this == &str)
		{
			return *this;
		}
		rus_word[wordCount] = str.rus_word[wordCount];
		eng_word[wordCount] = str.eng_word[wordCount];
		return *this;
	}
	void readDict(string filename = "Dictionary.txt")
	{
		ifstream in(filename);
		int i = 1;
		if (in.is_open())
		{
			string line;
			string rus, eng;
			while (getline(in, line))
			{
				//��������� ������ � ���������� � �������
				istringstream ist(line);
				ist >> eng;
				ist >> rus;
				eng_word[i - 1] = eng;
				rus_word[i - 1] = rus;
				i++;
			}
			wordCount = i;
		}
	}
	void Add_word(string english_word, string russian_word, string words)//������� ��� ����, ����� �������� � ������� ����� � ��� �������
	{
		int l1, l2;
		l1 = english_word.size();
		l2 = russian_word.size();
		if (l1 < 20) // ������������ � �����
		{
			for (int i = 0; i < (20 - l1); i++)
				english_word += " ";
		}
		if (l2 < 20) // ������������ � �����
		{
			for (int i = 0; i < (20 - l2); i++)
				russian_word += " ";
		}
		eng_word[wordCount] = english_word;
		rus_word[wordCount] = russian_word;
		wordCount++;
		//words = rus_word[wordCount] + eng_word[wordCount];
	}
	void Set_word(string englword, string russword, int num)//�������, ��� ����������� �������� �����
	{
		int  element = 0, my_size = 0;
		for (int i = 0; i < wordCount; i++)
		{
			if (englword == eng_word[i])
			{
				if (num == 1) // ������ ��������
				{
					eng_word[i] = russword;

				}
				if (num == 2) // ������ ������ �����
				{
					rus_word[i] = russword;
				}
			}
			else
				cout << "����� �� �������." << endl;
		}
	}
	void Get_word(string str)//�������,������� ��������� �����
	{
		for (int i = 0; i < wordCount; i++)
		{
			if (eng_word[i] == str)
			{
				int j = i;
				cout << " ������� �����: " << str << " - " << rus_word[j] << endl;
			}
			else
			{
				cout << "������ ����� ��� � �������." << endl;
			}
		}
	}
	void Number_of_words()//������� ��� �������� ���� � �������;
	{
		cout << "����� ���� � ������� :" << wordCount << endl;
	}
	void Print_dictionary()//������� ��� ������ ���� �� �����
	{
		for (int i = 0; i < wordCount; i++)
		{
			cout << eng_word[i] << " - " << rus_word[i] << endl;
		}
	}
	void File_print_dictionary(string words)//������� ��� ���������� ���� � ����;
	{
		ofstream file;
		file.open("Dictionary.txt", ofstream::app);
		for (int i = 0; i <= wordCount; i++)
		{
			file << eng_word[i];
			file << rus_word[i];
			file << endl;
		}
		file.close();
	}
	bool Check_word(string str)//������� ��� �������� ����� �� �������
	{
		for (int i = 0; i < wordCount; i++)
		{
			if (eng_word[i] == str)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	~Translator_dictionary()
	{}
};
int main(void)
{
	setlocale(0, "");
	int  choice, num;
	char ch;
	int type = 0;
	string Arr;
	string Word;
	string engl_word;
	string rus_word;
	Translator_dictionary vybor;
	Translator_dictionary word;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do
	{
		cout << "��� �� ������ �������:\n 1 - �������� ����� � �������.\n 2 - �������� �������.\n 3 - ������ ������� �����.\n 4 - ��������� �������.\n 5 - ������ ���������� ���� � �������.\n 6 - ������� ������� �� �����.\n 7 - ��������� � �������." << endl;
		cin >> choice;
		while ((choice < 1) || (choice > 7))
		{
			cout << "��� �� ������ �������:\n 1 - �������� ����� � �������.\n 2 - �������� �������.\n 3 - ������ ������� �����.\n 4 - ��������� �������.\n 5 - ������ ���������� ���� � �������.\n 6 - ������� ������� �� �����.\n 7 - ��������� � �������." << endl;
			cin >> choice;
			cin >> ch; // �������� �����
		}
		switch (choice)
		{
		case 1:
		{
			cout << "������� �����:" << endl;
			getline(cin, engl_word);
			cout << "������� ������� ������� ����� :" << endl;
			getline(cin, rus_word);
			Translator_dictionary vybor(engl_word, rus_word);
			vybor.Add_word(engl_word, rus_word, Arr);
			break;
		}
		case 2:
		{
			cout << "������� �����, ������� ������ ��������:" << endl;
			getline(cin, engl_word);
			cout << "��� �� ������ ������� � ���?\n1 - �������� ������� �����.\n2 - �������� ���� �����." << endl;
			cin >> num;
			cout << "������ �� : " << endl;
			getline(cin, Word);
			Translator_dictionary swap;
			swap.Set_word(engl_word, Word, num);
			break;
		}
		case 3:
		{
			cout << "������� �����, � �������� ������ ������ �������:" << endl;
			getline(cin, engl_word);
			word.Get_word(engl_word);
			break;
		}
		case 4:
		{
			cout << "������� �����, ������� ������ ��������� �� �������:" << endl;
			getline(cin, engl_word);
			bool check = word.Check_word(engl_word);
			if (check == true)
			{
				cout << "����� ��������� � �������." << endl;
			}
			else
			{
				cout << "����� �� ������� � �������." << endl;
			}
			break;
		}
		case 5:
		{
			word.Number_of_words();
			break;
		}
		case 6:
		{
			cout << "�������: " << endl;
			word.Print_dictionary();
			break;
		}
		case 7:
		{
			cout << "�������� � �������. " << endl;
			word.File_print_dictionary(Arr);
			Arr = "";
		}
		}
		cout << " ������ ��������� ������?/n1-��, 0-���" << endl;
		cin >> type;
		while ((type != 0) && (type != 1))
		{
			cout << ("�������  0 ��� 1.\n");
			cin >> type;
		}
	} while (type == 0);
	system("pause");
	return 0;
}