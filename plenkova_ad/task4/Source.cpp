#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct Date
{
	int Day;
	int Month;
	int Year;
	Date(int _year = 0, int _month = 0, int _day = 0) : Year(_year), Month(_month), Day(_day) {};
	Date& operator=(const Date& d)
	{
		Day = d.Day;
		Month = d.Month;
		Year = d.Year;
		return *this;
	}

	friend ostream& operator<<(ostream& os, const Date& obj);
};
Date WeightStartDate;

ostream& operator<<(ostream& os, const Date& obj)
{
	os << obj.Day << '.' << obj.Month << '.' << obj.Year;
	return os;
}

struct Weight
{
	Date TheDate;
	double TheWeight;
	Weight(Date _date, double _weight) :TheDate(_date), TheWeight(_weight) {};

	Weight& operator=(const Weight& n)
	{
		TheDate = n.TheDate;
		TheWeight = n.TheWeight;
		return *this;
	}

	friend ostream& operator<<(ostream& os, Weight& obj);
};

ostream& operator<<(ostream& os, Weight& obj)
{
	os << obj.TheDate.Day << '.' << obj.TheDate.Month << '.' << obj.TheDate.Year;
	os << ' ' << obj.TheWeight << '\n ' << endl;
	return os;
}

struct Person
{
	string Name;
	vector <Weight> PersonNumber;
	Person(string _name)
	{
		Name = _name;
	};

	Person(string _name, vector <Weight> n)
	{
		Name = _name;
		PersonNumber = n;
	};

	Person& operator=(const Person& n)
	{
		PersonNumber = n.PersonNumber;
		Name = n.Name;
		return *this;
	}

	int Search(int _day, int _month, int _year)
	{
		for (unsigned int j = 0; j < PersonNumber.size(); j++)
		{
			if (PersonNumber[j].TheDate.Day == _day && PersonNumber[j].TheDate.Month == _month && PersonNumber[j].TheDate.Year == _year)
			{
				return j;
			}
		}
		return -1;
	}

	void Observation(int _day, int _month, int _year, double _weight)
	{
		if (Search(_day, _month, _year) == -1)
		{
			Date d(_day, _month, _year);
			Weight w(d, _weight);
			PersonNumber.push_back(w);
		}
		else
		{
			PersonNumber[Search(_day, _month, _year)].TheWeight = _weight;
		}

	}

	friend ostream& operator<<(ostream& os, Person& obj);
};

ostream& operator<<(ostream& os, Person& obj)
{
	os << obj.Name << "\t" << endl;
	for (unsigned int i = 0; i < obj.PersonNumber.size(); i++)
	{
		os << obj.PersonNumber[i] << endl;
	}
	return os;
}

class Scales
{
	vector <Person> TheScale;
public:
	Scales() {};
	Scales(vector <Person> cl)
	{
		TheScale = cl;
	}

	~Scales() {};

	void SetWeight(int _day, int _month, int _year, double _weight, string _name)
	{
		for (unsigned int i = 0; i < TheScale.size(); i++)
		{
			if (TheScale[i].Name == _name)
				TheScale[i].Observation(_day, _month, _year, _weight);
		}
	}

	void SetStartDate(int _day, int _month, int _year)
	{
		WeightStartDate.Day = _day;
		WeightStartDate.Month = _month;
		WeightStartDate.Year = _year;
	};

	Date GetStartDate()
	{
		return WeightStartDate;
	};

	double GetWeight(int _day, int _month, int _year, string _name)
	{
		if (TheScale.size() > 0)
		{
			for (unsigned int i = 0; i < TheScale.size(); i++)
			{
				if (TheScale[i].Name == _name)
				{
					return TheScale[i].PersonNumber[TheScale[i].Search(_day, _month, _year)].TheWeight;
				}
			}
		}
		else
			return 0;
	};

	void AddName(string name)
	{
		Person p(name);
		TheScale.push_back(p);
	};

