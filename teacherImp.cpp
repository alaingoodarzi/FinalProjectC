#include<iostream>
#include<string>
#include<iomanip>
#include"myHeader.h"



int teacherOperations(int MAX, int &counter, UserProfile arrUserProfile[], Course arrCourse[], Buffer *tmpData)
{
	int choice = 0 ;
	do
	{
		choice = teacherMenu();
		switch(choice)
		{
		case 1 :
			//1.Course list
			teacherCourses(arrCourse, tmpData);
			break;
		case 2 :
			//"Add Student Grade";
			addStudentGrade(MAX, &counter, arrUserProfile,arrCourse, *tmpData);
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
int teacherCourses( Course arrCourses[], Buffer *tmpData)
{
	int    titleLengths[4];
	string listTitles[4] = {
						"TEACHER COURSE LIST",
						"Number    ",
						"Title                                       ",
						"Group  "
						};
	titleLength(titleLengths, listTitles);
	listHeader(listTitles,4, titleLengths);
	listRecord(arrCourses, listTitles, titleLengths, tmpData );
	return 0;
}

int addStudentGrade(int MAX, int &counter, UserProfile arrUserProfile[], Course arrCourse[], Buffer *tmpData)
{



	if (counter == MAX)
	{
		cout << "\n\tThe capacity of list is full!";
		return 0;
	}

	do
	{
		newStdID(arrUserProfile, counter);
	
	
	} while (counter < MAX);




}


int newStdID(UserProfile arrUserProfile[], int &counter)
{
	int newId = 0;
		while(!(cin >> newId ) || (newId > 999999 && newId < 10000000))
		{
			cout << "\n\tInavlid! Try again (7 digit number): ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}	
		return checkDuplicateID(arrUserProfile, counter, newId);
}