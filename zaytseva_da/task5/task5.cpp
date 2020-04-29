#define _CRT_SECURE_NO_WARNINGS
#include<locale.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

class ProcessingCenter
{
private:
	int CardNum;
	string Name1; //фамилия
	string Name2; //имя
	string Name3; //отчество
	string Pin;
	int Amount;
	int Credit;
	vector <int> BASE;
	vector <string> NAME1;
	vector <string> NAME2;
	vector <string> NAME3;
	vector <int> AMOUNT;
	vector <string> PIN;
	vector <int> CREDIT;
public:
	ProcessingCenter()
	{
		CardNum = 0;
		Name1 = "_";
		Name2 = "_";
		Name3 = "_";
		Pin = "_";
		Amount = 0;
		Credit = 0;
		BASE = { 0 };
		NAME1 = { 0 };
		NAME2 = { 0 };
		NAME3 = { 0 };
		AMOUNT = { 0 };
		PIN = { 0 };
		CREDIT = { 0 };
	}

	ProcessingCenter(int _CardNum, string _Name1, string _Name2, string _Name3, string _Pin, int _Amount, int _Credit)
	{
		CardNum = _CardNum;
		Name1 = _Name1;
		Name2 = _Name2;
		Name3 = _Name3;
		Pin = _Pin;
		Amount = _Amount;
		Credit = _Credit;
		BASE.push_back(CardNum);
		NAME1.push_back(Name1);
		NAME2.push_back(Name2);
		NAME3.push_back(Name3);
		AMOUNT.push_back(Amount);
		PIN.push_back(Pin);
		CREDIT.push_back(Credit);
	}
	void set_ChangeAmount(int _Amount)
	{
		Amount = _Amount;
	}

	void set_Pin(string _Pin)
	{
		Pin = _Pin;
	}

	void set_Name(string _Name1, string _Name2, string _Name3)
	{
		Name1 = _Name1;
		Name2 = _Name2;
		Name3 = _Name3;
	}

	void set_ChangePIN(int _CardNum, string _Pin, string _Pin1)
	{
		if (CardNum == _CardNum)
			if (Pin == _Pin)
			{
				Pin = _Pin1;
				return;
			}
		throw;
	}

	void set_Person(int _CardNum, string _Name1, string _Name2, string _Name3, string _Pin, int _Amount)
	{
		Name1 = _Name1;
		Name2 = _Name2;
		Name3 = _Name3;
		Pin = _Pin;
		Amount = _Amount;
		CardNum = _CardNum;
		Credit = 0;
	}

	void DataBase()
	{
		BASE.push_back(CardNum);
		NAME1.push_back(Name1);
		NAME2.push_back(Name2);
		NAME3.push_back(Name3);
		AMOUNT.push_back(Amount);
		PIN.push_back(Pin);
		CREDIT.push_back(Credit);
	}

	void set_CardNum_DataBase(int i)
	{
		for (i = 0; i < BASE.size(); i++)
		{
			cout << BASE[i] << " ";
		}
	}

	void set_Amount_DataBase(int i)
	{
		for (i = 0; i < AMOUNT.size(); i++)
		{
			cout << AMOUNT[i] << " ";
		}
	}

	void set_Name1_DataBase(int i)
	{
		for (i = 0; i < NAME1.size(); i++)
		{
			cout << NAME1[i] << " ";
		}
	}

	void set_Name2_DataBase(int i)
	{
		for (i = 0; i < NAME2.size(); i++)
		{
			cout << NAME2[i] << " ";
		}
	}

	void set_Name3_DataBase(int i)
	{
		for (i = 0; i < NAME3.size(); i++)
		{
			cout << NAME3[i] << " ";
		}
	}

	void set_Credit_DataBase(int i)
	{
		for (i = 0; i < CREDIT.size(); i++) {
			cout << CREDIT[i] << " ";
		}
	}

	int get_Amount()
	{
		return Amount;
	}

	int get_CardNum()
	{
		return CardNum;
	}

	int get_Credit()
	{
		return Credit;
	}

	string get_Pin()
	{
		return Pin;
	}

	void get_Person()
	{
		cout << "Your name: " << Name1 << " " << Name2 << " " << Name3 << endl;
		cout << "Card number: " << setfill('0') << setw(4) << CardNum << endl;
		cout << "Invoice amount: " << Amount << endl;
	}

	ProcessingCenter& operator=(const ProcessingCenter& a)
	{
		Name1 = a.Name1;
		Name2 = a.Name2;
		Name3 = a.Name3;
		CardNum = a.CardNum;
		Amount = a.Amount;
		Pin = a.Pin;
		return *this;
	}

	int take_AMOUNT(ProcessingCenter& PERSON)
	{
		for (int i = 0; i < 10000; i++)
		{
			if (PERSON.get_CardNum() == BASE[i])
			{
				return AMOUNT[i];
			}
			else
				throw;
		}
	}

