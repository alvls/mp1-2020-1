#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <fstream> 
#include <string>
#include <vector>
using namespace std;

struct Date
{
	int day;
	int month;
	int year;

	Date& operator = (const Date& date)
	{
		this->day = date.day;
		this->month = date.month;
		this->year = date.year;
		return *this;
	}

	bool operator == (const Date& date) const
	{
		if (this->day == date.day && this->month == date.month && this->year == date.year)
			return true;
		else
			return false;
	}

	friend ostream& operator<<(ostream& os, const Date& date);
};

ofstream scale_in;
ifstream scale_out;

ostream& operator<<(ostream& os, const Date& date)
{
	os << date.day << '.' << date.month << '.' << date.year;
	return os;
}

class Scale
{
	Date* date;
	string name;
	double* weight;
	int size;
	int i_m;
public:
	Scale(string _name = "name")
	{
		name = _name;
		size = 0;
		date = nullptr;
		weight = nullptr;
	}

	Scale(const Scale& sc)//
	{
		size = sc.size;
		name = sc.name;
		date = new Date[size];
		weight = new double[size];
		for (int i = 0; i < size; i++)
		{
			date[i] = sc.date[i];
			weight[i] = sc.weight[i];
		}
	}

	Scale& operator=(const Scale& sc)//
	{
		if (this == &sc)
			return *this;
		else
		{
			delete[]date;
			delete[]weight;
			size = sc.size;
			name = sc.name;
			date = new Date[size];
			weight = new double[size];
			for (int i = 0; i < size; i++)
			{
				date[i] = sc.date[i];
				weight[i] = sc.weight[i];
			}
			return *this;
		}
	}

	void IncreaseSize()
	{
		Date* date_2;
		double* weight2;
		date_2 = new Date[size];
		weight2 = new double[size];
		for (int i = 0; i < size; i++)
		{
			date_2[i] = date[i];
			weight2[i] = weight[i];
		}
		delete[]date;
		delete[]weight;
		date = new Date[size + 1];
		weight = new double[size + 1];
		for (int i = 0; i < size; i++)
		{
			date[i] = date_2[i];
			weight[i] = weight2[i];
		}
		delete[]date_2;
		delete[]weight2;
		size++;
	}

	void KnowStartData() const//
	{
		cout << date[0].day << "." << date[0].month << "." << date[0].year << endl;
	}

	double GetWeight(Date _date_1)
	{
		for (int i = 0; i < size; i++)
		{
			if (date[i] == _date_1)
				return weight[i];
		}
		return 0;
	}

	bool CheckName(string _name) const//
	{
		if (name == _name)
			return true;
		else
			return false;
	}

	void ChangeName(string _name)
	{
		name = _name;
	}

	bool CheckData(Date _date_1) const
	{
		for (int i = 0; i < size; i++)
		{
			if (date[i] == _date_1)
				return true;
		}
		return false;
	}

	int GetSize()
	{
		return size;
	}

	bool SetData(Date _date_1, double _weight)
	{
		IncreaseSize();
		for (int i = 0; i < size - 1; i++)
		{
			if (date[i] == _date_1)
			{
				weight[i] = _weight;
				return true;
			}
		}
		date[size - 1] = _date_1;
		weight[size - 1] = _weight;
		return false;
	}

