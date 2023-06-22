#include <iostream> 
#include <vector> 
#include <windows.h> 
#include <math.h> 
#include <algorithm> 
#include <time.h> 
#include <string> 
#include <conio.h>
#include <fstream>

using namespace std;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score, bScore;
int checkY, checkYY, checkX, checkXX;
int tailx[100], taily[100];
int nTail;
enum eDirecton { STOP, LEFT, RIGHT, UP, DOWN } dir;
char a = 254;
HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);

enum Color {
    Black = 0,
    NavyBlue = 1,
    Green = 2,
    LightBlue = 3,
    Red = 4,
    Purple = 5,
    Yellow = 6,
    LightGray = 7,
    Gray = 8,
    Blue = 9,
    LightGreen = 10,
    VeryLightBlue = 11,
    LightRed = 12,
    LightPurple = 13,
    LightYellow = 14,
    White = 15,
};
void GameOver()
{
    SetConsoleTextAttribute(hand, Red);
    cout << "You Lose!\n" << endl;
    cout << "Your Score: " << score << endl;
    exit(0);
}
void File()
{
    ifstream in;
    in.open("bestscore.bs");
    
    if (in.is_open())
    {
        string str;
        
        getline(in, str);
        int temp = stoi(str);
        if (score > temp)
        {
            bScore = temp;
            in.close();
            ofstream on;
            on.open("bestscore.bs");
            on << score;
            on.close();
            ifstream in;
            in.open("bestscore.bs");
        }
        bScore = temp;
        in.close();
    }

}

void Setup()
{
    cout << "  _________              __              ________" << endl;
    cout << " /   _____/ ____ _____  |  | __ ____    /  _____/_____    _____   ____" << endl;
    cout << " \\_____  \\ /    \\\\__  \\ |  |/ // __ \\  /   \\  ___\\__  \\  /     \\_/ __ \\" << endl;
    cout << " /        \\   |  \\/ __ \\|    <\\  ___/  \\    \\_\\  \\/ __ \\|  Y Y  \\\\  __/" << endl;
    cout << "/_______  /___|  (____  /__|_ \\\\___  >  \\______  (____  /__|_|  /\\\\___ >" << endl;
    cout << "        \\/     \\/     \\/     \\/    \\/          \\/     \\/      \\/     \\/" << endl;
    cout << "\n                                  LOADING..." << endl;
    Sleep(5000);

    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void Draw()
{
    system("cls");
    for (int i = 0; i < width + 2; i++) {
        cout << a;
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0) {
                SetConsoleTextAttribute(hand, LightYellow);
                cout << a;
            }
            if (i == y && j == x) {
                SetConsoleTextAttribute(hand, Green);
                cout << "O";
                SetConsoleTextAttribute(hand, LightYellow);
            }
            else if (i == fruitY && j == fruitX) {
                SetConsoleTextAttribute(hand, Purple);
                cout << "F";
                SetConsoleTextAttribute(hand, LightYellow);
            }
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailx[k] == j && taily[k] == i)
                    {
                        SetConsoleTextAttribute(hand, Green);
                        cout << "o";
                        SetConsoleTextAttribute(hand, LightYellow);
                        print = true;
                    }
                }
                if (!print) {
                    cout << " ";
                }
            }

            if (j == width - 1) {
                cout << a;
            }
        }
        cout << endl;
    }
    for (int i = 0; i < width + 2; i++) {
        cout << (char)254;
    }
    cout << endl;
    cout << "The Best Score: " << bScore << endl;
    cout << "Score: " << score << endl;
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            checkXX = 1;

            checkY = 0;
            checkYY = 0;
            break;
        case 'd':
            dir = RIGHT;
            checkX = 2;
 
            checkY = 0;
            checkYY = 0;
            break;
        case 'w':
            dir = UP;
            checkY = 2;
               
            checkX = 0;
            checkXX = 0;
            break;
        case 's':
            dir = DOWN;
            checkYY = 1;

            checkX = 0;
            checkXX = 0;
            break;
        case 'x':
            GameOver();
            break;
        }
    }
}
void Logic()
{
    for (int i = nTail - 1; i > 0; i--)
    {
        tailx[i] = tailx[i - 1];
        taily[i] = taily[i - 1];
    }
    tailx[0] = x;
    taily[0] = y;

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    for (int i = 0; i < nTail; i++) {
        if (tailx[i] == x && taily[i] == y) {
            GameOver();
        }
    }
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }

    if (dir == DOWN && checkY == 2)
    {
        GameOver();
    }
    else if (dir == UP && checkYY == 1)
    {
        GameOver();
    }
    else if (dir == LEFT && checkX == 2)
    {
        GameOver();
    }
    else if (dir == RIGHT && checkXX == 1)
    {
        GameOver();
   }

}
void main()
{
    Setup();
    while (true)
    {
        Draw();
        Input();
        Logic();
        File();
        Sleep(50);
    }
}