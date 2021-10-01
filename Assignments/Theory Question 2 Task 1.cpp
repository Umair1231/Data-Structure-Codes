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
		for(int i = 0; i < Size; i++)
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
	static void Disjoint(Test Obj1, Test Obj2)
	{
		int Flag = 0;
		int Temp;
		if(Obj1.Size < Obj2.Size)
		Temp = Obj1.Size;
		else 
		Temp = Obj2.Size;
		for(int i = 0; i < Temp ; i++)
		{
			if(Obj1.ArrPtr[i] == Obj2.ArrPtr[i])
			{
				Flag = 1;
				break;
			}
		}
		if(Flag)
		{
			cout << "Arrays are not disjoint. ";
		}
		else
		cout << "Arrays are disjoint.";
	}
};
int main()
{
	Test T1, T2;
	Test::Disjoint(T1, T2);
}
