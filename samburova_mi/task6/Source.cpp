#include "BullsCows.h"

int main()
{
	int n;
	int k;
	cout << "Enter your number" << endl;
	cin >> n;
	Game game(n);
	k = game.run();
	cout << "You managed in " << k << " moves!" << endl;
	system("pause");
}

