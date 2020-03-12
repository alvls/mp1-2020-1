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
	Translator_dictionary& operator=(const Translator_dictionary &str)//оператор присваивания
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
				//разбираем строку и записываем в массивы
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
	void Add_word(string english_word, string russian_word, string words)//функция для того, чтобы добавить в словарь слово и его перевод
	{
		int l1, l2;
		l1 = english_word.size();
		l2 = russian_word.size();
		if (l1 < 20) // выравнивание в файле
		{
			for (int i = 0; i < (20 - l1); i++)
				english_word += " ";
		}
		if (l2 < 20) // выравнивание в файле
		{
			for (int i = 0; i < (20 - l2); i++)
				russian_word += " ";
		}
		eng_word[wordCount] = english_word;
		rus_word[wordCount] = russian_word;
		wordCount++;
		//words = rus_word[wordCount] + eng_word[wordCount];
	}
	void Set_word(string englword, string russword, int num)//функция, для измененения перевода слова
	{
		int  element = 0, my_size = 0;
		for (int i = 0; i < wordCount; i++)
		{
			if (englword == eng_word[i])
			{
				if (num == 1) // замена перевода
				{
					eng_word[i] = russword;

				}
				if (num == 2) // замена самого слова
				{
					rus_word[i] = russword;
				}
			}
			else
				cout << "Слово не найдено." << endl;
		}
	}
	void Get_word(string str)//функция,которая переводит слово
	{
		for (int i = 0; i < wordCount; i++)
		{
			if (eng_word[i] == str)
			{
				int j = i;
				cout << " Перевод слова: " << str << " - " << rus_word[j] << endl;
			}
			else
			{
				cout << "Такого слова нет в словаре." << endl;
			}
		}
	}
	void Number_of_words()//функция для подсчёта слов в словаре;
	{
		cout << "Число слов в словаре :" << wordCount << endl;
	}
	void Print_dictionary()//функция для вывода слов из файла
	{
		for (int i = 0; i < wordCount; i++)
		{
			cout << eng_word[i] << " - " << rus_word[i] << endl;
		}
	}
	void File_print_dictionary(string words)//функция для сохранения слов в файл;
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
	bool Check_word(string str)//функция для проверки слова на наличие
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
		cout << "Что вы хотите сделать:\n 1 - добавить слово в словарь.\n 2 - изменить перевод.\n 3 - узнать перевод слова.\n 4 - проверить наличие.\n 5 - узнать количество слов в словаре.\n 6 - вывести словарь на экран.\n 7 - сохранить в словарь." << endl;
		cin >> choice;
		while ((choice < 1) || (choice > 7))
		{
			cout << "Что вы хотите сделать:\n 1 - добавить слово в словарь.\n 2 - изменить перевод.\n 3 - узнать перевод слова.\n 4 - проверить наличие.\n 5 - узнать количество слов в словаре.\n 6 - вывести словарь на экран.\n 7 - сохранить в словарь." << endl;
			cin >> choice;
			cin >> ch; // очистить поток
		}
		switch (choice)
		{
		case 1:
		{
			cout << "Введите слово:" << endl;
			getline(cin, engl_word);
			cout << "Введите перевод данного слова :" << endl;
			getline(cin, rus_word);
			Translator_dictionary vybor(engl_word, rus_word);
			vybor.Add_word(engl_word, rus_word, Arr);
			break;
		}
		case 2:
		{
			cout << "Введите слово, которое хотите изменить:" << endl;
			getline(cin, engl_word);
			cout << "Что вы хотите сделать с ним?\n1 - изменить перевод слова.\n2 - изменить само слово." << endl;
			cin >> num;
			cout << "Меняем на : " << endl;
			getline(cin, Word);
			Translator_dictionary swap;
			swap.Set_word(engl_word, Word, num);
			break;
		}
		case 3:
		{
			cout << "Введите слово, у которого хотите узнать перевод:" << endl;
			getline(cin, engl_word);
			word.Get_word(engl_word);
			break;
		}
		case 4:
		{
			cout << "Введите слово, которое хотите проверить на наличие:" << endl;
			getline(cin, engl_word);
			bool check = word.Check_word(engl_word);
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
			word.Number_of_words();
			break;
		}
		case 6:
		{
			cout << "Словарь: " << endl;
			word.Print_dictionary();
			break;
		}
		case 7:
		{
			cout << "Сохранил в словарь. " << endl;
			word.File_print_dictionary(Arr);
			Arr = "";
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