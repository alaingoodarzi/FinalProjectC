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
	

	if (counter == MAX)
	{
		cout << "\n\tThe capacity of list is full!";
		return 0;
	}

	do
	{
		system("cls");
		pageTitle("STUDENT GRADE FORM");
		formTitle("Please Enter student information", counter, MAX);

		bool jFound = false;
		tmpData->stdID = newStdID(arrUserProfile, counter, MAX);
		int jIndex = 0;
		jIndex = checkIdDuplication(arrUserProfile, counter, tmpData->stdID);
		if (jIndex > -1 )  // student already in the list
		{
			jFound = true;
			tmpData->stdFname = arrUserProfile[jIndex].fname;
			tmpData->stdLname = arrUserProfile[jIndex].lname;
			tmpData->stdPass = arrUserProfile[jIndex].passWord;
			tmpData->stdGroupID = arrUserProfile[jIndex].groupID;
			cout << "\tStudent first name: " << tmpData->stdFname << endl;
			cout << "\t Student last name: " << tmpData->stdLname << endl;
			cout << "\t  Student password: " << tmpData->stdPass << endl;
			cout << "\t     Student group: " << tmpData->stdGroupID << endl;

		}else  // new student
		{
			cin.ignore();
			tmpData->stdFname = newNameFamily("Student first name");
			tmpData->stdLname = newNameFamily(" Student last name");
			tmpData->stdPass = strUserPass   ("Student password(alphanumeric)");
			tmpData->stdGroupID = chooseGroup(arrGroups, MAX);
		}
		
		chooseCourse(arrCourse, tmpData->stdGroupID ,MAX, tmpData);

		if (stdCrsDuplicate(arrStudentResult, tmpData->stdCourseID, tmpData->stdID, counter ) == true) // student already in the group
		{
			getStudentGrade(arrStudentResult, tmpData->tchID,tmpData->stdCourseID, tmpData->stdID);

			cout << "\t     Project grade: " << tmpData->stdProject << endl;
			cout << "\tMidtrem exam grade: " << tmpData->stdMidterm << endl;
			cout << "\t  Final exam grade: " << tmpData->stdFinal   << endl;
			cout << "\n\n\tPress any key to add another ID...";
			system("pause>nul");
		}else
		{
			cout << endl << endl;
			tmpData->stdProject = floatValue(100,"     Project grade");
			tmpData->stdMidterm = floatValue(100,"Midtrem exam grade");
			tmpData->stdFinal = floatValue  (100,"  Final exam grade");
						
			displayNewStudent(tmpData);

			if(myYesNo("Do you want to save this infromation") == 'Y')
			{
				saveStudentInfo(arrUserProfile, arrStudentResult, tmpData, counter);
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
	cout << "\n\t 7 digit ID number: ";
	while(!(cin >> newId ) || (newId < 1000000 || newId > 9999999) )
	{
		cout << "\n\tInavlid! Try again (7 digit number): ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}	
	return newId;
}
int chooseGroup(Groups arrGroups[], int MAX)
{
	cout << "\tStudent group: ";
	int i = 0;
	for ( i = 0; i < MAX; i++)
	{
		if (arrGroups[i].groupN > 0)
		{
			cout << "\n\t\t\t" << arrGroups[i].groupN << "." << arrGroups[i].groupID;
		}
		else
		{
			break;
		}
	}
	cout << "\tEnter group number: ";
	int choice = getMenuChoiceOK( i );

	return arrGroups[choice-1].groupID;
}
void chooseCourse(Course arrCourses[], int groupID, int MAX, Buffer *tmpData)
{
	cout << "\n\tSelect the course: ";

	string *arrTmpCourseID;
	string *arrTmpCourseTitle;
	arrTmpCourseID = new string[MAX];
	arrTmpCourseTitle = new string[MAX];
	int jCounter = 0;

	for ( int i = 0; i < MAX; i++)
	{
		if (arrCourses[i].courseN > 0) // prevent searching empty records
		{
			if (arrCourses[i].groupID == groupID)
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
	cin.ignore();
	tmpData->   stdCourseID =    arrTmpCourseID[choice - 1];
	tmpData->stdCourseTitle = arrTmpCourseTitle[choice - 1];

	delete [] arrTmpCourseID;
	delete [] arrTmpCourseTitle;

}
void saveStudentInfo(UserProfile arrUserProfile[], StudentResult arrStudentResult[], Buffer *tmpData,int &counter)
{
	arrUserProfile[counter].userID = tmpData->stdID ;
	arrUserProfile[counter].passWord = tmpData->stdPass ;
	arrUserProfile[counter].fname = tmpData->stdFname;
	arrUserProfile[counter].lname = tmpData->stdLname;
	arrUserProfile[counter].groupID = tmpData->stdGroupID;
	arrUserProfile[counter].tOrS = 's';

	arrStudentResult[counter].studentID = tmpData->stdID;
	arrStudentResult[counter].teacherID  = tmpData->tchID;         
	arrStudentResult[counter].groupID  = tmpData->stdGroupID;
	arrStudentResult[counter].courseID  = tmpData->stdCourseID ;
	arrStudentResult[counter].Project = tmpData->stdProject;
	arrStudentResult[counter].midtremExam = tmpData->stdMidterm;
	arrStudentResult[counter].finalExamExam = tmpData->stdFinal;

}


// Validation
int    checkIdDuplication(UserProfile arrUserProfile[], int &counter, int newID)  // need to be changed using pointer
{
	for (int i = 0; i < counter; i++)
	{
		if (arrUserProfile[i].userID == newID)
		{
			cout << "\t\t\t\t\tThis ID already exists!\n";
			return i;  // index of student in array arrUserProfile
		}
	}
	return -1;
}


bool   stdCrsDuplicate(StudentResult arrStudentResult[], string courseID, int studentID,int &counter)
{
		for (int i = 0; i < counter; i++)
	{
		if ((arrStudentResult[i].studentID == studentID) && (arrStudentResult[i].courseID == courseID))
		{
			//cout << "\n\n\tThis course is already registered for the student!\n";
			cout << "\n";
			return true;  // the course and student are duplicated
		}
	}
	return false;
}