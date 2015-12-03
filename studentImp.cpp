#include<iostream>
#include<string>
#include<iomanip>
#include"myHeader.h"

//1.List all the courses he/she is taking
//2. View the grade for a given evaluation component 
//   (Midterm Exam, Final Project or final Exam) related to
//   a course he/she is taking in this session (Autumn 2015)
//3. List all the grades for a given course
//4. Quit the application

int studentOperation(StudentResult arrStudentResult[], Groups arrGroups[], Course arrCourse[], UserProfile arrUserProfile[], Buffer *tmpData, int counter, int MAX)
{
	int choice = 0 ;
	string stdFullname = tmpData->stdFname + " " + tmpData->stdLname;
	do
	{
		choice = studentMenu(stdFullname);
		switch(choice)
		{
		case 1 :
			cout << "Fisrt student choice";
			break;
		case 2 :
			cout << "second student choice";
			break;
		case 3 :
				tmpData->stdID = tmpData->currentUserId;
				chooseCourse(arrCourse, MAX, tmpData);
				gradeList(arrStudentResult, tmpData, counter);			
			break;
		case 4 :
			choice = exitPrompt("Are you sure you want to reurn to main menu",4);
			break;
		default :
			break;
		}
		system("pause>nul");

	}while(choice != 4);

	return 0;
}

void studentCourseList(Course arrCourses[], int MAX, Buffer *tmpData)
{
	//cout << "\n\tSelect the course: ";
	string listTitles[] = {"COURSE LIST",
							"Course ID     ",
							"Course Title                     ",
							"Teacher NAme        "};
	listHeader(listTitles, 4);
	string leftMargin = leftMarginSpace(listTitles,4);
	// as roie shomare daneshjooi courshash ro peida kone
	string *arrTmpCourseID
	string *arrTmpCourseTitle
	arrTmpCourseID = new string[MAX];
	arrTmpCourseTitle = new string[MAX];
	int jCounter = 0;

	for ( int i = 0; i < MAX; i++)
	{
		if (arrCourses[i].courseN > 0) // prevent searching empty records
		{
			if (arrCourses[i].groupID == tmpData->stdGroupID)
			{
				cout << "\n\t\t\t" << jCounter + 1 << "." << arrCourses[i].courseID;
				arrTmpCourseID[jCounter] = arrCourses[i].courseID;
				arrTmpCourseTitle[jCounter] = arrCourses[i].courseTitle;
				jCounter++;
			}
		}
		else
		{
			break;
		}
	}
	cout << "\tEnter course number: ";
	int choice = getMenuChoiceOK( jCounter );
	//cin.ignore();
	tmpData->   stdCourseID =    arrTmpCourseID[choice - 1];
	tmpData->stdCourseTitle = arrTmpCourseTitle[choice - 1];

	delete [] arrTmpCourseID;
	delete [] arrTmpCourseTitle;

}