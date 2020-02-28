// ---
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std ;
#include "constants.h"
#include "CCourse.hpp"
#include "CStudent.hpp"

CCourse::CCourse(char* vname, int vcode)
{
    char* name = vname;
	int code = vcode; // --- add constructir definition here
	int capacity = MAXSTCR;
	int *enrolled = new int[capacity]; //the array enrolled is the size of max capacity
	int nbEnrolled = 0;
}

CCourse::~CCourse()
{
    delete [] name;// --- add destructor definition here
    delete [] enrolled;
}

CCourse::displayInfo(*this) //takes an object of itself as an argument
{
	cout<<"Code: "<<this.code<<endl;

	cout<<"Name: "<<this.name<<endl; //HOW DO YOU PRINT AN ARRAY OF CHARACTERS??
	cout<<"Capacity: "<<this.capacity<<endl; //display code, name, capacity, no of students enrolled
	cout<<"Number of Students enrolled: "<<this.nbEnrolled<<endl;
}