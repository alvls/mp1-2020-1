#include <iostream>
#include <cmath>
#include <clocale>
using std::cout;
using std::cin;
using std::endl;

class Integral
{
private:
	double(*function)(double);
	double downlim, uplim;
	int n;
	double result;
	int mode;
public:
	Integral(double(*f)(double) = exp, double _downlim = 0, double _uplim = 0, int _n = 1, double _result = 0, int _mode = 1):
	function(f), downlim(_downlim), uplim(_uplim), n(_n), result(_result), mode(_mode)
	{}

	void SetFunction(double(*f)(double))
	{
		function = f;
	}

	void SetLimits(double _downlim, double _uplim)
	{
		downlim = _downlim;
		uplim = _uplim;
	}

	void GetLimits(double& _downlim, double& _uplim)
	{
		
		_downlim = downlim;
		_uplim = uplim;
	}

	void SetNumber(int _n)
	{
		n = _n;
	}

	void SetMode(char _mode)
	{
		mode = _mode;
	}

	void Calculate()
	{
		double h = (uplim - downlim) / n;
		double x;
		switch (mode)
		{
			case 1:
				x = downlim;
				break;
			case 2:
				x = downlim + h / 2;
				break;
			case 3:
				x = downlim + h;
				break;
		}
		for (int i = 0; i < n; i++)
		{
			result = result + function(x);
			x = x + h;
		}
		result = result * h;
	}

	void ShowResult()
	{
		cout << "Результат вычисления значения интеграла: " << result << endl;
	}

	Integral& operator=(const Integral &_F)
	{
		function = _F.function;
		downlim = _F.downlim;
		uplim = _F.uplim;
		n = _F.n;
		mode = _F.mode;
		result = _F.result;
		return *this;
	}

	Integral(const Integral &_F)
	{
		function = _F.function;
		downlim = _F.downlim;
		uplim = _F.uplim;
		n = _F.n;
		mode = _F.mode;
		result = _F.result;
	}

	~Integral() {}
};

void main()
{
	setlocale(LC_ALL, "Rus");
	bool flag = false;
	Integral F;
	double(*func[11])(double) = { exp, abs, sqrt, sin, cos, tan, asin, acos, atan, log, log10 };
	do
	{
		cout << "Выберете функуию" << endl;
		cout << "0)exp" << endl << "1)abs" << endl << "2)sqrt" << endl << "3)sin" << endl << "4)cos" << endl << "5)tan" << endl << "6)asin" << endl << "7)acos" << endl << "8)atan" << endl;
		cout << "9)log" << endl << "10)log10" << endl;
		int num_of_func;
		cin >> num_of_func;
		F.SetFunction(func[num_of_func]);
		double downlim, uplim;
		cout << "Введите левую границу интегрирования:" << endl;
		cin >> downlim;
		cout << "Введите правую границу интегрирования:" << endl;
		cin >> uplim;
		F.SetLimits(downlim, uplim);
		cout << "Введите количество отрезков интегрирования" << endl;
		int n;
		cin >> n;
		F.SetNumber(n);
		cout << "Выберете метод вычисления:" << endl << "1)Левые прямоугольники" << endl << "2)Средние прямоугольники" << endl << "3)Правые прямоугольники" << endl;
		int mode;
		cin >> mode;
		F.SetMode(mode);
		F.Calculate();
		F.ShowResult();
		double down, up;
		F.GetLimits(down, up);
		cout << "Пределы интегрирования: от " << down << " до " << up << endl;
		cout << "Вычислить новый интеграл? (1 - Да, 0 - Нет)" << endl;
		cin >> flag;
	} while (flag != false);
	system("pause");
}