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
	name_song = " ";
	poet = " ";
	composer = " ";
	singer = " ";
	name_album = " ";
	release_date = " ";
}

Song::Song(std::vector<std::string> _song)
{
	name_song = _song[0];
	poet = _song[1];
	composer = _song[2];
	singer = _song[3];
	name_album = _song[4];
	release_date = _song[5];
}

Song::Song(std::string _name_song, std::string _poet, std::string _composer, std::string _singer, std::string _name_album, std::string _release_date) :
	name_song(_name_song), poet(_poet), composer(_composer), singer(_singer), name_album(_name_album), release_date(_release_date)
{}

Song::Song(const Song &_song)
	: name_song(_song.name_song), poet(_song.poet), composer(_song.composer), singer(_song.singer), name_album(_song.name_album), release_date(_song.release_date)
{}

Song::~Song()
{}

void Song::ChangeDataOfSong(std::vector<std::string> _data)
{
	name_song = _data[0];
	poet = _data[1];
	composer = _data[2];
	singer = _data[3];
	name_album = _data[4];
	release_date = _data[5];
}

std::string Song::GetData(int index)
{
	std::vector<std::string> data = { name_song, poet, composer, singer, name_album, release_date };
	return data[index];
}

void Song::SetData(int index, std::string data)
{
	std::string * SetData[6];
	SetData[0] = &name_song;
	SetData[1] = &poet;
	SetData[2] = &composer;
	SetData[3] = &singer;
	SetData[4] = &name_album;
	SetData[5] = &release_date;

	*SetData[index] = data;

}

void Song::WriteConSong()
{
	for (size_t i = 0; i < 6; i++)
	{
		std::cout << std::left << "*  " << std::setw(25) << GetData(i);
	}
	std::cout << std::endl;
}

void Song::SaveInFileSong(std::fstream &file)
{

	for (size_t i = 0; i < 6; i++)
	{
		file << std::left << "*  " << std::setw(21) << GetData(i);
	}
	file << std::endl;
}

void Song::ReadFile(std::string new_song)
{
	int pos1, pos2;
	std::string new_data;
	for (int i = 0; i < 6; i++)
	{
		if (i == 5)
		{
			new_song.erase(0, 3);
			SetData(5, new_song);
			break;
		}
		pos1 = new_song.find("*", 0);
		pos2 = new_song.find("   ", 0);
		new_data = new_song.substr(pos1 + 3, pos2 - pos1 - 3);
		SetData(i, new_data);
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

int Songbook::GetCountOfSong()//узнать кол-во песен в песеннике
{
	return songs.size();
}

void Songbook::ChangeDataOfSong(std::string _song, std::vector<std::string> _data)//изменить данные о песне
{
	size_t i;
	for (i = 0; i < songs.size(); i++)
	{
		if (_song == songs[i].GetData(0))
		{
			songs[i].ChangeDataOfSong(_data);
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

Songbook Songbook::GetDataOfSongs(std::string _name, std::string human)//выдать все песни поэта, композитора, певца
{
	size_t i;
	Songbook _songbook;
	int _human = 0;
	if (human == "poet")
	{
		_human = 1;
	}
	if (human == "composer")
	{
		_human = 2;
	}
	if (human == "singer")
	{
		_human = 3;
	}
	if (_human == 0)
		throw "Переданы неверные параметры";
	for (i = 0; i < songs.size(); i++)
	{
		if (_name == songs[i].GetData(_human))
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
			break;
		}
	}
	if (i == songs.size())
		throw "Песенник не содержит данную песню";
}

void Songbook::WriteConDataSong()
{
	for (size_t i = 0; i < 6; i++)
	{
		std::cout << std::left << "*  " << std::setw(25) << data_song[i];
	}
	std::cout << std::endl;
}

void Songbook::WriteConSongbook()
{
	WriteConDataSong();
	for (size_t i = 0; i < songs.size(); i++)
	{
		songs[i].WriteConSong();
	}
}

void Songbook::SaveInFileData(std::fstream &file)
{
	for (size_t i = 0; i < 6; i++)
	{
		file << std::left << "*  " << std::setw(21) << data_song[i];
	}
	file << std::endl;
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
		SaveInFileData(file);
		for (size_t i = 0; i < songs.size(); i++)
		{
			songs[i].SaveInFileSong(file);
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