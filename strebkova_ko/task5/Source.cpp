#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

bool Compare_Time(tm time, tm _time)
{
	if ((time.tm_year == _time.tm_year) && (time.tm_mon == _time.tm_mon) && (time.tm_mday == _time.tm_mday) && (time.tm_hour == _time.tm_hour) && (time.tm_min == _time.tm_min))
		return true;
	else
		return false;
}

class Place
{
private:
	int row;
	int col;
public:
	Place(int _row, int _col):row(_row), col(_col) {}

	~Place() {}

	int Get_Col()
	{
		return col;
	}

	int Get_Row()
	{
		return row;
	}

	Place(const Place& place)
	{
		col = place.col;
		row = place.row;
	}

	Place& operator=(const Place& place)
	{
		col = place.col;
		row = place.row;
		return *this;
	}

	bool operator==(const Place &place)
	{
		if ((row == place.row) && (col == place.col))
			return true;
		else
			return false;
	}
};

class Hall
{
private:
	int number_of_hall;
	int vip_price;
	int base_price;
	int cols;
	int rows;
public:
	Hall(int _number_of_hall = 0, int _vip_price = 0, int _base_price = 0, int _cols = 0, int _rows = 0):number_of_hall(_number_of_hall), vip_price(_vip_price), base_price(_base_price),
		cols(_cols), rows(rows)
	{}

	~Hall() {}

	Hall (const Hall& hall)
	{
		number_of_hall = hall.number_of_hall;
		vip_price = hall.vip_price;
		base_price = hall.base_price;
		cols = hall.cols;
		rows = hall.rows;
	}

	Hall& operator=(const Hall &hall)
	{
		number_of_hall = hall.number_of_hall;
		vip_price = hall.vip_price;
		base_price = hall.base_price;
		cols = hall.cols;
		rows = hall.rows;
		return *this;
	}

	bool operator== (const Hall &hall)
	{
		if (number_of_hall == hall.number_of_hall)
			return true;
		else
			return false;
	}

	int Get_Number_Of_Hall()
	{
		return number_of_hall;
	}

	int Get_Vip_Price()
	{
		return vip_price;
	}

	int Get_Base_Price()
	{
		return base_price;
	}

	int Get_Cols()
	{
		return cols;
	}

	int Get_Rows()
	{
		return rows;
	}
};

class Seance
{
private:
	tm time;
	string name_of_film;
	Hall hall;
	vector <Place> unavailible_place;
public:
	Seance(tm _time = tm(), string _name_of_film = "", Hall _hall = Hall(), vector <Place> _unavailible_place = {}) : 
		time(_time), name_of_film(_name_of_film), hall(_hall), unavailible_place(_unavailible_place) {}

	~Seance() {}

	Seance(const Seance &seance)
	{
		time = seance.time;
		name_of_film = seance.name_of_film;
		hall = seance.hall;
		unavailible_place = seance.unavailible_place;
	}

	Seance& operator= (const Seance &seance)
	{
		time = seance.time;
		name_of_film = seance.name_of_film;
		hall = seance.hall;
		unavailible_place = seance.unavailible_place;
		return *this;
	}

	bool operator== (const Seance &seance)
	{
		if ((Compare_Time(time, seance.time) == true) && (name_of_film == seance.name_of_film) && (hall == seance.hall))
			return true;
		else
			return false;
	}

	tm Get_Time()
	{
		return time;
	}

	string Get_Name_Of_Film()
	{
		return name_of_film;
	}

	Hall Get_Hall()
	{
		return hall;
	}

	vector <Place> Get_Unavailible_Place()
	{
		return unavailible_place;
	}

	int Find_Number_Of_Place(const Place &place)
	{
		for (int i = 0; i < unavailible_place.size(); i++)
		{
			if (unavailible_place[i] == place)
				return i;
		}
	}

