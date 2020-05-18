#pragma once
#include "ProcessingCenter.h"

class Deposit
{
private:
	bool logged_in;
	int logged_user_acc_num;
	PC * proc_centre;
public:
	Deposit();
	~Deposit();
	void ConnectToProcessingCentre(PC * centre);
	int Get_Pay();
	bool Login(string account_num, string pswd);
	string Get_AvailableDeposits();
	string Get_SalaryAccountInfo();
	bool CheckExistingDeposit();
	bool OpenDeposit(int month, int init_sum);
	string Get_DepositInfo();
	string WidthrawPercents(unsigned int month_count);
	bool CloseDeposit();
	void Logout();
};