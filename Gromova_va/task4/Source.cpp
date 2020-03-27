#include <iostream>
#include <clocale> 
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
using namespace std;
class Thermometr
{
	int InitialYear;
	int InitialMonth;
	int InitialDay;
	int InitialHour;
	vector<int> Year;
	vector<int> Month;
	vector<int> Day;
	vector<int> Hour;
	vector<double> Temperature;
	int MaxDate[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
public:

	Thermometr()
	{
		InitialYear = 2000;
		InitialMonth = 1;
		InitialDay = 1;
		InitialHour = 0;
	}
	Thermometr ReadFile(string filename)
	{
		ifstream in(filename);
		Thermometr Therm;
		int i = 0;
		if (in.is_open())
		{
			int year;
			int month;
			int day;
			int hour;
			int temperature;
			while (!in.eof())
			{

				year = 0;
				month = 0;
				day = 0;
				hour = 0;
				temperature = 0;
				in >> year;
				in >> month;
				in >> day;
				in >> hour;
				in >> temperature;
				Year.push_back(year);
				Month.push_back(month);
				Day.push_back(day);
				Hour.push_back(hour);
				Temperature.push_back(temperature);
			}
			Year.pop_back();
			Month.pop_back();
			Day.pop_back();
			Hour.pop_back();
			Temperature.pop_back();
		}
		in.close();
		return Therm;
	}
	Thermometr(int year, int month, int day, int hour)
	{
		InitialYear = year;
		InitialMonth = month;
		InitialDay = day;
		InitialHour = hour;
	}
	void SetInitialDate(int year, int month, int day, int hour)
	{
		InitialYear = year;
		InitialMonth = month;
		InitialDay = day;
		InitialHour = hour;
	}
	void GetInitialDate(int &year, int &month, int &day, int &hour)
	{
		year = InitialYear;
		month = InitialMonth;
		day = InitialDay;
		hour = InitialHour;
	}
	void CheckData(int year, int month, int day, int hours)
	{
		if ((month < 0) || (month > 12))
		{
			throw "Неверно указана дата";
		}
		if ((day < 0) || (day > MaxDate[month - 1]))
		{
			throw "Неверно указана дата";
		}
	}
	bool SetObservation(int year, int month, int day, int hour, double temperature)
	{
		int i;
		for (i = 0; i < Temperature.size(); i++)
		{
			if ((year == Year[i]) && (month == Month[i]) && (day == Day[i]) && (hour == Hour[i]))
			{
				Temperature[i] = temperature;
				return 1;
			}
		}
		Year.push_back(year);
		Month.push_back(month);
		Day.push_back(day);
		Hour.push_back(hour);
		Temperature.push_back(temperature);
		return 0;
	}
	void SerialObservation(int year, int month, int day, double TempArr[])
	{
		for (int i = 0; i < 24; i++)
		{
			SetObservation(year, month, day, i, TempArr[i]);

		}
	}
	double GetTemperature(int year, int month, int day, int hour)//функция,которая получает температуру в заданный период
	{
		for (int i = 0; i < Temperature.size(); i++)
		{
			if (((year == Year[i]) && (month == Month[i]) && (day == Day[i]) && (hour == Hour[i])))
			{
				return Temperature[i];
			}
		}
		return -273.16;
	}
	double DailyAverageTemp(int year, int month, int day)
	{
		int n = 0;
		double Sum = 0;
		for (int i = 0; i < Temperature.size(); i++)
		{
			if ((year == Year[i]) && (month == Month[i]) && (day == Day[i]))
			{
				n++;
				Sum += Temperature[i];
			}
		}
		if (n == 0)
		{
			return -273.16;
		}
		Sum /= n;
		return Sum;
	}
	double MouthlyAverageTemp(int year, int month)
	{
		int n = 0;
		double Sum = 0;
		for (int i = 0; i < Temperature.size(); i++)
		{
			if ((year == Year[i]) && (month == Month[i]))
			{
				n++;
				Sum += Temperature[i];
			}
		}
		if (n == 0)
		{
			return -273.16;
		}
		Sum /= n;
		return Sum;
	}
	double AllTimeAverageTemp()
	{
		int n = 0;
		double Sum = 0;
		for (int i = 0; i < Temperature.size(); i++)
		{
			n++;
			Sum += Temperature[i];
		}
		if (n == 0)
		{
			return -273.16;
		}
		Sum /= n;
		return Sum;
	}
	double AverageDayTimeTemp(int year, int month)
	{
		int count = 0;
		double Sum = 0;
		for (int i = 0; i < Temperature.size(); i++)
			if ((year == Year[i]) && (month == Month[i]) && (Hour[i] < 18) && (Hour[i] > 6))
			{
				count++;
				Sum += Temperature[i];
			}
		if (count == 0)
		{
			return -273.16;
		}
		Sum /= count;
		return Sum;
	}
	double AverageNightTimeTemp(int _year, int _month)
	{
		int count = 0;
		double Sum = 0;
		for (int i = 0; i < Temperature.size(); i++)
			if ((_year == Year[i]) && (_month == Month[i]) && (Hour[i] < 18) && (Hour[i] < 6))
			{
				count++;
				Sum += Temperature[i];
			}
		if (count == 0)
		{
			return -273.16;
		}
		Sum /= count;
		return Sum;
	}
	void PrintObservation()//функция, которая выводит данные из файла
	{
		cout << "Г.   М.Д.Ч.Температура " << endl;
		for (int i = 0; i < Temperature.size(); i++)
		{
			cout << Year[i] << " " << Month[i] + 1 << " " << Day[i] + 1 << " " << Hour[i] << " " << Temperature[i] << " градусов." << endl;
		}
	}
	void SaveObservationToFile()//функция для сохранения наблюдения в файл;
	{
		//cout << Temperature.size();
		ofstream file;
		file.open("Temperature.txt");
		for (int i = 0; i < Temperature.size(); i++)
		{
			file << Year[i];
			file << " ";
			file << Month[i];
			file << " ";
			file << Day[i];
			file << " ";
			file << Hour[i];
			file << " ";
			file << Temperature[i];
			file << endl;
		}
		file.close();
	}
	~Thermometr() {}
};
int main(void)
{
	setlocale(0, "");
	int  choice;
	int type = 0;
	string Arr;
	int month = 0, year = 0, day = 0, hours = 0;
	Thermometr File;
	cout << "Установите начальное наблюдение: " << endl;
	cout << "Год - ";
	cin >> year;
	cout << endl << "Месяц - ";
	cin >> month;
	cout << endl << "День - ";
	cin >> day;
	cout << endl << "Время - ";
	cin >> hours;
	Thermometr Temp(year, month, day, hours);
	Temp.CheckData(year, month, day, hours);
	Temp.ReadFile("Temperature.txt");
	do
	{
		cout << "Что вы хотите сделать:\n 1  - Узнать начальную дату и время наблюдения.\n 2 - Задать наблюдение.\n 3 - Получить температуру в заданном наблюдении.\n 4 - Здать серию наблюдений.\n 5 - Получить среднюю температуру за день/месяц/всё время.\n 6 - Получить среднюю дневную или ночную температуру за месяц.\n 7 - Сохранить наблюдение.\n 8 - Считать историю наблюдений из файла." << endl;
		cin >> choice;
		while ((choice < 1) || (choice > 8))
		{
			cout << "Что вы хотите сделать:\n 1  - Узнать начальную дату и время наблюдения.\n 2 - Задать наблюдение.\n 3 - Получить температуру в заданном наблюдении.\n 4 - Здать серию наблюдений.\n 5 - Получить среднюю температуру за день/месяц/всё время.\n 6 - Получить среднюю дневную или ночную температуру за месяц.\n 7 - Сохранить наблюдение.\n 8 - Считать историю наблюдений из файла." << endl;
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			int y, m, d, h;
			Temp.GetInitialDate(y, m, d, h);
			cout << "Начальная дата:  " << y << " " << m << " " << d << " " << h << endl;
			break;
		}
		case 2:
		{
			int  temper = 0;
			cout << endl << "Введите температуру: ";
			cin >> temper;
			Temp.SetObservation(year, month, day, hours, temper);
			cout << "Наблюдение  задано. " << endl;
			break;
		}
		case 3:
		{
			int  m, d, h;
			cout << "Введите данные для поиска наблюдения наблюдения:\n  " << endl;
			cout << " 2)Месяц: " << endl;
			cin >> m;
			cout << " 2)День: " << endl;
			cin >> d;
			cout << " 2)Час: " << endl;
			cin >> h;
			Temp.CheckData(year, m, d, h);
			if (Temp.GetTemperature(year, m, d, h) == -1)
			{
				cout << "Такого наблюдения нет" << endl;
			}
			cout << " Температура заданной даты :" << Temp.GetTemperature(year, m, d, h) << " градуса(ов)." << endl;
			break;
		}
		case 4:
		{
			double Temper[24] = { 0, 1, 2, 3, 4 ,5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
			Temp.SerialObservation(year, month, day, Temper);
			break;
		}
		case 5:
		{
			int n = -1;
			int month = 0, day = 0;
			while ((n < 0) || (n > 2))
			{
				cout << "Выберите режим :" << endl;
				cout << "0 - За день" << endl << "1 - За месяц" << endl << "2 - Всё время" << endl;
				cin >> n;
			}
			switch (n)
			{
			case 0:
			{
				cout << "Введите месяц :" << endl;
				cin >> month;
				cout << "Введите день :" << endl;
				cin >> day;
				cout << "Средняя температура за день составляет: " << endl;
				cout << Temp.DailyAverageTemp(year, month, day) << " градуса(ов)." << endl;
				break;
			}
			case 1:
			{
				cout << "Введите месяц :" << endl;
				cin >> month;
				cout << "Средняя температура за месяц составляет: " << endl;
				cout << Temp.MouthlyAverageTemp(year, month) << " градуса(ов)." << endl;
				break;
			}
			case 2:
			{
				cout << "Средняя температура за всё время составляет: " << endl;
				cout << Temp.AllTimeAverageTemp() << " градуса(ов)." << endl;
				break;
			}
			}
			break;
		}
		case 6:
		{
			int s = 0;//для выбора режима;
			int mon = 0;
			do
			{
				cout << "1 - Дневная" << endl << "2 - Ночная" << endl;

				cin >> s;
			} while ((s < 1) || (s > 2));
			cout << "Месяц:" << endl;
			cin >> mon;
			switch (s)
			{
			case 1:
			{
				cout << "Средняя температура : " << Temp.AverageDayTimeTemp(year, mon) << endl;
				break;
			}
			case 2:
			{
				cout << "Средняя температура : " << Temp.AverageNightTimeTemp(year, mon) << endl;
				break;
			}
			}
			break;
		}
		case 7:
		{
			cout << "Сохранил данные. " << endl;
			Temp.SaveObservationToFile();
			Arr = "";
			break;
		}
		case 8:
		{

			cout << "Показатели температуры за всё время наблюдений " << endl;
			Temp.PrintObservation();
			break;
		}
		}
		cout << " Хотите закончить работу?/n1-да, 0-нет" << endl;
		cin >> type;
		while ((type != 0) && (type != 1))
		{
			cout << ("Введите  0 или 1.\n");
			cin >> type;
		}
	} while (type == 0);
	system("pause");
	return 0;
}