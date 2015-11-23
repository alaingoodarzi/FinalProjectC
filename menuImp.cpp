#include<iostream>
#include<string>
#include<iomanip>
#include"myHeader.h"
using namespace std;
//******* for password

int mainMenu()
{

	system("cls");
	programTitle();

	const string TITLE="MAIN MENU";

	cout << "\n\n\n"
		<< setw(TITLE.length()/2 + 40) << TITLE ;
	cout << "\n\n\t" 
		 << "\n\t 1.Teachers"
		 << "\n\t 2.Students"
		 << "\n\t Q.Quit";

	
	cout << "\n\n\n\n\t";
	system("pause");


	return 0;

}

int studentMenu()
{
	system("cls");
	const string TITLE="STUDENT MENU";
	cout << "\n\n\n"
		<< setw(TITLE.length()/2 + 40) << TITLE ;
	cout << "\n\n\t" 
		 << "\n\t 1. Courses list"
		 << "\n\t 2. Grade for a given evaluation component"   //(Midterm Exam, Final Project or final Exam) related to a course he/she is taking in this session (Autumn 2015)"
		 << "\n\t 3. Grades for a given course"
		 << "\n\t 4. Exit";
	cout << "\n\n\n\n\t";
	system("pause");


	return 0;

}


int teacherMenu()
{
	system("cls");
	const string TITLE="TEACHER MENU";
	cout << "\n\n\n"
		<< setw(TITLE.length()/2 + 40) << TITLE ;
	cout << "\n\n\t" 
		 << "\n\t 1. Course list " 
		 << "\n\t 2. Enter students’ grades for a given course"
		 << "\n\t 3. Search a student’s grades"                // by Student ID/First Name/Last Name/First Name and Last Name"
		 << "\n\t 3. Sort the student list by Student ID"
		 << "\n\t 4. List all the students’ grades for a given course"
		 << "\n\t Q. Exit";

	cout << "\n\n\n\n\t";
	system("pause");


	return 0;

}

void welcomePage()
{
	system("cls");
	const string TITLE2="By";
	const string TITLE3="Alireza Goodarzi";
	const string TITLE4="LaSalle College";
	const string TITLE5="Automn 2015";
	const string TITLE6="Teacher";
	const string TITLE7="Quang Hoang Cao ";
	const string TITLE8="press any key to enter the program...";


	programTitle();
	cout << setw(TITLE2.length()/2 + 40) << TITLE2 << endl; 
	cout << setw(TITLE3.length()/2 + 40) << TITLE3 << endl << endl << endl; 
	cout << setw(TITLE4.length()/2 + 40) << TITLE4 << endl ; 
	cout << setw(TITLE5.length()/2 + 40) << TITLE5 << endl << endl  << endl << endl; 
	cout << setw(TITLE6.length()/2 + 40) << TITLE6 << endl; 
	cout << setw(TITLE7.length()/2 + 40) << TITLE7 << endl << endl << endl << endl; 
	cout << setw(TITLE8.length()/2 + 40) << TITLE8 << endl; 

	//cout << "\n\n";
	system("pause > null");
}


void programTitle()
{
	const string TITLE1="STUDENT GRADE SYSTEM";
	cout << "\n\n\n";
	cout << setw(TITLE1.length()/2 + 40) << TITLE1 << endl << endl;
	cout << "\n\n";
}

//int mainMenuLater()
//{
//		int choice = 0;
//	do
//	{
//		system("cls");
//		string	menuItems[] = {	"        TTTTTTTTTT  TTT", 
//							"1. Teachers", 
//							"2. Students" ,
//							"3. Quit",
//							"                        ",
//							"Enter your choice? "
//							};
//	// argumnet:   array pointer, 
//	//             array size, 
//	//             beginning line, 
//	//             beginning column, 
//	//             random char display speed in milliseconds, 
//	//             horizontal scroll speed in milliseconds
//		myMenu1(menuItems,sizeof(menuItems)/sizeof(string),5,20,1,2,5);
//
//	
//		cin >> choice;  // user's choice
//		cin.clear();
//		cin.ignore(numeric_limits<streamsize>::max(),'\n');
//	
//	} while(!evaluateMenuChoice(choice,2));
//
//	return choice;
//}
