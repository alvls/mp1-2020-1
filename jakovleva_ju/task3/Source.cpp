#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

class Dictionary
{
private:
	int l;
	int len;
	string* rus;
	string* eng;
public:
	Dictionary();
	~Dictionary();
	void add_new_word(string, string);			//добавить слово в словарь
	void output();								//вывод
	string eng_translete(string);				//узнать перевод слова
	bool сheck_word(string);					//наличие слова в словаре
	bool change_translation(string, string);	//изменить перевод
	int get_amount();							//число слов
	void saved_to_file(string);					//сохранить в файл
	void read_from_file(string);				//прочитать из файла
};

Dictionary::Dictionary()
{
	l = 0;
	len = 100;
	eng = new string[len];
	rus = new string[len];
}
Dictionary::~Dictionary()
{
	delete[]eng;
	delete[]rus;
}
void Dictionary::add_new_word(string r, string e)
{
		rus[l] = r;
		eng[l] = e;
		l++;
}
void Dictionary::output()
{
	for (int i = 0; i < l; i++)
	{
		cout << rus[i];
		cout << " - ";
		cout << eng[i];
		cout << endl;
	}
}
string Dictionary::eng_translete(string r)
{
	for (int i = 0; i < l; i++)
	{
		if (rus[i] == r)
			return eng[i];
	}
	return string();
}
bool Dictionary::сheck_word(string r)
{
	for (int i = 0; i < l; i++)
	{
		if (r == rus[i])
			return true;
	}
	return false;
}
bool Dictionary::change_translation(string a, string b)
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
int Dictionary::get_amount()
{
	return l;
}
void Dictionary::saved_to_file(string name)
{
	FILE* out;
	fopen_s(&out, name.c_str(), "w");

	for (int i = 0; i < l; i++)
	{
		fprintf(out, "%s - %s\n", rus[i].c_str(), eng[i].c_str());
	}

	fclose(out);
}

void Dictionary::read_from_file(string name)
{
	FILE* in;
	errno_t err = fopen_s(&in, name.c_str(), "r");
	if (in == NULL)
	{
		return;
	}
	char r[100], e[100];
	l = 0;
	while (fgets(r, 100, in))
	{
		r[strlen(r) - 1] = 0;
		char* s = strchr(r, ' ');
		*s = 0;
		rus[l] = string(r);
		eng[l] = string(s + 3);
		l++;
	}
	fclose(in);
}

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Dictionary Sl;
	cout << "Программа русско-английский словарь" << endl;
	Sl.read_from_file("Словарь.txt");

	Sl.output();

	string r, e;
	int w;
	while (true)
	{
		cout << "Введите слово на русском: ";
		cin >> r;
		cout << "Введите его перевод на английский: ";
		cin >> e;
		Sl.add_new_word(r, e);
		cout << "Хотите добавить ещё слово? (1-да, 0-нет)" << endl;
		cin >> r;
		if (r == "0")
			break;
	}

	Sl.output();

	string a, b;
	cout << "Введите слово для замены его перевода: ";
	cin >> a;
	if (Sl.сheck_word(a)==false)
	{
		cout << "Данное слово отсутсвует в cловаре "<< endl;
	}
	else if (Sl.сheck_word(a) == true)
	{
		cout << "Введите новый перевод: ";
		cin >> b;
		if (Sl.change_translation(a, b))
		{
			cout << "Новый словарь: " << endl;
			Sl.output();
		}
	}

	cout << "В словаре " << Sl.get_amount() << " " << "слов(а)" << endl;
	string n;
	cout << "Введите слово для перевода: ";
	cin >> n;
	if (Sl.сheck_word(n))
		cout << "Слово есть в словаре" << endl;
	else cout << "Слово отсутсвует в словаре" << endl;
	string p = Sl.eng_translete(n);
	cout << p << endl;
	
	Sl.saved_to_file("Словарь.txt");

	system("pause");
	return 0;
}