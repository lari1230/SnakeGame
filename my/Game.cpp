#include "GameLib.h"

void main()
{
	while (!gameOver)
	{
		
		player();
		control();
		
		draw();
		
		system("cls");
	}
	
}
