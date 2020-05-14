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
        string name;
        Date date;
        int trainIndex;
        vector<pair<int, int>> seats;

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
                if (!trains[order.trainIndex].getWagons()[seat.first].getSeats()[seat.second].getStatus()) 
                    return false;
            }
            return true;
        }
        bool bookSeats(Order order)
        {
            if (!checkSeats(order)) return false;
            for (auto seat: order.seats)
            {
                trains[order.trainIndex].getWagons()[seat.first].bookSeat(seat.second);
            }
        }
        bool restoreSeats(Order order)
        {
            if (!checkSeats(order)) return false;
            for (auto seat: order.seats)
            {
                trains[order.trainIndex].getWagons()[seat.first].restoreSeat(seat.second);
            }
            return true;
        }
        int orderTotal(Order order)
        {
            int total = 0;
            for (auto seat: order.seats)
            {
                total += trains[order.trainIndex].getWagons()[seat.first].getSeats()[seat.second].getPrice();
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
                tickets.push_back(Ticket(order.name, order.date, trainId, seat.first+1, seat.second+1, stationFrom, stationTo));
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