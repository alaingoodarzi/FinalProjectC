#include<iostream>
#include<string>
#include<iomanip>
#include"myHeader.h"

#define NOMINMAX     // resolve the max() conflict on windows.h and limits libraries 
#include<windows.h>
#include <limits>
#include<ctype.h>


// I am looking for fare wage
// Clinical Reasearch Organization. JSS CRO Companey.(john sampalace)
// Wolf medical data,

using namespace std;
//******* for password

int mainMenu()
{
	system("cls");
	programTitle();
	int choice;

	const string TITLE="MAIN MENU";

	cout << "\n"
		<< setw(TITLE.length()/2 + 40) << TITLE ;

	cout << "\n\n\t" 
		 << "\n\t1.Teachers"
		 << "\n\t2.Students"
		 << "\n\t3.Quit";

	cout << "\n\n\tPlease select (1/3)? ";
	choice = getMenuChoiceOK(3);

	return choice;
}
int studentMenu()
{
	const string TITLE="STUDENT MENU";
	int choice = 0;

	system("cls");
	cout << "\n\n\n"
		<< setw(TITLE.length()/2 + 40) << TITLE ;

	cout << "\n\n\t" 
		<< "\n\t1.Courses list"
		<< "\n\t2.Grade for a given evaluation component"   //(Midterm Exam, Final Project or final Exam) related to a course he/she is taking in this session (Autumn 2015)"
		<< "\n\t3.Grades for a given course"
		<< "\n\t4.Exit";
	
	cout << "\n\n\tPlease select(1/4)? ";
	choice = getMenuChoiceOK(4);

	return choice;

}
int teacherMenu()
{

	int choice = 0;

	system("cls");
	const string TITLE="TEACHER MENU";
	cout << "\n\n\n"
		<< setw(TITLE.length()/2 + 40) << TITLE ;

	cout << "\n\n\t" 
		 << "\n\t1.Course list " 
		 << "\n\t2.Enter students’ grades for a given course"
		 << "\n\t3.Search a student’s grades"                // by Student ID/First Name/Last Name/First Name and Last Name"
		 << "\n\t4.Sort the student list by Student ID"
		 << "\n\t5.List all the students’ grades for a given course"
		 << "\n\t6.Exit";

	cout << "\n\n\tPlease select(1/6)? ";
	choice = getMenuChoiceOK(6);


	return choice;

}


