#include<iostream>
#include<string>
#include<iomanip>
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
	arrUserProfile[1].fname    = "AAAAAAA";
	arrUserProfile[1].lname    = "AAA";
	arrUserProfile[1].groupID  = 7148 ;
	arrUserProfile[1].tOrS     = 's';
	counter++;

	arrUserProfile[2].userID   = 1234568;
	arrUserProfile[2].passWord = "1234568";
	arrUserProfile[2].fname    = "BBBBBBBBB";
	arrUserProfile[2].lname    = "BBB";
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
	arrStudentResult[0].finalExamExam = 90.5f;

	arrStudentResult[1].studentID = 1234567;
	arrStudentResult[1].teacherID = 5257;
	arrStudentResult[1].groupID =7148 ;
	arrStudentResult[1].courseID = "420-P16-AS";
	arrStudentResult[1].Project = 92.5;
	arrStudentResult[1].midtremExam = 92.5;
	arrStudentResult[1].finalExamExam = 92.5;

	arrStudentResult[2].studentID = 1234568;
	arrStudentResult[2].teacherID = 5257;
	arrStudentResult[2].groupID = 7151 ;
	arrStudentResult[2].courseID = "420-P16-AS";
	arrStudentResult[2].Project = 93.5;
	arrStudentResult[2].midtremExam = 93.5;
	arrStudentResult[2].finalExamExam = 93.5;

	arrStudentResult[3].studentID = 1234569;
	arrStudentResult[3].teacherID = 5257;
	arrStudentResult[3].groupID = 7256 ;
	arrStudentResult[3].courseID = "420-P34-AS";
	arrStudentResult[3].Project = 90.5;
	arrStudentResult[3].midtremExam = 90.5;
	arrStudentResult[3].finalExamExam = 9.5;

	arrStudentResult[4].studentID = 1234570;
	arrStudentResult[4].teacherID = 5257;
	arrStudentResult[4].groupID =7148 ;
	arrStudentResult[4].courseID = "420-P16-XX";
	arrStudentResult[4].Project = 80.5f;
	arrStudentResult[4].midtremExam = 80.5f;
	arrStudentResult[4].finalExamExam = 80.5f;

	arrStudentResult[5].studentID = 1234571;
	arrStudentResult[5].teacherID = 5257;
	arrStudentResult[5].groupID =7148 ;
	arrStudentResult[5].courseID = "420-P16-XX";
	arrStudentResult[5].Project = 81.5;
	arrStudentResult[5].midtremExam = 81.5;
	arrStudentResult[5].finalExamExam = 81.5;




}
string newNameFamily(string prompt)
{
	string jName= strValue(prompt);
	jName = removeExcessSpace(jName);
	jName = firstLettersCapital(jName);
	return jName;
}

