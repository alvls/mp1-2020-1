#include <iostream>
#include "SongBook.h"
#include "Date.cpp"

using namespace std;

int main()
{
    SongBook s;
    s.readFromFile("1.txt");
    s.addSong(Song("1", "2", "3", "4", "5", Date(10,3,2001)));
    cout << s.size() << endl;
    s.addSong(Song("2", "4", "6", "8", "10", Date(20,6,2002)));
    cout << s.size() << endl;
    s.erase(1);
    cout << s.size() << endl;
    Song s1;
    vector<Song> s2;
    s1 = s.searchSong("4", "1");
    cout << s1.getAuthor() << endl;
    s2 = s.songsByAuthor("2");
    for (Song x: s2)
        cout << x.getComposer() << " ";
    cout << endl;
    s.saveToFile("1.txt");
}