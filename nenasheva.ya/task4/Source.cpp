#include <iostream>
#include <Windows.h>
#include "Weather.h"
using namespace std;

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Weather W;
	W.Read_from_file("Погода.txt");
	W.Set_start(01, 03, 2020, 00);
	Observation s = W.Get_start();
	cout << "Дата начала наблюдений: " << s.day << '.' << s.month << '.' << s.year << endl;
	cout << "Время: " << s.time << ".00" << endl;
	int d, m, y, h, t, from, to;
	int *q = new int[25];
	int r;
	cout << "Что вы хотите сделать?" << endl;
	cout << "1) Задать наблюдение" << endl;
	cout << "2) Задать серию наблюдений" << endl;
	cin >> r;
	switch (r)
	{
	case 1:
		cout << "Введите день, месяц, год, время и температуру: ";
		cin >> d >> m >> y >> h >> t;
		try
		{
			W.Set_observation(d, m, y, h, t);
		}
		catch (char *str)
		{
			cout << str << endl;
			system("pause");
			return 404;
		}
		cout << "Введите день, месяц, год и время, чтобы узнать температуру: ";
		cin >> d >> m >> y >> h;
		cout << "Заданная температура: " << W.Get_T(d, m, y, h) << endl;
		break;
	case 2:
		cout << "Введите день, месяц, год, начальный и конечный часы: ";
		cin >> d >> m >> y >> from >> to;
		for (int i = 0; i < to - from + 1; i++)
		{
			cout << "Введите температуру для " << from + i << ": ";
			cin >> q[i];
		}
		W.Set_series(d, m, y, from, to, q);
		break;
	}
	int p;
	cout << "Что вы хотите узнать?" << endl;
	cout << "1) Среднюю температуру за год" << endl;
	cout << "2) Среднюю температуру за месяц" << endl;
	cout << "3) Среднюю температуру за день" << endl;
	cout << "4) Среднюю дневную и ночную температуру за месяц" << endl;
	cin >> p;
	switch (p)
	{
	case 1:
		cout << "Средняя температура за год: " << W.Search_average_T_for_year() << endl;
		break;
	case 2:
		cout << "Введите номер месяца и года, за который хотите узнать среднюю температуру: ";
		cin >> m >> y;
		cout << "Средняя температура за выбранный мeсяц: " << W.Search_average_T_for_month(m, y) << endl;
		break;
	case 3:
		cout << "Введите день, месяц и год, за которые хотите узнать среднюю температуру(в цифрах): ";
		cin >> d >> m >> y;
		cout << "Cpедняя температура за указанную дату: " << W.Search_average_T_for_day(d, m, y) << endl;
		break;
	case 4:
		cout << "Введите номер месяца и года, за который хотите узнать среднюю дневную и ночную температуру: ";
		cin >> m >> y;
		cout << "Средняя дневная температура за выбранный мeсяц: " << W.Search_average_T(m, y, 11, 16) << endl;
		cout << "Средняя ночная температура за выбранный мeсяц: " << W.Search_average_T(m, y, 0, 6) << endl;
		break;
	}
	W.Save_to_file("Погода.txt");

	system("pause");
	return 0;
}