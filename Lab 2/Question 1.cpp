#include<iostream>
using namespace std;
class Test
{
	public:
	int row;
	int column;
	int **ptr;
	Test()
	{
		cout << "Row: ";
		cin >> row;
		cout << "Column: ";
		cin >> column;
		ptr = new int*[row];
		for(int i = 0;i < row; i++)
		{
			ptr[i] = new int[column];
		}
	}
	void FillArr()
	{
		for(int i = 0;i < row; i++)
		{
			for(int j = 0; j < column; j++)
			{
				cout << "Enter Matrix numbers: ";
				cin >> ptr[i][j];
			}
		}
	}
	int IdentityCheck()
	{
		if(row != column)
		{
			cout << "Not Identity Matrix.";
			return 0;
		}
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < column; j++)
			{
				if(ptr[i][j] != 0 && ptr[i][j] != 1)
				{
					cout << "Not Identity Matrix.";
					return 0;
				}
			}
		}
		for(int i = 0; i < row; i++)
		{
			if(ptr[i][i] != 1)
			{
				cout << "Not Identity Matrix.";
				return 0;
			}
		}
		cout << "Matrix is Identity Matrix.";
		return 0;
	}
	~Test()
	{
		delete[] ptr;
	}
};
int main()
{
	Test T;
	T.FillArr();
	int temp;
	temp = T.IdentityCheck();
	T.~Test();
}

