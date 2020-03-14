#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;
long factorial(int number)
{
	long factorial = 1;
	for (int i = 1; i <= number; i++)
		factorial = factorial * i;
	return factorial;
}
class TeilorFormuls
{
private:
	int NFunction;
	double x;
	int n;
public:
	TeilorFormuls(int NumFunction = 0, double x1 = 0, int num = 0)
	{
		NFunction = NumFunction;
		x = x1;
		n = num;
	}
	~TeilorFormuls()
	{

	}
	TeilorFormuls(TeilorFormuls& fun)
	{
		NFunction = fun.NFunction;
		x = fun.x;
		n = fun.n;
	}
	TeilorFormuls& operator=(const TeilorFormuls& fun)
	{
		NFunction = fun.NFunction;
		x = fun.x;
		n = fun.n;
		return *this;
	}
	void SetFunction(int number)
	{
		if (number != 1 && number != 2 && number != 3)
			throw number;
		NFunction = number;
	}
	int DiscoverFunction()
	{
		return NFunction;
	}
	void SetMemberSeries(int number)
	{
		if (number < 0)
			throw number;
		n = number;
	}
	int DiscoverMemberSeries()
	{
		return n;
	}
	void SetX(double number)
	{
		x = number;
	}
	double DiscoverX()
	{
		return x;
	}
	friend void FormulaMember(TeilorFormuls& fun);
	double ValueMember(int number)
	{
		switch (NFunction)
		{
		case 1:
		{
			return pow(x, 2 * number - 1) / factorial(2 * number - 1);
		}
		case 2:
		{
			return pow(x, 2 * number - 2) / factorial(2 * number - 2);
		}
		case 3:
		{
			return pow(x, number - 1) / factorial(number - 1);
		}
		}
	}
	double ValueSeries()
	{
		double value = 0.0;
		switch (NFunction)
		{
		case 1:
		{
			for (int i = 0; i < n; i++)
				value = value + pow(-1, i) * pow(x, 2 * i + 1) / factorial(2 * i + 1);
			break;
		}
		case 2:
		{
			for (int i = 0; i < n; i++)
				value = value + pow(-1, i) * pow(x, 2 * i) / factorial(2 * i);
			break;
		}
		case 3:
		{
			for (int i = 0; i < n; i++)
				value = value + pow(x, i) / factorial(i);
			break;
		}
		}
		return value;
	}
	double Fault()
	{
		switch (NFunction)
		{
		case 1:
		{
			return abs(sin(x) - (*this).ValueSeries());
		}
		case 2:
		{
			return abs(cos(x) - (*this).ValueSeries());
		}
		case 3:
		{
			return abs(exp(x) - (*this).ValueSeries());
		}
		}
	}
};
void FormulaMember(TeilorFormuls& fun)
{
	switch (fun.NFunction)
	{
	case 1:
	{
		cout << "sin(x) = ";
		for (int i = 0; i < fun.n; i = i++)
		{
			if (i % 2 == 0)
				cout << " + ";
			else
				cout << " - ";
			cout << "x^" << 2 * i + 1 << "/" << 2 * i + 1 << "!";
		}
		cout << endl;
		break;
	}
	case 2:
	{
		cout << "cos(x) = ";
		for (int i = 0; i < fun.n; i++)
		{
			if (i % 2 == 0)
				cout << " + ";
			else
				cout << " - ";
			cout << "x^" << 2 * i << "/" << 2 * i << "!";
		}
		cout << endl;
		break;
	}
	case 3:
	{
		cout << "exp(x) = ";
		for (int i = 0; i < fun.n; i++)
		{
			cout << " + x^" << i << "/" << i << "!";
		}
		cout << endl;
		break;
		break;
	}
	default:
	{
		cout << "Invalid input" << endl;
	}
	}
}
int main()
{
	int a, b, c, d;
	int check = 0;
	double x0;
	TeilorFormuls f1(1, 1, 7), f2(2, 3, 5), f3;
	f1 = f2;
	cout << "Please select a function:\n1) sin(x)\n2) cos(x)\n3) exp(x)\n" << endl;
	cin >> a;
	while (check == 0)
	{
		try
		{
			f3.SetFunction(a);
			cout << "\nPlease set the calculation point:";
			cin >> x0;
			f3.SetX(x0);
			cout << "\nPlease enter the number of row members:";
			cin >> b;
			f3.SetMemberSeries(b);
		}
		catch (...)
		{
			cout << "The object is damaged." << endl;
			return 1;
		}
		cout << "\n Please select next step:\n 1) Find out the function\n 2) Find out the quantity of rows\n 3) Find out the calculation point\n 4) Derive the formula of the row\n 5) Find out the value of a specific member of the row\n 6) Find out the value of the row at the selected point\n 7) Calculate the deviation from the reference value\n 8) Exit" << endl;
		cin >> c;
		switch (c)
		{
		case 1:
		{
			if (f3.DiscoverFunction() == 1)
				cout << "Current function: sin(x)\n" << endl;
			if (f3.DiscoverFunction() == 2)
				cout << "Current function: cos(x)\n" << endl;
			if (f3.DiscoverFunction() == 3)
				cout << "Current function: exp(x)\n" << endl;
			break;
		}
		case 2:
		{
			cout << "Quantity of rows:\n" << f3.DiscoverMemberSeries() << endl;
			break;
		}
		case 3:
		{
			cout << "The calculation point:\n" << f3.DiscoverX() << endl;
			break;
		}
		case 4:
		{
			cout << "\n Formula of the row:\n" << endl;
			FormulaMember(f3);
			break;
		}
		case 5:
		{
			cout << "\n Please enter the member of the row to be calculated:";
			cin >> d;
			cout << "Value of the row in this number: " << d << " at the point " << f3.DiscoverX() << " = " << f3.ValueMember(d) << endl;
			break;
		}
		case 6:
		{
			cout << "\n Value of the row of a given function at the point " << f3.DiscoverX() << " = " << f3.ValueSeries() << endl;
			break;
		}
		case 7:
		{
			cout << "Deviation from the reference value: " << f3.Fault() << endl;
			break;
		}
		case 8:
		{
			check = 1;
			break;
		}
		default:
		{
			cout << "Invalid input" << endl;
		}
		}
	}
	system("pause");
}