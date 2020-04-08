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
	Information(string _Name = "Без названия", int _Year = 1, int _Month = 1, int _Day= 1, int _Fees = 0, string _Producer = "Не указан", string _Screenwriter = "Не указан", string _Composer = "не указан")
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
	void AddFilm(string _Name = "Без названия", int _Year = 1, int _Month = 1, int _Day = 1, int _Fees = 0, string _Producer = "Не указан", string _Screenwriter = "Не указан", string _Composer = "не указан")
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
	void ChangeFilm(int _index, string _Name = "Без названия", int _Year = 1, int _Month = 1, int _Day = 1, int _Fees = 0, string _Producer = "Не указан", string _Screenwriter = "Не указан", string _Composer = "не указан")
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
			cout << "Ошибка открытия";
		else
			for (int i = 0; i < Films.size(); i++)
			{
				file << "Название фильма: " << Films[i].getName() << endl;
				file << "Дата выхода: " << Films[i].getYear() << "." << Films[i].getMonth() << "." << Films[i].getDay() << endl;
				file << "Сборы: " << Films[i].getFees() << endl;
				file << "Режиссер: " << Films[i].getProducer() << endl;
				file << "Сценарист: " << Films[i].getScreenwriter() << endl;
				file << "Композитор: " << Films[i].getComposer() << endl << endl;
			}
		file.close();
		ofstream File;
		File.open("FilmotekaRec.txt");
		if (!File.is_open())
			cout << "Ошибка открытия";
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
			cout << "Ошибка открытия";
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
	cout << "Название фильма: " << _Library.GetName(_index) << endl;
	cout << "Дата выхода: " << _Library.GetYear(_index) << "." << _Library.GetMonth(_index) << "." << _Library.GetDay(_index) << endl;
	cout << "Сборы: " << _Library.GetFees(_index) << endl;
	cout << "Режиссер: " << _Library.GetProducer(_index) << endl;
	cout << "Сценарист: " << _Library.GetScreenwriter(_index) << endl;
	cout << "Композитор: " << _Library.GetComposer(_index) << endl << endl;
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
		cout << "Фильмов данного режиссера не найдено." << endl;
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
		cout << "Фильмов в данном году не найдено." << endl;
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
		cout << "Фильм с данными параметрами не найден." << endl;
	return film_numbers;
}
vector <int>  PrintFees(int _Number, Filmoteka _Library)
{
	vector <int> film_numbers;
	if (_Number > _Library.GetNumberFilms())
	{
		cout << "Количество запрашиваемых фильмов превышает общее количество. Будет выведено - " << _Library.GetNumberFilms() << endl;
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
		cout << "Не найдено ни одного фильма " << _Year << " года" << endl;
		film_numbers.push_back(-1);
	}
	if (_Number > num)
		cout << "Количество запрашиваемых фильмов превышает количество фильмов данного года. Будет выведено - " << num << endl;
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
	cout << "1. Добавить новый фильм" << endl;
	cout << "2. Изменить данные фильма" << endl;
	cout << "3. Найти фильм" << endl;
	cout << "4. Вывести все фильмы заданного режиссера" << endl;;
	cout << "5. Вывести все фильмы, вышедшие в прокат в выбранном году" << endl;
	cout << "6. Вывести заданное число фильмов с наибольшими сборами " << endl;
	cout << "7. Вывести заданное число фильмов с наибольшими сборами в выбранном году " << endl;
	cout << "8. Узнать текущее число фильмов" << endl;
	cout << "9. Удалить фильм " << endl;
	cout << "10. Сохранить фильмотеку в файл " << endl;
	cout << "11. Считать фильмотеку из файла." << endl;
	cout << "12. Выход" << endl;
	cout << "Ваш выбор: ";
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	vector <int> film_number;
	string Name, Produсer, Screenwriter, Composer;
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
			cout << "Введите название фильма: ";
			cin >> Name;
			do
			{
				cout << endl << "Введите дату выхода(Год месяц число): ";
				cin >> Year >> Month >> Day;
			} while (!Library.ControlDate(Year, Month, Day));
			cout << endl << "Введите сборы(в рублях): ";
			cin >> Fees;
			cout << endl << "Введите фамилию режиссера: ";
			cin >>Produсer;
			cout << endl << "Введите фамилию сценариста: ";
			cin >> Screenwriter;
			cout << endl << "Введите фамилию композитора: ";
			cin >> Composer;
			Library.AddFilm(Name, Year, Month, Day, Fees, Produсer, Screenwriter, Composer);
			cout << endl << "Фильм добавлен!" << endl;
			system("pause");
			break;
		case 2:
			cout << "Введите название фильма, который хотите изменить: ";
			cin.ignore();
			getline(cin, Name);
			if (Library.SearchFilmName(i, Name) < 0)
			{
				cout << endl << "Фильм с данным названием не найден.";
				system("pause");
				break;
			}
			else
			{
				cout << "Введите год выхода фильма ";
				cin >> x;
				if (Library.SearchFilmYear(i,Year) < 0)
				{
					cout << endl << "Фильм с данным названием и годом не найден.";
					system("pause");
					break;
				}

			}
			j = Library.SearchFilmName(i, Name);
			cout << "Введите название нового фильма: ";
			getline(cin, Name);
			do
			{
				cout << endl << "Введите дату выхода(Год месяц число): ";
				cin >> Year >> Month >> Day;
			} while (!Library.ControlDate(Year, Month, Day));
			cout << endl << "Введите сборы(в рублях): ";
			cin >> Fees;
			cout << endl << "Введите фамилию режиссера: ";
			cin.ignore();
			getline(cin, Produсer);
			cout << endl << "Введите фамилию сценариста: ";
			getline(cin, Screenwriter);
			cout << endl << "Введите фамилию композитора: ";
			getline(cin, Composer);
			Library.ChangeFilm(j, Name, Year, Month, Day, Fees, Produсer, Screenwriter, Composer);
			cout << "Фильм изменен!" << endl;
			system("pause");
			break;
		case 3:
			cout << "Введите название фильма: ";
			cin.ignore();
			getline(cin, Name);
			cout << endl << "Введите год: ";
			cin >> Year;
			cout << endl;
			PrintFilmSearch(Name, Year, Library);
			system("pause");
			break;
		case 4:
			cout << "Введите фамилию режиссера: ";
			cin.ignore();
			getline(cin, Produсer);
			film_number = PrintFilmProducer(Produсer, Library);
			if (film_number[0] != -1)
				for (i = 0; i < film_number.size(); i++)
					Print(film_number[i], Library);
			system("pause");
			break;
		case 5:
			cout << "Введите год: ";
			cin >> Year;
			film_number = PrintFilmYear(Year, Library);
			if (film_number[0] != -1)
				for (i = 0; i < film_number.size(); i++)
					Print(film_number[i], Library);
			system("pause");
			break;
		case 6:
			cout << "Введите количество фильмов: ";
			cin >> number;
			cout << endl;
			film_number = PrintFees(number, Library);
			if (film_number[0] != -1)
				for (i = 0; i < film_number.size(); i++)
					Print(film_number[i], Library);
			system("pause");
			break;
		case 7:
			cout << "Введите количество фильмов: ";
			cin >> number;
			cout << endl;
			cout << "Введите год: ";
			cin >> Year;
			cout << endl;
			film_number = PrintFeesYear(number, Year, Library);
			if (film_number[0] != -1)
				for (i = 0; i < film_number.size(); i++)
					Print(film_number[i], Library);
			system("pause");
			break;
		case 8:
			cout << "Количество фильмов = " << Library.GetNumberFilms() << endl;
			system("pause");
			break;
		case 9:
			cout << "Введите название фильма, который хотите удалить: ";
			cin.ignore();
			getline(cin, Name);
			if (Library.SearchFilmName(i, Name) < 0)
			{
				cout << endl << "Фильм с данным названием не найден.";
				system("pause");
				break;
			}
			j = Library.SearchFilmName(i, Name);
			Library.DeleteFilm(j);
			cout << "Фильм удален!" << endl;;
			system("pause");
			break;
		case 10:
			Library.SaveFilmoteka();
			cout << "Файл сохранен!" << endl;
			system("pause");
			break;
		case 11:
		{
			Library = Library.ReadFilmoteka(lib);
			cout << endl << "Файл прочитан!" << endl;
		}
			system("pause");
			break;
		case 12: break;
		default:
			cout << "Данной команды нет. Проверьте ввод." << endl;
			system("pause");
		}
	}
}