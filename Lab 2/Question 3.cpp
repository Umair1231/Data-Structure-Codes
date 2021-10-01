#include<iostream>
using namespace std;
class Test
{
	public:
	int arr[10];
	Test()
	{
		cout << "Enter Elements: ";
		for(int i = 0; i < 10; i++)
		{
			while(1)
			{
				cin >> arr[i];
				if(arr[i] > 0)
				break;
				else
				cout << "Enter Positive Number.";
			}
		}
	}
	void SortArray()
	{
		int AscTemp = 0;
		int DesTemp = 0;
		int Ascending[10];
		int Descending[10];
		for(int i = 0;i < 9; i++)
		{
			for(int j = 0; j < 9 - i; j++)
			{
				if(arr[j] > arr[j + 1])
				{
					AscTemp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = AscTemp;
				}
			}
		}
		for(int i = 0;i < 10; i++)
		{
			Ascending[i] = arr[i];
			Descending[i] = arr[9 - i];
		}
		for(int i = 0; i < 5; i++)
		{
			arr[i] = Ascending[i];
			arr[i + 1] = Descending[i];
			cout << arr[i] << endl << arr[i + 1] << endl;
		}
	}
};
int main()
{
	Test T;
	T.SortArray();
}