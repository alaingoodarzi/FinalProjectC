#include<iostream>
#include<string>
#include<iomanip>
#include <conio.h>
#include <vector>
#include <sstream>
#include"myHeader.h"

void initialValues(UserProfile arrUserProfile[],Groups arrGroups[],Course arrCourses[], int MAX, Buffer *tmpData, int &counter, StudentResult arrStudentResult[])
//void initValues(UserProfile arrUserProfile[])
{

	arrUserProfile[0].userID   = 5257;
	arrUserProfile[0].passWord = "quanghoang";
	arrUserProfile[0].fname    = "Quang Hoang";
	arrUserProfile[0].lname    = "Cao";
	arrUserProfile[0].tOrS     = 't';
	counter++;

	for (int i = 7; i < MAX; i++)   // temp is 7 need to be 1
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

	arrCourses[4].courseN = 5;
	arrCourses[4].courseID = "420-P16-XX";
	arrCourses[4].courseTitle = "XXXXXX Programming";
	arrCourses[4].teacherID = 5257;
	arrCourses[4].groupID = 7148;


	for (int i = 5; i < MAX; i++)
	{
		arrCourses[i].courseN = 0;
	}


	//tmp data for test and simulation


    arrUserProfile[1].userID   =  1234567;
	arrUserProfile[1].passWord = "1234567";
	arrUserProfile[1].fname    = firstLettersCapital(removeExcessSpace("aLi"));
	arrUserProfile[1].lname    = firstLettersCapital(removeExcessSpace("rezA"));
	arrUserProfile[1].groupID  = 7148 ;
	arrUserProfile[1].tOrS     = 's';
	counter++;

	arrUserProfile[2].userID   = 1234568;
	arrUserProfile[2].passWord = "1234568";
	arrUserProfile[2].fname    = "BaLi";
	arrUserProfile[2].lname    = "Beza";
	arrUserProfile[2].groupID  = 7151 ;
	arrUserProfile[2].tOrS     = 's';
	counter++;

	arrUserProfile[3].userID   = 1234569;
	arrUserProfile[3].passWord = "1234569";
	arrUserProfile[3].fname    = "CCCCCCCCC";
	arrUserProfile[3].lname    = "CCC";
	arrUserProfile[3].groupID  = 7256 ;
	arrUserProfile[3].tOrS     = 's';
	counter++;

	arrUserProfile[4].userID   = 1234570;
	arrUserProfile[4].passWord = "1234570";
	arrUserProfile[4].fname    = "DDDDDDDDDDDDD";
	arrUserProfile[4].lname    = "DDD";
	arrUserProfile[4].groupID  = 7148 ;
	arrUserProfile[4].tOrS     = 's';
	counter++;

	arrUserProfile[5].userID   = 1234571;
	arrUserProfile[5].passWord = "1234571";
	arrUserProfile[5].fname    = "EEEEEEEEE";
	arrUserProfile[5].lname    = "EEE";
	arrUserProfile[5].groupID  = 7148 ;
	arrUserProfile[5].tOrS     = 's';
	counter++;

	// tmp result for simulation
	arrStudentResult[0].studentID = 1234567;
	arrStudentResult[0].teacherID = 5257;
	arrStudentResult[0].groupID = 7148 ;
	arrStudentResult[0].courseID = "420-P16-XX";
	arrStudentResult[0].Project = 90.5f;
	arrStudentResult[0].midtremExam = 90.5f;
	arrStudentResult[0].finalExam = 90.5f;

	arrStudentResult[1].studentID = 1234567;
	arrStudentResult[1].teacherID = 5257;
	arrStudentResult[1].groupID =7148 ;
	arrStudentResult[1].courseID = "420-P16-AS";
	arrStudentResult[1].Project = 92.5;
	arrStudentResult[1].midtremExam = 92.5;
	arrStudentResult[1].finalExam = 92.5;

	arrStudentResult[2].studentID = 1234568;
	arrStudentResult[2].teacherID = 5257;
	arrStudentResult[2].groupID = 7151 ;
	arrStudentResult[2].courseID = "420-P16-AS";
	arrStudentResult[2].Project = 93.5;
	arrStudentResult[2].midtremExam = 93.5;
	arrStudentResult[2].finalExam = 93.5;

	arrStudentResult[3].studentID = 1234569;
	arrStudentResult[3].teacherID = 5257;
	arrStudentResult[3].groupID = 7256 ;
	arrStudentResult[3].courseID = "420-P34-AS";
	arrStudentResult[3].Project = 90.5;
	arrStudentResult[3].midtremExam = 90.5;
	arrStudentResult[3].finalExam = 9.5;

	arrStudentResult[4].studentID = 1234570;
	arrStudentResult[4].teacherID = 5257;
	arrStudentResult[4].groupID =7148 ;
	arrStudentResult[4].courseID = "420-P16-XX";
	arrStudentResult[4].Project = 80.5f;
	arrStudentResult[4].midtremExam = 80.5f;
	arrStudentResult[4].finalExam = 80.5f;

	arrStudentResult[5].studentID = 1234571;
	arrStudentResult[5].teacherID = 5257;
	arrStudentResult[5].groupID =7148 ;
	arrStudentResult[5].courseID = "420-P16-XX";
	arrStudentResult[5].Project = 81.5;
	arrStudentResult[5].midtremExam = 81.5;
	arrStudentResult[5].finalExam = 81.5;




}
string newNameFamily(string prompt)
{
	string jName= strValue(prompt);
	jName = removeExcessSpace(jName);
	jName = firstLettersCapital(jName);
	return jName;
}
int searchUser(UserProfile arrUserProfile[], Buffer *tmpData, int &counter) // how id,fname,lname,fname+lname
{
	int userID = 0;
	userID = intValue(7, "Please enter student ID: ");
	for (int i = 0; i < counter; i++)
	{
		if (arrUserProfile[i].userID == userID)
		{
			tmpData->stdID = arrUserProfile[i].userID;
			tmpData->stdFname = arrUserProfile[i].fname;
			tmpData->stdLname = arrUserProfile[i].lname;
			tmpData->stdPass = arrUserProfile[i].passWord;
			tmpData->stdGroupID = arrUserProfile[i].groupID;
			return tmpData->stdID;
			break;
		}
	}
	tmpData->stdID = userID;
	return -1;
}
int searchUser(UserProfile arrUserProfile[],Buffer *tmpData, int &counter, char how)
{
	//const int MAX = 10;
	string name = "";
	if (how == 'f')
	{
		//name = strValue("\n\n\tPlease enter first name for search");
		name = newNameFamily("\n\tPlease enter first name for search");
	}else
	{
		//name = strValue("\n\n\tPlease enter last name for search");
		name = newNameFamily("\n\tPlease enter last name for search");
	}
	
	bool minimumOnePerson = false;
	for (int i = 0; i < counter; i++)
	{
		if (how == 'f')
		{
			if (arrUserProfile[i].fname == name)  // if there is minimum one person
			{
				minimumOnePerson = true;
				break;
			}
		}
		else
		{
			if (arrUserProfile[i].lname == name)  // if there is minimum one person
			{
				minimumOnePerson = true;
				break;
			}
		}
		
	}

	if(minimumOnePerson == true)
	{
		cout << "\n\tSelect the user: ";
		int    *arrTmpStdId;
		string *arrTmpStdFname;
		string *arrTmpStdLname;
		int    *arrTmpStdGroup;

		arrTmpStdId    = new int[counter];
		arrTmpStdFname = new string[counter];
		arrTmpStdLname = new string[counter];
		arrTmpStdGroup = new int[counter];		
		int jCounter = 0;

		for ( int i = 0; i < counter; i++)
		{
			if (how == 'f')
			{
				if (arrUserProfile[i].fname == name)
				{
					cout << "\n\t\t\t" << jCounter + 1 << "." << arrUserProfile[i].userID << "  " << arrUserProfile[i].fname << "," << arrUserProfile[i].lname   ;
						arrTmpStdId[jCounter] = arrUserProfile[i].userID;
						arrTmpStdFname[jCounter] = arrUserProfile[i].fname;
						arrTmpStdLname[jCounter] = arrUserProfile[i].lname;
						arrTmpStdGroup[jCounter] = arrUserProfile[i].groupID;
						jCounter++;
				}
			}
			else  // searches lname
			{
				if (arrUserProfile[i].lname == name)
				{
					cout << "\n\t\t\t" << jCounter + 1 << "." << arrUserProfile[i].userID << "  " << arrUserProfile[i].lname << "," << arrUserProfile[i].fname;
						arrTmpStdId[jCounter] = arrUserProfile[i].userID;
						arrTmpStdFname[jCounter] = arrUserProfile[i].fname;
						arrTmpStdLname[jCounter] = arrUserProfile[i].lname;
						arrTmpStdGroup[jCounter] = arrUserProfile[i].groupID;
						jCounter++;
				}			
			}
		}
		cout << "\tSelect user (1-" << jCounter << "): ";
		int choice = getMenuChoiceOK( jCounter );
		cin.ignore();
		tmpData->stdID =    arrTmpStdId[choice - 1];
		tmpData->stdGroupID = arrTmpStdGroup[choice - 1];
		tmpData->stdFname = arrTmpStdFname [choice - 1];
		tmpData->stdLname = arrTmpStdLname [choice - 1];

		delete [] arrTmpStdId;
		delete [] arrTmpStdFname;	
		delete [] arrTmpStdLname;
		delete [] arrTmpStdGroup;
		
		return tmpData->stdID;
	}
	else
	{
		return -1;
	}
}
int searchUser(UserProfile arrUserProfile[],Buffer *tmpData, int &counter, string how)
{
	string name = "";
	string fName = newNameFamily("\n\tPlease enter first name for search");
	string lName = newNameFamily("\n\t Please enter last name for search");
	
	bool minimumOnePerson = false;
	for (int i = 0; i < counter; i++)
	{
		if (arrUserProfile[i].fname == fName && arrUserProfile[i].lname == lName)  // if there is minimum one person
		{
			minimumOnePerson = true;				
			break;
		}	
	}

	if(minimumOnePerson == true)
	{
		cout << "\n\tSelect the user: ";
		int    *arrTmpStdId;
		string *arrTmpStdFname;
		string *arrTmpStdLname;
		int    *arrTmpStdGroup;

		arrTmpStdId    = new int[counter];
		arrTmpStdFname = new string[counter];
		arrTmpStdLname = new string[counter];
		arrTmpStdGroup = new int[counter];		
		int jCounter = 0;

		for ( int i = 0; i < counter; i++)
		{

			if (arrUserProfile[i].fname == fName && arrUserProfile[i].lname == lName)
			{
				cout << "\n\t\t\t" << jCounter + 1 << "." << arrUserProfile[i].userID << "  " << arrUserProfile[i].fname << "," << arrUserProfile[i].lname   ;
					arrTmpStdId[jCounter] = arrUserProfile[i].userID;
					arrTmpStdFname[jCounter] = arrUserProfile[i].fname;
					arrTmpStdLname[jCounter] = arrUserProfile[i].lname;
					arrTmpStdGroup[jCounter] = arrUserProfile[i].groupID;
					jCounter++;
			}
		}

		cout << "\tSelect user (1-" << jCounter << "): ";
		int choice = getMenuChoiceOK( jCounter );
		cin.ignore();
		tmpData->stdID =    arrTmpStdId[choice - 1];
		tmpData->stdGroupID = arrTmpStdGroup[choice - 1];
		tmpData->stdFname = arrTmpStdFname [choice - 1];
		tmpData->stdLname = arrTmpStdLname [choice - 1];

		delete [] arrTmpStdId;
		delete [] arrTmpStdFname;	
		delete [] arrTmpStdLname;
		delete [] arrTmpStdGroup;
		
		return tmpData->stdID;
	}
	else
	{
		return -1;
	}
}
void pausePrompt(string message)
{
	//cout << "\n\n\t";
	myCout1( message,2,1);
	system("pause>nul");
}
bool userPass(UserProfile arrUserProfile[], Buffer *tmpData, int counter)
{
	int user = 0;
	string pass = "";
	int jCounter = 1;
	do
	{
		system("cls");
		programTitle();
		cout << "\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\tUserName: ";
		user = strUser();
		pass = hiddenPassPhrase("PassWord",'h');
		if( checkUp(user,pass,arrUserProfile, tmpData, counter) == false)
		{
			cout << "\n\n\t\t\tInvalid username or password! " << "(" << jCounter << "/3" << ")  " << pass;
			system("pause > nul");
		}
		else
		{
			//cout << "OK" << endl;
			//system("pause");
			return true;
		}
	}while( jCounter++ < 3 );
	cout << "\n\n\t\t\t    Your login attempts is over! ";
	system("pause > nul");

	return false;
}
string hiddenPassPhrase(string message, char how)
{
	cout << "\t\t\t";
	cout << "\t" << message << ": ";
	stringstream pass;
	string spass = "";
	vector<char> passBit(20);    // declares a vector of integers
	int charNo = 0;
	
	do 
	{
		passBit[charNo] = _getch();
		switch(passBit[charNo])
		{
			case 13 :
				for (int j = 0; j < charNo+1 ; j++)
				{
					pass << passBit[j];
				}
				spass = pass.str();
				return spass;
				break;
			
			case '\b' :
				if (charNo > 0)
				{
					charNo--;
					cout << "\b" << " " << "\b";
				}
				break;
			case '*':
			case '?':
			case '/':
			case '\\':
			case ' ' :
			case '.':
			case ',':
			case ';':
			case '\'' :
			case '\"' :
				break;
			default:
				if(how == 'h')
				{
					cout << '*';
				}else
				{
					cout << passBit[charNo];
				}
				charNo++;
				break;

		}
	}while(charNo < 20);

	for (int i = 0; i < 20 ; i++)
	{
		pass << passBit[i];
	}
	spass = pass.str();
	return spass;
}





bool checkUp(int user,string pass,UserProfile arrUserProfile[],Buffer *tmpData, int counter)
{
	pass.erase(pass.size() - 1);
	for (int i = 0; i < counter; i++)
	{
		
		if (arrUserProfile[i].userID == user && arrUserProfile[i].passWord == pass)
		{
			tmpData->currentTorS = arrUserProfile[i].tOrS;
			tmpData->currentUserId = arrUserProfile[i].userID;
			tmpData->stdID = arrUserProfile[i].userID;
			tmpData->stdGroupID = arrUserProfile[i].groupID;
			tmpData->stdFname = arrUserProfile[i].fname;
			tmpData->stdLname = arrUserProfile[i].lname;
			return true;
		}
	}
	return false;
}