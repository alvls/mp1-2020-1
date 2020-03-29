#include <iostream>
#include <clocale> 
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
using namespace std;
class Thermometer
{
	int start_year;
	int start_month;
	int start_day;
	int start_hour;
	vector<int> Year;
	vector<int> Month;
	vector<int> Day;
	vector<int> Hour;
	vector<double> Temperature;
	int last_date[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
public:
	Thermometer() : start_year(2020), start_month(1), start_day(1), start_hour(0) {}
	~Thermometer() {}
	Thermometer(int year, int month, int day, int hour);
	void set_start_date(int year, int month, int day, int hour);
	void get_start_date(int& year, int& month, int& day, int& hour);
	void date_check(int year, int month, int day, int hour);
	bool create_new_observation(int year, int month, int day, int hour, double temperature);
	void create_series_of_observation(int year, int month, int day, double TempArr[]);
	double get_temperature(int year, int month, int day, int hour);
	double average_daily_temperature(int year, int month, int day);
	double average_monthy_temperature(int year, int month);
	double all_time_average_temperature();
	double am_average_temperature(int year, int month);
	double pm_average_temperature(int _year, int _month);
	Thermometer(string filename);
	void read_from_file();
	void save_to_file();
};
Thermometer::Thermometer(int year, int month, int day, int hour)
{
	start_year = year;
	start_month = month;
	start_day = day;
	start_hour = hour;
}
void Thermometer::set_start_date(int year, int month, int day, int hour)
{
	start_year = year;
	start_month = month;
	start_day = day;
	start_hour = hour;
}
void Thermometer::get_start_date(int& year, int& month, int& day, int& hour)
{
	year = start_year;
	month = start_month;
	day = start_day;
	hour = start_hour;
}
void Thermometer::date_check(int year, int month, int day, int hour)
{
	while (((month < 0) || (month > 12)) || ((day < 0) || (day > last_date[month - 1])) || ((hour < 0) || (hour > 23)))
	{
		cout << "Ошибка в вводе даты или времени. Попробуйте ввести дату еще раз" << endl;
		cin >> year >> month >> day;
		cout << "Введите время: ";
		cin >> hour;
		start_year = year;
		start_month = month;
		start_day = day;
		start_hour = hour;
	}
}
bool Thermometer::create_new_observation(int year, int month, int day, int hour, double temperature)
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
void Thermometer::create_series_of_observation(int year, int month, int day, double TempArr[])
{
	for (int i = 0; i < 24; i++)
	{
		create_new_observation(year, month, day, i, TempArr[i]);
	}
}
double Thermometer::get_temperature(int year, int month, int day, int hour)
{
	for (int i = 0; i < Temperature.size(); i++)
	{
		if (((year == Year[i]) && (month == Month[i]) && (day == Day[i]) && (hour == Hour[i])))
		{
			return Temperature[i];
		}
	}
	return 404;
}
double Thermometer::average_daily_temperature(int year, int month, int day)
{
	int n = 0;
	double amount = 0;
	for (int i = 0; i < Temperature.size(); i++)
	{
		if ((year == Year[i]) && (month == Month[i]) && (day == Day[i]))
		{
			n++;
			amount += Temperature[i];
		}
	}
	if (n == 0)
	{
		return 404;
	}
	amount /= n;
	return amount;
}
double Thermometer::average_monthy_temperature(int year, int month)
{
	int n = 0;
	double amount = 0;
	for (int i = 0; i < Temperature.size(); i++)
	{
		if ((year == Year[i]) && (month == Month[i]))
		{
			n++;
			amount += Temperature[i];
		}
	}
	if (n == 0)
	{
		return 404;
	}
	amount /= n;
	return amount;
}
double Thermometer::all_time_average_temperature()
{
	int n = 0;
	double amount = 0;
	for (int i = 0; i < Temperature.size(); i++)
	{
		n++;
		amount += Temperature[i];
	}
	if (n == 0)
	{
		return 404;
	}
	amount /= n;
	return amount;
}
double Thermometer::am_average_temperature(int year, int month)
{
	int n = 0;
	double amount = 0;
	for (int i = 0; i < Temperature.size(); i++)
		if ((year == Year[i]) && (month == Month[i]) && (Hour[i] > 9) && (Hour[i] < 21))
		{
			n++;
			amount += Temperature[i];
		}
	if (n == 0)
	{
		return 404;
	}
	amount /= n;
	return amount;
}
double Thermometer::pm_average_temperature(int _year, int _month)
{
	int n = 0;
	double amount = 0;
	for (int i = 0; i < Temperature.size(); i++)
		if ((_year == Year[i]) && (_month == Month[i]) && ((Hour[i] > 21) || (Hour[i] < 9)))
		{
			n++;
			amount += Temperature[i];
		}
	if (n == 0)
	{
		return 404;
	}
	amount /= n;
	return amount;
}
Thermometer::Thermometer(string filename)
{
	ifstream file(filename);
	int i = 0;
	if (file.is_open())
	{
		int year, month, day, hour, temperature;
		while (!file.eof())
		{
			year = 0;
			month = 0;
			day = 0;
			hour = 0;
			temperature = 0;
			file >> year >> month >> day >> hour >> temperature;
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
	file.close();
}
void Thermometer::read_from_file()
{
	cout << "Год   Месяц День Час Температура " << endl;
	for (int i = 0; i < Temperature.size(); i++)
	{
		cout << Year[i] << " " << Month[i] << " " << Day[i] << " " << Hour[i] << " " << Temperature[i] << " градуса(ов)" << endl;
	}
}
void Thermometer::save_to_file()
{
	ofstream file;
	file.open("Temperature.txt");
	for (int i = 0; i < Temperature.size(); i++)
	{
		file << Year[i] << " " << Month[i] << " " << Day[i] << " " << Hour[i] << " " << Temperature[i] << endl;
	}
	file.close();
}
int main(void)
{
	setlocale(LC_ALL, "Rus");
	int q = 0;
	int type = 0;
	string Arr;
	int month = 0, year = 0, day = 0, hour = 0;
	Thermometer Temp("Temperature.txt");
	cout << "Введите начало наблюдений в формате Год Месяц День: " << endl;
	cin >> year >> month >> day;
	cout << "Введите время: ";
	cin >> hour;
	Temp.set_start_date(year, month, day, hour);
	Temp.date_check(year, month, day, hour);
	while (q != 11)
	{
		cout << "0: Узнать начальныые дату и время наблюдений\n1: Задать наблюдение\n2: Получить температуру в выбранном наблюдении\n3: Задать серию наблюдений\n4: Найти среднюю температуру для выбранной даты\n5: Найти среднюю температуру для выбранного месяца\n6: Найти среднюю температуру за всю историю наблюдений\n7: Найти среднюю дневную температуру для выбранного месяца\n8: Найти среднюю ночную температуру для выбранного месяца\n9: Сохранить историю наблюдений в файл\n10: Считать историю наблюдений из файла\n11: Выйти из программы" << endl;
		cin >> q;
		switch (q)
		{
		case 0:
		{
			Temp.get_start_date(year, month, day, hour);
			cout << "Начальные дата и время:  " << year << " год " << month << " месяц " << day << " число " << hour << " час(а)(ов)" << endl;
			break;
		}
		case 1:
		{
			int  temper;
			cout << "Введите дату и время в формате Месяц День Час: " << endl;
			cin >> month >> day >> hour;
			cout << endl << "Введите температуру: ";
			cin >> temper;
			Temp.create_new_observation(year, month, day, hour, temper);
			cout << "Наблюдение  задано " << endl;
			break;
		}
		case 2:
		{
			int  my_m, my_d, my_h;
			cout << "Введите данные для поиска наблюдения в формате Месяц День Час:  " << endl;
			cin >> my_m >> my_d >> my_h;
			Temp.date_check(year, my_m, my_d, my_h);
			if (Temp.get_temperature(year, my_m, my_d, my_h) == -1)
			{
				cout << "Данных в этот день нет" << endl;
			}
			cout << " Температура в этот день :" << Temp.get_temperature(year, my_m, my_d, my_h) << " градус(а)(ов)." << endl;
			break;
		}
		case 3:
		{
			double t = 0;
			double Temper[24] = { 0, 1, 2, 3, 4 ,5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
			cout << "Введите дату, для которой хотите задать серийное наблюдение в формате Год Месяц День: " << endl;
			cin >> year >> month >> day;
			cout << "Запишите показания температуры за этот день с 0 до 23 часов:\n" << endl;
			for (int i = 0; i < 24; i++)
			{
				cin >> t;
				Temper[i] = t;
			}
			Temp.create_series_of_observation(year, month, day, Temper);
			break;
		}
		case 4:
		{
			int month = 0;
			int	day = 0;
			cout << "Введите Месяц и День :" << endl;
			cin >> month >> day;
			cout << "Средняя температура за день составляет: " << endl;
			cout << Temp.average_daily_temperature(year, month, day) << " градус(а)(ов)" << endl;
			break;
		}
		case 5:
		{
			int month = 0;
			cout << "Введите месяц :" << endl;
			cin >> month;
			cout << "Средняя температура за месяц составляет: " << endl;
			cout << Temp.average_monthy_temperature(year, month) << " градус(а)(ов)." << endl;
			break;
		}
		case 6:
		{
			cout << "Средняя температура за всё время составляет: " << endl;
			cout << Temp.all_time_average_temperature() << " градус(а)(ов)" << endl;
			break;
		}
		case 7:
		{
			int month;
			cout << "Месяц:" << endl;
			cin >> month;
			cout << "Средняя температура за день : " << Temp.am_average_temperature(year, month) << " градус(а)(ов)" << endl;
			break;
		}
		case 8:
		{
			int month;
			cout << "Месяц:" << endl;
			cin >> month;
			cout << "Средняя температура за ночь : " << Temp.pm_average_temperature(year, month) << " градус(а)(ов)" << endl;
			break;
		}
		case 9:
		{
			cout << "Данные сохранены" << endl;
			Temp.save_to_file();
			Arr = "";
			break;
		}
		case 10:
		{

			cout << "Данные о температуры за всё время наблюдений " << endl;
			Temp.read_from_file();
			break;
		}
		case 11:
		{
			system("pause");
			break;
			{
		default:
			cout << "Вы неправильно ввели номер. Данная функция отсутсвует" << endl;
			break;
			}
		}
		}
	}
	return 0;
}