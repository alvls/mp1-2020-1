#pragma once
#include <iostream>
using namespace std;
class DArray
{
private:
	float* arr;
	int SIZE;
public:
	DArray(int _n = 1)  //1) задать размер массива,
	{
		SIZE = _n;
		arr = new float[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			arr[i] = 0;
		}
	};
	~DArray()
	{
		delete[] arr;
	};
	DArray(const DArray& tmp)
	{
		SIZE = tmp.SIZE;
		arr = new float[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			arr[i] = tmp.arr[i];
		}
	};
	DArray& operator=(DArray tmp)
	{
		if (SIZE != tmp.SIZE)
		{
			if (SIZE != 0)
			{
				delete arr;
			}
			SIZE = tmp.SIZE;
			arr = new float[SIZE];
		}
		for (int i = 0; i < SIZE; i++)
		{
			arr[i] = tmp.arr[i];
		}
		return *this;
	};
	float& operator[](int index)  //3) задать/узнать элемент массива по его индексу,
	{
		float error = 2147483647.;
		if ((index >= 0) && (index < SIZE))
		{
			return arr[index];
		}
		else
		{
			return error;
		}
	};
	int GetSIZE()  //2) узнать размер массива,
	{
		return SIZE;
	};
	float Minim()   //5) найти минимальный элемент массива,
	{
		float Min = arr[0];
		for (int i = 0; i < SIZE; i++)
		{
			if (Min > arr[i])
			{
				Min = arr[i];
			}
		}
		return Min;
	}
	int ControleGreite()  //6) проверить, является ли массив упорядоченным,
	{
		int Res = 0;
		for (int i = 0; i < SIZE - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				Res++;
			}
		}
		if ((Res == 0) || (Res == SIZE - 1))
		{
			return 0;//массив упорядочен
		}
		else
		{
			return 1;//массив не упорядочен
		}
	}
	void Chose(DArray& tmp)  //7) выделить из массива подмассив с элементами с нечетными индексами.
	{
		DArray Res(SIZE / 2);
		for (int i = 0; i < Res.SIZE; i++)
		{
			Res[i] = arr[i * 2];
		}
		tmp = Res;
	};
	friend ostream& operator<<(ostream& out, DArray tmp)
	{
		for (int i = 0; i < tmp.SIZE; i++)
			out << tmp[i] << endl;
		return out;
	}
};







//Класс должен содержать все необходимые конструкторы, деструктор, оператор присваивания, а также «уметь» выводить себя на консоль.

