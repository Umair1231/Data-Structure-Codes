#include <iostream>
using namespace std;
void Display(int Arr[],int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << Arr[i] << endl;
	}
	cout << "====================================================================================" << endl;
}
int Partition(int Arr[], int High, int Low,int n)
{
	int Pivot = Arr[High];
	int i = Low - 1;
	for(int j = Low; j < High; j++)
	{
		if(Arr[j] < Pivot)
		{
			i++;
			swap(Arr[i], Arr[j]);
			Display(Arr,n);
		}
	}
	swap(Arr[i + 1], Arr[High]);
	Display(Arr,n);
	return i + 1;
}
int QuickSort(int Arr[], int High, int Low, int n)
{
	if(Low < High)
	{
		int j = Partition(Arr, High - 1, Low, n);
		QuickSort(Arr,j,Low,n);
		QuickSort(Arr,High, j + 1,n);
	}
}
int CombSort(int Arr[], int Gap, int n)
{
	while(Gap != 1)
	{
		Gap = Gap / 1.3;
		for(int i = 0; i < n - Gap; i++)
		{
			if(Arr[i] > Arr[i + Gap])
			{
				swap(Arr[i], Arr[i + Gap]);
				Display(Arr,n);
			}
		}
	}
}
int InsertionSort(int Arr[], int n)
{
	int Temp;
	for(int i = 1; i < n; i++)
	{
		Temp = Arr[i];
		for(int j = i - 1; j >= 0; j--)
		{
			if(Temp < Arr[j])
			{
				Arr[j + 1] = Arr[j];
				Arr[j] = Temp;
				Display(Arr,n);
			}
		}
	}
}
int SelectionSort(int Arr[], int n)
{
	int Temp;
	int TempIndex;
	int Min = 100000;
	for(int i = 0 ; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{	
			if(Arr[j] < Min)
			{
				Min = Arr[j];
				TempIndex = j;	
			}
		}
		Min = 100000;
		Temp = Arr[TempIndex];
		Arr[TempIndex] = Arr[i];
		Arr[i] = Temp;
		Display(Arr,n);
	}
}
int BubbleSort(int Arr[], int n)
{
	int Temp;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n - i; j++)
		{
			if(Arr[j] > Arr[j + 1])
			{
				Temp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = Temp;
				Display(Arr,n);
			}
		}
	}
}
int Menu(int Arr[], int n)
{
	int Selection;
	cout << "Press 1 to Sort through Quick Sort." << endl;
	cout << "Press 2 to Sort through Insertion Sort." << endl;
	cout << "Press 3 to Sort through Selection Sort." << endl;
	cout << "Press 4 to Sort through Comb Sort." << endl;
	cout << "Press 5 to Sort through Bubble Sort." << endl;
	cout << "Press 0 to Exit." << endl;
	while(1)
	{
		cin >> Selection;
		if(Selection > 0 && Selection < 6)
		break;
		else
		cout << "Wrong Input.";
	}
	if(Selection == 1)
	{
		QuickSort(Arr,n,0,n);
	}
	else if(Selection == 2)
	{
		InsertionSort(Arr,n);
	}
	else if(Selection == 3)
	{
		SelectionSort(Arr,n);
	}
	else if(Selection == 4)
	{
		CombSort(Arr,n,n);
	}
	else if(Selection == 5)
	{
		BubbleSort(Arr,n);
	}
}
int main()
{
	int n;
	cout << "Enter Size of Array: ";
	cin >> n;
	int Arr[n];
	cout << "Fill Array.";
	for(int i = 0; i < n; i++)
	{
		cin >> Arr[i];
	}
	Menu(Arr,n);
}
