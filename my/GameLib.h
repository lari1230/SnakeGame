#pragma once
#include <iostream> 
#include <vector> 
#include <windows.h> 
#include <math.h> 
#include <algorithm> 
#include <time.h> 
#include <string> 
#include <conio.h>


/*int widht = 20, lenght = 20;

int fruitX = rand() % widht, fruitY = rand() % lenght;
int TailX[20], TailY[20];
int score = 0;
char a;
char snake[100];*/

void player();
using namespace std;
enum dir {start,UP,DOWN, RIGHT,LEFT };
dir direction = start;
bool gameOver = false;

int wight = 20, lenght = 20;
int x = wight / 2, y = lenght / 2;

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

void draw()
{
    SetConsoleTextAttribute(hand, LightYellow);
    vector<vector<char>> world;

    for (size_t i = 0; i < wight; i++)
    {
        vector<char> vec;
        for (size_t j = 0; j < lenght; j++)
        {
            if (i == 0 || i == wight -1 || j == 0 || j == lenght -1)
            {
                vec.push_back(254);
            }
            else
            {
                vec.push_back(' ');
            }
            
        }
        world.push_back(vec);
    }
    for (size_t i = 0; i < world.size(); i++)
    {
        for (size_t j = 0; j < world[i].size(); j++)
        {
            if (x == 0 || x == wight - 1 || y == 0 || y == lenght - 1)
            {
                cout << "YOU LOSE!";

                exit(0);
            }
            
            if (i == y && j == x)
            {
                SetConsoleTextAttribute(hand, Red);
                cout << '#';
                SetConsoleTextAttribute(hand, LightYellow);



            }
        
            else
            {
                cout << world[i][j];
            }
            
        }

        
        cout << endl;

        
    }
    Sleep(200);
}


void player()
{   
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            direction = UP;
            break;
        case 's':
            direction = DOWN;
            break;
        case 'd':
            direction = RIGHT;
            break;
        case 'a':
            direction = LEFT;
            break;
        case 'x':
            gameOver = true;
        default:
            break;
        }
    }
}
void control()
{   
    switch (direction)
    {
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    case RIGHT:
        x++;
        break;
    case LEFT:
        x--;
        break;
    default:
        break;
    }
}