	void Add_Unavailible_Place(const Place &place)
	{
		unavailible_place.push_back(place);
	}

	void Delete_Unavailible_Place(const Place &place)
	{
		int i = Find_Number_Of_Place(place);
		unavailible_place.erase(unavailible_place.begin() + i);
	}

	void Show_Seance()
	{
		cout << "Дата: " << time.tm_mday << "." << time.tm_mon << "." << time.tm_year << endl << "Время: " << time.tm_hour << ":" << time.tm_min << endl << "Название фильма:" << name_of_film << endl;
		cout << "Номер зала: " << hall.Get_Number_Of_Hall() << endl;
	}
};

class Cinema
{
private:
	vector <Seance> seances;
	vector <Hall> halls;
public:
	Cinema() {}
	~Cinema() {}

	void Add_Seance(Seance& seance)
	{
		seances.push_back(seance);
	}

	void Add_Hall(Hall& hall)
	{
		halls.push_back(hall);
	}

	vector<Seance> Get_Seances()
	{
		return seances;
	}

	int Find_Number_Of_Seance(Seance &seance)
	{
		for (int i = 0; i < seances.size(); i++)
			if (seance == seances[i])
				return i;
	}

	void Add_Unavailible_Place(const Place &place, int j)
	{
		seances[j].Add_Unavailible_Place(place);
	}

	void Delete_Unavailible_Place(const Place &place, int j)
	{
		seances[j].Delete_Unavailible_Place(place);
	}
};

class Order
{
private:
	Seance seance;
	vector <Place> places;
	bool type;
public:
	Order(Seance _seance = Seance(), vector <Place> _places = {}, bool _type = false) : seance(_seance), places(_places), type(_type) {}

	~Order() {}

	Order(Order &order)
	{
		seance = order.seance;
		places = order.places;
		type = order.type;
	}

	Order& operator=(const Order &order)
	{
		seance = order.seance;
		places = order.places;
		type = order.type;
		return *this;
	}

	Seance Get_Seance()
	{
		return seance;
	}

	bool Get_Type()
	{
		return type;
	}

	vector <Place> Get_Places()
	{
		return places;
	}

	int Get_Count_Of_Places()
	{
		return places.size();
	}

	void Show_Order()
	{
		for (int i = 0; i < places.size(); i++)
		{
			cout << "Билет" << endl;
			seance.Show_Seance();
			cout << "Ряд: " << places[i].Get_Row() << endl << "Место: " << places[i].Get_Col() << endl;
		}
	}
};

class TicketOffice
{
private:
	Cinema cinema;
public:
	TicketOffice(Cinema _cinema = Cinema()): cinema(_cinema) {}

	~TicketOffice() {}

	TicketOffice(const TicketOffice &ticket_office)
	{
		cinema = ticket_office.cinema;
	}

	TicketOffice& operator=(const TicketOffice &ticket_office)
	{
		cinema = ticket_office.cinema;
		return *this;
	}

	Cinema Get_Cinema()
	{
		return cinema;
	}

	Order Accept_Data(int day, int month, int year, int hour, int min, string name_of_film, int number_of_hall, bool type, vector <Place> places)
	{
		vector <Seance> seances = cinema.Get_Seances();
		Hall hall;
		tm time;
		time.tm_mday = day;
		time.tm_mon = month;
		time.tm_year = year;
		time.tm_min = min;
		time.tm_hour = hour;
		int i;
		for (i = 0; i < seances.size(); i++)
		{
			hall = seances[i].Get_Hall();
			if ((Compare_Time(seances[i].Get_Time(), time) == true) && (seances[i].Get_Name_Of_Film() == name_of_film) && (hall.Get_Number_Of_Hall() == number_of_hall))
				break;
		}
		Order order = Order(seances[i], places, type);
		return order;
	}

