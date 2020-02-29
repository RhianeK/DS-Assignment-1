//here// ---
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std ;
#include "constants.h"
#include "CCourse.hpp"
#include "CStudent.hpp"

CCourse::CCourse(char* vname, int vcode)
{
  	name = vname;
	code = vcode; // --- add constructor definition here
	capacity = MAXSTCR;
	enrolled = new CStudent*[capacity]; //the array enrolled is the size of max capacity
	nbEnrolled = 0;
  // --- add constructor definition here
}

CCourse::~CCourse()
{
// --- add destructor definition here
}

//displays name, code, capacity and no of students enrolled in the course
void CCourse::displayInfo() //takes an object of itself as an argument
{
	cout<<"Name: "<<this->name<<endl;
	cout<<"Code: "<<this->code<<endl; //display code, name, capacity, no of students enrolled
  	cout<<"Capacity: "<<this->capacity<<endl; //display code, name, capacity, no of students enrolled
	cout<<"Number of Students enrolled: "<<this->nbEnrolled<<endl;

}

//enrolls the student in the course and increments number of students inrolled in that course by 1
void CCourse::enroll(CStudent* s)
{
  if(nbEnrolled<capacity)
  {
	enrolled[nbEnrolled] = s;
    nbEnrolled++;
	}
}

//calls the displayInfo method of the CStudent class, to display info of all the students enrolled in the course
void CCourse::displayStudents()
{
	if (nbEnrolled > 0){
		for(int i=0; i<nbEnrolled; i++)
    		enrolled[i]->displayInfo();}
}

//receives index of the student in the course and returns the student
CStudent* CCourse::getStudent(int ind)
{
  	if(ind >= 0 && ind < nbEnrolled)
		return enrolled[ind];
	return NULL;
}

//finds student with highest averages in the course, and their index
void CCourse::findBestStudent() 
{
	if(nbEnrolled>0){
	  float* avg = calcAverages();
	  int ind = -1;
	  for(int i=0; i<nbEnrolled; i++)
	  {
			if(avg[i] > avg[ind]){
	      		ind = i;
			}
	  }
	  cout<<"the highest grade is "<<avg[ind]<<" and it belongs to the student with index "<<ind<<endl;
	}else{
		cout<<"there are no students in the course"<<endl;
	}
}

//calculates averages of all students in the course
float* CCourse::calcAverages()
{
  float* av = new float[capacity];
  for(int i=0; i<nbEnrolled; i++)
  { 
    float total = 0;
    for(int e=0; e<NBEXAMS; e++)
    {
      	total += enrolled[i]->grades[enrolled[i]->getCourseIndex(this->code)][e];
    }
    av[i] = total/NBEXAMS;
  }
  return av;
}

//getter for nbEnrolled attribute
int CCourse::getnbEnrolled() 
{
	return nbEnrolled;
}
