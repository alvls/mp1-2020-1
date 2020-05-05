#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include <iostream>
#include "stdio.h"
#include <iomanip>
#include <vector>
using namespace std;
struct ticket
{
	int day = 0;
	int month = 0;
	int year = 0;
	int trainnum = 0;
	string vagontype;
	int vagonnum = 0;
	int seatnum = 0;
	int upseatnum = 0;
	int downseatnum = 0;
	string name;
	string first;
	string last;
};

class Std
{
public:
	int vagnum;
	int freeseats = 100;
	vector<bool> seat;
	string* name;
	Std()
	{
		name = new string[100];
		for (int k = 0; k < 100; k++)
		{
			seat.push_back(0);
		}
	}
	Std(const Std& a)
	{
		name = new string[100];
		for (int k = 0; k < 100; k++)
		{
			name[k] = a.name[k];
			seat.push_back(a.seat[k]);
		}
		freeseats = a.freeseats;
		vagnum = a.vagnum;

	}
	Std& Std::operator=(const Std& other)
	{
		if (this != &other)
		{
			for (int k = 0; k < 100; k++)
			{
				name[k] = other.name[k];
				seat[k] = other.seat[k];
			}
			freeseats = other.freeseats;
			vagnum = other.vagnum;
		}
		return *this;
	}
	friend class Day;
	friend class TicketOffice;
};
class qupe
{
public:
	int vagnum;
	int freeupseats = 18;
	int freedownseats = 18;
	string* upname;
	string* downname;
	vector <bool> upseat;
	vector <bool>downseat;
	qupe()
	{
		upname = new string[18];
		downname = new string[18];

		for (int k = 0; k < 18; k++)
		{
			downseat.push_back(false);
			upseat.push_back(false);
		}
	}
	qupe(const qupe& a)
	{
		upname = new string[18];
		downname = new string[18];
		for (int k = 0; k < 18; k++)
		{
			downseat.push_back(a.downseat[k]);
			upseat.push_back(a.upseat[k]);
			downname[k] = a.downname[k];
			upseat[k] = a.upseat[k];
		}
		freedownseats = a.freedownseats;
		freeupseats = a.freeupseats;
		vagnum = a.vagnum;
	}
	qupe& qupe::operator=(const qupe& other)
	{
		if (this != &other)
		{
			for (int k = 0; k < 18; k++)
			{
				downname[k] = other.downname[k];
				upname[k] = other.upname[k];
				downseat[k] = other.downseat[k];
				upseat[k] = other.upseat[k];
			}
			freedownseats = other.freedownseats;
			freeupseats = other.freeupseats;
			vagnum = other.vagnum;
		}
		return *this;
	}

	friend class Day;
	friend class TicketOffice;
};
class plaz
{
public:
	int vagnum;
	int freeupseats = 27;
	int freedownseats = 27;
	vector<bool> upseat;
	string* upname;
	vector<bool> downseat;
	string* downname;
	plaz()
	{
		upname = new string[27];
		downname = new string[27];
		for (int k = 0; k < 27; k++)
		{
			downseat.push_back(false);
			upseat.push_back(false);
		}
	}
	plaz(const plaz& a)
	{
		upname = new string[27];
		downname = new string[27];
		for (int k = 0; k < 27; k++)
		{
			upname[k] = a.upname[k];
			downname[k] = a.downname[k];
			downseat.push_back(a.downseat[k]);
			upseat.push_back(a.upseat[k]);
		}
		freedownseats = a.freedownseats;
		freeupseats = a.freeupseats;
		vagnum = a.vagnum;
	}
	plaz& plaz::operator=(const plaz& other)
	{
		if (this != &other)
		{
			for (int k = 0; k < 27; k++)
			{
				downname[k] = other.downname[k];
				downseat[k] = other.downseat[k];
				upname[k] = other.upname[k];
				upseat[k] = other.upseat[k];
			}
			freedownseats = other.freedownseats;
			freeupseats = other.freeupseats;
			vagnum = other.vagnum;
		}
		return *this;
	}
	friend class Day;
	friend class TicketOffice;
};
class sv
{

public:
	int vagnum;
	int freedownseats = 18;
	vector<bool> downseat;
	string* downname;
	sv()
	{
		downname = new string[18];
		for (int k = 0; k < 18; k++)
		{
			downseat.push_back(false);
		}
	}
	sv(const sv& a)
	{
		downname = new string[18];
		for (int k = 0; k < 18; k++)
		{
			downname[k] = a.downname[k];
			downseat.push_back(a.downseat[k]);
		}
		freedownseats = a.freedownseats;
		vagnum = a.vagnum;
	}
	sv& sv::operator=(const sv& other)
	{
		if (this != &other)
		{
			for (int k = 0; k < 18; k++)
			{
				downname[k] = other.downname[k];
				downseat[k] = other.downseat[k];
			}
			freedownseats = other.freedownseats;
			vagnum = other.vagnum;
		}
		return *this;
	}

