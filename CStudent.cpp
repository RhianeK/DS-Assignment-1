#include <iostream>
#include "constants.h"
#include "CStudent.hpp"
#include "CCourse.hpp"

using namespace std;

CStudent::CStudent(char* vname, int vid)
{
     // --- add constructir definition here
	name = vname;
	id = vid;
	maxCourses = MAXCRST;
	courses = new CCourse*[maxCourses];
		//creating the 2D array of grades with maxCourses as the number of rows and NBEXAMS as the cols
	grades = new int*[maxCourses]; //Create an Array of maxCourses Pointers (each pointer will point to 1 Row of 2D Array)
	for(int i=0; i<maxCourses; i++)
		grades[i] = new int[NBEXAMS]; //NBEXAMS number of cols in each row

}

CStudent::~CStudent()
{ // --- add destructor definition here
	delete [] courses;
  	for(int i=0; i<maxCourses; i++)
      delete grades[i];
  	delete [] grades;
}

void CStudent::enroll(CCourse* c) //receives pointer to a course
{
	if(nbCourses<maxCourses){
		courses[nbCourses] = c;
    nbCourses++;
	}
}

void CStudent::displayCourses()
{
	for(int i=0; i<nbCourses; i++)
		courses[i]->CCourse::displayInfo();
}

void CStudent::displayInfo()
{
	cout<<"Name: "<<this->name<<endl;
	cout<<"ID: "<<this->id<<endl;
  this->displayCourses();
}

void CStudent::setExamGrade(int ci, int ei, int score)
{
  if(ci>=0 && ci<nbCourses && ei>=0 && ei<NBEXAMS)
    grades[ci][ei] = score;
}
void CStudent::setCourseGrades(int ci, int* scores)
{
  if(0<=ci<nbCourses)
    for(int i=0; i<NBEXAMS; i++)
      grades[ci][i] = scores[i];
}
float* CStudent::calcAverages()
{
  float* av = new float[nbCourses];
  for(int i=0; i<nbCourses; i++)
  {
    float total = 0;
    for(int e=0; e<NBEXAMS; e++)
    {
      total += grades[i][e];
    }
    av[i] = total/NBEXAMS;
  }
  return av; // remember to delete
}
int CStudent::getCourseIndex(int icode)
{
  for(int i=0; i<nbCourses; i++){
    if(courses[i]->code == icode)
      return i;
  }
}
bool CStudent::alreadyEnrolled(CCourse* pc)
{
	for(int c=0; c>nbCourses; c++)
	{
		if (courses[c]->code == pc->code)
			return true;
	} return false;
}


//------------------------
