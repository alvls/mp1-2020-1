#include <iostream>
#include <clocale> 
#include <string>
#include <iomanip>
#include <vector>
int accnum = 1;
using namespace std;
class ProcessingCenter
{
public:
	vector<int> Time;
	vector<int> Salary;
	vector<int> Deposit;
	vector<string> FullName;
	vector<string> Password;
	vector<double> Percent;
	void SetData(string name, int deposit, int money, string password, int percen, int time)
	{
		FullName.push_back(name);
		Salary.push_back(money);
		Deposit.push_back(deposit);
		Password.push_back(password);
		Percent.push_back(percen);
		Time.push_back(time);
	}
	bool AuthorizationCheckNumber(int number)
	{
		if ((number < 1) || (number > FullName.size()))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool AuthorizationCheckPassword(int number, string &pin)
	{
		int n = pin.length();
		if (Password[number - 1].length() == n)
		{
			string pw = Password[number - 1];
			for (int i = 0; i <= n; i++)
			{
				if (pw[i] != pin[i])
					return false;
			}
			return true;
		}
		return false;
	}
	void OpenDeposit1(int amount, int time, int number)
	{
		double percent = 0;
		if (Salary[number - 1] < amount)
		{
			while (Salary[number - 1] < amount)
			{
				cout << "You are exaggerating a lot!" << endl;
				cin >> amount;
			}
		}
		Deposit[number - 1] = amount;
		Time[number - 1] = time;
		if (Deposit[number - 1] < 100000)
		{
			if (Time[number - 1] == 3)
				percent = 1.05;
			if (Time[number - 1] == 6)
				percent = 1.055;
			if (Time[number - 1] == 12)
				percent = 1.06;
			if (Time[number - 1] == 24)
				percent = 1.07;
			if (Time[number - 1] == 36)
				percent = 1.08;
		}
		if ((Deposit[number - 1] > 500000) && (Deposit[number - 1] < 100000))
		{
			if (Time[number - 1] == 3)
				percent = 1.055;
			if (Time[number - 1] == 6)
				percent = 1.06;
			if (Time[number - 1] == 12)
				percent = 1.07;
			if (Time[number - 1] == 24)
				percent = 1.075;
			if (Time[number - 1] == 36)
				percent = 1.085;
		}
		if ((Deposit[number - 1] > 500000) && (Deposit[number - 1] < 1000000))
		{
			if (Time[number - 1] == 3)
				percent = 1.06;
			if (Time[number - 1] == 6)
				percent = 1.065;
			if (Time[number - 1] == 12)
				percent = 1.07;
			if (Time[number - 1] == 24)
				percent = 1.08;
			if (Time[number - 1] == 36)
				percent = 1.09;
		}
		if (Deposit[number - 1] > 1000000)
		{
			if (Time[number - 1] == 3)
				percent = 1.073;
			if (Time[number - 1] == 6)
				percent = 1.08;
			if (Time[number - 1] == 12)
				percent = 1.09;
			if (Time[number - 1] == 24)
				percent = 1.1;
			if (Time[number - 1] == 36)
				percent = 1.116;
		}
		Percent[number - 1] = percent;
		Salary[number - 1] = Salary[number - 1] - Deposit[number - 1];
	}
	int FindOutDeposit(int number)
	{
		return Deposit[number - 1];
	}
	int Operations(int number, int time)
	{
		int dep = Percent[number - 1] * Deposit[number - 1] * time;
		Time[number - 1] = Time[number - 1] - time;
		Deposit[number - 1] = dep;
		return Time[number - 1];
	}
	void WithdrawnIterest(int number, int amount)
	{
		Salary[number - 1] += Deposit[number - 1] - amount;
		Deposit[number - 1] = amount;
	}
	int FindTime(int number)
	{
		return Time[number - 1];
	}
	double FindPercent(int number)
	{
		return Percent[number - 1];
	}
	int FindSalary(int number)
	{
		return Salary[number - 1];
	}
	void CloseDeposit(int number)
	{
		Deposit[number - 1] = -1;
		Percent[number - 1] = 0;
		Time[number - 1] = -1;
	}
};
class Deposit :public ProcessingCenter
{
	int number;
public:
	Deposit()
	{
		number = 0;
	}
	Deposit(int num)
	{
		number = num;
	}
	Deposit(const Deposit &object)
	{
		number = object.number;
	}
	void Registration()
	{
		string name, surname, patronymic, pin;
		string fullname = "";
		int  salary1 = 0;
		cout << "Enter full name." << endl;
		cout << "Name: ";
		cin >> name;
		name += " ";
		fullname += name;
		cout << "Surname: ";
		cin >> surname;
		surname += " ";
		fullname += surname;
		cout << "Patronymic: ";
		cin >> patronymic;
		fullname += patronymic;
		cout << "Enter password(at least 3 characters) :" << endl;
		cin >> pin;
		while (pin.length() < 3)
		{
			cout << "I thought we understood each other, and you ..." << endl;
			cout << "Enter password(at least 3 characters) :" << endl;
			cin >> pin;
		}
		cout << "Enter your salary:" << endl;
		cin >> salary1;
		SetData(fullname, -1, salary1, pin, -1, -1);
		//cout<< "Size"<<FullName.size();
		cout << setfill('0') << setw(4) << accnum << "-It is your registration number. " << endl;
		if (accnum > 9999)
		{
			throw ">9999";
		}
		accnum++;
	}
	int  Authorization()
	{
		string password1 = "";
		int login = 0;
		cout << "Enter account number: " << endl;
		cin >> login;
		while (AuthorizationCheckNumber(login) != true)
		{
			cout << "Enter account number:" << endl;
			cin >> login;
		}
		login;
		cout << "Enter password:" << endl;
		cin >> password1;
		while (AuthorizationCheckPassword(login, password1) != true)
		{
			cout << "Enter password:" << endl;
			cin >> password1;
		}
		number = login;
		return login;
	}
	void InformationAboutDiposit()
	{
		cout << "Available deposits to you :" << endl;
		if (FindOutDeposit(number) < 100000)
		{
			cout << " 1)3 months - 5% \n 2)6 months - 5,5% \n 3)1 year(12 months) - 6% \n 4)2 years(24 months) - 7% \n 5)3 years(36 months) - 8% " << endl;
		}
		if ((FindOutDeposit(number) > 100000) && (FindOutDeposit(number) < 500000))
		{
			cout << " 1)3 months - 5,5%% \n 2)6 months - 6% \n 3)1 year(12 months) - 7% \n 4)2 years(24 months) - 7,5% \n 5)3 years(36 months) - 8,5% " << endl;
		}
		if ((FindOutDeposit(number) > 500000) && (FindOutDeposit(number) < 1000000))
		{
			cout << " 1)3 months - 6% \n 2)6 months - 6,5% \n 3)1 year(12 months) - 7% \n 4)2 years(24 months) - 8% \n 5)3 years(36 months) - 9% " << endl;
		}
		if (FindOutDeposit(number) > 1000000)
		{
			cout << " 1)3 months - 7,3% \n 2)6 months - 8% \n 3)1 year(12 months) - 9% \n 4)2 years(24 months) - 10% \n 5)3 years(36 months) - 11,6% " << endl;
		}
	}
	bool ÑheckOpen()
	{
		if (FindOutDeposit(number) == -1)
			return false;
		else
			return true;
	}
	void OpenDeposit()
	{
		int n = 0, quantity = 0;
		cout << "Enter a  3 or 6 or 12 or 24 or 36 depending on the chosen period :" << endl;
		cin >> n;
		while ((n != 3) && (n != 6) && (n != 12) && (n != 24) && (n != 36))
		{
			cout << "You made a mistake,but I'm giving you a chance." << endl;
			cin >> n;
		}
		cout << "How much money do you want to allocate?" << endl;
		cin >> quantity;
		OpenDeposit1(quantity, n, number);
	}
	void GetDepositStatus()
	{
		cout << "The number of remaining months :" << FindTime(number) << endl << "Interest rate :" << (FindPercent(number) * 100) - 100 << " %" << endl;
		cout << "Money are lying on account now :" << FindOutDeposit(number) << endl;
		cout << "Salary account :" << FindSalary(number) << endl;
	}
	int Withdraw(int time, int amount)
	{
		int b = Operations(number, time);
		WithdrawnIterest(number, amount);
		return b;
	}
	void CloseDeposit1()
	{
		CloseDeposit(number);
	}
};
int main()
{
	Deposit Client;
	int type = 0, choice = 0;
	int period = 0;
	do
	{
		int n = 0;
		int d = 0;
		while ((n < 1) || (n > 2))
		{
			cout << "What do you want to do?\n 1-Register customer.\n 2-Log in." << endl;
			cin >> n;
		}
		switch (n)
		{
		case 1:
		{
			Client.Registration();
			break;
		}
		case 2:
		{

			int number = 0;
			number = Client.Authorization();
			do
			{

				d = 0;
				choice = 0;
				while ((choice < 1) || (choice > 6))
				{
					cout << "What do you want to do?\n 1 -I want to know:Do I have open deposit?\n 2 -I want to open a deposit.\n 3 -I want to know deposit status.\n 4 -I want to remove interest.\n 5 -I want to close deposit.\n 6 -I want to completion  work." << endl;
					cin >> choice;
				}
				switch (choice)
				{
				case 1:
				{
					if (Client.ÑheckOpen() == true)
					{
						cout << "Deposit was open on." << endl;
					}
					else
					{
						cout << "Deposit  not was open." << endl;
					}
					break;
				}
				case 2:
				{
					if (Client.ÑheckOpen() == true)
					{
						cout << "Deposit was open already." << endl;
					}
					else
					{
						cout << "Information about interest rates: " << endl;
						Client.InformationAboutDiposit();
						Client.OpenDeposit();
					}
					break;
				}
				case 3:
				{
					Client.GetDepositStatus();
					break;
				}
				case 4:
				{
					int month = -1;
					period = Client.FindTime(number);
					int n = Client.FindOutDeposit(number);
					while ((month < 0) || (month > period))
					{
						cout << "How many months have passed?" << endl;
						cin >> month;
					}
					period = Client.Withdraw(month, n);
					if (period = 0)
					{
						cout << "Time is over!Deposit was closed!" << endl;
					}
					break;
				}
				case 5:
				{
					if (period >= Client.FindTime(number))
					{
						Client.CloseDeposit1();
						cout << "Time is over!Deposit was closed!" << endl;
					}
					else
						cout << "Time is not over yet!" << endl;
					break;
				}
				case 6:
				{
					d = 122;
					break;
				}
				}
			} while (d == 0);
		}
		}
		cout << " Do you want to finish the work?/n1-yes, 0-no" << endl;
		cin >> type;
		while ((type != 0) && (type != 1))
		{
			cout << ("Enter  0 or 1.\n");
			cin >> type;
		}
	} while (type == 0);
	system("pause");
	return 0;
}