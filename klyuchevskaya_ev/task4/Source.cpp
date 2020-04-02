#define _CRT_SECURE_NO_WARNINGS
#include<locale.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class Contact
{
private:
	string Surname;
	string Name;
	string Middlename;
	string Tel;
	string Birthday;
	bool Favorite;

public:
	Contact(string surname = "фамилия", string name = "имя", string middlename = "отчество", string tel = "телефон",string birthday = "01.12.2000", bool favorite = false)
	{
		Surname = surname;
		Name = name;
		Middlename = middlename;
		Tel = tel;
		Birthday = birthday;
		Favorite = favorite;
	}
	void SetSurname(string surname)
	{
		Surname = surname;
	}

	void SetName(string name)
	{
		Name = name;
	}

	void SetMiddlename(string middlename)
	{
		Middlename = middlename;
	}

	string GetSurname()
	{
		return Surname;
	}

	string GetName()
	{
		return Name;
	}

	string GetMiddlename()
	{
		return Middlename;
	}

	string GetFullName()
	{
		string fullname = Surname + " " + Name + " " + Middlename;
		return fullname;
	}

	void SetTel(string tel)
	{
		Tel = tel;
	}

	string GetTel()
	{
		return Tel;
	}

	void SetBirthday(string birthday)
	{
		Birthday = birthday;
	}

	string GetBirthday()
	{
		return Birthday;
	}

	void SetFavorite(bool favorite)
	{
		Favorite = favorite;
	}

	bool GetFavorite()
	{
		return Favorite;
	}	

	void Show()
	{
		cout << Surname <<" "<< Name << " " << Middlename << " " << Tel << " " << Birthday << " " << " ";
		if (Favorite == true)
			cout << "Контакт в избранном" << endl;
	}

	Contact(const Contact &cont)
	{
		Surname = cont.Surname;
		Name = cont.Name;
		Middlename = cont.Middlename;
		Tel = cont.Tel;
		Birthday = cont.Birthday;
		Favorite = cont.Favorite;
	}

	~Contact() {}

	Contact& operator=(const Contact &cont)
	{
		Surname = cont.Surname;
		Name = cont.Name;
		Middlename = cont.Middlename;
		Tel = cont.Tel;
		Birthday = cont.Birthday;
		Favorite = cont.Favorite;
		return *this;
	}
};

class ContactsBase
{
private:
	vector<Contact> Contacts;
	void Sort()
	{
		unsigned N = Contacts.size();
		unsigned i, j, k;
		Contact t;
		for (k = N / 2; k > 0; k /= 2)
			for (i = k; i < N; i++)
			{
				t = Contacts[i];
				for (j = i; j >= k; j -= k)
				{
					if (t.GetFullName() < Contacts[j - k].GetFullName())
						Contacts[j] = Contacts[j - k];
					else
						break;
				}
				Contacts[j] = t;
			}
	}

public:
	ContactsBase() {}
	~ContactsBase() {}

	ContactsBase(size_t size)
	{
		Contacts.resize(size);
	}

	ContactsBase(vector <Contact> tmp)
	{
		Contacts = tmp;
	}

	ContactsBase(const ContactsBase& tmp)
	{
		Contacts = tmp.Contacts;
	}

	void Show()
	{
		for (size_t i = 0; i < Contacts.size(); i++)
		{
			Contacts[i].Show();
			cout << endl;
		}
	}

	void Show(size_t index)
	{
		Contacts[index].Show();
		cout << endl;
	}

	Contact NewContact()
	{
		Contact contact;
		string s;
		cout << "Введите данные контакта:" << endl;
		cout << "Фамилия: " << endl;
		cin >> s;
		contact.SetSurname(s);
		cout << "Имя: " << endl;
		cin >> s;
		contact.SetName(s);
		cout << "Отчество: " << endl;
		cin >> s;
		contact.SetMiddlename(s);
		cout << "Телефон: " << endl;
		cin >> s;
		contact.SetTel(s);
		cout << "Дата рождения:" << endl;
		cin >> s;
		contact.SetBirthday(s);
		cout << "Добавить контакт в избранное? (1 - Да, 0 - Нет): " << endl;
		bool fav;
		cin >> fav;
		contact.SetFavorite(fav);
		return contact;
	}

	void AddContact(const Contact &c)
	{
		Contacts.push_back(c);
		Sort();
	}
	vector<int> Find(string surname, string name, string middlename)
	{
		size_t i;
		vector <int> found;
		for (i = 0; i < Contacts.size(); i++)
			if ((surname == Contacts[i].GetSurname()) && (name == Contacts[i].GetName()) && (middlename == Contacts[i].GetMiddlename()))
				found.push_back(i);
		return found;
	}

	vector<int> Find(string tel)
	{
		size_t i;
		vector <int> found;
		for (i = 0; i < Contacts.size(); i++)
			if (tel == Contacts[i].GetTel())
				found.push_back(i);
		return found;
	}

