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
	Sl.Read_from_file("Словарь.txt");
	
	Sl.Output();
	
	string r, e;
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

	string rus, eng;
	cout << "Введите слово для замены: ";
	cin >> rus;
	cout << "Введите перевод для замены: ";
	cin >> eng;
	if (Sl.Change(rus, eng))
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

	Sl.Save_to_file("Словарь.txt");

	system("pause");
	return 0;
}