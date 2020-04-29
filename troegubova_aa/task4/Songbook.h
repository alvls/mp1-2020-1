#pragma once
#include <fstream> 
#include <vector>
#include <string>
#include <conio.h>
#include <iostream>
#include <iomanip>

const std::vector<std::string> data_song = { "Название песни:", "Автор слов:", "Композитор:", "Исполнитель:", "Альбома:", "Дата выпуска:" };

class Song
{
	std::string name_song;
	std::string poet;
	std::string composer;
	std::string singer;
	std::string name_album;
	std::string release_date;
public:
	Song();
	Song(std::vector<std::string> _song);
	Song(std::string _name_song, std::string _poet, std::string _composer, std::string _singer, std::string _name_album, std::string _release_date);
	Song(const Song &_song);
	~Song();

	void Song::SetData(int index, std::string data);
	void ChangeDataOfSong(std::vector<std::string> _data);
	void WriteConSong();
	std::string GetData(int index);
	void ReadFile(std::string new_song);
	void SaveInFileSong(std::fstream &file);
};

//-------------------------------------------------------------------------------------------------------------------------------------------

class Songbook
{
	std::vector <Song> songs;
	void Songbook::WriteConDataSong();
	void SaveInFileData(std::fstream &file);
	Songbook GetDataOfSongs(std::string _name, std::string human);
public:
	Songbook();
	Songbook(const Songbook &_song);
	~Songbook();

	void SetSong(std::vector<std::string> last_song);
	void SetSong(Song new_song);
	int GetCountOfSong();
	void ChangeDataOfSong(std::string _song, std::vector<std::string> _data);
	Song GetSong(std::string _name_song, std::string _singer);
	Songbook GetSongsOfPoet(std::string _name);
	Songbook GetSongsOfComposer(std::string _name);
	Songbook GetSongsOfSinger(std::string _name);
	void DeleteSong(std::string _delete_song);
	void WriteConSongbook();
	void SaveInFile();
	void ReadFile();
};
//------------------------------------------------------------------------------
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
	uint number_wagon;
	uint number_train;
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
};

class FastTrain
{
	const uint count_wagons_coupe = 4;
	const uint count_wagons_reserved_seat = 8;
	const uint count_place_coupe = 18;//колко пар мест
	const uint count_place_reserved_seat = 27;//кол-во пар
	uint number_wagon; //номер вагона, в котором зарезервированы билеты
	uint number_train;
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
};

class FirmTrain
{
	const uint count_wagons_SV = 2;
	const uint count_wagons_coupe = 6;
	const uint count_wagons_reserved_seat = 4;
	const uint count_place_reserved_seat = 27;
	const uint count_place_coupe = 18;
	const uint count_place_SV = 18;
	uint number_wagon;
	uint number_train;
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
};

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
	int DiffDay(const Date &first, const Date &second);
	Date& operator =(const Date &other);
	friend std::istream& operator >>(std::istream &, Date &);
	friend std::ostream& operator <<(std::ostream &, const Date &);
};

class OneDay
{
	Swallow swallows[6];
	FastTrain fact_trains[2];
	FirmTrain firm_trains[2];
public:
	OneDay();
	~OneDay();

	bool CheckAvailabilityOfTickets(uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth);
	void ReserveOfTickets(uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth);
	void CancelOrder(uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth);

};

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
class GorkyRailway
{
protected:
	const std::string station[2] = { " ", " " };
	const uint lower_seat_price = 1500;
	const uint upper_seat_price = 1200;
	const uint swallow_price = 1000;
	const uint SV_prise = 3000;
	const uint coefficient_firm_train = 2;
	Date date_flight;
	uint number_train;
	std::string type_of_wagon;
	uint count_seating;
	uint count_upper_berth;
	uint count_lower_berth;
	OneDay monthly_train_schedule[30];
public:
	GorkyRailway();
	~GorkyRailway();


};

class RailwayTicketOffice : public GorkyRailway
{
private:
	Date today;
	Date date_flight;
	uint number_train;
	std::string type_of_wagon;
	uint count_seating;
	uint count_upper_berth;
	uint count_lower_berth;
	uint flag; //flag = 1 данные уже введены, flag = 0 данные не введены
	std::vector<std::string> full_names;
public:
	RailwayTicketOffice();
	RailwayTicketOffice(Date _today, Date _date_flight, uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth, std::vector<std::string> _full_name);
	~RailwayTicketOffice();

	bool CheckDate();
	void SetData(Date _today, Date _date_flight, uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth, std::vector<std::string> _full_name);
	std::string CheckAvailabilityOfTickets(Date _today, Date _date_flight, uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth);
	void ReserveOfTickets(Date _today, Date _date_flight, uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth);
	uint CostOfTickets(uint numder_train, std::string type_of_wagon, uint count_seating, uint count_upper_berth, uint count_lower_berth);
	void CancelOrder(Date _torday, Date _date_flight, uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth);
	std::string GetOfTickets(std::string _date, uint _number_train, std::string _type_of_wagon, uint _count_seating, uint _count_upper_berth, uint _count_lower_berth, std::string _full_name);
};