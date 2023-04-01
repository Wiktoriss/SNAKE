#include "snake.h"

snake::snake()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	OwocX = rand() % width;
	OwocY = rand() % height;
	score = 0;
}
string snake::draw()
{
	mapa = "";
	mapa += '+';
	for (int i = 0; i < width; i++)
		mapa += "- ";
	mapa += "+";
	mapa += "\n";
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				mapa += "|";
			if (i == y && j == x)
				mapa += "O ";
			else if (i == OwocY && j == OwocX)
				mapa += "F ";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (j == tailX[k] && i == tailY[k])
					{
						mapa += "o ";
						print = true;
					}
				}
				if (!print)
					mapa += "  ";
			}


			if (j == width - 1)
				mapa += "|";
		}
		mapa += "\n";
	}
	mapa += '+';
	for (int i = 0; i < width; i++)
	{
		mapa += "- ";
	}
	mapa += '+';
	mapa += "\n";
	mapa += "Wynik: ";
	return mapa;
}
void snake::input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 75: case 'a': case 'A':
			if (dir != RIGHT)
			{
				dir = LEFT;
			}
			break;
		case 77: case 'd': case 'D':
			if (dir != LEFT)
			{
				dir = RIGHT;
			}
			break;
		case 72: case 'w': case 'W':
			if (dir != DOWN)
			{
				dir = UP;
			}
			break;
		case 80: case 's': case 'S':
			if (dir != UP)
			{
				dir = DOWN;
			}
			break;
			//case 'p':
			//	dir = STOP;
			//	break;
		case 27:
			gameOver = true;
			break;
		}
	}
}
void snake::alg()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;

	}

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
	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
	}
	if (x == -1 || y == -1 || x == width || y == height)
	{
		gameOver = true;
	}
	if (x == OwocX && y == OwocY)
	{
		OwocX = rand() % width;
		OwocY = rand() % height;
		score += 5;
		nTail++;
	}
	if (x < 0) x = width - 1; if (x >= width) x = 0;
	else if (y < 0) y = height - 1; if (y >= height) y = 0;
}

bool snake::koniecgry()
{
	return gameOver;
}

int snake::returnscore()
{
	return score;
}

void snake::gameover()
{
	system("cls");
	if (gameOver == true)
	{
		cout << "GAME OVER" << endl;
		cout << "WYNIK:" << returnscore() << " pkt" << endl;
	}
}