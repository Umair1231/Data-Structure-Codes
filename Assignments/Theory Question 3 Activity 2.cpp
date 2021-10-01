#include <iostream>
using namespace std;
int Test(int Array[], int Size)
{
	int temp;
	if(Size <= 1)
	{
		for(int i = 0; i < 3; i++)
		{
			cout << Array[i] << endl;
		}
		return 1;
	}
	else
	{
		for(int i = 0; i < Size - 1; i++)
		{
			if(Array[i] > Array[i + 1])
			{
				temp = Array[i];
				Array[i] = Array[i + 1];
				Array[i + 1] = temp;
			}
		}
		Test(Array, Size - 1);
	}
}
int main()
{
	int Array[] = {5,4,3};
	int Size = sizeof(Array) / sizeof(int);
	Test(Array, Size);
}