	friend class Day;
	friend class TicketOffice;
};
class Day
{
public:
	//////////////////////////////////////////////////////////////
	struct last
	{
		bool napr = false;
		int number;
		vector<Std> STDvagon;
	};
	struct brand
	{
		bool napr = false;
		int number;
		vector<sv> SVvagon;
		vector<qupe> QUPEvagon;
		vector<plaz> PLAZvagon;
	};
	struct fst
	{
		bool napr = false;
		int number;
		vector<qupe> QUPEvagon;
		vector<plaz> PLAZvagon;
	};
	//////////////////////////////////////////////////////////////
	last lastochka[6];
	brand firmed[2];
	fst fast[2];
	Std tmpstd;
	plaz tmpplaz;
	sv tmpsv;
	qupe tmpqupe;
	//////////////////////////////////////////////////////////////
	Day()
	{
		for (int k = 0; k < 8; k++)
		{
			lastochka[0].STDvagon.push_back(tmpstd);
			lastochka[1].STDvagon.push_back(tmpstd);
			lastochka[2].STDvagon.push_back(tmpstd);
			lastochka[3].STDvagon.push_back(tmpstd);
			lastochka[4].STDvagon.push_back(tmpstd);
			lastochka[5].STDvagon.push_back(tmpstd);
			fast[0].PLAZvagon.push_back(tmpplaz);
			fast[1].PLAZvagon.push_back(tmpplaz);
		}
		for (int k = 0; k < 2; k++)
		{
			firmed[0].SVvagon.push_back(tmpsv);
			firmed[1].SVvagon.push_back(tmpsv);
		}
		for (int k = 0; k < 4; k++)
		{
			firmed[0].PLAZvagon.push_back(tmpplaz);
			firmed[1].PLAZvagon.push_back(tmpplaz);
			fast[0].QUPEvagon.push_back(tmpqupe);
			fast[1].QUPEvagon.push_back(tmpqupe);
		}
		for (int k = 0; k < 6; k++)
		{
			firmed[0].QUPEvagon.push_back(tmpqupe);
			firmed[1].QUPEvagon.push_back(tmpqupe);
		}

		lastochka[3].napr = true;
		lastochka[4].napr = true;
		lastochka[5].napr = true;
		fast[1].napr = true;
		firmed[1].napr = true;
	}
	Day(const Day& a)
	{
		for (int k = 0; k < 8; k++)
		{
			lastochka[0].STDvagon.push_back(tmpstd);
			lastochka[1].STDvagon.push_back(tmpstd);
			lastochka[2].STDvagon.push_back(tmpstd);
			lastochka[3].STDvagon.push_back(tmpstd);
			lastochka[4].STDvagon.push_back(tmpstd);
			lastochka[5].STDvagon.push_back(tmpstd);
			fast[0].PLAZvagon.push_back(tmpplaz);
			fast[1].PLAZvagon.push_back(tmpplaz);
		}
		for (int k = 0; k < 2; k++)
		{
			firmed[0].SVvagon.push_back(tmpsv);
			firmed[1].SVvagon.push_back(tmpsv);
		}
		for (int k = 0; k < 4; k++)
		{
			firmed[0].PLAZvagon.push_back(tmpplaz);
			firmed[1].PLAZvagon.push_back(tmpplaz);
			fast[0].QUPEvagon.push_back(tmpqupe);
			fast[1].QUPEvagon.push_back(tmpqupe);
		}
		for (int k = 0; k < 6; k++)
		{
			firmed[0].QUPEvagon.push_back(tmpqupe);
			firmed[1].QUPEvagon.push_back(tmpqupe);
		}

		lastochka[3].napr = true;
		lastochka[4].napr = true;
		lastochka[5].napr = true;
		fast[1].napr = true;
		firmed[1].napr = true;
	}
	~Day()
	{

	}
	Day& Day::operator=(const Day& other)
	{
		if (this != &other)
		{
			for (int k = 0; k < 6; k++)
			{


				lastochka[k].napr = other.lastochka[k].napr;
				lastochka[k].number = other.lastochka[k].number;
				lastochka[k].STDvagon = other.lastochka[k].STDvagon;
			}
			for (int k = 0; k < 2; k++)
			{
				firmed[k].napr = other.firmed[k].napr;
				firmed[k].number = other.firmed[k].number;
				firmed[k].PLAZvagon = other.firmed[k].PLAZvagon;
				firmed[k].QUPEvagon = other.firmed[k].QUPEvagon;
				firmed[k].SVvagon = other.firmed[k].SVvagon;
			}
			for (int k = 0; k < 2; k++)
			{
				fast[k].napr = other.firmed[k].napr;
				fast[k].number = other.firmed[k].number;
				fast[k].PLAZvagon = other.firmed[k].PLAZvagon;
				fast[k].QUPEvagon = other.firmed[k].QUPEvagon;
			}
		}
		return *this;
	}

