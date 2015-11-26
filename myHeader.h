#ifndef AG_FINAL_PROJECT
#define	AG_FINAL_PROJECT



#include<iostream>
#include<string>
using namespace std;

struct UserProfile{
	   int	userID;
	string  passWord;
	string  fname;
	string  lname;
	  char tOrS;
};

struct Course{

	   int courseN;
    string courseID;
	string courseTitle;
	   int teacherID;
	   int group;
};

struct Groups{
	int groupN;
	int groupID;
};

struct StudentResult{
	int teacherID;
	int studentID;
	int groupID;
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

   	   int tchID;
	string tchFname;
	string tchLname;
	
	int stdCourseID;
	int stdCourse;
	
	float stdMidterm;
	float stdFinal;
	float stdProject;
	
	int stdGroupID;
	int stdGroup;
};








//prototype functions

// Validation and control functions
int checkDigits();
char getMenuChoiceOK(int);
int intValue(int,string);
string strValue(string);
string firstLettersCapital(string);
string removeExcessSpace(string);
string shortenString(string,int);
char myYesNo(string);
char exitByCTRLX();
int exitPrompt(string,int);



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


void listDisplay();

void initialValues( UserProfile[], Groups[], Course[], int, Buffer*);


// list Functions
string leftMarginSpace(string[], int);
void listHeader(string[],int, int[]);
void listRecord(Course[], string[], int[], Buffer *);
void titleLength(int[], string[]);


int listcourses();  // teacher & student





int mainMenu();
int teacherMenu();
int studentMenu();



//teacher: 
int teacherOperations( int, int&, UserProfile[], Course[], Buffer *);
int teacherCourses(Course[], Buffer *);
int addStudentGrade(int, int&, UserProfile[], Course[], Buffer *);
int newStdID(UserProfile[]);
bool checkDuplicateID(UserProfile[], int&, int);


int searchStd(int);
int searchStd(string,char);

int sortStudent();
int listCourseStudentsGrades();


//student
int studentOperation(int, int&);
int viewGradeComponent();
int listCourseGades();




#endif // !AG_FINAL_PROJECT