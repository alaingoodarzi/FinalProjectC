#include<iostream>
#include<string>
#include"myHeader.h"
using namespace std;

int main()
{
	const int MAX = 10;
	int counter = 0;
	UserProfile arrUserProfile[MAX];
	Course arrCourses[MAX];
	Groups arrGroups[MAX];
	StudentResult arrStudentResults[MAX];
	Buffer tmpData;
	welcomePage();
	initialValues(arrUserProfile, arrGroups, arrCourses, MAX, &tmpData, counter, arrStudentResults);
	int choice = 0;
	if (userPass(arrUserProfile, &tmpData, counter) == false)
		{
			return -1;
		}
	do
	{

		choice = mainMenu();
		switch(choice)
		{
			case 1 :
				if(tmpData.currentTorS == 't' )
				{
					teacherOperations(MAX,counter,arrUserProfile,arrCourses,arrGroups,arrStudentResults,&tmpData);
				}else
				{
					middleText("\n\n\tYou have no right to enter this part of program !");
					system("pause>nul");
				}
				break;
			case 2 :
				studentOperation(arrStudentResults, arrGroups, arrCourses, arrUserProfile, &tmpData, counter, MAX);
				break;
			case 3 :
				//choice = exitPrompt("Are you sure you want to exit program",3);
				break;
			default :
				break;
		}
	}while(choice != 3);
	
	return 1;
}
