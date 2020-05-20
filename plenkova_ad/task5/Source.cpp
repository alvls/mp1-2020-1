#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <iostream> 
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

class ProcessingCenter
{
	vector <int> AccountNumber;
	vector <string> Name;
	vector <int> Balance;
	vector <string> Password;
	vector <int> CreditAmount;
	int PersonAccountNumber;
	string PersonName;
	int PersonBalance;
	string PersonPassword;
	int PersonCreditAmount;

public:
	double MP = 0;
	ProcessingCenter()
	{
		PersonAccountNumber = 0;
		PersonName = " ";
		PersonBalance = 0;
		PersonPassword = " ";
		PersonCreditAmount = 0;
	};

	ProcessingCenter(int _number, string _name, int _balance, string _password, int _creditamount)
	{
		PersonAccountNumber = _number;
		PersonName = _name;
		PersonBalance = _balance;
		PersonPassword = _password;
		PersonCreditAmount = _creditamount;
		AccountNumber.push_back(PersonAccountNumber);
		Name.push_back(PersonName);
		Balance.push_back(PersonBalance);
		Password.push_back(PersonPassword);
		CreditAmount.push_back(PersonCreditAmount);
	};

	~ProcessingCenter() {};

	void SetPassword(string _password)
	{
		PersonPassword = _password;
	}
	string GetPasword()
	{
		return PersonPassword;
	}

	void SetPerson(string _name, string _password, int _balance, int _number)
	{
		PersonName = _name;
		PersonPassword = _password;
		PersonBalance = _balance;
		PersonAccountNumber = _number;
		PersonCreditAmount = 0;
	}
	void ShowPerson()
	{
		int a = PersonAccountNumber;
		int k = 0;
		while (a != 0)
		{
			a = a / 10;
			k++;
		}
		cout << "Name: " << PersonName << endl;
		cout << "Account number: ";
		if (k == 4) cout << PersonAccountNumber << endl;
		if (k == 3) cout << "0" << PersonAccountNumber << endl;
		if (k == 2) cout << "00" << PersonAccountNumber << endl;
		if (k == 1) cout << "000" << PersonAccountNumber << endl;
		cout << "Balance: " << PersonBalance << endl;
	}

	void SetName(string _name)
	{
		PersonName = _name;
	}


	int GetPersonBalance()
	{
		return PersonBalance;
	}
	int GetBalance(ProcessingCenter& PERSON)
	{
		for (int i = 0; i < AccountNumber.size(); i++)
		{
			if (PERSON.GetNumber() == AccountNumber[i])
			{
				return Balance[i];
			}
			else
				cout << "This account number doesn't exist!" << endl;
		}
	}


	int GetNumber()
	{
		return PersonAccountNumber;
	}


	void ShowCreditAmount(int i)
	{
		for (i = 0; i < CreditAmount.size(); i++) {
			cout << CreditAmount[i] << " ";
		}
	}
	int GetPersonCreditAmount()
	{
		return PersonCreditAmount;
	}
	int GetCreditAmount(ProcessingCenter& PERSON)
	{
		for (int i = 0; i < CreditAmount.size(); i++)
		{
			if (PERSON.GetNumber() == AccountNumber[i])
			{
				return CreditAmount[i];
			}
			else
				cout << "This account number doesn't exist!" << endl;
		}

	}
	void SetCredit(ProcessingCenter& PERSON, int _sum)
	{
		for (int i = 0; i < AccountNumber.size(); i++)
		{
			if (PERSON.GetNumber() == AccountNumber[i])
			{
				PERSON.CreditAmount[i] = _sum;
			}

		}
	}
	void SetCreditPayment(ProcessingCenter& PERSON, int _payment)
	{
		for (int i = 0; i < AccountNumber.size(); i++)
			if (PERSON.GetNumber() == AccountNumber[i])
			{

				PERSON.CreditAmount[i] = PERSON.CreditAmount[i] - _payment;
				PERSON.Balance[i] = PERSON.Balance[i] - _payment;
			}

	}

	bool SearchPerson(int _num)
	{
		for (int i = 0; i < AccountNumber.size(); i++)
			if (_num == AccountNumber[i])
			{
				cout << "Hello! " << Name[i] << endl;
				SetPerson(Name[i], Password[i], Balance[i], AccountNumber[i]);
				return true;
			}
			else
			{
				cout << "This account number doesn't exist!" << endl;
				return false;
			}
	}

