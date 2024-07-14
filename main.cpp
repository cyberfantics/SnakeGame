#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <conio.h>
using namespace std;

bool gameOver;
const int width = 30;
const int height = 20;
int x , y, fruitX , fruitY , score;
int tailX[100], tailY[100];
int nTail;
enum eDirection {STOP, LEFT , RIGHT ,UP ,DOWN};
eDirection dir;

void Setup(){
	gameOver = false;
	dir = STOP;
	x = width/2;
	y = height/2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Draw(){
	system ("cls");
	for(int i = 0; i < width+2; i++)
	cout<<"#";
	cout<<endl;

	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			if(j==0)
			cout<<"#";
			if(i==y && j==x)
			cout<<"O";
			else if(i==fruitY && j==fruitX)
			cout<<"*";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
				if (tailX[k]==j && tailY[k] ==i)
				{
					cout<<"o";
					print = true;
				} 
			}
							if (!print)
				cout<<" "; 
		}

			if(j==width-1)
			cout<<"#";
		}
		cout<<endl;
	}

	for(int i = 0; i < width+2; i++)
	cout<<"#";
	cout<<endl;
	cout<<"Your Score Are "<<score;
}

void Input(){
	if (_kbhit())
	{
		switch(_getch())
		{
			case 'a':
			dir = LEFT;
			break;
			
			case 'l':
			dir = RIGHT;
			break;

			case 'b':
			dir = DOWN;
			break;

			case 'y':
			dir = UP;
			break;

			case 'x':
			gameOver = true;
			break;
		}
	}
}

void Logic(){
	int privewX = tailX[0];
	int privewY = tailY[0];
	int prive2X , prive2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i=1; i < nTail; i++)
		{
			prive2X = tailX[i];
			prive2Y = tailY[i];
			tailX[i] = privewX;
			tailY[i] = privewY;
			privewX = prive2X ;
			privewY = prive2Y;
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
	}
	if(x > width || x < 0 || y > height || y < 0 )
		gameOver = true;
		for(int i = 0 ; i < nTail; i++)
		if(tailX[i] == x && tailY[i] == y)
		gameOver=true;
		if(x==fruitX && y==fruitY)
		{
		score +=10;
		 fruitX = rand() % width;
		 fruitY = rand() % height;
		 nTail++;
		}
}


int main(){
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		sleep(1);
	}
	return 0;
}