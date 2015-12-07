#include<iostream>
#include<string>
#include<iomanip>
#include"myHeader.h"

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
			studentCourseList(arrUserProfile,  arrStudentResult,  arrCourse,  counter,  tmpData,  MAX);
			break;
		case 2 :
			tmpData->stdID = tmpData->currentUserId;
			gradeComponent(arrCourse, arrStudentResult, tmpData, counter, MAX );			
			break;
		case 3 :
				tmpData->stdID = tmpData->currentUserId;
				chooseCourse(arrCourse, MAX, tmpData);
				gradeList(arrStudentResult, tmpData, counter);			
			break;
		case 4 :
			//choice = exitPrompt("Are you sure you want to reurn to main menu",4);
			break;
		default :
			break;
		}
		if(choice != 4 )
		{
			pausePrompt("Press any key to return to student menu....");
		}

	}while(choice != 4);

	return 0;
}
void studentCourseList(UserProfile arrUserProfile[], StudentResult arrStudentResult[], Course arrCourse[], int counter, Buffer *tmpData, int MAX)
{
	system("cls");
	programTitle();
	const string TITLE = "MAIN MENU/STUDENT MENU/COURSE LIST";
	pageTitle(TITLE);
	cout << "\n";
	string listTitles[] = {"COURSE LIST",
							"Course ID  ",
							"Course Title                      ",
							"Teacher Name     "};
	listHeader(listTitles, 4);
	string leftMargin = leftMarginSpace(listTitles,4);
	// as roie shomare daneshjooi courshash ro peida kone
	//string *arrTmpCourseID
	//string *arrTmpCourseTitle
	//arrTmpCourseID = new string[MAX];
	//arrTmpCourseTitle = new string[MAX];
	//int jCounter = 0;
				
	string fullName = tmpData->stdLname + "," + tmpData->stdFname;

	for ( int i = 0; i < counter; i++)
	{
		if (arrStudentResult[i].studentID == tmpData->currentUserId) // prevent searching empty records
		{
			getCourseInfo(arrCourse, arrStudentResult[i].courseID, tmpData, MAX);
			getTeacherInfo(arrUserProfile, tmpData, MAX);
			string courseTitle = tmpData->stdCourseTitle;
			string teacherName = tmpData->tchLname + "," + tmpData->tchLname;
			cout << leftMargin << "  "
				 << left << setw( listTitles[1].length() + 2) << arrStudentResult[i].courseID 
				 << setw(listTitles[2].length() + 2)  << courseTitle 
				 << setw( listTitles[3].length() )  << teacherName
				 << right << endl;
			}
		else
		{
			break;
		}
	}


}
void getCourseInfo(Course arrCourses[], string courseId, Buffer *tmpData, int MAX)
{
	for (int i = 0; i < MAX; i++)
	{
		if (arrCourses[i].courseID == courseId)
		{
			tmpData->stdCourseTitle =  arrCourses[i].courseTitle;
			tmpData->tchID = arrCourses[i].teacherID;
			break;
		}
	}
}
void getTeacherInfo(UserProfile arrUserProfile[], Buffer *tmpData, int MAX)
{
		for (int i = 0; i < MAX; i++)
	{
		if (arrUserProfile[i].userID == tmpData->tchID)
		{
			tmpData->tchFname = arrUserProfile[i].fname;
			tmpData->tchLname = arrUserProfile[i].lname;
			break;
		}
	}
}
void gradeComponent(Course arrCourse[], StudentResult arrStudentResult[], Buffer *tmpData, int counter, int MAX)
{
	system("cls");
	programTitle();
	cout << "\n\n";
	//("pause");
	//middleText("Course Number: " + tmpData->stdCourseID + "\n" );
	//middleText("Course Title: " + tmpData->stdCourseTitle + "\n" );
	middleText("Instructor: " + tmpData->tchFname + " " + tmpData->tchLname + "\n" );
	middleText("Session: Automn 2015\n" );
	middleText("Group: " + to_string(tmpData->stdGroupID) + "\n\n" );
	middleText(tmpData->stdFname + "," + tmpData->stdLname + "\n" );
	
	chooseCourse(arrCourse, MAX, tmpData);

	cout << "\n\n\tAvailable grade components: ";

	string arrComponents[] = {"1.Project      ",
							  "2.Midterm Exam ",
							  "3.Final Exam   ",
							  "4.Final result "};
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "\t\t\t\t\t" << arrComponents[i] << endl;
	}
	cout << "\n\t\t\t\t\tSelect component number:";
	int choice = getMenuChoiceOK(4);
	
	for (int i = 0; i < counter; i++)
	{
		if (tmpData->stdID == arrStudentResult[i].studentID && tmpData->stdCourseID == arrStudentResult[i].courseID )
		{
			switch(choice)
			{
				case 1:
					
					cout << "\n\tThe project grade is : "<< arrStudentResult[i].Project;
					break;
				case 2:
					cout << "\n\tThe midterm exam grade is : " << arrStudentResult[i].midtremExam;
					break;
				case 3:
					cout << "\n\tThe final exam grade is : " << arrStudentResult[i].finalExam;
					break;
				case 4:
					cout << "\n\tThe final result is : " << finalResult(arrStudentResult[i].Project,arrStudentResult[i].midtremExam,arrStudentResult[i].finalExam);
					break;
				default:
					break;

			}
		}
	}
	
	//pausePrompt("Press any key to return to teachers menu....");
	
}




