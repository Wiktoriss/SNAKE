#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <sstream>
#include "snake.h"

using namespace std;

int main()
{
	snake snake;
	while (!snake.koniecgry())
	{
		system("cls");
		cout << snake.draw();
		cout << snake.returnscore();
		snake.input();
		snake.alg();
		Sleep(100);
	}
	snake.gameover();
}