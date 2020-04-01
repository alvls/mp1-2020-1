#include <iostream>
#include <string>
#include <clocale>
#include <vector>
#include <fstream>
#include <Windows.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::size;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::strcpy;

class Contact
{
private:
	string surname;
	string name;
	string patronymic;
	string phone;
	string day;
	string month;
	string year;
	bool is_favourite;
public:
	Contact(string _surname = "-", string _name = "-", string _patronymic = "-", string _phone = "-", string _day = "-", string _month = "-", string _year = "-", bool _is_favourite = false) :
		surname(_surname), name(_name), patronymic(_patronymic), phone(_phone), day(_day), month(_month), year(_year), is_favourite(_is_favourite)
	{}
	
	~Contact() {};

	void Set_Surname(string _surname)
	{
		surname = _surname;
	}

	void Set_Name(string _name)
	{
		name = _name;
	}

	void Set_Patronymic(string _patronymic)
	{
		patronymic = _patronymic;
	}

	void Set_Phone(string _phone)
	{
		phone = _phone;
	}

	void Set_Day(string _day)
	{
		day = _day;
	}

	void Set_Month(string _month)
	{
		month = _month;
	}

	void Set_Year(string _year)
	{
		year = _year;
	}

	void Is_Favourite(bool _is_favourite)
	{
		is_favourite = _is_favourite;
	}

	string Get_Surname()
	{
		return surname;
	}

	string Get_Name()
	{
		return name;
	}

	string Get_Patronymic()
	{
		return patronymic;
	}

	string Get_Phone()
	{
		return phone;
	}

	string Get_Day()
	{
		return day;
	}

	string Get_Month()
	{
		return month;
	}

	string Get_Year()
	{
		return year;
	}

	bool Is_Favourite()
	{
		return is_favourite;
	}

	void Show_Contact()
	{
		cout << surname << endl << name << endl << patronymic << endl << phone << endl << day << " " << month << " " << year << endl;
		if (is_favourite == true)
			cout << "Контакт в избранном" << endl;
	}

	Contact& operator=(const Contact &contact)
	{
		surname = contact.surname;
		name = contact.name;
		patronymic = contact.patronymic;
		phone = contact.phone;
		day = contact.day;
		month = contact.month;
		year = contact.year;
		is_favourite = contact.is_favourite;
		return *this;
	}

	Contact(const Contact &contact)
	{
		surname = contact.surname;
		name = contact.name;
		patronymic = contact.patronymic;
		phone = contact.phone;
		day = contact.day;
		month = contact.month;
		year = contact.year;
		is_favourite = contact.is_favourite;
	}

	bool operator==(const Contact &contact)
	{
		if ((surname == contact.surname) && (name == contact.name) && (patronymic == contact.patronymic) && (day == contact.day) && (month == contact.month) && (year == contact.year) && (is_favourite == contact.is_favourite))
			return true;
		else
			return false;
	}
};

class ContactList
{
private:
	vector<Contact> list;
public:
	ContactList() {}
	~ContactList() {}

	void Create_New_Contact(const string &surname, const string &name, const string &patronymic, const string &phone, const string &day, const string &month, const string &year, const bool &fav)
	{
		Contact contact;
		contact = Contact(surname, name, patronymic, phone, day, month, year, fav);
		Add_Contact(contact);
	}

	void Add_Contact(const Contact &contact)
	{
		list.push_back(contact);
		Sort_ContactList();
	}

	void Change_Contact(const int &num_contact, const int &mode, const string &change)
	{
			switch (mode)
			{
			case 1:
				list[num_contact].Set_Surname(change);
				break;
			case 2:
				list[num_contact].Set_Name(change);
				break;
			case 3:
				list[num_contact].Set_Patronymic(change);
				break;
			case 4:
				list[num_contact].Set_Phone(change);
				break;
			case 5:
				list[num_contact].Set_Day(change);
				break;
			case 6:
				list[num_contact].Set_Month(change);
				break;
			case 7:
				list[num_contact].Set_Year(change);
				break;
			}
		Sort_ContactList();
	}

	int Search_By_Name(const string &surname, const string &name, const string &patronymic)
	{
		bool flag = false;
		int i;
		for (i = 0; i < list.size(); i++)
		{
			if ((surname == list[i].Get_Surname()) && (name == list[i].Get_Name()) && (patronymic == list[i].Get_Patronymic()))
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			cout << "Контакта с таким ФИО нет!" << endl;
			i = -1;
		}
		return i;
	}

