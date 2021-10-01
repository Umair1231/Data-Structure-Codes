#include<iostream>
using namespace std;
static int NodeCount = 0;
class LinkedList
{
	public:
	int Data;
	LinkedList* Head;
	LinkedList* Tail;
};

void Insert(LinkedList** HeadPointer, int Data)
{
	LinkedList* NewNode = new LinkedList();
	NewNode->Data = Data;
	NewNode->Head = *HeadPointer;
	NewNode->Tail = NULL;
	 if (*HeadPointer != NULL)
        (*HeadPointer)->Tail = NewNode;
	*HeadPointer = NewNode;
	NodeCount++;
	/* Cyclic Linked List 
	for(int i = 0;i < NodeCount - 1 ;i++)
	{
		NewNode = NewNode->Head;
	}
	NewNode->Head = *HeadPointer;
	*HeadPointer->Tail = NewNode;*/
}
void Display(LinkedList* Node)
{
	LinkedList* Temp = new LinkedList();
	while(Node != NULL)
	{
		cout << Node->Data << endl;
		Node = Node->Head;
	}
}
void BubbleSort(LinkedList* Node,LinkedList* Head)
{
	LinkedList* Temp = new LinkedList();
	for(int i = 0; i < NodeCount;i++)
	{
		for(int j = 0; j < NodeCount - i - 1;j++)
		{
			if(Node->Data > Node->Head->Data && Node->Head != NULL)
			{
				Temp->Data = Node->Head->Data;
				Node->Head->Data = Node->Data;
				Node->Data = Temp->Data;
			}
			Node = Node->Head;
		}
		Node = Head;
	}
	delete Temp;
}
int main()
{
	LinkedList* HeadPointer = NULL;	
	Insert(&HeadPointer,5);
	Insert(&HeadPointer,3);
	Insert(&HeadPointer,7);
	Insert(&HeadPointer,10);
	BubbleSort(HeadPointer,HeadPointer);
	Display(HeadPointer);
}
