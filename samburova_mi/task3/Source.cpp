#include <iostream>
#include <math.h>
#include <fstream>

class Tabulator
{
private:
	int points, limit_1, limit_2;
	double *values;
	double (*func)(double x);
public:
	Tabulator()
	{
		func = 0;
		points = 0;
		limit_1 = 0;
		limit_2 = 0;
		values = new double[10];
	}
	Tabulator(const Tabulator& other)
	{
		func = other.func;
		points = other.points;
		limit_1 = other.limit_1;
		limit_2 = other.limit_2;
		values = new double[10];
		for (int i = 0; i < 9; i++)
			values[i] = other.values[i];
	}
	~Tabulator()
	{
		delete[] values;
	}
    void set_func(double (*function)(double))
	{
		func = function;
	}
	void set_points(int segments)
	{
		points = segments;
	}
	int set_limit_1(int edge_1)
	{
		limit_1 = edge_1;
		return limit_1;
	}
	int set_limit_2 (int edge_2)
	{
		limit_2 = edge_2;
		return limit_2;
	}
	void print_points()
	{
		std::cout << "Current number of tab points is " << points << std::endl;
	}
	void print_limits()
	{
		std::cout << "Current tab lenght is [" << limit_1 << "; " << limit_2 << "]" << std::endl;
	}
	void do_tab()
	{
		double step;
		step = ((limit_2 - limit_1) / points);
		for (int i = limit_1, j=0; i <= limit_2; i = i + step, j++)
		{
			values[j] = func(i);
		}
		values[points + 2] = func(limit_2);
	}
	void show_tab()
	{
		for (int x = 0; x < points+1; x++)
		{
			std::cout << values[x] << std::endl;
		}
		std::cout << func(limit_2) << std::endl;
	}
	void save_tab(std::string path)
	{ 

		std::ofstream out;
		out.open(path);
		if (out.is_open())
		{
			for (int i = 0; i < points + 1; i++)
				out << values[i] << std::endl;
			out << func(limit_2) << std::endl;
		}
		else
			std::cout << "Error: file was not opened" << std::endl;	
	}
};

int main()
{
	Tabulator Tabulator;
	int variable, var_func, segments, edge_1, edge_2;
	std::string file;

	while (true)
	{
		std::cout << "What is needed?" << std::endl
			<< "1)Set current function" << std::endl
			<< "2)Set current number of tab points" << std::endl
			<< "3)Get current number of tab points" << std::endl
			<< "4)Set distance of tabulation" << std::endl
			<< "5)Get distance of tabulation" << std::endl
			<< "6)Tabulate" << std::endl
			<< "7)Show results of tabulation" << std::endl
			<< "8)Save results of tabulation" << std::endl
			<< "9)Exit" << std::endl
			<< "~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::cin >> variable;
		std::cout << "~~~~~~~~~~~~~~~~~~~" << std::endl;
		switch (variable)
		{
		case 1:
			std::cout << "Choose function" << std::endl
				<< "1)abs" << std::endl
				<< "2)sqrt" << std::endl
				<< "3)sin" << std::endl
				<< "4)cos" << std::endl
				<< "5)tg" << std::endl
				<< "6)arcsin" << std::endl
				<< "7)arccos" << std::endl
				<< "8)arctg" << std::endl
				<< "9)log" << std::endl
				<< "10)lg" << std::endl
				<< "11)exp" << std::endl
				<< "~~~~~~~~~~~~~~~~~~~" << std::endl;
			std::cin >> var_func;
			switch (var_func)
			{
			case 1: Tabulator.set_func(abs); std::cout << "Your function is abs!" << std::endl; break;
			case 2: Tabulator.set_func(sqrt); std::cout << "Your function is sqrt!" << std::endl; break;
			case 3: Tabulator.set_func(sin); std::cout << "Your function is sin!" << std::endl; break;
			case 4: Tabulator.set_func(cos); std::cout << "Your function is cos!" << std::endl; break;
			case 5: Tabulator.set_func(tan); std::cout << "Your function is tan!" << std::endl; break;
			case 6: Tabulator.set_func(asin); std::cout << "Your function is asin!" << std::endl; break;
			case 7: Tabulator.set_func(acos); std::cout << "Your function is acos!" << std::endl; break;
			case 8: Tabulator.set_func(atan); std::cout << "Your function is atan!" << std::endl; break;
			case 9: Tabulator.set_func(log); std::cout << "Your function is log!" << std::endl; break;
			case 10:Tabulator.set_func(log10); std::cout << "Your function is log10!" << std::endl; break;
			case 11:Tabulator.set_func(exp); std::cout << "Your function is exp!" << std::endl; break;
			};
			break;
		case 2:
			std::cin >> segments;
			Tabulator.set_points(segments);
			break;
		case 3:
			Tabulator.print_points();
			break;
		case 4:
			std::cout << "Enter first limit: ";
			std::cin >> edge_1;
			Tabulator.set_limit_1(edge_1);
			std::cout << "Enter second limit: ";
			std::cin >> edge_2;
			Tabulator.set_limit_2(edge_2);
			break;
		case 5:
			Tabulator.print_limits();
			break;
		case 6:
			Tabulator.do_tab();
			std::cout << "Tabulated!" << std::endl;
			break;
		case 7:
			Tabulator.show_tab();
			break;
		case 8:
			std::cout << "Enter the path where you want to save the data (only english names!)" << std::endl;
			std::cin >> file;
			Tabulator.save_tab(file);
			std::cout << "Saved!" << std::endl;
			break;
		case 9:
			return 0;
		}
	}
} 