	int Search_By_Phone(const string &phone)
	{
		bool flag = false;
		int i;
		for (i = 0; i < list.size(); i++)
		{
			if (list[i].Get_Phone() == phone)
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			cout << "Контакта с таким номером нет!" << endl;
			i = -1;
		}
		return i;
	}

	 vector <int> Show_By_Letter(const char &letter)
	{
		vector <int> contact_numbers;
		bool flag = false;
		for (int i = 0; i < list.size(); i++)
		{
			string surname = list[i].Get_Surname();
			if (surname[0] == letter)
			{
				contact_numbers.push_back(i);
				flag = true;
			}
		}
		if (flag == false)
		{
			cout << "Контакта на такую букву нет!" << endl;
			contact_numbers.push_back(-1);
		}
		return contact_numbers;
	}

	int Get_Count_Of_Contacts()
	{
		return list.size();
	}

	void Add_To_Favourites(const int &num_contact)
	{
		list[num_contact].Is_Favourite(true);
	}

	void Delete_From_Favourites(const int &num_contact)
	{
		list[num_contact].Is_Favourite(false);
	}

	void Show_Favourites()
	{
		bool flag = false;
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i].Is_Favourite() == true)
			{
				list[i].Show_Contact();
				flag = true;
			}
		}
		if (flag == false)
			cout << "Нет избранных контактов!" << endl;
	}

	void Delete_Contact(const int &num_contact)
	{
		list.erase(list.begin() + num_contact);
	}

	void Save_To_File(const char *path)
	{
		ofstream file(path, ios::app);
		int n = Get_Count_Of_Contacts();
		for (int i = 0; i < n; i++)
		{
			file << list[i].Get_Surname() << endl;
			file << list[i].Get_Name() << endl;
			file << list[i].Get_Patronymic() << endl;
			file << list[i].Get_Phone() << endl;;
			file << list[i].Get_Day() << endl;
			file << list[i].Get_Month() << endl;
			file << list[i].Get_Year() << endl;
			if (list[i].Is_Favourite() == true)
				file << "1" << endl;
			else
				file << "0" << endl;
		}
		file.close();
	}

	void Load_From_File(const char *path)
	{
		try
		{
			ifstream file(path);
			string str;
			Contact contact;
			if (!file.is_open())
			{
				char error[256];
				strcpy_s(error, path);
				throw error;
			}
			while (getline(file, str))
			{
				contact.Set_Surname(str);
				getline(file, str);
				contact.Set_Name(str);
				getline(file, str);
				contact.Set_Patronymic(str);
				getline(file, str);
				contact.Set_Phone(str);
				getline(file, str);
				contact.Set_Day(str);
				getline(file, str);
				contact.Set_Month(str);
				getline(file, str);
				contact.Set_Year(str);
				getline(file, str);
				if (str == "1")
					contact.Is_Favourite(true);
				else
					contact.Is_Favourite(false);
				Add_Contact(contact);
			}
			file.close();
		}
		catch (char *error)
		{
			cout << "Ошибка - файл " << error << " не может быть открыт!" << endl;
		}
	}

	void Sort_ContactList()
	{
		int n = Get_Count_Of_Contacts();
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1; j > i; j--)
			{
				if (list[j - 1].Get_Surname() == list[j].Get_Surname())
				{
					if (list[j - 1].Get_Name() == list[j].Get_Name())
					{
						if (list[j - 1].Get_Patronymic() > list[j].Get_Patronymic())
						{
							Transposition(j);
						}
					}
					else if (list[j - 1].Get_Name() > list[j].Get_Name())
					{
						Transposition(j);
					}

				}
				else if (list[j - 1].Get_Surname() > list[j].Get_Surname())
				{
					Transposition(j);
				}
			}
		}
	}

	void Transposition(int i)
	{
		Contact tmp;
		tmp = list[i - 1];
		list[i - 1] = list[i];
		list[i] = tmp;
	}

	Contact& operator[](const int &i)
	{
		return list[i];
	}
};

void Menu()
{
	cout << "1)Создать новый контакт" << endl << "2)Изменить выбранный контакт" << endl << "3)Найти контакт по ФИО" << endl << "4)Найти контакт по телефону" << endl;
	cout << "5)Выдать все контакты на заданную букву" << endl << "6)Узнать текущее число контактов" << endl << "7)Внести контакт в список избранных" << endl;
	cout << "8)Удалить контакт из списка избранных" << endl << "9)Выдать все избранные контакты" << endl << "10)Удалить контакт" << endl << "11)Сохранить контакты в файл" << endl;
	cout << "12)Считать контакты из файла" << endl;
}

