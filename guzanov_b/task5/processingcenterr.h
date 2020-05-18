#pragma once
#include <iostream>
#include "string"
#include "stdlib.h"
#include <time.h>
#include <stdio.h>
using namespace std;
class processingcenter
{
private:
	string* name;
	int size;
	int* time;
	unsigned int count;
	string* number_of_salary_account;//номер счета
	int* information_about_credit;//номер варианта кредита
	string* password;
	int* money;//оставшаяся сумма кредита
	int* money_on_the_count;//сумма на счете
public:
	processingcenter(int size_ = 10)
	{
		size = size_;
		count = 0;
		time = new int[size];
		name = new string[size];
		number_of_salary_account = new string[size];
		information_about_credit = new int[size];
		password = new string[size];
		money = new int[size];
		money_on_the_count = new int[size];
		for (int i = 0; i < size; i++)
		{
			time[i] = 0;
			money[i] = 0;
			money_on_the_count[i] = 0;
		}
	}
	//processingcenter(string namefile);
	//void save(string namefile);
	processingcenter(const processingcenter& tmp)
	{
		size = tmp.size;
		count = tmp.count;
		time = new int[size];
		name = new string[size];
		number_of_salary_account = new string[size];
		information_about_credit = new int[size];
		password = new string[size];
		money = new int[size];
		money_on_the_count = new int[size];
		for (int i = 0; i < size; i++)
		{
			time[i] = tmp.time[i];
			number_of_salary_account[i] = tmp.number_of_salary_account[i];
			information_about_credit[i] = tmp.information_about_credit[i];
			password[i] = tmp.password[i];
			name[i] = tmp.name[i];
			money[i] = tmp.money[i];
			money_on_the_count[i] = tmp.money_on_the_count[i];
		}
	};
	~processingcenter()
	{
		delete[]number_of_salary_account;
		delete[]password;
		delete[]money;
		delete[]money_on_the_count;
		delete[]name;
		delete[]information_about_credit;
	}
	processingcenter& operator=(const processingcenter& tmp)
	{
		if (size != tmp.size)
		{
			if (size != 0)
			{
				delete[]time;
				delete[]number_of_salary_account;
				delete[]password;
				delete[]money;
				delete[]money_on_the_count;
				delete[]name;
				delete[]information_about_credit;
			}

			size = tmp.size;
			name = new string[size];
			time = new int[size];
			number_of_salary_account = new string[size];
			information_about_credit = new int[size];
			password = new string[size];
			money = new int[size];
			money_on_the_count = new int[size];
		}
		count = tmp.count;
		for (int i = 0; i < size; i++)
		{
			number_of_salary_account[i] = tmp.number_of_salary_account[i];
			information_about_credit[i] = tmp.information_about_credit[i];
			password[i] = tmp.password[i];
			name[i] = tmp.name[i];
			money[i] = tmp.money[i];
			money_on_the_count[i] = tmp.money_on_the_count[i];
		}
	};

	string add_client(string FIO, int Summa = 0)
	{
		int l = -1;
		int i = 0;
		while ((i < count) && (l == -1))
		{
			if (FIO == name[i])
			{
				l = i;
			}
			i++;
		}
		if (l == -1)
		{
			char c[10];
			for (int i = 0; i < 9; i++)
			{
				int l = (65 + i * (count + 1)) % 26 + 65;
				c[i] = l;
			}
			string pass = string(c);

			pass.erase(0, 1);
			pass.erase(8);
			name[count] = FIO;
			money_on_the_count[count] = Summa;
			money[count] = 0;
			information_about_credit[count] = 0;
			number_of_salary_account[count] = "100" + to_string(count);
			password[count++] = pass;
			return pass;
		}
		else
			return "error";
	}
	void base_out(string key)
	{
		if (key == "admin")
		{
			cout << "count = " << count << endl;
			for (int i = 0; i < count; i++)
			{
				cout << name[i] << "\t";
				cout << number_of_salary_account[i] << "\t";
				cout << information_about_credit[i] << "\t";
				cout << password[i] << "\t";
				cout << money[i] << "\t";
				cout << money_on_the_count[i] << "\t";
				cout << endl;
			}
			cout << endl;
		}
		else cout << "You have not rights" << endl;
	}
	int add_money(string FIO, string Password, int Sum)
	{
		int l = -1;
		int i = 0;
		while ((i < count) && (l == -1))
		{
			if ((FIO == name[i]) && (Password == password[i]))
			{
				l = i;
			}
			i++;
		}
		if (l > -1)
		{
			money_on_the_count[l] += Sum;
			return money_on_the_count[l];
		}
		else return -1;
	}
	int get_money(string FIO, string Password, int Sum)
	{
		int l = -1;
		int i = 0;
		while ((i < count) && (l == -1))
		{
			if ((FIO == name[i]) && (Password == password[i]))
			{
				l = i;
			}
			i++;
		}
		if ((l > -1) && (money_on_the_count[l] > Sum))
		{
			money_on_the_count[l] -= Sum;
			return money_on_the_count[l];
		}
		else return -1;
	}
	string serch(string FIO, string pass)
	{
		int l = -1;
		int i = 0;
		while ((i < count) && (l == -1))
		{
			if ((FIO == name[i]) && (pass == password[i]))
			{
				l = i;
			}
			i++;
		}
		if (l > -1)
		{
			return number_of_salary_account[l];
		}
		else return "-1";
	}
	int serch_number(string FIO, string pass)
	{
		int l = -1;
		int i = 0;
		while ((i < count) && (l == -1))
		{
			if ((FIO == name[i]) && (pass == password[i]))
			{
				l = i;
			}
			i++;
		}

		{
			return l;
		}



	};
	void add_money_credit(string FIO, string Password, int Sum)
	{
		int l = -1;
		int i = 0;
		while ((i < count) && (l == -1))
		{
			if ((FIO == name[i]) && (Password == password[i]))
			{
				l = i;
			}
			i++;
		}
		if (l > -1)
		{
			if (Sum < money[l])
			{
				money[l] -= Sum;
			}
			else
			{
				money_on_the_count[l] += Sum - money[l];
				money[l] = 0;

			}
		}
	};
	int is_credit(string FIO, string Pass)
	{
		int l = -1;
		int i = 0;
		while ((i < count) && (l == -1))
		{
			if (FIO == name[i])
			{
				l = i;
			}
			i++;
		}
		if ((l > -1) && (Pass == password[l]))
		{
			return money[l];
		}
		else return -1;
	}
	int issuance_of_credit(int L, int pr, int Sum, int time)
	{
		float fpr = pr;
		fpr = fpr / 100.0;
		if ((L > -1) && (money[L] == 0))
		{
			if (pr > -1)
			{
				int platez = 0;
				for (int i = 1; i < 7; i++)
				{
					platez += Sum * (fpr + (fpr / (1 + fpr) * i - 1));
				}
				if ((platez < money_on_the_count[L]))
				{
					int platez = 0;
					for (int i = 1; i < time * 12 + 1; i++)
					{
						platez += Sum * (fpr + (fpr / (1 + fpr) * i - 1));
					}
					money[L] = Sum + platez;
					money_on_the_count[L] += Sum;
				}
				else L = -1;
			}
		}
		return L;

	}
	int getdolg(int l)
	{
		return money[l];
	}
};



