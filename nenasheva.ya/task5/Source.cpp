#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include "Deposit.h"
using namespace std;

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	PC P;
	Deposit D;

	string f, n, p, pass, fnp;
	double money;
	cout << "Регистрация " << endl;
	cout << "----------- " << endl << endl;
	cout << "Введите ФИО: ";
	cin >> f;
	cin >> n;
	cin >> p;
	fnp = f + " " + n + " " + p;
	cout << "Введите баланс счёта: ";
	cin >> money;
	cout << "Придумайте пароль: ";
	cin >> pass;
	cout << P.AddUser(fnp, money, pass) << endl;
	D.ConnectToProcessingCentre(&P);

	string an;
	cout << "Войдите в систему" << endl;
	cout << "Введите номер счёта: ";
	cin >> an;
	cout << "Введите пароль: ";
	cin >> pass;
	D.Login(an, pass);
	cout << D.Get_AvailableDeposits() << endl;

	string a;
	int month;
	if (D.CheckExistingDeposit())
		cout << "У вас уже есть открытый депозит" << endl;
	else
	{
		cout << "У вас ещё нет депозита. Хотите открыть?\t";
		cin >> a;
		if ((a == "да") || (a == "Да"))
		{
			cout << "На сколько месяцев Вы хотите открыть депозит?\t";
			cin >> month;
			cout << "Сколько денег вы хотите перечислить на депозитный счет?\t";
			cin >> money;
			if (D.OpenDeposit(month, money))
			{
				cout << "Вы успешно открыли депозит!" << endl;
				cout << D.Get_DepositInfo() << endl;
			}
			else
			{
				cout << "Не удалось открыть депозит!" << endl;
			}
		}
		else
		{
			cout << "До свидания!" << endl;
			system("pause");
			return false;
		}
	}

	int month_persents;
	cout << D.Get_SalaryAccountInfo() << endl;
	cout << "За сколько месяцев Вы хотите снять проценты?\t";
	cin >> month_persents;
	cout << D.WidthrawPercents(month_persents) << endl;
	cout << D.Get_SalaryAccountInfo() << endl;

	if (D.CloseDeposit())
		cout << "Срок вашего депозита истёк" << endl;
	else return false;

	D.Logout();
	
	system("pause");
	return 0;
}