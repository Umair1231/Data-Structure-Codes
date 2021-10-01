// Umair Amir K20-0133 //
#include<iostream>
using namespace std;
class Test
{
	int Size;
	int* ArrPtr;
	public:
	Test()
	{
		cout << "Enter Size of Array: ";
		cin >> Size;
		ArrPtr = new int[Size];
		cout << "Enter Array Elements: ";
		for(int i = 0;i < Size; i++)
		{
			cin >> ArrPtr[i];
		}	
	}
	int& operator [](int i)
	{
		if (i < 0 || i > Size - 1)
		{
			cout << "Boundary Exceeded.";
			exit(1);
		}
	return ArrPtr[i];
	}
	void Duplicate()
	{
		int A = 0;
		int Count = 0;
		int TempArray[Size];
		int Flag = 0;
		for(int i = 0; i < Size; i++)
		{
			Flag = 1;
			for(int j = 0; j < i; j++)
			{
				if(ArrPtr[i] == ArrPtr[j])
				{
					Flag = 0;
					break;
				}
			}
			if(Flag)
			{
				TempArray[A] = ArrPtr[i];
				Count++;
				A++;	
			}		
		}
		int* NewArray;
		NewArray = new int[Count];
		memcpy(NewArray,TempArray,Count * sizeof(int));
		Size = Count;
		delete[] ArrPtr;
		ArrPtr = NewArray;		
	}
	void Display()
	{
		cout << "Array without Duplicates: ";
		for(int i = 0; i < Size; i++)
		{
			cout << ArrPtr[i] << endl;	
		}	
	}		
};
int main()
{
	Test T;
	T.Duplicate();
	T.Display();
}
