#include "Deposit.h"

Deposit::Deposit()
{
	logged_in = false;
	logged_user_acc_num = 0;
	proc_centre = NULL;
}

Deposit::~Deposit()
{
}

void Deposit::ConnectToProcessingCentre(PC * centre)
{
	proc_centre = centre;
}

int Deposit::Get_Pay()
{
	return proc_centre->data_base[logged_user_acc_num].salary_account;
}

bool Deposit::Login(string account_num, string pswd)
{
	int ac_num = 1;
	try
	{
		ac_num = stoi(account_num);
	}
	catch (...)
	{
		return false;
	}
	if ((ac_num > 0) && (ac_num < 10000) && (ac_num < proc_centre->data_base.size()+1))
	{
		if (proc_centre->data_base[ac_num-1].password == pswd)
		{
			logged_in = true;
			logged_user_acc_num = ac_num-1;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	return false;
}

string Deposit::Get_AvailableDeposits()
{
	if (!logged_in)
		return "Error 404";
	else
	{
		string result = "";
		result += "Сейчас у вас на счёте " + to_string(Get_Pay()) + " руб.\n";
		result += "Доступные депозиты\n";
		result += "Период:\t\t\tПроцент:\n";
		int current_money = Get_Pay();
		if (0 < current_money && current_money < 100000)
			result += "3 месяца\t\t1,2%\n6 месяцев\t\t1,4%\n12 месяцев\t\t1,8%\n24 месяца\t\t2,0%\n36 месяцев\t\t2,2%\n";
		else if (100000 <= current_money && current_money < 500000)
			result += "3 месяца\t\t1,8%\n6 месяцев\t\t2,2%\n12 месяцев\t\t2,6%\n24 месяца\t\t2,8%\n36 месяцев\t\t3,2%\n";
		else if (500000 <= current_money && current_money < 1000000)
			result += "3 месяца\t\t2,9%\n6 месяцев\t\t3,2%\n12 месяцев\t\t3,5%\n24 месяца\t\t3,8%\n36 месяцев\t\t4,0%\n";
		else if (current_money >= 1000000)
			result += "3 месяца\t\t4,2%\n6 месяцев\t\t4,5%\n12 месяцев\t\t4,9%\n24 месяца\t\t5,3%\n36 месяцев\t\t5,7%\n";
		else
			result += "Вы не можете открыть депозит.";
		return result;
	}
}

string Deposit::Get_SalaryAccountInfo()
{
	if (!logged_in)
		return "Error 404";
	string s = "На зарплатном счету пользователя " + to_string((int)proc_centre->data_base[logged_user_acc_num].salary_account) + " руб.";
	return s;
}


bool Deposit::CheckExistingDeposit()
{
	return proc_centre->data_base[logged_user_acc_num].dep;
}

bool Deposit::OpenDeposit(int month, int init_sum)
{
	if (!logged_in)
		return false;
	if (CheckExistingDeposit())
		return false;

	if (init_sum > proc_centre->data_base[logged_user_acc_num].salary_account)
	{
		return false;
	}
	double current_percent = 0;
	if (month == 3)
	{
		if ((0 < init_sum) && (init_sum < 100000))
			current_percent = 1.2;
		else if ((100000 <= init_sum) && (init_sum < 500000))
			current_percent = 1.8;
		else if ((500000 <= init_sum) && (init_sum < 1000000))
			current_percent = 2.9;
		else
			current_percent = 3.2;
	}
	else if (month == 6)
	{
		if ((0 < init_sum) && (init_sum < 100000))
			current_percent = 1.4;
		else if ((100000 <= init_sum) && (init_sum < 500000))
			current_percent = 2.2;
		else if ((500000 <= init_sum) && (init_sum < 1000000))
			current_percent = 3.2;
		else
			current_percent = 4.5;
	}
	else if (month == 12)
	{
		if ((0 < init_sum) && (init_sum < 100000))
			current_percent = 1.8;
		else if ((100000 <= init_sum) && (init_sum < 500000))
			current_percent = 2.6;
		else if ((500000 <= init_sum) && (init_sum < 1000000))
			current_percent = 3.5;
		else
			current_percent = 4.9;
	}
	else if (month == 24)
	{
		if ((0 < init_sum) && (init_sum < 100000))
			current_percent = 2.0;
		else if ((100000 <= init_sum) && (init_sum < 500000))
			current_percent = 2.8;
		else if ((500000 <= init_sum) && (init_sum < 1000000))
			current_percent = 3.8;
		else
			current_percent = 5.3;
	}
	else if (month == 36)
	{
		if ((0 < init_sum) && (init_sum < 100000))
			current_percent = 2.2;
		else if ((100000 <= init_sum) && (init_sum < 500000))
			current_percent = 2.8;
		else if ((500000 <= init_sum) && (init_sum < 1000000))
			current_percent = 4.0;
		else
			current_percent = 5.7;
	}
	else
	{
		return false;
	}
	proc_centre->data_base[logged_user_acc_num].deposit_time_to_close_in_month = month;
	proc_centre->data_base[logged_user_acc_num].deposit_percent = current_percent;
	proc_centre->data_base[logged_user_acc_num].deposit_account = init_sum;

	proc_centre->data_base[logged_user_acc_num].salary_account -= init_sum;
	proc_centre->data_base[logged_user_acc_num].dep = true;
	return true;
}

string Deposit::Get_DepositInfo()
{
	string result = "";
	if (!logged_in)
	{
		result += "Error 404.";
	}
	if (!CheckExistingDeposit())
	{
		result += "У вас нет открытых депозитов.";
	}
	else
	{
		result += "На вашем депозите " + to_string(proc_centre->data_base[logged_user_acc_num].deposit_account) + " руб.\n";
		result += "Годовая процентная ставка: " + to_string(proc_centre->data_base[logged_user_acc_num].deposit_percent) + "\n";
		result += "До окончания срока действия депозита " + to_string(proc_centre->data_base[logged_user_acc_num].deposit_time_to_close_in_month) + " мес.";
	}	

	return result;
}

string Deposit::WidthrawPercents(unsigned int month_count)
{
	if (!logged_in)
		return "Error 404.";

	string result = "";
	if (month_count > proc_centre->data_base[logged_user_acc_num].deposit_time_to_close_in_month)
		month_count = proc_centre->data_base[logged_user_acc_num].deposit_time_to_close_in_month;

	double percents = proc_centre->data_base[logged_user_acc_num].deposit_percent/100.0 *
					  proc_centre->data_base[logged_user_acc_num].deposit_account / 12.0 * month_count;
	result += "Начислено: " + to_string(percents) + " руб.";
	proc_centre->data_base[logged_user_acc_num].salary_account += percents;
	proc_centre->data_base[logged_user_acc_num].deposit_time_to_close_in_month -= month_count;
	return result;
}

bool Deposit::CloseDeposit()
{
	if (!logged_in)
		return false;
	if (!CheckExistingDeposit())
		return false;
	if (proc_centre->data_base[logged_user_acc_num].deposit_time_to_close_in_month != 0)
		return false;
	else
	{
		proc_centre->data_base[logged_user_acc_num].salary_account = proc_centre->data_base[logged_user_acc_num].deposit_account;
		proc_centre->data_base[logged_user_acc_num].deposit_account = 0;
		proc_centre->data_base[logged_user_acc_num].dep = false;
		proc_centre->data_base[logged_user_acc_num].deposit_percent = 0;
		return true;
	}
}

void Deposit::Logout()
{
	logged_in = false;
	logged_user_acc_num = -1;
}