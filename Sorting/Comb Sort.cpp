#include <iostream>
using namespace std;
int main()
{
	int Arr[10] = {4,6,8,3,2,10,5,1,7,9};
	int Gap = 10;
	while(Gap != 1)
	{
		Gap = Gap / 1.3;
		for(int i = 0; i < 10 - Gap; i++)
		{
			if(Arr[i] > Arr[i + Gap])
			{
				swap(Arr[i], Arr[i + Gap]);
			}
		}
	}
	for(int i = 0; i < 10; i++)
	{
		cout << Arr[i] << endl;
	}
}
