#include <iostream>
#include "DM.h"

DM::DM()
{
	n = 0;
	arr = 0;
}

DM::DM(int q)
{
	n = q;
	arr = new double[n];  //выделяет память для столького количества элементов, сколько мы хотим
	for (int i = 0; i < n; i++)
	{
		arr[i] = 0;
	}
}

DM::DM(const DM & x)
{
	n = x.n;
	arr = new double[n];  //выделяет память для столького количества элементов, сколько мы хотим
	for (int i = 0; i < n; i++)
	{
		arr[i] = x.arr[i];    //Копируесм массив, как strcpy
	}
}

DM::~DM()
{
	if (n > 0)  //проверка на освобождение памяти. Если n = 0, то удаляться не будет
	delete[]arr;
}

DM & DM::operator=(const DM & x)
{
	if (n != x.n)
	{
		delete[]arr;
		n = x.n;
		arr = new double[n];  //выделяет память для столького количества элементов, сколько мы хотим
	}
	for (int i = 0; i < x.n; i++)
	{
		arr[i] = 0;
	}
	return *this;
}

void DM::set_n(int f)
{
	if (n > 0)
	delete[]arr;
	n = f;
	arr = new double[n];  //выделили новую память
}

int DM::get_n()
{
	return n;
}

void DM::set_element(int x, double y)
{
	arr[x] = y;  //записывает в массив по заданному номеру элемента
}

double DM::get_element(int x)
{
	return arr[x];
}

double DM::get_min()
{
	double min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}

int DM::test()
{
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return 0;
	}
	return 1;
}

DM DM::select()
{
	DM Result(n / 2);
	for (int i = 1; i < n; i += 2)
	{
		Result.arr[i/2] = arr[i];
	}
	return Result;
}
