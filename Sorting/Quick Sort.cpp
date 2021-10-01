#include <iostream>
using namespace std;
int Partition(int Arr[], int High, int Low)
{
	int Pivot = Arr[High];
	int i = Low - 1;
	for(int j = Low; j < High; j++)
	{
		if(Arr[j] < Pivot)
		{
			i++;
			swap(Arr[i], Arr[j]);
		}
	}
	swap(Arr[i + 1], Arr[High]);
	return i + 1;
}
int QuickSort(int Arr[], int High, int Low)
{
	if(Low < High)
	{
		int j = Partition(Arr, High, Low);
		QuickSort(Arr,j - 1,Low);
		QuickSort(Arr,High, j + 1);
	}
}
void Display(int Arr[])
{
	for(int i = 0 ; i < 10; i++)
	{
		cout << Arr[i] << endl;
	}
}
int main()
{
	int Arr[10] = {4,6,8,3,2,10,5,1,7,9};
	QuickSort(Arr,9,0);
	Display(Arr);
}
