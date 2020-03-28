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
	std::vector<std::string> song;

public:
	Song();
	Song(std::vector<std::string> _song);
	Song(const Song &_song);
	~Song();

	void ChangeData(std::vector<std::string> _data);
	void WriteCon1();
	void WriteCon2();
	std::string GetData(int index);
	void ReadFile(std::string new_song);
	void Song::SaveInFile1(std::fstream &file);
	void SaveInFile2(std::fstream &file);
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
	void Songbook::SetSong(Song new_song);
	int GetCountSong();
	void ChangeDataSong(std::string _song, std::vector<std::string> _data);
	Song GetSong(std::string _name_song, std::string _singer);
	Songbook GetSongsData(std::string _name, int human);
	void DeleteSong(std::string _delete_song);
	void WriteCon();
	void SaveInFile();
	void ReadFile();
};
