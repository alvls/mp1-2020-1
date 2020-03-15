#include <iostream>
#include <math.h>
using namespace std;
class TaylorSeries
{
private:
	double PointX;
	int N;
	int FunctionNumber;
public:
	TaylorSeries(double _x = 0, int _num = 0, int _function = 0)
	{
		PointX = _x;
		N = _num;
		FunctionNumber = _function;
	}
	~TaylorSeries()
	{
		cout << "DELETE" << endl;
	}

	void SetFunctionNumber(int _functionNumber)
	{
		FunctionNumber = _functionNumber;
	}
	int GetFunctionNumber()
	{
		return FunctionNumber;
	}

	void SetNumberOfElements(int _number)
	{
		N = _number;
	}
	int GetNumberOfElements()
	{
		return N;
	}

	void SetArgument(double _argument)
	{
		PointX = _argument;
	}

	double CalculateCurrentElement()
	{
		switch (GetFunctionNumber())
		{
		case 3:
		{
			double u = 1.0;
			double i = 0.0;
			int num = GetNumberOfElements();
			if (num == 1)
				return 1.0;
			else
			{
				i = pow(PointX, num);
				for (int j = 1; j <= num; j++)
					u *= j;
				return (i / u);
			}
			break;
		}
		case 2:
		{
			double u = 1.0;
			double i = 0.0;
			int num = GetNumberOfElements();
			if (num == 1)
				return PointX;
			else
			{
				i = pow(-1, (2 * num - 1)) * pow(PointX, (2 * num - 1));
				for (int j = 1; j <= (2 * num - 1); j++)
					u *= j;
				return (i / u);
				break;
			}
		}
		case 1:
		{
			double u = 1.0;
			double i = 0.0;
			int num = GetNumberOfElements();
			if (num == 1)
				return 1.0;
			else
			{
				i = pow(-1, num) * pow(PointX, 2 * num);
				for (int j = 1; j <= (2 * num); j++)
					u *= j;
				return (i / u);
			}
			break;
		}
		default:
			return 0;
		}
	};

	double CalculateSeries()
	{
		double sum, g;
		switch (FunctionNumber)
		{
		case 1:
		{
			g = 1.0;
			sum = 0.0;
			for (int i = 1; i <= N; i++)
			{
				sum += g;
				g *= -1.0 * PointX * PointX / ((2 * i - 1) * (2 * i));
			}
			return sum;
		}
		case 2:
		{
			g = PointX;
			sum = 0.0;
			for (int i = 1; i <= N; i++)
			{
				sum += g;
				g *= -1.0 * PointX * PointX / ((2 * i) * (2 * i + 1));
			}
			return sum;
		}
		case 3:
		{
			g = 1.0;
			sum = 1.0;
			for (int i = 1; i <= N; i++)
			{
				g *= (PointX / i);
				sum += g;
			}
			return sum;
		}

		default:
			return 0;
		}
	}

	double GetAccuracyOfSeries()
	{
		double sum, g;
		switch (FunctionNumber)
		{
		case 1:
		{
			g = 1.0;
			sum = 0.0;
			for (int i = 1; i <= N; i++)
			{
				sum += g;
				g *= -1.0 * PointX * PointX / ((2 * i - 1) * (2 * i));
			}
			return abs(sum - cos(PointX));
		}
		case 2:
		{
			g = PointX;
			sum = 0.0;
			for (int i = 1; i <= N; i++)
			{
				sum += g;
				g *= -1.0 * PointX * PointX / ((2 * i) * (2 * i + 1));
			}
			return abs(sum - sin(PointX));
		}
		case 3:
		{
			g = 1.0;
			sum = 1.0;
			for (int i = 1; i <= N; i++)
			{
				g *= (PointX / i);
				sum += g;
			}
			return abs(sum - exp(PointX));
		}
		default:
			return 0;
		}
	}

	void PrintSeries()
	{
		switch (FunctionNumber)
		{
		case 1:
		{
			cout << "1";
			for (int i = 2; i <= N; i++)
			{
				if (i % 2 == 1)
					cout << "+";
				else
					cout << "-";
				cout << "x^(" << (2 * i - 2) << ")/" << (2 * i - 2) << "!";
			}
			break;
		}
		case 2:
		{
			cout << "x";
			for (int i = 2; i <= N; i++)
			{
				if (i % 2 == 1)
					cout << "+";
				else
					cout << "-";
				cout << "x^(" << (2 * i - 1) << ")/" << (2 * i - 1) << "!";
			}
			break;
		}
		case 3:
		{
			cout << "1";
			for (int i = 1; i < N; i++)
				cout << "+x^(" << i << ")/" << i << "!";
			break;
		}
		}
	}
};
int main()
{
	int FunctionNumber = 0;
	double _x;
	int _n;
	int Exist = 1;
	int Choice;
	TaylorSeries T;
	while (Exist == 1)
	{
		cout << "1) Set function" << endl;
		cout << "2) Get function" << endl;
		cout << "3) Set number of elements" << endl;
		cout << "4) Get number of elements" << endl;
		cout << "5) Get formula of series" << endl;
		cout << "6) Calculate the value of series" << endl;
		cout << "7) Calculate the value of current element" << endl;
		cout << "8) Calculate accuracy of the series" << endl;
		cout << "9) Exit" << endl;
		cin >> Choice;
		system("cls");
		switch (Choice)
		{
		case 1:
		{
			int Function;
			cout << "Choose function" << endl;
			cout << "1) cos(x)" << endl;
			cout << "2) sin(x)" << endl;
			cout << "3) exp" << endl;
			cin >> Function;
			T.SetFunctionNumber(Function);
			system("cls");
			break;
		}
		case 2:
		{
			switch (T.GetFunctionNumber())
			{
			case 1:
			{
				cout << "cos(x)" << endl;
				break;
			}
			case 2:
			{
				cout << "sin(x)" << endl;
				break;
			}
			case 3:
			{
				cout << "exp" << endl;
				break;
			}
			}
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			cout << "Enter number of elements: ";
			cin >> _n;
			T.SetNumberOfElements(_n);
			system("cls");
			break;
		}
		case 4:
		{
			cout << T.GetNumberOfElements() << endl;
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			T.PrintSeries();
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			cout << "Enter argument x: ";
			cin >> _x;
			T.SetArgument(_x);
			cout << T.CalculateSeries() << endl;
			system("pause");
			system("cls");
			break;
		}
		case 7:
		{
			cout << T.CalculateCurrentElement() << endl;
			system("pause");
			system("cls");
			break;
		}
		case 8:
		{
			cout << T.GetAccuracyOfSeries() << endl;
			system("pause");
			system("cls");
			break;
		}
		case 9:
		{
			Exist = 0;
			break;
		}
		}
	}
}