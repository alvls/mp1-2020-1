#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <clocale>

using namespace std;

class Cell
{
	int x;
	int y;
	bool is_ship;
	bool is_dead;
	bool is_try;
public:
	Cell(int _x = 0, int _y = 0, bool _is_ship = false, bool _is_dead = false, bool _is_try = false) : x(_x), y(_y), is_ship(_is_ship), is_dead(_is_dead), is_try(_is_try) {}

	~Cell() {}

	Cell(const Cell &cell)
	{
		x = cell.x;
		y = cell.y;
		is_ship = cell.is_ship;
		is_dead = cell.is_dead;
		is_try = cell.is_try;
	}

	Cell& operator=(const Cell &cell)
	{
		x = cell.x;
		y = cell.y;
		is_ship = cell.is_ship;
		is_dead = cell.is_dead;
		is_try = cell.is_try;
		return *this;
	}

	int Get_x()
	{
		return x;
	}

	int Get_y()
	{
		return y;
	}

	void Set_Ship_True()
	{
		is_ship = true;
	}

	bool Is_Ship()
	{
		return is_ship;
	}

	bool Is_Dead()
	{
		return is_dead;
	}

	void Set_Dead_True()
	{
		is_dead = true;
	}

	bool Is_Try()
	{
		return is_try;
	}

	void Set_Try_True()
	{
		is_try = true;
	}

	bool operator==(Cell &cell)
	{
		if ((cell.Get_x() == x) && (cell.Get_y() == y))
			return true;
		else return false;
	}
};

class Ship
{
	Cell cell;
	bool direction; //true - vertical, false - horizontal
	int size;
public:
	Ship(Cell _cell = Cell(), bool _direction = false, int _size = 1) : cell(_cell), direction(_direction), size(_size) {}

	~Ship() {}

	Ship(const Ship &ship)
	{
		cell = ship.cell;
		direction = ship.direction;
		size = ship.size;
	}

	Ship& operator=(const Ship &ship)
	{
		cell = ship.cell;
		direction = ship.direction;
		size = ship.size;
		return *this;
	}

	int Get_Size()
	{
		return size;
	}

	Cell Get_Cell()
	{
		return cell;
	}

	bool Get_Direction()
	{
		return direction;
	}
};

class Field
{
	vector <Cell> cells;
	int count_of_cellships;
public:
	Field(vector <Cell> _cells = {}, int _count_of_cellships = 0) : cells(_cells), count_of_cellships(_count_of_cellships)
	{
		if (cells.size() == 0)
			for (int i = 0; i < 100; i++)
			{
				cells.push_back(Cell(i % 10, int(i / 10)));
			}
	}

	~Field() {}

	Field(const Field &field)
	{
		cells = field.cells;
		count_of_cellships = field.count_of_cellships;
	}

	Field& operator=(const Field &field)
	{
		cells = field.cells;
		count_of_cellships = field.count_of_cellships;
		return *this;
	}

	int Get_Count_Of_CellShips()
	{
		return count_of_cellships;
	}

	void Add_Cellships(Ship &ship)
	{
		Cell cell = ship.Get_Cell();
		int x = cell.Get_x();
		int y = cell.Get_y();
		int i;
		bool direction = ship.Get_Direction();
		for (i = 0; i < ship.Get_Size(); i++)
		{
			cells[y * 10 + x].Set_Ship_True();
			if (direction)
				y++;
			else
				x++;
		}
		count_of_cellships = count_of_cellships + i;
	}

	bool Check_Free_Cells_For_Ship(Ship &ship)
	{
		Cell cell = ship.Get_Cell();
		int x = cell.Get_x();
		int y = cell.Get_y();
		int i;
		bool direction = ship.Get_Direction();
		for (i = 0; i < ship.Get_Size(); i++)
		{
			if (!cells[y * 10 + x].Is_Ship())
			{
				if (direction)
					y++;
				else
					x++;
			}
			else return false;
		}
		return true;
	}

	vector <Cell> Get_Field()
	{
		return cells;
	}

