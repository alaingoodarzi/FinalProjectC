#ifndef AG_FINAL_PROJECT
#define	AG_FINAL_PROJECT



#include<iostream>
#include<string>
using namespace std;

struct Teacher{
	   int	teacherID;
	string  passWord;
	string  fname;
	string  lname;
};

struct Course{
	string courseID;
	string courseTitle;
	   int groupID;
	   int teacherID;
};

struct Group{
	int groupID;
	int group;
};

struct Student{
	   int studentID;
	string passWord;
	string fname;
	string lname;
};

struct StudentResult{
	int teacherID;
	int courseID;
	float midtremExam;
	float finalExamExam;
	float Project;
};

struct Buffer{
	int stdID;
	string stdFname;
	string stdLname;
	string stdPass;

	int stdTeacherID;
	string stdTeacherFname;
	string stdTeacherLname;
	
	int stdCourseID;
	int stdCourse;
	
	float stdMidterm;
	float stdFinal;
	float stdProject;
	
	int stdGroupID;
	int stdGroup;
};








//prototype functions

// Validation
int checkDigits();




//General functions
void welcomePage();
void programTitle();

int login();
int addUser();   // teacher& student
int checkDuplicateID();
int addGroup();
int addCourse();
int footer();

void reportTitle();
void listHeader();
void listRecords();
void listDisplay();

int listcourses();  // teacher & student

int mainMenu();
int teacherMenu();
int studentMenu();



//teacher: 
int addStudentGrade();

int searchStd(int);
int searchStd(string,char);

int sortStudent();
int listCourseStudentsGrades();


//student
int viewGradeComponent();
int listCourseGades();




#endif // !AG_FINAL_PROJECT