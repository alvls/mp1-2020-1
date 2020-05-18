#include <iostream>
#include <string>
#include <vector>
#include <string>

using namespace std;

class Seat
{
    private: 
        int price;
        bool status;
    public:
        Seat(int _price = 0, bool _status = true)
        {
            status = _status;
            price = _price;
        }
        int getPrice()
        {
            return price;
        }
        bool getStatus()
        {
            return status;
        }
        void book()
        {
            status = false;
        }
        void restore()
        {
            status = true;
        }
};

class Wagon
{
    private:
        int id;
        vector<Seat> seats;
    public:
        Wagon(vector<Seat> _seats = {})
        {
            seats = _seats;
        }
        vector<Seat> getSeats() {return seats;}
        void bookSeat(int seatIndex)
        {
            seats[seatIndex].book();
        }
        void restoreSeat(int seatIndex)
        {
            seats[seatIndex].restore();
        }
};

class Train
{
    private:
        int id;
        string stationFrom;
        string stationTo;
        vector<Wagon> wagons;
    public:
        Train(int _id, string _stationFrom, string _stationTo, vector<Wagon> _wagons)
        {
            id = _id;
            stationFrom = _stationFrom;
            stationTo = _stationTo;
            wagons = _wagons;
        }
        int getId() {return id;}
        string getStationFrom() {return stationFrom;}
        string getStationTo() {return stationTo;}
        vector<Wagon> getWagons() {return wagons;}
};