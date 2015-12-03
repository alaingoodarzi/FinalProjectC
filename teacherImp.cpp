#include<iostream>
#include<string>
#include<iomanip>
#include"myHeader.h"
// document to mr Cao :  what you learned from the project


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
			//"Search student grade";
			teacherSearchGradeOperation(arrUserProfile, arrStudentResult, arrCourse, tmpData, counter, MAX);
			break;
		case 4 :
			// "Sort Student list by ID";
			sortStudentList(arrUserProfile,counter,tmpData);
			break;
		case 5 :
			// "List all the students’ grades for a given course";
			courseGradeList(arrStudentResult, arrGroups, arrCourse, arrUserProfile, tmpData, counter, MAX);
			break;

		case 6 :
			//choice = exitPrompt("Are you sure you want to reurn to main menu",6);
			break;
		default :
			break;
		}
		//system("pause>null");

	}while(choice != 6);

	return 0;

}
int teacherCourses( Course arrCourses[], Buffer *tmpData)
{
	system("cls");
	cout << "\n\n\n";
	int    titleLengths[4];
	string listTitles[4] = {
						"TEACHER COURSE LIST",
						"Number    ",
						"Title                                       ",
						"Group  "
						};
	titleLength(titleLengths, listTitles);
	listHeader(listTitles,4);
	teacherCoursList(arrCourses, listTitles, titleLengths, tmpData );
	return 0;
}
int addStudentGrade(UserProfile arrUserProfile[], Course arrCourse[], Groups arrGroups[], StudentResult arrStudentResult[], Buffer *tmpData ,int MAX, int &counter)
{

	
	
	do
	{
		system("cls");
		pageTitle("STUDENT GRADE FORM");
		formTitle("Please Enter student information", counter, MAX);

		
		if (searchUser(arrUserProfile, tmpData, counter) > -1) //found
		{
			cout << "\tStudent first name: " << tmpData->stdFname   << endl;
			cout << "\t Student last name: " << tmpData->stdLname   << endl;
			cout << "\t  Student password: " << tmpData->stdPass    << endl;
			cout << "\t     Student group: " << tmpData->stdGroupID << endl;

		}else  // new student
		{
			//cin.ignore();
			tmpData->stdFname = newNameFamily("Student first name");
			tmpData->stdLname = newNameFamily(" Student last name");
			tmpData->stdPass = hiddenPassPhrase ("Student password(alphanumeric)", 's');
			tmpData->stdGroupID = chooseGroup(arrGroups, MAX);
		}
		
		chooseCourse(arrCourse, MAX, tmpData);

		if (stdCrsDuplicate(arrStudentResult, tmpData->stdCourseID, tmpData->stdID, counter ) == true) // student already in the group
		{
			getStudentGrade(arrStudentResult, tmpData, counter);

			
			
			cout << "\t     Project grade: " << tmpData->stdProject << endl;
			cout << "\tMidtrem exam grade: " << tmpData->stdMidterm << endl;
			cout << "\t  Final exam grade: " << tmpData->stdFinal   << endl;
			cout << "\n\n\tPress any key to continue...";
			//system("pause>nul");
			break;
		}else
		{
			cout << endl << endl;
			tmpData->stdProject = floatValue(100,"     Project grade");
			tmpData->stdMidterm = floatValue(100,"Midtrem exam grade");
			tmpData->stdFinal = floatValue  (100,"  Final exam grade");
						
			displayNewStudent(tmpData);

			if(myYesNo("Do you want to save this infromation") == 'Y')
			{
				if (counter == MAX)
					{
						cout << "\n\tThe capacity of list is full!";
						return 0;
					}
				saveStudentInfo(arrUserProfile, arrStudentResult, tmpData, counter);
				counter++;
			}
		}
	} while (counter < MAX);
}
//if user exists, returnd true, sets tmpData if no returm false
//bool getUserProfile(UserProfile arrUserProfile[],Buffer *tmpData , int &counter, int userID)
//{
//	bool jFound = false;
//	int jIndex = 0;
//	jIndex = checkIdDuplication(arrUserProfile, counter, userID);
//	if (jIndex > -1 )  // student already in the list
//	{
//		jFound = true;
//		tmpData->stdID = arrUserProfile[jIndex].userID;
//		tmpData->stdFname = arrUserProfile[jIndex].fname;
//		tmpData->stdLname = arrUserProfile[jIndex].lname;
//		tmpData->stdPass = arrUserProfile[jIndex].passWord;
//		tmpData->stdGroupID = arrUserProfile[jIndex].groupID;
//		//cout << "\tStudent first name: " << tmpData->stdFname << endl;
//		//cout << "\t Student last name: " << tmpData->stdLname << endl;
//		//cout << "\t  Student password: " << tmpData->stdPass << endl;
//		//cout << "\t     Student group: " << tmpData->stdGroupID << endl;
//		return true;
//	}else  // new student
//	{
//		return false;
//	}
//}
void getStudentGrade(StudentResult arrStudentResult[], Buffer *tmpData, int &counter)
{
	bool found = false;
	for (int i = 0; i < counter; i++)
	{
		if (arrStudentResult[i].studentID == tmpData->stdID)
		{
			for (int j = i; j < counter; j++)
			{
				if (arrStudentResult[j].courseID == tmpData->stdCourseID)
				{
					tmpData->stdProject = arrStudentResult[j].Project;
					tmpData->stdMidterm = arrStudentResult[j].midtremExam;
					tmpData->stdFinal = arrStudentResult[j].finalExam; 
					found = true;
				}
				if (found == true)
				{
					break;
				}
			}
			if (found == true)
			{
				break;
			}
		}
	}
}
//int newStdID(UserProfile arrUserProfile[], int &counter, int MAX) //
//{
//	int newId = 0;
//	cout << "\n\t 7 digit ID number: ";
//	while(!(cin >> newId ) || (newId < 1000000 || newId > 9999999) )
//	{
//		cout << "\n\tInavlid! Try again (7 digit number): ";
//		cin.clear();
//		cin.ignore(numeric_limits<streamsize>::max(),'\n');
//	}	
//	return newId;
//}
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
void chooseCourse(Course arrCourses[], int MAX, Buffer *tmpData)
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
	arrStudentResult[counter].finalExam = tmpData->stdFinal;

}
// Validation
int  checkIdDuplication(UserProfile arrUserProfile[], int &counter, int newID)  // need to be changed using pointer
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
bool stdCrsDuplicate(StudentResult arrStudentResult[], string courseID, int studentID,int &counter)
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
void teacherSearchGradeOperation(UserProfile arrUserProfile[], StudentResult arrStudentResult[], Course arrCourse[], Buffer *tmpData, int &counter, int MAX)
{	
	int choice = 0 ;
	do
	{
		choice = teacherGradeSearchMenu();
		switch(choice)
		{
		case 1 :
			if (searchUser(arrUserProfile,tmpData, counter) == -1)
			{
				pausePrompt("This ID in not in the list!");
			}else
			{
				chooseCourse(arrCourse, MAX, tmpData);
				gradeList(arrStudentResult, tmpData, counter);
			}
			break;
			pausePrompt("Press any key to return to menu....");
		case 2 :
			//searchGradeByName('f');
			if (searchUser(arrUserProfile, tmpData, counter, 'f') == -1)
			{
				pausePrompt("This name in not in the list!");
			}else
			{
				chooseCourse(arrCourse, MAX, tmpData);
				gradeList(arrStudentResult, tmpData, counter);
			}
			break;
			pausePrompt("Press any key to return to menu....");
		case 3 :
			//searchGradeByName('l');
						
			if (searchUser(arrUserProfile, tmpData, counter, 'l') == -1)
			{
				pausePrompt("This name in not in the list!");
			}else
			{
				chooseCourse(arrCourse, MAX, tmpData);
				gradeList(arrStudentResult, tmpData, counter);
			}
			break;
			pausePrompt("Press any key to return to menu....");
		case 4 :
			//serchGradeByName("fl");
						//searchGradeByName('f');
			if (searchUser(arrUserProfile, tmpData, counter, "fl") == -1)
			{
				pausePrompt("This name in not in the list!");
			}else
			{
				chooseCourse(arrCourse, MAX, tmpData);
				gradeList(arrStudentResult, tmpData, counter);
			}
			break;
			pausePrompt("Press any key to return to menu....");
		case 5 :
			//choice = exitPrompt("Are you sure you want to reurn to previous menu",5);
			break;
		default :
			break;
		}
		
	}while(choice != 5);

}
void gradeList(StudentResult arrStudentResult[], Buffer *tmpData, int &counter)
{
	system("cls");
	programTitle();
	cout << "\n\n";
	//("pause");
	middleText("Course Number: " + tmpData->stdCourseID + "\n" );
	middleText("Course Title: " + tmpData->stdCourseTitle + "\n" );
	middleText("Instructor: " + tmpData->tchFname + " " + tmpData->tchLname + "\n" );
	middleText("Session: Automn 2015\n" );
	middleText("Group: " + to_string(tmpData->stdGroupID) + "\n" );

	string listTitles[] = {"ASSESSMENT SUMMERY",
							"Student ID",
							"Student Name       ",
							"project",
							"Midterm",
							"Final Exam",
							"Final Result"};
	listHeader(listTitles, 7);
	string leftMargin = leftMarginSpace(listTitles,7);

	for (int i = 0; i < counter; i++)
	{
		if (arrStudentResult [i].studentID == tmpData->stdID && arrStudentResult [i].courseID == tmpData->stdCourseID)
		{
			string fullName = tmpData->stdLname + "," + tmpData->stdFname;
			cout << leftMargin 
				 << setw( listTitles[1].length() + 2)  << tmpData->stdID << "  "
				 << left << setw( listTitles[2].length() + 2)  << fullName
				 << right << setw( listTitles[3].length() )  << arrStudentResult[i].Project
				 << setw( listTitles[4].length() )  << arrStudentResult[i].midtremExam
				 << setw( listTitles[5].length() )  << arrStudentResult[i].finalExam
				 << setw( listTitles[6].length() )  << finalResult(arrStudentResult[i].Project, arrStudentResult[i].midtremExam,arrStudentResult[i].finalExam) << endl;
		}
	}


	pausePrompt("Press any key to return to teachers menu....");
	
}
void teacherCoursList(Course arrCourses[], string listTitles[],int titleLenghts[],  Buffer *tmpData )
{
	string leftMargin = leftMarginSpace(listTitles,4);
	int counter = 0;
	while (arrCourses[counter].courseN != 0 )
	{
		if (arrCourses[counter].teacherID == tmpData->tchID)
		{
			cout <<left << leftMargin << "  "
				 << setw( titleLenghts[1] + 2)  << arrCourses[counter].courseID
				 << setw( titleLenghts[2] + 2)  << arrCourses[counter].courseTitle
				 << setw( titleLenghts[3] + 2)  << arrCourses[counter].groupID << endl;
			counter++;
		}

	}
	cout << right;
}
int  finalResult(float project, float midTerm, float finalExam)
{
	const float PROJECT_WEIGHT   = 0.3f;     //30%
	const float MIDTERM_WEIGHT   = 0.3f;     //30%
	const float FINALEXAM_WEIGHT = 0.4f;     //40%

	return floor((project * PROJECT_WEIGHT + midTerm * MIDTERM_WEIGHT + finalExam * FINALEXAM_WEIGHT)  + 0.5 );
}
void courseGradeList(StudentResult arrStudentResult[], Groups arrGroups[], Course arrCourse[], UserProfile arrUserProfile[], Buffer *tmpData, int counter, int MAX)
{
	
	if(tmpData->currentTorS == 't')  // for use in teacher menu 5. the group of student is already determined
	{
		tmpData->stdGroupID = chooseGroup(arrGroups, MAX);
	}else
	{
		cout << tmpData->stdGroupID << endl;
	}
	chooseCourse(arrCourse, MAX, tmpData);
	system("cls");
	
	cout << "\n\n\n\n\n";
	middleText("Course Number: " + tmpData->stdCourseID + "\n" );
	middleText("Course Title: " + tmpData->stdCourseTitle + "\n" );
	middleText("Instructor: " + tmpData->tchFname + " " + tmpData->tchLname + "\n" );
	middleText("Session: Automn 2015\n" );
	middleText("Group: " + to_string(tmpData->stdGroupID) + "\n" );

	string listTitles[] = {"ASSESSMENT SUMMERY",
							"Student ID",
							"Student Name       ",
							"project",
							"Midterm",
							"Final Exam",
							"Final Result"};
	listHeader(listTitles, 7);
	string leftMargin = leftMarginSpace(listTitles,7);

	int nPassed = 0;
	int nFailed = 0;

	for (int i = 0; i < counter; i++)
	{
		if (arrStudentResult [i].courseID == tmpData->stdCourseID)
		{
			string fullName = getFullName(arrUserProfile, arrStudentResult[i].studentID, MAX);
			float finalRes = 0.0f;
			finalRes = finalResult(arrStudentResult[i].Project, arrStudentResult[i].midtremExam,arrStudentResult[i].finalExam);
			if (finalRes>= 60)
			{
				nPassed++;
			}
			else
			{
				nFailed++;
			}
			cout << leftMargin 
				 << setw( listTitles[1].length() + 2)  << arrStudentResult[i].studentID << "  "
				 << left << setw( listTitles[2].length() + 2)  << fullName
				 << right << setw( listTitles[3].length() )  << arrStudentResult[i].Project
				 << setw( listTitles[4].length() )  << arrStudentResult[i].midtremExam
				 << setw( listTitles[5].length() )  << arrStudentResult[i].finalExam
				 << setw( listTitles[6].length() )  << finalRes << endl;
		}
	}
	cout << "\n\n\tNumber of students who passed the course: " << nPassed << endl << endl;
	cout << "\tNumber of students who failed the course: " << nFailed << endl;
	pausePrompt("Press any key to return to teahcers menu....");
	
}
string getFullName(UserProfile arrUserProfile[], int studentID, int MAX)
{
	for (int i = 0; i < MAX; i++)
	{
		if(arrUserProfile[i].userID == studentID)
		{
			return arrUserProfile[i].lname + "," + arrUserProfile[i].fname;
		}
	}
	return "";
}
void sortStudentList(UserProfile arrUserProfile[],int counter, Buffer *tmpData)
{
	int *arrSortedStdId;
	arrSortedStdId = new int[counter];
	for (int i = 0; i < counter  ; i++)
	{
			arrSortedStdId[i] = arrUserProfile[i].userID;
	}

	for (int i = 0; i < counter -1 ; i++)
	{
		for (int j = i+1; j < counter; j++)
		{
			if (arrSortedStdId[i] < arrSortedStdId[j])
			{
				int jSwap = 0;
				jSwap = arrSortedStdId[i];
				arrSortedStdId[i] = arrSortedStdId[j];
				arrSortedStdId[j] = jSwap;
			}
		}
	}


	courseStudentList(arrUserProfile, counter, arrSortedStdId, tmpData );
	
	delete [] arrSortedStdId;

}
void courseStudentList(UserProfile arrUserProfile[], int counter, int arrSortedStdId[], Buffer *tmpData)
{
	string listTitles[] = {"STUDENT LIST",
							"ID      ",
							"first name              ",
							"last name               ",
							"Group  "};
	listHeader(listTitles, 5);
	string leftMargin = leftMarginSpace(listTitles,5);

	for (int i = 0; i < counter; i++)
	{
		getStudentRecord(arrUserProfile, tmpData, arrSortedStdId[i], counter);
		if(tmpData->tOrS == 's')
		{
			cout << leftMargin 
				 << setw( listTitles[1].length() + 2)          << tmpData->stdID << "  "
				 << left << setw( listTitles[2].length() + 2)  << tmpData->stdFname
				 << setw( listTitles[3].length() + 2)          << tmpData->stdLname
				 << right << setw( listTitles[4].length())     << tmpData->stdGroup << endl;
		}
	}
	pausePrompt("Press any key to return to teahcers menu....");
} 
void getStudentRecord(UserProfile arrUserProfile[], Buffer *tmpData, int stdId, int &counter)
{
	for (int i = 0; i < counter; i++)
	{
		if (arrUserProfile[i].userID == stdId)
		{
			tmpData->stdGroup = arrUserProfile[i].groupID;
			tmpData->stdID = arrUserProfile[i].userID;
			tmpData->stdFname = arrUserProfile[i].fname;
			tmpData->stdLname = arrUserProfile[i].lname;
			tmpData->tOrS = arrUserProfile[i].tOrS;
			break;
		}
	}
}

