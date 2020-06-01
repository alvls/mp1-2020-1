#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

int DAY;
int MONTH;
int YEAR;
void SetDate(int _day, int _month, int _year)
{
	DAY = _day;
	MONTH = _month;
	YEAR = _year;
}
struct deposit
{
	int day;//дата открытия депозита
	int month;
	int year;
	int contribution;//начальная сумма депозита
	double percent;//процент по вкладу
	string time;//срок
	bool status;//статус(открыт/закрыт)
	int endday;//дата закрытия депозита
	int endmonth;
	int endyear;
};
ostream& operator<<(ostream& os, const deposit dep)
{
	os << "На вашем вкладе " << dep.contribution << " рублей, под " << dep.percent << "% годовых " << "на " << dep.time << endl << endl;
	os << "Дата открытия вклада:" << dep.day << " " << dep.month << " " << dep.year << endl;
	os << "Дата закрытия вклада:" << dep.endday << " " << dep.endmonth << " " << dep.endyear;
	return os;
}
struct Client
{
	int login;//номер счета
	string pass;//пароль
	string fullname;//фио
	int pay;//сумма на зарплатном счете
	deposit Deposit;//информация о депозите
};
ostream& operator<<(ostream& os, const Client& client)
{
	os << "Номер счета:" << client.login << "\n" << "Пользователь:" << client.fullname << "\n" << "Сумма на зарплатном счете:" << client.pay << "рублей";
	return os;
}
class ProcessingCentr
{
private:
	vector<Client>base;
public:
	Client AddClient(Client tmp)
	{
		if (tmp.pass.length() > 3 && (tmp.login < 10000 && tmp.login>0))//проверка длины пароля и номера счета
		{
			base.push_back(tmp);
			return tmp;
		}
		if (tmp.pass.length() < 3)
		{
			cout << "Пароль должен быть от трех символов.";
			throw;
		}
		if (tmp.login > 9999 || tmp.login <= 0)
		{
			cout << "Неверно указан номер счета.";
			throw;
		}
	}