	double AverageWeight(int _month = 0, int _year = 0)
	{
		double av_weight = 0;
		int _size = 0;
		if ((_month == 0) && (_year == 0))
		{
			for (int i = 0; i < size; i++)
			{
				av_weight += weight[i];
			}
			return av_weight / size;
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				if ((date[i].month == _month) && (date[i].year == _year))
				{
					_size++;
					av_weight += weight[i];
				}
			}
			if (_size == 0)
				return 0;
			else
				return av_weight / _size;
		}
	}

	pair<Date, double> MinWeight(int _month = 0, int _year = 0)
	{
		double min_weight = 0;
		if ((_month == 0) && (_year == 0))
		{
			min_weight = weight[0];
			i_m = 0;
			for (int i = 0; i < size; i++)
			{
				if (weight[i] < min_weight)
				{
					min_weight = weight[i];
					i_m = i;
				}
			}
			return pair< Date, double>(Date(), min_weight);
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				if ((date[i].month == _month) && (date[i].year == _year))
				{
					min_weight = weight[i];
					break;
				}
			}
			if (min_weight == 0)
				throw;
			else
			{
				for (int i = 0; i < size; i++)
				{
					if ((date[i].month == _month) && (date[i].year == _year))
					{
						if (weight[i] < min_weight)
						{
							min_weight = weight[i];
							i_m = i;
						}
					}
				}
			}
			return pair< Date, double>(Date(), min_weight);
		}
	}

	pair<Date, double> MaxWeight(int _month = 0, int _year = 0)
	{
		double max_weight = 0;
		if ((_month == 0) && (_year == 0))
		{
			max_weight = weight[0];
			i_m = 0;
			for (int i = 0; i < size; i++)
			{
				if (weight[i] > max_weight)
				{
					max_weight = weight[i];
					i_m = i;
				}
			}
			return pair< Date, double>(Date(), max_weight);
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				if ((date[i].month == _month) && (date[i].year == _year))
				{
					max_weight = weight[i];
					break;
				}
			}
			if (max_weight == 0)
				throw;
			else
			{
				for (int i = 0; i < size; i++)
				{
					if ((date[i].month == _month) && (date[i].year == _year))
					{
						if (weight[i] > max_weight)
						{
							max_weight = weight[i];
							i_m = i;
						}
					}
				}
			}
			return pair< Date, double>(Date(), max_weight);
		}
	}

	void PrintDataMinMax() const
	{
		cout << date[i_m].day << "." << date[i_m].month << "." << date[i_m].year << endl;
	}

	void SaveInFile()
	{
		scale_in << name << endl;
		scale_in << "Number of observations: " << size << endl;
		for (int i = 0; i < size; i++)
		{
			scale_in << date[i] << endl << weight[i] << endl;
		}
	}

	void LoadFromFile()
	{
		char y[300];
		scale_out.getline(y, 100, '\n');
		name = y;
		scale_out.getline(y, 100, ' ');
		scale_out.getline(y, 100, ' ');
		scale_out.getline(y, 100, '\n');
		size = atoi(y);
		date = new Date[size];
		weight = new double[size];
		for (int i = 0; i < size; i++)
		{
			scale_out.getline(y, 100, '.');
			date[i].day = atoi(y);
			scale_out.getline(y, 100, '.');
			date[i].month = atoi(y);
			scale_out.getline(y, 100, '\n');
			date[i].year = atoi(y);
			scale_out.getline(y, 100, '\n');
			weight[i] = atoi(y);
		}
	}

	~Scale()
	{
		delete[] weight;
		delete[] date;
	}

};


