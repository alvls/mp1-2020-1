#include <iostream>
#include "SongBook.h"

using namespace std;

int main()
{
    SongBook s;
    s.readFromFile("1.txt");
    // s.addSong(Song("1", "2", "3", "4", "5"));
    // s.addSong(Song("1", "2", "3", "4", "5"));
    s.saveToFile("1.txt");
}