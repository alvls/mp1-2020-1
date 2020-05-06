#include <iostream>
#include <cstdlib>
#include <vector>
#include <clocale>
#include <string>
#include <windows.h>
using namespace std;


struct hall
{
	int numberh;
	int price;
	int vipprice;
	hall(int n = 0, int pr = 0, int vpr = 0)
		: numberh(n), price(pr), vipprice(vpr) {}
};
struct place
{
	int raw_;
	int place_;
	bool type;
};

struct time
{
	int hour;
	int minute;
	time(int h = 0, int m = 0) : hour(h), minute(m) {}
};

struct reserve
{
	int d;
	time t;
	string name;
	int numberhall;
	vector <place> res_places;
	bool reserves = false;

};
struct ticket
{
	int t_date;
	time t_time;
	string t_name;
	int t_numberh;
	place t_place;
};
class Seance
{
private:
	string film;
	int day;
	time time_seance;
	int number_hall;
	vector<vector<bool>> employment;
public:
	static int st_row;
	static int st_place;
	Seance(string _film = "", int _day = 0, time _time_seance = time(0, 0), int _number_hall = 0)
		: film(_film), day(_day), time_seance(_time_seance), number_hall(_number_hall)
	{
		vector<bool> m;
		for (int i = 0; i < st_place; i++)
			m.push_back(true);
		for (int i = 0; i < st_row; i++)
			employment.push_back(m);
	}
	~Seance()
	{}
	Seance(const Seance & s)
	{
		film = s.film;
		day = s.day;
		time_seance = s.time_seance;
		number_hall = s.number_hall;
		employment = s.employment;
	}
	Seance& operator=(const Seance &s)
	{
		if (this != &s) {
			film = s.film;
			day = s.day;
			time_seance.hour = s.time_seance.hour;
			time_seance.minute = s.time_seance.minute;
			number_hall = s.number_hall;
			employment = s.employment;
		}
		return *this;
	}
	bool operator ==(const Seance &s)
	{
		if (film == s.film && day == s.day && time_seance.hour == s.time_seance.hour && time_seance.minute == s.time_seance.minute)
			return true;
		else
			return false;
	}
	void ChangeData(string _film, int _day, time _time_seance, int _number_hall)
	{
		film = _film;
		day = _day;
		time_seance = _time_seance;
		number_hall = _number_hall;
	}
	bool Employment(int _row, int _place)
	{
		if (employment[_row - 1][_place - 1])
			return true;
		else
			return false;
	}
	void ChangeEmployment(vector <place> m)
	{
		for (size_t i = 0; i < m.size(); i++)
			for (size_t j = 0; j < m.size(); j++)
				employment[m[i].raw_ - 1][m[j].place_ - 1] = false;
	}
	void CancelEmployment(vector <place> m)
	{
		for (size_t i = 0; i < m.size(); i++)
			for (size_t j = 0; j < m.size(); j++)
				employment[m[i].raw_ - 1][m[j].place_ - 1] = true;
	}
	string ReturnNameFilm()
	{
		return film;
	}
	int ReturnDayOfTheSeance()
	{
		return day;
	}
	time ReturnTimeOfTheSeance()
	{
		return time_seance;
	}
	int ReturnNumberOfHall()
	{
		return number_hall;
	}
};
class Cinema
{
private:
	vector< vector<Seance> > &info;
	vector <hall> &halls;
public:
	Cinema(vector < vector<Seance> > & _inf = vector< vector<Seance> >(), vector <hall> & _halls = vector<hall>())
		: info(_inf), halls(_halls) {}
	void AddSeance(Seance s, int _day)
	{
		info[_day - 1].push_back(s);
	}
	void AddHall(hall r)
	{
		halls.push_back(r);
	}
	vector < vector<Seance> > & ReturnInformation()
	{
		return info;
	}
	vector <hall> & ReturnHalls()
	{
		return halls;
	}
	Seance & ReturnTheSeance(int d1, time t1, int zall)
	{
		for (size_t i = 0; i < info[d1 - 1].size(); i++)
		{
			if (info[d1 - 1][i].ReturnDayOfTheSeance() == d1
				&& info[d1 - 1][i].ReturnTimeOfTheSeance().hour == t1.hour
				&& info[d1 - 1][i].ReturnTimeOfTheSeance().minute == t1.minute
				&& info[d1 - 1][i].ReturnNumberOfHall() == zall)
				return info[d1 - 1][i];
			else continue;
		}
	}
	vector<Seance> AllOfSeances()
	{
		vector<Seance> all_of_seances;
		for (size_t i = 0; i < info.size(); i++)
			for (size_t j = 0; j < info[i].size(); j++)
				all_of_seances.push_back(info[i][j]);
		return all_of_seances;
	}
};
class TicketOffice
{
private:
	Cinema  my_cinema;
	vector <reserve> rsrvs;
public:
	TicketOffice(Cinema  _my_cinema, vector <reserve> _rsrvs)
		: my_cinema(_my_cinema), rsrvs(_rsrvs) {}
	int AcceptData(int _day, time _t, string _name, int _numberhall, vector<place> p)
	{
		reserve _reserve;
		_reserve.d = _day;
		_reserve.t = _t;
		_reserve.name = _name;
		_reserve.numberhall = _numberhall;
		_reserve.res_places = p;
		rsrvs.push_back(_reserve);
		return rsrvs.size();
	}
	bool CheckPlaces(Seance seans, vector<place> m)
	{
		for (size_t i = 0; i < my_cinema.ReturnInformation().size(); i++)
			for (size_t j = 0; j < my_cinema.ReturnInformation()[i].size(); j++)
			{
				if (my_cinema.ReturnInformation()[i][j] == seans)
				{
					for (size_t k = 0; k < m.size(); k++)
						if (my_cinema.ReturnInformation()[i][j].Employment(m[k].raw_, m[k].place_) == false)
							return false;
					return true;
				}
				else continue;
			}
	}
	bool MakeReservation(int a) 
	{
		Seance s(rsrvs[a - 1].name, rsrvs[a - 1].d, rsrvs[a - 1].t, rsrvs[a - 1].numberhall);
		for (size_t i = 0; i < my_cinema.ReturnInformation()[rsrvs[a - 1].d - 1].size(); i++)
		{
			if (my_cinema.ReturnInformation()[rsrvs[a - 1].d - 1][i] == s)
			{
				if ((*this).CheckPlaces(my_cinema.ReturnInformation()[rsrvs[a - 1].d - 1][i], rsrvs[a - 1].res_places))
				{
					my_cinema.ReturnTheSeance(rsrvs[a - 1].d, rsrvs[a - 1].t, rsrvs[a - 1].numberhall).ChangeEmployment(rsrvs[a - 1].res_places);
					rsrvs[a - 1].reserves = true;
					return true;
				}
			}
		}
		return false;
	}
	double TotalValue(int a) 
	{
		double sum = 0;
		if (rsrvs[a - 1].t.hour < 12)
		{
			cout << rsrvs[a - 1].res_places.size() << endl;
			for (size_t i = 0; i < rsrvs[a - 1].res_places.size(); i++)
			{
				if (rsrvs[a - 1].res_places[i].type)
					sum = sum + (0.75 * my_cinema.ReturnHalls()[rsrvs[a - 1].numberhall - 1].vipprice);
				else 
					sum = sum + (0.75 * my_cinema.ReturnHalls()[rsrvs[a - 1].numberhall - 1].price);
			}
			return sum;
		}
		if (rsrvs[a - 1].t.hour > 18)
		{
			for (size_t i = 0; i < rsrvs[a - 1].res_places.size(); i++)
			{
				if (rsrvs[a - 1].res_places[i].type)
					sum = sum + (1.5 * my_cinema.ReturnHalls()[rsrvs[a - 1].numberhall - 1].vipprice);
				else
					sum = sum + (1.5 * my_cinema.ReturnHalls()[rsrvs[a - 1].numberhall - 1].price);
			}
			return sum;
		}
		if ((rsrvs[a - 1].t.hour<18) && (rsrvs[a - 1].t.hour>12))
		{
			for (size_t i = 0; i < rsrvs[a - 1].res_places.size(); i++)
			{
				if (rsrvs[a - 1].res_places[i].type)
					sum += my_cinema.ReturnHalls()[rsrvs[a - 1].numberhall - 1].vipprice;
				else
					sum += my_cinema.ReturnHalls()[rsrvs[a - 1].numberhall - 1].price;
			}
			return sum;
		}
		return sum;
	}
	void DeleteReserve(int a) 
	{
		Seance s(rsrvs[a - 1].name, rsrvs[a - 1].d, rsrvs[a - 1].t, rsrvs[a - 1].numberhall);
		for (size_t i = 0; i < my_cinema.ReturnInformation()[rsrvs[a - 1].d - 1].size(); i++)
		{
			if (my_cinema.ReturnInformation()[rsrvs[a - 1].d - 1][i] == s)
				my_cinema.ReturnInformation()[rsrvs[a - 1].d - 1][i].CancelEmployment(rsrvs[a - 1].res_places);
		}
		rsrvs.erase(rsrvs.begin() + a - 1);
	}
	vector <ticket> MakeTickets(int a)
	{
		ticket t_ticket;
		vector <ticket> tickets;
		if (rsrvs[a - 1].reserves)
		{
			for (size_t i = 0; i < rsrvs[a - 1].res_places.size(); i++)
			{
				t_ticket.t_date = rsrvs[a - 1].d;
				t_ticket.t_name = rsrvs[a - 1].name;
				t_ticket.t_numberh = rsrvs[a - 1].numberhall;
				t_ticket.t_place = rsrvs[a - 1].res_places[i];
				t_ticket.t_time.hour = rsrvs[a - 1].t.hour;
				t_ticket.t_time.minute = rsrvs[a - 1].t.minute;
				tickets.push_back(t_ticket);
			}
		}
		return tickets;
	}
};
int Seance::st_row = 4;
int Seance::st_place = 5;
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	int virtday, vib, a, b, c, d, e, f, j;
	int w = 1;
	int y = 1;
	f = 1;
	time t1, virtime;
	string s1;
	Seance kino;
	place q1, q2;
	vector <place> n1, n2;
	vector<vector<Seance>> info1(30);
	vector<hall> hall1;
	vector<reserve> res1;
	Cinema Bumbastic(info1, hall1);
	TicketOffice kassa(Bumbastic, res1);
	cout << "Введите сегодняшнее число:" << endl;
	cin >> virtday;
	cout << "Введите время:" << endl;
	cout << "ч:";
	cin >> virtime.hour;
	cout << "м:";
	cin >> virtime.minute;
	while (f)
	{
		cout << "Выберите действие:" << endl;
		cout << "1.Добавить информацию о киносеансах" << endl;
		cout << "2.Заказать билеты в кино" << endl;
		cout << "3.Выйти из программы" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
		{
			w = 1;
			while (w)
			{
				cout << "Что хотите добавить?" << endl << "1.Обозначить стоимость билетов" << endl << "2.Добавить сеанс" << endl << "3.Главное меню" << endl;
				cin >> b;
				switch (b)
				{
				case 1:
				{
					cout << "Номер зала:";
					cin >> c;
					cout << "Стандартная цена билета:";
					cin >> d;
					cout << "Цена VIP-билета:";
					cin >> e;
					hall h1(c, d, e);
					Bumbastic.AddHall(h1);
					cout << "Зал добавлен!" << endl;
					break;
				}
				case 2:
				{
					cout << "Название фильма:";
					cin.ignore();
					getline(cin, s1);
					cout << "День:";
					cin >> c;
					cout << "Время сеанса:" << endl;
					cout << "ч:";
					cin >> t1.hour;
					cout << "м:";
					cin >> t1.minute;
					cout << "Номер зала, в котором будет проходить сеанс:";
					cin >> d;
					kino.ChangeData(s1, c, t1, d);
					Bumbastic.AddSeance(kino, c);
					cout << "Киносеанс добавлен!" << endl;
					break;
				}
				case 3:
				{
					w = 0;
					break;
				}
				break;
				}
			}
			break;
		}
		case 2:
		{
			y = 1;
			while (y)
			{
				cout << "Добро пожаловать в кинотеатр 'Бумбастик'! Выберите желаемое действие:" << endl;
				cout << "1. Посмотреть расписание киносеансов" << endl;
				cout << "2. Проверить наличие свободных мест в требуемой зоне" << endl;
				cout << "3. Сделать заказ" << endl;
				cout << "4. Забронировать места" << endl;
				cout << "5. Узнать общую стоимость заказа" << endl;
				cout << "6. Отменить заказ" << endl;
				cout << "7. Вывести информацию о билетах" << endl;
				cout << "8. Вернуться в главное меню" << endl;
				cout << "9. Выйти из программы" << endl;
				cin >> a;
				switch (a)
				{
				case 1:
				{
					cout << "1.Посмотреть расписание на ближайший месяц" << endl << "2.Посмотреть расписание на ближайшие 3 дня" << endl;
					cin >> vib;
					if (vib == 1) {
						for (size_t i = 0; i < Bumbastic.AllOfSeances().size(); i++)
						{
							cout << i + 1 << "." << Bumbastic.AllOfSeances()[i].ReturnNameFilm() << " , " << Bumbastic.AllOfSeances()[i].ReturnDayOfTheSeance() << " мая 2020." << endl;
							cout << "Время сеанса: " << Bumbastic.AllOfSeances()[i].ReturnTimeOfTheSeance().hour << ":" << Bumbastic.AllOfSeances()[i].ReturnTimeOfTheSeance().minute << endl;
							cout << "Номер зала: " << Bumbastic.AllOfSeances()[i].ReturnNumberOfHall() << endl;
							cout << endl;
						}
						break;
					}
					else
					{
						for (size_t i = 0; i < Bumbastic.AllOfSeances().size(); i++)
						{
							if ((Bumbastic.AllOfSeances()[i].ReturnDayOfTheSeance() - virtday) <= 3) {
								cout << i + 1 << "." << Bumbastic.AllOfSeances()[i].ReturnNameFilm() << ". " << Bumbastic.AllOfSeances()[i].ReturnDayOfTheSeance() << " мая 2020." << endl;
								cout << "Время сеанса: " << Bumbastic.AllOfSeances()[i].ReturnTimeOfTheSeance().hour << ":" << Bumbastic.AllOfSeances()[i].ReturnTimeOfTheSeance().minute << endl;
								cout << "Номер зала: " << Bumbastic.AllOfSeances()[i].ReturnNumberOfHall() << endl;
							}
						}
						break;

					}
				}
				case 2:
				{
					cout << "Введите данные сеанса:" << endl;
					cout << "День:";
					cin >> b;
					cout << "Название фильма:";
					cin.ignore();
					getline(cin, s1);
					cout << "Номер зала:";
					cin >> c;
					cout << "Время:" << endl;
					cout << "ч:";
					cin >> t1.hour;
					cout << "м:";
					cin >> t1.minute;
					cout << "Введите места, которые желаете проверить" << endl;
					do {
						cout << "Ряд:";
						cin >> q2.raw_;
						cout << "Место:";
						cin >> q2.place_;
						n2.push_back(q2);
						cout << "VIP(1) или стандарт(2)?" << endl;
						cin >> e;
						if (e == 1) {
							q1.type = true;
						}
						else
						{
							q1.type = false;
						}
						cout << "Ещё одно место?" << endl;
						cout << "1.Да" << endl;
						cout << "2.Нет" << endl;
						cin >> j;
					} while (j == 1);

					if (kassa.CheckPlaces(Bumbastic.ReturnTheSeance(b, t1, c), n2))
						cout << "Места свободны!" << endl;
					else
						cout << "Места заняты." << endl;
					n2.clear();
					break;
				}
				case 3:
				{
					cout << "День:";
					cin >> d;
					cout << "Время:" << endl;
					cout << "ч:";
					cin >> t1.hour;
					cout << "м:";
					cin >> t1.minute;
					if (((abs(t1.minute - virtime.minute) < 10) && (virtday == d)) || ((d - virtday) > 3) || ((d - virtday) < 0)) {
						cout << "К сожалению, данный сеанс недоступен" << endl;
						break;
					}
					else {
						cout << "Название фильма:";
						cin.ignore();
						getline(cin, s1);
						cout << "Номер зала:";
						cin >> c;
						do {
							cout << "Ряд:";
							cin >> q1.raw_;
							cout << "Место:";
							cin >> q1.place_;
							cout << "VIP(1) или стандарт(2)?" << endl;
							cin >> e;
							if (e == 1) {
								q1.type = true;
							}
							else
							{
								q1.type = false;
							}
							n1.push_back(q1);
							cout << "Ещё одно место?" << endl;
							cout << "1.Да" << endl;
							cout << "2.Нет" << endl;
							cin >> j;
						} while (j == 1);
						cout << "Заказ принят! Чтобы забронировать, необходимо выйти в основное меню и выбрать нужный пукнт" << endl;
						cout << "Ваш номер заказа: " << kassa.AcceptData(d, t1, s1, c, n1) << endl;
						n1.clear();
						break;
					}
				}
				case 4:
				{
					cout << "Для резервирования введите номер заказа:";
					cin >> b;
					if (kassa.MakeReservation(b))
						cout << "Места успешно забронированы!" << endl;
					else
						cout << "Ошибка! Места уже были забронированы." << endl;
					break;
				}
				case 5:
				{
					cout << "Введите ваш номер заказа:";
					cin >> b;
					cout << "Общая смоимость билетов составила " << kassa.TotalValue(b) << " рублей." << endl;
					break;
				}
				case 6:
				{
					cout << "Введите ваш номер заказа:";
					cin >> b;
					kassa.DeleteReserve(b);
					cout << "Заказ отменён." << endl;
					break;
				}
				case 7:
				{
					cout << "Введите ваш номер заказа:";
					cin >> b;
					vector <ticket> bilet;
					bilet = kassa.MakeTickets(b);
					cout << "ВАШИ БИЛЕТЫ:" << endl;
					if (bilet.size() == 0) {
						cout << "Вы не забронировали заказ";
					}
					for (size_t i = 0; i < bilet.size(); i++)
					{
						cout << "Билет № " << i + 1 << "." << endl;
						cout << "Дата: " << bilet[i].t_date << " мая 2020." << endl;
						cout << "Время сеанса: " << bilet[i].t_time.hour << ":" << bilet[i].t_time.minute << endl;
						cout << "Название фильма: " << bilet[i].t_name << endl;
						cout << "Номер зала: " << bilet[i].t_numberh << endl;
						cout << "Ряд: " << bilet[i].t_place.raw_ << " Место: " << bilet[i].t_place.place_ << endl;
					}
					break;
				}
				case 8:
				{
					y = 0;
					break;
				}
				case 9:
					y = 0;
					f = 0;
				}
			}
			break;
		}
		case 3:
		{
			f = 0;
			break;
		}
		}
	}
	system("pause");
}