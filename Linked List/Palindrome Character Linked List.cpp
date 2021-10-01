#include<iostream>
using namespace std;
static int NodeCount = 0;
class LinkedList
{
	public:
	char Data;
	LinkedList* Head;
};

void Insert(LinkedList** HeadPointer, char Data)
{
	LinkedList* NewNode = new LinkedList();
	NewNode->Data = Data;
	NewNode->Head = *HeadPointer;
	*HeadPointer = NewNode;
	NodeCount++;
	/* Cyclic Linked List 
	for(int i = 0;i < NodeCount - 1 ;i++)
	{
		NewNode = NewNode->Head;
	}
	NewNode->Head = *HeadPointer;*/
}
int Palindrome(LinkedList* Node)
{
	int count = 2;
	int temp = NodeCount / 2;
	int OffSet = 0;
	if(NodeCount % 2 == 0)
	{
		OffSet = 0.5;
		count = 1;	
	}
	LinkedList* NewNode[temp];
	for(int i = 0; i < temp; i++)
	{
		NewNode[i] = new LinkedList();
	}
	for(int i = 0; i < NodeCount; i++)
	{
		if(i < NodeCount / 2)
		{
			NewNode[i]->Data = Node->Data;
		}
		else if(i > (NodeCount / 2) - OffSet)
		{
			if(Node->Data != NewNode[i - count]->Data)
			{
				cout << "Linked List is not Palindrome.";
				return 1;
			}
			else
			{
				count = count + 2;
			}
		}
		if(Node->Head != NULL)
		Node = Node->Head;
	}
	cout << "Linked List is Palindrome.";
}
void Display(LinkedList* Node)
{
	system("CLS");
	LinkedList* Temp = new LinkedList();
	while(Node != NULL)
	{
		cout << Node->Data << endl;
		Node = Node->Head;
	}
}
int main()
{
	int n;
	char Data;
	cout << "Enter number of elements in the Linked List: ";
	cin >> n;
	LinkedList* HeadPointer = NULL;	
	if(n <= 1)
	cout << "Linked List is not Palindrome" << endl;
	else
	{
		cout << "Enter Elements: ";
		for(int i = 0;i < n;i++)
		{
			cin >> Data;
			Insert(&HeadPointer,Data);
		}
		Palindrome(HeadPointer);
	}
}