	vector <int> ShowByFirstLetter()
	{
		vector <int> index;
		bool flag = false;
		cout << "Введите букву: ";
		char letter;
		cin >> letter;
		cout << endl;
		for (int i = 0; i < Contacts.size(); i++)
		{
			string surname = Contacts[i].GetSurname();
			if (surname[0] == letter)
			{
				index.push_back(i);
				flag = true;
			}
		}
		if (flag == false)
		{
			cout << "Контакт на такую букву не найден" << endl;
			index.push_back(-1);
		}
		return index;
	}

	void AddChanges(size_t numMethod, int numContact, char *newStr)
	{
		void(Contact::*method[7])(string str) = { &Contact::SetSurname, &Contact::SetName, &Contact::SetMiddlename, &Contact::SetTel, &Contact::SetBirthday};

		(Contacts[numContact].*method[numMethod])(newStr);
	}

	bool GetFavoriteStatus(size_t index)
	{
		return Contacts[index].GetFavorite();
	}

	void SetFavoriteStatus(size_t index, bool status)
	{
		Contacts[index].SetFavorite(status);
	}

	int GetKolContacts()
	{
		return Contacts.size();
	}

	void ShowFavorites()
	{
		bool flag = false;
		for (int i = 0; i < Contacts.size(); i++)
		{
			if (Contacts[i].GetFavorite() == true)
			{
				Contacts[i].Show();
				flag = true;
			}
		}
		if (flag == false)
			cout << "Нет избранных контактов!" << endl;
	}

	void deleteContact(size_t index)
	{
		Contacts.erase(Contacts.begin() + index);
	}
	void SaveToFile()
	{
		ofstream fout;
		fout.open("Contacts.txt");
		for (int i = 0; i < Contacts.size(); i++)
		{
			string Surname = Contacts[i].GetSurname();
			string Name = Contacts[i].GetName();
			string Middlename = Contacts[i].GetMiddlename();
			string Tel = Contacts[i].GetTel();
			string Birthday = Contacts[i].GetBirthday();
			bool Favorite = Contacts[i].GetFavorite();
			fout << Surname << ' ' << Name << ' ' << Middlename << ' ' << Tel << ' ' << Birthday << ' ' << Favorite;
		}
		fout.close();
	}

	ContactsBase ReadFromCont(ContactsBase& contact)
	{
		Contact tmp;
		ifstream fout;
		fout.open("Contacts.txt");
		if (!fout.is_open())
			cout << "Ошибка при чтении файла";
		else
			while (!fout.eof())
			{
				string str;
				bool fav;
				getline(fout, str);
				tmp.SetSurname(str);
				getline(fout, str);
				tmp.SetName(str);
				getline(fout, str);
				tmp.SetMiddlename(str);
				getline(fout, str);
				tmp.SetTel(str);
				getline(fout, str);
				tmp.SetBirthday(str);
				fout >> fav;
				tmp.SetFavorite(fav);
				fout.ignore();
				contact.Contacts.push_back(tmp);
			}
		fout.close();
		return contact;
	}

	Contact& operator[](const int &i)
	{
		return Contacts[i];
	}
};

vector <int> SearchByFIO(ContactsBase& contact)
{
	string _Surname, _Name, _Midd;
	int again;
	vector <int> indexes;
	do
	{
		cout << "Введите фамилию: " << endl;
		cin >> _Surname;
		cout << "Введите имя: " << endl;
		cin >> _Name;
		cout << "Введите отчество: " << endl;
		cin >> _Midd;
		indexes = contact.Find(_Surname, _Name, _Midd);
		if (indexes.size() == 0)
		{
			cout << "Контакт с таким ФИО не найден!" << endl;
			cout << "Продолжить поиск? (1 - да; 0 - нет):" << endl;
			cin >> again;
		}
		else
			again = 0;
	} while ((indexes.size() == 0) && (again == 1));
	if (indexes.size() > 0)
	{
		cout << endl << "Нашелся один контакт:" << endl;
		for (size_t i = 0; i < indexes.size(); i++)
		{
			cout << i + 1 << "." << endl;
			contact.Show(indexes[i]);
		}
	}
	return indexes;
}

int FindByN(vector <int> indexes)
{
	int index, _index;
	if (indexes.size() == 0)
		index = -1;
	else if (indexes.size() == 1)
		index = indexes[0];
	else
	{
		cout << "Введите номер нужного контакта";
		cin >> _index;
		_index -= 1;
		index = indexes[_index];
	}
	return index;
}
void СhangeFavourite(ContactsBase& contact, size_t index)
{
	if (contact.GetFavoriteStatus(index))
	{
		cout << "Убрать контакт из избранных? (1 - да, 0 - нет): ";
		int f;
		cin >> f;
		if (f == 1)
		{
			contact.SetFavoriteStatus(index, false);
			cout << "Контакт убран из избранных" << endl;
		}
	}
	else
	{
		cout << "Добавить контакт в избранные? (1 - да; 0 - нет): ";
		int f;
		cin >> f;
		if (f == 1)
		{
			contact.SetFavoriteStatus(index, true);
			cout << "Контакт добавлен в избранные " << endl;
		}
	}
}