	int take_Credit(ProcessingCenter& PERSON)
	{
		for (int i = 0; i < 10000; i++)
		{
			if (PERSON.get_CardNum() == BASE[i])
			{
				return CREDIT[i];
			}
			else
				throw;
		}
	}

	void set_CREDIT(int _c, int p)
	{
		int k = 0;
		for (int i = 0; i < BASE.size(); i++)
			if (BASE[i] == p)
			{
				k = i;
				break;
			}
		CREDIT.at(k) = _c;
	}

	void set_AMOUNT(ProcessingCenter& PERSON, int _c)
	{
		int k = 0;
		for (int i = 0; i < BASE.size(); i++)
			if (BASE[i] == PERSON.get_CardNum())
			{
				k = i;
				break;
			}
		AMOUNT.at(k) = _c;
	}

	bool Comparison(int p)
	{
		for (int i = 0; i < BASE.size(); i++)
			if (p == BASE[i])
			{
				set_Person(BASE[i], NAME1[i], NAME2[i], NAME3[i], PIN[i], AMOUNT[i]);
				return 1;
			}
			else
				return 0;
	}

	~ProcessingCenter()
	{

	}
};

class Credit
{
	int a; //проверка авторизации
	int Proc; //начисленные проценты по кредиту
	int Payment; //суммарные выплаты по кредиту
	int MonPayment; //ежемесячная выплата по кредиту
	int Years; //количество лет
	int Quantity; //сумма кредита
	int Repay; //остаток по кредиту
	int Chek; //хватит ли денег на выплаты
public:
	Credit()
	{
		a = 1;
		Proc = 0;
		Payment = 0;
		MonPayment = 0;
		Years = 0;
		Quantity = 0;
		Repay = 0;
		Chek = 0;
	}

	void Authorization(ProcessingCenter& PERSON, int n, string pin)
	{
		if (PERSON.Comparison(n))
		{

			if (pin != PERSON.get_Pin())
			{
				cout << "You entered your password incorrectly, please, try logging in again" << endl;
			}
			else
			{
				cout << "You are logged in" << endl;
			}
		}
	}

	void AvailableCredit(int y, int q)
	{
		double ky, kq;
		switch (y)
		{
		case 1:
		{
			ky = 4;
		}

		case 2:
		{
			ky = 6;
		}
		case 3:
		{
			ky = 12;
		}
		case 5:
		{
			ky = 15;
		}
		case 15:
		{
			ky = 18;
		}
		}

		if (q < 100000) kq = 8;
		if (100000 <= q < 500000) kq = 6;
		if (500000 <= q < 1000000) kq = 4;
		if (1000000 <= q < 3000000) kq = 3;

		Proc = ky * kq;
		Payment = (0.01 * Proc * q) + q;
		MonPayment = Payment / (y * 12);
		Years = y;
		Quantity = q;
		Repay = Payment;
		cout << "you can get a loan for the amount of: " << Quantity << " for the next number of years: " << Years << " at " << Proc << " % per annum" << endl;
		cout << "The total amount of payments will be: " << Payment << " the monthly payment will be: " << MonPayment << endl;
	}

	void CheckCredit(ProcessingCenter& PERSON)
	{
		if (PERSON.take_Credit(PERSON) == 0)
		{
			cout << "You don't have an open credit" << endl;
		}
		else
			cout << "Your credit is: " << PERSON.take_Credit(PERSON) << endl;
	}

	bool CheckToGet(ProcessingCenter& PERSON)
	{
		int p;
		int q;
		p = PERSON.get_Amount();

		q = MonPayment * 6;

		if (p >= q)
		{
			cout << "Loan approved" << endl;
			return true;
		}
		else
			cout << "The loan is not approved" << endl;
		return false;
	}

	void AddCredit(ProcessingCenter& PERSON)
	{
		if (CheckToGet(PERSON))
		{
			PERSON.set_CREDIT(Quantity, PERSON.get_CardNum());
		}
	}

	int MonthlyPayment(ProcessingCenter& PERSON)
	{
		int t;
		t = PERSON.get_Amount();
		Chek = t - MonPayment;
		if (Chek < 0)
			cout << "Your balance is not sufficient to repay the payment" << endl;
		else
			Repay = Repay - MonPayment;
		cout << "Monthly payment paid" << endl;
		if (Repay <= 0)
			cout << "The loan is repaid" << endl;
		return Repay;
	}

	int ExtraPayment(ProcessingCenter& PERSON, int a)
	{
		int t;
		t = PERSON.get_Amount();
		Chek = t - a;
		if (Chek < 0)
			cout << "Your balance is not sufficient to repay the payment" << endl;
		else Repay = Repay - a;
		if (Repay <= 0)
			cout << "The loan is repaid" << endl;
		return Repay;
	}