	bool Shoot(int x, int y)
	{
		if (cells[y * 10 + x].Is_Ship())
			return true;
		else
		{
			cells[y * 10 + x].Set_Try_True();
			return false;
		}
	}

	void Set_Try(int x, int y)
	{
		cells[y * 10 + x].Set_Try_True();
	}

	void Add_Dead_Cell(int x, int y)
	{
		cells[y * 10 + x].Set_Dead_True();
		count_of_cellships--;
	}

	void Rand_Ship(int size, Field &C_Field)
	{
		bool flag = true;
		bool direction;
		int k;
		int x, y;
		do
		{
			k = rand() % (100 - 0) + 0;
			direction = k % 2;
			switch (direction)
			{
			case true:
				do
				{
					x = rand() % (9 - 0) + 0;
					y = rand() % ((10 - size) - 0) + 0;
				} while (cells[y * 10 + x].Is_Ship());
				flag = Check_Free_Cells_For_Ship(Ship(Cell(x, y), direction, size));
				if (flag)
				{
					C_Field.Add_Cellships(Ship(Cell(x, y), direction, size));
					Add_Cellships(Ship(Cell(x, y), direction, size));
					if (x > 0)
						Add_Cellships(Ship(Cell(x - 1, y), direction, size));
					if (x < 9)
						Add_Cellships(Ship(Cell(x + 1, y), direction, size));
					for (int i = 0; i < 3; i++)
					{
						if (y > 0)
							if ((x > 0) && (x < 11))
								Add_Cellships(Ship(Cell(x - 1, y - 1), !direction, 1));
						if (y < 7)
							if ((x > 0) && (x < 11))
								Add_Cellships(Ship(Cell(x - 1, y + size), !direction, 1));
						x++;
					}
				}
				break;
			case false:
				do
				{
					x = rand() % ((10 - size) - 0) + 0;
					y = rand() % (9 - 0) + 0;
				} while (cells[y * 10 + x].Is_Ship());
				flag = Check_Free_Cells_For_Ship(Ship(Cell(x, y), direction, size));
				if (flag)
				{
					Add_Cellships(Ship(Cell(x, y), direction, size));
					C_Field.Add_Cellships(Ship(Cell(x, y), direction, size));
					if (y > 0)
						Add_Cellships(Ship(Cell(x, y - 1), direction, size));
					if (y < 9)
						Add_Cellships(Ship(Cell(x, y + 1), direction, size));
					for (int i = 0; i < 3; i++)
					{
						if (x > 0)
							if ((y > 0) && (y < 11))
								Add_Cellships(Ship(Cell(x - 1, y - 1), !direction, 1));
						if (x < 7)
							if ((y > 0) && (y < 11))
								Add_Cellships(Ship(Cell(x + size, y - 1), !direction, 1));
						y++;
					}
				}
				break;
			}
		} while (!flag);
	}

	bool Check_Try_Cell(int x, int y)
	{
		if (cells[y * 10 + x].Is_Try())
			return true;
		return false;
	}

	void Show_My_Cell(int x, int y)
	{
		if (cells[y * 10 + x].Is_Ship())
		{
			if (cells[y * 10 + x].Is_Dead())
				cout << "* ";
			else
				cout << "1 ";
		}
		else
		{
			if (cells[y * 10 + x].Is_Try())
				cout << "# ";
			else
				cout << "0 ";
		}
	}

	void Show_C_Cell(int x, int y)
	{
		if ((cells[y * 10 + x].Is_Ship())&&(cells[y * 10 + x].Is_Dead()))
		{
				cout << "* ";
		}
		else
		{
			if (cells[y * 10 + x].Is_Try())
				cout << "# ";
			else
				cout << "0 ";
		}
	}
};

class Game
{
	Field My_Field;
	Field C_Field;
public:
	Game(Field _My_Field = Field(), Field _C_Field = Field()) : My_Field(_My_Field), C_Field(_C_Field) {}

	~Game() {}

	Game(const Game &game)
	{
		My_Field = game.My_Field;
		C_Field = game.C_Field;
	}

	Game& operator=(const Game &game)
	{
		My_Field = game.My_Field;
		C_Field = game.C_Field;
		return *this;
	}

