#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include "Dictionary.h"
using namespace std;

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Dictionary Sl;
	Sl.Read_form_file("Словарь.txt");

	string r, e;
	int w;
	while(true)
	{
		cout << "Введите слово: ";
		cin >> r;
		cout << "Введите его перевод: ";
		cin >> e;
		Sl.Add_word(r, e);
		cout << "Хотите добавить ещё слово? (да/нет)" << endl;
		cin >> r;
		if (r == "нет")
			break;
	}
	Sl.Output();

	string a, b;
	cout << "Введите слово для замены: ";
	cin >> a;
	cout << "Введите перевод для замены: ";
	cin >> b;
	if (Sl.Change(a, b))
	{
		cout << "Новый словарь: " << endl;
		Sl.Output();
	}
	else
		cout << "Такого слова нет" << endl;

	cout << "В словаре " << Sl.Get_count() << " " << "слов(а)" << endl;
	string q;
	cout << "Введите слово для перевода: ";
	cin >> q;
	if (Sl.Check_word(q))
		cout << "Такое слово есть" << endl;      
	else cout << "Такого слова нет" << endl;
	string p = Sl.Get_en(q);
	cout << p << endl;

	Sl.Saved_to_file("Словарь.txt");

	system("pause");
	return 0;
}