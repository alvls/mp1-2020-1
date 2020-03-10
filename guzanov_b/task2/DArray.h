#pragma once
#include <iostream>
using namespace std;
class DArray
{
private:
	float* arr;
	int SIZE;
public:
	DArray(int _n = 1)  //1) ������ ������ �������,
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
	float& operator[](int index)  //3) ������/������ ������� ������� �� ��� �������,
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
	int GetSIZE()  //2) ������ ������ �������,
	{
		return SIZE;
	};
	float Minim()   //5) ����� ����������� ������� �������,
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
	int ControleGreite()  //6) ���������, �������� �� ������ �������������,
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
			return 0;//������ ����������
		}
		else
		{
			return 1;//������ �� ����������
		}
	}
	void Chose(DArray& tmp)  //7) �������� �� ������� ��������� � ���������� � ��������� ���������.
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







//����� ������ ��������� ��� ����������� ������������, ����������, �������� ������������, � ����� ������� �������� ���� �� �������.