int Find_Contact(ContactList &list)
{
	cout << "Выберете способ поиска:" << endl;
	cout << "1)Найти контак по ФИО" << endl << "2)Найти контакт по телефону" << endl;
	int mode, i;
	cin >> mode;
	string surname, name, patronymic, phone;
	switch (mode)
	{
	case 1:
		cout << "Введите фамилию: ";
		cin >> surname;
		cout << endl;
		cout << "Введите имя: ";
		cin >> name;
		cout << endl;
		cout << "Введите отчество: ";
		cin >> patronymic;
		cout << endl;
		i = list.Search_By_Name(surname, name, patronymic);
		break;
	case 2:
		cout << "Введите телефон: ";
		cin >> phone;
		i = list.Search_By_Phone(phone);
		break;
	}
	return i;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	Contact contact;
	ContactList list;
	bool flag = false;
	list.Load_From_File("contacts.txt");
	do
	{
		system("cls");
		Menu();
		int mode, i;
		cin >> mode;
		vector <int> contact_numbers;
		string surname, name, patronymic, phone, day, month, year, change;
		bool fav;
		char letter, path[256];
		switch (mode)
		{
			case 1:
				cout << "Введите данные контакта:" << endl;
				cout << "Фамилия: " << endl;
				cin >> surname;
				cout << "Имя: " << endl;
				cin >> name;
				cout << "Отчество: " << endl;
				cin >> patronymic;
				cout << "Телефон: " << endl;
				cin >> phone;
				cout << "Дата рождения:" << endl;
				cout << "День: " << endl;
				cin >> day;
				cout << "Месяц: " << endl;
				cin >> month;
				cout << "Год: " << endl;
				cin >> year;
				cout << "Добавить в избранное? (1 - Да, 0 - Нет): " << endl;
				cin >> fav;
				list.Create_New_Contact(surname, name, patronymic, phone, day, month, year, fav);
				break;
			case 2:
				i = Find_Contact(list);
				cout << "Что хотите изменить?" << endl;
				cout << "1)Фамилия" << endl << "2)Имя" << endl << "3)Отчество" << endl << "4)Телефон" << endl << "Дата рождения:" << endl << "5)День" << endl << "6)Месяц" << endl << "7)Год" << endl;
				cin >> mode;
				cout << "Введите изменение: " << endl;
				cin >> change;
				list.Change_Contact(i, mode, change);
				break;
			case 3:
				cout << "Введите фамилию: ";
				cin >> surname;
				cout << endl;
				cout << "Введите имя: ";
				cin >> name;
				cout << endl;
				cout << "Введите отчество: ";
				cin >> patronymic;
				cout << endl;
				i = list.Search_By_Name(surname, name, patronymic);
				if (i != -1)
					list[i].Show_Contact();
				break;
			case 4:
				cout << "Введите телефон: ";
				cin >> phone;
				cout << endl;
				i = list.Search_By_Phone(phone);
				if (i != -1)
					list[i].Show_Contact();
				break;
			case 5:
				cout << "Введите букву: ";
				cin >> letter;
				cout << endl;
				contact_numbers = list.Show_By_Letter(letter);
				if (contact_numbers[0] != -1)
					for (i = 0; i < contact_numbers.size(); i++)
						list[contact_numbers[i]].Show_Contact();
					break;
				case 6:
					cout << list.Get_Count_Of_Contacts() << endl;
					break;
				case 7:
					i = Find_Contact(list);
					list.Add_To_Favourites(i);
					break;
				case 8:
					i = Find_Contact(list);
					list.Delete_From_Favourites(i);
					break;
				case 9:
					list.Show_Favourites();
					break;
				case 10:
					i = Find_Contact(list);
					list.Delete_Contact(i);
					break;
				case 11:
					cout << "Введите путь к файлу: ";
					cin >> path;
					cout << endl;
					list.Save_To_File(path);
					break;
				case 12:
					cout << "Введите путь к файлу: ";
					cin >> path;
					cout << endl;
					list.Load_From_File(path);
					break;
		}
		cout << "Продолжить? (1 - Да, 0 - Нет)" << endl;
		cin >> flag;
	} while (flag == true);
	system("pause");
}