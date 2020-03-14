#include<iostream>
#include<locale>

class DynamicArr
{
private:
	double* arr; //массив 
	int len; //длина массива

public:
	DynamicArr();
	DynamicArr(int size);
	DynamicArr(DynamicArr& x);
	~DynamicArr();
	DynamicArr& operator=(DynamicArr& x);

	int get_len(); //узнать длину массива
	void set_len(int f); //задать длину массива 

	double get(int x); //узнать элемент массива по индексу 
	void set(int x, double zn); //задать элемент массива по его индексу 

	double get_min_el(); //поиск минимального элемента 
	int ubiv(); //проверка на упорядоченность по убыванию
	int rast(); //проверка на упорядоченность по возрастанию 

	DynamicArr nech_podmassiv(); //подмассив с нечётными индексами
};

DynamicArr::DynamicArr()
{
	arr = nullptr;
	len = 0;
}
DynamicArr::DynamicArr(int size)
{
	len = size;
	arr = new double[len];
	for (int i = 0; i < len; i++)
	{
		arr[i] = 0;
	}
}
DynamicArr::DynamicArr(DynamicArr& x)
{
	len = x.len;
	arr = new double[len];
	for (int i = 0; i < len; i++)
	{
		arr[i] = x.arr[i];
	}
}
DynamicArr::~DynamicArr()
{
	delete [] arr;
}
DynamicArr& DynamicArr::operator=(DynamicArr& x)
{
	if (len != x.len)
	{
		delete [] arr;
		len = x.len;
		arr = new double[len];
	}
	for (int i = 0; i < x.len; i++)
	{
		arr[i] = x.arr[i];
	}
	return *this;
}
void DynamicArr::set_len(int f)
{
	if (len > 0)
		delete [] arr;
	len = f;
	arr = new double[len];
}
int DynamicArr::get_len()
{
	return len;
}
void DynamicArr::set(int x, double zn)
{
	arr[x] = zn;
}
double DynamicArr::get(int x)
{
	return arr[x];
}
double DynamicArr::get_min_el()
{
	double min = arr[0];
	for (int i = 0; i < len; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}
int DynamicArr::ubiv()
{
	for (int i = 0; i < len - 1; i++)
	{
		if (arr[i] < arr[i + 1])
			return false;
	}
	return true;
}
int DynamicArr::rast()
{
	for (int i = 0; i < len - 1; i++)
	{
		if (arr[i + 1] < arr[i])
			return false;
	}
	return true;
}
DynamicArr DynamicArr::nech_podmassiv()
{
	DynamicArr Result(len / 2);
	for (int i = 1; i < len; i += 2)
	{
		Result.arr[i / 2] = arr[i];
	}
	return Result;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int k;
	printf("Задайте размер массива: ");
	scanf_s("%d", &k);
	DynamicArr mas(k);
	printf("Размер массива: %d \n", mas.get_len());

	printf("Задайте новый размер массива: ");
	scanf_s("%d", &k);
	mas.set_len(k);
	printf("Новый размер массива: %d \n", mas.get_len());

	printf("Задайте значение элементов: ");
	for (int i = 0; i < k; i++)
	{
		double zn;
		scanf_s("%lf", &zn);
		mas.set(i, zn);
	}

	printf("Ваш массив: ");
	for (int i = 0; i < k; i++)
	{
		printf("%lf ", mas.get(i));
	}
	printf("\n");

	printf("Минимальный элемент: ");
	double r = mas.get_min_el();
	printf("%lf\n", r);

	if (mas.ubiv())
		printf("Упорядоченный по убыванию\n");
	if (mas.rast())
		printf("Упорядоченный по возрастанию\n");
	if (!mas.ubiv() && !mas.rast())
		printf("Не упорядоченный\n");

	DynamicArr Res = mas.nech_podmassiv();
	printf("Ваш подмассив с нечётными индексами: ");
	for (int i = 0; i < Res.get_len(); i++)
	{
		printf("%lf", (Res.get(i)));
	}
	printf("\n");

	system("pause");
}