int teacherGradeSearchMenu()
{

	int choice = 0;

	system("cls");
	const string TITLE="GRADE SEARCH MENU";
	cout << "\n\n\n"
		<< setw(TITLE.length()/2 + 40) << TITLE ;

	cout << "\n\n\t" 
		 << "\n\t1.By Student ID " 
		 << "\n\t2.By student first name"
		 << "\n\t3.By student last name"                // by Student ID/First Name/Last Name/First Name and Last Name"
		 << "\n\t4.BY stdent first and last name"
		 << "\n\t5.Exit";

	cout << "\n\n\tPlease select(1/5)? ";
	choice = getMenuChoiceOK(5);

	return choice;
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
// lab4 
// function:   myCout1 
// action:     This function displays a string with special effect
// argumnet:   text string, number of end lines after text, number of tabs befor text.
// returns:    none
// used by:    every where we use cout 
// created by: Alireza Goodarzi
// 
void myCout1(string myText, int noEndls, int noTabs)
{
	
	int charCounter = 0;
	charCounter = charCounter + myText.length();

	// for keeping cursor position of the console
	
	/* this part is got from an online referenc -BEGIN*/
	struct CurPos 
	{
		CurPos():x(-1),y(-1) {}
		int x, y;
		operator bool() const { return x >= 0 && y >= 0; }
	};

	CurPos pos;
    CONSOLE_SCREEN_BUFFER_INFO con;
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hcon != INVALID_HANDLE_VALUE &&
        GetConsoleScreenBufferInfo(hcon,&con)) 
    {
        pos.x = con.dwCursorPosition.X;
        pos.y = con.dwCursorPosition.Y;
    }
	/* this part is got from an online referenc END*/


	pos.x = noTabs*8;
	pos.y += noEndls;

	// dynamic arrays because the length of the text is not determined
	char *array = new char[charCounter];
	int     *x = new int[charCounter];


	int counter = 0;

		for (int j = 0; j < myText.length(); j++)
		{
			array[counter] = myText[j];
			x[counter++] = j;
		}

	
	// first effect random display of message characters
	// manipulating corsur position randomly in the range of text 	
	COORD coord;
	srand(time(0));
	for (int i = 0; i < 100; i++)
	{
		int jrand=rand() % charCounter ;
		coord.X = x[jrand]+pos.x;  //column
		coord.Y = pos.y;
		SetConsoleCursorPosition(
		GetStdHandle( STD_OUTPUT_HANDLE ),
		coord
		);
		
		cout << array[jrand]  ;
		
		Sleep(5);  // controls random character display speed 
	}


	// second effect, scrolling effect and completion the message text 	
	for (int i = 0; i < charCounter; i++)
	{
		coord.X = x[i]+pos.x;  //column
		coord.Y = pos.y;
		SetConsoleCursorPosition(
		GetStdHandle( STD_OUTPUT_HANDLE ),
		coord
		);
		
		cout << "  "  ;

		Sleep(10); // we can cotrol the text scroll effect speed here  
		SetConsoleCursorPosition(
		GetStdHandle( STD_OUTPUT_HANDLE ),
		coord
		);
		cout << array[i]  ;
	}

	delete array;
	delete x;
	return;
}
// lab4 
// function:   myMenu1 
// action:     This function displays a menu with special effects
// argumnet:   array pointer, 
//             array size, 
//             beginning line, 
//             beginning column, 
//             random char display speed in milliseconds, 
// returns:    none
// used by:    mainmenu()
// created by: Alireza Goodarzi
// 
void myMenu1(string *menuItems,int menuItemNumber, int beginLine, int beginCol,int lineBetween, int charDispSpeed, int horzantalScrolSpeed )
{



	//const int BEGIN_LINE = 2;
	//const int BEGIN_COL  = 20;

	//int menuItemNumber = sizeof(menuItems)/sizeof(string);
	int charCounter = 0;
	
	//
	for (int i = 0; i < menuItemNumber; i++)
	{
		charCounter = charCounter + menuItems[i].length();
	}
	
	//cout << charCounter;

	char *array = new char[charCounter];
	int     *x = new int[charCounter];
	int     *y = new int[charCounter];

	int counter = 0;
	for (int i = 0; i < menuItemNumber; i++)
	{
		for (int j = 0; j < menuItems[i].length(); j++)
		{
			array[counter] = menuItems[i][j];
			x[counter] = j;
			y[counter++] = i;
			//cout << menuItems[i][j] ;

		}
	}



	COORD coord;
	srand(time(0));
	for (int i = 0; i < 1000; i++)
	{
		int jrand=rand() % charCounter ;
		coord.X = x[jrand] + beginCol;  
		coord.Y = y[jrand] + beginLine;
		SetConsoleCursorPosition(
		GetStdHandle( STD_OUTPUT_HANDLE ),
		coord
		);
		
		cout << array[jrand]  ;
		
		Sleep(charDispSpeed);
	}

	for (int i = 0; i < charCounter; i++)
	{
		coord.X = x[i] + beginCol;  //column
		coord.Y = y[i] + beginLine;
		SetConsoleCursorPosition(
		GetStdHandle( STD_OUTPUT_HANDLE ),
		coord
		);
		
		cout << "   "  ;

		Sleep(horzantalScrolSpeed);
		SetConsoleCursorPosition(
		GetStdHandle( STD_OUTPUT_HANDLE ),
		coord
		);
			
		cout << array[i]  ;
	}

	

	delete array;
	delete x;
	delete y;

	coord.Y = coord.Y-2;
	coord.X = coord.X-18;
	SetConsoleCursorPosition(
	GetStdHandle( STD_OUTPUT_HANDLE ),
	coord
	);




	return;


}
