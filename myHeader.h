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

	char tOrS;

	char currentTorS;
	int  currentUserId;
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
int  exitPrompt(string,int);
int strUser();
float floatValue(int, string);

//prompt functions
void welcomePage();
void pageTitle(string);
void programTitle();
void formTitle(string, int&, int);
void pausePrompt(string);
void myCout1(string, int, int );
void middleText(string);
string hiddenPassPhrase(string, char);
bool userPass(UserProfile[], Buffer *, int);
bool checkUp(int, string, UserProfile [], Buffer *, int);


// initializeand interactions
int  login();
int  addUser();   // teacher& student
int  checkDuplicateID();
int  addGroup();
int  addCourse();
bool stdCrsDuplicate(StudentResult[],string, int, int&);
string getFullName(UserProfile[], int, int);
void initialValues( UserProfile[], Groups[], Course[], int, Buffer*, int&, StudentResult[]);
string newNameFamily(string);
int  chooseGroup(Groups[], int);
void chooseCourse(Course[], int, Buffer*);

// calculation
int  finalResult(float, float , float );



// report related 
void reportTitle();
void listDisplay();
string leftMarginSpace(string[], int);
void listHeader(string[],int);
void teacherCoursList(Course[], string[], int[], Buffer *);
void titleLength(int[], string[]);
void getCourseInfo(Course[], string , Buffer *, int );
void getTeacherInfo(UserProfile[], Buffer *, int);
int listcourses();  // teacher & student




// menu related
int mainMenu();
int teacherMenu();
int studentMenu(string);
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
void courseGradeList(StudentResult[], Groups[], Course[], UserProfile[], Buffer *, int , int);
void sortStudentList(UserProfile[],int, Buffer*);
void courseStudentList(UserProfile[],int,int[],Buffer*);
void getStudentRecord(UserProfile [], Buffer *, int , int &);



//student
int studentOperation(StudentResult [], Groups[], Course[], UserProfile[], Buffer *, int, int);
//int viewGradeComponent();
int listCourseGades();
void studentCourseList(UserProfile[], StudentResult[], Course[], int , Buffer *, int);
void gradeComponent(Course[], StudentResult[], Buffer *, int, int);
int searchUser(UserProfile[],Buffer *, int &);
int searchUser(UserProfile[],Buffer *, int&, char);
int searchUser(UserProfile[],Buffer *, int&, string);






#endif // !AG_FINAL_PROJECT