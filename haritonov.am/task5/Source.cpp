#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <algorithm>

#include <fstream>
using namespace std;

struct client
{
	int card;
	string name;
	int summ;
	int pin;
};

class processing_center
{
	friend class cash_machine;
	vector <client> base;
public:
	void add_client(int _card, string _name, int _summ, int _pin)
	{
		client buffer;
		buffer.card = _card;
		buffer.name = _name;
		buffer.summ = _summ;
		buffer.pin = _pin;
		base.push_back(buffer);
	}

};

class cash_machine
{
	int one_h = 1600;
	int two_h = 1600;
	int five_h = 1600;
	int one_th = 1600;
	int two_th = 1600;
	int five_th = 1600;
	int card = 0;
	int id;
public:

	void take_card(int _card, processing_center &YOTA)
	{
		int _pin;
		int i = 0;
		while (_card != YOTA.base[i].card) 	i++;
		id = i;
		cout << "Enter PIN" << endl;
		cin >> _pin;
		if (_pin == YOTA.base[i].pin) return;
		cout << endl << "Invalid PIN" << endl;
		cin >> _pin;
		if (_pin == YOTA.base[i].pin) return;
		cout << endl << "Invalid PIN" << endl;
		cin >> _pin;
		if (_pin == YOTA.base[i].pin) return;
		cout << endl << "Invalid PIN, card was blocked" << endl;
		card = 0;
	}

	client find_client(processing_center &YOTA)
	{
		return YOTA.base[id];
	}

	void balance(processing_center &YOTA)
	{
		cout << YOTA.base[id].summ << endl;
	}

	void add_sum(processing_center &YOTA)
	{
		int i = 0;
		int _summ = 1;
		cout << "You can put 100, 200, 500, 1000, 2000, 5000 or 0 to stop" << endl;
		while ((_summ != 0) && (i <= 40))
		{
			cin >> _summ;
			YOTA.base[id].summ += _summ;
			if (_summ == 100)
			{
				one_h++;
				if (one_h == 2000) break;
			}
			if (_summ == 200)
			{
				two_h++;
				if (two_h == 2000) break;
			}
			if (_summ == 500)
			{
				five_h++;
				if (five_h == 2000) break;
			}
			if (_summ == 1000) 
			{
				one_th++;
				if (one_th == 2000) break;
			}
			if (_summ == 2000) 
			{
				two_th++;
				if (two_th == 2000) break;
			}
			if (_summ == 5000) 
			{
				five_th++;
				if (five_th == 2000) break;
			}
		}
		if (_summ != 0) cout << "OVERFLOW!!!" << endl;
	}

	void take_sum(processing_center &YOTA)
	{
		int i = 0;
		int _summ = 1;
		cout << "You can take 100, 200, 500, 1000, 2000, 5000 or 0 to stop" << endl;
		while ((_summ != 0) && (i <= 40))
		{
			cin >> _summ;
			if (YOTA.base[id].summ - _summ < 0) break;
			YOTA.base[id].summ -= _summ;
			if (_summ == 100)
			{
				one_h--;
				if (one_h == 0) break;
			}
			if (_summ == 200)
			{
				two_h--;
				if (two_h == 0) break;
			}
			if (_summ == 500)
			{
				five_h--;
				if (five_h == 0) break;
			}
			if (_summ == 1000)
			{
				one_th--;
				if (one_th == 0) break;
			}
			if (_summ == 2000)
			{
				two_th--;
				if (two_th == 0) break;
			}
			if (_summ == 5000)
			{
				five_th--;
				if (five_th == 0) break;
			}
		}
		if (_summ != 0) 
			if (YOTA.base[id].summ - _summ < 0) cout << "insufficient funds on the account" << endl;
			else cout << "THE LACK OF BILLS!!!" << endl;
	}

	void pull_out_the_card()
	{
		card = 0;
		cout << "Card wad pulled out" << endl;
	}
};





int main()
{
	processing_center YOTA;
	cash_machine siemens;
	YOTA.add_client(0001, "name", 1000, 1111);
	YOTA.add_client(3001, "name", 1000, 1111);
	YOTA.add_client(2102, "name", 1000, 1111);
	YOTA.add_client(2713, "name", 1000, 1111);

	siemens.take_card(3001, YOTA);
	siemens.find_client(YOTA);
	siemens.balance(YOTA);
	siemens.add_sum(YOTA);
	siemens.balance(YOTA);
	siemens.take_sum(YOTA);
	siemens.balance(YOTA);
	siemens.pull_out_the_card();
	system("pause");
}