	void CreditStatus(ProcessingCenter& PERSON)
	{
		cout << "You still have to pay: " << Repay << endl;
		cout << "Already paid: " << (Payment - Repay) << endl;
	}

	~Credit()
	{

	}
};

int main()
{
	int c;
	int x = 0;
	int k;
	int t;
	int a = 0;
	string name1 = "";
	string name2 = "";
	string name3 = "";
	string pin = "";
	int s = 0;
	string pin1 = "";
	int m = 0;
	Credit C;
	int y = 0;
	int q = 0;
	int w;
	int f;
	int r = 0;
	ProcessingCenter Person(a, name1, name2, name3, pin, s, m);

	while (x == 0)
	{
		do
		{
			cout << "\n1) Create an account" << endl;
			cout << "2) Authorization" << endl;
			cout << "10) Exit" << endl;
			cin >> k;
			if (k == 1)
			{
				cout << "Please enter your account number from 0001 to 9999: " << endl;
				cin >> a;
				while (a < 1 || a > 9999)
				{
					cout << "This number does not exist!" << endl;
					cout << "Please enter your account number from 0001 to 9999: " << endl;
					cin >> a;
				}
				cout << "Please enter your last name: " << endl;
				cin >> name1;
				cout << "Please enter your name: " << endl;
				cin >> name2;
				cout << "Please enter your middle name: " << endl;
				cin >> name3;


				cout << "Please enter a password longer than three characters: " << endl;
				cin >> pin;
				while (pin.length() < 4)
				{
					cout << "Your password must be more than three characters long: " << endl;
					cin >> pin;
				}

				cout << "Please enter the amount of your invoice: " << endl;
				cin >> s;
				while (s < 0)
				{
					cout << "You entered a negative amount!" << endl;
					cin >> s;
				}
				Person.set_Person(a, name1, name2, name3, pin, s);
				Person.DataBase();
				Person.get_Person();
				r = 0;
			}

			else if (k == 2)
			{
				cout << "Please enter your card number: " << endl;
				cin >> a;
				cout << "Please enter your pin: " << endl;
				cin >> pin;
				C.Authorization(Person, a, pin);
				r = 1;

			}

			else if (k == 3)
			{
				exit(EXIT_SUCCESS);
				break;
			}

			else
			{
				cout << "Invalid input" << endl;
			}

		} while (r == 0);
		int z = 0;
		while (z == 0)
		{
			cout << "\n1) Change account" << endl;
			cout << "2) View available credits" << endl;
			cout << "3) Check the availability of credit" << endl;
			cout << "4) Check the ability to get" << endl;
			cout << "5) Receive credit" << endl;
			cout << "6) Find out the current status of the loan" << endl;
			cout << "7) Make a monthly loan payment" << endl;
			cout << "8) Make an extra payment on the loanonal payment on the loan" << endl;
			cout << "9) Log out" << endl;
			cout << "10) Exit" << endl;

			cin >> c;

			switch (c)
			{
			case 1:
			{
				cout << "\n1) Change pin" << endl;
				cout << "2) Change name" << endl;
				cout << "3) Change amount" << endl;
				cin >> t;
				switch (t)
				{
				case 1:
				{
					cout << "Please enter your card number" << endl;
					cin >> a;
					cout << "Please enter your old pin" << endl;
					cin >> pin1;
					cout << "Please enter your new pin" << endl;
					cin >> pin;
					Person.set_ChangePIN(a, pin1, pin);
					Person.get_Person();
					break;
				}

				case 2:
				{
					cout << "Please enter your last name" << endl;
					cin >> name1;
					cout << "Please enter your name" << endl;
					cin >> name2;
					cout << "Please enter your middle name" << endl;
					cin >> name3;
					Person.set_Name(name1, name2, name3);
					Person.get_Person();
					break;
				}

				case 3:
				{
					cout << "Please enter your new account balance" << endl;
					cin >> s;
					Person.set_ChangeAmount(s);
					Person.get_Person();
					break;
				}

				default:
				{
					cout << "Invalid input" << endl;
					break;
				}
				}




			}

			case 2:
			{
				cout << "Please enter the term for which you want to take out a loan: " << endl;
				cin >> y;
				cout << "Please enter the loan amount: " << endl;
				cin >> q;
				C.AvailableCredit(y, q);
				break;
			}

			case 3:
			{
				C.CheckCredit(Person);
				break;
			}

			case 4:
			{
				C.CheckToGet(Person);
				break;
			}

			case 5:
			{
				C.AddCredit(Person);
				break;
			}

			case 6:
			{
				C.CreditStatus(Person);
				break;
			}

			case 7:
			{
				C.MonthlyPayment(Person);
				break;
			}

			case 8:
			{
				cout << "Enter the payment amount: " << endl;
				cin >> f;
				C.ExtraPayment(Person, f);
				break;
			}

			case 9:
			{
				z = 1;
				break;
			}

			case 10:
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
}