#include<iostream>
#include<string>
#include <conio.h>
#include <regex>
#include <sstream>
#include"myHeader.h"

using namespace std;


char getMenuChoiceOK(int maxMenuNumber)
{
	char choice;
	while(true)
	{
		choice = _getch();
		cout <<  choice;
		if ( ((int) choice > 48   && (int) choice <= maxMenuNumber + 48 ) )
		{
			return (int) choice - 48;
		}
		cout << "\n\tInavlide!Try again : ";
	}
}


int intValue(int maxNumber, string message)
{
	 const regex REGEX_ONLYNUMBERS("^[0-9]*$");
	 string number;
	 cout << "\n\t" << message << " (" << maxNumber << " digits): ";
	 do
	 {
		getline(cin,number);
		
		if (number.length() == maxNumber  &&  regex_match(number, REGEX_ONLYNUMBERS))
		{
			int intNumber;
			istringstream ( number ) >> intNumber;
			return intNumber;
        }
        else
        {
            cout << "\n\tInvalid entry!\n\t" << message << " (" << maxNumber << " digits): ";
        }
	}while(true);
}


string strValue(string message)
{
	 const regex REGEX("^[a-zA-Z ]*$");
	 string jString;
	 cout << "\n\t" << message << ": ";
	 do
	 {
		 getline(cin,jString);
		
		if (regex_match(jString, REGEX))
		{	
			return jString;
        }
        else
        {
            cout << "\n\tInvalid entry!\n\t" << message << " : ";
        }
	}while(true);
}

string strUserPass(string message)
{
	 const regex REGEX("^[a-zA-Z1-9]*$");
	 string jString;
	 cout << "\n\t" << message << ": ";
	 do
	 {

		 getline(cin,jString);
		
		if (regex_match(jString, REGEX))
		{	
			return jString;
        }
        else
        {
            cout << "\n\tSpace and non-alphanumeric is not allowed !\n\t" << message << " : ";
        }
	}while(true);
}


string firstLettersCapital(string str)
{
	str[0] = toupper(str[0]);
	bool spaceOccurance = false;
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			if (spaceOccurance ==  false)
			{
				str[i] = tolower(str[i]);
			}
			else
			{
				str[i] = toupper(str[i]);
				spaceOccurance =  false;
			}
		}
		else
		{
			spaceOccurance =  true;
		}
	}
	return str;
}


string removeExcessSpace(string str)
{
	string jStr = str;
	bool oneSpace = false;
	int index = 0;
	if (str[0] == ' ')
	{
		oneSpace = true;

	}
	
	for (int i = 0; i < str.length(); i++)
	{
		if (oneSpace == false )//    dc  vvv
		{
			jStr[index] = str[i];
			index++;
			if (str[i] == ' ')
			{
				oneSpace = true;
			}
		}
		else
		{
			if (str[i] != ' ')
			{
				oneSpace = false;
				jStr[index] = str[i];
				index++;
			}
		}
	}
	for (int i = index; i < str.length(); i++)
	{
		jStr[i] = ' ';
	}
	return jStr;
}


string shortenString(string str,int length)
{
	if (str.length() > length)
	{
		str = str.substr(0,length-3);
	}
	return str + "...";
}

char myYesNo(string message)
{
	char choice;
	cout << "\n\n\t" << message << "(y/n)?";
	while(true)
	{
		choice = _getch();
		if ( toupper (choice) == 'Y' || toupper (choice) == 'N' )
		{
			return toupper (choice);
		}
	}
}

char exitByCTRLX()
{
		char choice;
	cout << "\n\t" << "Enter" << "(y/n)?";
	while(true)
	{
		choice = _getch();
		if ( toupper (choice) == 'X'  )
		{
			return toupper (choice);
		}
		cout << (int) choice;
	}
}

int exitPrompt(string message, int exitValue)
{
	if (myYesNo("Are you sure you want to exit program?") == 'Y')
	{
		//goodByPage();
		return exitValue;
	}else
	{
		return 0;
	}
}

int checkIdDuplication(UserProfile arrUserProfile[], int &counter, int newID)  // need to be changed using pointer
{
	for (int i = 0; i < counter; i++)
	{
		if (arrUserProfile[i].userID == newID)
		{
			cout << "\n\tTHis student already exists in the list!";
			return i;  // index of student in array arrUserProfile
		}
	}
	return 0;
}

bool stdCrsDuplicate(StudentResult arrStudentResult[], string courseID, int studentID,int &counter)
{
		for (int i = 0; i < counter; i++)
	{
		if ((arrStudentResult[i].studentID == studentID) && (arrStudentResult[i].courseID == courseID))
		{
			cout << "\n\tTHis course is already registered for the student!";
			return true;  // the course and student are duplicated
		}
	}
	return false;
}