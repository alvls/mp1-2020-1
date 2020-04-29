#include <iostream>
#include <vector>
#include "TicketService.h"
using namespace std;

int main()
{
    vector<Wagon> Ltrain;
    for (int i = 0; i < 8; i++) 
    {
        vector<Seat> Lseats;
        for (int i = 0; i < 100; i++) Lseats.push_back(Seat(1700));
        Ltrain.push_back(Wagon(Lseats));
    }
    Train Lastochka(1, "НиНо", "Москва", Ltrain);

    vector<Wagon> Btrain;
    for (int i = 0; i < 2; i++) 
    {
        vector<Seat> Bseats;
        for (int i = 0; i < 18; i++) Bseats.push_back(Seat(10700));
        Btrain.push_back(Wagon(Bseats));
    }
    for (int i = 0; i < 6; i++) 
    {
        vector<Seat> Bseats;
        for (int i = 0; i < 36; i++) Bseats.push_back(Seat(6700));
        Btrain.push_back(Wagon(Bseats));
    }
    for (int i = 0; i < 4; i++) 
    {
        vector<Seat> Bseats;
        for (int i = 0; i < 54; i++) Bseats.push_back(Seat(2700));
        Btrain.push_back(Wagon(Bseats));
    }
    Train BrandedTrain(2, "НиНо", "Москва", Btrain);

    vector<Wagon> Etrain;
    for (int i = 0; i < 4; i++) 
    {
        vector<Seat> Eseats;
        for (int i = 0; i < 36; i++) Eseats.push_back(Seat(6700));
        Etrain.push_back(Wagon(Eseats));
    }
    for (int i = 0; i < 8; i++) 
    {
        vector<Seat> Eseats;
        for (int i = 0; i < 54; i++) Eseats.push_back(Seat(2700));
        Etrain.push_back(Wagon(Eseats));
    }
    Train ExpressTrain(3, "НиНо", "Москва", Etrain);
}