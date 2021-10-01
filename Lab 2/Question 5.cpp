#include<iostream>
using namespace std;

class Students
{
	double** Score;
	string* StudentNames;
	int* CourseNumbers;
	int NumberofStd;


	
	public:
		Students(int a)
		{	
			NumberofStd = a;
			//Getting Student Names and Number of Courses
			StudentNames = new string[NumberofStd];
			CourseNumbers = new int[NumberofStd];
			for(int i = 0 ;i < NumberofStd; i++)
			{
				cout << "Enter Student Name: ";
				cin >> StudentNames[i];
				cout << "Enter Number of Courses for this semester: ";
				cin >> CourseNumbers[i];
			}
			for(int i = 0; i < NumberofStd; i++)
			{
				Score = new double*[NumberofStd];
			}
			for(int i = 0; i < NumberofStd; i++)
			{	
				Score[i] = new double[CourseNumbers[i]];
				cout << "For student " << StudentNames[i] << " : " << endl;
				for(int j = 0; j < CourseNumbers[i] ; j++)
				{
					cout << "Enter Marks for Course " << i + 1 << " : ";
					cin >> Score[i][j];
				}	
				
				cout << endl;
			}		
		}
		
		void DisplayGPA()
		{
			cout << "GPA OF ALL STUDENTS:" << endl;
			
			double totalGPA = 0;
			
			for(int i=0; i<NumberofStd; i++)
			{	
				cout << StudentNames[i] << " : " << endl;
				for(int j = 0; j < CourseNumbers[i] ; j++)
				{
					totalGPA += (Score[i][j] * 3);
				}	
				totalGPA = totalGPA / (CourseNumbers[i] * 3);
				cout << "GPA: " << totalGPA << endl;
				totalGPA = 0;
			}	
			
		}
		
		void DisplayData()
		{		
			cout << "Student Data" << endl;
		
			for(int i = 0; i < NumberofStd ; i++)
			{		
				cout << StudentNames[i] << "\t";
				for(int j = 0; j < CourseNumbers[i] ; j++)
				{
					cout << Score[i][j] << "\t";
				}
				cout << endl;
			}
		}
		
		~Students()
		{
			delete[]Score;
			delete[]StudentNames;
			delete[]CourseNumbers;
		}
		
};




int main()
{
cout<<"Enter Number of Students: ";
int numberofStds;
cin >> numberofStds;
Students std(numberofStds);
std.DisplayData();
cout << endl;
std.DisplayGPA();


}
