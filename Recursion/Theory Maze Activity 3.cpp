#include <iostream>
#include <Windows.h>
#include <unistd.h>
using namespace std;
int Rat[10][10];
int MazeSolve = 0;
int Check(int i, int j, int n)
{
	if(i == n - 1 && j == n -1)
	return 1;
	else
	return 0;
}
int Maze(int Array[][10], int Flag[][10],int i,int j, int n);
void Display(int Flag[][10])
{
	for(int a = 0; a < 10; a++)
		{
			for(int b = 0; b < 10; b++)
			{
				cout << Flag[a][b];
			}
			cout << endl;
		}
}
void RatDisplay(int Rat[10][10])
{
	for(int a = 0; a < 10; a++)
	{
		for(int b = 0; b < 10; b++)
		{
			cout << Rat[a][b];
		}
		cout << endl;
	}
	usleep(100000);
	system("CLS");
}
int Maze(int Array[][10],int Flag[][10], int i, int j, int n)
{
	RatDisplay(Rat);
	if(Check(i,j,n) == 1)
	{
		Flag[i][j] = 1;
		Rat[i][j] = 5;
		for(int a = 0; a < 10; a++)
		{
			for(int b = 0; b < 10; b++)
			{
				cout << Rat[a][b];
			}
			cout << endl;
		}
		usleep(500000);
		MazeSolve = 1;
		system("CLS");
	}
	else
	{
		Flag[i][j] = 1;
		if(Array[i][j + 1] == 1 && Flag[i][j + 1] == 0	 && j != n - 1 && MazeSolve != 1)
		{
			Rat[i][j] = 0;
			Rat[i][j + 1] = 5;
			Maze (Array,Flag,i,j + 1,n);
			Rat[i][j] = 5;
			if(MazeSolve != 1)
			RatDisplay(Rat);
		}
		if(Array[i + 1][j] == 1 && Flag[i + 1][j] == 0 && i != n - 1 && MazeSolve != 1)
		{
			Rat[i][j] = 0;
			Rat[i + 1][j] = 5;
			Maze(Array,Flag,i + 1, j,n);
			Rat[i][j] = 5;
			if(MazeSolve != 1)
			RatDisplay(Rat);
		}
		if(Array[i][j - 1] == 1 && Flag[i][j - 1] == 0 &&  j != 0 && Check(i,j,n) == 0 && MazeSolve != 1)
		{
			Rat[i][j] = 0;
			Rat[i][j - 1] = 5;
			Maze (Array,Flag,i,j - 1,n);
			Rat[i][j] = 5;
			if(MazeSolve != 1)
			RatDisplay(Rat);
		}
		if(Array[i - 1][j] == 1 && Flag[i - 1][j] == 0 &&  i != 0 && Check(i,j,n) == 0 && MazeSolve != 1)
		{
			Rat[i][j] = 0;
			Rat[i - 1][j] = 5;
			Maze(Array,Flag,i - 1, j,n);
			Rat[i][j] = 5;
			if(MazeSolve != 1)
			RatDisplay(Rat);
		}
		if(MazeSolve != 1)
		{
			Array[i][j] = 0;
			Flag[i][j] = 2;
			Rat[i][j] = 0;
			return 1;
		}
		return 1;
	}
}
int main()
{
	for(int i = 0;i < 10;i++)
	{
		for(int j = 0; j < 10;j++)
		{
			Rat[i][j] = 0;
		}
	}
	int Array[][10] = 
	{
		{1,1,0,0,1,1,1,0,0,1},
		{0,1,1,0,1,0,1,1,0,1},
		{0,0,1,0,1,0,0,0,0,0},
		{1,1,1,1,1,0,1,1,0,0},
		{1,0,0,0,1,1,0,1,1,1},
		{1,1,0,0,0,0,0,1,0,1},
		{0,1,1,1,1,1,1,1,0,1},
		{0,1,0,1,0,0,1,0,0,1},
		{1,1,0,1,0,0,1,0,0,1},
		{0,0,0,1,1,1,1,1,0,1}
		};
	int Flag[][10] = 
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0}
	};
	Maze(Array,Flag,0,0,10);
	system("CLS");
	Display(Flag);
	cout << "1s are optimal path, 2s are explored paths that lead to dead ends.";
}