	friend class GorkRailway;
	friend class TicketOffice;
};
//////////////////////////////////////////////////////////////////////////////////////


class GorkRailway
{
protected:
	int tmpnumber = 1;
	vector <Day> days;
	GorkRailway()
	{
		int tmpvagnum = 1;
		cout << "please wait..." << endl;
		Day tmpday;
		for (int k = 0; k < 30; k++)
		{
			days.push_back(tmpday);
			for (int i = 0; i < 6; i++)
			{
				days[k].lastochka[i].number = tmpnumber;
				for (int o = 0; o < 8; o++)
				{
					days[k].lastochka[i].STDvagon[o].vagnum = tmpvagnum;
					tmpvagnum++;
				}
				tmpvagnum = 1;
				tmpnumber++;
			}
			days[k].fast[0].number = tmpnumber;
			tmpnumber++;
			for (int o = 0; o < 8; o++)
			{
				days[k].fast[0].PLAZvagon[o].vagnum = tmpvagnum;
				tmpvagnum++;
			}
			tmpvagnum = 1;
			for (int o = 0; o < 4; o++)
			{
				days[k].fast[0].QUPEvagon[o].vagnum = tmpvagnum;
				tmpvagnum++;
			}
			tmpvagnum = 1;
			days[k].fast[1].number = tmpnumber;
			tmpnumber++;
			for (int o = 0; o < 8; o++)
			{
				days[k].fast[1].PLAZvagon[o].vagnum = tmpvagnum;
				tmpvagnum++;
			}
			tmpvagnum = 1;
			for (int o = 0; o < 4; o++)
			{
				days[k].fast[1].QUPEvagon[o].vagnum = tmpvagnum;
				tmpvagnum++;
			}
			tmpvagnum = 1;
			days[k].firmed[0].number = tmpnumber;
			tmpnumber++;

			for (int o = 0; o < 6; o++)
			{
				days[k].firmed[0].QUPEvagon[o].vagnum = tmpvagnum;
				tmpvagnum++;
			}
			tmpvagnum = 1;
			for (int o = 0; o < 4; o++)
			{
				days[k].firmed[0].PLAZvagon[o].vagnum = tmpvagnum;
				tmpvagnum++;
			}
			tmpvagnum = 1;
			days[k].firmed[0].SVvagon[0].vagnum = tmpvagnum;
			tmpvagnum++;
			days[k].firmed[0].SVvagon[1].vagnum = tmpvagnum;
			tmpvagnum = 1;

			days[k].firmed[1].number = tmpnumber;
			tmpnumber++;
			for (int o = 0; o < 6; o++)
			{
				days[k].firmed[1].QUPEvagon[o].vagnum = tmpvagnum;
				tmpvagnum++;
			}
			tmpvagnum = 1;
			for (int o = 0; o < 4; o++)
			{
				days[k].firmed[1].PLAZvagon[o].vagnum = tmpvagnum;
				tmpvagnum++;
			}
			tmpvagnum = 1;
			days[k].firmed[1].SVvagon[0].vagnum = tmpvagnum;
			tmpvagnum++;
			days[k].firmed[1].SVvagon[1].vagnum = tmpvagnum;
			tmpvagnum = 1;


		}
	}
	int GetNecessaryDay(int _day, int _month, int _year)
	{
		int necessaryday;
		tm lastdate;
		lastdate.tm_mday = _day;
		lastdate.tm_mon = _month - 1;
		lastdate.tm_year = _year - 1900;
		lastdate.tm_hour = 0;
		lastdate.tm_min = 0;
		lastdate.tm_sec = 0;
		tm firstdate = *gmtime(now());
		time_t ld = mktime(&lastdate);
		time_t fd = mktime(&firstdate);
		necessaryday = difftime(ld, fd) / (60 * 60 * 24);
		return necessaryday;
	}
	const time_t* now()
	{
		static time_t res;
		res = time(nullptr) + 10800;
		return &res;
	}
	void Swap(Day& a, Day& b)
	{
		Day tmpday;
		tmpday = a;
		a = b;
		b = tmpday;
	}
};
class TicketOffice : public GorkRailway
{
private:
	ticket tmpticket;
	double money = 0;
	double price1 = 100, price2 = 1000, price3 = 110;
public:
	int quantity = 0;
	vector <ticket> tickets;
	bool Checkseats(int _day, int _month, int _year, int _trainnum, string _traintype, string _vagontype, int _vagnum, int _seats, int _upseats, int _downseats)
	{
		_trainnum = (_trainnum % 10);
		if (_trainnum > 6)
		{
			if ((_trainnum == 9) || (_trainnum == 0))
			{
				_trainnum -= 2;
			}
			_trainnum -= 6;
		}
		_trainnum--;
		int necessaryday = GetNecessaryDay(_day, _month, _year);
		if (_traintype == "lastochka")
		{
			if (days[necessaryday].lastochka[_trainnum].STDvagon[_vagnum].freeseats >= _seats)
			{
				return true;
			}
			else return false;
		}
		if (_traintype == "firmed")
		{
			if (_vagontype == "SV")
			{

				if ((days[necessaryday].firmed[_trainnum].SVvagon[_vagnum].freedownseats >= _downseats) && (_upseats && _seats == 0))
				{
					return true;
				}
				else return false;

			}
			if (_vagontype == "QUPE")
			{
				if ((days[necessaryday].firmed[_trainnum].QUPEvagon[_vagnum].freedownseats >= _downseats) && (days[necessaryday].firmed[_trainnum].QUPEvagon[_vagnum].freeupseats >= _upseats) && (_seats == 0))
				{
					return true;
				}
				else return false;
			}
			if (_vagontype == "PLAZ")
			{
				if ((days[necessaryday].firmed[_trainnum].PLAZvagon[_vagnum].freedownseats >= _downseats) && (days[necessaryday].firmed[_trainnum].QUPEvagon[_vagnum].freeupseats >= _upseats) && (_seats == 0))
				{
					return true;
				}
				else return false;
			}
		};
		if (_traintype == "fast")
		{

			if (_vagontype == "QUPE")
			{
				if ((days[necessaryday].firmed[_trainnum].QUPEvagon[_vagnum].freedownseats >= _downseats) && (days[necessaryday].firmed[_trainnum].QUPEvagon[_vagnum].freeupseats >= _upseats) && (_seats == 0))
				{
					return true;
				}
				else return false;
			}
			if (_vagontype == "PLAZ")
			{
				if ((days[necessaryday].firmed[_trainnum].PLAZvagon[_vagnum].freedownseats >= _downseats) && (days[necessaryday].firmed[_trainnum].QUPEvagon[_vagnum].freeupseats >= _upseats) && (_seats == 0))
				{
					return true;
				}
				else return false;
			}
		}
	};
	void Reserve(int _day, int _month, int _year, int _trainnum, string _traintype, string _vagontype, int _vagnum, int _seats, int _upseats, int _downseats, string _name)
	{
		money += _upseats * price1 + _downseats * price2 + _seats * price3;
		int necessaryday = GetNecessaryDay(_day, _month, _year);
		tmpticket.day = _day;
		tmpticket.month = _month;
		tmpticket.year = _year;
		tmpticket.name = _name;
		tmpticket.trainnum = _trainnum;
		tmpticket.vagonnum = _vagnum;
		tmpticket.vagontype = _vagontype;
		if (days[necessaryday].firmed[_vagnum].napr == false)
		{
			tmpticket.first = "NN";
			tmpticket.last = "Msk";
		}
		else
		{
			tmpticket.first = "Msk";
			tmpticket.last = "NN";
		}
		int s = 0;
		_trainnum = (_trainnum % 10);
		if (_trainnum > 6)
		{
			if ((_trainnum == 9) || (_trainnum == 0))
			{
				_trainnum -= 2;
			}
			_trainnum -= 6;
		}
		_trainnum--;
		if (_traintype == "lastochka")
		{
			while (_seats > 0)
			{
				while (s < 100)
				{
					if (days[necessaryday].lastochka[_trainnum].STDvagon[_vagnum].seat[s] == true)
					{
						s++;
					}
					else
					{
						days[necessaryday].lastochka[_trainnum].STDvagon[_vagnum].seat[s] = true;
						days[necessaryday].lastochka[_trainnum].STDvagon[_vagnum].freeseats--;
						break;
					}

				}
				_seats--;
				tmpticket.seatnum = s + 1;
				tickets.push_back(tmpticket);
			}
		}
		if (_traintype == "firmed")
		{
			if (_vagontype == "SV")
			{
				while (_downseats > 0)
				{
					while (s < 18)
					{
						if (days[necessaryday].firmed[_trainnum].SVvagon[_vagnum].downseat[s] == true)
						{
							s++;
						}
						else
						{
							days[necessaryday].firmed[_trainnum].SVvagon[_vagnum].downseat[s] = true;
							days[necessaryday].firmed[_trainnum].SVvagon[_vagnum].freedownseats--;
							break;
						}
					}
					_downseats--;
					tmpticket.upseatnum = s + 1;
					tickets.push_back(tmpticket);
				}
			}
			if (_vagontype == "QUPE")
			{
				if (_downseats > 0)
				{
					while (_downseats > 0)
					{
						{
							while (s < 18)
							{
								if (days[necessaryday].firmed[_trainnum].QUPEvagon[_vagnum].downseat[s] == true)
								{
									s++;
								}
								else
								{
									days[necessaryday].firmed[_trainnum].QUPEvagon[_vagnum].downseat[s] = true;
									days[necessaryday].firmed[_trainnum].QUPEvagon[_vagnum].freedownseats--;
									break;
								}
							}
						}
						_downseats--;
						tmpticket.upseatnum = s + 1;
						tickets.push_back(tmpticket);
					}
				}

				if (_upseats > 0) {
					while (_upseats > 0)
					{
						while (s < 18)
						{
							if (days[necessaryday].firmed[_trainnum].QUPEvagon[_vagnum].upseat[s] == true)
							{
								s++;
							}
							else
							{
								days[necessaryday].firmed[_trainnum].QUPEvagon[_vagnum].upseat[s] = true;
								days[necessaryday].firmed[_trainnum].QUPEvagon[_vagnum].freeupseats--;
								break;
							}
						}
					}
					_upseats--;
					tmpticket.upseatnum = s + 1;
					tickets.push_back(tmpticket);
				}
			}
			if (_vagontype == "PLAZ")
			{
				if (_downseats > 0)
				{
					while (_downseats > 0)
					{
						while (s < 27)
						{
							if (days[necessaryday].firmed[_trainnum].PLAZvagon[_vagnum].downseat[s] == true)
							{
								s++;
							}
							else
							{
								days[necessaryday].firmed[_trainnum].PLAZvagon[_vagnum].downseat[s] = true;
								days[necessaryday].firmed[_trainnum].PLAZvagon[_vagnum].freedownseats--;
								break;
							}
						}
						_downseats--;
						tmpticket.upseatnum = s + 1;
						tickets.push_back(tmpticket);
					}
				}
				if (_upseats > 0)
				{
					while (_upseats > 0)
					{
						while (s < 27)
						{
							if (days[necessaryday].firmed[_trainnum].PLAZvagon[_vagnum].upseat[s] == true)
							{
								s++;
							}
							else
							{
								days[necessaryday].firmed[_trainnum].PLAZvagon[_vagnum].upseat[s] = true;
								days[necessaryday].firmed[_trainnum].PLAZvagon[_vagnum].freeupseats--;
								break;
							}
						}
						_upseats--;
						tmpticket.upseatnum = s + 1;
						tickets.push_back(tmpticket);
					}


				}
			}
		};
		if (_traintype == "fast")
		{
			if (_vagontype == "QUPE")
			{
				if (_downseats > 0) {
					while (_downseats > 0)
					{
						while (s < 18)
						{
							if (days[necessaryday].fast[_trainnum].QUPEvagon[_vagnum].downseat[s] == true)
							{
								s++;
							}
							else
							{
								days[necessaryday].fast[_trainnum].QUPEvagon[_vagnum].downseat[s] = true;
								days[necessaryday].fast[_trainnum].QUPEvagon[_vagnum].freedownseats--;
								break;
							}
						}
						_downseats--;
						tmpticket.upseatnum = s + 1;
						tickets.push_back(tmpticket);
					}
				}
				if (_upseats > 0) {
					while (_upseats > 0)
					{
						while (s < 18) {
							if (days[necessaryday].fast[_trainnum].QUPEvagon[_vagnum].upseat[s] == true)
							{
								s++;
							}
							else
							{
								days[necessaryday].fast[_trainnum].QUPEvagon[_vagnum].upseat[s] = true;
								days[necessaryday].fast[_trainnum].QUPEvagon[_vagnum].freeupseats--;
								break;
							}
						}
						_upseats--;
						tmpticket.upseatnum = s + 1;
						tickets.push_back(tmpticket);
					}
				}
				if (_vagontype == "PLAZ")
				{

					if (_downseats > 0)
					{
						while (_downseats > 0)
						{
							while (s < 27) {
								if (days[necessaryday].fast[_trainnum].PLAZvagon[_vagnum].downseat[s] == true)
								{
									s++;
								}
								else
								{
									days[necessaryday].fast[_trainnum].PLAZvagon[_vagnum].downseat[s] = true;
									days[necessaryday].fast[_trainnum].PLAZvagon[_vagnum].freedownseats--;
									break;
								}
							}
							_downseats--;
							tmpticket.upseatnum = s + 1;
							tickets.push_back(tmpticket);
						}
					}
					if (_upseats > 0)
					{
						while (_upseats > 0)
						{
							while (s < 27)
							{
								if (days[necessaryday].fast[_trainnum].PLAZvagon[_vagnum].upseat[s] == true)
								{
									s++;
								}
								else
								{
									days[necessaryday].fast[_trainnum].PLAZvagon[_vagnum].upseat[s] = true;
									days[necessaryday].fast[_trainnum].PLAZvagon[_vagnum].freeupseats--;
									break;
								}
							}
							tmpticket.upseatnum = s + 1;
							tickets.push_back(tmpticket);
							_upseats--;
						}
					}
				}
			}
		}
		quantity++;
	}
	double Getprice()
	{
		return money;
	}
	void UnReserve(int _day, int _month, int _year, string _name)
	{
		int necessaryday = GetNecessaryDay(_day, _month, _year);

		for (int k = 0; k < tickets.size(); k++)
		{
			if (tickets[k].name == _name)
			{
				tickets[k].trainnum = tickets[k].trainnum % 10;




				if (((tickets[k].trainnum) < 7) && ((tickets[k].trainnum) != 0))
				{
					if (tickets[k].trainnum > 6)
					{
						if ((tickets[k].trainnum == 9) || (tickets[k].trainnum == 0))
						{
							tickets[k].trainnum -= 2;
						}
						tickets[k].trainnum -= 6;
					}
					tickets[k].trainnum--;
					days[necessaryday].lastochka[tickets[k].trainnum].STDvagon[tickets[k].vagonnum].seat[tickets[k].seatnum] = false;
					days[necessaryday].lastochka[tickets[k].trainnum].STDvagon[tickets[k].vagonnum].freeseats++;
					days[necessaryday].lastochka[tickets[k].trainnum].STDvagon[tickets[k].vagonnum].name[tickets[k].seatnum] = "";
				}
				if (((tickets[k].trainnum) == 7) || ((tickets[k].trainnum) == 8))
				{
					if (tickets[k].trainnum > 6)
					{
						if ((tickets[k].trainnum == 9) || (tickets[k].trainnum == 0))
						{
							tickets[k].trainnum -= 2;
						}
						tickets[k].trainnum -= 6;
					}
					tickets[k].trainnum--;
					if (tickets[k].vagontype == "SV")
					{
						days[necessaryday].firmed[tickets[k].trainnum].SVvagon[tickets[k].vagonnum].downseat[tickets[k].downseatnum] = false;
						days[necessaryday].firmed[tickets[k].trainnum].SVvagon[tickets[k].vagonnum].freedownseats++;
						days[necessaryday].firmed[tickets[k].trainnum].SVvagon[tickets[k].vagonnum].downname[tickets[k].seatnum] = "";
					}


					if (tickets[k].vagontype == "QUPE")
					{
						if (tickets[k].downseatnum > 0)
						{
							days[necessaryday].firmed[tickets[k].trainnum].QUPEvagon[tickets[k].vagonnum].downseat[tickets[k].downseatnum] = false;
							days[necessaryday].firmed[tickets[k].trainnum].QUPEvagon[tickets[k].vagonnum].freedownseats++;
							days[necessaryday].firmed[tickets[k].trainnum].QUPEvagon[tickets[k].vagonnum].downname[tickets[k].seatnum] = "";
						}
						if (tickets[k].upseatnum > 0) {
							days[necessaryday].firmed[tickets[k].trainnum].QUPEvagon[tickets[k].vagonnum].upseat[tickets[k].upseatnum] = false;
							days[necessaryday].firmed[tickets[k].trainnum].QUPEvagon[tickets[k].vagonnum].freeupseats++;
							days[necessaryday].firmed[tickets[k].trainnum].QUPEvagon[tickets[k].vagonnum].upname[tickets[k].seatnum] = "";
						}
					}
					if (tickets[k].vagontype == "PLAZ")
					{
						if (tickets[k].downseatnum > 0)
						{
							if (tickets[k].downseatnum > 0)
							{
								days[necessaryday].firmed[tickets[k].trainnum].PLAZvagon[tickets[k].vagonnum].downseat[tickets[k].downseatnum] = false;
								days[necessaryday].firmed[tickets[k].trainnum].PLAZvagon[tickets[k].vagonnum].freedownseats++;
								days[necessaryday].firmed[tickets[k].trainnum].PLAZvagon[tickets[k].vagonnum].downname[tickets[k].seatnum] = "";
							}
						}
						if (tickets[k].upseatnum > 0)
						{
							days[necessaryday].firmed[tickets[k].trainnum].PLAZvagon[tickets[k].vagonnum].upseat[tickets[k].upseatnum] = false;
							days[necessaryday].firmed[tickets[k].trainnum].PLAZvagon[tickets[k].vagonnum].freeupseats++;
							days[necessaryday].firmed[tickets[k].trainnum].PLAZvagon[tickets[k].vagonnum].upname[tickets[k].seatnum] = "";
						}

					}
				};
				if (((tickets[k].trainnum) == 9) || ((tickets[k].trainnum) == 0))
				{
					if (tickets[k].trainnum > 6)
					{
						if ((tickets[k].trainnum == 9) || (tickets[k].trainnum == 0))
						{
							tickets[k].trainnum -= 2;
						}
						tickets[k].trainnum -= 6;
					}
					if (tickets[k].trainnum != 0)
					{
						tickets[k].trainnum--;
					}
					if (tickets[k].vagontype == "QUPE")
					{
						if (tickets[k].downseatnum > 0)
						{
							days[necessaryday].fast[tickets[k].trainnum].QUPEvagon[tickets[k].vagonnum].downseat[tickets[k].downseatnum] = false;
							days[necessaryday].fast[tickets[k].trainnum].QUPEvagon[tickets[k].vagonnum].freedownseats++;
							days[necessaryday].fast[tickets[k].trainnum].QUPEvagon[tickets[k].vagonnum].downname[tickets[k].seatnum] = "";
						}
						if (tickets[k].upseatnum > 0)
						{
							days[necessaryday].fast[tickets[k].trainnum].QUPEvagon[tickets[k].vagonnum].upseat[tickets[k].upseatnum] = false;
							days[necessaryday].fast[tickets[k].trainnum].QUPEvagon[tickets[k].vagonnum].freeupseats++;
							days[necessaryday].fast[tickets[k].trainnum].QUPEvagon[tickets[k].vagonnum].upname[tickets[k].seatnum] = "";
						}
					}
					if (tickets[k].vagontype == "PLAZ")
					{
						if (tickets[k].downseatnum > 0)
						{
							days[necessaryday].fast[tickets[k].trainnum].PLAZvagon[tickets[k].vagonnum].downseat[tickets[k].downseatnum] = false;
							days[necessaryday].fast[tickets[k].trainnum].PLAZvagon[tickets[k].vagonnum].freedownseats++;
							days[necessaryday].fast[tickets[k].trainnum].PLAZvagon[tickets[k].vagonnum].downname[tickets[k].seatnum] = "";
						}
						if (tickets[k].upseatnum > 0)
						{
							days[necessaryday].fast[tickets[k].trainnum].PLAZvagon[tickets[k].vagonnum].upseat[tickets[k].upseatnum] = false;
							days[necessaryday].fast[tickets[k].trainnum].PLAZvagon[tickets[k].vagonnum].freeupseats++;
							days[necessaryday].fast[tickets[k].trainnum].PLAZvagon[tickets[k].vagonnum].upname[tickets[k].seatnum] = "";
						}
					}
				}
				tickets.erase(tickets.begin() + k);
			}
		}
	}
	void NewDay()
	{
		for (int k = 0; k < 29; k++)
		{
			Swap(days[k], days[k + 1]);
		}
		days.pop_back();
		Day tmpday;
		days.push_back(tmpday);
		for (int i = 0; i < 6; i++)
		{
			days[29].lastochka[i].number = tmpnumber;
			tmpnumber++;
		}
		days[29].fast[0].number = tmpnumber;
		tmpnumber++;
		days[29].fast[1].number = tmpnumber;
		tmpnumber++;
		days[29].firmed[0].number = tmpnumber;
		tmpnumber++;
		days[29].firmed[1].number = tmpnumber;
		tmpnumber++;
	}

};
void main()
{
	TicketOffice biletiki;
	if (biletiki.Checkseats(17, 5, 2020, 1, "lastochka", "STD", 2, 1, 0, 0))
	{
		cout << "svobodno" << endl;
	}
	else cout << "zanyato" << endl;
	biletiki.Reserve(17, 5, 2020, 1, "lastochka", "STD", 2, 99, 0, 0, "Ivan Ivanovich Ivanov");//traintypes -lastochka, firmed, fast. vagontypes-STD, QUPE, PLAZ, SV.
	if (biletiki.Checkseats(17, 5, 2020, 1, "lastochka", "STD", 2, 5, 0, 0))
	{
		cout << "svobodno" << endl;
	}
	else cout << "zanyato" << endl;
	cout << biletiki.Getprice() << endl;
	biletiki.UnReserve(17, 5, 2020, "Ivan Ivanovich Ivanov");
	if (biletiki.Checkseats(17, 5, 2020, 1, "lastochka", "STD", 2, 5, 0, 0))
	{
		cout << "svobodno" << endl;
	}
	else cout << "zanyato" << endl;
	cout << biletiki.tickets[biletiki.quantity].year;
	system("pause");

}