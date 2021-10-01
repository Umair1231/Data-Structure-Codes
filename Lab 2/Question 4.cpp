#include<iostream>
using namespace std;
class Test
{
	public:
		bool arr[5][5];
		Test():arr
		{
			{false,true,false,true,true},
			{true,false,true,false,true},
			{false,true,false,false,false},
			{true,false,false,false,true},
			{true,true,false,true,false}
		}
		{
			
		}
		public:
		void CommonFriend()
		{
			for(int i = 0;i < 5; i++)
			{
				for(int j = i ; j < 5; j++)
				{
					if(arr[i][j] == true)
					cout << i << " and " << j << " are common friends." << endl;
				}
			}
		}
};
int main()
{
	Test T;
	T.CommonFriend();
}