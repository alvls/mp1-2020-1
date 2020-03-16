#define _CRT_SECURE_NO_WARNINGS
#include<locale.h>
#include <iostream>
#include <math.h>
using namespace std;

class Integral
{
private:
	double(*func)(double);
	double leftBorder, rightBorder;
	int n;
	double result;
public:
	Integral()
	{
		func = exp;
		leftBorder = 0;
		rightBorder = 1;
		n = 1000;
		result = 0;
	}
	Integral(double nleft, double nright, double(*function)(double) = exp, int kol = 1000)
	{
		func = function;
		leftBorder = nleft;
		rightBorder = nright;
		n = kol;
		result = 0;
	}
	void SetFunction(double(*function)(double))
	{
		func = function;
	}
	void SetBorders(double nleft, double nright)
	{
		leftBorder = nleft;
		rightBorder = nright;
	}
	void SetNumberOfSegments(int kol)
	{
		n = kol;
	}
	double GetLeftBorder()
	{
		return leftBorder;
	}
	double GetRightBorder()
	{
		return rightBorder;
	}
	double CalculateByLeftRectangle()
	{
		double h, left_1;
		int i;
		h = (rightBorder - leftBorder) / n;
		left_1 = leftBorder;
		for (i = 0; i < n; i++)
		{
			result = result + func(left_1);
			left_1 = left_1 + h;
		}
		result = result * h;
		return result;
	}
	double	CalculateByRightRectangle()
	{
		double h, right_1;
		int i;
		h = (rightBorder - leftBorder) / n;
		right_1 = leftBorder + h;
		for (i = 1; i <= n; i++)
		{
			result = result + func(right_1);
			right_1 = right_1 + h;
		}
		result = result * h;
		return result;
	}
	double	CalculateByMiddleRectangle()
	{
		double h, middle;
		int i;
		h = (rightBorder - leftBorder) / n;
		middle = leftBorder + (h / 2);
		for (i = 1; i <= n; i++)
		{
			result = result + func(middle);
			middle = middle + h;
		}
		result = result * h;
		return result;
	}

	Integral(const Integral &I)
	{
		func = I.func;
		leftBorder = I.leftBorder;
		rightBorder = I.rightBorder;
		n = I.n;
		result = I.result;
	}

	Integral& operator=(const Integral &I)
	{
		func = I.func;
		leftBorder = I.leftBorder;
		rightBorder = I.rightBorder;
		n = I.n;
		result = I.result;
	}
};

void main()
{
	setlocale(LC_ALL, "Rus");
	int  f = 0, metod= 0;
	double(*_function[10])(double) = {exp, cos, sin, tan, acos, asin, atan, sqrt, log, log10 };
	double left, right;
	int N;
	Integral A;
	double result_ = 0;
	cout << "Выберите функцию для рассчета интеграла:\n1)exp\n2)cos\n3)sin\n4)tan\n5)acos\n6)asin\n7)atan\n8)sqrt\n9)log\n10)log10\n";
	cin >> f;
	f--;
	A.SetFunction(_function[f]);
	cout << "Введите правую и левые границы : ";
	cin >> right >> left;
	while (right <= left)
	{
		cout << "Правая граница должна быть больше левой!\n";
		cin >> right >> left;
	}
	A.SetBorders(left, right);
	cout << "Пределы интегрирования :\n";
	left = A.GetLeftBorder();
	right = A.GetRightBorder();
	cout << "Правая граница : " << right << '\n' << "Левая граница : " << left << '\n';
	cout << "Задайте число отрезков (разбиений)\n";
	cin >> N;
	A.SetNumberOfSegments(N);
	cout << "Выберите метод вычисления:\n1)Левые прямоугольники\n2)Правые прямоугольники\n3)Средние прямоугольники\n";
	cin >> metod;
	switch (metod)
	{
	case 1:
		result_ = A.CalculateByLeftRectangle();
		break;

	case 2:
		result_= A.CalculateByRightRectangle();
		break;
	
	case 3:
		result_ = A.CalculateByMiddleRectangle(); 
		break;
	}
	result_ = A.CalculateByMiddleRectangle();
	cout << "Результат вычислений : " << result_ << '\n';
	system("pause");
}