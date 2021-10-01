#include <iostream>
using namespace std;
int Chess[8][8];
int CounterCheck()
{
	int i,j,Counter = 0;
	
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			if(Chess[i][j] == 1)
			Counter++;
		}
		
	}
	return Counter;
}
int Check(int a, int b)
{
	int t1,t2,t3,t4,t5,t6,t7,t8;
	int Count = 0;
	int i;
	for(i = 1; i < 8; i++)
	{
		t1 = 0;
		t2 = 0;
		t3 = 0;
		t4 = 0;
		t5 = 0;
		t6 = 0;
		t7 = 0;
		t8 = 0;
		if(a + i < 8)
		{
		t1 = Chess[a+i][b];
		}
		if(a - i > -1)
		{
		t2 = Chess[a-i][b];
		}
		if(b + i < 8)
		{
		t3 = Chess[a][b+i];
		}
		if(b - i > -1)
		{
		t4 = Chess[a][b-i];
		}
		if(a + i < 8 && b + i < 8)
		{
		t5 = Chess[a+i][b+i];
		}
		if(a - i > -1 && b - i > -1)
		{
		t6 = Chess[a-i][b-i];
		}
		if(a + i < 8 && b - i > -1)
		{
		t7 = Chess[a+i][b-i];
		}
		if(a - i > -1 && b + i < 8)
		{
		t8 = Chess[a-i][b+i];
		}
		if(t1 == 1 || t2 == 1 || t3 == 1 || t4 == 1 || t5 == 1 || t6 == 1 || t7 == 1 || t8 == 1)
		{
			Count = 1;
			break;
		}
		
	}
	return Count;
}
int Queen(int i, int j)
{
	int z;
	if(CounterCheck() == 8)
	return 0;
	while(1)
	{
		if(Check(i,j) == 1)
		{
			if(j >= 7 && i >= 7)
			return 0;
			else if(j == 7)
			{
				return 0;
			}
			else
			j++;
		}
		else
		{
			Chess[i][j] = 1;
			z = j;
			j = 0;
			i++;
			Queen(i,j);
			if(CounterCheck() == 8)
			return 0;
			if(z == 7)
			return 0;
			Chess[i-1][z] = 0;
			i = i-1;
			j = z + 1;
		}
	}
}
int main()
{
	int i;
	int j;
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			Chess[i][j] = 0;
		}
	}
	Queen(0,0);
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			cout << Chess[i][j];
		}
		cout << endl;
	}
}