	friend ostream& operator<<(ostream& os, const ProcessingCentr& tmp);
	friend class Bank;
};
ostream& operator<<(ostream& os, const ProcessingCentr& tmp)
{
	for (size_t i = 0; i < tmp.base.size(); i++)
	{
		os << tmp.base[i] << endl;
	}
	return os;
}
class Bank
{
private:
	ProcessingCentr box;
	Client clt = {};
	bool enter = false;//проверка на вход
	bool end = false;//проверка был закрты депозит или нет
	int savings;//накопления на вкладе
	string srok[5] = { "3 месяца","6 месяцев","1 год","2 года","3 года" };//массивы с основной информацией 
	double percent[20] = { 3.0, 3.5, 4.0, 4.3, 4.8, 4.2, 4.5, 4.8, 5., 5.5, 5, 5.4, 5.7, 6, 6.3, 6, 6.5, 6.9, 7.2, 7.5 };
	int sum[3] = { 100000,500000,1000000 };
	void rewrite(Client tmp)
	{
		for (size_t i = 0; i < box.base.size(); i++)
		{
			if (tmp.login == box.base[i].login && tmp.pass == box.base[i].pass)
				box.base[i] = tmp;
		}
	}
	int Rise()//рост по вкладу
	{
		int tempmonth = 0;//колличество прошедших месяцев с момента открытия депозита по установленную дату
		if (DAY >= clt.Deposit.day)
		{
			if (YEAR <= clt.Deposit.endyear)
				tempmonth = (MONTH - clt.Deposit.month) + 12 * (YEAR - clt.Deposit.year);//высчитываем сколько всего месяцев прошло с момента открытия депозита до момента входа в систему
			if (YEAR == clt.Deposit.endyear && MONTH >= clt.Deposit.endmonth)
				tempmonth = (clt.Deposit.endmonth - clt.Deposit.month) + 12 * (clt.Deposit.endyear - clt.Deposit.year);
			if (YEAR > clt.Deposit.endyear)
				tempmonth = (clt.Deposit.endmonth - clt.Deposit.month) + 12 * (clt.Deposit.endyear - clt.Deposit.year);
		}
		if (DAY < clt.Deposit.day)
		{
			if (YEAR <= clt.Deposit.endyear)
				tempmonth = (MONTH - clt.Deposit.month) + 12 * (YEAR - clt.Deposit.year) - 1;
			if (YEAR == clt.Deposit.endyear && MONTH >= clt.Deposit.endmonth)
				tempmonth = (clt.Deposit.endmonth - clt.Deposit.month) + 12 * (clt.Deposit.endyear - clt.Deposit.year);
			if (YEAR > clt.Deposit.endyear)
				tempmonth = (clt.Deposit.endmonth - clt.Deposit.month) + 12 * (clt.Deposit.endyear - clt.Deposit.year);
		}
		savings = int(clt.Deposit.contribution * tempmonth * clt.Deposit.percent / 12 / 100);
		return savings;
	}
public:
	Bank(ProcessingCentr _box)
	{
		box = _box;
	};
	Client SignIn(unsigned int account, string str)//войти в систему
	{
		for (size_t i = 0; i < box.base.size(); i++)
		{
			if (box.base[i].login == account && box.base[i].pass == str)
			{
				clt = box.base[i];
				enter = true;
				return clt;
			}
			if (box.base[i].login != account || box.base[i].pass != str)
			{
				cout << "Неправильно введен номер или пароль." << endl;
				throw;
			}
		}
	}
	void ShowVariantsOfDeposits()//показать доступные депозиты
	{
		if (enter)
		{
			if (clt.Deposit.status)
			{
				cout << "У Вас уже открыт депозит" << endl;
				return;
			}
			cout << "Вам доступны следующие депозиты" << endl;
			if (clt.pay < sum[0])
			{
				cout << "На сумму до " << sum[0] << " рублей " << endl;
				for (int i = 0; i < 5; i++)
				{
					cout << " на срок " << srok[i] << " под " << percent[i] << " % годовых" << endl;
				}
			}
			if (clt.pay >= sum[0] && clt.pay < sum[1])
			{
				int i = 0;
				int j = 0;
				int k = 0;
				cout << "На сумму до " << sum[k] << " рублей " << endl;
				for (i, j; i < 10; i++, j++)
				{
					if (j > 4)
					{
						j = 0;
						cout << "На сумму от " << sum[k] << " до " << sum[k + 1] << " рублей " << endl;
						k++;
						cout << endl;
					}
					cout << " на срок " << srok[j];
					cout << " под " << percent[i] << " % годовых " << endl;
				}
			}
			if (clt.pay >= sum[1] && clt.pay < sum[2])
			{
				int i = 0;
				int j = 0;
				int k = 0;
				cout << "На сумму до " << sum[k] << " рублей " << endl;
				for (i, j; i < 15; i++, j++)
				{
					if (j > 4)
					{
						j = 0;
						cout << "На сумму от " << sum[k] << " до " << sum[k + 1] << " рублей " << endl;
						k++;
						cout << endl;
					}
					cout << " на срок " << srok[j];
					cout << " под " << percent[i] << " % годовых " << endl;
				}
			}
			if (clt.pay >= sum[2])
			{
				int i = 0;
				int j = 0;
				int k = 0;
				cout << "На сумму до " << sum[k] << " рублей " << endl;
				for (i, j; i < 20; i++, j++)
				{
					if (j > 4)
					{
						cout << endl;
						j = 0;
						if (k == 2)
							cout << "На сумму от " << sum[k] << " рублей " << endl;
						else cout << "На сумму от " << sum[k] << " до " << sum[k + 1] << " рублей " << endl;
						k++;
					}
					cout << " на срок " << srok[j];
					cout << " под " << percent[i] << " % годовых " << endl;
				}
			}
		}
		else cout << "Войдите в систему" << endl;
	}
	void OpenDeposit(int money, string time)
	{
		if (enter)
		{
			deposit dep = {};
			if (clt.Deposit.status)
				cout << "На вашем счете уже открыт депозит" << endl;
			if (clt.pay >= money)
			{
				if (money < sum[0])
				{
					for (int i = 0; i < 5; i++)
						if (srok[i] == time)
							dep.percent = percent[i];
				}
				if (money >= sum[0] && money < sum[1])
				{
					int i = 5;
					int j = 0;
					for (i, j; i < 10; i++, j++)
						if (srok[j] == time)
							dep.percent = percent[i];
				}
				if (money >= sum[1] && money < sum[2])
				{

					int i = 10;
					int j = 0;
					for (i, j; i < 15; i++, j++)
						if (srok[j] == time)
							dep.percent = percent[i];
				}
				if (money >= sum[2])
				{
					int i = 15;
					int j = 0;
					for (i, j; i < 20; i++, j++)
						if (srok[j] == time)
							dep.percent = percent[i];
				}
				clt.pay -= money;
				dep.contribution = money;
				dep.status = true;
				dep.day = DAY;
				dep.month = MONTH;
				dep.year = YEAR;
				dep.endday = DAY;
				dep.endmonth = MONTH;
				dep.endyear = YEAR;
				if (time == "3 месяца")
				{
					dep.endmonth += 3;
					if (dep.endmonth > 12)
					{
						dep.endmonth %= 12;
						dep.endyear++;
					}
				}
				if (time == "6 месяцев")
				{
					dep.endmonth += 6;
					if (dep.endmonth > 12)
					{
						dep.endmonth %= 12;
						dep.endyear++;
					}
				}
				if (time == "1 год")
					dep.endyear++;
				if (time == "2 года")
					dep.endyear += 2;
				if (time == "3 года")
					dep.endyear += 3;
				dep.time = time;
				clt.Deposit = dep;
				rewrite(clt);
				end = false;
			}
			else cout << "Сумма депозита превышает зарплатный счет" << endl;
		}
		else cout << "Войдите в систему" << endl;
	}
	void StateDep()//показать открыт депозит или нет
	{
		if (enter)
		{
			if (clt.Deposit.status)
				cout << "Депозит открыт" << endl;
			else
				cout << "У вас нет открытых депозитов" << endl;
		}
		else cout << "Войдите в систему" << endl;
	}
	void ShowStatusOfDeposit()//показать состояние депозита
	{
		if (enter)
		{
			if (clt.Deposit.status)
			{
				Rise();
				cout << clt.Deposit << endl;
				cout << "Ваши накопления составляют:" << savings << endl;
			}
			if (end)
			{
				cout << "Ваш депозит был закрыт" << endl;
			}
		}
		else cout << "Войдите в систему" << endl;
	}
	void GetPercent()//снять проценты
	{
		if (enter)
		{
			Rise();
			clt.pay += savings;
			savings = 0;
			rewrite(clt);
		}
		else cout << "Войдите в систему" << endl;
	}
	void CloseDeposit()
	{
		if (enter)
		{
			if (YEAR > clt.Deposit.endyear)
			{
				clt.pay += clt.Deposit.contribution + savings;
				clt.Deposit = {};
				savings = 0;
				rewrite(clt);
				cout << "Ваш депозит был закрыт" << endl;
				end = true;
				return;
			}
			if (YEAR == clt.Deposit.endyear && MONTH >= clt.Deposit.endmonth)
			{
				if (MONTH == clt.Deposit.endmonth && DAY >= clt.Deposit.endday)
				{
					clt.pay += clt.Deposit.contribution + savings;
					clt.Deposit = {};
					savings = 0;
					rewrite(clt);
					cout << "Ваш депозит был закрыт" << endl;
					end = true;
					return;
				}
				if (MONTH > clt.Deposit.endmonth)
				{
					clt.pay += clt.Deposit.contribution + savings;
					clt.Deposit = {};
					savings = 0;
					rewrite(clt);
					cout << "Ваш депозит был закрыт" << endl;
					end = true;
					return;
				}
				if (MONTH == clt.Deposit.endmonth && DAY < clt.Deposit.endday)
					cout << "Депозит может быть закрыт только по оканчанию срока" << endl;
			}
			if ((YEAR < clt.Deposit.endyear) || (YEAR == clt.Deposit.endyear && YEAR < clt.Deposit.endyear))
				cout << "Депозит может быть закрыт только по оканчанию срока" << endl;
		}
		else cout << "Войдите в систему" << endl;
	}
	friend ostream& operator<<(ostream& os, const ProcessingCentr& tmp);
	friend class ProcessingCentr;

};
void main()
{
	setlocale(LC_ALL, "rus");
	SYSTEMTIME st;
	GetLocalTime(&st);
	Client one = { 1225,"hello","Малинина Виктория Сергеевна",1230000, };
	char password[16];
	int num, i, choice = 0;
	int day, month, year;
	ProcessingCentr centr;
	centr.AddClient(one);
	Bank network(centr);
	cout << "Введите логин" << endl;
	cin >> num;
	cout << "Введите пароль" << endl;
	for (i = 0; (password[i] = _getch()) != '\r';)
	{
		if (password[i] == '\b' && i != 0)
		{
			cout << "\b \b";
			i--;
		}
		else if (password[i] != '\b')
		{
			cout << '*';
			i++;
		}
	}
	password[i] = '\0';
	network.SignIn(num, string(password));
	SetDate(st.wDay, st.wMonth, st.wYear);
	system("cls");
	while (_getch())
	{
		cout << "Дата:" << ::DAY << " " << ::MONTH << " " << ::YEAR << endl << endl;
		cout << network.SignIn(num, string(password)) << endl << endl;
		cout << "1 -Информация о доступных депозитах" << endl << "2 -Открыть депозит" << endl << "3 -Закрыть депозит" << endl << "4 -Проверить наличие открытого депозита" << endl << "5 -Узнать состояние депозита" << endl << "6 -Cнять проценты (переведя их на зарплатный счет клиента)" << endl << "7 -Перемотать время" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("cls");
			network.ShowVariantsOfDeposits();
			cout << endl;
			break;
		}
		case 2:
		{
			system("cls");
			int button = 0;
			int am;
			string str;
			cout << "Выберете срок депозита" << endl;
			cout << "1) 3 месяца" << endl;
			cout << "2) 6 месяцев" << endl;
			cout << "3) 1 года" << endl;
			cout << "4) 2 года" << endl;
			cout << "5) 3 года" << endl;
			cin >> button;
			switch (button)
			{
			case 1:
			{
				str = "3 месяца";
				break;
			}
			case 2:
			{
				str = "6 месяцев";
				break;
			}
			case 3:
			{
				str = "1 год";
				break;
			}
			case 4:
			{
				str = "2 года";
				break;
			}
			case 5:
			{
				str = "3 года";
				break;
			}
			default:
			{
				cout << "Неверное значение" << endl;
				break;
			}
			}
			cout << "Введите сумму" << endl;
			cin >> am;
			network.OpenDeposit(am, str);
			break;
		}
		case 3:
		{
			system("cls");
			network.CloseDeposit();
			break;
		}
		case 4:
		{
			system("cls");
			network.StateDep();
			break;
		}
		case 5:
		{
			system("cls");
			network.ShowStatusOfDeposit();
			break;
		}
		case 6:
		{
			system("cls");
			network.GetPercent();
			break;
		}
		case 7:
		{
			system("cls");
			cout << "Введите дату в формате день месяц год" << endl;
			cin >> day;
			cin >> month;
			cin >> year;
			SetDate(day, month, year);
			break;
		}
		default:
		{
			cout << "Неверное значение" << endl;
			break;
		}
		}
	}
	system("pause");
}