	double AvgWeightAllTime(string _name)
	{
		double avg = 0;
		int count = 0;
		for (unsigned int i = 0; i < TheScale.size(); i++)
		{
			if (TheScale[i].Name == _name)
			{
				for (unsigned int j = 0; j < TheScale[i].PersonNumber.size(); j++)
				{
					avg += TheScale[i].PersonNumber[j].TheWeight;
					count++;
				}

			}
		}
		if (count == 0)
		{
			return 0;
		}
		else
			return avg / count;
	};
	double AvgWeightThisMonth(string _name, int _month, int _year)
	{
		double avg = 0;
		int count = 0;
		for (unsigned int i = 0; i < TheScale.size(); i++)
		{
			if (TheScale[i].Name == _name)
			{
				for (unsigned int j = 0; j < TheScale[i].PersonNumber.size(); j++)
				{
					if ((TheScale[i].PersonNumber[j].TheDate.Month == _month) && (TheScale[i].PersonNumber[j].TheDate.Year == _year))
					{
						avg += TheScale[i].PersonNumber[j].TheWeight;
						count++;
					}
				}
			}
		}
		if (count == 0)
		{
			return 0;
		}
		else
			return avg / count;
	};

	double MinWeightAllTime(string _name)
	{
		double min = 1000;
		for (unsigned int i = 0; i < TheScale.size(); i++)
		{
			if (TheScale[i].Name == _name)
			{
				for (unsigned int j = 0; j < TheScale[i].PersonNumber.size(); j++)
				{
					if (TheScale[i].PersonNumber[j].TheWeight < min)
						min = TheScale[i].PersonNumber[j].TheWeight;
				}
			}
		}
		return min;
	};
	double MinWeightThisMonth(string _name, int _month, int _year)
	{
		double min = 1000;
		for (unsigned int i = 0; i < TheScale.size(); i++)
		{
			if (TheScale[i].Name == _name)
			{
				for (unsigned int j = 0; j < TheScale[i].PersonNumber.size(); j++)
				{
					if ((TheScale[i].PersonNumber[j].TheDate.Month == _month) && (TheScale[i].PersonNumber[j].TheDate.Year == _year))
					{
						if (TheScale[i].PersonNumber[j].TheWeight < min)
							min = TheScale[i].PersonNumber[j].TheWeight;
					}
				}
			}
		}
		return min;
	};

	double MaxWeightAllTime(string _name)
	{
		double max = 0;
		for (unsigned int i = 0; i < TheScale.size(); i++)
		{
			if (TheScale[i].Name == _name)
			{
				for (unsigned int j = 0; j < TheScale[i].PersonNumber.size(); j++)
				{
					if (TheScale[i].PersonNumber[j].TheWeight > max)
						max = TheScale[i].PersonNumber[j].TheWeight;
				}
			}
		}
		return max;
	};
	double MaxWeightThisMonth(string _name, int _month, int _year)
	{
		double max = 0;
		for (unsigned int i = 0; i < TheScale.size(); i++)
		{
			if (TheScale[i].Name == _name)
			{
				for (unsigned int j = 0; j < TheScale[i].PersonNumber.size(); j++)
				{
					if ((TheScale[i].PersonNumber[j].TheDate.Month == _month) && (TheScale[i].PersonNumber[j].TheDate.Year == _year))
					{
						if (TheScale[i].PersonNumber[j].TheWeight > max)
							max = TheScale[i].PersonNumber[j].TheWeight;
					}
				}
			}
		}
		return max;
	};

	void InputFile()
	{
		ofstream file;
		file.open("Scales.txt");
		for (unsigned int i = 0; i < TheScale.size(); i++)
		{
			file << TheScale[i].Name << endl;
			for (unsigned int j = 0; j < TheScale[i].PersonNumber.size(); j++)
			{
				file << TheScale[i].PersonNumber[j] << endl;
			}
		}
		file.close();
	};

