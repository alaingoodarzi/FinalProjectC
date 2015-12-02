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
	   int groupID;
	  char tOrS;
};

struct Course{

	   int courseN;
    string courseID;
	string courseTitle;
	   int teacherID;
   	   int groupID;
};

struct Groups{
	int groupN;
	int groupID;
};

struct StudentResult{
	int teacherID;
	int studentID;
	int groupID;
	string courseID;
	float midtremExam;
	float finalExam;
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
	
	string stdCourseID;
	string stdCourseTitle;
	
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
string strUserPass(string);
float floatValue(int, string);

//General functions
void welcomePage();
void pageTitle(string);
void programTitle();
void formTitle(string, int&, int);
void pausePrompt(string);

int login();
int addUser();   // teacher& student
int checkDuplicateID();
int addGroup();
int addCourse();
int footer();
void middleText(string);
bool stdCrsDuplicate(StudentResult[],string, int, int&);
int finalResult(float, float , float );



void reportTitle();
void listDisplay();

void initialValues( UserProfile[], Groups[], Course[], int, Buffer*, int&, StudentResult[]);

string newNameFamily(string);

int chooseGroup(Groups[], int);
void chooseCourse(Course[], int, Buffer*);


// list Functions
string leftMarginSpace(string[], int);
void listHeader(string[],int);
void teacherCoursList(Course[], string[], int[], Buffer *);
void titleLength(int[], string[]);


int listcourses();  // teacher & student





int mainMenu();
int teacherMenu();
int studentMenu();
int teacherGradeSearchMenu();


//teacher: 
int teacherOperations( int, int&, UserProfile[], Course[],Groups[],StudentResult[], Buffer *);
int teacherCourses(Course[], Buffer *);
int addStudentGrade( UserProfile[], Course[], Groups[], StudentResult[], Buffer *, int, int&);
int newStdID(UserProfile[], int&,int);
int checkIdDuplication(UserProfile[], int&, int);

void displayNewStudent(Buffer*);

void getStudentGrade(StudentResult[],Buffer*, int &);

int searchStd(int);
int searchStd(string,char);

int sortStudent();
int listCourseStudentsGrades();

void saveStudentInfo(UserProfile[], StudentResult[], Buffer *, int&);
void teacherSearchGradeOperation(UserProfile[], StudentResult[], Course[], Buffer *, int &,int);


void gradeList(StudentResult [], Buffer *, int &);
//bool getUserProfile(UserProfile[], Buffer *, int &, int);


//student
int studentOperation(int, int&);
int viewGradeComponent();
int listCourseGades();



//returns User ID and sets tmpData or return -1
int searchUser(UserProfile[],Buffer *, int &);
int searchUser(UserProfile[],char);
int searchUser(UserProfile[],string);


#endif // !AG_FINAL_PROJECT