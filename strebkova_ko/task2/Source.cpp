#include <iostream>
#include <clocale>
#include <cstring>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

class Polynom
{
private:
	int n;
	double coeff[13];
public:
	Polynom()
	{
		n = 0;
		std::memset(coeff, 0, 13 * sizeof(double));
	}

	Polynom(int _n, double* _coeff)
	{
		n = _n;
		for (int i = 0; i <= n; i++)
			coeff[i] = _coeff[i];
	}

	void Set_Deg(int _n)
	{
		n = _n;
	}

	void Set_Coeff(double* _coeff)
	{
		for (int i = 0; i <= n; i++)
		{
			coeff[i] = _coeff[i];
		}
	}

	void Show_Polynom()
	{
		for (int i = 0; i < n; i++)
			cout << coeff[i] << "x^" << n - i << " + ";
		cout << coeff[n] << endl;
	}

	int Find_Deg()
	{
		int i;
		for (i = 0; i <= n; i++)
			if (coeff[i] != 0)
				break;
		return n - i;
	}

	double Get_Coeff(int k)
	{
		return coeff[k];
	}

	double Calculate(double x)
	{
		double f = 0;
		for (int i = 0; i <= n; i++)
		{
			f = f + coeff[i] * std::pow(x, n - i);
		}
		return f;
	}

	Polynom Derivative()
	{
		double Coeff[12];
		for (int i = 0; i < n; i++)
		{
			Coeff[i] = coeff[i] * (n - i);
		}
		int k = n - 1;
		Polynom P = Polynom(k, Coeff);
		return P;
	}

	Polynom& operator=(const Polynom &F)
	{
		n = F.n;
		for (int i = 0; i <= n; i++)
			coeff[i] = F.coeff[i];
		return *this;
	}

	~Polynom() {}
};

void main()
{
	std::setlocale(LC_ALL, "Rus");
	Polynom F;
	int n;
	cout << "Введите степень полинома (от 0 до 12)" << endl;
	cin >> n;
	F.Set_Deg(n);
	double* coeff = new double[n + 1];
	cout << "Введите коэффициенты полинома" << endl;
	for (int i = 0; i <= n; i++)
	{
		cin >> coeff[i];
	}
	F.Set_Coeff(coeff);
	cout << "Выберете действие" << endl;
	cout << "1) Вывести полином на экран" << endl << "2) Узнать степень полинома" << endl << "3) Узнать значение коэффициента по его номеру" << endl;
	cout << "4) Вычислить значение полинома в заданной точке х" << endl << "5) Найти производную полинома" << endl;
	int mode;
	cin >> mode;
	switch (mode)
	{
	case 1:
		F.Show_Polynom();
		break;
	case 2:
		cout << "Степень полинома: " << F.Find_Deg() << endl;
		break;
	case 3:
		cout << "Коэффициенты пронумерованы от 0 до " << n << ", слева направо" << endl;
		cout << "Введите номер коэффицинта" << endl;
		int k;
		cin >> k;
		cout << k << "-ый кэффициент: " << F.Get_Coeff(k) << endl;
		break;
	case 4:
		cout << "Введите х" << endl;
		double x;
		cin >> x;
		cout << "Значение полинома в точке х = " << x << ": " << F.Calculate(x) << endl;
		break;
	case 5:
		Polynom P = F.Derivative();
		P.Show_Polynom();
		break;
	}
	delete[]coeff;
	system("pause");
}