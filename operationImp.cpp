#include<iostream>
#include<string>
#include"myHeader.h"


int studentOperation(int MAX, int& counter)
{
	int choice = 0 ;
	do
	{
		choice = studentMenu();
		switch(choice)
		{
		case 1 :
			cout << "Fisrt student choice";
			break;
		case 2 :
			cout << "second student choice";
			break;
		case 3 :
			cout << "third student choice";
			break;
		case 4 :
			choice = exitPrompt("Are you sure you want to reurn to main menu",4);
			break;
		default :
			break;
		}
		system("pause>null");

	}while(choice != 4);

	return 0;
}


int teacherOperations(int MAX, int &counter)
{
	int choice = 0 ;
	do
	{
		choice = teacherMenu();
		switch(choice)
		{
		case 1 :
			cout << "Fisrt teacher choice";

			break;
		case 2 :
			cout << "second teacher choice";
			break;
		case 3 :
			cout << "third teacher choice";
			break;
		case 4 :
			cout << "forth teacher choice";
			break;
		case 5 :
			cout << "fift teacher choice";
			break;

		case 6 :
			choice = exitPrompt("Are you sure you want to reurn to main menu",6);
			break;
		default :
			break;
		}
		system("pause>null");

	}while(choice != 6);

	return 0;

}

int initialValues(UserProfile arrUserProfile[],int arrGroups[],Course arrCourses[])
{

	arrUserProfile[0].userID   = 5257;
	arrUserProfile[0].passWord = "quanghoang";
	arrUserProfile[0].fname    = "Quang Hoang";
	arrUserProfile[0].fname    = "Cao";
	arrUserProfile[0].tOrS     = 't';

	arrGroups[0] = 7148;
	arrGroups[1] = 7150;
	arrGroups[2] = 7151;
	arrGroups[3] = 7256;

	arrCourses[0].courseID = "420-P16-AS";
	arrCourses[0].courseTitle = "Structured Programming";
	arrCourses[0].teacherID = 5257;
	arrCourses[0].group = 7148;

	arrCourses[1].courseID = "420-P16-AS";
	arrCourses[1].courseTitle = "Structured Programming";
	arrCourses[1].teacherID = 5257;
	arrCourses[1].group = 7150;

	arrCourses[2].courseID = "420-P16-AS";
	arrCourses[2].courseTitle = "Introduction à la programmation structurée";
	arrCourses[2].teacherID = 5257;
	arrCourses[2].group = 7151;

	arrCourses[3].courseID = "420-P34-AS";
	arrCourses[3].courseTitle = "Advanced Object Programming";
	arrCourses[3].teacherID = 5257;
	arrCourses[3].group = 7256;








	return 0;
}