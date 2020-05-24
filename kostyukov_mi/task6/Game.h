#include <iostream>
#include <vector>

#ifdef __linux
    #include "LinuxConsole.h"
#else
    #include "WindowsConsole.h"
#endif

typedef unsigned int uint;

class Boat
{
public:
    unsigned int x,y;
    size_t size;
    size_t left;
    bool horizontal;

    Boat(size_t _size)
    {
        x = 0;
        y = 0;
        size = _size;
        left = _size;
        horizontal = true;
    }
    Boat(unsigned int _x, unsigned int _y, size_t _size, bool _horizontal)
    {
        x = _x;
        y = _y;
        size = _size;
        left = _size;
        horizontal = _horizontal;
    }
    size_t _size()
    {
        return size;
    }
    bool hit()
    {
        left--;
        return (left == 0);
    }

    friend class BattleMap;
};

class BattleMap
{
public:
//private:
    bool hidden;
    uint x0, y0;
    std::vector<Boat> boats;
    int map[100] = {0};
//public:
    BattleMap(uint _x=0,uint _y=0,  bool _hidden = false, std::vector<Boat> _boats={})
    {
        x0 = _x;
        y0 = _y;
        boats = _boats;
        hidden = _hidden;
        for (int i=0; i<boats.size(); i++)
        {
            for (int j=0; j<boats[i]._size(); j++)
                map[boats[i].y*10 + boats[i].x + j] = i+1;
        }
    }
    int el(uint x, uint y)
    {
        return map[y*10+x];
    }
    std::string cell(uint x, uint y)
    {
        if (map[y*10 + x] > 0) return "[]";
        if (map[y*10 + x] == 0) return "  ";
        if (map[y*10 + x] == -1) return " *";
        if (map[y*10 + x] == -2) return " X";
    }
    
    char hit(uint x, uint y)
    {
        uint i = map[y*10+x];
        if (i == -2)
        {
            return -2;
        }
        if (i == -1)
        {
            return -1;
        }
        if (i == 0)
        {
            map[y*10+x] = -1;
            return 0;
        }
        if (i > 0)
        {
            // * в клетку;
            map[y*10+x] = -2;

            Boat& boat = boats[i-1];

            if (boat.hit())
            {
                // выделить корабль
                if (boat.horizontal)
                {
                    for (int i=0;i<boat.size+2; i++)
                    {
                        if ((boat.x == 0) && (i == 0)) i++;
                        if (boat.x+i == 11) break; 
                        if (boat.y>0) map[(boat.y-1)*10+boat.x+i-1] = -1;
                        if (boat.y<9) map[(boat.y+1)*10+boat.x+i-1] = -1;
                    }
                    if (boat.x > 0)              map[(boat.y)*10 + boat.x-1] = -1;
                    if (boat.x + boat.size < 10) map[(boat.y)*10 + boat.x+boat.size] = -1;
                }
                else
                {
                    for (int i=0;i<boat.size+2; i++)
                    {
                        if ((boat.y == 0) && (i == 0)) i++;
                        if (boat.y+i == 11) break;
                        if (boat.x>0) map[(boat.y+i-1)*10+boat.x-1] = -1;
                        if (boat.x<9) map[(boat.y+i-1)*10+boat.x+1] = -1;
                    }
                    if (boat.y > 0)              map[(boat.y-1)*10 + boat.x] = -1;
                    if (boat.y + boat.size < 10) map[(boat.y+boat.size)*10 + boat.x] = -1;
                }
                return 2;
            }
            return 1;
        }
    } 
    void draw()
    {
        for (int i=0; i<10; i++)
        {
            gotoxy(x0+i*3+3, y0); std::cout<<(char)(i+97);
            gotoxy(x0, y0+i*2+2); std::cout<<i+1;
        }
        for (int i=0; i<10; i++)
        {
            for (int j=0; j<10; j++)
            {
                gotoxy(x0+i*3+2,y0+j*2+1);
                std::cout << "+--";
                gotoxy(x0+i*3+2, y0+j*2+2);
                std::cout << "|";
                if ((map[j*10 + i] > 0) && (!hidden)) std::cout<<"[]";
                if (map[j*10 + i] == 0) std::cout << "  ";
                if (map[j*10 + i] == -1) std::cout << " *";
                if (map[j*10 + i] == -2) std::cout << " X";
            }
        }
        for (int i=0; i<10; i++)
        {
            gotoxy(x0+i*3+2,y0+21); std::cout<<"+--";
            gotoxy(x0+32, y0+i*2+1); std::cout<<"+";
            gotoxy(x0+32, y0+i*2+2); std::cout<<"|";
        }
        gotoxy(x0+32,y0+21); std::cout<<"+"<<"\n";
    }
};



void selectCell(uint x0, uint y0)
{
    char c;
    int x=0,y=0;
    gotoxy(x0+x*3+3,y0+y*2+2);
    std::cout<<"x";
    while (true)
    {
        c = getKey();
        gotoxy(x0+x*3+3,y0+y*2+2);
        std::cout<<" ";
        switch (c)
        {
        case KB_ARROWLEFT:
            if (x > 0) x--;
            break;
        case KB_ARROWRIGHT:
            if (x < 9) x++;
            break;
        case KB_ARROWUP:
            if (y > 0) y--;
            break;
        case KB_ARROWDOWN:
            if (y < 9) y++;
            break;
        default:
            break;
        }
        gotoxy(x0+x*3+3,y0+y*2+2);
        std::cout<<"x";
    }
}