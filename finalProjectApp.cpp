
//This program could temporarily keep information about a teacher and his/her students who could be part a group and choose several courses from the course list that's available in that group.
//the program name is STUDENTS GRADE DATA SYSTEM
//
//By: Alireza Goodarzi
//ID: 1310670
//
//	I analyzed and designed the program to be reusable and dynamic as far as possible.
//Part of this aim could be seen in data structure design. The structure variables that keep 
//the data mimicked the tables of a database and using common variables inside structures mimic
//primary and foreign keys as possible. A good result of this design is that we could easily 
//add more teachers, groups, courses and students without any changes in the data structure.
//At the same time it is almost ready to use a real database system, replacing data structures 
//with tables and their field.
//
//In order to simplify the passage of arguments and avoid using global variables and unsecure coding, 
//and temporary data structure is implemented in program, named Buffer, that keeps some essential 
//information like active user's user ID and type of user as teacher or student.
//
//Handling several structures and passing their reference as an argument was a big challenge in this program.
//
//In order to provide assistance and save time for program test, I already added 5 students 
//as default and users can add 4 more students to check the functionality of the program. To add more 
//student user could increase the MAX variable in main () function of finalProjetcApp.cpp file.
//
//For verification of default student list, please check initialValues () function in operationImp.cpp file.

#include<iostream>
#include<string>
#include"myHeader.h"
using namespace std;

int main()
{
	const int MAX = 10;
	int counter = 0;
	UserProfile arrUserProfile[MAX];
	Course arrCourses[MAX];
	Groups arrGroups[MAX];
	StudentResult arrStudentResults[MAX];
	Buffer tmpData;
	welcomePage();
	initialValues(arrUserProfile, arrGroups, arrCourses, MAX, &tmpData, counter, arrStudentResults);
	int choice = 0;
	if (userPass(arrUserProfile, &tmpData, counter) == false)
		{
			return -1;
		}
	do
	{

		choice = mainMenu();
		switch(choice)
		{
			case 1 :
				if(tmpData.currentTorS == 't' )
				{
					teacherOperations(MAX,counter,arrUserProfile,arrCourses,arrGroups,arrStudentResults,&tmpData);
				}else
				{
					middleText("\n\n\tYou have no right to enter this part of program !");
					system("pause>nul");
				}
				break;
			case 2 :
				studentOperation(arrStudentResults, arrGroups, arrCourses, arrUserProfile, &tmpData, counter, MAX);
				break;
			case 3 :
				
				if (exitPrompt("Are you sure you want to exit program",3) == 3)
				{
					system("cls");
					myCout1("Thank you for using my project.  Good Buy!",10,2);
					
					system("pause>nul");
				}
				else
				{
					choice = 0;
				}
				break;
			default :
				break;
		}
	}while(choice != 3);
	
	return 1;
}
