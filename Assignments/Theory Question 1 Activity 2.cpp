#include <iostream>
using namespace std;
int Test(int i)
{
	cout << i << endl;
	if(i >= 5)
	return i;
	else
	{
	Test(i + 1);
	cout << i << endl;
	}
}
int main()
{
	Test(1);
}
