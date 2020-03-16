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
		rus_word[0];
		eng_word[0];
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
		rus_word[0] = russian_word;
		eng_word[0] = english_word;
		wordCount = 1;
	}
	TranslatorDictionary(const TranslatorDictionary &str)
	{
		for (int i = 0; i < wordCount; i++)
		{
			eng_word[i] = str.eng_word[i];
			rus_word[i] = str.rus_word[i];
		}
	}
	TranslatorDictionary& operator=(const TranslatorDictionary &str)//оператор присваивания
	{
		if (this == &str)
		{
			return *this;
		}
		for (int i = 0; i < wordCount; i++)
		{

			eng_word[i] = str.eng_word[i];
			rus_word[i] = str.rus_word[i];
		}
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
	void AddWord(string english_word, string russian_word)//функция для того, чтобы добавить в словарь слово и его перевод
	{

		eng_word[wordCount] = english_word;
		rus_word[wordCount] = russian_word;
		wordCount++;
	}
	void SetWord(string englword, string russword)//функция, для измененения перевода слова
	{
		for (int i = 0; i < wordCount; i++)
		{
			if (englword == eng_word[i])
			{
				eng_word[i] = russword;
			}
		}
	}
	string FindTranslation(string str)//функция,которая переводит слово
	{
		for (int i = 0; i < wordCount; i++)
		{
			if (eng_word[i] == str)
			{
				int j = i;
				return rus_word[j];
			}
		}
	}
	int NumberOfWords()//функция для подсчёта слов в словаре;
	{
		return wordCount;
	}
	void PrintDictionary()//функция для вывода слов из файла
	{
		for (int i = 0; i < wordCount; i++)
		{
			cout << eng_word[i] << " - " << rus_word[i] << endl;
		}
	}
	void SaveDictionaryToFile()//функция для сохранения слов в файл;
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
	bool CheckWord(string str)//функция для проверки слова на наличие
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
	int  choice;
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
		cout << "Что вы хотите сделать:\n 1 - добавить слово в словарь.\n 2 - изменить перевод.\n 3 - узнать перевод слова.\n 4 - проверить наличие.\n 5 - узнать количество слов в словаре.\n 6 - вывести словарь на экран.\n 7 - сохранить в словарь." << endl;
		cin >> choice;
		while ((choice < 1) || (choice > 7))
		{
			cout << "Что вы хотите сделать:\n 1 - добавить слово в словарь.\n 2 - изменить перевод.\n 3 - узнать перевод слова.\n 4 - проверить наличие.\n 5 - узнать количество слов в словаре.\n 6 - вывести словарь на экран.\n 7 - сохранить в словарь." << endl;
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			cout << "Введите слово:" << endl;
			cin >> engl_word;
			cout << "Введите перевод данного слова :" << endl;
			cin >> rus_word;
			vybor.AddWord(engl_word, rus_word);
			break;
		}
		case 2:
		{
			cout << "Введите слово, которое хотите изменить:" << endl;
			cin >> engl_word;
			if (vybor.CheckWord(engl_word))
			{
				cout << "Меняем на : " << endl;
				cin >> word;
				vybor.SetWord(engl_word, word);
			}
			else
			{
				cout << "Слово не найдено в словаре." << endl;
			}
			break;
		}
		case 3:
		{
			cout << "Введите слово, у которого хотите узнать перевод:" << endl;
			cin >> engl_word;
			if (vybor.CheckWord(engl_word))
			{
				cout << " Перевод слова: " << engl_word << " - " << vybor.FindTranslation(engl_word) << endl;
			}
			else
			{
				cout << "Слово не найдено в словаре." << endl;
			}
			break;
		}
		case 4:
		{
			cout << "Введите слово, которое хотите проверить на наличие:" << endl;
			cin >> engl_word;
			bool check = vybor.CheckWord(engl_word);
			if (check == true)
			{
				cout << "Слово находится в словаре." << endl;
			}
			else
			{
				cout << "Слово не найдено в словаре." << endl;
			}
			break;
		}
		case 5:
		{
			cout << "Число слов в словаре :" << vybor.NumberOfWords() << endl;
			break;
		}
		case 6:
		{
			cout << "Словарь: " << endl;
			vybor.PrintDictionary();
			break;
		}
		case 7:
		{
			cout << "Сохранил в словарь. " << endl;
			vybor.SaveDictionaryToFile();
			arr = "";
		}
		}
		cout << " Хотите закончить работу?/n1-да, 0-нет" << endl;
		cin >> type;
		while ((type != 0) && (type != 1))
		{
			cout << ("Введите  0 или 1.\n");
			cin >> type;
		}
	} while (type == 0);
	system("pause");
	return 0;
}