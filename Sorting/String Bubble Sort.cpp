#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int k;
	string temp;
	string a[] = {"Zimbabwe", "South-Africa", "India", "America", "Yugoslavia", "Australia", "Denmark", "France", "Netherlands", "Italy", "Germany"};
	for(int i = 0; i < 11; i++)
	{
		for(int j = 0; j < 10 - i; j++)
		{
			if(a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for(int i = 0 ; i < 11; i++)
	{
		cout << a[i] << endl;
	}
}
