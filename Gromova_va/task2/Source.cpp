#include <iostream>
#include <clocale> 
using namespace std; class dynamarr
{
private:
	int *din_arr;
	int size;
public:
	dynamarr()
	{
		size = 0;
		din_arr = nullptr;
	}
	dynamarr(int n) : size(n)
	{
		din_arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			din_arr[i] = 0;
		}
	}
	dynamarr(const dynamarr &mass)// копирования данных массива
	{
		din_arr = new int[mass.size];
		size = mass.size;
		for (int i = 0; i < mass.size; i++)
		{
			din_arr[i] = mass.din_arr[i];
		}
	}
	dynamarr& operator=(const dynamarr &mass)//оператор присваивания
	{
		if (this != &mass)
		{
			delete[] din_arr;
			din_arr = new int[mass.size];
			for (int i = 0; i < mass.size; i++)
			{
				din_arr[i] = mass.din_arr[i];
			}
			size = mass.size;
		}
		return *this;
	}
	void changel(int index, int number)
	{
		din_arr[number] = index;
	}
	int getelement(int number)
	{
		return din_arr[number];
	}
	int minel()
	{
		int min = din_arr[0];
		for (int i = 0; i < (size - 1); i++)
		{
			if (din_arr[i + 1] < min)
			{
				min = din_arr[i + 1];
			}
		}
		return min;
	}
	bool SortCheck()//проверка на упорядоченность элементов в массиве;
	{
		int i;
		bool Check = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (din_arr[i] > din_arr[i + 1])
			{
				return Check;
			}
		}
		if (i == size - 1)
		{
			Check = 1;
			return Check;
		}
	}
	dynamarr Subarr() // создание подмассива с нечетными элементами
	{
		int i, j = 0, m = 0;
		dynamarr subarr(size / 2);
		double n;
		for (i = 0; i < size; i++)
		{
			n = i % 2;
			if (n != 0)
			{
				m = din_arr[i];
				subarr.changel(m, j);
				j++;
			}
		}
		return subarr;
	}
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << " " << i << " элемент - " << din_arr[i] << endl;

		}
	}
	~dynamarr()
	{
		delete[] din_arr;
	}
};
int main(void)
{
	setlocale(0, "");
	int n, v;
	int elements;
	int num;
	int type = 0;
	cout << "Введите размер массива: " << endl;
	cin >> n;
	dynamarr mass(n);
	do
	{
		cout << "Что вы хотите сделать:/n 1-задать элемент массива по его индексу.(Нумерация массива с 0)\n 2-Узнать элемент по индексу 3-Узнать минимальный элемент./n 4-Проверить, является ли массив упорядоченным./n 5- Выделить подмассив с нечетными числами." << endl;
		cin >> v;
		while ((v < 1) || (v > 5))
		{
			cout << "Что вы хотите сделать:/n 1-задать элемент массива по его индексу.(Нумерация массива с 0)\n 2-Узнать элемент по индексу 3-Узнать минимальный элемент./n 4-Проверить, является ли массив упорядоченным./n 5- Выделить подмассив с нечетными числами." << endl;
			cin >> v;
		}
		switch (v)
		{
		case 1:
			cout << "Введите индекс элемента, который хотите изменить:" << endl;
			cin >> num;
			cout << "Введите новый элемент:\n" << num << " элемент: ";
			cin >> elements;
			mass.changel(elements, num);
			break;
		case 2:
			cout << "Введите индекс:\n";
			cin >> num;
			cout << "\nЭлемент под номером " << num << " - это  " << mass.getelement(num);
			break;
		case 3:
			cout << "Минимальный элемент: " << mass.minel() << endl;
			break;
		case 4:
			if (mass.SortCheck() == 1)
				cout << "Упорядочен." << endl;
			else
				cout << "Не упорядочен." << endl;
			break;
		case 5:
			dynamarr mas;
			mas = mass.Subarr();
			cout << "Полученый подмассив :" << endl;
			mas.Print();
			break;
		}
		cout << " Хотите закончить работу?/n1-да,0-нет" << endl;
		cin >> type;
		while ((type != 0) && (type != 1))
		{
			cout << ("Введите  0 или 1.\n");
			cin >> type;
		}
	} while (type == 0);
	system("pause");
	return 0;
}