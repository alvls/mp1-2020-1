#include "Game.h"

class Player
{
protected:
    std::string nickname;
    std::pair<uint, uint> lastMove;
    BattleMap battlemap;
    uint score=0;
public:
    Player(std::string _nickname, BattleMap _battlemap)
    {
        nickname = _nickname;
        battlemap = _battlemap;
    }
    std::pair<uint, uint> move()
    {
        gotoxy(0,25);
        char x; int y;
        do
        {
            std::cout<<"              ";
            gotoxy(0,25);
            std::cin>>x>>y;
        }
        while ((x < 97) || (x > 106) || (y < 1) || (y > 10));
        return std::pair<int,int>(x-97,y-1);
    }
    std::string getNickname()
    {
        return nickname;
    }
    bool boatKilled()
    {
        score++;
        return (score == 10);
    }
    char getEnemyMove(uint x, uint y)
    {
        return battlemap.hit(x,y);
    }
    BattleMap getBattlemap()
    {
        return battlemap;
    }
    void placeBoat(Boat boat)
    {
        char c;
        bool bad = false;
        bool vert = false;
        uint x0 = battlemap.x0;
        uint y0 = battlemap.y0;
        uint x=0,y=0;

        battlemap.draw();

        while (true)
        {
            for(size_t i=0; i<boat.size;i++)
            {
                gotoxy(x0+x*3+3+i*3*vert, y0+y*2+2+i*2*(!vert));
                std::cout<<"[]";
            }
            c = getKey();

            for(size_t i=0; i<boat.size;i++)
            {
                gotoxy(x0+x*3+3+i*3*vert, y0+y*2+2+i*2*(!vert));
                std::cout<<battlemap.cell(x+i*vert, y+i*(!vert));
            }

            switch (c)
            {
            case KB_ARROWLEFT:
                if (x > 0) x--;
                break;
            case KB_ARROWRIGHT:
                if (x < 9-(boat.size-1)*vert) x++;
                break;
            case KB_ARROWUP:
                if (y > 0) y--;
                break;
            case KB_ARROWDOWN:
                if (y < 9-(boat.size-1)*(!vert)) y++;
                break;
            case KB_ENTER:

                bad = false;

                if (vert)
                {
                    for (int i=0;i<boat.size+2; i++)
                    {
                        if ((x == 0) && (i == 0)) i++;
                        if (x+i == 11) break;
                        if ((y>0) && (battlemap.map[(y-1)*10+x+i-1] > 0)) {bad = 1; break;}
                        if (battlemap.map[y*10+x+i-1] > 0)                {bad = 1; break;}
                        if ((y<9) && (battlemap.map[(y+1)*10+x+i-1] > 0)) {bad = 1; break;}
                    }
                } 
                else
                {
                    for (int i=0;i<boat.size+2; i++)
                    {
                        if ((y == 0) && (i == 0)) i++;
                        if (y+i == 11) break;
                        if ((x>0) &&(battlemap.map[(y+i-1)*10+x-1] > 0)) {bad = 1; break;}
                        if (battlemap.map[(y+i-1)*10+x] > 0)             {bad = 1; break;}
                        if ((x<9) &&(battlemap.map[(y+i-1)*10+x+1] > 0)) {bad = 1; break;}

                    }
                }

                if (bad) continue;

                boat.x = x;
                boat.y = y;
                boat.horizontal = vert;
                battlemap.boats.push_back(boat);
                if(vert)
                {
                    for(int i=0; i<boat.size; i++)
                    {
                        battlemap.map[y*10+x+i] = battlemap.boats.size();
                    }
                }
                else
                {
                    for(int i=0; i<boat.size; i++)
                    {
                        battlemap.map[(y+i)*10+x] = battlemap.boats.size();
                    }
                }
                battlemap.draw();
                return;

            default:
                if (vert)
                {
                    if (y >= 10-boat.size)
                    {
                        y = 10-boat.size;
                    }
                }       
                else
                {
                    if (x >= 10-boat.size)
                    {
                        x = 10-boat.size;
                    }
                }
                vert = !vert;
                break;
            }
        }
    }
    void placeBoats()
    {
        for (int i=0; i<4; i++)
            placeBoat(Boat(1));
        for (int i=0; i<3; i++)
            placeBoat(Boat(2));
        for (int i=0; i<2; i++)
            placeBoat(Boat(3));
        placeBoat(Boat(4));
    }
};

class BotEnemy:public Player
{
public: 
    BotEnemy(std::string _nickname, BattleMap _battlemap):Player(_nickname, _battlemap)
    {

    }
    std::pair<uint, uint> move()
    {
        int x = rand() % 10;
        int y = rand() % 10;
        return std::pair<int,int>(x,y);
    }
    void placeBoat(Boat boat)
    {
        uint x,y;
        bool vert;
        bool bad = true;
        while (bad)
        {
            vert = rand()%2;
            if (vert)
            {
                x = rand()%(10-boat.size);
                y = rand()%10;
            }
            else
            {
                x = rand()%10;
                y = rand()%(10-boat.size);
            }

            bad = false;

            if (vert)
            {
                for (int i=0;i<boat.size+2; i++)
                {
                    if ((x == 0) && (i == 0)) i++;
                    if (x+i == 11) break;
                    if ((y>0) && (battlemap.map[(y-1)*10+x+i-1] > 0)) {bad = 1; break;}
                    if (battlemap.map[y*10+x+i-1] > 0)                {bad = 1; break;}
                    if ((y<9) && (battlemap.map[(y+1)*10+x+i-1] > 0)) {bad = 1; break;}
                }
            } 
            else
            {
                for (int i=0;i<boat.size+2; i++)
                {
                    if ((y == 0) && (i == 0)) i++;
                    if (y+i == 11) break;
                    if ((x>0) &&(battlemap.map[(y+i-1)*10+x-1] > 0)) {bad = 1; break;}
                    if (battlemap.map[(y+i-1)*10+x] > 0)             {bad = 1; break;}
                    if ((x<9) &&(battlemap.map[(y+i-1)*10+x+1] > 0)) {bad = 1; break;}

                }
            }
        }
        boat.x = x;
        boat.y = y;
        boat.horizontal = vert;
        battlemap.boats.push_back(boat);
        if(vert)
        {
            for(int i=0; i<boat.size; i++)
            {
                battlemap.map[y*10+x+i] = battlemap.boats.size();
            }
        }
        else
        {
            for(int i=0; i<boat.size; i++)
            {
                battlemap.map[(y+i)*10+x] = battlemap.boats.size();
            }
        }
    }
    void placeBoats()
    {
        for (int i=0; i<4;i++)
        {
            placeBoat(Boat(1));
        }
        for (int i=0; i<3;i++)
        {
            placeBoat(Boat(2));
        }
        for (int i=0; i<2;i++)
        {
            placeBoat(Boat(3));
        }
        placeBoat(Boat(4));
        battlemap.draw();
    }

};

class NetworkEnemy:public Player
{
public:
    std::string nickname;
    bool server = true;
    int sockfd;
    std::vector<int> connections;
private:
    NetworkEnemy(std::string _nickname, BattleMap& _battlemap):Player(_nickname, _battlemap)
    {
        //сервер

        //создать сокет
        //ждать подключения
        //сохранить сокет
    }
    NetworkEnemy(std::string _nickname, BattleMap& _battlemap, std::string adress):Player(_nickname, _battlemap)
    {
        //клиент

        //подключение по адресу
    }
    std::pair<int, int> move()
    {
        int x,y;
        return std::pair<int, int>(x,y);
    }
    void getEnemyMove(int x, int y)
    {
        //передача хода
    }
};