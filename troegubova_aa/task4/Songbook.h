﻿#pragma once
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
public:
	Songbook();
	Songbook(const Songbook &_song);
	~Songbook();

	void SetSong(std::vector<std::string> last_song);
	void SetSong(Song new_song);
	int GetCountSong();
	void ChangeDataOfSong(std::string _song, std::vector<std::string> _data);
	Songbook GetSong(std::string _name_song, std::string _singer);
	Songbook GetDataOfSongs(std::string _name, int human);
	void DeleteSong(std::string _delete_song);
	void Songbook::WriteConDataSong();
	void WriteConSongbook();
	void SaveInFileData(std::fstream &file);
	void SaveInFile();
	void ReadFile();
};
