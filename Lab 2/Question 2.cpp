#include<iostream>
using namespace std;
class Test
{
	public:
		int arr[10];
		Test()
		{
			
			for(int i = 0;i < 10; i++)
			{
				cout << "Enter Element: ";
				cin >> arr[i];
			}
		}
		void SortArray()
		{
			int Min = 1000;
			int SecMin = 1000;
			cout << "Ascending: " << endl;
			for(int j = 0; j < 10; j++)
				{
			 		if(arr[j] < Min)
					Min = arr[j];
				}
			for(int j = 0; j < 10; j++)
				{
					if(arr[j] > Min && arr[j] < SecMin)
					SecMin = arr[j];
				}	
			cout << Min << endl << SecMin << endl;
			for(int i = 0; i < 4; i++)
			{
				Min = 1000;
				for(int j = 0; j < 10; j++)
				{
					if(arr[j] > SecMin && arr[j] < Min)
					Min = arr[j];
				}
				SecMin = 1000;
				for(int k = 0; k < 10; k++)
				{
					if(arr[k] > Min && arr[k] < SecMin)
					SecMin = arr[k];
				}
				cout << Min << endl << SecMin << endl;
			}
			cout << "Descending: " << endl;
			int Max = 0;
			int SecMax = 0;
			for(int j = 0; j < 10; j++)
				{
			 		if(arr[j] > Max)
					Max = arr[j];
				}
			for(int j = 0; j < 10; j++)
				{
					if(arr[j] < Max && arr[j] > SecMax)
					SecMax = arr[j];
				}	
			cout << Max << endl << SecMax << endl;
			for(int i = 0; i < 4; i++)
			{
				Max = 0;
				for(int j = 0; j < 10; j++)
				{
					if(arr[j] < SecMax && arr[j] > Max)
					Max = arr[j];
				}
				SecMax = 0;
				for(int k = 0; k < 10; k++)
				{
					if(arr[k] < Max && arr[k] > SecMax)
					SecMax = arr[k];
				}
				cout << Max << endl << SecMax << endl;
			}
		}
		~Test()
		{
		}
};
int main()
{
	Test T;
	T.SortArray();
}
