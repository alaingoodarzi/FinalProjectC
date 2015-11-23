#include<iostream>
#include<string>
#include"myHeader.h"
using namespace std;

void main()
{
	    welcomePage();
	int choice = mainMenu();
	    choice = teacherMenu();
	    choice = studentMenu();
}
