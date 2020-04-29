#include"RailwayTicketOffice.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

Swallow::Swallow() : number_wagon(-1), number_train(0)
{
	numbers_place.resize(0);
	passengers.resize(count_wagons_swallow);
}

Swallow::Swallow(uint _number_train) : number_wagon(-1), number_train(_number_train)
{
	numbers_place.resize(0);
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
	for (uint i = 0; i < count_wagons_swallow; i++)
	{
		if (passengers[i].size() <= count_place_swallow - count_tickets)
		{
			number_wagon = i;
			numbers_place.resize(0);
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
		for (size_t j = 0; j < count_tickets; j++)
		{
			passengers[number_wagon].push_back(passengers[number_wagon].size() + 1);
			numbers_place.push_back(passengers[number_wagon].size());
		}
	}
}

void Swallow::CancelOrder(uint count_tickets)
{
	for (size_t j = 0; j < count_tickets; j++)
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

uint Swallow::GetNumderWagon() 
{
	if (number_wagon != -1)
		return number_wagon + 1;
	else
	{
		throw;
	}
}

std::vector<int> Swallow::GetNumderPlace()
{
	if (number_wagon != -1)
		return numbers_place;
	else
	{
		throw;
	}
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

FastTrain::FastTrain() :number_wagon(-1), number_train(0)
{
	numbers_place.resize(0);
	passengers.resize((count_wagons_coupe + count_wagons_reserved_seat) * 2);
}

FastTrain::FastTrain(uint _number_train) : number_wagon(-1), number_train(_number_train)
{
	numbers_place.resize(0);
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
		for (size_t i = 0; i < count_wagons_coupe * 2; i++)
		{
			if (passengers[i].size() <= count_place_coupe - count_tickets_lower)
			{
				if (passengers[i++].size() <= count_place_coupe - count_tickets_upper)
				{
					number_wagon = i / 2;
					numbers_place.resize(0);
					return true;
				}
			}
		}
		return false;
	}
	else
	{
		if (type_wagon == "reserved seat")
		{

			for (size_t i = count_wagons_coupe * 2; i < passengers.size(); i++)
			{
				if (passengers[i].size() <= count_place_coupe - count_tickets_lower)
				{
					if (passengers[i++].size() <= count_place_coupe - count_tickets_upper)
					{
						number_wagon = i / 2;
						numbers_place.resize(0);
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
		for (size_t j = 0; j < count_tickets_lower; j++)
		{
			passengers[number_wagon].push_back(passengers[number_wagon].size() * 2);
			numbers_place.push_back(passengers[number_wagon].size() * 2 - 1 );
		}
		for (size_t j = 0; j < count_tickets_upper; j++)
		{
			int _number_wagon = number_wagon + 1;
			passengers[_number_wagon].push_back(passengers[_number_wagon].size() * 2 + 1);
			numbers_place.push_back(passengers[_number_wagon].size() * 2);
		}
	}
}

void FastTrain::CancelOrder(uint count_tickets_lower, uint count_tickets_upper, std::string type_wagon)
{
	for (size_t j = 0; j < count_tickets_lower; j++)
	{
		passengers[number_wagon].pop_back();
	}
	int _number_wagon = number_wagon + 1;
	for (size_t j = 0; j < count_tickets_upper; j++)
	{
		passengers[_number_wagon].pop_back();
	}
}

uint FastTrain::GetNumderWagon()
{
	if (number_wagon != -1)
		return number_wagon + 1;
	else
		throw;
}

std::vector<int> FastTrain::GetNumderPlace()
{
	if (number_wagon != -1)
		return numbers_place;
	else
		throw;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

FirmTrain::FirmTrain() : number_train(0), number_wagon(-1)
{
	numbers_place.resize(0);
	passengers.resize(count_wagons_coupe + 2 * (count_wagons_coupe + count_wagons_reserved_seat));
}

FirmTrain::FirmTrain(uint _number_train) : number_train(_number_train), number_wagon(0)
{
	numbers_place.resize(0);
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
			numbers_place.resize(0);
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
		for (size_t j = 0; j < count_tickets; j++)
		{
			passengers[number_wagon].push_back(passengers[number_wagon].size());
			numbers_place.push_back(passengers[number_wagon].size());
		}
	}
}

void FirmTrain::CancelOrderSV(uint count_tickets)
{
	for (size_t j = 0; j < count_tickets; j++)
	{
		passengers[number_wagon].pop_back();
	}
}

bool FirmTrain::CheckAvailabilityOfTickets(uint count_tickets_lower, uint count_tickets_upper, std::string type_wagon)
{
	if (type_wagon == "coupe")
	{
		for (size_t i = count_wagons_SV; i < count_wagons_coupe * 2; i++)
		{
			if (passengers[i].size() <= count_place_coupe - count_tickets_lower)
			{
				if (passengers[i++].size() <= count_place_coupe - count_tickets_upper)
				{
					number_wagon = i / 2 + 1;
					numbers_place.resize(0);
					return true;
				}
			}
		}
		return false;
	}
	else
	{
		if (type_wagon == "reserved seat")
		{

			for (size_t i = count_wagons_coupe * 2; i < passengers.size(); i++)
			{
				if (passengers[i].size() <= count_place_coupe - count_tickets_lower)
				{
					if (passengers[i++].size() <= count_place_coupe - count_tickets_upper)
					{
						number_wagon = i / 2;
						numbers_place.resize(0);
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
		for (size_t j = 0; j < count_tickets_lower; j++)
		{
			passengers[number_wagon].push_back(passengers[number_wagon].size() * 2);
			numbers_place.push_back(passengers[number_wagon].size() * 2 - 1);
		}
		for (size_t j = 0; j < count_tickets_upper; j++)
		{
			int _number_wagon = number_wagon + 1;
			passengers[_number_wagon].push_back(passengers[_number_wagon].size() * 2 + 1);
			numbers_place.push_back(passengers[_number_wagon].size() * 2);
		}
	}
}

void FirmTrain::CancelOrder(uint count_tickets_lower, uint count_tickets_upper, std::string type_wagon)
{
	for (size_t j = 0; j < count_tickets_lower; j++)
	{
		passengers[number_wagon].pop_back();
	}
	int _number_wagon = number_wagon + 1;
	for (size_t j = 0; j < count_tickets_upper; j++)
	{
		passengers[_number_wagon].pop_back();
	}
}

uint FirmTrain::GetNumderWagon()
{
	if (number_wagon != -1)
		return number_wagon + 1;
	else
		throw;
}

std::vector<int> FirmTrain::GetNumderPlace()
{
	if (number_wagon != -1)
		return numbers_place;
	else
		throw;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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
	else throw;
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
	for (size_t i = 0; i < date.month - 1; i++)
	{
		days += MaxDays(i + 1, date.year);
	}
	days += date.day;
	return days;
}

uint Date::DiffDay(const Date &first, const Date &second)
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

std::string Date::DateString()
{
	std::string date, buffer;
	Date *tmp = this;
	date = (tmp -> day < 10 ? "0" : "") + std::to_string(tmp->day);
	date += (tmp ->month < 10 ? ".0" : ".") + std::to_string(tmp -> month);
	date += "." + std::to_string(tmp->year);
	return date;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Ticket::Ticket(): number_train(0),number_wagon(0), number_place(0)
{
	full_name = " ";
	departure_station = " ";
	arrival_station = " ";
}

Ticket::~Ticket()
{}

void Ticket::SetTikcet(Date _date_flight, uint _number_train, uint _number_wagon, uint _number_place, std::string _full_name, std::string _departure_station, std::string _arrival_station)
{
	number_train = _number_train;
	number_wagon = _number_wagon;
	number_place = _number_place;
	date_flight = _date_flight;
	full_name = _full_name;
	departure_station = _departure_station;
	arrival_station = _arrival_station;
}

std::string Ticket::GetTikcet()
{
	std::string ticket = "Date flight: ";
	ticket = date_flight.DateString() + "     Number train: "  + std::to_string(number_train) + "    Number wagon: " + std::to_string(number_wagon);
	ticket += "    Number place: " + std::to_string(number_place) +  "    Full name: " + full_name + "     Departure_station: " + departure_station + "     Arrival station: " + arrival_station + "\n";
	return  ticket;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
GorkyRailway::GorkyRailway()
{};

GorkyRailway::~GorkyRailway()
{};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

OneDay::OneDay()
{
	for (uint i = 0; i < 6; i ++)
	{
		uint j = i;
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
			if ((_number_train >= 12) || (_number_train <= 27) || (_number_train % 3 == 0))
			{
				for (int i = 0; i < 6; i++)
				{
					if (swallows[i].GetNumderTrain() == _number_train)
						return swallows[i].CheckAvailabilityOfTickets(_count_seating);
				}
			}
			else
				 throw;
		}
	}
}

void OneDay::ReserveOfTickets( uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth)
{
	if ((_number_train == 75) || (_number_train == 80))
	{
		for (int i = 0; i < 2; i++)
		{
			if (fact_trains[i].GetNumderTrain() == _number_train)
			{
				fact_trains[i].ReserveOfTickets(_count_lower_berth, _count_upper_berth, _type_of_wagon);
				break;
			}
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
					{ 
						firm_trains[i].ReserveOfTicketsSV(_count_seating);
						break;
					}
					else
					{
						firm_trains[i].ReserveOfTickets(_count_lower_berth, _count_upper_berth, _type_of_wagon);
						break;
					}
			}
		}
		else
		{
			if ((_number_train >= 12) || (_number_train <= 27) || (_number_train % 3 == 0))
			{
				for (int i = 0; i < 6; i++)
				{
					if (swallows[i].GetNumderTrain() == _number_train)
					{
						swallows[i].ReserveOfTickets(_count_seating);
						break;
					}
				}
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
			{
				fact_trains[i].CancelOrder(_count_lower_berth, _count_upper_berth, _type_of_wagon);
				break;
			}
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
					{
						firm_trains[i].CancelOrderSV(_count_seating);
						break;
					}
					else
					{
						firm_trains[i].CancelOrder(_count_lower_berth, _count_upper_berth, _type_of_wagon);
						break;
					}
			}
		}
		else
		{
			if ((_number_train >= 12) || (_number_train <= 27) || (_number_train % 3 == 0))
			{
				for (int i = 0; i < 6; i++)
				{
					if (swallows[i].GetNumderTrain() == _number_train)
					{
						swallows[i].CancelOrder(_count_seating);
						break;
					}
				}
			}
		}
	}
}

std::vector <std::string> OneDay::GetLineTrain(uint _number_train)
{
	for (int i = 0; i < 5; i++)
	{
		if (_number_train == first_line_trains[i])
			return { "Nizhniy Novgorod: Moscow station", "Moscow: Kazan station" };
		if (_number_train == second_line_trains[i])
			return { "Moscow: Kazan station", "Nizhniy Novgorod: Moscow station" };
	}
}

uint OneDay::GetNumderWagon(uint _number_train)
{
	for (int i = 0; i < 6; i++)
	{
		if (swallows[i].GetNumderTrain() == _number_train)
			return swallows[i].GetNumderWagon();
		if (i < 2)
		{
			if (firm_trains[i].GetNumderTrain() == _number_train)
				return firm_trains[i].GetNumderWagon();
			if (fact_trains[i].GetNumderTrain() == _number_train)
				return fact_trains[i].GetNumderWagon();
		}
	}
}

std::vector<int> OneDay::GetNumderPlase(uint _number_train)
{
	for (uint i = 0; i < 6; i++)
	{
		if (swallows[i].GetNumderTrain() == _number_train)
			return swallows[i].GetNumderPlace();
		if (i < 2)
		{
			if (firm_trains[i].GetNumderTrain() == _number_train)
				return firm_trains[i].GetNumderPlace();
			if (fact_trains[i].GetNumderTrain() == _number_train)
				return fact_trains[i].GetNumderPlace();
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

RailwayTicketOffice::RailwayTicketOffice(): GorkyRailway(), diffDay(0), flag(0), number_train(0), count_seating(0), count_upper_berth(0), count_lower_berth(0)
{
	type_of_wagon = " ";
	full_names.resize(0);
}

RailwayTicketOffice::RailwayTicketOffice(Date _today, Date _date_flight, uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth, std::vector<std::string> _full_names) : GorkyRailway()
{
	SetData (_today, _date_flight, _number_train, _type_of_wagon, _count_seating, _count_upper_berth, _count_lower_berth, _full_names);
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
	diffDay = today.DiffDay(date_flight, today);
	type_of_wagon = _type_of_wagon;
	full_names.assign(_full_names.begin(), _full_names.end());
	flag = 1;
}

bool RailwayTicketOffice::CheckDate()
{
	if (flag)
	{
		if (diffDay > 30)
			return false;
		return true;
	}
	else
		throw;
}

std::string RailwayTicketOffice::CheckAvailabilityOfTickets()
{
	if (!CheckDate())
		return "Invalid date entered, enter the correct data";
	else
	{
		if (monthly_train_schedule[diffDay - 1].CheckAvailabilityOfTickets(number_train, type_of_wagon, count_seating, count_upper_berth, count_lower_berth))
			return "Tickets are available";
		else
			return "No tickets available";
	}
}

void RailwayTicketOffice::ReserveOfTickets()
{
	if (!CheckDate())
		throw "Invalid date entered";
	else
	{
		monthly_train_schedule[diffDay - 1].ReserveOfTickets( number_train, type_of_wagon, count_seating, count_upper_berth, count_lower_berth);
		Ticket now_ticket;
		for (size_t i = 0; i < count_seating + count_upper_berth + count_lower_berth; i++)
		{
			now_ticket.SetTikcet(date_flight, number_train, monthly_train_schedule[diffDay - 1].GetNumderWagon(number_train), monthly_train_schedule[diffDay - 1].GetNumderPlase(number_train)[i], full_names[i], monthly_train_schedule[diffDay - 1].GetLineTrain(number_train)[0], monthly_train_schedule[diffDay - 1].GetLineTrain(number_train)[1]);
			tickets.push_back(now_ticket);
		}
	}
}

void RailwayTicketOffice::CancelOrder()
{
	if (flag)
	{
		if (!CheckDate())
			throw "Invalid date entered";
		else
		{
			monthly_train_schedule[diffDay - 1].CancelOrder(number_train, type_of_wagon, count_seating, count_upper_berth, count_lower_berth);
			for (size_t i = 0; i < count_seating + count_upper_berth + count_lower_berth; i++)
			{
				tickets.pop_back();
			}
			flag = 0;
		}
	}
	else
		throw;
}

double RailwayTicketOffice::CostOfTickets()
{
	if (flag)
	{
		if (type_of_wagon == "SV")
			return SV_prise * count_seating;
		if (type_of_wagon == "swallow")
			return swallow_price * count_seating;
		if (type_of_wagon == "coupe")
		{
			if ((number_train = 75) || (number_train = 80))
				return (lower_seat_price * count_lower_berth + upper_seat_price * count_upper_berth) * coefficient_coupe;
			else
			{
				if ((number_train = 60) || (number_train = 64))
					return (lower_seat_price * count_lower_berth + upper_seat_price * count_upper_berth) * coefficient_coupe * coefficient_firm_train;
			}
		}
		else
		{
			if (type_of_wagon == "reserved seat")
			{
				if ((number_train = 75) || (number_train = 80))
					return lower_seat_price * count_lower_berth + upper_seat_price * count_upper_berth;
				else
				{
					if ((number_train = 60) || (number_train = 64))
						return (lower_seat_price * count_lower_berth + upper_seat_price * count_upper_berth) * coefficient_firm_train;
				}
			}
		}
	}
	else throw;
}

std::string RailwayTicketOffice::GetOfTickets()
{
	std::string _tickets;
	if (flag)
	{
		for (size_t i = tickets.size() - (count_lower_berth + count_upper_berth + count_seating); i < tickets.size(); i++)
		{
			_tickets += tickets[i].GetTikcet();
		}
		return _tickets;
	}
	else
		throw;
}