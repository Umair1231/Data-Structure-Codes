#include<bits/stdc++.h>
using namespace std;
class myclass
{
	private:
		int size;
		int *array;
	public:
		myclass(int n)
		{
			size = n;
			array = new int [size] { 6, 6, 7, 6, 9, 1, 9, 0, 0, 1, 4, 5, 1 };
	    }
	    void duplicateremove()
	    {
	    	int k=0;
	    	int count=0;
	    	int temp[size];
	    	for (int i = 0; i < size; ++i)
			{
                int flag = 1;
                for (int j = 0; j < i; ++j) 
				{ 
                    if (array[j] == array[i])
				    {
                        flag = 0;
                        break;
                    }
                }
            if (flag)
            {
            	temp[k] = array[i];
            	count++;
            	k++;
			}
            }
            for (int i = 0; i<count; ++i)
            {
            	array[i] = temp[i];
			}
            int newSize = count;
            int* newArr = new int[newSize];
            memcpy(newArr, array, size * sizeof(int));
            size = newSize;
            delete[] array;
            array = newArr;
        }
        void print()
        {
        	cout<<"ARRAY WITHOUT DUPLICATES"<<endl;
        	for(int i=0;i<size;i++)
        	{
        		cout<<array[i]<<"\t";
			}
		}
};
int main()
{
	myclass obj1(13);
	obj1.duplicateremove();
	obj1.print();
}

