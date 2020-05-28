#pragma once
#include"element.h"
 class snake
{
private:
	element* mem;
	int size;
	int count;
public:
	snake(int i_ = 0, int j_ = 0, int size_ = 100, int count_ = 5)
	{
		count = count_;
		size = size_;
		mem = new element[size];
		    mem[0].seti(i_);
		    mem[0].setj(j_++);
			mem[1].seti(i_++);
			mem[1].setj(j_ );
			mem[2].seti(i_++);
			mem[2].setj(j_);
			mem[3].seti(i_);
			mem[3].setj(j_++);
			mem[4].seti(i_);
			mem[4].setj(j_);
		if (count == 1)
		{
			mem[0].setpriznak(4);
		}
		else
			if (count > 1)
			{
				mem[0].setpriznak(1);
				mem[count - 1].setpriznak(3);//1)
			}
	};
	snake(const snake& tmp)
	{
		count = tmp.count;
		size = tmp.size;
		mem = new element[size];
		for (int i = 0; i < count; i++)
		{
			mem[i] = tmp.mem[i];
		}
	};
	~snake() { delete[]mem; }
	snake& operator=(const snake& tmp)
	{
		count = tmp.count;
		size = tmp.size;
		mem = new element[size];
		for (int i = 0; i < count; i++)
		{
			mem[i] = tmp.mem[i];
		}
		return *this;
	}
	void show_snake(System::Windows::Forms::DataGridView^ tmp )
	{
		
		for (int i = 1; i < count; i++)
		{
			//dataGridView1.Rows[i].Cells[0].Style.BackColor = System.Drawing.Color.Gray;
			tmp->Rows[mem[i].geti()]->Cells[mem[i].getj()]->Style->BackColor = Color::Yellow;
		}
		tmp->Rows[mem[0].geti()]->Cells[mem[0].getj()]->Style->BackColor = Color::Orange;
	}
	int move(char s)//U - up, D - down, L - left,R - right;G - сдвиг и увеличение
	{
		for (int i = count - 1; i > 0; i--)
		{
			mem[i] = mem[i - 1];
		}
		if (mem[0].getpriznak() != 3)
		{
			mem[1].setpriznak(2);
		};
		if (count > 1)
		{
			mem[count - 1].setpriznak(3);
		}
		if (s == 'U') { mem[0].seti(mem[0].geti() - 1); }
		if (s == 'D') { mem[0].seti(mem[0].geti() + 1); }
		if (s == 'L') { mem[0].setj(mem[0].getj() - 1); }
		if (s == 'R') { mem[0].setj(mem[0].getj() + 1); }
		if (count > 1)
		{
			for (int i = 1; i < count; i++)
			{
				if (mem[0] == mem[i])
					return 0;//error 
			}
			return 1;//game remember
		}
		else
			return 1;//game remember		
	}
	void add(char s)
	{
		count++;
		move(s);
	}
	int getcount()
	{
		return count;
	}
	int getlastx()
	{
		if (count > 0)
		{
			return mem[count - 1].getj();
		}
		else
		{
			return -1;
		}
	}
	int getlasty()
	{
		if (count > 0)
		{
			return mem[count - 1].geti();
		}
		else
		{
			return -1;
		}
	}
	int getheadx()
	{
		if (count > 0)
		{
			return mem[0].getj();
		}
		else
		{
			return -1;
		}
	}
	int getheady()
	{
		if (count > 0)
		{
			return mem[0].geti();
		}
		else
		{
			return -1;
		}
	}
};

