#include <iostream> 
#include <clocale>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
class User
{
private:
	string cardnumber;
	string name;
	int cash;
	string pincode;
	bool block;
public:
	User()
	{
	};
	User( string _cardnumber, string _pincode, string _name ,int _cash)
	{
		cardnumber = _cardnumber;
		pincode = _pincode;
		name = _name;
		cash = _cash;
		block = true;
	}
	string GetCardNumber()
	{
		return cardnumber;
	}
	bool CheckPin(string _pin)
	{
		return _pin == pincode;
	}
	string GetName()
	{
		return name;
	}
	bool AddMoney(long newMoney)
	{
		if (!block || newMoney < 0)
		{
			return false;
		}
		cash += newMoney;
		return true;
	}
	bool  LooseMoney(long oldMoney)
	{
		if (!block || ((oldMoney < 0) && (block < oldMoney)))
		{
			return false;
		}
		cash -= oldMoney;
		return true;
	}
	int GetCash()
	{
		return cash;
	}
	void SetBlock(bool newblock)
	{
		block = newblock;
	}
	bool GetBlock()
	{
		return block;
	}
	User &operator=(const User& s)
	{
		if (this == &s)
			return *this;
		cardnumber = s.cardnumber;
		name = s.name;
		pincode = s.pincode;
		cash = s.cash;
		block = s.block;
	}
};
class ProcessingCenter
{
private:
	vector<User> users;
	int count;
public:
	ProcessingCenter()

	{

		count = 0;

		users = vector<User>();

		users.resize(1);

	};
	void AddClient(string cardNumber, string Pin, string FullName, int Sum)
	{
		User c(cardNumber, Pin, FullName, Sum);
		users.push_back(c);
	}
	bool CheckByPin(int i, string _pin)

