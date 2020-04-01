#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Pedometer
{
private:
	vector<int> days, months, years, hours_1, minutes_1, hours_2, minutes_2, steps;
	vector<string> weekdays;
	int firstday, firstmonth, firstyear, records;
public:
	Pedometer()
	{
		firstday = firstmonth = firstyear = 0;
	}
	Pedometer(const Pedometer& other)
	{
		firstday = other.firstday;
		firstmonth = other.firstmonth;
		firstyear = other.firstyear;
		records = other.records;
		for (int i = 0; i < records; i++)
		{
			days.push_back(other.days[i]);
			months.push_back(other.months[i]);
			years.push_back(other.years[i]);
			steps.push_back(other.steps[i]);
			hours_1.push_back(other.hours_1[i]);
			minutes_1.push_back(other.minutes_1[i]);
			hours_2.push_back(other.hours_2[i]);
			minutes_2.push_back(other.minutes_2[i]);
			weekdays.push_back(other.weekdays[i]);
		}
	}
	void SetFirstDate(int dayX, int monthX, int yearX)
	{
		firstday = dayX;
		firstmonth = monthX;
		firstyear = yearX;
	}
	int GetFirstDay()
	{
		return firstday;
	}
	int GetFirstMonth()
	{
		return firstmonth;
	}
	int GetFirstYear()
	{
		return firstyear;
	}
	void Push_back(int step, int day, int month, int year, string weekday, int hour_1, int minute_1, int hour_2, int minute_2)
	{
		steps.push_back(step);
		days.push_back(day);
		months.push_back(month);
		years.push_back(year);
		weekdays.push_back(weekday);
		hours_1.push_back(hour_1);
		minutes_1.push_back(minute_1);
		hours_2.push_back(hour_2);
		minutes_2.push_back(minute_2);
		records++;
	}
	int** GetInfo(int step)
	{
		int counter = 0;
		for (int i = 0; i < records; i++)
		{
			if (steps[i] == step)
				counter++;
		}
		int** res = new int* [counter];
		counter = 0;
		for (int i = 0; i < records; i++)
		{
			if (steps[i] == step)
			{
				res[counter] = new int[8];
				res[counter][0] = days[i];
				res[counter][1] = months[i];
				res[counter][2] = years[i];
				res[counter][3] = hours_1[i];
				res[counter][4] = minutes_1[i];
				res[counter][5] = hours_2[i];
				res[counter][6] = minutes_2[i];
				res[counter][7] = steps[i];
				counter++;
			}
		}
		return res;
	}
	int GetCounter(int step)
	{
		int counter = 0;
		for (int i = 0; i < records; i++)
		{
			if (steps[i] == step)
				counter++;
		}
		return counter;
	}
	int GetAverage()
	{
		int sum = 0;
		for (int j = 0; j < records; j++)
			sum = sum + steps[j];
		if (records == 0) return -1;
		return sum / records;
	}
	int GetAverageMonth(int month)
	{
		int sum = 0;
		int k = 0;
		for (int j = 0; j < records; j++)
		{
			if (month == months[j])
			{
				sum = sum + steps[j];
				k++;
			}
		}
		if (k == 0) return -1;
		return sum / k;
	}
	int GetAverageWeekDay(string weekday)
	{
		int sum = 0;
		int k = 0;
		int j = 0;
		for (j = 0; j < records; j++)
		{
			if (weekday == weekdays[j])
			{
				sum = sum + steps[j];
				k++;
			}
		}
		if (k == 0) return -1;
		return sum / k;
	}
	int* GetMaxMonth(int month)
	{
		int max = 0;
		int j = 0;
		int index_max = 0;
		for (j = 0; j < records; j++)
		{
			if (month == months[j] && steps[j] > max)
			{
				max = steps[j];
				index_max = j;
			}
		}
		int* res = new int[4];
		res[0] = max;
		res[1] = days[index_max];
		res[2] = months[index_max];
		res[3] = years[index_max];
		return res;
	}
	int* GetMaxAll()
	{
		int max = 0;
		int j = 0;
		int index_max = 0;
		for (j = 0; j < records; j++)
		{
			if (steps[j] > max)
			{
				max = steps[j];
				index_max = j;
			}
		}
		int* res = new int[4];
		res[0] = max;
		res[1] = days[index_max];
		res[2] = months[index_max];
		res[3] = years[index_max];
		return res;
	}

	void SaveStepsHistory(string path)
	{
		ofstream out;
		out.open(path);
		if (out.is_open())
		{
			for (int i = 0; i < records-1; i++)
				out << days[i] << " " << months[i] << " " << years[i] << " " << weekdays[i] << " " << hours_1[i] << " " << minutes_1[i] << " " << hours_2[i] << " " << minutes_2[i] << " " << steps[i] << std::endl;
			out << days[records - 1] << " " << months[records - 1] << " " << years[records - 1] << " " << weekdays[records - 1] << " " << hours_1[records - 1] << " " << minutes_1[records - 1] << " " << hours_2[records - 1] << " " << minutes_2[records - 1] << " " << steps[records - 1];
		}

		else cout << "Error: file was not opened!" << endl;
	}

	void ReadStepsHistory(string path)
	{
		fstream myfile(path, std::ios_base::in);
		string data;
		int data_counter = 0;
		int record_counter = 0;
		while (myfile >> data)
		{
			data_counter++;
			switch (data_counter)
			{
			case 1:
				days.push_back(stoi(data));
				break;
			case 2:
				months.push_back(stoi(data));
				break;
			case 3:
				years.push_back(stoi(data));
				break;
			case 4:
				weekdays.push_back(data);
				break;
			case 5:
				hours_1.push_back(stoi(data));
				break;
			case 6:
				minutes_1.push_back(stoi(data));
				break;
			case 7:
				hours_2.push_back(stoi(data));
				break;
			case 8:
				minutes_2.push_back(stoi(data));
			case 9:
				steps.push_back(stoi(data));
				data_counter = 0;
				record_counter++;
				break;
			}
		}
		myfile.close();
	}
};
int main()
{
	Pedometer pedometer;
	int day, month, year, variable, hour1, hour2, minute1, minute2, step, * arr, ** arrr, x, i;
	string weekday, path;
	while (true)
	{
		cout << "What is needed?" << endl;
		cout << "1. Set first date" << endl;
		cout << "2. Get first date" << endl;
		cout << "3. Set record " << endl;
		cout << "4. Get the information about entered number of steps" << endl;
		cout << "5. Get average number of steps in entered month" << endl;
		cout << "6. Get average number of steps" << endl;
		cout << "7. Get average number of steps in entered day of week" << endl;
		cout << "8. Get max number of steps in entered month and its date" << endl;
		cout << "9. Get max number of steps and its date" << endl;
		cout << "10. Save steps history" << endl;
		cout << "11. Read steps history" << endl;
		cout << "12. Exit" << endl;
		cin >> variable;
		switch (variable)
		{
		case 1:
			cout << "Enter first day, month, year (dd mm yy): ";
			cin >> day >> month >> year;
			pedometer.SetFirstDate(day, month, year);
			break;
		case 2:
			day = pedometer.GetFirstDay();
			month = pedometer.GetFirstMonth();
			year = pedometer.GetFirstMonth();
			cout << "First date is " << day << "." << month << "." << year << ", ";
			break;
		case 3:
			cout << "Enter date(dd mm yy): ";
			cin >> day >> month >> year;
			cout << "Enter day of week: ";
			cin >> weekday;
			cout << "Enter time of start(hh mm): ";
			cin >> hour1 >> minute1;
			cout << "Enter time of finish(hh mm): ";
			cin >> hour2 >> minute2;
			cout << "Enter number of steps: ";
			cin >> step;
			pedometer.Push_back(step, day, month, year, weekday, hour1, minute1, hour2, minute2);
			cout << "Recorded! ";
			break;
		case 4:
			cout << "Enter number of steps: ";
			cin >> step;
			x = pedometer.GetCounter(step);
			arrr = pedometer.GetInfo(step);
			cout << "Info: ";
			for (i = 0; i < x; i++)
			{
				cout << arrr[i][0] << ".";
				cout << arrr[i][1] << ".";
				cout << arrr[i][2] << "; ";
				cout << arrr[i][3] << ":";
				cout << arrr[i][4] << "-";
				cout << arrr[i][5] << ":";
				cout << arrr[i][6] << "; ";
				cout << arrr[i][7] << " steps " << endl;
			}
			break;
		case 5:
			cout << "Enter month: ";
			cin >> month;
			step = pedometer.GetAverageMonth(month);
			if (step == -1) cout << "There is no average number of steps!";
			cout << "Average steps in entered month is " << step << ", ";
			break;
		case 6:
			step = pedometer.GetAverage();
			if (step == -1) cout << "There is no average number of steps!";
			cout << "Average number of steps is " << step << ", ";
			break;
		case 7:
			cout << "Enter day of the week: ";
			cin >> weekday;
			step = pedometer.GetAverageWeekDay(weekday);
			if (step == -1) cout << "There is no average number of steps!";
			cout << "Average number of steps on this weekday is " << step << ", ";
			break;
		case 8:
			cout << "Enter month: ";
			cin >> month;
			arr = pedometer.GetMaxMonth(month);
			cout << "Max numberof steps in " << month << " month is" << arr[0] << ", date is ";
			cout << arr[1] << ".";
			cout << arr[2] << ".";
			cout << arr[3] << ", ";
			break;
		case 9:
			arr = pedometer.GetMaxAll();
			cout << "Max number of steps is " << arr[0] << ", date is ";
			cout << arr[1] << ".";
			cout << arr[2] << ".";
			cout << arr[3] << ", ";
			break;
		case 10:
			cout << "Enter the path: ";
			cin >> path;
			pedometer.SaveStepsHistory(path);
			break;
		case 11:
			cout << "Enter the path: ";
			cin >> path;
			pedometer.ReadStepsHistory(path);
			break;
		case 12:
			return 0;
			break;
		}
	}
}