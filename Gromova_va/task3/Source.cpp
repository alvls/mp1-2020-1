#include <iostream>
#include <clocale> 
#include <string>
#include <windows.h>
#include <fstream>
#include <sstream>
const int MAX_SIZE = 1000;
using namespace std;
class TranslatorDictionary
{
private:
	string eng_word[MAX_SIZE];
	string rus_word[MAX_SIZE];
	int wordCount;
public:
	TranslatorDictionary()
	{
		rus_word[0] = { "" };
		eng_word[0] = { "" };
		wordCount = 0;
	}
	TranslatorDictionary(string filename)
	{
		ifstream in(filename);
		int i = 0;
		if (in.is_open())
		{
			string line;
			string rus, eng;
			while (getline(in, line))
			{
				istringstream ist(line);
				ist >> eng;
				ist >> rus;
				eng_word[i] = eng;
				rus_word[i] = rus;
				i++;
			}
			wordCount = i - 1;
		}
	}
	TranslatorDictionary(string english_word, string russian_word)
	{
		rus_word[wordCount] = russian_word;
		eng_word[wordCount] = english_word;
		wordCount = 1;
	}
	TranslatorDictionary(const TranslatorDictionary  &str)
	{
		rus_word[wordCount] = str.rus_word[wordCount];
		eng_word[wordCount] = str.eng_word[wordCount];
	}
	TranslatorDictionary& operator=(const TranslatorDictionary &str)//�������� ������������
	{
		if (this == &str)
		{
			return *this;
		}
		rus_word[wordCount] = str.rus_word[wordCount];
		eng_word[wordCount] = str.eng_word[wordCount];
		return *this;
	}
	void ReadDict(string filename = "Dictionary.txt")
	{
		ifstream in(filename);
		int i = 0;
		if (in.is_open())
		{
			string line;
			string rus, eng;
			while (getline(in, line))
			{
				istringstream ist(line);
				ist >> eng;
				ist >> rus;
				eng_word[i] = eng;
				rus_word[i] = rus;
				i++;
				in >> line;
			}
			wordCount = i;
		}
	}
	void AddWord(string english_word, string russian_word)//������� ��� ����, ����� �������� � ������� ����� � ��� �������
	{

		eng_word[wordCount] = english_word;
		rus_word[wordCount] = russian_word;
		wordCount++;
	}
	void SetWord(string englword, string russword, int num)//�������, ��� ����������� �������� �����
	{
		for (int i = 0; i < wordCount; i++)
		{
			if (englword == eng_word[i])
			{
				if (num == 1) // ������ ������ �����
				{
					rus_word[i] = russword;
				}
				if (num == 2) // ������ ��������
				{
					eng_word[i] = russword;
				}

			}
		}
	}
	void GetWord(string str)//�������,������� ��������� �����
	{
		for (int i = 0; i < wordCount; i++)
		{
			if (eng_word[i] == str)
			{
				int j = i;
				cout << " ������� �����: " << str << " - " << rus_word[j] << endl;
			}
		}
	}
	void NumberofWords()//������� ��� �������� ���� � �������;
	{
		cout << "����� ���� � ������� :" << wordCount << endl;
	}
	void PrintDictionary()//������� ��� ������ ���� �� �����
	{
		for (int i = 0; i < wordCount; i++)
		{
			cout << eng_word[i] << " - " << rus_word[i] << endl;
		}
	}
	void FilePrintDict()//������� ��� ���������� ���� � ����;
	{
		ofstream file;
		file.open("Dictionary.txt");
		for (int i = 0; i <= wordCount; i++)
		{
			file << eng_word[i];
			file << " ";
			file << rus_word[i];
			file << endl;
		}
		file.close();
	}
	bool CheckWord(string str)//������� ��� �������� ����� �� �������
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
	~TranslatorDictionary()
	{}
};
int main(void)
{
	setlocale(0, "");
	int  choice, num;
	int type = 0;
	string arr;
	string word;
	string engl_word;
	string rus_word;
	TranslatorDictionary vybor("Dictionary.txt");
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
		}
		switch (choice)
		{
		case 1:
		{
			cout << "������� �����:" << endl;
			cin >> engl_word;
			cout << "������� ������� ������� ����� :" << endl;
			cin >> rus_word;
			vybor.AddWord(engl_word, rus_word);
			break;
		}
		case 2:
		{
			cout << "������� �����, ������� ������ ��������:" << endl;
			cin >> engl_word;
			if (vybor.CheckWord(engl_word))
			{
				cout << "��� �� ������ ������� � ���?\n1 - �������� ������� �����.\n2 - �������� ���� �����." << endl;
				cin >> num;
				cout << "������ �� : " << endl;
				cin >> word;
				vybor.SetWord(engl_word, word, num);
			}
			else
			{
				cout << "����� �� ������� � �������." << endl;
			}
			break;
		}
		case 3:
		{
			cout << "������� �����, � �������� ������ ������ �������:" << endl;
			cin >> engl_word;
			if (vybor.CheckWord(engl_word))
			{
				vybor.GetWord(engl_word);
			}
			else
			{
				cout << "����� �� ������� � �������." << endl;
			}
			break;
			break;
		}
		case 4:
		{
			cout << "������� �����, ������� ������ ��������� �� �������:" << endl;
			cin >> engl_word;
			bool check = vybor.CheckWord(engl_word);
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
			vybor.NumberofWords();
			break;
		}
		case 6:
		{
			cout << "�������: " << endl;
			vybor.PrintDictionary();
			break;
		}
		case 7:
		{
			cout << "�������� � �������. " << endl;
			vybor.FilePrintDict();
			arr = "";
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