#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

class Translation_Dictionary
{
public:
	Translation_Dictionary();
	Translation_Dictionary(const Translation_Dictionary& str);					//конструктор копирования
	Translation_Dictionary& operator=(const Translation_Dictionary& str);		//оператор присваивания
	~Translation_Dictionary();
	void enter_words(string, string);											//добавить слово в словарь
	void console_output();														//вывод на консоль
	string eng_translation(string);												//узнать перевод слова
	bool сheck_word(string);													//наличие слова в словаре
	bool change_translation(string, string);									//изменить перевод
	int get_amount();															//число слов в словаре
	void file_save(string);														//сохранить в файл
	void read_file(string);														//прочитать из файла
private:
	int l;
	int len;
	string* rus;		//массив русских слов
	string* eng;		//массив английских слов
};

Translation_Dictionary::Translation_Dictionary()
{
	l = 0;
	len = 100;
	eng = new string[len];
	rus = new string[len];
}
Translation_Dictionary& Translation_Dictionary::operator=(const Translation_Dictionary& str)
{
	if (len != str.len)
	{
		delete[] rus;
		delete[] eng;
		len = str.len;
		rus = new string[len];
		eng = new string[len];
	}
	for (int i = 0; i < str.len; i++)
	{
		rus[i] = str.rus[i];
		eng[i] = str.eng[i];
	}
	return *this;
}
Translation_Dictionary::Translation_Dictionary(const Translation_Dictionary& str)
{
	len = str.len;
	rus = new string [len];
	eng = new string[len];
	for (int i = 0; i < len; i++)
	{
		rus[i] = str.rus[i];
		eng[i] = str.eng[i];
	}
}
Translation_Dictionary::~Translation_Dictionary()
{
	delete[]eng;
	delete[]rus;
}
void Translation_Dictionary::enter_words(string my_rus_word, string my_eng_word)
{
		rus[l] = my_rus_word;
		eng[l] = my_eng_word;
		l = l + 1;
}
void Translation_Dictionary::console_output()
{
	for (int i = 0; i < l; i++)        
		cout << rus[i] << " - " << eng[i] <<endl;
}
string Translation_Dictionary::eng_translation(string my_rus_word)
{
	for (int i = 0; i < l; i++)
	{
		if (rus[i] == my_rus_word)
			return eng[i];
	}
	return string();
}
bool Translation_Dictionary::сheck_word(string my_rus_word)
{
	for (int i = 0; i < l; i++)
	{
		if (my_rus_word == rus[i])
			return true;
	}
	return false;
}
bool Translation_Dictionary::change_translation(string a, string b)
{
	if (сheck_word(a) == false)
	{
		return false;
	}
	for (int i = 0; i < l; i++)
	{
		if (a == rus[i])
		{
			eng[i] = b;
			return true;
		}
	}
	return true;
}
int Translation_Dictionary::get_amount()
{
	return l;
}
void Translation_Dictionary::file_save(string name)
{
	FILE* out;
	fopen_s(&out, name.c_str(), "w");

	for (int i = 0; i < l; i++)
	{
		fprintf(out, "%s - %s\n", rus[i].c_str(), eng[i].c_str());
	}
	fclose(out);
}

void Translation_Dictionary::read_file(string name)
{
	FILE* in;
	errno_t err = fopen_s(&in, name.c_str(), "r");
	if (in == NULL)
	{
		return;
	}
	char my_rus_word[100];
	char my_eng_word[100];
	l = 0;
	while (fgets(my_rus_word, 100, in))
	{
		my_rus_word[strlen(my_rus_word) - 1] = 0;
		char* s = strchr(my_rus_word, ' ');
		*s = 0;
		rus[l] = string(my_rus_word);
		eng[l] = string(s + 3);
		l++;
	}
	fclose(in);
}

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Translation_Dictionary Sl;
	Sl.read_file("Dictionary.txt");
	Sl.console_output();
	int a = 0;
	while (a != 7)
	{
		cout << endl << "Введите:" << endl << "0 - Добавить слово и его перевод в словарь" << endl << "1 - Изменить перевод указанного слова" << endl << "2 - Узнать перевод выбранного слова" << endl << "3 - Проверить наличие слова в словаре" << endl << "4 - Узнать число слов в словаре" << endl << "5 - Сохранить словарь в файл" << endl << "6 - Прочитать словарь из файла" << endl << "7 - Выйти из программы" << endl;
		cin >> a;
		switch (a)
		{
		case 0:
		{
			string my_rus_word, my_eng_word;
			cout << "Введите слово по-русски: ";
			cin >> my_rus_word;
			cout << "Введите его перевод на английский: ";
			cin >> my_eng_word;
			Sl.enter_words(my_rus_word, my_eng_word);
			break;
		}
		case 1:
		{
			string a, b;
			cout << "Введите слово, перевод которого хотите изменить: ";
			cin >> a;
			if (Sl.сheck_word(a) == false)
			{
				cout << "Данное слово отсутсвует в cловаре " << endl;
			}
			else if (Sl.сheck_word(a) == true)
			{
				cout << "Введите новый перевод: ";
				cin >> b;
				if (Sl.change_translation(a, b))
				{
					cout << "Новый словарь: " << endl;
					Sl.console_output();
				}
			}
			break;
		}
		case 2:
		{
			string n;
			cout << "Введите слово, чтобы узнать его перевод: ";
			cin >> n;
			if (Sl.сheck_word(n))
			{
				string p = Sl.eng_translation(n);
				cout << p << endl;
			}
			else cout << "Слово отсутсвует в словаре" << endl;
			break;
		}
		case 3:
		{
			string n;
			cout << "Введите слово, чтобы проверить наличие: ";
			cin >> n;
			if (Sl.сheck_word(n))
				cout << "Слово есть в словаре" << endl;
			else cout << "Слово отсутсвует в словаре" << endl;
			break;
		}
		case 4:
		{
			cout << "В словаре " << Sl.get_amount() << " " << "слов(а)" << endl;
			break;
		}
		case 5:
		{
			Sl.file_save("Dictionary.txt");
			cout << "Словарь сохранен"<<endl;
			break;
		}
		case 6:
		{
			Sl.read_file("Dictionary.txt");
			cout << "Cловарь: " << endl;
			Sl.console_output();
			break;
		}
		case 7:
		{
			system("pause");
			break;
			{
		default:
			cout << "Вы неправильно ввели номер. Данная функция отсутсвует" << endl;
			break;
			}
		}
		}
	}
}