int main()
{
	int x = 0;
	int a;
	Date date;
	double weight;
	int month;
	int year;
	string name;
	int family = 0;
	int k = 0;
	Scale scale[5];
menu2:
	cout << "\n1) Add a family member" << endl;
	cout << "\n2) Select a family member" << endl;
	cout << "\n3) Set the start date of observations" << endl;
	cout << "\n4) Find out the start date of observations" << endl;
	cout << "\n5) Set an observation" << endl;
	cout << "\n6) Find out the weight in the selected observation" << endl;
	cout << "\n7) Find the average weight of a family member" << endl;
	cout << "\n8) Find the minimum weight of a family member" << endl;
	cout << "\n9) Find the maximum weight of a family member" << endl;
	cout << "\n10) Save the observation history to a file" << endl;
	cout << "\n11) Read the observation history from a file" << endl;
	cout << "\n12) Clear the console" << endl;
	cout << "\n13) Exit" << endl << endl;
	while (x == 0)
	{
	menu:
		cout << "\nPlease, select menu item: ";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			if (family == 5)
			{
				cout << "Maximum of five family members" << endl << endl;
				goto menu;
			}
			cout << "Please, enter a name: ";
			cin >> name;
			for (int i = 0; i < 5; i++)
			{
				if (scale[i].CheckName(name))
				{
					cout << "This name already exists" << endl << endl;
					goto menu;
				}
			}
			scale[family].ChangeName(name);
			k = family;
			family++;
			cout << "Added" << endl << endl;
			break;
		}

		case 2:
		{
			if (family == 0)
			{
				cout << "You need to add a family member" << endl << endl;
				goto menu;
			}
			cout << "Please, enter a name: ";
			cin >> name;
			for (int i = 0; i < 5; i++)
			{
				if (scale[i].CheckName(name))
				{
					k = i;
					cout << "Selected" << endl << endl;
					goto menu;
				}
			}
			cout << "No such name was found" << endl << endl;
			break;
		}

		case 3:
		{
			if (family == 0)
			{
				cout << "You need to add a family member" << endl << endl;
				goto menu;
			}
			cout << "Please, enter the day: ";
			cin >> date.day;
			cout << "Please, enter the month number: ";
			cin >> date.month;
			cout << "Please, enter the year: ";
			cin >> date.year;
			cout << "Please, enter the weight value (kg): ";
			cin >> weight;
			scale[k].SetData(date, weight);
			cout << "Conserved" << endl << endl;
			break;
		}

		case 4:
		{
			if (family == 0)
			{
				cout << "You need to add a family member" << endl << endl;
				goto menu;
			}
			if (scale[k].GetSize())
				scale[k].KnowStartData();
			else
				cout << "The observation history is empty" << endl;
			cout << endl;
			break;
		}

		case 5:
		{
			if (family == 0)
			{
				cout << "You need to add a family member" << endl << endl;
				goto menu;
			}
			cout << "Please, enter the day: ";
			cin >> date.day;
			cout << "Please, enter the month number: ";
			cin >> date.month;
			cout << "Please, enter the year: ";
			cin >> date.year;
			cout << "Please, enter the weight value (kg): ";
			cin >> weight;
			if (scale[k].SetData(date, weight))
				cout << "Changed" << endl;
			else
				cout << "Conserved" << endl;
			cout << endl;
			break;
		}

		case 6:
		{
			if (family == 0)
			{
				cout << "You need to add a family member" << endl << endl;
				goto menu;
			}
			if (scale[k].GetSize())
			{
				cout << "Please, enter the day: ";
				cin >> date.day;
				cout << "Please, enter the month number: ";
				cin >> date.month;
				cout << "Please, enter the year: ";
				cin >> date.year;
				if (scale[k].GetWeight(date))
					cout << "Weight value: " << scale[k].GetWeight(date) << endl;
				else
					cout << "Observation is not found" << endl;
			}
			else
				cout << "The observation history is empty" << endl;
			cout << endl;
			break;
		}

		case 7:
		{
			if (family == 0)
			{
				cout << "You need to add a family member" << endl << endl;
				goto menu;
			}
			if (scale[k].GetSize())
			{
				cout << "\n1) For the entire history of observations" << endl;
				cout << "\n2) In the selected month" << endl;
				cin >> a;
				switch (a)
				{
				case 1:
				{
					cout << "Average Weight: " << scale[k].AverageWeight() << endl;
					break;
				}

				case 2:
				{
					cout << "Please, enter the month number: ";
					cin >> month;
					cout << "Please, enter the year: ";
					cin >> year;
					if (scale[k].AverageWeight(month, year))
						cout << "Average Weight: " << scale[k].AverageWeight(month, year) << endl;
					else
						cout << "There are no observations this month" << endl;
					break;
				}

				default:
				{
					cout << "Invalid input" << endl;
				}
				}
			}
			else
				cout << "The observation history is empty" << endl;
			cout << endl;
			break;
		}

		case 8:
		{
			if (family == 0)
			{
				cout << "You need to add a family member" << endl << endl;
				goto menu;
			}
			if (scale[k].GetSize())
			{
				cout << "\n1) For the entire history of observations" << endl;
				cout << "\n2) In the selected month" << endl;
				cin >> a;
				switch (a)
				{
				case 1:
				{
					cout << "Minimum weight: " << scale[k].MinWeight().first << "Date: " << scale[k].MinWeight().second << endl;
					break;
				}

				case 2:
				{
					cout << "Please, enter the month number: ";
					cin >> month;
					cout << "Please, enter the year: ";
					cin >> year;
					if (scale[k].AverageWeight(month, year))
					{
						cout << "Minimum weight: " << scale[k].MinWeight().first << "Date: " << scale[k].MinWeight().second << endl;

					}
					else
						cout << "There are no observations this month" << endl;
					break;
				}

				default:
				{
					cout << "Invalid input" << endl;
				}
				}
			}
			else
				cout << "The observation history is empty" << endl;
			cout << endl;
			break;
		}
		case 9:
		{
			if (family == 0)
			{
				cout << "You need to add a family member" << endl << endl;
				goto menu;
			}
			if (scale[k].GetSize())
			{
				cout << "\n1) For the entire history of observations" << endl;
				cout << "\n2) In the selected month" << endl;
				cin >> a;
				switch (a)
				{
				case 1:
				{
					cout << "Maximum weight: " << scale[k].MaxWeight().first << "Date: " << scale[k].MinWeight().second << endl;
					break;
				}

				case 2:
				{
					cout << "Please, enter the month number: ";
					cin >> month;
					cout << "Please, enter the year: ";
					cin >> year;
					if (scale[k].AverageWeight(month, year))
					{
						cout << "Maximum weight: " << scale[k].MaxWeight().first << "Date: " << scale[k].MinWeight().second << endl;
					}
					else
						cout << "There are no observations this month" << endl;
					break;
				}

				default:
				{
					cout << "Invalid input" << endl;
				}
				}
			}
			else
				cout << "The observation history is empty" << endl;
			cout << endl;
			break;
		}

		case 10:
		{
			scale_in.open("scale.txt");
			scale_in << "Number of family members: " << family << endl;
			for (int i = 0; i < family; i++)
			{
				scale[i].SaveInFile();
			}
			scale_in.close();
			break;
		}

		case 11:
		{
			char x[100];
			scale_out.open("scale.txt");
			scale_out.getline(x, 100, ' ');
			scale_out.getline(x, 100, ' ');
			scale_out.getline(x, 100, ' ');
			scale_out.getline(x, 100, '\n');
			family = atoi(x);
			for (int i = 0; i < family; i++)
			{
				scale[i].LoadFromFile();
			}
			scale_out.close();
			break;
		}

		case 12:
		{
			system("cls");
			goto menu2;
			break;
		}

		case 13:
		{
			exit(EXIT_SUCCESS);
			break;
		}

		default:
		{
			cout << "Invalid input" << endl;
		}
		}
	}

}