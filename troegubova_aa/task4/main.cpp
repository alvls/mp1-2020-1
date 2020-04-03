#include <clocale>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <locale>
#include <fstream>
#include "Songbook.h"
#include <Windows.h>

std::vector<std::string> SetSongData(int i, std::string _data, std::vector<std::string> _Data)
{
	std::string data;
	std::cout << _data;
	if (i != 0)
		std::getline(std::cin, data);
	else
	{
		std::getline(std::cin, data);
		std::getline(std::cin, data);
	}
	_Data.push_back(data);
	return _Data;
}

Songbook SetSong(std::vector<std::string> _data_song, Songbook _songbook)//добавить песню
{
	std::vector<std::string> Data;
	std::cout << "Введите данные о песне, которую хотите добавить:" << std::endl;

	for (int i = 0; i < 6; i++)
		Data = SetSongData(i, _data_song[i], Data);
	_songbook.SetSong(Data);
	return _songbook;
}

Songbook ChangeDataSong(std::vector<std::string> _data_song, Songbook _songbook)//изменить данные о песне
{
	std::string change_song, data;
	std::vector<std::string> Data;
	std::cout << "Введите название песни, данные которой хотите изменить: ";
	std::getline(std::cin, change_song);
	std::getline(std::cin, change_song);
	std::cout << "Введите данные о песне, которые хотите изменить:" << std::endl;

	for (int i = 0; i < 6; i++)
	{
		std::cout << _data_song[i];
		std::getline(std::cin, data);
		Data.push_back(data);
	}
	_songbook.ChangeDataOfSong(change_song, Data);
	return _songbook;
}

void GetSong(Songbook songbook)//найти песню по названию и исполнителю
{
	std::string _name_song, _singer;
	std::cout << "Название песни:";
	std::getline(std::cin, _name_song);
	std::getline(std::cin, _name_song);
	std::cout << "Имя исполнителя:";
	std::getline(std::cin, _singer);
	Song get_song = songbook.GetSong(_name_song, _singer);
	Songbook song;
	song.SetSong(get_song);
	song.WriteConSongbook();
}

void GetSongs(Songbook songbook, int human)// выдать все песни заданного поэта, композитора, исполнителя
{
	Songbook get_songbook;
	std::string _name;
	std::cout << "Название имя:";
	std::getline(std::cin, _name);
	std::getline(std::cin, _name);
	if (human == 1)
	{
		get_songbook = songbook.GetSongsOfPoet(_name);
	}
	if (human == 2)
	{
		get_songbook = songbook.GetSongsOfComposer(_name);
	}
	if (human == 3)
	{
		get_songbook = songbook.GetSongsOfSinger(_name);
	}
	get_songbook.WriteConSongbook();
}

void GetCountSong(Songbook songbook)//выдать количество песен
{
	std::cout << "Текущее кол-во песен в песеннике: " << songbook.GetCountOfSong() << std::endl;
}

Songbook DeleteSong(Songbook songbook)
{
	std::string delete_song;
	std::cout << "Введите название песни, которую хотите удалить: ";
	std::getline(std::cin, delete_song);
	std::getline(std::cin, delete_song);
	songbook.DeleteSong(delete_song);
	return songbook;
}
void SaveInFile(Songbook songbook)
{
	songbook.SaveInFile();
	std::cout << "Песенник сохранён в файл" << std::endl;
}

Songbook ReadFile(Songbook songbook)
{
	songbook.ReadFile();
	return songbook;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Songbook songbook1;
	int i, item;

	std::vector<std::string> data_song
		= { "Название песни:", "Автор слов:", "Композитор:", "Исполнитель:", "Название альбома, в который входит песня:", "Дата выпуска песни:" };
	Songbook(*Act_1[2])(std::vector<std::string> _data_song, Songbook _songbook) = { SetSong, ChangeDataSong };
	void(*Act_2[3])(Songbook songbook) = { GetSong, GetCountSong, SaveInFile };
	Songbook(*Act_3[2])(Songbook _songbook) = { DeleteSong, ReadFile };

	while (true)
	{
		system("cls");
		std::cout << "1) добавить песню\n2) изменить данные выбранной песни\n3) выдать все песни заданного поэта\n4) выдать все песни заданного композитора\n5) выдать все песни заданного исполнителя\n6) найти песню по названию и исполнителю\n7) узнать текущее число песен\n8) сохранить песенник в файл\n9) удалить песню\n10) считать песенник из файла\n";
		std::cin >> item;
		if ((item == 1) || (item == 2))
		{
			songbook1 = Act_1[item - 1](data_song, songbook1);
		}
		else
		{
			if ((item > 2) && (item < 6))
			{
				GetSongs(songbook1, item - 2);
			}
			else
			{
				if ((item > 5) && (item < 9))
					Act_2[item - 6](songbook1);
				else
				{
					if ((item == 9) || (item == 10))
						songbook1 = Act_3[item - 9](songbook1);
				}
			}
		}
		std::cout << "Продолжить работу программы?\n1)да\n2)нет\n";
		std::cin >> i;
		if (i != 1)break;
	}
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	system("pause");
}
