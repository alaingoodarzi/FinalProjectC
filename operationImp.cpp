#include<iostream>
#include<string>
#include<iomanip>
#include"myHeader.h"

void initialValues(UserProfile arrUserProfile[],Groups arrGroups[],Course arrCourses[], int MAX, Buffer *tmpData)
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
	tmpData->tchID = arrUserProfile[0].userID;
	tmpData->tchLname = arrUserProfile[0].lname;
	tmpData->tchFname = arrUserProfile[0].fname;





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
	arrCourses[0].groupID = 7148;

	arrCourses[1].courseN = 2;
	arrCourses[1].courseID = "420-P16-AS";
	arrCourses[1].courseTitle = "Structured Programming";
	arrCourses[1].teacherID = 5257;
	arrCourses[1].groupID = 7150;

	arrCourses[2].courseN = 3;
	arrCourses[2].courseID = "420-P16-AS";
	arrCourses[2].courseTitle = "Introduction à la programmation structurée";
	arrCourses[2].teacherID = 5257;
	arrCourses[2].groupID = 7151;

	arrCourses[3].courseN = 4;
	arrCourses[3].courseID = "420-P34-AS";
	arrCourses[3].courseTitle = "Advanced Object Programming";
	arrCourses[3].teacherID = 5257;
	arrCourses[3].groupID = 7256;
	for (int i = 4; i < MAX; i++)
	{
		arrCourses[i].courseN = 0;
	}

}


//List design and display functions
void listHeader(string listTitles[], int titleNumber, int titleLenghts[])
{
	system("cls");
	programTitle();
	
	cout << endl << setw(listTitles[0].length()/2 + 40) << listTitles[0] << endl ;

	string leftMargin = leftMarginSpace(listTitles,titleNumber);
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
void listRecord(Course arrCourses[], string listTitles[],int titleLenghts[],  Buffer *tmpData )
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
void titleLength(int titleLenghts[], string listTitles[])
{
	for (int i = 0; i < 4; i++)
	{
		titleLenghts[i] = listTitles[i].length();
	}
}

string newNameFamily(string prompt)
{
	string jName= strValue(prompt);
	jName = removeExcessSpace(jName);
	jName = firstLettersCapital(jName);
	return jName;
}