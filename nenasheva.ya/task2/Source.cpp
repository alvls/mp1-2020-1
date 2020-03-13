#include <iostream>
#include <locale.h>
#include "DM.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int k;
	cout << "Введите длину массива: ";
	cin >> k;

	DM mas1(k);
	cout << "Длина массива: " << mas1.get_n() << '\n';

	cout << "Введите новую длину массива: ";
	cin >> k;
	mas1.set_n(k);
	cout << "Новая длина массива: " << mas1.get_n() << '\n';

	cout << "Вводим значение элементов: ";
	for (int i = 0; i < k; i++)
	{
		double y;
		cin >> y;
		mas1.set_element(i, y);   // Используется функция, задающая значение y элементу с номером i
	}

	cout << "Выводим массив: ";
	for (int i = 0; i < k; i++)
	{
		cout << mas1.get_element(i) << ' ';   // используется функция, возвращающая значение элемента по индексу
	}
	cout << '\n';

	cout << "Ищем минимальный элемент массива: ";
	double r = mas1.get_min();
	cout << r << '\n';

	if (mas1.test())
	    cout << "Упорядоченный\n";
	else cout << "Неупорядоченный\n";

	DM Res = mas1.select();   //Выбор элементов с нечётными индексами
	cout << "Выводим подмассив: ";
	for (int i = 0; i < Res.get_n(); i++)
	{
		cout << Res.get_element(i) << ' ';   // используется функция, возвращающая значение элемента по индексу
	}
	cout << '\n';

	system("pause");
}
