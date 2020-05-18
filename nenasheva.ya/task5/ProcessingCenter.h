#pragma once
#include <string>
#include <vector>
#include <Windows.h>
#include <iostream>
using namespace std;

struct UserData
{
	int num;
	string FIO;
	double salary_account;
	bool dep;
	string password;
	double deposit_account;
	double deposit_percent;
	int deposit_time_to_close_in_month;
};

class PC
{
public:
	string AddUser(string fio, double init_money, string password)
	{
		if (password.length() > 3)
		{
			UserData data;
			data.dep = false;
			data.FIO = fio;
			data.salary_account = init_money;
			data.num = data_base.size()+1;
			data.password = password;
			data.deposit_account = 1;
			data_base.push_back(data);
			data.deposit_percent = 0;
			return "Ваш номер счета: " + to_string(data.num);
		}
		else
		{
			return "Короткий пароль";
		}
	}
	vector<UserData> data_base;
};