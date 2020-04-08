#include <iostream>
#include <clocale>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <Windows.h>
#include <math.h>
using namespace std;
class Information
{
private:
	string Name;
	string Producer;
	string Screenwriter;
	string Composer;
	int Fees;
	int Year;
	int Month;
	int Day;
public:
	string getName()
	{
		return Name;
	}
	string getProducer()
	{
		return Producer;
	}
	string getScreenwriter()
	{
		return Screenwriter;
	}
	string getComposer()
	{
		return Composer;
	}
	int getFees()
	{
		return Fees;
	}
	int getYear()
	{
		return Year;
	}
	int getMonth()
	{
		return Month;
	}
	int getDay()
	{
		return Day;
	}
	void setName(string _name)
	{
		Name = _name;
	}
	void setProducer(string _producer)
	{
		Producer = _producer;
	}
	void setScreenwriter(string _screenwriter)
	{
		Screenwriter = _screenwriter;
	}
	void setComposer(string _composer)
	{
		Composer = _composer;
	}
	void setFees(int _fees)
	{
		Fees = _fees;
	}
	void setYear(int _year)
	{
		Year = _year;
	}
	void setMonth(int _month)
	{
		Month = _month;
	}
	void setDay(int _day)
	{
		Day = _day;
	}
	Information(string _Name = "��� ��������", int _Year = 1, int _Month = 1, int _Day= 1, int _Fees = 0, string _Producer = "�� ������", string _Screenwriter = "�� ������", string _Composer = "�� ������")
	{
		Name = _Name;
		Producer = _Producer;
		Screenwriter = _Screenwriter;
		Composer = _Composer;
		Year = _Year;
		Month = _Month;
		Day = _Day;
		Fees = _Fees;
	}
	Information(Information const& Info)
	{
		Name = Info.Name;
		Producer = Info.Producer;
		Screenwriter = Info.Screenwriter;
		Composer = Info.Composer;
		Fees = Info.Fees;
		Year = Info.Year;
		Month = Info.Month;
		Day = Info.Day;
	}
	Information& operator=(const Information& Info)
	{
		if (this == &Info)
			return *this;
		Name = Info.Name;
		Producer = Info.Producer;
		Screenwriter = Info.Screenwriter;
		Composer = Info.Composer;
		Fees = Info.Fees;
		Year = Info.Year;
		Month = Info.Month;
		Day = Info.Day;
		return *this;
	}
	bool operator > (const Information& Info)
	{
		unsigned int i = 0;
		bool flag = false;
		while ((i < size(Name)) && (i < size(Info.Name)))
		{
			if (Name[i] < Info.Name[i])
			{
				flag = true;
				break;
			}
			i++;
		}
		if (!flag)
			if (Name == Info.Name)
				if (Year > Info.Year)
					flag = true;
		return flag;
	}
};
class Filmoteka
{
	vector<Information>Films;
public:
	Filmoteka() {}
	Filmoteka(Filmoteka const& _Filmoteka)
	{
		Films = _Filmoteka.Films;
	}
	Filmoteka& operator = (const Filmoteka& _Filmoteka)
	{
		if (this == &_Filmoteka)
			return *this;
		Films = _Filmoteka.Films;
		return *this;
	}
	vector<Information>& GetFilms()
	{
		return Films;
	}
	void Sort()
	{
		if (Films.size() > 1)
		{
			Information tmp;
			for (unsigned int i = 1; i < Films.size(); i++)
				for (int j = i - 1; j >= 0; j--)
					if (Films[j + 1] > Films[j])
					{
						tmp = Films[j + 1];
						Films[j + 1] = Films[j];
						Films[j] = tmp;
					}
		}
	}
	void SortFees()
	{
		if (Films.size() > 1)
		{
			Information tmp;
			for (unsigned int i = 1; i < Films.size(); i++)
				for (int j = i - 1; j >= 0; j--)
					if (Films[j + 1].getFees() > Films[j].getFees())
					{
						tmp = Films[j + 1];
						Films[j + 1] = Films[j];
						Films[j] = tmp;
					}
		}
	}
	string GetName(int _index)
	{
		return Films[_index].getName();
	}
	string GetProducer(int _index)
	{
		return Films[_index].getProducer();
	}
	string GetScreenwriter(int _index)
	{
		return Films[_index].getScreenwriter();
	}
	string GetComposer(int _index)
	{
		return Films[_index].getComposer();
	}
	int GetYear(int _index)
	{
		return Films[_index].getYear();
	}
	int GetMonth(int _index)
	{
		return Films[_index].getMonth();
	}
	int GetDay(int _index)
	{
		return Films[_index].getDay();
	}
	int GetFees(int _index)
	{
		return Films[_index].getFees();
	}
	void AddFilm(string _Name = "��� ��������", int _Year = 1, int _Month = 1, int _Day = 1, int _Fees = 0, string _Producer = "�� ������", string _Screenwriter = "�� ������", string _Composer = "�� ������")
	{
		Information tmp;
		tmp.setName(_Name);
		tmp.setYear(_Year);
		tmp.setMonth(_Month);
		tmp.setDay(_Day);
		tmp.setProducer(_Producer);
		tmp.setScreenwriter(_Screenwriter);
		tmp.setComposer(_Composer);
		tmp.setFees(_Fees);
		Films.push_back(tmp);
		Sort();
	}
	int GetNumberFilms()
	{
		return (int)Films.size();
	}
	int SearchFilmName(int tmp, string _Name)
	{
		tmp = -1;
		for (int i = 0; i < Films.size(); i++)
		{
			if (Films[i].getName() == _Name)
			{
				tmp = i; ;
				break;
			}
		}
		return tmp;
	}
	int SearchFilmYear(int tmp, int _Year)
	{
		tmp = -1;
		for (int i = 0; i < Films.size(); i++)
		{
			if (Films[i].getYear() == _Year)
			{
				tmp = i; ;
				break;
			}
		}
		return tmp;
	}
	void DeleteFilm(int _index)
	{
		Films.erase(Films.begin() + _index);
	}
	bool ControlDate(int _Year, int _Month, int _Day)
	{
		bool flag = true;
		if (_Year < 0)
			flag = false;
		else
			if ((_Month > 12) || (_Month < 1))
				flag = false;
			else
				if (_Day < 0 || _Day>31)
					flag = false;
				else
				{
					if (_Month == 4 || _Month == 6 || _Month == 9 || _Month == 11)
					{
						if (_Day > 30)
							flag = false;
					}
					else
						if (_Month == 2)
						{
							if ((_Year % 4 == 0) || (_Year % 400 == 0))
							{
								if (_Day > 29)
									flag = false;
							}
							else
								if (_Day > 28)
									flag = false;
						}
				}
		return flag;
	}
	void ChangeFilm(int _index, string _Name = "��� ��������", int _Year = 1, int _Month = 1, int _Day = 1, int _Fees = 0, string _Producer = "�� ������", string _Screenwriter = "�� ������", string _Composer = "�� ������")
	{
		Films[_index].setName(_Name);
		Films[_index].setYear(_Year);
		Films[_index].setMonth(_Month);
		Films[_index].setDay(_Day);
		Films[_index].setProducer(_Producer);
		Films[_index].setScreenwriter(_Screenwriter);
		Films[_index].setComposer(_Composer);
		Films[_index].setFees(_Fees);
	}
	void SaveFilmoteka()
	{
		ofstream file;
		file.open("Filmoteka.txt");
		if (!file.is_open())
			cout << "������ ��������";
		else
			for (int i = 0; i < Films.size(); i++)
			{
				file << "�������� ������: " << Films[i].getName() << endl;
				file << "���� ������: " << Films[i].getYear() << "." << Films[i].getMonth() << "." << Films[i].getDay() << endl;
				file << "�����: " << Films[i].getFees() << endl;
				file << "��������: " << Films[i].getProducer() << endl;
				file << "���������: " << Films[i].getScreenwriter() << endl;
				file << "����������: " << Films[i].getComposer() << endl << endl;
			}
		file.close();
		ofstream File;
		File.open("FilmotekaRec.txt");
		if (!File.is_open())
			cout << "������ ��������";
		else
			for (int i = 0; i < Films.size(); i++)
			{
				File << Films[i].getName() << endl;
				File << Films[i].getYear() << endl;
				File << Films[i].getMonth() << endl;
				File << Films[i].getDay() << endl;
				File << Films[i].getFees() << endl;
				File << Films[i].getProducer() << endl;
				File << Films[i].getScreenwriter() << endl;
				File << Films[i].getComposer() << endl;
			}
		File.close();
	}
	Filmoteka ReadFilmoteka(Filmoteka _Library)
	{
		Information tmp;
		ifstream fout;
		fout.open("FilmotekaRec.txt");
		if (!fout.is_open())
			cout << "������ ��������";
		else
			while (!fout.eof())
			{
				string str;
				int Str;
				getline(fout, str);
				tmp.setName(str);
				fout >> Str;
				tmp.setYear(Str);
				fout >> Str;
				tmp.setMonth(Str);
				fout >> Str;
				tmp.setDay(Str);
				fout >> Str;
				tmp.setFees(Str);
				fout.ignore();
				getline(fout, str);
				tmp.setProducer(str);
				getline(fout, str);
				tmp.setScreenwriter(str);
				getline(fout, str);
				tmp.setComposer(str);
				fout.ignore();
				_Library.Films.push_back(tmp);
			}
		fout.close();
		return _Library;
	}
};
void Print(int _index, Filmoteka _Library)
{
	cout << "�������� ������: " << _Library.GetName(_index) << endl;
	cout << "���� ������: " << _Library.GetYear(_index) << "." << _Library.GetMonth(_index) << "." << _Library.GetDay(_index) << endl;
	cout << "�����: " << _Library.GetFees(_index) << endl;
	cout << "��������: " << _Library.GetProducer(_index) << endl;
	cout << "���������: " << _Library.GetScreenwriter(_index) << endl;
	cout << "����������: " << _Library.GetComposer(_index) << endl << endl;
}
vector <int> PrintFilmProducer(string _Producer, Filmoteka _Library)
{
	vector <int> film_numbers;
	bool flag = false;
	for (int i = 0; i < _Library.GetNumberFilms(); i++)
		if (_Library.GetProducer(i) == _Producer)
		{
			film_numbers.push_back(i);
			flag = true;
		}
	if (!flag)
	{
		cout << "������� ������� ��������� �� �������." << endl;
		film_numbers.push_back(-1);
	}
	return film_numbers;
}
vector <int> PrintFilmYear(int _Year, Filmoteka _Library)
{
	vector <int> film_numbers;
	bool flag = false;
	for (int i = 0; i < _Library.GetNumberFilms(); i++)
		if (_Library.GetYear(i) == _Year)
		{
			film_numbers.push_back(i);
			flag = true;
		}
	if (!flag)
		cout << "������� � ������ ���� �� �������." << endl;
	return film_numbers;
}
vector <int>  PrintFilmSearch(string _Name, int _Year, Filmoteka _Library)
{
	vector <int> film_numbers;
	bool flag = false;
	for (int i = 0; i < _Library.GetNumberFilms(); i++)
		if ((_Library.GetName(i) == _Name) && (_Library.GetYear(i) == _Year))
		{
			film_numbers.push_back(i);
			flag = true;
		}
	if (!flag)
		cout << "����� � ������� ����������� �� ������." << endl;
	return film_numbers;
}
vector <int>  PrintFees(int _Number, Filmoteka _Library)
{
	vector <int> film_numbers;
	if (_Number > _Library.GetNumberFilms())
	{
		cout << "���������� ������������� ������� ��������� ����� ����������. ����� �������� - " << _Library.GetNumberFilms() << endl;
		_Number = _Library.GetNumberFilms();
	}
	_Library.SortFees();
	for (int i = 0; i < _Number; i++)
		film_numbers.push_back(i);
	return film_numbers;
}
vector <int> PrintFeesYear(int _Number, int _Year, Filmoteka _Library)
{
	vector <int> film_numbers;
	int num = 0;
	for (int i = 0; i < _Library.GetNumberFilms(); i++)
		if (_Library.GetYear(i) == _Year)
			num++;
	if (num == 0)
	{
		cout << "�� ������� �� ������ ������ " << _Year << " ����" << endl;
		film_numbers.push_back(-1);
	}
	if (_Number > num)
		cout << "���������� ������������� ������� ��������� ���������� ������� ������� ����. ����� �������� - " << num << endl;
	else
		num = _Number;
	_Library.SortFees();
	int i = 0, k = 0;
	while (i < num)
	{
		if (_Library.GetYear(k) == _Year)
		{
			film_numbers.push_back(i);
			i++;
		}
		k++;
	}
	return film_numbers;
}
void Menu()
{
	cout << "1. �������� ����� �����" << endl;
	cout << "2. �������� ������ ������" << endl;
	cout << "3. ����� �����" << endl;
	cout << "4. ������� ��� ������ ��������� ���������" << endl;;
	cout << "5. ������� ��� ������, �������� � ������ � ��������� ����" << endl;
	cout << "6. ������� �������� ����� ������� � ����������� ������� " << endl;
	cout << "7. ������� �������� ����� ������� � ����������� ������� � ��������� ���� " << endl;
	cout << "8. ������ ������� ����� �������" << endl;
	cout << "9. ������� ����� " << endl;
	cout << "10. ��������� ���������� � ���� " << endl;
	cout << "11. ������� ���������� �� �����." << endl;
	cout << "12. �����" << endl;
	cout << "��� �����: ";
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	vector <int> film_number;
	string Name, Produ�er, Screenwriter, Composer;
	int count = 0, number = 0, i = 0, j, x;
	int Year, Month, Day, Fees;
	Filmoteka Library;
	Filmoteka lib;
	while (count != 12)
	{
		system("cls");
		Menu();
		cin >> count;
		system("cls");
		switch (count)
		{
		case 1:
			cout << "������� �������� ������: ";
			cin >> Name;
			do
			{
				cout << endl << "������� ���� ������(��� ����� �����): ";
				cin >> Year >> Month >> Day;
			} while (!Library.ControlDate(Year, Month, Day));
			cout << endl << "������� �����(� ������): ";
			cin >> Fees;
			cout << endl << "������� ������� ���������: ";
			cin >>Produ�er;
			cout << endl << "������� ������� ����������: ";
			cin >> Screenwriter;
			cout << endl << "������� ������� �����������: ";
			cin >> Composer;
			Library.AddFilm(Name, Year, Month, Day, Fees, Produ�er, Screenwriter, Composer);
			cout << endl << "����� ��������!" << endl;
			system("pause");
			break;
		case 2:
			cout << "������� �������� ������, ������� ������ ��������: ";
			cin.ignore();
			getline(cin, Name);
			if (Library.SearchFilmName(i, Name) < 0)
			{
				cout << endl << "����� � ������ ��������� �� ������.";
				system("pause");
				break;
			}
			else
			{
				cout << "������� ��� ������ ������ ";
				cin >> x;
				if (Library.SearchFilmYear(i,Year) < 0)
				{
					cout << endl << "����� � ������ ��������� � ����� �� ������.";
					system("pause");
					break;
				}

			}
			j = Library.SearchFilmName(i, Name);
			cout << "������� �������� ������ ������: ";
			getline(cin, Name);
			do
			{
				cout << endl << "������� ���� ������(��� ����� �����): ";
				cin >> Year >> Month >> Day;
			} while (!Library.ControlDate(Year, Month, Day));
			cout << endl << "������� �����(� ������): ";
			cin >> Fees;
			cout << endl << "������� ������� ���������: ";
			cin.ignore();
			getline(cin, Produ�er);
			cout << endl << "������� ������� ����������: ";
			getline(cin, Screenwriter);
			cout << endl << "������� ������� �����������: ";
			getline(cin, Composer);
			Library.ChangeFilm(j, Name, Year, Month, Day, Fees, Produ�er, Screenwriter, Composer);
			cout << "����� �������!" << endl;
			system("pause");
			break;
		case 3:
			cout << "������� �������� ������: ";
			cin.ignore();
			getline(cin, Name);
			cout << endl << "������� ���: ";
			cin >> Year;
			cout << endl;
			PrintFilmSearch(Name, Year, Library);
			system("pause");
			break;
		case 4:
			cout << "������� ������� ���������: ";
			cin.ignore();
			getline(cin, Produ�er);
			film_number = PrintFilmProducer(Produ�er, Library);
			if (film_number[0] != -1)
				for (i = 0; i < film_number.size(); i++)
					Print(film_number[i], Library);
			system("pause");
			break;
		case 5:
			cout << "������� ���: ";
			cin >> Year;
			film_number = PrintFilmYear(Year, Library);
			if (film_number[0] != -1)
				for (i = 0; i < film_number.size(); i++)
					Print(film_number[i], Library);
			system("pause");
			break;
		case 6:
			cout << "������� ���������� �������: ";
			cin >> number;
			cout << endl;
			film_number = PrintFees(number, Library);
			if (film_number[0] != -1)
				for (i = 0; i < film_number.size(); i++)
					Print(film_number[i], Library);
			system("pause");
			break;
		case 7:
			cout << "������� ���������� �������: ";
			cin >> number;
			cout << endl;
			cout << "������� ���: ";
			cin >> Year;
			cout << endl;
			film_number = PrintFeesYear(number, Year, Library);
			if (film_number[0] != -1)
				for (i = 0; i < film_number.size(); i++)
					Print(film_number[i], Library);
			system("pause");
			break;
		case 8:
			cout << "���������� ������� = " << Library.GetNumberFilms() << endl;
			system("pause");
			break;
		case 9:
			cout << "������� �������� ������, ������� ������ �������: ";
			cin.ignore();
			getline(cin, Name);
			if (Library.SearchFilmName(i, Name) < 0)
			{
				cout << endl << "����� � ������ ��������� �� ������.";
				system("pause");
				break;
			}
			j = Library.SearchFilmName(i, Name);
			Library.DeleteFilm(j);
			cout << "����� ������!" << endl;;
			system("pause");
			break;
		case 10:
			Library.SaveFilmoteka();
			cout << "���� ��������!" << endl;
			system("pause");
			break;
		case 11:
		{
			Library = Library.ReadFilmoteka(lib);
			cout << endl << "���� ��������!" << endl;
		}
			system("pause");
			break;
		case 12: break;
		default:
			cout << "������ ������� ���. ��������� ����." << endl;
			system("pause");
		}
	}
}