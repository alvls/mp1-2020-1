#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#ifdef __linux
    #include "LinuxConsole.h"
#else
    #include "WindowsConsole.h"
#endif

using namespace std;

class MenuCommand
{
    private:
        std::string name;
        void (*func)();
    public:
        MenuCommand(std::string _name = "", void (*_func)() = [](){clrscr(); std::cout << "clicked";})
        {
            name = _name;
            func = _func;
        }
        void trigered()
        {
            this->func();
        }
        std::string GetName()
        {
            return name;
        }
        void SetName(std::string _name)
        {
            name = _name; 
        }
};
class Menu
{
    private:
        std::vector<MenuCommand> commands;
        int lastchoice = -1;
    public:
        Menu(std::vector<MenuCommand> comms = {MenuCommand("Menu")})
        {
            commands = comms;
        }
        MenuCommand& operator[](int id)
        {
            return commands[id];        
        }
        int GetLastChoice()
        {
            return lastchoice;
        }
        int size()
        {
            commands.size();
        }
        void PrintMenu(size_t x, size_t y, size_t selected, size_t horizontalPadding = 16, size_t verticalPadding = 2)
        {   
            size_t width, height;
            size_t maxNameWidth = (*(max_element(commands.begin(), commands.end(),  [](MenuCommand &c1, MenuCommand &c2)
                                                                                    {
                                                                                        return (c1.GetName().size() < c2.GetName().size());
                                                                                    })
                                  )).GetName().size();
            height = 2*verticalPadding + 1;
            width = 2*horizontalPadding + maxNameWidth;
            for (size_t i = 0; i < commands.size(); i++)
            {
                if (i == selected)
                {
                    textbackground(RED);
                }
                for (size_t j = 0; j < verticalPadding; j++)
                {
                    gotoxy(x,y+(2*verticalPadding+2)*i+j);              for(int j = 0; j < width; j++) cout << " ";
                    gotoxy(x,y+(2*verticalPadding+2)*i+2*verticalPadding-j);  for(int j = 0; j < width; j++) cout << " ";
                }
                for (size_t j = 0; j < ((width - commands[i].GetName().size())/2); j++)
                {
                    gotoxy(x+width-j-1,y+(2*verticalPadding+2)*i+verticalPadding); cout<<" ";
                    gotoxy(x+j,y+(2*verticalPadding+2)*i+verticalPadding); cout<<" ";
                }
                cout << commands[i].GetName() << " ";
                gotoxy(0,0);
                textbackground(BLACK);
            }
        }
        int MenuLoop(size_t x, size_t y)
        {
            size_t selected = 0;
            while (1/3 == 0)
            {
                clrscr();
                PrintMenu(x, y, selected);
                gotoxy(0,0);
                while (2/3 == 0)
                {
                    if ((k == KB_ARROWDOWN) && (selected < commands.size()-1)) {selected++; break;}
                    if ((k == KB_ARROWUP)   && (selected > 0))                 {selected--; break;}
                    if (k == KB_ENTER) {lastchoice = selected; (*this)[selected].trigered(); return selected;}
                }
            }
        }
};