vector<int> SearchByTel(ContactsBase& contact)
{
	string _tel;
	int again;
	vector <int> indexes;
	do
	{
		cout << "Введите номер телефона: " << endl;
		cin >> _tel;

		indexes = contact.Find(_tel);
		if (indexes.size() == 0)
		{
			cout << "Контакт не найден" << endl;
			cout << "Попробовать ещё раз? (1 - да; 0 - нет):" << endl;
			cin >> again;
		}
		else
			again = 0;
	} while ((indexes.size() == 0) && (again == 1));
	if (indexes.size() > 0)
	{
		cout << endl << "Найден один контакт:" << endl ;
		for (size_t i = 0; i < indexes.size(); i++)
		{
			cout << i + 1 << "." << endl;
			contact.Show(indexes[i]);
		}
	}
	return indexes;
}

vector <int> Search(ContactsBase& contact)
{
	int vib;
	cout << "Найти контакт: " << endl;
	cout << "1 - по ФИО" << endl;
	cout << "2 - по телефону" << endl;
	cin >> vib;

	vector <int> indexes;
	switch (vib)
	{
	case 1:
		indexes = SearchByFIO(contact);
		break;
	case 2:
		indexes = SearchByTel(contact);
		break;
	default:
		break;
	}
	return indexes;
}

void ChangeContact(ContactsBase& contact)
{
	char buff[256];
	cout << "Выберите контакт, который хотите изменить." << endl;
	vector <int> indexes = Search(contact);
	int index = FindByN(indexes);
	if (index == -1)
		return;
	cout << endl << "Что хотите изменить?:" << endl;
	int method;
	do
	{
		contact.Show(index);
		cout << "1 - Фамилию" << endl;
		cout << "2 - Имя" << endl;
		cout << "3 - Отчество" << endl;
		cout << "4 - Номер телефона" << endl;
		cout << "5 - Дату рождения" << endl;
		cout << "6 - Добавить/удалить контакт из избранного" << endl;
		cout << "7 - Закончить редактирование" << endl;
		cin >> method;
		switch (method)
		{
		case 1:
			cout << "Введите фамилию: " << endl;
			cin >> buff;
			contact.AddChanges(0, index, buff);
			break;
		case 2:
			cout << "Введите имя: " << endl;
			cin >> buff;
			contact.AddChanges(1, index, buff);
			break;
		case 3:
			cout << "Введите отчество: " << endl;
			cin >> buff;
			contact.AddChanges(2, index, buff);
			break;
		case 4:
			cout << "Введите номер: " << endl;
			cin >> buff;
			contact.AddChanges(3, index, buff);
			break;
		case 5:
			cout << "Введите дату рождения: " << endl;
			cin >> buff;
			contact.AddChanges(4, index, buff);
		case 6:
			СhangeFavourite(contact, index);
			break;
		default:
			break;
		}
	} while (method != 7);
}

void DeleteContact(ContactsBase& contact)
{
	cout << "Найдите контакт который хотите удалить" << endl;
	vector <int> indexes = Search(contact);
	int index = FindByN(indexes);
	if (index == -1)
		return;
	contact.Show(index);
	cout << "Удалить данный контакт?(1 - Да; 0 - Нет): "<<endl;
	int vb;
	cin >> vb;
	if (vb == 1)
	{
		contact.deleteContact(index);
		cout << "Контакт удален." << endl;
	}
}


void Menu()
{
	cout << "1)Создать новый контакт" << endl << "2)Изменить выбранный контакт" << endl << "3)Найти контакт" << endl << "4)Выдать все контакты на заданную букву" << endl << "5)Узнать текущее число контактов"<<endl;
	cout <<  "6)Выдать все избранные контакты" << endl << "7)Удалить контакт" << endl << "8)Сохранить контакты в файл" << endl<<"9)Считать контакты из файла" << endl;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	Contact contact;
	ContactsBase base;
	ContactsBase Base;
	int i;
	bool flag = false;
	do
	{
		system("cls");
		Menu();
		int mode;
		cin >> mode;
		vector <int> index;
		switch (mode)
		{
		case 1:
			contact = Base.NewContact();
			Base.AddContact(contact);
			break;
		case 2:
			ChangeContact(Base);
			break;
		case 3:
			Search(Base);
			break;
		case 4:
			index = Base.ShowByFirstLetter();
			if (index[0] != -1)
				for (i = 0; i < index.size(); i++)
					Base[i].Show();
			break;
		case 5:
			cout << Base.GetKolContacts() << endl;
			break;
		case 6:
			Base.ShowFavorites();
			break;
		case 7:
			DeleteContact(Base);
			break;
		case 8:
			Base.SaveToFile();
			break;
		case 9:
			Base=Base.ReadFromCont(base);
			break;
		}

		cout << "Вернуться в меню? (1 - Да, 0 - Нет)" << endl;
		cin >> flag;
	} while (flag == true);
	system("pause");
}