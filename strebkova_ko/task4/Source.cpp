#include <iostream>
#include <clocale>
#include <string>
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

	~Contact() {};
};

class ContactList
{
private:
	vector<Contact> list;
public:
	ContactList() {}
	~ContactList() {}

	Contact Create_New_Contact()
	{
		Contact contact;
		string str;
		cout << "Введите данные контакта:" << endl;
		cout << "Фамилия: " << endl;
		cin >> str;
		contact.Set_Surname(str);
		cout << "Имя: " << endl;
		cin >> str;
		contact.Set_Name(str);
		cout << "Отчество: " << endl;
		cin >> str;
		contact.Set_Patronymic(str);
		cout << "Телефон: " << endl;
		cin >> str;
		contact.Set_Phone(str);
		cout << "Дата рождения:" << endl;
		cout << "День: " << endl;
		cin >> str;
		contact.Set_Day(str);
		cout << "Месяц: " << endl;
		cin >> str;
		contact.Set_Month(str);
		cout << "Год: " << endl;
		cin >> str;
		contact.Set_Year(str);
		cout << "Добавить в избранное? (1 - Да, 0 - Нет): " << endl;
		bool fav;
		cin >> fav;
		contact.Is_Favourite(fav);
		return contact;
	}

	void Add_Contact(const Contact &contact)
	{
		list.push_back(contact);
		this->Sort_ContactList();
	}

	Contact Find_Contact()
	{
		Contact contact;
		cout << "Выберете способ поиска:" << endl;
		cout << "1)Найти контак по ФИО" << endl << "2)Найти контакт по телефону" << endl;
		int mode, i;
		cin >> mode;
		switch (mode)
		{
		case 1:
			i = this->Search_By_Name();
			break;
		case 2:
			i = this->Search_By_Phone();
			break;
		}
		contact = list[i];
		return contact;
	}

	void Change_Contact()
	{
		bool flag = false;
		int num_contact = this->Get_Number_Of_Contact(this->Find_Contact());
		do
		{
			string change;
			cout << "Что хотите изменить?" << endl;
			cout << "1)Фамилия" << endl << "2)Имя" << endl << "3)Отчество" << endl << "4)Телефон" << endl << "Дата рождения:" << endl << "5)День" << endl << "6)Месяц" << endl << "7)Год" << endl;
			int mode;
			cin >> mode;
			switch (mode)
			{
			case 1:
				cout << "Введите фамилию: ";
				cin >> change;
				list[num_contact].Set_Surname(change);
				break;
			case 2:
				cout << "Введите имя: ";
				cin >> change;
				list[num_contact].Set_Name(change);
				break;
			case 3:
				cout << "Введите отчество: ";
				cin >> change;
				list[num_contact].Set_Patronymic(change);
				break;
			case 4:
				cout << "Введите телефон: ";
				cin >> change;
				list[num_contact].Set_Phone(change);
				break;
			case 5:
				cout << "Введите день: ";
				cin >> change;
				list[num_contact].Set_Day(change);
				break;
			case 6:
				cout << "Введите месяц: ";
				cin >> change;
				list[num_contact].Set_Month(change);
				break;
			case 7:
				cout << "Введите год: ";
				cin >> change;
				list[num_contact].Set_Year(change);
				break;
			}
			cout << endl;
			cout << "Хотите изменить что-то ещё? (1 - Да, 0 - Нет)" << endl;
			cin >> flag;
		} while (flag == true);
		this->Sort_ContactList();
	}

	int Search_By_Name()
	{
		bool flag = false;
		string surname, name, patronymic;
		cout << "Введите фамилию: ";
		cin >> surname;
		cout << endl;
		cout << "Введите имя: ";
		cin >> name;
		cout << endl;
		cout << "Введите отчество: ";
		cin >> patronymic;
		cout << endl;
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

	int Search_By_Phone()
	{
		bool flag = false;
		string phone;
		cout << "Введите телефон: ";
		cin >> phone;
		cout << endl;
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

	 vector <int> Show_By_Letter()
	{
		vector <int> contact_numbers;
		bool flag = false;
		cout << "Введите букву: ";
		char letter;
		cin >> letter;
		cout << endl;
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

	void Add_To_Favourites()
	{
		int num_contact = this->Get_Number_Of_Contact(this->Find_Contact());
		if (list[num_contact].Is_Favourite() == true) {}
		else
			list[num_contact].Is_Favourite(true);
	}

	void Delete_From_Favourites()
	{
		int num_contact = this->Get_Number_Of_Contact(this->Find_Contact());
		if (list[num_contact].Is_Favourite() == false) {}
		else
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

	void Delete_Contact()
	{
		int num_contact = this->Get_Number_Of_Contact(this->Find_Contact());
		list.erase(list.begin() + num_contact);
	}

	void Save_To_File()
	{
		cout << "Введите путь к файлу: ";
		char path[256];
		cin >> path;
		cout << endl;
		ofstream file(path, ios::app);
		int n = this->Get_Count_Of_Contacts();
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

	void Load_From_File()
	{
		cout << "Введите путь к файлу: ";
		char path[256];
		cin >> path;
		cout << endl;
		try
		{
			this->Load_From_File(path);
		}
		catch (char *error)
		{
			cout << "Ошибка - файл " << error << " не может быть открыт!" << endl;
		}

	}

	void Load_From_File(const char *path)
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
			this->Add_Contact(contact);
		}
		file.close();
	}

	void Show_ContactList()
	{
		for (int i = 0; i < list.size(); i++)
		{
			list[i].Show_Contact();
		}
	}

	int Get_Number_Of_Contact(const Contact &contact)
	{
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i] == contact)
				return i;
		}
	}

	void Sort_ContactList()
	{
		int n = this->Get_Count_Of_Contacts();
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
							this->Transposition(j);
						}
					}
					else if (list[j - 1].Get_Name() > list[j].Get_Name())
					{
						this->Transposition(j);
					}

				}
				else if (list[j - 1].Get_Surname() > list[j].Get_Surname())
				{
					this->Transposition(j);
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

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	Contact contact;
	ContactList list;
	bool flag = false;
	int i;
	list.Load_From_File("contacts.txt");
	do
	{
		system("cls");
		Menu();
		int mode;
		cin >> mode;
		vector <int> contact_numbers;
		switch (mode)
		{
			case 1:
				contact = list.Create_New_Contact();
				list.Add_Contact(contact);
				break;
			case 2:
				list.Change_Contact();
				break;
			case 3:
				i = list.Search_By_Name();
				if (i != -1)
					list[i].Show_Contact();
				break;
			case 4:
				i = list.Search_By_Phone();
				if (i != -1)
					list[i].Show_Contact();
				break;
			case 5:
				contact_numbers = list.Show_By_Letter();
				if (contact_numbers[0] != -1)
					for (i = 0; i < contact_numbers.size(); i++)
						list[i].Show_Contact();
				break;
			case 6:
				cout << list.Get_Count_Of_Contacts() << endl;
				break;
			case 7:
				list.Add_To_Favourites();
				break;
			case 8:
				list.Delete_From_Favourites();
				break;
			case 9:
				list.Show_Favourites();
				break;
			case 10:
				list.Delete_Contact();
				break;
			case 11:
				list.Save_To_File();
				break;
			case 12:
				list.Load_From_File();
				break;
		}
		cout << "Продолжить? (1 - Да, 0 - Нет)" << endl;
		cin >> flag;
	} while (flag == true);
	system("pause");
}