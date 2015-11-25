#include<iostream>
#include<string>
#include<iomanip>
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


int teacherOperations(int MAX, int &counter, UserProfile arrUserProfile[], Course arrCourse[], Buffer tmpData)
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
			system("pause");
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

void initialValues(UserProfile arrUserProfile[],Groups arrGroups[],Course arrCourses[], int MAX, Buffer tmpData)
//void initValues(UserProfile arrUserProfile[])
{

	arrUserProfile[0].userID   = 5257;
	arrUserProfile[0].passWord = "quanghoang";
	arrUserProfile[0].fname    = "Quang Hoang";
	arrUserProfile[0].lname    = "Cao";
	arrUserProfile[0].tOrS     = 't';
	for (int i = 1; i < MAX; i++)
	{
		arrUserProfile[i].userID = 0;
	}


	//temp
	tmpData.tchID = arrUserProfile[0].userID;
	tmpData.tchLname = arrUserProfile[0].lname;
	tmpData.tchFname = arrUserProfile[0].fname;





	arrGroups[0].groupN = 1;
	arrGroups[0].groupID = 7148;
	arrGroups[1].groupN = 2;
	arrGroups[1].groupID = 7150;
	arrGroups[2].groupN = 3;
	arrGroups[2].groupID = 7151;
	arrGroups[3].groupN = 4;
	arrGroups[3].groupID = 7256;
	for (int i = 4; i < MAX; i++)
	{
		arrGroups[i].groupN = 0;
	}


	arrCourses[0].courseN = 1;
	arrCourses[0].courseID = "420-P16-AS";
	arrCourses[0].courseTitle = "Structured Programming";
	arrCourses[0].teacherID = 5257;
	arrCourses[0].group = 7148;

	arrCourses[1].courseN = 2;
	arrCourses[1].courseID = "420-P16-AS";
	arrCourses[1].courseTitle = "Structured Programming";
	arrCourses[1].teacherID = 5257;
	arrCourses[1].group = 7150;

	arrCourses[2].courseN = 3;
	arrCourses[2].courseID = "420-P16-AS";
	arrCourses[2].courseTitle = "Introduction à la programmation structurée";
	arrCourses[2].teacherID = 5257;
	arrCourses[2].group = 7151;

	arrCourses[3].courseN = 4;
	arrCourses[3].courseID = "420-P34-AS";
	arrCourses[3].courseTitle = "Advanced Object Programming";
	arrCourses[3].teacherID = 5257;
	arrCourses[3].group = 7256;
	for (int i = 4; i < MAX; i++)
	{
		arrCourses[i].courseN = 0;
	}

}


int teacherCourses( Course arrCourses[], Buffer tmpData)
{
	string titles[] = {
						"TEACHER COURSE LIST",
						"Number          ",
						"Title                                          ",
						"Group     "
						};
	listHeader(titles,4);
	int counter = 0;
	while (arrCourses[counter].courseN != 0)
	{
		cout << 
		if (arrCourses[counter].teacherID == tmpData.tchID)
		{
			cout << arrCourses[counter].courseID << arrCourses[counter].courseTitle << arrCourses[counter].group << endl;
			counter++;
		}

	}
	return 0;
}

void listHeader(string listTitles[], int titleNumber)
{
	system("cls");
	programTitle();
	string leftMargin = leftMarginSpace(listTitles,titleNumber);
	cout << endl << setw(listTitles[0].length()/2 + 40) << listTitles[0] << endl ;
	cout << "\n" << leftMargin;	
	for (int i = 1; i < titleNumber; i++)  // from 1 because index 0 is table title
	{
		cout <<  setw( listTitles[i].length() + 2) << listTitles[i];
	}
	cout << "\n" << leftMargin ;

	
	for (int i = 1; i < titleNumber; i++)
	{
		cout <<  setw( listTitles[i].length() + 2) << string(listTitles[i].length(), '=') ;
	}
	cout << "\n";				

}




//void listRecord(string tmp, int index)
//{
//
//	cout << right << setw(   HEDER_STD_ID.length()+10) << studentList[index].id << "   "
//		 << left << setw(HEDER_STD_FNAME.length()+10) << studentList[index].firstName  
//		 << left << setw(HEDER_STD_LNAME.length()+10) << studentList[index].lastName << "\n"; 
//}



string leftMarginSpace(string listTitles[], int titleNumber)
{
	int titleLength = 0;
	for (int i = 1; i < titleNumber; i++)   // from 1 because index 0 is table title
	{
		titleLength += listTitles[i].length() + 2;
	}
	int titleLeftSpace = 40 - titleLength /2 ;
	string leftMargin = "";
	for (int i = 0; i < titleLeftSpace; i++)
	{
		leftMargin = leftMargin + ' ' ;
	}
	return leftMargin;
}