	void SetMP(double _MP) { MP = _MP; }
	double GetMP() { return MP; }
};

class Credit
{
public:
	Credit() {};
	~Credit() {};

	double Percent[8] = { 0.05, 0.07, 0.1, 0.11, 0.13, 0.15, 0.17, 0.2 };

	void Authorization(ProcessingCenter& PERSON)
	{
		string pas;
		int num;
		cout << "Enter account number" << endl;
		cin >> num;
		if (PERSON.SearchPerson(num) == true)
		{
			cout << "Enter password" << endl;
			cin >> pas;
			while (pas != PERSON.GetPasword())
			{
				cout << "Wrong pasword! Repeat" << endl;
				cin >> pas;
			}
			cout << "Welcome to the 'Credit' system!" << endl;
		}
	}

	void AvailableCredits(ProcessingCenter& PERSON)
	{
		cout << "Avialable credits: " << endl;
		if (PERSON.GetPersonBalance() > 0)
		{
			cout << "From 100.000 rub" << endl;

			if (PERSON.GetPersonBalance() > 100000)
			{
				cout << "From 100.000 to 500.000 rub" << endl;

				if (PERSON.GetPersonBalance() > 500000)
				{
					cout << "From 500.000 to 1.000.000 rub" << endl;

					if (PERSON.GetPersonBalance() > 1000000)
					{
						cout << "From 1.000.000 to 3.000.000 rub" << endl;

					}
				}
			}
		}
	}

	void CheckCredits(ProcessingCenter& PERSON)
	{
		if (PERSON.GetPersonCreditAmount() == 0)
		{
			cout << "You haven't open credit" << endl;
		}
		else
			cout << "You have open credit" << endl << "You credit = " << PERSON.GetCreditAmount(PERSON) << endl;
	}

	void CheckCreditReceive(ProcessingCenter& PERSON, int _sum, int _time)
	{
		double pct = 0;
		int p = PERSON.GetNumber();
		if ((_sum > 0) || (_sum < 100000))
		{
			if (_time == 1) pct = Percent[3];
			if (_time == 2) pct = Percent[4];
			if (_time == 3) pct = Percent[5];
			if (_time == 5) pct = Percent[6];
			if (_time == 15) pct = Percent[7];
		};
		if ((_sum > 100000) || (_sum < 500000))
		{
			if (_time == 1) pct = Percent[2];
			if (_time == 2) pct = Percent[3];
			if (_time == 3) pct = Percent[4];
			if (_time == 5) pct = Percent[5];
			if (_time == 15) pct = Percent[6];
		};
		if ((_sum > 500000) || (_sum < 1000000))
		{
			if (_time == 1) pct = Percent[1];
			if (_time == 2) pct = Percent[2];
			if (_time == 3) pct = Percent[3];
			if (_time == 5) pct = Percent[4];
			if (_time == 15) pct = Percent[5];
		};
		if ((_sum > 1000000) || (_sum < 3000000))
		{
			if (_time == 1) pct = Percent[0];
			if (_time == 2) pct = Percent[1];
			if (_time == 3) pct = Percent[2];
			if (_time == 5) pct = Percent[3];
			if (_time == 15) pct = Percent[4];
		};
		cout << "You take credit " << _sum << " rub at " << pct * 100 << "% per year" << endl;


		double MP = (_sum * (1 + pct)) / (_time * 12.0);
		cout << MP << endl;
		double MP6 = 6 * MP;
		PERSON.SetMP(MP);
		cout << PERSON.GetMP();
		if (PERSON.GetPersonBalance() >= MP6)
		{
			cout << "Credit approved" << endl;
			PERSON.SetCredit(PERSON, _sum * (1 + pct));
		}
		else
			cout << "Credit not approved" << endl;
	}

	void CreditStatus(ProcessingCenter& PERSON)
	{
		if (PERSON.GetCreditAmount(PERSON) == 0) cout << "Credit closed" << endl;
		else
			cout << "Credit left to repay: " << PERSON.GetCreditAmount(PERSON);
	}

