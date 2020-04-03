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

istream& operator>>(istream& in, Date& date)
{
	char c;
	in >> date.year;
	in >> c;
	if (c == '-')
	{
		in >> date.month;
		in >> c;
		if (c == '-') in >> date.day;
		else cout << "Wrong date format, excepted '-' after month, variable is not complete\n";
	}
	else cout << "Wrong date format, excepted '-' after years, variable is not complete\n";
	return in;
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

	string GetName()
	{
		return name;
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

	pair<Date, double> operator [] (size_t index)
	{
		return pair<Date, double>(date[index], weight[index]);
	}

	~Scale()
	{
		delete[] weight;
		delete[] date;
	}

};

class Libra
{
	vector <Scale> family;
	Date beginingdate;
public:
	void Setbeginingdate(const Date& date)
	{
		beginingdate = date;
	}
	Date Getbeginingdate()
	{
		return beginingdate;
	}
	void Setscale(string& name, Date& date, double weight)
	{
		for (size_t i = 0; i < family.size(); i++)
		{
			if (family[i].GetName() == name)
			{
				family[i].SetData(date, weight);
				return;
			}
		}
		family.push_back(Scale(name));
		family[family.size() - 1].SetData(date, weight);
	}
	double Getscaleweight(string name, Date& date)
	{
		for (size_t i = 0; i < family.size(); i++)
		{
			if (family[i].GetName() == name)
			{
				return family[i].GetWeight(date);
			}
		}
		return -1;
	}

	pair<Date, double> GetMinWeight(string& name, int month, int year)
	{
		for (size_t i = 0; i < family.size(); i++)
		{
			if (family[i].GetName() == name)
			{
				return family[i].MinWeight(month, year);
			}
		}
		throw "A person with that name is not in Libra's memory";
	}

	double AverageWeight(string& name, int month, int year)
	{
		for (size_t i = 0; i < family.size(); i++)
		{
			if (family[i].GetName() == name)
			{
				return family[i].AverageWeight(month, year);
			}
		}
		throw "A person with that name is not in Libra's memory";
	}

	pair<Date, double> MaxWeight(string& name, int month, int year)
	{
		for (size_t i = 0; i < family.size(); i++)
		{
			if (family[i].GetName() == name)
			{
				return family[i].MaxWeight(month, year);
			}
		}
		throw "A person with that name is not in Libra's memory";
	}
	//...
	//Среднее значение, максимум, проверить работу с файлом


	//Name1
	//date11 45
	//date12 65
	//Name2
	//...
	void SaveInFile(const string& path)
	{
		std::fstream file;
		file.open(path, std::fstream::out);
		if (!file.is_open())
		{
			std::cout << "File not open!" << std::endl;
		}
		else
		{
			for (size_t i = 0; i < family.size() - 1; i++)
			{
				file << family[i].GetName() << endl;
				int size = family[i].GetSize();
				file << size << endl;
				for (int j = 0; j < size; j++)
				{
					pair<Date, double> curScale = family[i][j];
					file << curScale.first << " " << curScale.second << endl;
				}
			}
			file << family[family.size() - 1].GetName() << endl;
			int size = family[family.size() - 1].GetSize();
			file << size << endl;
			for (int j = 0; j < size - 1; j++)
			{
				pair<Date, double> curScale = family[family.size() - 1][j];
				file << curScale.first << " " << curScale.second << endl;
			}
			pair<Date, double> curScale = family[family.size() - 1][size - 1];
			file << curScale.first << " " << curScale.second;
			std::cout << "Saving succeed!" << std::endl;
		}
		file.close();


	}

	void LoadFromFile(const string& path)
	{
		std::fstream file;
		file.open(path, std::fstream::in);
		if (!file.is_open())
		{
			std::cout << "File not open!" << std::endl;
		}
		else
		{
			family.clear();
			while (!file.eof())
			{
				int index = family.size();
				string name;
				int size;
				file >> name;
				file >> size;
				family.push_back(Scale(name));
				for (int i = 0; i < size; i++)
				{
					Date date;
					double weight;
					file >> date >> weight;
					family[index].SetData(date, weight);
				}
			}
		}
		file.close();
	}

	Scale& operator [](size_t index)
	{
		return family[index];
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
	Libra libra;
menu2:
	cout << "\n1) Add a family member" << endl;
	cout << "2) Select a family member" << endl;
	cout << "3) Set the start date of observations" << endl;
	cout << "4) Find out the start date of observations" << endl;
	cout << "5) Set an observation" << endl;
	cout << "6) Find out the weight in the selected observation" << endl;
	cout << "7) Find the average weight of a family member" << endl;
	cout << "8) Find the minimum weight of a family member" << endl;
	cout << "9) Find the maximum weight of a family member" << endl;
	cout << "10) Save the observation history to a file" << endl;
	cout << "11) Read the observation history from a file" << endl;
	cout << "12) Clear the console" << endl;
	cout << "13) Exit" << endl << endl;
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
				if (libra[i].CheckName(name))
				{
					cout << "This name already exists" << endl << endl;
					goto menu;
				}
			}
			libra[family].ChangeName(name);
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
				if (libra[i].CheckName(name))
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
			libra[k].SetData(date, weight);
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
			if (libra[k].GetSize())
				libra[k].KnowStartData();
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
			if (libra[k].SetData(date, weight))
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
			if (libra[k].GetSize())
			{
				cout << "Please, enter the day: ";
				cin >> date.day;
				cout << "Please, enter the month number: ";
				cin >> date.month;
				cout << "Please, enter the year: ";
				cin >> date.year;
				if (libra[k].GetWeight(date))
					cout << "Weight value: " << libra[k].GetWeight(date) << endl;
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
			if (libra[k].GetSize())
			{
				cout << "\n1) For the entire history of observations" << endl;
				cout << "\n2) In the selected month" << endl;
				cin >> a;
				switch (a)
				{
				case 1:
				{
					cout << "Average Weight: " << libra[k].AverageWeight() << endl;
					break;
				}

				case 2:
				{
					cout << "Please, enter the month number: ";
					cin >> month;
					cout << "Please, enter the year: ";
					cin >> year;
					if (libra[k].AverageWeight(month, year))
						cout << "Average Weight: " << libra[k].AverageWeight(month, year) << endl;
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
			if (libra[k].GetSize())
			{
				cout << "\n1) For the entire history of observations" << endl;
				cout << "\n2) In the selected month" << endl;
				cin >> a;
				switch (a)
				{
				case 1:
				{
					cout << "Minimum weight: " << libra[k].MinWeight().first << "Date: " << libra[k].MinWeight().second << endl;
					break;
				}

				case 2:
				{
					cout << "Please, enter the month number: ";
					cin >> month;
					cout << "Please, enter the year: ";
					cin >> year;
					if (libra[k].AverageWeight(month, year))
					{
						cout << "Minimum weight: " << libra[k].MinWeight().first << "Date: " << libra[k].MinWeight().second << endl;

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
			if (libra[k].GetSize())
			{
				cout << "\n1) For the entire history of observations" << endl;
				cout << "\n2) In the selected month" << endl;
				cin >> a;
				switch (a)
				{
				case 1:
				{
					cout << "Maximum weight: " << libra[k].MaxWeight().first << "Date: " << libra[k].MinWeight().second << endl;
					break;
				}

				case 2:
				{
					cout << "Please, enter the month number: ";
					cin >> month;
					cout << "Please, enter the year: ";
					cin >> year;
					if (libra[k].AverageWeight(month, year))
					{
						cout << "Maximum weight: " << libra[k].MaxWeight().first << "Date: " << libra[k].MinWeight().second << endl;
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
			libra.SaveInFile("scale.txt");
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
			libra.LoadFromFile("scale.txt");
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