	bool Check_Free_Place(Order &order)
	{
		bool flag = true;
		Seance seance = order.Get_Seance();
		vector <Place> places = order.Get_Places();
		Hall hall = seance.Get_Hall();
		for (int i = 0; i < places.size(); i++)
		{
			vector <Place> unavailible_place = seance.Get_Unavailible_Place();
			for (int j = 0; j < unavailible_place.size(); j++)
			{
				if (places[i] == unavailible_place[j])
				{
					flag = false;
					break;
				}
			}
		}
		return flag;
	}

	void Reserve_Places(Order &order)
	{
		vector <Place> places = order.Get_Places();
		Seance seance = order.Get_Seance();
		int j = cinema.Find_Number_Of_Seance(seance);
		time_t now;
		time(&now);
		tm _time = seance.Get_Time();
		_time.tm_year -= 1900;
		_time.tm_mon -= 1;
		_time.tm_sec = 0;
		if (Check_Free_Place(order) == true)
		{
			if (difftime(now, mktime(&_time)) < 600)
			{
				tm *_now = localtime(&now);
				_now->tm_hour = 0;
				_now->tm_min = 0;
				_now->tm_sec = 0;
				now = mktime(_now);
				_time.tm_hour = 0;
				_time.tm_min = 0;
				if (difftime(mktime(&_time), now) < 345600)
					for (int i = 0; i < places.size(); i++)
						cinema.Add_Unavailible_Place(places[i], j);

				else
					cout << "Продажа билетов еще не началась!" << endl;
			}
			else
				cout << "Продажа билетов закончилась!" << endl;
		}
		else
			cout << "Невозможно зарезервировать билеты" << endl;
	}

	double Calculate_Sum(Order &order)
	{
		Seance seance = order.Get_Seance();
		Hall hall = seance.Get_Hall();
		double price;
		tm time = seance.Get_Time();
		bool type = order.Get_Type();
		if (type == true)
			price = hall.Get_Vip_Price();
		else
			price = hall.Get_Base_Price();
		float koef = 1;
		if ( time.tm_hour < 12)
			koef = 0.75;
		if (time.tm_hour > 18)
			koef = 1.5;
		return price * koef * order.Get_Count_Of_Places();
	}

	void Cancel_Place(Order &order)
	{
		Seance seance = order.Get_Seance();
		vector <Place> places = order.Get_Places();
			int j = cinema.Find_Number_Of_Seance(seance);
			for (int i = 0; i < places.size(); i++)
				cinema.Delete_Unavailible_Place(places[i], j);
	}

	void Show_Ticket (Order &order)
	{
		order.Show_Order();
	}
};

void main()
{
	setlocale(LC_ALL, "Rus");
	Cinema cinema;
	Hall hall = Hall(1, 300, 150, 15, 20);
	cinema.Add_Hall(hall);
	tm time;
	time.tm_year = 2020;
	time.tm_mon = 4;
	time.tm_mday = 30;
	time.tm_hour = 13;
	time.tm_min = 30;
	Seance seance = Seance(time, "The Lion King", hall);
	cinema.Add_Seance(seance);
	TicketOffice ticket_office = TicketOffice(cinema);
	Order order1 = ticket_office.Accept_Data(30, 4, 2020, 13, 30, "The Lion King", hall.Get_Number_Of_Hall(), 0, { Place(15, 10) });
	ticket_office.Reserve_Places(order1);
	ticket_office.Cancel_Place(order1);
	Order order2 = ticket_office.Accept_Data(30, 4, 2020, 13, 30, "The Lion King", hall.Get_Number_Of_Hall(), 0, { Place(15, 10), Place(15, 9) });
	if (ticket_office.Check_Free_Place(order2))
		cout << "Места свободны" << endl;
	else
		cout << "Места заняты" << endl;
	cout << "Общая сумма: " << ticket_office.Calculate_Sum(order2) << endl;
	ticket_office.Reserve_Places(order2);
	ticket_office.Show_Ticket(order2);
	system("pause");
}
