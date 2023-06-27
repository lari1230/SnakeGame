#include "Main.h"

void main()
{
    Setup();
    while (true)
    {
        Draw();
        Input();
        Logic();
        File();
        Sleep(sleep);
    }
}
