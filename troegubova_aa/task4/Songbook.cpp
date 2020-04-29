#include"Songbook.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <Windows.h>
#include <conio.h>
#include <fstream>

Song::Song()
{
	name_song = " ";
	poet = " ";
	composer = " ";
	singer = " ";
	name_album = " ";
	release_date = " ";
}

Song::Song(std::vector<std::string> _song)
{
	name_song = _song[0];
	poet = _song[1];
	composer = _song[2];
	singer = _song[3];
	name_album = _song[4];
	release_date = _song[5];
}

Song::Song(std::string _name_song, std::string _poet, std::string _composer, std::string _singer, std::string _name_album, std::string _release_date) :
	name_song(_name_song), poet(_poet), composer(_composer), singer(_singer), name_album(_name_album), release_date(_release_date)
{}

Song::Song(const Song &_song)
	: name_song(_song.name_song), poet(_song.poet), composer(_song.composer), singer(_song.singer), name_album(_song.name_album), release_date(_song.release_date)
{}

Song::~Song()
{}

void Song::ChangeDataOfSong(std::vector<std::string> _data)
{
	name_song = _data[0];
	poet = _data[1];
	composer = _data[2];
	singer = _data[3];
	name_album = _data[4];
	release_date = _data[5];
}

std::string Song::GetData(int index)
{
	std::vector<std::string> data = { name_song, poet, composer, singer, name_album, release_date };
	return data[index];
}

void Song::SetData(int index, std::string data)
{
	std::string * SetData[6];
	SetData[0] = &name_song;
	SetData[1] = &poet;
	SetData[2] = &composer;
	SetData[3] = &singer;
	SetData[4] = &name_album;
	SetData[5] = &release_date;

	*SetData[index] = data;

}

void Song::WriteConSong()
{
	for (size_t i = 0; i < 6; i++)
	{
		std::cout << std::left << "*  " << std::setw(25) << GetData(i);
	}
	std::cout << std::endl;
}

void Song::SaveInFileSong(std::fstream &file)
{

	for (size_t i = 0; i < 6; i++)
	{
		file << std::left << "*  " << std::setw(21) << GetData(i);
	}
	file << std::endl;
}

void Song::ReadFile(std::string new_song)
{
	int pos1, pos2;
	std::string new_data;
	for (int i = 0; i < 6; i++)
	{
		if (i == 5)
		{
			new_song.erase(0, 3);
			SetData(5, new_song);
			break;
		}
		pos1 = new_song.find("*", 0);
		pos2 = new_song.find("   ", 0);
		new_data = new_song.substr(pos1 + 3, pos2 - pos1 - 3);
		SetData(i, new_data);
		new_song.erase(0, 1);
		pos1 = new_song.find("*", 0);
		new_song.erase(0, pos1);
	}
}

//--------------------------------------------------------------------------------------

Songbook::Songbook()
{
	songs.resize(0);
}

Songbook::Songbook(const Songbook &_song)
{
	songs.assign(_song.songs.begin(), _song.songs.end());
}

Songbook::~Songbook()
{}

void Songbook::SetSong(std::vector<std::string> last_song)
{
	Song new_song(last_song);
	songs.push_back(new_song);
}

void Songbook::SetSong(Song new_song)
{
	songs.push_back(new_song);
}

int Songbook::GetCountOfSong()//узнать кол-во песен в песеннике
{
	return songs.size();
}

void Songbook::ChangeDataOfSong(std::string _song, std::vector<std::string> _data)//изменить данные о песне
{
	size_t i;
	for (i = 0; i < songs.size(); i++)
	{
		if (_song == songs[i].GetData(0))
		{
			songs[i].ChangeDataOfSong(_data);
			break;
		}
	}
	if (i == songs.size())
		throw "Песенник не содержит данную песню";
}


