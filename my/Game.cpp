#include "GameLib.h"

void main()
{
	srand(time(NULL));
	while (!gameOver)
	{
		player();
		checkControl();
		control();
		draw();
		fruit();
		system("cls");
	}	
}
