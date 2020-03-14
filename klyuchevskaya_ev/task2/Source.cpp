#include<iostream>
#include<iomanip>
using namespace std;
class Polynom
{
private:
	int deg;
	double *koef;
public:
	Polynom()
	{
		koef = NULL;
	}

	~Polynom()
	{
		delete[]koef;
	}

	double &operator()(int i)
	{
		return koef[i];
	}

	Polynom(int an)
	{
		int i;
		deg = an;
		koef = new double[deg + 1];
		for (i = 0; i <= deg; i++)
		{
			koef[i] = 0;
		}
	}

	Polynom(const Polynom &f)
	{
		deg = f.deg;
		koef = new double[deg + 1];
		for (int i = 0; i <= deg; i++)
			koef[i] = f.koef[i];
	}

	int getdeg()
	{
		for (int i = deg; i >= 0; i--)
			while (koef[i] != 0)
				return i;
	}

	double getkoef(int n)
	{
		if (n <= deg)
			return koef[n];
		else
			return 0.0;
	}

	friend istream &operator>>(istream &s, Polynom &c)
	{
		int i;
		for (i = 0; i <= c.deg; i++)
		{
			s >> c.koef[i];
		}
		return s;
	}

	friend ostream &operator<<(ostream &s, const Polynom &c)
	{
		int i, deg = 0;
		for (i = 0; i <= c.deg; i++)
		{
			if (c.koef[i] != 0)
				deg++;
		}
		if (deg != 0)
		{
			if (c.koef[0] != 0)
			{
				s << c.koef[0];
			}
			for (i = 1; i <= c.deg; i++)
			{
				if (c.koef[i] < 0)
				{
					if (c.koef[i] != -1)
						s << c.koef[i] << "x^" << i;
					else
						s << "-" << "x^" << i;
				}
				else
				{
					if (c.koef[i] != 0)
					{
						if (c.koef[i] != 1)
							s << "+" << c.koef[i] << "x^" << i;
						else
							s << "+" << "x^" << i;
					}
				}
			}
		}
		else
		{
			s << 0;
		}
		return s;
	}

	double getvalue(double x)
	{
		double result = koef[0];
		double per = x;
		for (int i = 1; i <= deg ; i++)
		{
			result = result + koef[i] * per; 
			per = per*x;
		}
		return result;
	}

	Polynom derivative()
	{
		int i;
		Polynom Z(deg - 1);
		for (i = 0; i <= deg - 1; i++)
		{
			Z.koef[i] = (i + 1)*koef[i + 1];
		}
		return Z;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int deg,n;
	double x;
	cout << "Введите степень полинома от 0 до 12 : ";
	cin >> deg;
	Polynom A(deg);
	cout << "Введите коэффициенты полинома, начиная со свободного члена: " << '\n';
	cin >> A;
	cout << "Многочлен: " << A << '\n';
	cout << "Степень данного полинома: " << A.getdeg() << '\n';
	cout << "Введите номер нужного коэффициента: ";
	cin >> n;
	cout << "Коэффициент под этим номером = " << A.getkoef(n) << '\n';
	cout << "Введите значение x: ";
	cin >> x;
	cout << "Значение многочлена в данной точке = " << A.getvalue(x) << '\n';
	cout << "Производная полинома :" << A.derivative() << '\n';
	system("pause");
}