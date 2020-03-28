#include"Songbook.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <Windows.h>
#include <conio.h>
#include <fstream>

Song::Song()
{
	song.resize(6);
}

Song::Song(std::vector<std::string> _song)
{
	song.assign(_song.begin(), _song.end());
}

Song::Song(const Song &_song)
{
	song.assign(_song.song.begin(), _song.song.end());
}

Song::~Song()
{}

void Song::ChangeData(std::vector<std::string> _data)
{
	song.assign(_data.begin(), _data.end());
}

void Song::WriteCon1()
{
	for (size_t i = 0; i < 6; i++)
	{
		std::cout << std::left << "*  " << std::setw(25) << data_song[i];
	}
	std::cout << std::endl;
}


void Song::WriteCon2()
{
	for (size_t i = 0; i < 6; i++)
	{
		std::cout << std::left << "*  " << std::setw(25) << song[i];
	}
	std::cout << std::endl;
}

std::string Song::GetData(int index)
{
	return song[index];
}

void Song::SaveInFile1(std::fstream &file)
{
	for (size_t i = 0; i < 6; i++)
	{
		file << std::left << "*  " << std::setw(21) << data_song[i];
	}
	file << std::endl;
}

void Song::SaveInFile2(std::fstream &file)
{

	for (size_t i = 0; i < 6; i++)
	{
		file << std::left << "*  " << std::setw(21) << song[i];
	}
	file << std::endl;
}

void Song::ReadFile(std::string new_song)
{
	int pos1, pos2;
	for (int i = 0; i < 6; i++)
	{
		if (i == 5)
		{
			new_song.erase(0, 3);
			song[5] = new_song;
			break;
		}
		pos1 = new_song.find("*", 0);
		pos2 = new_song.find("   ", 0);
		song[i] = new_song.substr(pos1 + 3, pos2 - pos1 - 3);
		new_song.erase(0, 1);
		pos1 = new_song.find("*", 0);
		new_song.erase(0, pos1);
	}

}

//--------------------------------------------------------------------------------------

Songbook::Songbook()
{
	songs.resize(0);
}

Songbook::Songbook(const Songbook &_song)
{
	songs.assign(_song.songs.begin(), _song.songs.end());
}

Songbook::~Songbook()
{}

void Songbook::SetSong(std::vector<std::string> last_song)
{
	Song new_song(last_song);
	songs.push_back(new_song);
}

void Songbook::SetSong(Song new_song)
{
	songs.push_back(new_song);
}

int Songbook::GetCountSong()//узнать кол-во песен в песеннике
{
	return songs.size();
}

void Songbook::ChangeDataSong(std::string _song, std::vector<std::string> _data)//изменить данные о песне
{
	size_t i;
	for (i = 0; i < songs.size(); i++)
	{
		if (_song == songs[i].GetData(0))
		{
			songs[i].ChangeData(_data);
			break;
		}
	}
	if (i == songs.size())
		throw "Песенник не содержит данную песню";
}

Song Songbook::GetSong(std::string _name_song, std::string _singer)//найти песню по назв. и исполнителю
{
	Song song;
	size_t i;
	for (i = 0; i < songs.size(); i++)
	{
		if (_name_song == songs[i].GetData(0))
		{
			if (_singer == songs[i].GetData(3))
			{
				break;
			}
		}
	}
	if (i == songs.size())
	{
		throw "Данная песня не содержится в песеннике";
	}
	return songs[i];
}

Songbook Songbook::GetSongsData(std::string _name, int human)//выдать все песни поэта, композитора, певца
{
	size_t i;
	Songbook _songbook;
	for (i = 0; i < songs.size(); i++)
	{
		if (_name == songs[i].GetData(human))
		{
			_songbook.SetSong(songs[i]);
		}
	}
	if (_songbook.songs.size() == 0)
		throw "Искомые песни не найдены";
	return _songbook;
}

void Songbook::DeleteSong(std::string _delete_song)//удалить песню
{
	size_t i;
	for (i = 0; i < songs.size(); i++)
	{
		if (_delete_song == songs[i].GetData(0))
		{
			songs.erase(songs.begin() + i);
			songs.shrink_to_fit();
		}
	}
	if (i == songs.size())
		throw "Песенник не содержит данную песню";
}

void Songbook::WriteCon()
{
	songs[0].WriteCon1();
	for (size_t i = 0; i < songs.size(); i++)
	{
		songs[i].WriteCon2();
	}
}

void Songbook::SaveInFile()
{
	std::fstream file("Songbook2.txt", std::fstream::out);
	if (!file)
	{
		std::cout << "Не удалось открыть файл " << std::endl;
		exit(1);
	}
	else
	{
		songs[0].SaveInFile1(file);
		for (size_t i = 0; i < songs.size(); i++)
		{
			songs[i].SaveInFile2(file);
		}
	}
	file.close();
}

void Songbook::ReadFile()
{
	std::ifstream file("Songbook1.txt");
	std::string new_song;
	Song song;
	if (!file)
	{
		std::cout << "Не удалось открыть файл " << std::endl;
		exit(1);
	}
	else
	{
		getline(file, new_song);
		while (getline(file, new_song))
		{
			song.ReadFile(new_song);
			songs.push_back(song);
		}

	}
	file.close();
}
