#pragma once
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class snake
{
	enum kierunek { STOP = 0, UP, DOWN, LEFT, RIGHT };
	kierunek dir, dir1;
	int width = 25;
	int height = 25;
	int x, y, OwocX, OwocY, score;
	bool gameOver;
	int tailX[100], tailY[100];
	int nTail = 0;
	string mapa;
public:
	snake();
	string draw();
	void input();
	void alg();
	bool koniecgry();
	int returnscore();
	void gameover();
};