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
	grades = new int*[maxCourses]; 
	for(int i=0; i<maxCourses; i++){
		grades[i] = new int[NBEXAMS];//NBEXAMS number of cols in each row
		for(int j=0; j<NBEXAMS; j++){
			grades[i][j] = 0;
		}
	}
	nbCourses = 0;
}

CStudent::~CStudent()
{ // --- add destructor definition here
	delete [] courses;
  	for(int i=0; i<maxCourses; i++)
      delete grades[i];
  	delete [] grades;
}

//enrolls a student in the specified course and increments nbCourses that the student has taken by 1
void CStudent::enroll(CCourse* c) //receives pointer to a course
{
	if(nbCourses<maxCourses){
		courses[nbCourses] = c;
    	nbCourses++;
	}
}

//displays the info of the courses by calling the method from the CCourse class
void CStudent::displayCourses()
{
	if(nbCourses>0){
	for(int i=0; i<nbCourses; i++)
		courses[i]->CCourse::displayInfo();}
}

//displays the name and ID of the student
void CStudent::displayInfo()
{
	cout<<"Name: "<<this->name<<endl;
	cout<<"ID: "<<this->id<<endl;
}

//receives and course index and exam index and score and sets the score in the specified loaction in the grades 2D array
void CStudent::setExamGrade(int ci, int ei, int score)
{
  if(ci>=0 && ci<nbCourses && ei>=0 && ei<NBEXAMS)
    grades[ci][ei] = score;
}

//receives a course index and an array of scores to be places into the array of grades for the student under the specified course
void CStudent::setCourseGrades(int ci, int* scores)
{
  if(ci>=0 && ci<nbCourses){
  	for(int i=0; i<NBEXAMS; i++){
  		grades[ci][i] = scores[i];
  	}
  }
}

//calculates average score of a student for all their courses and returns an array of averages of each course
float* CStudent::calcAverages()
{
  if(nbCourses>0){
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
  return av;} 
  else{return NULL;}
}

//returns index of the course, from its code
int CStudent::getCourseIndex(int icode)
{
  for(int i=0; i<nbCourses; i++){
    if(courses[i]->code == icode)
      return i;
  }
}
//takes pointer to a course as parameter to check if student is enrolled in the course
bool CStudent::alreadyEnrolled(CCourse* pc)
{
	for(int c=0; c>nbCourses; c++)
	{
		if (courses[c]->code == pc->code) //compares code of course passed in by pointer to the codes of all the courses of the student
			return true;
	} return false;
}

int CStudent::getnbCourses() 
{
	return nbCourses;
}

//------------------------
