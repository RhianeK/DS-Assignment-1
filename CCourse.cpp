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

void CCourse::displayInfo() //takes an object of itself as an argument
{
	cout<<"Code: "<<this->code<<endl; //display code, name, capacity, no of students enrolled
  cout<<"Name: "<<this->name<<endl;
  cout<<"Capacity: "<<this->capacity<<endl; //display code, name, capacity, no of students enrolled
	cout<<"Number of Students enrolled: "<<this->nbEnrolled<<endl;

}

void CCourse::enroll(CStudent* s)
{
  if(nbEnrolled<capacity)
  {
	enrolled[nbEnrolled] = s;
    nbEnrolled++;
	}
}
void CCourse::displayStudents()
{
	if (nbEnrolled > 0){
		for(int i=0; i<nbEnrolled; i++)
    		enrolled[i]->displayInfo();}

}

CStudent* CCourse::getStudent(int ind)
{
  if(ind >= 0 && ind < nbEnrolled)
		return enrolled[ind];
	return NULL;
}

void CCourse::findBestStudent() // what to do with ties? -- get as in print or return?
{
  float* avg = calcAverages();
  int ind = 0;
  for(int i=0; i<nbEnrolled; i++)
  {
		if(avg[i] > avg[ind])
      ind = i;
  }
  cout<<"the highest grade is "<<avg[ind]<<"and it belongs to the student with index "<<ind<<endl;
}

float* CCourse::calcAverages()
{
  float* av = new float[capacity];
  for(int i=0; i<nbEnrolled; i++)
  {
    float total = 0;
    	for(int e=0; e<NBEXAMS; e++)
    	{
      	total += enrolled[i]->grades[enrolled[i]->getCourseIndex(code)][e];
    	}
    av[i] = total/NBEXAMS;
  }
  return av;
}
