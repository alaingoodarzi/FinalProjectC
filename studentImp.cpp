#include<iostream>
#include<string>
#include<iomanip>
#include"myHeader.h"



int studentOperation(int MAX, int& counter)
{
	int choice = 0 ;
	do
	{
		choice = studentMenu();
		switch(choice)
		{
		case 1 :
			cout << "Fisrt student choice";
			break;
		case 2 :
			cout << "second student choice";
			break;
		case 3 :
			cout << "third student choice";
			break;
		case 4 :
			choice = exitPrompt("Are you sure you want to reurn to main menu",4);
			break;
		default :
			break;
		}
		system("pause>null");

	}while(choice != 4);

	return 0;
}