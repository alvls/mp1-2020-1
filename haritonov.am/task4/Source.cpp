#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;

struct film
{
	string name;
	string producer;
	string screenwriter;
	string composer;
	int dd;
	int mm;
	int yy;
	int summ;
};

class film_library
{
	vector <film> movie;
public:
	void show_pos(int num)
	{
		cout << movie[num].name << endl;
	}


	friend bool compareByName(const film &a, const film &b)
	{
		return (a.name < b.name);
	}
	void sort_by_name()
	{
		sort(movie.begin(), movie.end(), compareByName);
	}

	friend bool compareByDate(const film &a, const film &b)
	{
		return (a.yy < b.yy);
	}
	void sort_by_date()
	{
		sort(movie.begin(), movie.end(), compareByDate);
	}

	friend bool compareByProducer(const film &a, const film &b)
	{
		return (a.producer < b.producer);
	}
	void sort_by_producer()
	{
		sort(movie.begin(), movie.end(), compareByProducer);
	}

	friend bool compareBySumm(const film &a, const film &b)
	{
		return (a.summ > b.summ);
	}
	void sort_by_summ()
	{
		sort(movie.begin(), movie.end(), compareBySumm);
	}


	void show_films(int type)
	{
		if (type == 1) sort_by_name();
		if (type == 2) sort_by_date();
		if (type == 3) sort_by_producer();
		for (int i = 0; i < movie.size(); i++)
		{
			cout << setw(14) << movie[i].name;
			cout << setw(14) << movie[i].producer;
			cout << setw(14) << movie[i].screenwriter;
			cout << setw(14) << movie[i].composer;
			cout << setw(4) << movie[i].dd;
			cout << setw(4) << movie[i].mm;
			cout << setw(6) << movie[i].yy;
			cout << setw(12) << movie[i].summ;
			cout << endl;
		}
		cout << endl;
	}

	void add_film(string _n, string _p, string _s, string _c, int _dd, int _mm, int _yy, int _summ)
	{
		film new_movie;
		new_movie.name = _n;
		new_movie.producer = _p;
		new_movie.screenwriter = _s;
		new_movie.composer = _c;
		new_movie.dd = _dd;
		new_movie.mm = _mm;
		new_movie.yy = _yy;
		new_movie.summ = _summ;
		movie.push_back(new_movie);
	}

	void change_film(int num, string _n = "", string _p = "", string _s = "", string _c = "", int _dd = 0, int _mm = 0, int _yy = 0, int _summ = 0)
	{
		if (_n != "") movie[num].name = _n;
		if (_p != "") movie[num].producer = _p;
		if (_s != "") movie[num].screenwriter = _s;
		if (_c != "") movie[num].composer = _c;
		if (_dd != 0) movie[num].dd = _dd;
		if (_mm != 0) movie[num].mm = _mm;
		if (_yy != 0) movie[num].yy = _yy;
		if (_summ != 0) movie[num].summ = _summ;
	}

	film search_by_nameAndDate(string _name, int _yy)
	{
		int i = 0;
		while ((movie[i].name != _name) && (movie[i].yy != _yy)) i++;
		return(movie[i]);
	}

	vector <film> search_by_producer(string _producer)
	{
		sort_by_producer();
		vector <film> buffer;
		int i = 0;
		if (movie[i].producer != _producer)  while (movie[i].producer != _producer) i++;
		while ((i < movie.size()) && (movie[i].producer == _producer))
		{
			buffer.push_back(movie[i]);
			i++;
		}
		return buffer;
	}

	vector <film> search_by_year(int _yy)
	{
		sort_by_date();
		vector <film> buffer;
		int i = 0;

		if (movie[i].yy != _yy)	while (movie[i].yy != _yy) i++;

		while ((i < movie.size()) && (movie[i].yy == _yy))
		{
			buffer.push_back(movie[i]);
			i++;
		}
		return buffer;
	}

	vector <film> search_by_summ(int _num)
	{
		sort_by_summ();
		vector <film> buffer;
		for (int i = 0; i < _num; i++)
			buffer.push_back(movie[i]);
		return buffer;
	}

	int count_of_films()
	{
		return(movie.size());
	}

	void erase_film(int _num)
	{
		movie.erase(movie.begin() + _num);
	}

	void file_write()
	{
		ofstream out;
		out.open("F:\\List.txt");
		//out.open("C:\Users\Aleksey\Desktop\List.txt");
		if (out.is_open())
		{
			for (int i = 0; i < movie.size(); i++)
			{
				out << movie[i].name << endl;
				out << movie[i].producer << endl;
				out << movie[i].screenwriter << endl;
				out << movie[i].composer << endl;
				out << movie[i].dd << endl;
				out << movie[i].mm << endl;
				out << movie[i].yy << endl;
				out << movie[i].summ << endl;
				if (i < movie.size() - 1)
				out << endl;
			}
		}
	}

	void file_read()
	{
		movie.clear();
		string line;
		film new_movie;
		ifstream in("F:\\List.txt");
		if (in.is_open())
		{
			while(!in.eof())
			{
				getline(in, line);
				new_movie.name = line;
				getline(in, line);
				new_movie.producer = line;
				getline(in, line);
				new_movie.screenwriter = line;
				getline(in, line);
				new_movie.composer = line;
				getline(in, line);
				new_movie.dd = atof(line.c_str());
				getline(in, line);
				new_movie.mm = atof(line.c_str());
				getline(in, line);
				new_movie.yy = atof(line.c_str());
				getline(in, line);
				new_movie.summ = atof(line.c_str());
				getline(in, line);
				movie.push_back(new_movie);
			}
		}
		in.close();
	}
};


int main()
{
	film_library a;
	a.add_film("name", "producer", "screenwriter", "composer", 0, 0, 92, 1000);
	a.add_film("Name", "producer", "screenwriter", "composer", 0, 0, 101, 1000);
	a.add_film("trr", "producer", "screenwriter", "composer", 0, 0, 101, 1000);
	a.add_film("top-1", "producer", "screenwriter", "composer", 0, 0, 101, 100023);
	a.add_film("top-2", "producer", "screenwriter", "composer", 0, 0, 101, 100002);
	a.add_film("abs", "true", "screenwriter", "composer", 0, 0, 4, 1000);
	a.show_films(1);
	a.change_film(2, "zzz");
	a.show_films(2);
	a.search_by_nameAndDate("abs", 4);
	a.search_by_producer("producer");
	a.search_by_year(101);
	a.search_by_summ(3);
	a.file_write();
	a.erase_film(3);
	a.show_films(1);
	a.file_read();
	a.show_films(1);
	system("pause");
}
