#include <iostream>
#include "constants.h"
#include "CStudent.hpp"
#include "CCourse.hpp"

CStudent::CStudent(char* vname, int vid)
{
     // --- add constructir definition here
	char* name = vname;
	int id = vid;
	int maxCourses = 7; //change this. where should it be declared??
	int *courses = new int[maxCourses];
		//creating the 2D array of grades with maxCourses as the number of rows and NBEXAMS as the cols
	grades = new int*[maxCourses]; //Create an Array of maxCourses Pointers (each pointer will point to 1 Row of 2D Array)
	for(int i=0; i<maxCourses; i++)
		grades[i] = new int[NBEXAMS]; //NBEXAMS number of cols in each row
	int nbCourses = 0;
}

CStudent::~CStudent()
{
    delete [] name; // --- add destructor definition here
    delete [] courses; 
}

CStudent::enroll(CCourse& c) //receives pointer to a course
{
	if(nbCourses!=MAXCRST){
		nbCourses++;
		courses[nbCourses-1] = c;
	}
	
}

CStudent::displayCourses()
{
	for(int c=0; c<maxCourses; c++)
		{	
			cout<<"Course "<<c<<" : "<<courses[c]<<endl;
			
		}
	CCourse::displayInfo(CCourse c);
}

CStudent::displayInfo(CStudent& student)
{
	cout<<"Name: "<<student.name<<endl; //how do you print a pointer??
	cout<<"ID: "<<student.id<<endl;
}