	void Set_C_Field()
	{
		Field field;
		srand(time(NULL));
		field.Rand_Ship(4, C_Field);
		for (int i = 0; i < 2; i++)
		{
			field.Rand_Ship(3, C_Field);
		}
		for (int i = 0; i < 3; i++)
		{
			field.Rand_Ship(2, C_Field);
		}
		for (int i = 0; i < 4; i++)
		{
			field.Rand_Ship(1, C_Field);
		}
	}

	bool My_Shoot(int x, int y)
	{
		if (C_Field.Shoot(x, y))
		{
			C_Field.Add_Dead_Cell(x, y);
			return true;
		}
	}

	void C_Shoot()
	{
		srand(time(NULL));
		vector<Cell> cells;
		int x, y;
		bool flag = false;
		do
		{
			do
			{
				x = rand() % (9 - 0) + 0;
				y = rand() % (9 - 0) + 0;
			} while (My_Field.Check_Try_Cell(x, y));
			flag = My_Field.Shoot(x, y);
			if (flag)
			{
				My_Field.Add_Dead_Cell(x, y);
				My_Field.Set_Try(x, y);
			}
				
		} while (flag);
	}

	bool Check_End()
	{
		if ((My_Field.Get_Count_Of_CellShips()) && (C_Field.Get_Count_Of_CellShips()))
			return false;
		return true;
	}

	void Show_Fields()
	{
		cout << "    0 1 2 3 4 5 6 7 8 9                    0 1 2 3 4 5 6 7 8 9" << endl;
		cout << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << i << "   ";
			for (int j = 0; j < 10; j++)
			{
				My_Field.Show_My_Cell(j, i);
			}
			cout << "               ";
			cout << i << "   ";
			for (int j = 0; j < 10; j++)
			{
				C_Field.Show_C_Cell(j, i);
			}
			cout << endl;
		}
	}

	bool Winner()
	{
		if (C_Field.Get_Count_Of_CellShips() == 0)
			return true;
		if (My_Field.Get_Count_Of_CellShips() == 0)
			return false;
	}
};

void main()
{
	setlocale(LC_ALL, "Rus");
	Field My_Field = Field();
	int x, y;
	bool direction;
	cout << "Введите координаты начальной точки и направление четырёхпалубного корабля (1 - вертикальное, 0 -горизонтальное)" << endl;
	cin >> x;
	cin >> y;
	cin >> direction;
	My_Field.Add_Cellships(Ship(Cell(x, y), direction, 4));
	for (int i = 0; i < 2; i++)
	{
		cout << "Введите координаты начальной точки и направление трёхпалубного корабля (1 - вертикальное, 0 -горизонтальное)" << endl;
		cin >> x;
		cin >> y;
		cin >> direction;
		My_Field.Add_Cellships(Ship(Cell(x, y), direction, 3));
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "Введите координаты начальной точки и направление двухпалубного корабля (1 - вертикальное, 0 -горизонтальное)" << endl;
		cin >> x;
		cin >> y;
		cin >> direction;
		My_Field.Add_Cellships(Ship(Cell(x, y), direction, 2));
	}
	for (int i = 0; i < 4; i++)
	{
		cout << "Введите координаты однопалубного корабля" << endl;
		cin >> x;
		cin >> y;
		My_Field.Add_Cellships(Ship(Cell(x, y), true, 1));
	}
	Field C_Field;
	Game game = Game(My_Field, C_Field);
	game.Set_C_Field();
	bool flag;
	do
	{
		flag = false;
		do
		{
			system("cls");
			game.Show_Fields();
			cout << endl;
			cout << "Введите кординаты выстрела " << endl;
			cin >> x;
			cin >> y;
			flag = game.My_Shoot(x, y);
			if (flag)
				flag = !game.Check_End();
			system("cls");
			game.Show_Fields();
			cout << endl;
		} while (flag);
		if (!game.Check_End())
			game.C_Shoot();
		cout << endl;
	} while (!game.Check_End());
	if (game.Winner())
		cout << "Вы победили!" << endl;
	else cout << "Вы проиграли :(" << endl;
	system("pause");
}