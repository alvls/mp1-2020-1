#include <stdlib.h>
#include <iostream>
#include <vector>
#include <new.h>
using namespace std;

class Vectors
{
private:                        
	int *coords;
	int size;
public:
	Vectors()   //по умолчанию
	{
		size = 2;
		coords = new int[2];
		coords[0] = 0;
		coords[1] = 0;
	}
	Vectors(const Vectors& v) //копирования		
	{
			int k = 0;
			size = v.size;
			coords = new int[size];
			for (k = 0; k < size; k++)
			{
				coords[k] = v.coords[k];
			}
	}
	Vectors(const int n) // перегрузка конструктора
	{
			size = n;
			coords = new int[size];
			int k;
			for (k = 0; k < n; k++)
			{
				coords[k] = 0;
			}	
	}
	void inkomp(const int num, int a1) //задать компоненту по номеру
	{
		coords[num - 1] = a1;
	}
	void outkomp(int num) //узнать компоненту по номеру
	{
		cout << "comp N" << num << "   " << coords[num-1] << endl;
	}
	void outSize() //узнать размер
	{
		cout << "size   " << size << endl;
	}
	void dlina() // узнать длину
	{
		int k;
		double b = 0;
		for (k = 0; k < size; k++)
		{
			int a = coords[k];
			b = b + (a * a);
		}
		cout<< "dlina vectora   " << sqrt(b) << endl;
	}
	~Vectors() //деструктор
	{
		delete [] coords;
	}
	Vectors& operator* (const Vectors& other)
	{
		if (size > other.size)
		{
			Vectors tmpvector1(size);
			for (int i = 0; i < other.size; i++)
			{
				tmpvector1.coords[i] = coords[i] * other.coords[i];
			}
			delete[] coords;
			coords = new int(size);
			*this = tmpvector1;
			return *this;
		}
		else
		{
			Vectors tmpvector1(other.size);
			for (int i = 0; i < size; i++)
			{
				tmpvector1.coords[i] = coords[i] * other.coords[i];
			}
			delete[] coords;
			coords = new int(other.size);
			for (int i = 0; i < other.size; i++)
			{
				coords[i] = tmpvector1.coords[i];
			}
			return *this;
		}
	}
	Vectors& operator+ (const Vectors& other)
	{
		if (size!=other.size)
		{
			cout << "error(+)";
		}
		else 
		{
			for (int i = 0; i < size; i++)
			{
				coords[i] = coords[i] + other.coords[i];
			}
		}
		return *this;
	}
	Vectors& operator= (const Vectors& other) // присваивания
	{
		size = other.size;
		delete[] coords;
		coords = new int[other.size];
		for (int i = 0; i < other.size; i++)
		{
			coords[i] = other.coords[i];
		}

		return *this;
	}
	friend ostream& operator << (ostream& out, const Vectors& f);
};
ostream& operator << (ostream& out, const Vectors& f) // Вывод
{
	out << "(";
	int k;
	for (k = 0; k < f.size;k++) 
	{
		out << f.coords[k] << ";";
	}
	out << ")" << endl;
	return out;
}


void main()
{
	Vectors v3;
	cout << v3;
	Vectors v1(3);
	cout << "v1 ";
	v1.outSize();
	v1.inkomp(1, 60);
	v1.inkomp(2, 3);
	v1.inkomp(3, 0);
	v1.outkomp(2);
	v1.dlina();
	Vectors v2(2);
	v2.inkomp(1, 4);
	v2.inkomp(2, 1);
	//v1.scalar(v2);
	cout << v1;
	cout << v2;
	Vectors v4(v1);
	cout << v4;
	Vectors v5(3);
	v5.inkomp(1, 4);
	v5.inkomp(2, 3);
	v5.inkomp(3, 80);
	Vectors v6;
	v6.inkomp(1, 9);
	v6.inkomp(2, 9);
	cout << v5;
	Vectors v7;
 	v7= v5*v6;
	cout << v7;
	Vectors v8 = v6 + v2;
	cout << v8;
	cout << "end";
	system("pause");
	
}