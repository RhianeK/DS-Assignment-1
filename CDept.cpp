#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "constants.h"
#include "CDept.hpp"
#include "CCourse.hpp"
#include "CStudent.hpp"

CDept::CDept()
{
    students = new CStudent*[MAXNBST];
    courses = new CCourse*[MAXNBCR];
    nbStudents = 0;
    nbCourses = 0;
    createStudents() ;
    createCourses() ;
    createDefaultGrades() ;
    enrollStudentsInCourses() ;
}

CDept::~CDept() {
    // -- do it here --
    delete [] students;
    delete [] courses;
}

CStudent* CDept::getStudent(int index)
{
    // -- do it here --

    return NULL ; //Added to avoid compiler error. Replace it with the right return statement
}

CCourse* CDept::getCourse(int index)
{
    // -- do it here --
    return NULL ; //Added to avoid compiler error. Replace it with the right return statement
}

void CDept::createStudents() {
    char* stNames[] = {(char*)"Bill", (char*)"Alex", (char*)"Bob", (char*)"Ana", (char*)"Lilya",
        (char*)"Julie", (char*)"Chris", (char*)"Stef", (char*)"Max", (char*)"Ray"} ;
    int stCodes[]   = {105, 115, 125, 135, 145, 155, 165, 175, 185, 195} ;

    // Let's create 5 students,
    nbStudents= 5 ;
    for(int st= 0; st<nbStudents; st++) students[st] = new CStudent(stNames[st], stCodes[st]) ;
}

void CDept::createCourses() {
    char* crNames[] = {(char*)"CSO", (char*)"OS", (char*)"DB", (char*)"D. Math", (char*)"Software Eng",
        (char*)"logic", (char*)"AI", (char*)"Algo", (char*)"NLP", (char*)"Prog 1"} ;
    int crCodes[]   = {106, 116, 126, 206, 216, 226, 306, 316, 326, 406} ;

    // Let's create 5 courses,
    if(nbCourses==0){
      nbCourses= 5 ;
      for(int cr= 0; cr<nbCourses; cr++) courses[cr] = new CCourse(crNames[cr], crCodes[cr]) ;
    }
}

void CDept::enrollStudentsInCourses()
{
  for(int s=0; s<nbStudents; s++)
  {
    CStudent* st = students[s];
    srand((unsigned int)time(0));
    for(int nbc=0; nbc<rand()%st->maxCourses; nbc++)
    {
      do{
        srand((unsigned int)time(0));
        enroll(st, courses[rand()%nbCourses]);
      }while(!enroll(st, courses[rand()%nbCourses]));
    }
  }
}

void CDept::createDefaultGrades()
{
  // Use current time as seed for random generator
  for(int s=0; s<nbStudents; s++){
    CStudent* st = students[s];
		for(int c=0; c<st->nbCourses;c++){
      for(int i=0; i<NBEXAMS; i++){
        srand((unsigned int)time(0));
        st->grades[c][i] = rand()%101;
      }
    }
  }
}

bool CDept::addStudent(char* n, int c) {
  if(nbStudents<MAXNBST){
    students[nbStudents] = new CStudent(n, c);
    return true;
  }
  return false ;
}

bool CDept::addCourse(char* n, int c) {
  if(nbCourses<MAXNBCR){
    courses[nbCourses] = new CCourse(n, c);
    return true;
  }
  return false ;
}

bool CDept::enroll(CStudent* ps, CCourse* pc) {
    // -- do it here --
    if(ps->maxCourses > ps->nbCourses && pc->capacity > pc->nbEnrolled && !ps->alreadyEnrolled(pc))
      {
        ps->enroll(pc);
        pc->enroll(ps);
        return true;
      }
    return false ; //or return false
}

void CDept::displayStudents() {

  for(int s=0; s>nbStudents; s++){
    students[s]->displayInfo();
  }
}

void CDept::displayCourses() {
  for(int c=0; c>nbCourses; c++){
    courses[c]->displayInfo();
  }
}

void CDept::enterStudentGrades(CStudent* ps, CCourse* pc, int* gr) {
    if (ps->alreadyEnrolled(pc)){
        int i = ps->getCourseIndex(pc->code);
        for(int g=0; g<NBEXAMS; g++){
            ps->grades[i][g] = gr[g];
        }
    }
}

void CDept::coursesofStudent(CStudent* ps){
    ps->displayCourses();
}

void CDept::bestStudentInCourse(CCourse* pc){
    pc->findBestStudent();
}
CStudent* CDept::findBestinDept(){
  float max = 0;
  int ind;
  for(int s=0; s<nbStudents; s++){
    CStudent* st = students[s];
    if (st->nbCourses >= 3){
      float* allgrades = st->calcAverages();
      float total = 0;
      float av = 0;
      for(int g=0; g<st->nbCourses; g++){
        total += allgrades[g];
        av = total/st->nbCourses;
      }
    if(av > max){
      max = av;
      ind = s;
      }
    }
  }
  return students[ind];
}