	{
		if (users[i].CheckPin(_pin))
			return 1;
		return 0;
	}
	int FindByNumb(string _numb)
	{
		for (size_t i = 0; i < users.size(); i++)
			if (users[i].GetCardNumber() == _numb)
				return i;
		return -1;
	}
	bool CheckByNumb(string _numb)
	{
		for (size_t i = 0; i < users.size(); i++)
			if (users[i].GetCardNumber() == _numb)
				return 1;
		return 0;
	}
	bool RequestToLooseMoney(int i, long value)
	{
		return  users[i].LooseMoney(value);
	}
	bool RequestToAddMoney(int i, long value)
	{
		return  users[i].AddMoney(value);
	}
	void SetState(int i, bool newState)
	{
		users[i].SetBlock(newState);
	}
	bool GetState(int i)
	{
		return  users[i].GetBlock();
	}
	int CheckBalans(int i)
	{
		return	users[i].GetCash();
	}
};
class ATM
{
	int case100;
	int case200;
	int case500;
	int case1000;
	int case2000;
	int case5000;
	ProcessingCenter* PC;
	int i;
public:
	ATM(ProcessingCenter* pc)
	{
		case100 = 1600000;
		case200 = 1600000;
		case500 = 1600000;
		case1000 = 1600000;
		case2000 = 1600000;
		case5000 = 1600000;
		PC = pc;
	};
	bool FindUser(string _cardNumber)
	{

		i = PC->FindByNumb(_cardNumber);

		return PC->CheckByNumb(_cardNumber);

	}
	bool CheckPinCode(string _pinCode)
	{
		return PC->CheckByPin(i, _pinCode);
	}
	bool CheckState()
	{
		return PC->GetState(i);
	}
	bool BlockUser()
	{
		PC->SetState(i, false);
		return true;
	}
	int CheckBalance()
	{
		return PC->CheckBalans(i);
	}
	bool WithdrawMoney(int _case100, int _case200, int _case500, int _case1000, int _case2000, int _case5000)
	{
		bool tmp = 0;
		if ((case100 >= _case100) && (case200 >= _case200) && (case500 >= _case500) && (case1000 >= _case1000) && (case2000 >= _case2000) && (case5000 >= _case5000))
		{
			if ((_case100 + _case200 + _case500 + _case1000 + _case2000 + _case5000) <= 40)
			{
				int s = 100 * _case100 + 200 * _case200 + 500 * _case500 + 1000 * _case1000 + 2000 * _case2000 + 5000 * _case5000;
				if (PC->CheckBalans(i) >= s)
				{
					case100 -= _case100;
					case200 -= _case200;
					case500 -= _case500;
					case1000 -= _case1000;
					case2000 -= _case2000;
					case5000 -= _case5000;
					if (PC->RequestToLooseMoney(i, s))
						tmp = 1;
				}
			}
			else
				cout << "Превышен лимит купюр";
		}
		return tmp;
	}
	bool DepositMoney(int _case100, int _case200, int _case500, int _case1000, int _case2000, int _case5000)
	{
		bool tmp = 0;
		if ((case100 + _case100 <= 2000000) && (case200 + _case200 <= 2000000) && (case500 + _case500 <= 2000000) && (case1000 + _case1000 <= 2000000) && (case2000 + _case2000 <= 2000000) && (case5000 + _case5000 <= 2000000))
		{
			if ((_case100 + _case200 + _case500 + _case1000 + _case2000 + _case5000) <= 40)
			{
				int s = 100 * _case100 + 200 * _case200 + 500 * _case500 + 1000 * _case1000 + 2000 * _case2000 + 5000 * _case5000;
				case100 += _case100;
				case200 += _case200;
				case500 += _case500;
				case1000 += _case1000;
				case2000 += _case2000;
				case5000 += _case5000;
				if (PC->RequestToAddMoney(i, s))
					tmp = 1;
			}
			else 
				cout << "Превышен лимит купюр";
			return tmp;
		}
	}
};
void main()
{

	setlocale(LC_ALL, "Russian");
	ProcessingCenter PC;
	int n;
	PC.AddClient("0001", "1111", "Golovkin Nikita Kirillovich", 10000);
	PC.AddClient("0002", "2222", "Abad Daba Bydi", 15000);
	PC.AddClient("0003", "3333", "Gogi Gigy Tabat", 25000);
	ATM atm(&PC);
	int op;
	string s, p;
	bool
		menu1 = 1;
	int _case100;
	int _case200;
	int _case500;
	int _case1000;
	int _case2000;
	int _case5000;
	while (menu1)
	{
		bool flag = true;
		cout << "Вставьте карту: ";
		cin >> s;
		if (!atm.FindUser(s))
		{
			while (!atm.FindUser(s))
			{
				cout << "Ваша карта не принята!\n" << endl;
				cout << "Вставьте карту: \n" << endl;
				cin >> s;
			}
		}
		if (!atm.CheckState())
		{
			cout << "Операция не была выполнена. Ваша карта заблокирована! \n" << endl;
		}
			for (int i = 0; i < 3; i++)
			{
				cout << "Введите PIN" << endl;
				cin >> p;
				if (atm.CheckPinCode(p))
				{
					cout << "Ваша карта пинята! \n" << endl;
					flag = true;
					break;
				}
				else
				{
					cout << " PIN не корректный!\n" << endl;
					flag = false;
				}
			}
			if (flag == false)
			{
				cout << "Ваша карта заблокирована! \n" << endl;
				atm.BlockUser();
			}
		cout << "Выберите операцию\n" << endl;
		while (flag == true)
		{
			cout << "1 - Снять деньги со счета" << "\n" << endl;
			cout << "2 - Внести деньги на счет" << "\n" << endl;
			cout << "3 - Проверить баланс" << "\n" << endl;
			cout << "4 - Выйти" << "\n" << endl;
			cin >> op;
			switch (op)
			{
			case 1:
			{
				cout << "Enter 100: " << endl;
				cin >> _case100;
				cout << "Enter 200: " << endl;
				cin >> _case200;
				cout << "Enter 500: " << endl;
				cin >> _case500;
				cout << "Enter 1000: " << endl;
				cin >> _case1000;
				cout << "Enter 2000: " << endl;
				cin >> _case2000;
				cout << "Enter 5000: " << endl;
				cin >> _case5000;
				if (atm.WithdrawMoney(_case100, _case200, _case500, _case1000, _case2000, _case5000))
				{
					cout << "Успешно\n" << endl;
				}
				else
				{
					cout << "Сожалею. Операция в данный момент недоступна!" << endl;
				}
				break;
			}
			case 2:
			{
				cout << "Enter 100: " << endl;
				cin >> _case100;
				cout << "Enter 200: " << endl;
				cin >> _case200;
				cout << "Enter 500: " << endl;
				cin >> _case500;
				cout << "Enter 1000: " << endl;
				cin >> _case1000;
				cout << "Enter 2000: " << endl;
				cin >> _case2000;
				cout << "Enter 5000: " << endl;
				cin >> _case5000;
				if (atm.DepositMoney(_case100, _case200, _case500, _case1000, _case2000, _case5000))
				{
					cout << "Успешно\n" << endl;
				}
				else
				{
					cout << "Сожалею. Операция в данный момент недоступна!" << endl;
				}
				break;
			}
			case 3:
			{
				cout << atm.CheckBalance() << endl;
				break;
			}
			case 4:
			{
				flag = false;
			}
			}
		}
		}
}