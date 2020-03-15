#include <iostream>
#include "Menu.h"
using namespace std;

int main()
{
    Menu m({MenuCommand("123"), MenuCommand("2345"), MenuCommand("3456789")});
    m.MenuLoop(7, 5);
    cout << std::endl;
}