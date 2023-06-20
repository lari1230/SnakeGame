#include "GameLib.h"

void main()
{
	srand(time(NULL));
	while (true)
	{
		player();
		checkControl();
		control();
		draw();
		tail();
		fruit();
		file();
		system("cls");
	}
	cout << "YOU LOSE!" << endl;
}