	void OutputFile()
	{
		ifstream file;
		char str[100];
		file.open("Scales.txt");
		for (unsigned int i = 0; i < TheScale.size(); i++)
		{
			file.getline(str, 40, '\t');
			TheScale[i].Name = atoi(str);
			for (unsigned int j = 0; j < TheScale[i].PersonNumber.size(); j++)
			{
				file.getline(str, 10, '.');
				TheScale[i].PersonNumber[j].TheDate.Day = atoi(str);
				file.getline(str, 10, '.');
				TheScale[i].PersonNumber[j].TheDate.Month = atoi(str);
				file.getline(str, 10, ' ');
				TheScale[i].PersonNumber[j].TheDate.Year = atoi(str);
				file.getline(str, 10, '\n');
				TheScale[i].PersonNumber[j].TheWeight = atoi(str);
			}
		}
		file.close();
	};
};

	
int main()
{
	Scales Scale;
	int day;
	int month;
	int year;
	double weight;
	int choice1, choice2;
	bool menu = 1;
	string name;
	while (menu != 0)
	{
		system("cls");
		cout << "1 - Add new person\n" << endl;
		cout << "2 - Set start date\n" << endl;
		cout << "3 - Get start date\n" << endl;
		cout << "4 - Set new notice\n" << endl;
		cout << "5 - Get weight from notice\n" << endl;
		cout << "6 - Average weight\n" << endl;
		cout << "7 - Min weight\n" << endl;
		cout << "8 - Max weight\n" << endl;
		cout << "9 - Save observation history to file\n" << endl;
		cout << "10 - Read observation history from file\n" << endl;
		cout << "11 - Exit\n" << endl;
		cin >> choice1;
		switch (choice1)
		{
		case 1:
		{
			cout << "Add name: ";
			cin >> name;
			Scale.AddName(name);
			break;
		}
		case 2:
		{
			cout << "Enter day: ";
			cin >> day;
			cout << "Enter month: ";
			cin >> month;
			cout << "Enter year: ";
			cin >> year;
			Scale.SetStartDate(day, month, year);
			break;
		}
		case 3:
		{
			cout << Scale.GetStartDate() << endl;
			system("pause");
			break;
		}
		case 4:
		{
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter day: ";
			cin >> day;
			cout << "Enter month: ";
			cin >> month;
			cout << "Enter year: ";
			cin >> year;
			cout << "Enter weight: ";
			cin >> weight;
			Scale.SetWeight(day, month, year, weight, name);
			break;
		}
		case 5:
		{
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter day: ";
			cin >> day;
			cout << "Enter month: ";
			cin >> month;
			cout << "Enter year: ";
			cin >> year;
			cout << Scale.GetWeight(day, month, year, name) << endl;
			system("pause");
			break;
		}
		case 6:
		{
			cout << "Enter name: " << endl;
			cin >> name;
			cout << "1 - all observation" << endl;
			cout << "2 - in chosen month" << endl;
			cin >> choice2;
			switch (choice2)
			{
			case 1:
			{
				cout << "Average Weight =" << Scale.AvgWeightAllTime(name) << endl;
				break;
			}
			case 2:
			{
				cout << "Enter month: ";
				cin >> month;
				cout << "Enter year: ";
				cin >> year;
				cout << "Average Weight =" << Scale.AvgWeightThisMonth(name, month, year) << endl;
				break;
			}
			}
			system("pause");
			break;
		}
		case 7:
		{
			cout << "Enter name: " << endl;
			cin >> name;
			cout << "1 - all observation" << endl;
			cout << "2 - in chosen month" << endl;
			cin >> choice2;
			switch (choice2)
			{
			case 1:
			{
				cout << "Min Weight =" << Scale.MinWeightAllTime(name) << endl;
				break;
			}
			case 2:
			{
				cout << "Enter month: ";
				cin >> month;
				cout << "Enter year: ";
				cin >> year;
				cout << "Min Weight =" << Scale.MinWeightThisMonth(name, month, year) << endl;
				break;
			}
			}
			system("pause");
			break;
		}
		case 8:
		{
			cout << "Enter name: " << endl;
			cin >> name;
			cout << "1 - all observation" << endl;
			cout << "2 - in chosen month" << endl;
			cin >> choice2;
			switch (choice2)
			{
			case 1:
			{
				cout << "Max Weight =" << Scale.MaxWeightAllTime(name) << endl;
				break;
			}
			case 2:
			{
				cout << "Enter month: ";
				cin >> month;
				cout << "Enter year: ";
				cin >> year;
				cout << "Max Weight =" << Scale.MaxWeightThisMonth(name, month, year) << endl;
				break;
			}
			}
			system("pause");
			break;
		}
		case 9:
		{
			Scale.InputFile();
			break;
		}
		case 10:
		{
			Scale.OutputFile();
			break;
		}
		case 11:
		{
			menu = 0;
			break;
		}
		}
	}
	return 0;
}
