#include<iostream>
#include<string>
#include<iomanip>
#include"myHeader.h"
using namespace std;

void welcomePage()
{
	//Introduction
	//Development Process
		//Analysis
		//Design
		//Implementatio
		//Testing (form)
	//Conclusion
		//what learned
		//The worth issue spend more time in logic and coding
		//demo from exe file. with a plan


	system("cls");
	const string TITLE2="By";
	const string TITLE3="Alireza Goodarzi";
	const string TITLE4="LaSalle College";
	const string TITLE5="Automn 2015";
	const string TITLE6="Teacher";
	const string TITLE7="Quang Hoang Cao ";
	const string TITLE8="Press any key ...";


	programTitle();
	cout << setw(TITLE2.length()/2 + 40) << TITLE2 << endl  << endl; 
	cout << setw(TITLE3.length()/2 + 40) << TITLE3 << endl << endl << endl; 
	cout << setw(TITLE4.length()/2 + 40) << TITLE4 << endl ; 
	cout << setw(TITLE5.length()/2 + 40) << TITLE5 << endl << endl  << endl << endl; 
	cout << setw(TITLE6.length()/2 + 40) << TITLE6 << endl  << endl; 
	cout << setw(TITLE7.length()/2 + 40) << TITLE7 << endl << endl << endl << endl << endl; 
	cout << right << setw(74) << TITLE8 ; 

	system("pause > null");
}
void pageTitle(string title)
{
	//const string TITLE1="STUDENT GRADE SYSTEM";
	cout << endl
	     << setw(title.length()/2 + 40) << title 
		 << endl ;

}

void formTitle(string title, int &counter, int MAX)
{
	cout << endl
	     << "\n\t" << title << "(" <<  counter + 1  << "/" << MAX << "):"
		 << "\n\t" << string(title.length(),'=');
}

void middleText(string text)
{
	cout <<  setw(text.length()/2 + 40) << text;
}


void programTitle()
{
	const string TITLE1="STUDENTS GRADE DATA SYSTEM";
	cout << endl
	     << setw(TITLE1.length()/2 + 40) << TITLE1 
		 << endl ;
}

// lists UI design

void   listHeader(string listTitles[], int titleNumber)
{
	//system("cls");
	//programTitle();
	
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

string leftMarginSpace(string listTitles[], int titleNumber)
{
	int titleLength = 0;
	for (int i = 1; i < titleNumber; i++)   // from 1 because index 0 is table title
	{
		titleLength += listTitles[i].length() + 2;
	}
	int titleLeftSpace = 40 - titleLength /2 ;
	string leftMargin = "";
	for (int i = 0; i < titleLeftSpace/2; i++)
	{
		leftMargin = leftMargin + ' ' ;
	}
	return leftMargin;
}
void   titleLength(int titleLenghts[], string listTitles[])
{
	for (int i = 0; i < 4; i++)
	{
		titleLenghts[i] = listTitles[i].length();
	}
}