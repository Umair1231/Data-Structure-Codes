#include <iostream>
using namespace std;
int main()
{
	int Arr[5] = {4,3,8,1,5};
	int Temp;
	for(int i = 1; i < 5; i++)
	{
		Temp = Arr[i];
		for(int j = i - 1; j >= 0; j--)
		{
			if(Temp < Arr[j])
			{
				Arr[j + 1] = Arr[j];
				Arr[j] = Temp;
			}
		}
	}
	for(int i = 0 ; i < 5; i++)
	{
		cout << Arr[i] << endl;
	}
}