Song Songbook::GetSong(std::string _name_song, std::string _singer)//найти песню по назв. и исполнителю
{
	size_t i;
	for (i = 0; i < songs.size(); i++)
	{
		if (_name_song == songs[i].GetData(0))
		{
			if (_singer == songs[i].GetData(3))
			{
				break;
			}
		}
	}
	if (i == songs.size())
	{
		throw "Данная песня не содержится в песеннике";
	}
	return songs[i];
}

Songbook Songbook::GetDataOfSongs(std::string _name, std::string human)//выдать все песни поэта, композитора, певца
{
	size_t i;
	Songbook _songbook;
	int _human = 0;
	if (human == "poet")
	{
		_human = 1;
	}
	if (human == "composer")
	{
		_human = 2;
	}
	if (human == "singer")
	{
		_human = 3;
	}
	if (_human == 0)
		throw "Переданы неверные параметры";
	for (i = 0; i < songs.size(); i++)
	{
		if (_name == songs[i].GetData(_human))
		{
			_songbook.SetSong(songs[i]);
		}
	}
	if (_songbook.songs.size() == 0)
		throw "Искомые песни не найдены";
	return _songbook;
}

Songbook Songbook::GetSongsOfPoet(std::string _name)
{
	return this->GetDataOfSongs(_name, "poet");
}

Songbook Songbook::GetSongsOfComposer(std::string _name)
{
	return this->GetDataOfSongs(_name, "composer");
}

Songbook Songbook::GetSongsOfSinger(std::string _name)
{
	return this->GetDataOfSongs(_name, "singer");
}

void Songbook::DeleteSong(std::string _delete_song)//удалить песню
{
	size_t i;
	for (i = 0; i < songs.size(); i++)
	{
		if (_delete_song == songs[i].GetData(0))
		{
			songs.erase(songs.begin() + i);
			songs.shrink_to_fit();
			break;
		}
	}
	if (i == songs.size())
		throw "Песенник не содержит данную песню";
}

void Songbook::WriteConDataSong()
{
	for (size_t i = 0; i < 6; i++)
	{
		std::cout << std::left << "*  " << std::setw(25) << data_song[i];
	}
	std::cout << std::endl;
}

void Songbook::WriteConSongbook()
{
	WriteConDataSong();
	for (size_t i = 0; i < songs.size(); i++)
	{
		songs[i].WriteConSong();
	}
}

void Songbook::SaveInFileData(std::fstream &file)
{
	for (size_t i = 0; i < 6; i++)
	{
		file << std::left << "*  " << std::setw(21) << data_song[i];
	}
	file << std::endl;
}

void Songbook::SaveInFile()
{
	std::fstream file("Songbook2.txt", std::fstream::out);
	if (!file)
	{
		std::cout << "Не удалось открыть файл " << std::endl;
		exit(1);
	}
	else
	{
		SaveInFileData(file);
		for (size_t i = 0; i < songs.size(); i++)
		{
			songs[i].SaveInFileSong(file);
		}
	}
	file.close();
}

void Songbook::ReadFile()
{
	std::ifstream file("Songbook1.txt");
	std::string new_song;
	Song song;
	if (!file)
	{
		std::cout << "Не удалось открыть файл " << std::endl;
		exit(1);
	}
	else
	{
		getline(file, new_song);
		while (getline(file, new_song))
		{
			song.ReadFile(new_song);
			songs.push_back(song);
		}

	}
	file.close();
}
//-------------------------------------------------------------------------------

#include"RailwayTicketOffice.h"
#include <iostream>
#include <vector>
#include <string>

Swallow::Swallow() : number_wagon(0), number_train(0)
{
	passengers.resize(count_wagons_swallow);
}

Swallow::Swallow(uint _number_train) : number_wagon(0), number_train(_number_train)
{
	passengers.resize(count_wagons_swallow);
}

Swallow::~Swallow()
{}

uint Swallow::GetNumderTrain()
{
	return number_train;
}

bool Swallow::CheckAvailabilityOfTickets(uint count_tickets)
{
	for (size_t i = 0; i < count_wagons_swallow; i++)
	{
		if (passengers[i].size() <= count_place_swallow - count_tickets)
		{
			number_wagon = i;
			return true;
		}
	}
	return false;
}

