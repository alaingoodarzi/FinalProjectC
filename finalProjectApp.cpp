#include<iostream>
#include<string>
#include"myHeader.h"
using namespace std;

void main()
{
	const int MAX = 3;
	int counter = 0;

	UserProfile arrUserProfile[MAX];
	Course arrCourses[MAX];
	int arrGroups[MAX];
	StudentResult arrStudentResults[MAX];
	Buffer tmpStdRslt;

	welcomePage();
	initValues(arrUserProfile,arrGroups,arrCourses);

	int choice = 0;
	do
	{
		choice = mainMenu();
		switch(choice)
		{
			case 1 :
				teacherOperations(MAX,counter);
				break;
			case 2 :
				studentOperation(MAX,counter);
				break;
			case 3 :
				choice = exitPrompt("Are you sure you want to exit program",3);
				break;
			default :
				break;
		}
	}while(choice != 3);
}
