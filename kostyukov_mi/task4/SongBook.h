#include <iostream>
#include "Date.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class Song
{
    private:
        std::string name;
        std::string author;
        std::string composer;
        std::string singer;
        std::string albumName;
        Date date;
    public:
        Song(std::string _name = "", std::string _author = "", std::string _composer = "", 
             std::string _singer = "", std::string _albumName = "", Date _date = Date())
        {
            name = _name;
            author = _author;
            composer = _composer;
            singer = _singer;
            albumName = _albumName;
            date = _date;
        }
        std::string getName() {return name;}
        std::string getSinger() {return singer;}
        std::string getComposer() {return composer;}
        std::string getAuthor() {return author;}
        std::string getAlbumName() {return albumName;}
        Date getDate() {return date;}
        void setName(std::string _name) {name = _name;}
        void setSinger(std::string _singer) {singer = _singer;}
        void setComposer(std::string _composer) {composer = _composer;}
        void setAuthor(std::string _author) {author = _author;}
        void setAlbumName(std::string _albumName) {albumName = _albumName;}
        void setDate(Date _date) {date = _date;}
};

class SongBook
{
    private:
        std::vector<Song> songs;
    public:
        SongBook(std::vector<Song> _songs = {})
        {
            songs = _songs;
        }
        void addSong(Song song)
        {
            songs.push_back(song);
        }
        Song operator[](size_t index)
        {
            return songs[index];
        }
        size_t size()
        {
            return songs.size();
        }
        void erase(size_t index)
        {
            songs.erase(songs.begin() + index);
        }
        Song searchSong(std::string singer, std::string name)
        {
            for (Song song: songs)
            {
                if ((song.getSinger() == singer) &&(song.getName() == name))
                    return song;
            }
            return Song();
        }
        std::vector<Song> songsByAuthor(std::string author)
        {
            std::vector<Song> _songs;
            for (Song song: songs)
            {
                if (song.getAuthor() == author)
                    _songs.push_back(song);
            }
            return _songs;
        }
        std::vector<Song> songsByComposer(std::string composer)
        {
            std::vector<Song> _songs;
            for (Song song: songs)
            {
                if (song.getComposer() == composer)
                    _songs.push_back(song);
            }
            return _songs;
        }
        std::vector<Song> songsBySinger(std::string singer)
        {
            std::vector<Song> _songs;
            for (Song song: songs)
            {
                if (song.getSinger() == singer)
                    _songs.push_back(song);
            }
            return _songs;
        }
        void saveToFile(std::string filename)
        {
            std::ofstream fout;
            fout.open(filename);
            for (Song song: songs)
            {
                fout << song.getName() << " ";
                fout << song.getSinger() << " ";
                fout << song.getAuthor() << " ";
                fout << song.getComposer() << " ";
                fout << song.getAlbumName() << " ";
                fout << song.getDate() << "\n";
            }
        }
        void readFromFile(std::string filename)
        {
            std::ifstream fin;
            fin.open(filename);
            if (fin.is_open())
            {
                std::string _line;
                std::string name, singer, author, composer, albumName;
                Date date;
                while (getline(fin, _line))
                {
                    if (_line != "")
                    {
                        std::istringstream line(_line);
                        line >> name;
                        line >> singer;
                        line >> author;
                        line >> composer;
                        line >> albumName;
                        line >> date;
                        Song song(name, author, composer, singer, albumName, date);
                        this->addSong(song);
                    }
                }
            }
        }
};