void Swallow::ReserveOfTickets(uint count_tickets)
{
	if (!CheckAvailabilityOfTickets(count_tickets))
	{
		throw;
	}
	else
	{
		for (int j = 0; j < count_tickets; j++)
		{
			passengers[number_wagon].push_back(passengers[number_wagon].size() + 1);
		}
	}
}

void Swallow::CancelOrder(uint count_tickets)
{
	for (int j = 0; j < count_tickets; j++)
	{
		passengers[number_wagon].pop_back();
	}
}

Swallow& Swallow::operator =(const Swallow &_swallow)
{
	number_train = _swallow.number_train;
	number_wagon = _swallow.number_wagon;
	passengers.assign(_swallow.passengers.begin(), _swallow.passengers.end());
	return *this;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

FastTrain::FastTrain() :number_wagon(0), number_train(0)
{
	passengers.resize((count_wagons_coupe + count_wagons_reserved_seat) * 2);
}

FastTrain::FastTrain(uint _number_train) : number_wagon(0), number_train(_number_train)
{
	passengers.resize((count_wagons_coupe + count_wagons_reserved_seat) * 2);
}

FastTrain::~FastTrain()
{}

uint FastTrain::GetNumderTrain()
{
	return number_train;
}


FastTrain& FastTrain::operator =(const FastTrain &_fast_train)
{
	number_train = _fast_train.number_train;
	number_wagon = _fast_train.number_wagon;
	passengers.assign(_fast_train.passengers.begin(), _fast_train.passengers.end());
	return *this;
}

bool FastTrain::CheckAvailabilityOfTickets(uint count_tickets_lower, uint count_tickets_upper, std::string type_wagon)
{
	if (type_wagon == "coupe")
	{
		for (size_t i = 0; i < count_wagons_coupe * 2; i += 2)
		{
			if (passengers[i].size() <= count_place_coupe - count_tickets_lower)
			{
				if (passengers[i++].size() <= count_place_coupe - count_tickets_upper)
				{
					number_wagon = i / 2;
					return true;
				}
			}
		}
		return false;
	}
	else
	{
		if (type_wagon == "reserved_seat")
		{

			for (size_t i = count_wagons_coupe; i < passengers.size(); i += 2)
			{
				if (passengers[i].size() <= count_place_coupe - count_tickets_lower)
				{
					if (passengers[i++].size() <= count_place_coupe - count_tickets_upper)
					{
						number_wagon = i / 2;
						return true;
					}
				}
			}
			return false;
		}
		else
			throw;
	}
}

void FastTrain::ReserveOfTickets(uint count_tickets_lower, uint count_tickets_upper, std::string type_wagon)
{
	if (!CheckAvailabilityOfTickets(count_tickets_lower, count_tickets_upper, type_wagon))
	{
		throw;
	}
	else
	{
		for (int j = 0; j < count_tickets_lower; j++)
		{
			passengers[number_wagon].push_back(passengers[number_wagon].size() + 1);
		}
		for (int j = 0; j < count_tickets_upper; j++)
		{
			int _number_wagon = number_wagon + 1;
			passengers[_number_wagon].push_back(passengers[_number_wagon].size() + 1);
		}
	}
}

void FastTrain::CancelOrder(uint count_tickets_lower, uint count_tickets_upper, std::string type_wagon)
{
	for (int j = 0; j < count_tickets_lower; j++)
	{
		passengers[number_wagon].pop_back();
	}
	int _number_wagon = number_wagon + 1;
	for (int j = 0; j < count_tickets_upper; j++)
	{
		passengers[_number_wagon].pop_back();
	}
}

//----------------------------------------------------------------------------------------------------------------------------------------------

FirmTrain::FirmTrain() : number_train(0), number_wagon(0)
{
	passengers.resize(count_wagons_coupe + 2 * (count_wagons_coupe + count_wagons_reserved_seat));
}

FirmTrain::FirmTrain(uint _number_train) : number_train(_number_train), number_wagon(0)
{
	passengers.resize(count_wagons_coupe + 2 * (count_wagons_coupe + count_wagons_reserved_seat));
}

FirmTrain::~FirmTrain()
{}

uint FirmTrain::GetNumderTrain()
{
	return number_train;
}

FirmTrain& FirmTrain:: operator =(const FirmTrain &_firm_train)
{
	number_train = _firm_train.number_train;
	number_wagon = _firm_train.number_wagon;
	passengers.assign(_firm_train.passengers.begin(), _firm_train.passengers.end());
	return *this;
}

bool FirmTrain::CheckAvailabilityOfTicketsSV(uint count_tickets)
{
	for (size_t i = 0; i < count_wagons_SV; i++)
	{
		if (passengers[i].size() <= count_place_SV - count_tickets)
		{
			number_wagon = i;
			return true;
		}
	}
	return false;
}

void FirmTrain::ReserveOfTicketsSV(uint count_tickets)
{
	if (!CheckAvailabilityOfTicketsSV(count_tickets))
	{
		throw;
	}
	else
	{
		for (int j = 0; j < count_tickets; j++)
		{
			passengers[number_wagon].push_back(passengers[number_wagon].size() + 1);
		}
	}
}

void FirmTrain::CancelOrderSV(uint count_tickets)
{
	for (int j = 0; j < count_tickets; j++)
	{
		passengers[number_wagon].pop_back();
	}
}

bool FirmTrain::CheckAvailabilityOfTickets(uint count_tickets_lower, uint count_tickets_upper, std::string type_wagon)
{
	if (type_wagon == "coupe")
	{
		for (size_t i = count_wagons_SV; i < count_wagons_coupe * 2; i += 2)
		{
			if (passengers[i].size() <= count_place_coupe - count_tickets_lower)
			{
				if (passengers[i++].size() <= count_place_coupe - count_tickets_upper)
				{
					number_wagon = i / 2;
					return true;
				}
			}
		}
		return false;
	}
	else
	{
		if (type_wagon == "reserved_seat")
		{

			for (size_t i = count_wagons_coupe; i < passengers.size(); i += 2)
			{
				if (passengers[i].size() <= count_place_coupe - count_tickets_lower)
				{
					if (passengers[i++].size() <= count_place_coupe - count_tickets_upper)
					{
						number_wagon = i / 2;
						return true;
					}
				}
			}
			return false;
		}
		else
			throw;
	}
}

void FirmTrain::ReserveOfTickets(uint count_tickets_lower, uint count_tickets_upper, std::string type_wagon)
{
	if (!CheckAvailabilityOfTickets(count_tickets_lower, count_tickets_upper, type_wagon))
	{
		throw;
	}
	else
	{
		for (int j = 0; j < count_tickets_lower; j++)
		{
			passengers[number_wagon].push_back(passengers[number_wagon].size() + 1);
		}
		for (int j = 0; j < count_tickets_upper; j++)
		{
			int _number_wagon = number_wagon + 1;
			passengers[_number_wagon].push_back(passengers[_number_wagon].size() + 1);
		}
	}
}

void FirmTrain::CancelOrder(uint count_tickets_lower, uint count_tickets_upper, std::string type_wagon)
{
	for (int j = 0; j < count_tickets_lower; j++)
	{
		passengers[number_wagon].pop_back();
	}
	int _number_wagon = number_wagon + 1;
	for (int j = 0; j < count_tickets_upper; j++)
	{
		passengers[_number_wagon].pop_back();
	}
}
//--------------------------------------------------------------------------------------------

Date::Date()
{
	SetDate(1, 1, 2020);
}

Date::Date(uint _day, uint _month, uint _year)
{
	SetDate(_day, _month, _year);
}

Date::Date(const Date &other)
{
	SetDate(other.day, other.month, other.year);
}

Date::~Date()
{}


void Date::SetDate(uint _day, uint _month, uint _year)
{
	if (Check(_day, _month, _year))
	{
		year = _year;
		month = _month;
		day = _day;
	}
}

bool Date::Check(uint _day, uint _month, uint _year)
{
	if (_year < 2020)
		return false;
	if (_month > 12)
		return false;
	if (_day > MaxDays(_month, _year))
		return false;
	return true;

}

bool Date::LeapYear(uint year)
{
	bool leap = false;
	if (year % 4 == 0) leap = true;
	if (year % 100 == 0) leap = false;
	if (year % 400 == 0) leap = true;
	return leap;

}

uint Date::MaxDays(uint month, uint year)
{
	uint days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (LeapYear(year))
		days[1] = 29;
	return days[month - 1];
}

uint Date::CountDays(const Date &date)
{
	uint days;
	days = (date.year - 2020) * 365 + ((date.year - 2020) * 365) % 4 + 1;
	for (int i = 0; i < date.month - 1; i++)
	{
		days += MaxDays(date.month, date.year);
	}
	days += date.day;
	return days;


}

int Date::DiffDay(const Date &first, const Date &second)
{
	return CountDays(first) - CountDays(second);
}

std::istream& operator >>(std::istream &in, Date &date)
{
	char c;
	in >> date.day >> c >> date.month >> c >> date.year;
	return in;
}

std::ostream& operator <<(std::ostream &out, const Date &date)
{
	std::string res = (date.day < 10 ? "0" : "") + std::to_string(date.day);
	res += (date.month < 10 ? ".0" : ".") + std::to_string(date.month);
	res += "." + std::to_string(date.year);
	out << res;
	return out;
}

Date& Date::operator =(const Date &other)
{
	day = other.day;
	month = other.month;
	year = other.year;
	return *this;
}

GorkyRailway::GorkyRailway()
{};

GorkyRailway::~GorkyRailway()
{};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

OneDay::OneDay()
{
	for (int i = 0; i < 6; i++)
	{
		int j = i;
		swallows[i] = Swallow((i + 4) * 3);
		if (j < 2)
		{
			fact_trains[i] = FastTrain((i + 15) * 5);
			firm_trains[i] = FirmTrain((i + 15) * 4);
		}
	}

}

OneDay::~OneDay()
{};

bool OneDay::CheckAvailabilityOfTickets(uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth)
{
	if ((_number_train == 75) || (_number_train == 80))
	{
		for (int i = 0; i < 2; i++)
		{
			if (fact_trains[i].GetNumderTrain() == _number_train)
				return fact_trains[i].CheckAvailabilityOfTickets(_count_lower_berth, _count_upper_berth, _type_of_wagon);
		}
	}
	else
	{
		if ((_number_train == 64) || (_number_train == 60))
		{
			for (int i = 0; i < 2; i++)
			{
				if (firm_trains[i].GetNumderTrain() == _number_train)
					if (_type_of_wagon == "SV")
						return firm_trains[i].CheckAvailabilityOfTicketsSV(_count_seating);
					else
						return firm_trains[i].CheckAvailabilityOfTickets(_count_lower_berth, _count_upper_berth, _type_of_wagon);
			}

		}
		else
		{
			for (int i = 0; i < 6; i++)
			{
				if (swallows[i].GetNumderTrain() == _number_train)
					return swallows[i].CheckAvailabilityOfTickets(_count_seating);
			}
		}
	}
}

void OneDay::ReserveOfTickets(uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth)
{
	if ((_number_train == 75) || (_number_train == 80))
	{
		for (int i = 0; i < 2; i++)
		{
			if (fact_trains[i].GetNumderTrain() == _number_train)
				fact_trains[i].ReserveOfTickets(_count_lower_berth, _count_upper_berth, _type_of_wagon);
		}
	}
	else
	{
		if ((_number_train == 64) || (_number_train == 60))
		{
			for (int i = 0; i < 2; i++)
			{
				if (firm_trains[i].GetNumderTrain() == _number_train)
					if (_type_of_wagon == "SV")
						firm_trains[i].ReserveOfTicketsSV(_count_seating);
					else
						firm_trains[i].ReserveOfTickets(_count_lower_berth, _count_upper_berth, _type_of_wagon);
			}

		}
		else
		{
			for (int i = 0; i < 6; i++)
			{
				if (swallows[i].GetNumderTrain() == _number_train)
					swallows[i].ReserveOfTickets(_count_seating);
			}
		}
	}
}

void OneDay::CancelOrder(uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth)
{
	if ((_number_train == 75) || (_number_train == 80))
	{
		for (int i = 0; i < 2; i++)
		{
			if (fact_trains[i].GetNumderTrain() == _number_train)
				fact_trains[i].CancelOrder(_count_lower_berth, _count_upper_berth, _type_of_wagon);
		}
	}
	else
	{
		if ((_number_train == 64) || (_number_train == 60))
		{
			for (int i = 0; i < 2; i++)
			{
				if (firm_trains[i].GetNumderTrain() == _number_train)
					if (_type_of_wagon == "SV")
						firm_trains[i].CancelOrderSV(_count_seating);
					else
						firm_trains[i].CancelOrder(_count_lower_berth, _count_upper_berth, _type_of_wagon);
			}
		}
		else
		{
			for (int i = 0; i < 6; i++)
			{
				if (swallows[i].GetNumderTrain() == _number_train)
					swallows[i].CancelOrder(_count_seating);
			}
		}
	}
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

RailwayTicketOffice::RailwayTicketOffice() :number_train(0), count_seating(0), count_upper_berth(0), count_lower_berth(0)
{
	type_of_wagon = " ";
	full_names.resize(0);
}

RailwayTicketOffice::RailwayTicketOffice(Date _today, Date _date_flight, uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth, std::vector<std::string> _full_names)
{
	SetData(_today, _date_flight, _number_train, _type_of_wagon, _count_seating, _count_upper_berth, _count_lower_berth, _full_names);
}

RailwayTicketOffice::~RailwayTicketOffice()
{}

void RailwayTicketOffice::SetData(Date _today, Date _date_flight, uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth, std::vector<std::string> _full_names)
{
	number_train = _number_train;
	count_seating = _count_seating;
	count_upper_berth = _count_upper_berth;
	count_lower_berth = _count_lower_berth;
	today = _today;
	date_flight = _date_flight;
	type_of_wagon = _type_of_wagon;
	full_names.assign(_full_names.begin(), _full_names.end());
}

bool RailwayTicketOffice::CheckDate()
{
	if (today.DiffDay(today, date_flight) > 30)
		return false;
	return true;
}

std::string RailwayTicketOffice::CheckAvailabilityOfTickets(Date _today, Date _date_flight, uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth)
{
	if (!CheckDate(_today, _date_flight))
		return "Invalid date entered";
	else
	{
		if (monthly_train_schedule[_today.DiffDay(_today, _date_flight) - 1].CheckAvailabilityOfTickets(_number_train, _type_of_wagon, _count_seating, _count_upper_berth, _count_lower_berth))
			return "Tickets are available";
		else
			return "No tickets available";
	}
}

void RailwayTicketOffice::ReserveOfTickets(Date _today, Date _date_flight, uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth)
{
	if (!CheckDate())
		throw "Invalid date entered";
	else
	{
		monthly_train_schedule[_today.DiffDay(_today, _date_flight) - 1].ReserveOfTickets(_number_train, _type_of_wagon, _count_seating, _count_upper_berth, _count_lower_berth);
	}
}

void RailwayTicketOffice::CancelOrder(Date _today, Date _date_flight, uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth)
{
	if (!CheckDate())
		throw "Invalid date entered";
	else
	{
		monthly_train_schedule[_today.DiffDay(_today, _date_flight) - 1].CancelOrder(_number_train, _type_of_wagon, _count_seating, _count_upper_berth, _count_lower_berth);
	}
}