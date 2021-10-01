#include <iostream>
using namespace std;
int Test(int Base, int Power)
{
	static int StartValue = Base;
	int Answer;
	if(Power <= 1)
	return Base;
	else
	{
	Answer = Test(Base * StartValue, Power - 1);
	return Answer;
	}
}
int main()
{
	int Base, Power;
	cout << "Enter Base Number: ";
	cin >> Base;
	cout << "Enter Power: ";
	cin >> Power;
	cout << "Answer: " << Test(Base, Power);
}
