#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
class BullsCowsGames
{
public:
	int length;
	BullsCowsGames(int _length = 0) : length(_length) {};
	~BullsCowsGames() {};

	vector <int> RandomNumber()
	{
		srand(time(0));
		vector <int> Number(length);
		for (int i = 0; i < length; i++)
		{
			Number[i] = rand() % 9 + 1;
			for (int j = 0; j < i; j++)
			{
				while (Number[i] == Number[j])
				{
					Number[i] = rand() % 10;
					j = 0;
				}
			}
		}
		return Number;
	}

	vector<int> UserNumber(int _number)
	{
		vector <int> Number(length);
		for (int i = length - 1; i >= 0; i--)
		{
			Number[i] = _number % 10;
			_number = _number / 10;
		}
		return Number;
	}

	int getBulls(vector <int> _computer, vector <int> _person)
	{
		vector <int> Computer = _computer;
		vector <int> Person = _person;
		int Bulls = 0;
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if ((Computer[i] == Person[j]) && (i == j))
					Bulls++;
			}
		}
		return Bulls;
	};
	int getCows(vector <int> _computer, vector <int> _person)
	{
		vector <int> Computer = _computer;
		vector <int> Person = _person;
		int Cows = 0;
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if ((Computer[i] == Person[j]) && (i != j))
					Cows++;
			}
		}
		return Cows;
	};

	unsigned int PlayGame()
	{
		vector <int> Person(length);
		vector <int> Computer = RandomNumber();
		int attempts = 0;
		while (getBulls(Computer, Person) != length)
		{
			cout << "Enter your number: " << endl;
			int number;
			cin >> number;
			vector <int> Person = UserNumber(number);
			attempts++;
			cout << "Bulls are " << getBulls(Computer, Person) << ", Cows are " << getCows(Computer, Person) << endl << endl;
			if (getBulls(Computer, Person) == length)
				break;
		};
		return attempts;
	}
};

int main()
{
	int length;
	int attempts;
	cout << "Enter length of number" << endl;
	cin >> length;
	BullsCowsGames Game1(length);
	attempts = Game1.PlayGame();
	cout << "Hooray! You did it. You took " << attempts << " attempts" << endl;
	system("pause");
}