	void CreditPayment(ProcessingCenter& PERSON, int _time)
	{
		int payment = _time * PERSON.GetMP();
		int balance = PERSON.GetBalance(PERSON) - payment;
		if (balance < 0)
			cout << "You can't repay credit for this time" << endl;
		else
			PERSON.SetCreditPayment(PERSON, payment);
	}

	void CloseCredit(ProcessingCenter& PERSON)
	{
		if ((PERSON.GetBalance(PERSON) - PERSON.GetCreditAmount(PERSON)) >= 0)
		{
			PERSON.SetCreditPayment(PERSON, PERSON.GetCreditAmount(PERSON));
			cout << "Credit closed" << endl;
		}
	}
};

int main()
{
	int num, balance, time, sum = 0;
	string pas;
	string name;
	Credit Credit1;
	int Choice1 = 1;

	cout << "Hello!";

	cout << "Enter account number from 0001 to 9999" << endl;
	cin >> num;
	while (num < 1 || num > 9999)
	{
		cout << "This number doesn't exist!" << endl;
		cout << "Enter account number from 0001 to 9999" << endl;
		cin >> num;
	}
	cout << "Enter your name" << endl;
	getchar();
	getline(cin, name);

	cout << "Enter password (more then 3 symbols)" << endl;
	getline(cin, pas);
	while (pas.length() < 4)
	{
		cout << "This password is wrong! Password must be more then 3 symbols" << endl;
		getline(cin, pas);
	}

	cout << "Enter balance on your account number" << endl;
	cin >> balance;
	while (balance < 0)
	{
		cout << "Value is less than zero! Repeat, please" << endl;
		cin >> balance;
	}
	system("cls");
	ProcessingCenter Person1(num, name, balance, pas, 1);
	Person1.ShowPerson();


	while (Choice1 != 0)
	{
		cout << endl << "Ñhoose next" << endl << "1 - Registration" << endl << "2 - Authorization" << endl << "3 - Available credits" << endl << "4 - Check for credit" << endl << "5 - Check and get the selected credit" << endl << "6 - Repay part of credit" << endl << "7 - Show credit status" << endl << "8 - Fully repay the credit" << endl << "0 - Exit" << endl << endl;
		cin >> Choice1;
		switch (Choice1)
		{
		case 1:
		{
			cout << "Enter account number from 0001 to 9999" << endl;
			cin >> num;
			while (num < 1 || num > 9999)
			{
				cout << "This number doesn't exist!" << endl;
				cout << "Enter account number from 0001 to 9999" << endl;
				cin >> num;
			}
			cout << "Enter your name" << endl;
			getchar();
			getline(cin, name);

			cout << "Enter password (more then 3 symbols)" << endl;
			getline(cin, pas);
			while (pas.length() < 4)
			{
				cout << "This password is wrong! Password must be more then 3 symbols" << endl;
				getline(cin, pas);
			}

			cout << "Enter balance on your account number" << endl;
			cin >> balance;
			while (balance < 0)
			{
				cout << "Value is less than zero! Repeat, please" << endl;
				cin >> balance;
			}
			system("cls");
			ProcessingCenter Person1(num, name, balance, pas, 1);
			Person1.ShowPerson();
		}
		break;
		case 2:
		{
			Credit1.Authorization(Person1);
		}
		break;
		case 3:
		{
			Credit1.AvailableCredits(Person1);
		}
		break;
		case 4:
		{
			Credit1.CheckCredits(Person1);
		}
		break;
		case 5:
		{
			cout << "Choose how many years you want to take credit" << endl << "1 - 1 year" << endl << "2 - 2 years" << endl << "3 - 3 years" << endl << "5 - 5 years" << endl << " 15 - 15 years" << endl;
			cin >> time;
			cout << "Enter credit amount" << endl;
			cin >> sum;
			Credit1.CheckCreditReceive(Person1, sum, time);
		}
		break;
		case 6:
		{
			int deltatime;
			cout << "How many months have passed?" << endl;
			cin >> deltatime;
			Credit1.CreditPayment(Person1, deltatime);
		}
		break;
		case 7:
		{
			Credit1.CreditStatus(Person1);
		}
		break;
		case 8:
		{
			Credit1.CloseCredit(Person1);
		}
		break;
		case 0:
		{
			Choice1 = 0;
		}
		}

	}
};