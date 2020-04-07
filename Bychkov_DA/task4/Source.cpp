#define _CRT_SECURE_NO_DEPRECATE
#include <stdlib.h>
#include<fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <locale.h>
#include <algorithm>
#include<string>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////

class Song
{
private:
	string name;
	string textwriter;
	string composer;
	string performer;
	string album;
	string date;
public:
	Song()
	{
		name = "empty";
		textwriter = "empty";
		composer = "empty";
		performer = "empty";
		album = "empty";
		date = "empty";
	}
	Song(const Song& other)
	{
		name = other.name;
		textwriter = other.textwriter;
		composer = other.composer;
		performer = other.performer;
		album = other.album;
		date = other.date;
	}
	void Outsongname()   //for check
	{
		cout << endl << name;
	}
	void Outsongtextwriter() {
		cout << endl << textwriter;
	}
	friend class SongList;
};


class SongList  ////////////////////////////////////////////////////////////////
{
private:
	int quantity = 0;
	vector<Song> songs;
	vector<Song> tmpsong;
public:
	SongList()
	{

	}
	/////////////////////////////////////////////////////////////////////////////////
	void AddSong()
	{
		quantity++;
		Song tmpsong;
		songs.push_back(tmpsong);
	}
	///////////////////////////////////////////////////////////////////////////////////
	void Changesongname(int n, const string& a)
	{
		songs[n - 1].name = a;
		Sort();
	}
	void Changesongtextwriter(int n, const string& a)
	{
		songs[n - 1].textwriter = a;
	}
	void Changesongcomposer(int n, const string& a)
	{
		songs[n - 1].composer = a;
	}
	void Changesongperformer(int n, const string& a)
	{
		songs[n - 1].performer = a;
	}
	void Changesongalbum(int n, char a[])
	{
		songs[n - 1].album = a;
	}
	void Changesongdate(int n, const string& a)
	{
		songs[n - 1].date = a;
	}
	///////////////////////////////////////////////////////////////////////////////////
	Song Getsong(string sname, string sperformer)
	{
		for (int k = 0; k < quantity; k++)
		{
			if ((sname == songs[k].name) && (sperformer == songs[k].performer))
			{
				return songs[k];
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	vector<Song> GetSongsByTextWritter(string stextwritter)
	{
		for (int k = 0; k < quantity; k++)
		{
			if (songs[k].textwriter == stextwritter)
			{
				tmpsong.push_back(songs[k]);
			}
		}
		return tmpsong;
	}
	vector<Song> GetSongsByComposer(string scomposer)
	{
		for (int k = 0; k < quantity; k++)
		{
			if (songs[k].composer == scomposer)
			{
				tmpsong.push_back(songs[k]);
			}
		}
		return tmpsong;
	}
	vector<Song> GetSongsByPerformer(string sperf)
	{
		for (int k = 0; k < quantity; k++)
		{
			if (songs[k].performer == sperf)
			{
				tmpsong.push_back(songs[k]);
			}
		}
		return tmpsong;
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	int GetQuantity()
	{
		return quantity;
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	void DeleteSong(string sname, string sperformer)
	{
		for (int k = 0; k < quantity; k++)
		{
			if ((sname == songs[k].name) && (sperformer == songs[k].performer))
			{
				swap(songs[k], songs.back());
				songs.pop_back();
				quantity--;
			}
		}
		Sort();
	}
	////////////////////////////////////////////////////////////////////////////////////////////
	void Sort()
	{
		Song* tmpsongs = new Song[quantity];
		for (int i = 0; i < quantity; i++)
		{
			tmpsongs[i].name = songs[i].name;
		}
		for (int k = 0; k < quantity; k++)
		{
			tmpsongs[k] = songs[k];
		}

		sort1(tmpsongs, quantity);

		for (int k = 0; k < quantity; k++)
		{
			songs[k] = tmpsongs[k];
		}

		delete[] tmpsongs;
	}
	void sort1(Song* S, int N)
	{
		for (int i = 0; i < N - 1; i++)
			for (int j = i + 1; j < N; j++) {
				if (strcmp(S[i].name.c_str(), S[j].name.c_str()) > 0) swap(S[i], S[j]);
			}
	}
	void Getfromfile(string a)
	{
		char* buff = new char[300];
		string str;
		ifstream fin(a);
		while (fin.eof() == false)
		{
			AddSong();
			getline(fin, str);
			
			strcpy(buff, str.c_str());
			int k = 0;
			while (buff[k] != '/')
			{
				k++;
			}
			string tmpstr = string(buff, k);
			songs[quantity - 1].name = tmpstr;

			k++;
			tmpstr = '\0';
			int prev = k;
			while (buff[k] != '/')
			{
				k++;
			}
			tmpstr = string(buff, prev, k - prev);
			songs[quantity - 1].textwriter = tmpstr;

			k++;
			tmpstr = '\0';
			prev = k;
			while (buff[k] != '/')
			{
				k++;
			}
			tmpstr = string(buff, prev, k - prev);
			songs[quantity - 1].composer = tmpstr;

			k++;
			tmpstr = '\0';
			prev = k;
			while (buff[k] != '/')
			{
				k++;
			}
			tmpstr = string(buff, prev, k - prev);
			songs[quantity - 1].performer = tmpstr;

			k++;
			tmpstr = '\0';
			prev = k;
			while (buff[k] != '/')
			{
				k++;
			}
			tmpstr = string(buff, prev, k - prev);
			songs[quantity - 1].album = tmpstr;

			k++;
			tmpstr = '\0';
			prev = k;
			while (buff[k] != '/')
			{
				k++;
			}
			tmpstr = string(buff, prev, k - prev);
			songs[quantity - 1].date = tmpstr;
		}
		delete[] buff;
	}
	void Outinfile(string a)
	{
		ofstream fout;
		fout.open(a);
		if (!fout.is_open())
		{
			cout << "opening error" << endl;
		}
		else
		{
			Sort();
			for (int k = 0; k < quantity; k++)
			{
				fout << songs[k].name << '/' << songs[k].textwriter << '/' << songs[k].composer << '/' << songs[k].performer << '/' << songs[k].album << '/' << songs[k].date << endl;
			}
		}
		fout.close();
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	SongList list;
	/*list.AddSong();
	list.Changesongname(1, "ананасина");
	list.Changesongperformer(1, "фыфка");
	list.Changesongtextwriter(1, "јсѕушка");
	list.AddSong();
	list.Changesongname(2, "л€пота");
	list.Changesongperformer(2, "evgenMc");
	list.Changesongtextwriter(2, "јсѕушка");
	Song a(list.Getsong("л€пота", "evgenMc"));
	a.Outsongtextwriter();

	vector <Song> songsbyperf = list.GetSongsByTextWritter("јсѕушка");
	cout << endl << endl << endl;
	songsbyperf[0].Outsongname();
	songsbyperf[1].Outsongname();
	cout << endl;
	list.DeleteSong("ананасина", "фыфка");
	list.AddSong();
	list.Changesongname(2, "абрикос");
	list.AddSong();
	list.Changesongname(3, "розетка");
	list.AddSong();
	list.Changesongname(4, "перфоратор");


	cout << endl << endl << list.GetQuantity();
	*/
	list.Getfromfile("myList.txt");
	list.Outinfile("ascasc.txt");
	system("pause");
}
