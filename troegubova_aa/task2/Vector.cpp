#include <clocale>
#include <iomanip>
#include <iostream>
#include <math.h>

#include "Vector.h"

void set_size(Vector vec)
{
	int n;
	std::cout << "Задайте размер вектора: " << std::endl;
	std::cin >> n;
	while ((n < 0) || (n > 20))
	{
		std::cout << "Введено некорректное значение, введите данные ещё раз: ";
		std::cin >> n;
	}
	vec.setSize(n);
}
void set_comp(Vector vec)
{
	int numd, valute;
	std::cout << "Ведите номер компаненты: \n";
	std::cin >> numd;
	std::cout << "Введите значение компоненты по указанному номеру: \n";
	std::cin >> valute;
	vec.setComp(numd, valute);
}
void get_size(Vector vec)
{
	int size;
	size = vec.getSize();
	std::cout << "Вектор: " << vec << "Размер вектора: " << size << std::endl;
}
void get_comp(Vector vec)
{
	int comp, numb;
	std::cout << "Введите номер компоненты, значение которой вы хотите узнать: ";
	std::cin >> numb;
	while ((numb < 0) || (numb >= vec.getSize()))
	{
		std::cout << "Введено некорректное значение, введите данные ещё раз: ";
		std::cin >> numb;
	}
	comp = vec.getComp(numb);
	std::cout << "Вектор: " << vec << "Значение компаненты под " << numb << " номером: " << comp << std::endl;
}
void get_len(Vector vec)
{
	double len;
	len = vec.getLen();
	std::cout << "Вектор: " << vec << "Длина вектора:" << len << std::endl;
}
void scalar_mul(Vector vec1, Vector vec2)
{
	std::cout << "Вектор 1: " << vec1 << "Вектор 2: " << vec2 << "Скалярное произведение: " << vec1 * vec2 << std::endl;
}

void get_add(Vector vec1, Vector vec2)
{
	std::cout << "Вектор 1: " << vec1 << "Вектор 2: " << vec2 << "Сумма: " << vec1 + vec2 << std::endl;
}

int main()
{
	std::setlocale(LC_CTYPE, "Russian");
	std::cout << std::setprecision(2) << std::fixed;

	int *d1 = new int[12];
	for (int i = 0; i < 12; ++i)
		d1[i] = 1 + (i + 1) * 2;
	Vector v1(20, 6), v2(12, d1), v3(12, 15);
	int i, act, r;
	void(*Act_1[2])(Vector vec1, Vector vec2) = { scalar_mul, get_add };
	void(*Act_2[5])(Vector vec) = { set_size, set_comp, get_size, get_comp, get_len };
	while (true)
	{
		system("cls");
		std::cout << "Выберит нужное действие, выбрав соответствующую цифру:\n1) задать размер вектора\n2) задать компоненту вектора по ее номеру\n3) узнать размер вектора\n4) узнать компоненту вектора по ее номеру\n5) вычислить длину вектора\n6) найти скалярное произведение двух векторов\n7) найти сумму двух векторов одного размера\n";
		std::cin >> act;
		if ((act == 1) || (act == 2))
			Act_2[act - 1](v1);
		else
		{
			if ((act > 2) && (act < 6))
				Act_2[act - 1](v2);
			else
				Act_1[act - 6](v2, v3);
		}
		std::cout << "Продолжить работу программы?\n1)да\n2)нет\n";
		std::cin >> i;
		if (i != 1)break;
	}
	system("pause");
}