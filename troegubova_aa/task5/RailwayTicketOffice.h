#pragma once
#include <fstream> 
#include <vector>
#include <string>
#include <conio.h>
#include <iostream>

typedef unsigned int uint;

class Swallow
{
	const uint count_place_swallow = 100;
	const uint count_wagons_swallow = 8;
	int number_wagon;
	uint number_train;
	std::vector<int> numbers_place;
	std::vector<std::vector<uint>> passengers;
public:
	Swallow();
	Swallow(uint _number_train);
	~Swallow();

	uint GetNumderTrain();
	Swallow& operator =(const Swallow &_swallow);
	bool CheckAvailabilityOfTickets(uint count_tickets);
	void ReserveOfTickets(uint count_tickets);
	void CancelOrder(uint count_tickets);
	uint GetNumderWagon();
	std::vector<int> GetNumderPlace();
};

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class FastTrain
{
	const uint count_wagons_coupe = 4;
	const uint count_wagons_reserved_seat = 8;
	const uint count_place_coupe = 18;//колко пар мест
	const uint count_place_reserved_seat = 27;//кол-во пар
	int number_wagon; //номер вагона, в котором зарезервирован последний заказ
	uint number_train;
	std::vector<int> numbers_place;
	std::vector < std::vector<uint>> passengers;
public:
	FastTrain();
	FastTrain(uint _numder_train);
	~FastTrain();

	uint GetNumderTrain();
	FastTrain& operator =(const FastTrain &_fast_train);
	bool CheckAvailabilityOfTickets(uint count_tickets_lower, uint count_tickets_upper, std::string type_wagon);
	void ReserveOfTickets(uint count_tickets_lower, uint count_tickets_upper, std::string type_wagon);
	void CancelOrder(uint count_tickets_lower, uint count_tickets_upper, std::string type_wagon);
	uint GetNumderWagon();
	std::vector<int> GetNumderPlace();
};

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class FirmTrain
{
	const uint count_wagons_SV = 2;
	const uint count_wagons_coupe = 6;
	const uint count_wagons_reserved_seat = 4;
	const uint count_place_reserved_seat = 27;
	const uint count_place_coupe = 18;
	const uint count_place_SV = 18;
	int number_wagon; 
	uint number_train;
	std::vector<int> numbers_place;
	std::vector < std::vector<uint>> passengers;
public:
	FirmTrain();
	FirmTrain(uint _number_train);
	~FirmTrain();

	uint GetNumderTrain();
	FirmTrain& operator =(const FirmTrain &_firm_train);
	bool CheckAvailabilityOfTicketsSV(uint count_tickets);
	void ReserveOfTicketsSV(uint count_tickets);
	void CancelOrderSV(uint count_tickets);
	bool CheckAvailabilityOfTickets(uint count_tickets_lower, uint count_tickets_upper, std::string type_wagon);
	void ReserveOfTickets(uint count_tickets_lower, uint count_tickets_upper, std::string type_wagon);
	void CancelOrder(uint count_tickets_lower, uint count_tickets_upper, std::string type_wagon);
	uint GetNumderWagon();
	std::vector<int> GetNumderPlace();
};

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Date
{
	uint day, month, year;
public:
	Date();
	Date(uint _day, uint _month, uint _year);
	Date(const Date &other);
	~Date();

	void SetDate(uint _day, uint _month, uint _year);
	bool Check(uint _day, uint _month, uint _year);
	bool LeapYear(uint year);
	uint MaxDays(uint month, uint year);
	uint CountDays(const Date &date);
	uint DiffDay(const Date &first, const Date &second);
	Date& operator =(const Date &other);
	std::string DateString();
	friend std::istream& operator >>(std::istream &, Date &);
	friend std::ostream& operator <<(std::ostream &, const Date &);
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class OneDay
{
	Swallow swallows[6];
	FastTrain fact_trains[2];
	FirmTrain firm_trains[2];
	const uint first_line_trains[5] = {12, 15, 18, 75, 60};
	const uint second_line_trains[5] = {21, 24, 27, 80, 64};
public:
	OneDay();
	~OneDay();

	bool CheckAvailabilityOfTickets(uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth);
	void ReserveOfTickets( uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth);
	void CancelOrder( uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth);
	std::vector<std::string> GetLineTrain(uint _number_train);
	uint GetNumderWagon(uint _number_train);
	std::vector <int> GetNumderPlase(uint _number_train);
};

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Ticket
{
	Date date_flight;
	uint number_train;
	uint number_wagon;
	uint number_place;
	std::string full_name;
	std::string departure_station;
	std::string arrival_station;
public:
	Ticket();
	~Ticket();
	void SetTikcet(Date _date_flight, uint _nuber_train, uint _number_wagon, uint _number_place, std::string _full_name, std::string _deterture_station, std::string _arrival_station);
	std::string GetTikcet();
};

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class GorkyRailway
{
private:
	const uint lower_seat_price = 1500;
	const uint upper_seat_price = 1200;
	const uint swallow_price = 1000;
	const uint SV_prise = 5000;
	const double coefficient_firm_train = 1.2;
	const double coefficient_coupe = 1.8;
	std::vector<Ticket> tickets;
	OneDay monthly_train_schedule[30];
public:
	GorkyRailway();
	~GorkyRailway();
	friend class RailwayTicketOffice;
};
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class RailwayTicketOffice
{
private:
	Date today;
	Date date_flight;
	uint diffDay;
	uint number_train;
	std::string type_of_wagon;
	uint count_seating;
	uint count_upper_berth;
	uint count_lower_berth;
	uint flag; //flag = 1 данные уже введены, flag = 0 данные не введены, или заказ был отменён
	std::vector<std::string> full_names;
	GorkyRailway* gorky_railway;
public:	
	RailwayTicketOffice(GorkyRailway* gorky_railway);
	RailwayTicketOffice(Date _today, Date _date_flight, uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth, std::vector<std::string> _full_name, GorkyRailway* _gorky_railway);
	~RailwayTicketOffice();

	bool CheckDate();
	void SetData(Date _today, Date _date_flight, uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth, std::vector<std::string> _full_names);
	std::string CheckAvailabilityOfTickets();
	void ReserveOfTickets();
	double CostOfTickets();
	void CancelOrder();
	std::string GetOfTickets();
};