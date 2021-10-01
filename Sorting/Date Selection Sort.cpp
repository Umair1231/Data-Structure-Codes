#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
	int Day[5] = {2,3,4,5,6};
	int Month[5] = {2,3,4,5,6};
	int Year[5] = {1400,1600,1200,1800,1000};
	cout << "Input Dates: " << endl;
	for(int i = 0;i < 5; i++)
	{
	
	}
	int Temp;
	int TempIndex;
	int Min = 100000;
	for(int i = 0 ; i < 5; i++)
	{
		for(int j = i; j < 5; j++)
		{	
			if(Year[j] < Min)
			{
				Min = Year[j];
				TempIndex = j;	
			}
		}
		Min = 100000;
		Temp = Year[TempIndex];
		Year[TempIndex] = Year[i];
		Year[i] = Temp;
		Temp = Day[TempIndex];
		Day[TempIndex] = Day[i];
		Day[i] = Temp;
		Temp = Month[TempIndex];
		Month[TempIndex] = Month[i];
		Month[i] = Temp;
	}
	for(int i = 0; i < 5; i++)
	{
		cout << Day[i] << "/" << Month[i] << "/" << Year[i] << endl;
	}
}
