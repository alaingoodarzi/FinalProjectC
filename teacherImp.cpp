#include<iostream>
#include<string>
#include<iomanip>
#include"myHeader.h"



int teacherOperations(int MAX, int &counter, UserProfile arrUserProfile[], Course arrCourse[], Groups arrGroups[], StudentResult arrStudentResult[], Buffer *tmpData)
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
			addStudentGrade(arrUserProfile,arrCourse, arrGroups, arrStudentResult, tmpData, MAX, counter );
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




int addStudentGrade(UserProfile arrUserProfile[], Course arrCourse[], Groups arrGroups[], StudentResult arrStudentResult[], Buffer *tmpData ,int MAX, int &counter)
{

	system("cls");
	cout << "\n\n\n\t\t\t\tSTUDENT GRADE FORM" << endl << endl << endl << endl;

	if (counter == MAX)
	{
		cout << "\n\tThe capacity of list is full!";
		return 0;
	}

	do
	{
		bool jFound = false;
		tmpData->stdID = newStdID(arrUserProfile, counter, MAX);
		int jIndex = 0;
		jIndex = checkIdDuplication(arrUserProfile, counter, tmpData->stdID);
		if (jIndex != 0 )
		{
			jFound = true;
			tmpData->stdFname = arrUserProfile[jIndex].fname;
			tmpData->stdLname = arrUserProfile[jIndex].lname;
			tmpData->stdPass = arrUserProfile[jIndex].passWord;
			cout << "\n\tStudent first name: " << tmpData->stdFname << endl;
			cout << "\n\tStudent last name: " << tmpData->stdLname << endl;
			cout << "\n\tStudent password: " << tmpData->stdPass << endl;
		}else
		{
			cin.ignore();
			tmpData->stdFname = newNameFamily("Please enter student name");
			tmpData->stdLname = newNameFamily("Please enter student family");
			tmpData->stdPass = strUserPass("Please enter student password(alphanumeric)");
			tmpData->stdGroupID = chooseGroup(arrGroups, MAX);
		}
		
		tmpData->stdCourseID = chooseCourse(arrCourse, tmpData->stdGroupID ,MAX, tmpData);

		if (stdCrsDuplicate(arrStudentResult, tmpData->stdCourseID, tmpData->stdID, counter ) == true)
		{
			getStudentGrade(arrStudentResult, tmpData->tchID,tmpData->stdCourseID, tmpData->stdID);

			cout << "\n\tStudent Projecte: " << tmpData->stdProject << endl;
			cout << "\n\tStudent last name: " << tmpData->stdMidterm << endl;
			cout << "\n\tStudent password: " << tmpData->stdFinal << endl;
		}else
		{
 
			tmpData->stdProject = floatValue(100,"Please enter the Project grade");
			tmpData->stdMidterm = floatValue(100,"Please enter the Midtrem exam grade");
			tmpData->stdFinal = floatValue(100,"Please enter the Final exam grade");
						
			displayNewStudent(tmpData);

			if(myYesNo("Do you want to save this student") == 'Y')
			{
				counter++;
			}
		}
		

	} while (counter < MAX);
}


void getStudentGrade(StudentResult arrStudentResult[],int teacherID,string CourseID, int stdID)
{

}



int newStdID(UserProfile arrUserProfile[], int &counter, int MAX)
{
	int newId = 0;
	cout << "\n\tPlease enetr a 7 digit number for student ID (" << counter + 1 << "/" << MAX << "): ";
	while(!(cin >> newId ) || (newId < 1000000 || newId > 9999999) )
	{
		cout << "\n\tInavlid! Try again (7 digit number): ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}	
	return newId;
}