#include <iostream>
#include <vector>
#include <string>
#include "Train.h"
#include "Date.h"

using namespace std;

class Ticket
{
    public:
        string name;
        Date date;
        int trainId;
        int wagonId;
        int seatId;
        string stationFrom;
        string stationTo;
        Ticket(string _name, Date _date, int _trainId, int _wagonId, int _seatId, string _stationFrom, string _stationTo)
        {
            date = _date;
            name = _name;
            trainId = _trainId;
            wagonId = _wagonId;
            seatId = _seatId;
            stationFrom = _stationFrom;
            stationTo = _stationTo;
        }
};

class Order
{
    public:
        Date date;
        int trainIndex;
        vector<pair< string, pair< int, int > >> seats;

};

class TicketService
{
    private:
        vector<Train> trains;
    public:
        TicketService(vector<Train> _trains)
        {
            trains = _trains;
        }
        bool checkSeats(Order order)
        {
            for (auto seat: order.seats)
            {
                if (!trains[order.trainIndex].getWagons()[seat.second.first].getSeats()[seat.second.second].getStatus()) 
                    return false;
            }
            return true;
        }
        bool bookSeats(Order order)
        {
            if (!checkSeats(order)) return false;
            for (auto seat: order.seats)
            {
                trains[order.trainIndex].getWagons()[seat.second.first].bookSeat(seat.second.second);
            }
        }
        bool restoreSeats(Order order)
        {
            if (!checkSeats(order)) return false;
            for (auto seat: order.seats)
            {
                trains[order.trainIndex].getWagons()[seat.second.first].restoreSeat(seat.second.second);
            }
            return true;
        }
        int orderTotal(Order order)
        {
            int total = 0;
            for (auto seat: order.seats)
            {
                total += trains[order.trainIndex].getWagons()[seat.second.first].getSeats()[seat.second.second].getPrice();
            }
            return total;
        }
        vector<Ticket> processOrder(Order order)
        {
            int trainId = trains[order.trainIndex].getId();
            string stationFrom = trains[order.trainIndex].getStationFrom();
            string stationTo = trains[order.trainIndex].getStationTo();
            vector<Ticket> tickets;
            for (auto seat: order.seats)
            {
                tickets.push_back(Ticket(seat.first, order.date, trainId, seat.second.first+1, seat.second.second+1, stationFrom, stationTo));
            }
            return tickets;
        }
};
class GorkyRailway
{
    private:
        vector<TicketService> ts;
    public:
        GorkyRailway(vector<TicketService> _ts)
        {
            ts = _ts;
        }
        TicketService operator[](size_t index)
        {
            return ts[index];
        }   
};