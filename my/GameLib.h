#pragma once
#include <iostream> 
#include <vector> 
#include <windows.h> 
#include <math.h> 
#include <algorithm> 
#include <time.h> 
#include <string> 
#include <conio.h>
#include <fstream>


/*int widht = 20, lenght = 20;


int TailX[20], TailY[20];
int score = 0;
char a;
char snake[100];*/

using namespace std;
enum dir {start,UP,DOWN, RIGHT,LEFT };
dir direction = start;

int checkX, checkXX, checkY, checkYY;

int score = 0;
int bScore;


int wight = 25, lenght = 25;
int x = wight / 2, y = lenght / 2;
int fruitX = rand() % wight, fruitY = rand() % lenght;
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

void gameOver()
{
    SetConsoleTextAttribute(hand, Red);
    cout << "You Lose!\n" << endl;
    cout << "Your Score: " << score << endl;
    exit(0);
}
void draw()
{
    SetConsoleTextAttribute(hand, LightYellow);
    vector<vector<char>> world;

    for (size_t x = 0; x < wight; x++)
    {
        vector<char> vec;
        for (size_t y = 0; y < lenght; y++)
        {
            if (x == 0 || x == wight -1 || y == 0 || y == lenght -1)
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
                gameOver();

            }
            else if (i == y && j == x)
            {
                SetConsoleTextAttribute(hand, Red);
                cout << '#';
                SetConsoleTextAttribute(hand, LightYellow);
            }
            else if (i == fruitY && j == fruitX)
            {
                SetConsoleTextAttribute(hand, Red);
                cout << '&';
                SetConsoleTextAttribute(hand, LightYellow);
            }
            else
            {
                cout << world[i][j];
            }
        }
        cout << endl;   
    }
    cout << "The Best Score: " << bScore << endl;
    cout << "Score: " << score;
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
            checkY = 2;

            checkX = 0;
            checkXX = 0;
            break;
        case 's':
            direction = DOWN;
            checkYY = 1;

            checkX = 0;
            checkXX = 0;
            break;
        case 'd':
            direction = RIGHT;
            checkX = 2;

            checkY = 0;
            checkYY = 0;
            break;
        case 'a':
            direction = LEFT;
            checkXX = 1;

            checkY = 0;
            checkYY = 0;
            break;
        case 'x':
            gameOver();
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

void checkControl()
{
    if (direction == DOWN && checkY == 2)
    {
        gameOver();
    }
    else if (direction == UP && checkYY == 1)
    {
        gameOver();
    }
    else if (direction == LEFT && checkX == 2)
    {
        gameOver();
    }
    else if (direction == RIGHT && checkXX == 1)
    {
        gameOver();
    }
}

void fruit() {

    if (fruitX == x && fruitY == y)
    {
        score += 10;
        fruitX = rand() % (wight-2) +1;
        fruitY = rand() % (lenght-2) +1;
    }

}

void file()
{
    ifstream in;
    in.open("BestScore.bs");
    
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
            on.open("BestScore.bs");
            on << score;
            on.close();
            ifstream in;
            in.open("BestScore.bs");
        }
        bScore = temp;
        in.close();
    }

}
