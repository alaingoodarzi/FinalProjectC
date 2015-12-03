#include<iostream>
#include<string>
#include <conio.h>
#include <regex>
#include <sstream>
#include"myHeader.h"
using namespace std;


// General Validation functions
char   getMenuChoiceOK(int maxMenuNumber)
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
int    intValue(int maxNumber, string message)
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
float  floatValue(int maxNumber, string message)
{
	 const regex REGEX_ONLYNUMBERS("^[0-9.]*$");
	 string number;
	 cout << "\t" << message << " (" << maxNumber << " maximum): ";
	 do
	 {
		getline(cin,number);
		
		if (number.length() > 0 && regex_match(number, REGEX_ONLYNUMBERS))
		{
			float jNumber;
			istringstream ( number ) >> jNumber;
			if(jNumber <= 100)
			{
				return jNumber;
			}else
			{
				cout << "\t\tInvalid grade!\n\t" << message << " (" << maxNumber << " maximum): ";
			}
        }
        else
        {
            cout << "\t\tInvalid entry!\n\t" << message << " (" << maxNumber << " maximum): ";
        }
	}while(true);
}
string strValue(string message)
{
	 const regex REGEX("^[a-zA-Z ]*$");
	 string jString;
	 cout << "\t" << message << ": ";
	 do
	 {
		 getline(cin,jString);
		
		if (jString.length() > 0 &&  jString.substr(0,1) != " "  && regex_match(jString, REGEX) )
		{	
			return jString;
        }
        else
        {
            cout << "\n\tInvalid entry!\n\t" << message << " : ";
        }
	}while(true);
}


int strUser()
{
	const regex REGEX_ONLYNUMBERS("^[0-9]*$");
	string number;
	getline(cin,number);
		
	if (regex_match(number, REGEX_ONLYNUMBERS))
	{
		int intNumber;
		istringstream ( number ) >> intNumber;
		return intNumber;
    }
    else
    {
		return -1;
    }
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


// confirmation functions
char   myYesNo(string message)
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
char   exitByCTRLX()
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
int    exitPrompt(string message, int exitValue)
{
	if (myYesNo(message) == 'Y')
	{
		//goodByPage();
		return exitValue;
	}else
	{
		return 0;
	}
}
void   displayNewStudent(Buffer *tmpData)
{
	cout << "\n\t New Grade information: " << endl;
	cout << "\t Student ID:         " << tmpData->stdID          << endl 
		 << "\t Student Name:       " << tmpData->stdFname       << endl
		 << "\t Student Family:     " << tmpData->stdLname       << endl
		 << "\t Student Group:      " << tmpData->stdGroupID     << endl
		 << "\t Course ID:          " << tmpData->stdCourseID    << endl
		 << "\t Course Name:        " << tmpData->stdCourseTitle << endl
		 << "\t Progect grade:      " << tmpData->stdProject     << endl
		 << "\t Midterm Grade:      " << tmpData->stdMidterm     << endl
		 << "\t Final Grade:        " << tmpData->stdFinal       << endl;
}


